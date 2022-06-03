//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TButton *Button1;
	TButton *Button2;
	TLabel *Label1;
	TLabel *Label3;
	TEdit *Edit1;
	TEdit *Edit2;
	TLabel *Label5;
	TLabel *Label6;
	TButton *Button5;
	TButton *Button6;
	TLabel *Label8;
	TLabel *Label10;
	void __fastcall Button5Click(TObject *Sender);
	void __fastcall Button6Click(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
private:	// User declarations
	class ReadThread* ReadThreadPtr;
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
 //---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
