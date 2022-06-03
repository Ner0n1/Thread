//---------------------------------------------------------------------------

#include <System.hpp>
#pragma hdrstop

#include "Unit1.h"
#include "Unit2.h"
#include "Unit3.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------

//   Important: Methods and properties of objects in VCL can only be
//   used in a method called using Synchronize, for example:
//
//      Synchronize(&UpdateCaption);
//
//   where UpdateCaption could look like:
//
//      void __fastcall ReadThread::UpdateCaption()
//      {
//        Form1->Caption = "Updated in a thread";
//      }
//---------------------------------------------------------------------------
DWORD bytes = 512;
const WCHAR *name = L"\\\\.\\C:";

__fastcall ReadThread::ReadThread(bool CreateSuspended)
	: TThread(CreateSuspended)
{
	bytes = (Form1 -> Edit1 -> Text).ToInt()*1024;
	if (bytes < 512) {
		Application->MessageBox(L"Error - block can't be less than 512 bytes!",L"Message", MB_OK);
		return;
	}
	name = (Form1 -> Edit2 -> Text).c_str();

	FreeOnTerminate = true;
	MyEvent = new TEvent(NULL, true, false, "", false);
}
//---------------------------------------------------------------------------
void __fastcall ReadThread::Execute()
{
	HANDLE FileHandle = CreateFileW(name, GENERIC_READ, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, NULL);
	if (FileHandle == INVALID_HANDLE_VALUE) {
	   Application->MessageBox(L"Can't open disk! Please, enter disk name, like \"\\\\.\\C:\"",L"Message", MB_OK);
	   return;
	}
	LARGE_INTEGER BlockOffset;
	BlockOffset.QuadPart = 0;
	unsigned long CurrentPosition = SetFilePointer(FileHandle, BlockOffset.LowPart, &BlockOffset.HighPart, FILE_BEGIN);
	if (CurrentPosition != BlockOffset.LowPart) {
	   CloseHandle(FileHandle);
	   Application->MessageBox(L"Error - wrong pointer position!",L"Message", MB_OK);
	   return;
	}
	BYTE *Block = new BYTE[bytes];
	DWORD BytesRead;
	//ProcessThreadPtr -> Start();
	ProcessThreadPtr = new ProcessThread(MyEvent, false);
	while (true){
        if (Terminated) {
            Form1 -> Label10 -> Caption = UnicodeString(L"FINISHED");
			break;
		}

		bool ReadBlock = ReadFile(FileHandle,Block, bytes, &BytesRead, NULL);
		if (ReadBlock == false || BytesRead != bytes) {
			Application -> MessageBox(L"Error - can't read block!",L"Message",MB_OK);
			break;
		}
		MyEvent -> SetEvent();
		while(MyEvent -> WaitFor(0) == wrSignaled){
            Sleep(50);
		}
	}
	CloseHandle(FileHandle);
	ProcessThreadPtr -> Terminate();
    delete ProcessThreadPtr;
}
//---------------------------------------------------------------------------
