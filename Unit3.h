//---------------------------------------------------------------------------

#ifndef Unit3H
#define Unit3H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
//---------------------------------------------------------------------------
class ProcessThread : public TThread
{
private:
    TEvent* MyEvent;
protected:
	void __fastcall Execute();
	void __fastcall IsBlockRead();
public:
	__fastcall ProcessThread(TEvent *MyEvent, bool CreateSuspended);
};
//---------------------------------------------------------------------------
#endif
