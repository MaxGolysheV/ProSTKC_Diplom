//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop


#include "proc1.h"
#include "XKY_HBO_4_1.h"
#include "XKY_HBO_4_2.h"
#include "XKY_HBO_4_6.h"
#include "coil.h"
//--
#include "Graph.h"
#include "Strukts.h"
#include "GraphSettings.cpp"
#include "FuncClass.cpp"
//---------------------------------------------------------------------------
#include "Unit1.h"
#include "Unit4.h"
#include "Unit5.h"
#include "Unit6.h"


#include "csvReader.cpp"



Kosmo ka[30];
Floats fka[10];

TColor drawable_color[10];
TColor drawable_color2[4];  int vitcount=0;

double GLOBAL_tn1=0;
double GLOBAL_tk1=0;
double GLOBAL_tn2=0;
double GLOBAL_tk2=0;
double GLOBAL_tn3=0;
double GLOBAL_tk3=0;
double GLOBAL_tn4=0;
double GLOBAL_tk4=0;

class RGB_Randomize
{
 public:
 RGB_Randomize(){}

 TColor GetColor()
 {
	TColor color;
	Randomize();
	int a = Random(255);
	int b = Random(255);
	int c = Random(255);
	color = RGB(a,b,c);
	return color;
 }

};
AnsiString selectedFilePath="";
///
typedef struct
{
 int	tab;     //
 int	nru1;    //
 int	kru1;    //
 int	nru2;    //
 int	kru2;    //
 int	Pvz;    //
}RU_ka;
typedef struct
{
 KU_TimeDATA	tnru1;    //
 KU_TimeDATA	tkru1;    //
 KU_TimeDATA	tA1;    //
 KU_TimeDATA	tnru2;    //
 KU_TimeDATA	tkru2;    //
  KU_TimeDATA	tA2;    //
 KU_TimeDATA	tnru3;    //
 KU_TimeDATA	tkru3;    //
  KU_TimeDATA	tA3;    //
 KU_TimeDATA	tnru4;    //
 KU_TimeDATA	tkru4;    //
  KU_TimeDATA	tA4;    //
 int Pru;
}sDatRU;
RU_ka ParRU;
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
	coil(); Button1->Enabled = false; Mem1->ReadOnly = true;
}
 KU_TimeDATA a1;
 KU_TimeDATA a2;
 KU_TimeDATA a3;
 KU_TimeDATA a4;
 AnsiString historyMemo[4];
 sDatRU  DatRU;
//---------------------------------------------------------------------------
//�� ���� � ��� �����! �� ������ ���� �����!!!!
void GetTimeA12(double r[6],KU_TimeDATA tr1,KU_TimeDATA tr,AnsiString s[6])
{

double p1[6],p2[6],rr[6][6],r2[6],ps1[6],ps2[6],pa1[6],pa2[6],pa12[6],pa10[6],pa20[6],psa2[6],pa22[6],Lmd1,Lmd2;
KU_TimeDATA tn_by,tn0,t1,t2,ts,tn,dtt,ta10,tsa11,tsa12,tsa21,tsa22,tsa2,tssa[2];
KU_DateDATA Ds;
KU_TimeDATA ta1,ta12,t0_1,t0_10,t0_12,tnru11,tnru12,tkru11,tkru12,t0_2,tnru21,tnru22,tkru21,tkru22,tnru13,tnru14,tkru13,tkru14;
KU_TimeDATA ta2,ta22,ta20,tnru23,tnru24,tkru23,tkru24;
KU_MKOR MDKOR;
int ii,jj,tip;
double shkp,dkp,hkp,Rz,GRA,TKP[3],BN,sfi,alf,MJD,Sm,Um,mR[3],Rm,SM,SM0,SM_by,eu,M0,tby,DVAPI,PI;
double Rka1[3],Vka1[3],Rka2[3],Vka2[3],Vpkp1[3],Vpkp2[3],uk12;
int Pru1,Pru2,Pma,Prnka[6];
AnsiString SS,s2,ss,ss11,ss12,ss21,ss22,ssu,ssta[6][2];
KU_OSKP Kac1,Kac2;
int tab1,tab2,nru11,kru11,nru12,kru12,nru21,kru21,nru22,kru22;
 //sDatRU  DatRU;//
//coil();

Rz=6371.0;
Pru1=0;
Pru2=0;
Pma=0;
GRA=57.2957795130823252;
alf = 1/298.257223563;
PI=3.141592653589793;
DVAPI=2*PI;

	Prnka[0]=1;

 // ���� �������
ts=tr;

RIPM(r, p1); //�������� � ���������  P K Q

MDKOR.n_kor=0; //���������� ������� ���������
jj=0;
MDKOR.TIPkor[jj]= 0;
MDKOR.Mtkor[jj][0].d =0;
MDKOR.Mtkor[jj][0].s = 0;
MDKOR.Mtkor[jj][1].d = 0;
MDKOR.Mtkor[jj][1].s = 0;
MDKOR.MW[jj][0] = 0;
MDKOR.MW[jj][1] = 0;
MDKOR.MW[jj][2] = 0;
tip=2; //��� ������

PROV(tr1,p1,tip,tr,ps1,MDKOR,MDKOR); // ������� �� ����� �������
ts=tr;
DatRU.tnru1=ts;
DatRU.tkru1=ts;
DatRU.tnru2=ts;
DatRU.tkru2=ts;
DatRU.tnru3=ts;
DatRU.tkru3=ts;
DatRU.tnru4=ts;
DatRU.tkru4=ts;

tab1=ParRU.tab;
nru11=ParRU.nru1;
kru11=ParRU.kru1;
nru12=ParRU.nru2;
kru12=ParRU.kru2;


APSIDK(&ts,ps1,tip,0,1,&MDKOR,&ta1,pa1); //����� ������� ������ � ������
if (ta1.d<ts.d) {
	APSIDK(&ts,ps1,tip,1,1,&MDKOR,&ta1,pa1);
	Pma=1;
}
APSIDK(&ta1,pa1,tip,1,1,&MDKOR,&tsa2,psa2); //����� ������� ������ � ������
//����������� ������ �����
LapvKep(&Kac1,pa1);
SMJ2000(&ta1, &MJD);
ZVEWS(MJD, 0, &Sm);

   tn0.d=ta1.d;
   tn0.s=0;
   SMJ2000(&ta1,&SM);
   ZVEWS(SM,0.0,&SM);
   SMJ2000(&tn0,&SM0);
   ZVEWS(SM0,0.0,&SM0);

   eu = 2.0*atan(tan(-Kac1.wpi/2.0)*sqrt((1 - Kac1.e)/(1 + Kac1.e)));
   M0 = eu - Kac1.e*sin(eu);
tby = Kac1.tosk*(0.5 - M0/DVAPI); //����������� ������� ����������� ����

//����������� ������� ��
  dtt.d=0;
   dtt.s=tby;
   SLOGM(&ta1, &dtt, -1, &tn_by);

   SMJ2000(&tn_by,&SM_by);
   ZVEWS(SM_by,0.0,&SM_by);
   Lmd1=Kac1.om-SM_by;
   if (Lmd1<-PI) {
	   Lmd1=Lmd1+2*PI;
   }
///////////////////////////////
if (Lmd1*GRA>100&&Lmd1*GRA<175) { //���� ����� �1
	tssa[0]=ta1;
	tssa[1]=tsa2;
   dtt.d=0;
   dtt.s=tab1;
   SLOGM(&ta1, &dtt, -1, &t0_1);
   dtt.d=0;
   dtt.s=nru11;
   SLOGM(&t0_1, &dtt, 1, &DatRU.tnru1);
   if (DatRU.tnru1.d<ts.d) {
	 DatRU.tnru1=ts;
	 APSIDK(&ts,ps1,tip,2,1,&MDKOR,&ta12,pa12);
	 dtt.d=0;
	 dtt.s=tab1;
	 SLOGM(&ta12, &dtt, -1, &t0_12);
	 dtt.d=0;
	 dtt.s=nru11;
	 SLOGM(&t0_12, &dtt, 1, &DatRU.tnru3);
	 dtt.d=0;
	 dtt.s=kru11;
	 DatRU.tA3=ta12;
	 SLOGM(&t0_12, &dtt, 1, &DatRU.tkru3);
	 if (DatRU.tkru3.d>ts.d) {
	   DatRU.tkru3=ts;
	   DatRU.tkru3.s=86400;
	 }
   }

   dtt.d=0;
   dtt.s=kru11;
   SLOGM(&t0_1, &dtt, 1, &DatRU.tkru1);
   DatRU.tA1=ta1;

   dtt.d=0;
   dtt.s=nru12;
   SLOGM(&t0_1, &dtt, 1, &DatRU.tnru2);
   dtt.d=0;
   dtt.s=kru12;
   SLOGM(&t0_1, &dtt, 1, &DatRU.tkru2);
	DatRU.tA2=tsa2;
   if (DatRU.tkru2.d>ts.d) {
	   DatRU.tkru2=ts;
	   DatRU.tkru2.s=86400;
	   APSIDK(&ts,ps1,tip,-2,1,&MDKOR,&ta10,pa10);
	   APSIDK(&ts,ps1,tip,-1,1,&MDKOR,&ta12,pa10);
	   dtt.d=0;
	   dtt.s=tab1;
	   SLOGM(&ta10, &dtt, -1, &t0_10);
	   dtt.d=0;
	   dtt.s=kru12;
	   SLOGM(&t0_1, &dtt, 1, &DatRU.tkru4);
	   DatRU.tA4=ta12;
	   tnru14=ts;
   }
//////////////////////////////////////
  }else{ //���� ����� �2
	tssa[1]=ta1;
	tssa[0]=tsa2;
   APSIDK(&ts,ps1,tip,Pma-1,1,&MDKOR,&ta1,pa1);
   APSIDK(&ts,ps1,tip,Pma,1,&MDKOR,&ta12,pa1);
   dtt.d=0;
   dtt.s=tab1;
   SLOGM(&ta1, &dtt, -1, &t0_1);
   dtt.d=0;
   dtt.s=nru11;
   SLOGM(&t0_1, &dtt, 1, &DatRU.tnru1);
   DatRU.tA1=ta1;
   if (DatRU.tnru1.d<ts.d) {
	 DatRU.tnru1=ts;
   }
   dtt.d=0;
   dtt.s=kru11;
   SLOGM(&t0_1, &dtt, 1, &DatRU.tkru1);
   if (DatRU.tkru1.d<ts.d) {
	 DatRU.tkru1=ts;
   }

   dtt.d=0;
   dtt.s=nru12;
   SLOGM(&t0_1, &dtt, 1, &DatRU.tnru2);
   if (DatRU.tnru2.d<ts.d) {
	 DatRU.tnru2=ts;
   }
   dtt.d=0;
   dtt.s=kru12;
   SLOGM(&t0_1, &dtt, 1, &DatRU.tkru2);
   DatRU.tA2=ta12;

   APSIDK(&ts,ps1,tip,3,1,&MDKOR,&ta12,pa1);
   APSIDK(&ts,ps1,tip,2,1,&MDKOR,&ta1,pa1);
   dtt.d=0;
   dtt.s=tab1;
   SLOGM(&ta1, &dtt, -1, &t0_1);
   dtt.d=0;
   dtt.s=nru11;
   SLOGM(&t0_1, &dtt, 1, &DatRU.tnru3);
   dtt.d=0;
   dtt.s=kru11;
   SLOGM(&t0_1, &dtt, 1, &DatRU.tkru3);
   DatRU.tA3=ta1;
   if (DatRU.tkru3.d>ts.d) {
	   DatRU.tkru3=ts;
	   DatRU.tkru3.s=86400;
	}


   dtt.d=0;
   dtt.s=nru12;
   SLOGM(&t0_1, &dtt, 1, &DatRU.tnru4);
   if (DatRU.tnru4.d>ts.d) {
	   DatRU.tnru4=ts;
	   DatRU.tnru4.s=86400;
	}
   dtt.d=0;
   dtt.s=kru12;
	DatRU.tA4=ta12;
   SLOGM(&t0_1, &dtt, 1, &DatRU.tkru4);
   if (DatRU.tkru4.d>ts.d) {
	   DatRU.tkru4=ts;
	   DatRU.tkru4.s=86400;
	}
  }
//////////////////////////
s[0]="1������: "+ IntToStr(DatRU.tnru1.d)+" "+FloatToStr(DatRU.tnru1.s)+" - ������: "+ IntToStr(DatRU.tkru1.d)+" "+FloatToStr(DatRU.tkru1.s)+" A1: "+ IntToStr(DatRU.tA1.d)+" "+FloatToStr(DatRU.tA1.s)+";";
s[1]="2������: "+ IntToStr(DatRU.tnru2.d)+" "+FloatToStr(DatRU.tnru2.s)+" - ������: "+ IntToStr(DatRU.tkru2.d)+" "+FloatToStr(DatRU.tkru2.s)+" A2: "+ IntToStr(DatRU.tA2.d)+" "+FloatToStr(DatRU.tA2.s)+";";
s[2]="3������: "+ IntToStr(DatRU.tnru3.d)+" "+FloatToStr(DatRU.tnru3.s)+" - ������: "+ IntToStr(DatRU.tkru3.d)+" "+FloatToStr(DatRU.tkru3.s)+" A1: "+ IntToStr(DatRU.tA3.d)+" "+FloatToStr(DatRU.tA3.s)+";";
s[3]="4������: "+ IntToStr(DatRU.tnru4.d)+" "+FloatToStr(DatRU.tnru4.s)+" - ������: "+ IntToStr(DatRU.tkru4.d)+" "+FloatToStr(DatRU.tkru4.s)+" A2: "+ IntToStr(DatRU.tA4.d)+" "+FloatToStr(DatRU.tA4.s)+";";


historyMemo[0]=s[0];
historyMemo[1]=s[1];
historyMemo[2]=s[2];
historyMemo[3]=s[3];


 GLOBAL_tn1=DatRU.tnru1.s;
 GLOBAL_tk1=DatRU.tkru1.s;

 GLOBAL_tn2=DatRU.tnru2.s;
 GLOBAL_tk2=DatRU.tkru2.s;

 GLOBAL_tn3=DatRU.tnru3.s;
 GLOBAL_tk3=DatRU.tkru3.s;

 GLOBAL_tn4=DatRU.tnru4.s;
 GLOBAL_tk4=DatRU.tkru4.s;



}
//�� ���� � ��� �����! �� ������ ���� �����!!!!

int maxKa=0;
extern int step;//��� ��� ����������� �� ����� Graph
//���������� �������
int daysec = 86400;//������� � ������
double xstep=1;//��� �� ��� �
int ystep=0;//��� �� ��� �
int baseStepY =60;// ������� ��� �� ��� �

int cKa=0;//���������� ��������
int posY =1;//������� �� �� ��� � ������������ �������


TColor c1;
TColor c2;
int x1=0;
int y1=0;
int m = 45;

GraphSettings gs = GraphSettings();
void __fastcall TForm1::ClearGraph(TImage *img)//����� ������� ��������
{

	int mnoj=gs.step;

	xstep=step*m/mnoj;//
	int width = img->Width;
	int heigth = img->Height;
	img->Canvas->Brush->Color = clWhite;
	img->Canvas->Rectangle(0,0,width,heigth);

	TFont *canvasFont = new TFont;
	canvasFont = img->Canvas->Font;

	 LOGFONT logfont;//����� ��� ����������� ������� �� ��������� �����
	 logfont.lfEscapement = logfont.lfOrientation = 90*10;
	 logfont.lfHeight=10;
	 logfont.lfUnderline = false;
	 logfont.lfUnderline = false;
	 logfont.lfStrikeOut = false;
	 logfont.lfWeight =8;
	 logfont.lfWidth =4;



	 img->Canvas->Font->Handle = CreateFontIndirect(&logfont);
	double hour=0;
	int i =1;
	int colcount=25;
	int colcounter=0;
	switch(mnoj)
	{
		case 2: i=2; colcount*=2; break;
		case 3: i=3; colcount*=3; break;
		case 4: i=4; colcount*=4; break;
	}
	while(x1<=width && colcounter<colcount )//�������� ���� ����� ������(�)
	{

		img->Canvas->MoveTo(x1+xstep*hour,0);
		img->Canvas->LineTo(x1+xstep*hour,heigth);
		AnsiString h = FloatToStr(hour)+":00";//

		if(hour<25)
		{
		   img->Canvas->TextOutW(x1+xstep*colcounter*i,20,h);//
		}



		hour+=1;
		colcounter+=1;
	}
	img->Canvas->Font->Handle = (HFONT)canvasFont;
}

AnsiString a1s;
AnsiString a2s;
AnsiString a3s;
AnsiString a4s;

void __fastcall TForm1::DrawGraph(TImage *img, double tn1, double tk1,double tn2, double tk2, double tab,int num,AnsiString a1,AnsiString a2)
 {
	xstep=step;

	double a;
	double b;
	int width = img->Width;//����� ��������
	int heigth = img->Height;//������ ��������
	int y = 0;//��� ��������

	tn1=(24*tn1/daysec)*(xstep*m)+x1;//�������� ����� ������ 1 ��� ����������� ��������
	//((24 ���� * ������� ����� ������ / ������� � 24 ����� )* ��� �� ��� � * M(?)+ ��������� ����� ��������� �������)
	tk1=(24*tk1/daysec)*(xstep*m)+x1;//�������� ����� ����� 1 ��� ����������� ��������
	//
	tn2=(24*tn2/daysec)*(xstep*m)+x1;//�������� ����� ������ 2 ��� ����������� ��������
	tk2=(24*tk2/daysec)*(xstep*m)+x1;//�������� ����� ����� 2 ��� ����������� ��������
	//
	int rows = 0;//���������� ������������ �����
	int tx,LT;//
	double SXT;//
	//


		  while(y<=heigth && rows<=cKa   )//�������� ���� �� (�)
		{

			img->Canvas->MoveTo(0, y+ystep);//�������� ����� � ����������� �� ���������� ��
			y+=ystep;
			img->Canvas->LineTo(width,y);
			//

			if(gs.combineType==true)
			{
				if(tk1!=0)
				{
					img->Canvas->Brush->Color = drawable_color[num];//����� ����� ��� ����������� �������� �������
					img->Canvas->Rectangle(tn1,posY*ystep,tk1,ystep*posY+ystep);//������� �������� ������� 1
					LT=img->Canvas->TextWidth(a1s+";");//����� ������ �� �������� �������  ��� 1 ������� ��������
					SXT=(tn1+(tk1-tn1)*0.5);//���������� �������� �������� ������� 1 ��� ������ ������ ����������
					tx=(int)(SXT-LT*0.5);
					img->Canvas->Brush->Color = clWhite;//�������� ����
					img->Canvas->TextOutW(tx,ystep*posY+(ystep/2),a1+";");//����� ������ 1

				}
				if(tk2<86400 && tk2!=0 && tn2!=tk2)
				{
					img->Canvas->Brush->Color = drawable_color[num];//
					img->Canvas->Rectangle(tn2,posY*ystep,tk2,ystep*posY+ystep);//������� �������� ������� 2
					LT=img->Canvas->TextWidth(a2s+";"); //����� ������ �� �������� �������  ��� 2 ������� ��������
					SXT=(tn2+(tk2-tn2)*0.5); //���������� �������� �������� ������� 2 ��� ������ ������ ����������
					tx=(int)(SXT-LT*0.5);
					img->Canvas->Brush->Color = clWhite;//�������� ����
					img->Canvas->TextOutW(tx,ystep*posY+(ystep/2),a2+";"); //����� ������ 2
				}
			}


			if(gs.combineType==false)
			{
				int n;
				int k;
				switch(vitcount)
				{
				   case 0: n=0; k=1; break;
				   case 1: n=2; k=3; break;
				   default: vitcount=0; break;
                }

				if(tk1!=0)
				{
					img->Canvas->Brush->Color = drawable_color[n];//
					img->Canvas->Rectangle(tn1,posY*ystep,tk1,ystep*posY+ystep);
					LT=img->Canvas->TextWidth(a1s+";");
					SXT=(tn1+(tk1-tn1)*0.5);
					tx=(int)(SXT-LT*0.5);
					img->Canvas->Brush->Color = clWhite;
					img->Canvas->TextOutW(tx,ystep*posY+(ystep/2),a1+";");
				}
				if(tk2<86400 && tk2!=0 && tn2!=tk2)
				{

					img->Canvas->Brush->Color = drawable_color[k];//
					img->Canvas->Rectangle(tn2,posY*ystep,tk2,ystep*posY+ystep);
					LT=img->Canvas->TextWidth(a2s+";");
					SXT=(tn2+(tk2-tn2)*0.5);
					tx=(int)(SXT-LT*0.5);
					img->Canvas->Brush->Color = clWhite;
					img->Canvas->TextOutW(tx,ystep*posY+(ystep/2),a2+";");
				}

			}
			img->Canvas->TextOutW(0,y-ystep*0.7,rows);
			img->Canvas->Brush->Color = clWhite;//�������� ����
			rows++;


			vitcount++;



		}

	


 }
int active_max_ka=0;//���������� ��������� ��
void __fastcall TForm1::RedrawGraph(int maxka)//���������������� ������� ���������� �������
{
	posY=1;
	ystep=baseStepY;


	ClearGraph(Form2->img1);
	cKa=maxka;
    a1s = FloatToStr(DatRU.tA1.s);
	a2s = FloatToStr(DatRU.tA2.s);
	a3s = FloatToStr(DatRU.tA3.s);
	a4s = FloatToStr(DatRU.tA4.s);

	for(int i=0; i<maxka;i++)
	{
		DrawGraph(Form2->img1,fka[i].tn1,fka[i].tk1,fka[i].tn2,fka[i].tk2,fka[i].tab,i,a1s,a2s);//
		DrawGraph(Form2->img1,fka[i].tn3,fka[i].tk3,fka[i].tn4,fka[i].tk4,fka[i].tab,i,a3s,a4s);//


		posY++;
	}
	cKa=0;
}
void __fastcall TForm1::Button1Click(TObject *Sender)//��������� �������
{


	double p1[6],p2[6],rr[6][6],r2[6],ps1[6][6],ps2[6],pa1[6],pa2[6],pa12[6],pa10[6],pa20[6],psa2[6],pa22[6],Lmd1,Lmd2,Rz;
	KU_TimeDATA tn_by,tn0,t1[6],t2,ts,tn,dtt,ta10,tsa11,tsa12,tsa21,tsa22,tsa2,tssa[6][2];
	KU_DateDATA Ds;
	KU_TimeDATA ta1,ta12,t0_1,t0_10,t0_12,tnru11,tnru12,tkru11,tkru12,t0_2,tnru21,tnru22,tkru21,tkru22,tnru13,tnru14,tkru13,tkru14;
	KU_TimeDATA ta2,ta22,ta20,tnru23,tnru24,tkru23,tkru24;
	int Pru1,Pru2,Pma,ii;
	double GRA,alf,PI,DVAPI;
	AnsiString s1[6];
	//coil();
	active_max_ka=0;
	RGB_Randomize rgb =  RGB_Randomize();
	rgb.GetColor();
	// ���� �������

	ts.d=StrToInt(Edk->Text);//
	ts.s=0.0;

	ClearGraph(Form2->img1);

	posY=1;

	ystep=baseStepY;

	for(int i=0; i<4;i++)//����� ��� �� ��� ������ ����������
	{
		c2= rgb.GetColor();
		drawable_color2[i]=c2;
    }

	for (int i = 0; i < kaList->Count; i++)//��������� �������
	{if(kaList->Checked[i]){cKa++;if(cKa >= 10){ystep = ystep/2;}}}//��������� �������

	int j=0;
	for (int i = 0; i < kaList->Count; i++)
	{
	  if(kaList->Checked[i])
	  {
		if(cKa>10)//����������� �� ����� ��������� ��
		{ShowMessage("���������� ������� ������ 10 �� ��� ���������� �������");return;}
		else
		{

			ParRU.tab=ka[i].ru[0];
			ParRU.nru1=ka[i].ru[1];
			ParRU.kru1=ka[i].ru[2];
			ParRU.nru2=ka[i].ru[3];
			ParRU.kru2=ka[i].ru[4];

			GetTimeA12(ka[i].r,ka[i].ts,ts, s1);//

			c1 = rgb.GetColor();


			//
			drawable_color[j] = c1;
			fka[j].name = i;


			fka[j].tn1=GLOBAL_tn1;
			fka[j].tk1=GLOBAL_tk1;
			fka[j].tn2=GLOBAL_tn2;
			fka[j].tk2=GLOBAL_tk2;
			fka[j].tn3=GLOBAL_tn3;
			fka[j].tk3=GLOBAL_tk3;
			fka[j].tn4=GLOBAL_tn4;
			fka[j].tk4=GLOBAL_tk4;
			fka[j].tab=ParRU.tab;

			//


			 a1s = FloatToStr(DatRU.tA1.s);
			 a2s = FloatToStr(DatRU.tA2.s);
			 a3s = FloatToStr(DatRU.tA3.s);
			 a4s = FloatToStr(DatRU.tA4.s);

			DrawGraph(Form2->img1,GLOBAL_tn1,GLOBAL_tk1,GLOBAL_tn2,GLOBAL_tk2,ParRU.tab,i,a1s,a2s);//
			DrawGraph(Form2->img1,GLOBAL_tn3,GLOBAL_tk3,GLOBAL_tn4,GLOBAL_tk4,ParRU.tab,i,a3s,a4s);//


			posY++;
			active_max_ka++;

			j++;
		}
	  }
	}
	Form2->Visible=true;
	active_max_ka = cKa;
	cKa=0;
	for(int i = 0; i<4;i++)
	{
	  Mem1->Lines->Add(historyMemo[i]);
	}



}
//---------------------------------------------------------------------------
void __fastcall TForm1::btnOpenClick(TObject *Sender)
{
	ofd1->Execute();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ofd1CanClose(TObject *Sender, bool &CanClose)
{
	kaList->Clear();
	AnsiString path = ofd1->FileName;

	if(AnsiLowerCase(ExtractFileExt(path))==".txt")
	{
	FILE *data;

	 fopen_s(&data,path.c_str(),"r");
	 fscanf(data,"%d",&maxKa);
	 for (int i = 0; i < maxKa; i++)
	 {
	   fscanf(data,"%d",&ka[i].name);
	   kaList->Items->Add("KA �"+IntToStr(ka[i].name));//!

	   fscanf(data,"%lf %lf %lf %lf %lf %lf",&ka[i].r[0],&ka[i].r[1],&ka[i].r[2],&ka[i].r[3],&ka[i].r[4],&ka[i].r[5]);
	   fscanf(data,"%d %lf",&ka[i].ts.d,&ka[i].ts.s);
	   fscanf(data,"%d %d %d %d %d",&ka[i].ru[0],&ka[i].ru[1],&ka[i].ru[2],&ka[i].ru[3],&ka[i].ru[4]);
	 }

	  fclose(data);
	}
	else
	if(AnsiLowerCase(ExtractFileExt(path))==".csv")
	{
	  readEOF(path,Form1,ka);
	}



	Button1->Enabled = true;
	selectedFilePath = path;
	kaList->Selected[0]=true;
	kaListClick(Sender);



}
//---------------------------------------------------------------------------
void __fastcall TForm1::kaListClick(TObject *Sender)
{
	int items = kaList->Count;
	 for(int i = 0; i<items; i++)
	 {
		if(kaList->Selected[i]==true)
		{
			 Er_1->Text=ka[i].r[0];
			 Ev_1->Text=ka[i].r[1];
			 Etet_1->Text=ka[i].r[2];
			 Ei_1->Text=ka[i].r[3];
			 Eo_1->Text=ka[i].r[4];
			 Eu_1->Text=ka[i].r[5];

			 LE_tab->Text=ka[i].ru[0];
			 LE_nru1->Text=ka[i].ru[1];
			 LE_kru1->Text=ka[i].ru[2];
			 LE_nru2->Text=ka[i].ru[3];
			 LE_kru2->Text=ka[i].ru[4];

			 Ed_1->Text=ka[i].ts.d;
			 Es_1->Text=ka[i].ts.s;

			 //etA1->Text = ka[i].A1;//
			 //etA2->Text = ka[i].A2;//
		}
	 }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::btnAddClick(TObject *Sender)
{

		try
		{
		ka[maxKa].name = ka[maxKa-1].name+1;
		AnsiString nm = "�� �"+IntToStr(ka[maxKa].name);
		ka[maxKa].r[0] =  StrToFloat(Er_1->Text);
		ka[maxKa].r[1] =  StrToFloat(Ev_1->Text);
		ka[maxKa].r[2] =  StrToFloat(Etet_1->Text);
		ka[maxKa].r[3] =  StrToFloat(Ei_1->Text);
		ka[maxKa].r[4] =  StrToFloat(Eo_1->Text);
		ka[maxKa].r[5] =  StrToFloat(Eu_1->Text);

		ka[maxKa].ru[0] =  StrToInt(LE_tab->Text);
		ka[maxKa].ru[1] =  StrToInt(LE_nru1->Text);
		ka[maxKa].ru[2] =  StrToInt(LE_kru1->Text);
		ka[maxKa].ru[3] =  StrToInt(LE_nru2->Text);
		ka[maxKa].ru[4] =  StrToInt(LE_kru2->Text);

		ka[maxKa].ts.d =StrToInt(Ed_1->Text);
		ka[maxKa].ts.s=StrToFloat(Es_1->Text);

		maxKa++;

		kaList->Items->Add(nm);
		ShowMessage("�� ��������!");
		}
		catch(Exception& e)
		{
			ShowMessage("������ ������ ������! ������������ ������");
		}

}
//---------------------------------------------------------------------------
void Delemass(int ii)//������� ��������� ��
{  int i;
	for (i = ii; i < maxKa; i++) {
	 ka[i]=ka[i+1];
	}
	maxKa--;
}
void __fastcall TForm1::btnDeleteClick(TObject *Sender)
{
	for(int i =0; i<kaList->Count; i++)
	{
	  if(kaList->Selected[i]==true)
	  {
		 kaList->Items->Delete(i);
		 Delemass(i);
		 ShowMessage("������� ������!");
	  }
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::btnEditClick(TObject *Sender)
{
	try
	{
           	for(int i =0; i<kaList->Count; i++)
	{
	  if(kaList->Selected[i]==true)
	  {
		ka[i].r[0] =  StrToFloat(Er_1->Text);
		ka[i].r[1] =  StrToFloat(Ev_1->Text);
		ka[i].r[2] =  StrToFloat(Etet_1->Text);
		ka[i].r[3] =  StrToFloat(Ei_1->Text);
		ka[i].r[4] =  StrToFloat(Eo_1->Text);
		ka[i].r[5] =  StrToFloat(Eu_1->Text);

		ka[i].ru[0] =  StrToInt(LE_tab->Text);
		ka[i].ru[1] =  StrToInt(LE_nru1->Text);
		ka[i].ru[2] =  StrToInt(LE_kru1->Text);
		ka[i].ru[3] =  StrToInt(LE_nru2->Text);
		ka[i].ru[4] =  StrToInt(LE_kru2->Text);

		ka[i].ts.d = StrToInt(Ed_1->Text);
		ka[i].ts.s = StrToFloat(Es_1->Text);


	  }
	}
	ShowMessage("�� �������!");
	}
	catch(Exception& e)
	{
		ShowMessage("������ ������ ������! ������������ ������");
	}

}
//---------------------------------------------------------------------------
void __fastcall TForm1::btnSaveFileClick(TObject *Sender)
{
	if(selectedFilePath != "")
	{

		AnsiString p = selectedFilePath;
//		FILE *data;
//
//		fopen_s(&data,p.c_str(),"w");
//
//		fprintf(data,"%d \n",maxKa);
//		for(int i =0; i<kaList->Count; i++)
//		{
//			fprintf(data,"%d \n",ka[i].name);
//			fprintf(data,"%10.16e %10.16e %10.16e %10.16e %10.16e %10.16e \n",ka[i].r[0],ka[i].r[1],ka[i].r[2],ka[i].r[3],ka[i].r[4],ka[i].r[5]);//
//			fprintf(data, "%d %10.16f \n", ka[i].ts.d,ka[i].ts.s);//
//			fprintf(data, "%d %d %d %d %d \n",ka[i].ru[0],ka[i].ru[1],ka[i].ru[2],ka[i].ru[3],ka[i].ru[4]);//
//
//		}
//		fclose(data);


		if(AnsiLowerCase(ExtractFileExt(p))==".txt")
		{
			FILE *data;
			fopen_s(&data,p.c_str(),"w");
			fprintf(data,"%d \n",maxKa);
			for(int i =0; i<kaList->Count; i++)
			{
				fprintf(data,"%d \n",ka[i].name);
				fprintf(data,"%10.16e %10.16e %10.16e %10.16e %10.16e %10.16e \n",ka[i].r[0],ka[i].r[1],ka[i].r[2],ka[i].r[3],ka[i].r[4],ka[i].r[5]);//
				fprintf(data, "%d %10.16f \n", ka[i].ts.d,ka[i].ts.s);//
				fprintf(data, "%d %d %d %d %d \n",ka[i].ru[0],ka[i].ru[1],ka[i].ru[2],ka[i].ru[3],ka[i].ru[4]);//
			}
			fclose(data);
		}
		else
		if(AnsiLowerCase(ExtractFileExt(p))==".csv")
		{
		  writeCsv(p,ka);
		}


		ShowMessage("���������");
	}
	else ShowMessage("���� �� ������!");
}
//---------------------------------------------------------------------------
void __fastcall TForm1::sfd1CanClose(TObject *Sender, bool &CanClose)
{
	AnsiString savePath ="";
	savePath =  sfd1->FileName;

	if(sfd1->FilterIndex==1)//index 1 - txt
	{
	  savePath+=".txt";
	}
	else if (sfd1->FilterIndex==2)//index 2 -  csv
	{
	  savePath+=".csv";		 
	}
	
	selectedFilePath = savePath;
	btnSaveFileClick(Sender);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::btnFileCreateClick(TObject *Sender)
{
	if(sfd1->Execute());
}
//---------------------------------------------------------------------------
void __fastcall TForm1::selectAllClick(TObject *Sender)
{
   if(selectAll->Checked==true)
   {
	kaList->CheckAll(cbChecked,true,false);
   }
   else for (int i = 0; i < kaList->Count; i++) kaList->Checked[i]=false;
   kaListClickCheck(Sender);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::kaListClickCheck(TObject *Sender)
{
	int items = kaList->Count;
	int checkeditms =0;
	 for(int i = 0; i<items; i++)
	 {
		if(kaList->Checked[i]==true)
		{
		   checkeditms++;
		}
	 }
	 if(checkeditms>0)  Button1->Enabled=true; else Button1->Enabled=false;
}
//--------------------------------------------------------------------------- 
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                 
void __fastcall TForm1::btnSettingsClick(TObject *Sender)
{
	gs.showWin();
}
//---------------------------------------------------------------------------
int edkChange;
int kaEdchange;
void __fastcall TForm1::FormCreate(TObject *Sender)
{
	gs = GraphSettings(true,1,10);
	edkChange=0;
	kaEdchange=0;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::btnEnterVectorClick(TObject *Sender)
{
   Form5->Visible=true;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::EdkChange(TObject *Sender)//����������� ������
{
  if(Edk->Text!="" && edkChange==0)
  {
	KU_TimeDATA t;
	t.d =StrToInt(Edk->Text);
	t.s =0.0;
	KU_DateDATA D;

	SKD2000(&t,&D);
	Eyc->Text=D.y;
	Emc->Text=D.m;
	Edc->Text=D.d;
  }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::EycChange(TObject *Sender)
{

  if(Eyc->Text!="" && Emc->Text!="" && Edc->Text!="" && edkChange==1)
  {
	KU_TimeDATA t;
	KU_DateDATA d;
	d.y = StrToInt(Eyc->Text);
	d.m = StrToInt(Emc->Text);
	d.d = StrToInt(Edc->Text);
	d.h = 0;
	d.min = 0;
	d.sec = 0;

	KDS2000(&d,&t);
	Edk->Text=t.d;
  }

}
//---------------------------------------------------------------------------
void __fastcall TForm1::EdkClick(TObject *Sender)
{
	edkChange=0;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::EycClick(TObject *Sender)
{
	 edkChange=1;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Ed_1Change(TObject *Sender)
{
  if(Ed_1->Text!="" && Es_1->Text!="" && kaEdchange==0 )
  {
	KU_TimeDATA t;
	t.d =StrToInt(Ed_1->Text);
	t.s =StrToFloat(Es_1->Text);
	KU_DateDATA D;

	SKD2000(&t,&D);

	kaEyc->Text=D.y;
	kaEmc->Text=D.m;
	kaEdc->Text=D.d;
	kaEhc->Text=D.h;
	kaEmic->Text=D.min;
	kaEsc->Text=D.sec;
  }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Ed_1Click(TObject *Sender)
{
 kaEdchange=0;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::kaEycChange(TObject *Sender)
{
	if(kaEyc->Text!="" && kaEmc->Text!="" && kaEdc->Text!="" &&
	kaEhc->Text!="" && kaEmic->Text!="" && kaEsc->Text!="" &&
	 kaEdchange==1)
	  {
		KU_TimeDATA t;
		KU_DateDATA d;
		d.y = StrToInt(kaEyc->Text);
		d.m = StrToInt(kaEmc->Text);
		d.d = StrToInt(kaEdc->Text);
		d.h = StrToFloat(kaEhc->Text);
		d.min = StrToFloat(kaEmic->Text);
		d.sec = StrToFloat(kaEsc->Text);

		KDS2000(&d,&t);
		Ed_1->Text=t.d;
		Es_1->Text=t.s;
	  }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::kaEycClick(TObject *Sender)
{
	kaEdchange=1;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormClose(TObject *Sender, TCloseAction &Action)
{ if(selectedFilePath!="")
	{
         if(
		  MessageDlg("��������� ��������� ��������� �����?",mtConfirmation,TMsgDlgButtons()<<
		  mbYes<<mbNo,0)==mrYes)
		  {
			btnSaveFileClick(Sender);
			Application->Terminate();
		  }
	}


}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender)
{


     for(int i =0; i<kaList->Count; i++)
	 {
		if(kaList->Selected[i]==true)
		{
		  Kosmo kac;
		  kac=ka[i];

		  KU_TimeDATA td;
		  td.d=StrToFloat(Edk->Text);
		  td.s=0.0;

		  StatF2i(kac.r,kac.ts,td,60,Form6);

		}
	 }







}
//---------------------------------------------------------------------------


