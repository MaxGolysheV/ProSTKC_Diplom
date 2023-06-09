//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Graph.h"
#include "Unit1.h"
#include "Graph2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
#include "Strukts.h"
#include "DrawClass1.cpp"
#include "FuncClass.cpp"
#include "GraphSettings.cpp"

TForm2 *Form2;
//---------------------------------------------------------------------------
int td= 0;
int step=1;
int minstep=1;
int maxstep = 6;
int laststep;

int Psbz;
extern int x1,y1;
extern int active_max_ka;
extern double xstep;
extern int ystep;
extern int posY;

__fastcall TForm2::TForm2(TComponent* Owner)
	: TForm(Owner)
{
	td= StrToInt(Form1->Edk->Text);
	et1->Text=td;
	sb1->Min =0;
	sb1->Max =24;
	Psbz=sb1->Position;
}
//---------------------------------------------------------------------------
void __fastcall TForm2::FormMouseWheelDown(TObject *Sender, TShiftState Shift, TPoint &MousePos,
		  bool &Handled)
{
	laststep = step;
	step-=1;
	if(step<minstep)
	{
	 step=laststep;
	}
	Form1->RedrawGraph(active_max_ka);
	edtZoom->Text = IntToStr(step);
	ClearSelection(img2);
}
//---------------------------------------------------------------------------
void __fastcall TForm2::FormMouseWheelUp(TObject *Sender, TShiftState Shift, TPoint &MousePos,
		  bool &Handled)
{
	laststep = step;
	step+=1;
	if(step>maxstep)
	{
	 step=laststep;
	}
	Form1->RedrawGraph(active_max_ka);
	edtZoom->Text = IntToStr(step);
	ClearSelection(img2);
}
//---------------------------------------------------------------------------
void __fastcall TForm2::dayForwardBtnClick(TObject *Sender)
{
	td++;
	Form1->Edk->Text=td;
	et1->Text=td;
	 ClearSelection(img2);
	Form1->ClearGraph(img1);
	Form1->Button1Click(Sender);
	ClearSelection(img2);
}
//---------------------------------------------------------------------------
void __fastcall TForm2::dayBackBtnClick(TObject *Sender)
{
	td--;
	Form1->Edk->Text=td;
	et1->Text=td;
	 ClearSelection(img2);
	Form1->ClearGraph(img1);
	Form1->Button1Click(Sender);
	ClearSelection(img2);
}
//---------------------------------------------------------------------------
void __fastcall TForm2::btnSaveClick(TObject *Sender) // сохранить кратинку
{
   spd1->Execute();
}
//---------------------------------------------------------------------------
void __fastcall TForm2::spd1CanClose(TObject *Sender, bool &CanClose)
{
 AnsiString path =  spd1->FileName + ".png";

  img1->Picture->SaveToFile(path);
}
//---------------------------------------------------------------------------
void __fastcall TForm2::ud1Changing(TObject *Sender, bool &AllowChange)
{


	laststep = step;
	step-=1;
	if(step<minstep)
	{
	 step=laststep;
	}


	laststep = step;
	step+=1;
	if(step>maxstep)
	{
	 step=laststep;
	}


	//Form1->ClearGraph(img1);
	//Form1->Button1Click(Sender);//
	Form1->RedrawGraph(active_max_ka);

}
void __fastcall TForm2::btn1Click(TObject *Sender)
{
	laststep = step;
	step-=1;
	if(step<minstep)
	{
	 step=laststep;
	}
	Form1->RedrawGraph(active_max_ka);
	edtZoom->Text = IntToStr(step);
	ClearSelection(img2);
}
//---------------------------------------------------------------------------
void __fastcall TForm2::btn2Click(TObject *Sender)
{
      laststep = step;
	step+=1;
	if(step>maxstep)
	{
	 step=laststep;
	}
	Form1->RedrawGraph(active_max_ka);
	edtZoom->Text = IntToStr(step);
	ClearSelection(img2);
}
//---------------------------------------------------------------------------
void __fastcall TForm2::sb1Change(TObject *Sender)
{
	x1=-(int)(step*img1->Width*(sb1->Position)/sb1->Max);

	Form1->RedrawGraph(active_max_ka);
	Psbz=sb1->Position;
	ClearSelection(img2);
}
//---------------------------------------------------------------------------
void __fastcall TForm2::FormActivate(TObject *Sender)
{
    td = StrToInt(Form1->Edk->Text);
	et2->Text = IntToStr(active_max_ka);
}
//---------------------------------------------------------------------------

extern Floats fka[];
extern Kosmo ka[];
extern GraphSettings gs;

void __fastcall TForm2::graphMouseClick(double tn, double tk, double xn,double xk, double y0, double y1, int X, int Y, int i)
{

	KU_TimeDATA tn1,tk1;
	 xn=(24*tn/86400)*(xstep*45)+x1;
	 xk=(24*tk/86400)*(xstep*45)+x1;
	 y0=(i+1)*ystep;
	 y1=ystep*(i+1)+ystep;
	 if(X>=xn && X<=xk && Y>=y0 && Y<= y1)
	 {
		 DrawSelection(img2,xn,xk,y0,y1);
		 int n = fka[i].name;
		 tn1.s= tn;
		 tn1.d=td;
		 tk1.s= tk;
		 tk1.d=td;
		 StatF(ka[n].r,ka[n].ts,tn1,tk1,gs.delta,Form3);

		 return;
	 }
}
//---------------------------------------------------------------------------
void __fastcall TForm2::checkMouseClick(double tn, double tk, double xn,double xk, double y0, double y1, int X, int Y, int i)
{
	 xn=(24*tn/86400)*(xstep*45)+x1;
	 xk=(24*tk/86400)*(xstep*45)+x1;
	 y0=(i+1)*ystep;
	 y1=ystep*(i+1)+ystep;
	 if(X>=xn && X<=xk && Y>=y0 && Y<= y1)
	 {
		 DrawSelection(img2,xn,xk,y0,y1);
		 return;
	 }
}
//---------------------------------------------------------------------------
void __fastcall TForm2::img1MouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
		  int X, int Y)
{
	double xn,xk,y0=0,y1=0;
	int i;
	for (i = 0; i < active_max_ka; i++)
	{
	  graphMouseClick(fka[i].tn1,fka[i].tk1,xn,xk,y0,y1,X,Y,i);
	  graphMouseClick(fka[i].tn2,fka[i].tk2,xn,xk,y0,y1,X,Y,i);
	  graphMouseClick(fka[i].tn3,fka[i].tk3,xn,xk,y0,y1,X,Y,i);
	  graphMouseClick(fka[i].tn4,fka[i].tk4,xn,xk,y0,y1,X,Y,i);
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm2::img1MouseMove(TObject *Sender, TShiftState Shift, int X, int Y)

{
	double xn,xk,y0=0,y1=0;
	int i;
	for (i = 0; i < active_max_ka; i++)
	{
		checkMouseClick(fka[i].tn1,fka[i].tk1,xn,xk,y0,y1,X,Y,i);
		checkMouseClick(fka[i].tn2,fka[i].tk2,xn,xk,y0,y1,X,Y,i);
		checkMouseClick(fka[i].tn3,fka[i].tk3,xn,xk,y0,y1,X,Y,i);
		checkMouseClick(fka[i].tn4,fka[i].tk4,xn,xk,y0,y1,X,Y,i);
	}
}
//---------------------------------------------------------------------------


