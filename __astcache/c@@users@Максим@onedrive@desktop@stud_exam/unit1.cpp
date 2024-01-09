#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "Unit2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;


//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Panel6Resize(TObject *Sender)
{
int w = Panel6->Width;
int a = DBGrid1->Columns->Items[0]->Width+ DBGrid1->Columns->Items[1]->Width+DBGrid1->Columns->Items[2]->Width
+DBGrid1->Columns->Items[3]->Width+DBGrid1->Columns->Items[4]->Width+DBGrid1->Columns->Items[5]->Width
+DBGrid1->Columns->Items[6]->Width+DBGrid1->Columns->Items[7]->Width;
DBGrid1->Columns->Items[8]->Width = w-a-80;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Panel8Resize(TObject *Sender)
{
int w = Panel8->Width;
int a = DBGrid2->Columns->Items[0]->Width+ DBGrid2->Columns->Items[1]->Width+DBGrid2->Columns->Items[2]->Width;
DBGrid2->Columns->Items[3]->Width = w-a-100;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::SpeedButton1Click(TObject *Sender)
{
if(Edit1->Text=="1"&&Edit2->Text=="1")     {





		DataModule2->FDQuery2->Close();
		DataModule2->FDQuery2->Open();
		AUTENTIFICARE->TabVisible=false;
		TabSheet2->TabVisible=true;
}

else{
    Edit1->Clear();
	Edit2->Clear();
    ShowMessage("Autentificare esuata");
}
}
//---------------------------------------------------------------------------


void __fastcall TForm1::FormShow(TObject *Sender)
{
 AUTENTIFICARE->TabVisible=true;
 TabSheet2->TabVisible=false;
 TabSheet3->TabVisible=false;
 TabSheet4->TabVisible=false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SpeedButton3Click(TObject *Sender)
{
	DataModule2->FDQuery2->Close();
	DataModule2->FDQuery2->Open();
	AUTENTIFICARE->TabVisible=false;
	TabSheet2->TabVisible=false;
	TabSheet4->TabVisible=true;
	TabSheet7->TabVisible=true;
	TabSheet8->TabVisible=false;
	TabSheet9->TabVisible=false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SpeedButton4Click(TObject *Sender)
{    	DataModule2->FDQuery1->Close();
		DataModule2->FDQuery1->Open();

		TabSheet2->TabVisible=false;
		TabSheet3->TabVisible=true;
		TabSheet1->TabVisible=true;
		TabSheet5->TabVisible=false;
		TabSheet6->TabVisible=false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SpeedButton11Click(TObject *Sender)
{
	TabSheet3->TabVisible=false;
	TabSheet2->TabVisible=true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SpeedButton12Click(TObject *Sender)
{
    TabSheet4->TabVisible=false;
	TabSheet2->TabVisible=true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SpeedButton13Click(TObject *Sender)
{
exit(0);
}
//---------------------------------------------------------------------------


void __fastcall TForm1::SpeedButton20Click(TObject *Sender)
{
if((Edit16->Text!="")&&(Edit17->Text!=""))
{

  DataModule2->INS_GRUPA->Close();
  DataModule2->INS_GRUPA->ParamByName("AN_FORMARE")->AsInteger= Edit17->Text.ToInt();
  DataModule2->INS_GRUPA->ParamByName("NUME")->AsString=Edit16->Text;
  DataModule2->INS_GRUPA->ExecSQL();
  DataModule2->FDQuery2->Close();
  DataModule2->FDQuery2->Open();

  Edit16->Text="";
  Edit17->Text="";
}
}
//---------------------------------------------------------------------------



void __fastcall TForm1::SpeedButton18Click(TObject *Sender)
{
  DataModule2->UPD_GRUPA->Close();
  DataModule2->UPD_GRUPA->ParamByName("GRUPA_ID")->AsInteger=DataModule2->FDQuery2->FieldByName("GRUPA_ID")->AsInteger;
  DataModule2->UPD_GRUPA->ParamByName("AN_FORMARE")->AsInteger= Edit20->Text.ToInt();
  DataModule2->UPD_GRUPA->ParamByName("NUME")->AsString=Edit19->Text;
  DataModule2->UPD_GRUPA->ExecSQL();
  DataModule2->FDQuery2->Close();
  DataModule2->FDQuery2->Open();

  Edit19->Text="";
  Edit20->Text="";
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SpeedButton10Click(TObject *Sender)
{
try{
	 if(!DataModule2->FDQuery2->IsEmpty())
	 {

			DataModule2->DEL_GRUPA->Close();
			DataModule2->DEL_GRUPA->ParamByName("GRUPA_ID")->AsInteger = DataModule2->FDQuery2->FieldByName("GRUPA_ID")->AsInteger;
			DataModule2->DEL_GRUPA->ExecSQL();
			DataModule2->FDQuery2->Close();
			DataModule2->FDQuery2->Open();
			MessageDlg("Eliminare cu succes!",mtInformation,TMsgDlgButtons()<<mbOK,0);
	 }


	 else{
		 ShowMessage("Nu sunt date de eliminat");
		 }
}

catch(...)     {

   ShowMessage("Ups,ceva nu a mers bine, va rugam apelati administratorul");
}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SpeedButton16Click(TObject *Sender)
{
   if((Edit3->Text!="")&&(Edit4->Text!="")&&(Edit5->Text!="")&&(DateTimePicker1->ToString()!="")&&(Edit8->Text!="")&&(Edit9->Text!="")
   &&(ComboBox1->Text!=""))
{

  DataModule2->INS_STUD->Close();
  DataModule2->INS_STUD->ParamByName("NUME")->AsString= Edit3->Text;
  DataModule2->INS_STUD->ParamByName("PRENUME")->AsString=Edit4->Text;
  DataModule2->INS_STUD->ParamByName("GRUPA_ID")->AsInteger=Edit5->Text.ToInt();
  DataModule2->INS_STUD->ParamByName("DATA_NAST")->AsString=DateTimePicker1->Date;
  DataModule2->INS_STUD->ParamByName("GEN")->AsString=ComboBox1->Text;
  DataModule2->INS_STUD->ParamByName("IDNP")->AsString=Edit8->Text;
  DataModule2->INS_STUD->ParamByName("TELEFON")->AsString=Edit9->Text;
  DataModule2->INS_STUD->ExecSQL();
  DataModule2->FDQuery1->Close();
  DataModule2->FDQuery1->Open();

  Edit3->Text="";
  Edit4->Text="";
  Edit5->Text="";
  Edit8->Text="";
  Edit9->Text="";
  ComboBox1->Text="";
}
}
//---------------------------------------------------------------------------


void __fastcall TForm1::SpeedButton14Click(TObject *Sender)
{
   DataModule2->UPD_STUD->Close();
  DataModule2->UPD_STUD->ParamByName("NUME")->AsString= Edit11->Text;
  DataModule2->UPD_STUD->ParamByName("PRENUME")->AsString=Edit13->Text;
  DataModule2->UPD_STUD->ParamByName("GRUPA_ID")->AsInteger=Edit7->Text.ToInt();
  DataModule2->UPD_STUD->ParamByName("DATA_NAST")->AsString=DateTimePicker2->Date;
  DataModule2->UPD_STUD->ParamByName("GEN")->AsString=ComboBox2->Text;
  DataModule2->UPD_STUD->ParamByName("IDNP")->AsString=Edit14->Text;
  DataModule2->UPD_STUD->ParamByName("TELEFON")->AsString=Edit10->Text;
  DataModule2->UPD_STUD->ParamByName("STUDENTT_ID")->AsInteger=DataModule2->FDQuery1->FieldByName("STUDENTT_ID")->AsInteger;
  DataModule2->UPD_STUD->ExecSQL();
  DataModule2->FDQuery1->Close();
  DataModule2->FDQuery1->Open();

  Edit11->Text="";
  Edit13->Text="";
  Edit7->Text="";

  Edit14->Text="";
  Edit10->Text="";
  ComboBox2->Text="";
}
//---------------------------------------------------------------------------


void __fastcall TForm1::SpeedButton7Click(TObject *Sender)
{
try{
	 if(!DataModule2->FDQuery2->IsEmpty())
	 {

			DataModule2->DEL_STUD->Close();
			DataModule2->DEL_STUD->ParamByName("STUDENTT_ID")->AsInteger = DataModule2->FDQuery1->FieldByName("STUDENTT_ID")->AsInteger;
			DataModule2->DEL_STUD->ExecSQL();
			DataModule2->FDQuery1->Close();
			DataModule2->FDQuery1->Open();
			MessageDlg("Eliminare cu succes!",mtInformation,TMsgDlgButtons()<<mbOK,0);
	 }


	 else{
		 ShowMessage("Nu sunt date de eliminat");
		 }
}

catch(...)     {

   ShowMessage("Ups,ceva nu a mers bine, va rugam apelati administratorul");
}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SpeedButton6Click(TObject *Sender)
{
   if(!DataModule2->FDQuery1->IsEmpty())
   {
   Edit11->Text=DataModule2->FDQuery1->FieldByName("NUME")->AsString;
   Edit13->Text=DataModule2->FDQuery1->FieldByName("PRENUME")->AsString;
   Edit7->Text=DataModule2->FDQuery1->FieldByName("GRUPA_ID")->AsString;
   ComboBox2->Text=DataModule2->FDQuery1->FieldByName("GEN")->AsString;
   DateTimePicker2->Date = DataModule2->FDQuery1->FieldByName("DATA_NAST")->AsString;
   Edit14->Text=DataModule2->FDQuery1->FieldByName("IDNP")->AsString;
   Edit10->Text=DataModule2->FDQuery1->FieldByName("TELEFON")->AsString;
	 TabSheet6->TabVisible=true;
	 TabSheet1->TabVisible=false;
	 TabSheet5->TabVisible=false;
   }

   else
  {
	  MessageDlg("Nu sunt date de editat",mtError ,TMsgDlgButtons()<<mbYes,0);
  }

}
//---------------------------------------------------------------------------

void __fastcall TForm1::SpeedButton9Click(TObject *Sender)
{
 if(!DataModule2->FDQuery2->IsEmpty())
   {
Edit19->Text =  DataModule2->FDQuery2->FieldByName("NUME")->AsString;
Edit20->Text =  DataModule2->FDQuery2->FieldByName("AN_FORMARE")->AsString;

	 TabSheet8->TabVisible=false;
	 TabSheet7->TabVisible=false;
	 TabSheet9->TabVisible=true;
}
   else
  {
	  MessageDlg("Nu sunt date de editat",mtError ,TMsgDlgButtons()<<mbYes,0);
  }
}

//---------------------------------------------------------------------------





void __fastcall TForm1::DBGrid2MouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y)
{
Edit19->Text =  DataModule2->FDQuery2->FieldByName("NUME")->AsString;
  Edit20->Text =  DataModule2->FDQuery2->FieldByName("AN_FORMARE")->AsString;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::DBGrid1MouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y)
{
   Edit11->Text=DataModule2->FDQuery1->FieldByName("NUME")->AsString;
   Edit13->Text=DataModule2->FDQuery1->FieldByName("PRENUME")->AsString;
   Edit7->Text=DataModule2->FDQuery1->FieldByName("GRUPA_ID")->AsString;
   ComboBox2->Text=DataModule2->FDQuery1->FieldByName("GEN")->AsString;
   DateTimePicker2->Date = DataModule2->FDQuery1->FieldByName("DATA_NAST")->AsString;
   Edit14->Text=DataModule2->FDQuery1->FieldByName("IDNP")->AsString;
   Edit10->Text=DataModule2->FDQuery1->FieldByName("TELEFON")->AsString;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SpeedButton8Click(TObject *Sender)
{
	 TabSheet8->TabVisible=true;
	 TabSheet7->TabVisible=false;
	 TabSheet9->TabVisible=false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SpeedButton5Click(TObject *Sender)
{
	 TabSheet6->TabVisible=false;
	 TabSheet1->TabVisible=false;
	 TabSheet5->TabVisible=true;
}
//---------------------------------------------------------------------------


void __fastcall TForm1::SpeedButton22Click(TObject *Sender)
{
	 TabSheet1->TabVisible=true;
	 TabSheet5->TabVisible=false;
	 TabSheet6->TabVisible=false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SpeedButton23Click(TObject *Sender)
{
     TabSheet1->TabVisible=true;
	 TabSheet5->TabVisible=false;
	 TabSheet6->TabVisible=false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SpeedButton24Click(TObject *Sender)
{
	 TabSheet8->TabVisible=false;
	 TabSheet7->TabVisible=true;
	 TabSheet9->TabVisible=false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SpeedButton21Click(TObject *Sender)
{
   Edit16->Text="";
   Edit17->Text="";
}
//---------------------------------------------------------------------------



void __fastcall TForm1::SpeedButton17Click(TObject *Sender)
{
  Edit3->Text="";
  Edit4->Text="";
  Edit5->Text="";

   Edit8->Text="";
   Edit9->Text="";
   ComboBox1->Text="";
}
//---------------------------------------------------------------------------


void __fastcall TForm1::SpeedButton15Click(TObject *Sender)
{
   Edit11->Text=DataModule2->FDQuery1->FieldByName("NUME")->AsString;
   Edit13->Text=DataModule2->FDQuery1->FieldByName("PRENUME")->AsString;
   Edit7->Text=DataModule2->FDQuery1->FieldByName("GRUPA_ID")->AsString;
   ComboBox2->Text=DataModule2->FDQuery1->FieldByName("GEN")->AsString;
   DateTimePicker2->Date = DataModule2->FDQuery1->FieldByName("DATA_NAST")->AsString;
   Edit14->Text=DataModule2->FDQuery1->FieldByName("IDNP")->AsString;
   Edit10->Text=DataModule2->FDQuery1->FieldByName("TELEFON")->AsString;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SpeedButton19Click(TObject *Sender)
{
  Edit19->Text =  DataModule2->FDQuery2->FieldByName("NUME")->AsString;
  Edit20->Text =  DataModule2->FDQuery2->FieldByName("AN_FORMARE")->AsString;
}
//---------------------------------------------------------------------------
