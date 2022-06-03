//---------------------------------------------------------------------------

#ifndef Unit2H
#define Unit2H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
//---------------------------------------------------------------------------
class ReadThread : public TThread
{
private:
	class ProcessThread* ProcessThreadPtr;
	TEvent* MyEvent;
protected:
	void __fastcall Execute();
public:
	__fastcall ReadThread(bool CreateSuspended);
};
BYTE *Block;
//---------------------------------------------------------------------------
#endif
