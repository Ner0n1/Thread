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
//      void __fastcall ProcessThread::UpdateCaption()
//      {
//        Form1->Caption = "Updated in a thread";
//      }
//---------------------------------------------------------------------------
int i;

void __fastcall ProcessThread::IsBlockRead()
{
    Form1 -> Label6 -> Caption = UnicodeString(i);
	Form1 -> Label10 -> Caption = UnicodeString(L"OK");
}

__fastcall ProcessThread::ProcessThread(TEvent *MyEvent, bool CreateSuspended)
	: TThread(CreateSuspended), MyEvent(MyEvent)
{
		FreeOnTerminate = true;
//        MyEvent = MyEvent;
        i = 0;
}
//---------------------------------------------------------------------------
void __fastcall ProcessThread::Execute()
{
	while(true)
	{
        if (Terminated) {
            break;
		}
		if (MyEvent -> WaitFor(0) == wrSignaled) {
			i++;
			Synchronize(&IsBlockRead);
			Sleep(20);
			MyEvent -> ResetEvent();

		}
	}

}

//---------------------------------------------------------------------------
