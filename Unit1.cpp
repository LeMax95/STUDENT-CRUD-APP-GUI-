#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "Unit2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
InputL *Inputs[9];
AnsiString date;
int entryPoint;

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

void __fastcall TForm1::Panel13Resize(TObject *Sender)
{
     int w = Panel13->Width;
   int a = DBGrid3->Columns->Items[0]->Width+ DBGrid3->Columns->Items[1]->Width+DBGrid3->Columns->Items[2]->Width
	+DBGrid3->Columns->Items[3]->Width+DBGrid3->Columns->Items[4]->Width+DBGrid3->Columns->Items[5]->Width
	+DBGrid3->Columns->Items[6]->Width+DBGrid3->Columns->Items[7]->Width;
	DBGrid3->Columns->Items[8]->Width = w-a-80;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::SpeedButton1Click(TObject *Sender)
{

  try{
	 if((Edit1->Text!="")&&(Edit2->Text!=""))
	   {
		   DataModule2->Q_AUTENTIFICARE->Close();
		   DataModule2->Q_AUTENTIFICARE->ParamByName("NUME")->AsString=Edit1->Text;
		   DataModule2->Q_AUTENTIFICARE->ParamByName("PASS")->AsString=Edit2->Text;
		   DataModule2->Q_AUTENTIFICARE->Open();

   if(!DataModule2->Q_AUTENTIFICARE->IsEmpty())
   {

        	DataModule2->FDQuery2->Close();
			DataModule2->FDQuery2->Open();
			int i = 0;
			while (!DataModule2->FDQuery2->Eof) {
				   GRUPSTUD->Items->Add(DataModule2->FDQuery2->FieldByName("NUME")->AsString);
				   GRUPNAME->Items->Add(DataModule2->FDQuery2->FieldByName("NUME")->AsString);
				   Edit5->Items->Add(DataModule2->FDQuery2->FieldByName("GRUPA_ID")->AsInteger);
				   STGRUPEDIT->Items->Add(DataModule2->FDQuery2->FieldByName("GRUPA_ID")->AsInteger);
					i++;

					DataModule2->FDQuery2->Next();




   }
   	AUTENTIFICARE->TabVisible=false;
				TabSheet2->TabVisible=true;

   }

   else
   {
	  Edit1->Clear();
      Edit2->Clear();
	   ShowMessage("Autentificare esuata");
   }
}
   else
   {
	   Edit1->Clear();
	   ShowMessage("Nu sunt introduse totate campurile");
   }
  }

  catch(...){
  ShowMessage("Ceva nu a mers bine, apelati la administratorul retelei");

 }
  }


















//---------------------------------------------------------------------------


void __fastcall TForm1::FormShow(TObject *Sender)
{
 AUTENTIFICARE->TabVisible=true;
 TabSheet2->TabVisible=false;
 TabSheet3->TabVisible=false;
 TabSheet4->TabVisible=false;
 CAUTARE->TabVisible=false;


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

	 if(!DataModule2->FDQuery2->IsEmpty())
	 {

			DataModule2->DEL_GRUPA->Close();
			DataModule2->DEL_GRUPA->ParamByName("GRUPA_ID")->AsInteger = DataModule2->FDQuery2->FieldByName
			("GRUPA_ID")->AsInteger;
			DataModule2->DEL_GRUPA->ExecSQL();
			DataModule2->FDQuery2->Close();
			DataModule2->FDQuery2->Open();
			MessageDlg("Eliminare cu succes!",mtInformation,TMsgDlgButtons()<<mbOK,0);
	 }


	 else{
		 ShowMessage("Nu sunt date de eliminat");
		 }



   ShowMessage("Ups,ceva nu a mers bine, va rugam apelati administratorul");

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
  Edit5->ItemIndex = -1;
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
  DataModule2->UPD_STUD->ParamByName("GRUPA_ID")->AsInteger= STGRUPEDIT->Text.ToInt();
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
   STGRUPEDIT->ItemIndex=-1;

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
   STGRUPEDIT->Text=DataModule2->FDQuery1->FieldByName("GRUPA_ID")->AsString;
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
   STGRUPEDIT->Text=DataModule2->FDQuery1->FieldByName("GRUPA_ID")->AsString;
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
   STGRUPEDIT->Text=DataModule2->FDQuery1->FieldByName("GRUPA_ID")->AsString;
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

void __fastcall TForm1::Cautare_BClick(TObject *Sender)
{


AnsiString s;
bool empty = true;
int nr_obj = 0;

			if(entryPoint==1)
			{
				Inputs[0] = new InputL( " S.NUME = '",NSTUD->Text);
				Inputs[1]=new InputL( " PRENUME = '",PSTUD->Text);
				Inputs[3]=new InputL( " GEN = '","");
				Inputs[2]=new InputL( " G.NUME = '","");
				Inputs[4]=new InputL( " TELEFON = '",TELSTUD->Text);
				Inputs[5]=new InputL( " IDNP = '",IDNP->Text);
				Inputs[6]=new InputL( " DATA_NAST = '","");




 if(GSTUD->ItemIndex!=-1)
 {

	 Inputs[3]->userInput = GSTUD->Text;


 }

   if(GRUPSTUD->ItemIndex!=-1)
 {

	 Inputs[2]->userInput = GRUPSTUD->Text;


 }

 if(date!="")
 {
	 Inputs[6]->userInput = date;
 }


for(int i = 0,j=0;i<7;i++)
{
	if(Inputs[i]->userInput!=""&&empty==true)
	{
		empty=false;
		 s="SELECT * FROM STUD S INNER JOIN GRUPA G ON S.GRUPA_ID = G.GRUPA_ID WHERE ";
		s+=Inputs[i]->dbParam;
		s+=Inputs[i]->userInput;
		s+="'";

	}

	else if(Inputs[i]->userInput!=""&&empty==false)
	{
		s+=" AND ";
		s+=Inputs[i]->dbParam;
		s+=Inputs[i]->userInput;
		s+="'";
	}


   }



 }

    else{

	   if(GRUPNAME->Text!=""||GRUPYEAR->Text!=""){
		   s="SELECT * FROM GRUPA WHERE ";
           	Inputs[0] = new InputL( " NUME = '",GRUPNAME->Text);
			Inputs[1]=new InputL( " AN_FORMARE = '",GRUPYEAR->Text);

			for(int i = 0;i<2;i++)
			{
                  	if(Inputs[i]->userInput!=""&&empty==true)
					{
						empty=false;
						  s="SELECT * FROM GRUPA WHERE ";
						s+=Inputs[i]->dbParam;
						s+=Inputs[i]->userInput;
						s+="'";

					}

					else if(Inputs[i]->userInput!=""&&empty==false)
					{
						s+=" AND ";
						s+=Inputs[i]->dbParam;
						s+=Inputs[i]->userInput;
						s+="'";
					}
							}


					   }
   }




 if(empty==false)
 {
	 if(entryPoint==1)
	 {
		DataModule2->FDQuery1->Close();
		DataModule2->FDQuery1->SQL->Clear();
		DataModule2->FDQuery1->SQL->Add(s);
		DataModule2->FDQuery1->Open();

	 }

	 else
	 {
		  DataModule2->FDQuery2->Close();
		  DataModule2->FDQuery2->SQL->Clear();
		  DataModule2->FDQuery2->SQL->Add(s);
		  DataModule2->FDQuery2->Open();
	 }

     	 if(entryPoint==1)
		 {
			nr_obj = 6;
			NSTUD->Clear();
			PSTUD->Clear();
			GSTUD->ItemIndex = -1;
			TELSTUD->Clear();
			GRUPSTUD->ItemIndex = -1;
			IDNP->Clear();
		 }


		 else
		 {
			 nr_obj = 2;
			 GRUPNAME->ItemIndex = -1;
			 GRUPYEAR->Clear();

		 }




  for(int i = 0;i<nr_obj;i++)
  {
   delete Inputs[i];
  }


 date = "";

 }

 else{
     ShowMessage("Introduceti macar un parametru de cautare");
 }





}
//---------------------------------------------------------------------------



//---------------------------------------------------------------------------



void __fastcall TForm1::GSTUDChange(TObject *Sender)
{
GSTUD->Text = GSTUD->Items[GSTUD->ItemIndex].Text;
}
//---------------------------------------------------------------------------


void __fastcall TForm1::DATESTUDChange(TObject *Sender)
{

  date = DATESTUD->Date.DateString();


}
//---------------------------------------------------------------------------

void __fastcall TForm1::BitBtn2Click(TObject *Sender)
{
CAUTARE->TabVisible =true;
TabSheet3->TabVisible=false;
TabSheet10->TabVisible=true;
TabSheet11->TabVisible=false;
entryPoint = 1;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::DBGrid3DblClick(TObject *Sender)
{
	if(entryPoint==1)
	{
	  CAUTARE->TabVisible=false;
	  TabSheet3->TabVisible=true;
	}

	else
	{
         CAUTARE->TabVisible=false;
	     TabSheet4->TabVisible=true;
    }

}
//---------------------------------------------------------------------------

void __fastcall TForm1::BitBtn1Click(TObject *Sender)
{
  CAUTARE->TabVisible =true;
  TabSheet4->TabVisible=false;
  TabSheet10->TabVisible=false;
  TabSheet11->TabVisible=true;

  entryPoint=2;
}
//---------------------------------------------------------------------------



//---------------------------------------------------------------------------






void __fastcall TForm1::SEARCHSKeyUp(TObject *Sender, WORD &Key, TShiftState Shift)

{
if(Key == 13)
{

	AnsiString s;

s = "SELECT * FROM STUD WHERE NUME = '"+SEARCHS->Text+"' OR PRENUME = '"+SEARCHS->Text
	 + "' or DATA_NAST LIKE '%"+SEARCHS->Text+"%'";

		DataModule2->FDQuery1->Close();
		DataModule2->FDQuery1->SQL->Clear();
		DataModule2->FDQuery1->SQL->Add(s);
		DataModule2->FDQuery1->Open();

	 SEARCHS->Clear();


}
}
//---------------------------------------------------------------------------


void __fastcall TForm1::SEARCHGKeyUp(TObject *Sender, WORD &Key, TShiftState Shift)

{
 if(Key == 13)
{

	AnsiString s;

s = "SELECT * FROM GRUPA WHERE NUME = '"+SEARCHG->Text+"' OR AN_FORMARE = '"+SEARCHG->Text+"'";

		DataModule2->FDQuery2->Close();
		DataModule2->FDQuery2->SQL->Clear();
		DataModule2->FDQuery2->SQL->Add(s);
		DataModule2->FDQuery2->Open();

	 SEARCHG->Clear();


}
}
//---------------------------------------------------------------------------


