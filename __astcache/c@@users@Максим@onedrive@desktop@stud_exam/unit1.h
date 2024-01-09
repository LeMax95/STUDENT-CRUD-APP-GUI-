//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Buttons.hpp>
#include <Vcl.Imaging.pngimage.hpp>
#include <Data.DB.hpp>
#include <Vcl.DBGrids.hpp>
#include <Vcl.Grids.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TPanel *Panel1;
	TPanel *Panel2;
	TPanel *Panel3;
	TPageControl *PageControl1;
	TTabSheet *AUTENTIFICARE;
	TTabSheet *TabSheet2;
	TTabSheet *TabSheet3;
	TTabSheet *TabSheet4;
	TPanel *Panel4;
	TLabel *Label1;
	TEdit *Edit1;
	TEdit *Edit2;
	TSpeedButton *SpeedButton2;
	TSpeedButton *SpeedButton1;
	TImage *Image1;
	TSpeedButton *SpeedButton3;
	TSpeedButton *SpeedButton4;
	TPanel *Panel5;
	TPanel *Panel6;
	TSpeedButton *SpeedButton5;
	TSpeedButton *SpeedButton6;
	TSpeedButton *SpeedButton7;
	TPanel *Panel7;
	TPanel *Panel8;
	TDBGrid *DBGrid1;
	TDBGrid *DBGrid2;
	TPageControl *PageControl2;
	TTabSheet *TabSheet1;
	TTabSheet *TabSheet5;
	TTabSheet *TabSheet6;
	TPanel *Panel9;
	TPageControl *PageControl3;
	TTabSheet *TabSheet7;
	TSpeedButton *SpeedButton8;
	TSpeedButton *SpeedButton9;
	TSpeedButton *SpeedButton10;
	TTabSheet *TabSheet8;
	TTabSheet *TabSheet9;
	TSpeedButton *SpeedButton12;
	TSpeedButton *SpeedButton13;
	TEdit *Edit3;
	TEdit *Edit4;
	TEdit *Edit5;
	TEdit *Edit8;
	TEdit *Edit9;
	TComboBox *ComboBox1;
	TSpeedButton *SpeedButton11;
	TEdit *Edit11;
	TEdit *Edit13;
	TComboBox *ComboBox2;
	TEdit *Edit14;
	TEdit *Edit10;
	TEdit *Edit7;
	TEdit *Edit16;
	TEdit *Edit17;
	TEdit *Edit19;
	TEdit *Edit20;
	TSpeedButton *SpeedButton14;
	TSpeedButton *SpeedButton16;
	TSpeedButton *SpeedButton17;
	TSpeedButton *SpeedButton18;
	TSpeedButton *SpeedButton20;
	TSpeedButton *SpeedButton21;
	TDateTimePicker *DateTimePicker1;
	TDateTimePicker *DateTimePicker2;
	TSpeedButton *SpeedButton22;
	TSpeedButton *SpeedButton23;
	TSpeedButton *SpeedButton24;
	TSpeedButton *SpeedButton25;
	TSpeedButton *SpeedButton15;
	TSpeedButton *SpeedButton19;
	void __fastcall Panel6Resize(TObject *Sender);
	void __fastcall Panel8Resize(TObject *Sender);
	void __fastcall SpeedButton1Click(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall SpeedButton3Click(TObject *Sender);
	void __fastcall SpeedButton4Click(TObject *Sender);
	void __fastcall SpeedButton11Click(TObject *Sender);
	void __fastcall SpeedButton12Click(TObject *Sender);
	void __fastcall SpeedButton13Click(TObject *Sender);
	void __fastcall SpeedButton20Click(TObject *Sender);
	void __fastcall SpeedButton18Click(TObject *Sender);
	void __fastcall SpeedButton10Click(TObject *Sender);
	void __fastcall SpeedButton16Click(TObject *Sender);
	void __fastcall SpeedButton14Click(TObject *Sender);
	void __fastcall SpeedButton7Click(TObject *Sender);
	void __fastcall SpeedButton6Click(TObject *Sender);
	void __fastcall SpeedButton9Click(TObject *Sender);
	void __fastcall DBGrid2MouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y);
	void __fastcall DBGrid1MouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y);
	void __fastcall SpeedButton8Click(TObject *Sender);
	void __fastcall SpeedButton5Click(TObject *Sender);
	void __fastcall SpeedButton22Click(TObject *Sender);
	void __fastcall SpeedButton23Click(TObject *Sender);
	void __fastcall SpeedButton24Click(TObject *Sender);
	void __fastcall SpeedButton21Click(TObject *Sender);
	void __fastcall SpeedButton17Click(TObject *Sender);
	void __fastcall SpeedButton15Click(TObject *Sender);
	void __fastcall SpeedButton19Click(TObject *Sender);

private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
