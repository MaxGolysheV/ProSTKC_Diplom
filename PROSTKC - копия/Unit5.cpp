//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit5.h"
#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm5 *Form5;
//---------------------------------------------------------------------------
__fastcall TForm5::TForm5(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm5::btnAcceptClick(TObject *Sender)
{
  AnsiString vectors[6];
  for(int i =0;i <6; i++)
  {
	vectors[i]=memoData->Lines->Strings[i];
  }
   Form1->Er_1->Text=vectors[0];
   Form1->Ev_1->Text=vectors[1];
   Form1->Etet_1->Text=vectors[2];
   Form1->Ei_1->Text=vectors[3];
   Form1->Eo_1->Text=vectors[4];
   Form1->Eu_1->Text=vectors[5];
  this->Visible=false;
}
//---------------------------------------------------------------------------
