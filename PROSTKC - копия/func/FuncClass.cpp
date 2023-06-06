#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdarg.h>
#include <math.h>
#include <vcl.h>


#include "Unit1.h"
#include "proc1.h"
#include "Graph2.h"
#include "Unit6.h"

#include "XKY_HBO_4_1.h"
#include "XKY_HBO_4_2.h"
#include "XKY_HBO_4_6.h"
#include "coil.h"
#include "Graph.h"

#include "XKY_HBO_5_0.h"
#include "Strukts.h"
//������� ��������� ���������� �� ���� ������� (Graph2.cpp)
void StatF(double rv[6],KU_TimeDATA tv,KU_TimeDATA tns,KU_TimeDATA tks, double dts, TForm3 *tform3)

{
double rn[6],ps[6],pn[6],pk[6],pk1[6],pt[6],rtn[3],Rs[3],Rl[3],Rka[3],Rks[3],Rkl[3],XS[4],XL[4],R_tn,sh_tn,d_tn,GRA,Rz,gamma;
double r[3],v[3],MJD,Sm,rZ,roZ,rr,rks,rot,droZ,droL,rkl,rol,RRL,tm,duS,PI,RZ;
int Pg, np,Pt,a3,a4;
KU_OSKP Kac;

KU_TimeDATA ts,ta1,ta2,tnru1,tnru2,tkru1,tkru2,tn,tk,tnd,tnp,dt,dtru,tnru,del_t,tt;
	KU_DateDATA D;
	KU_MKOR MDKOR;
	int jj,tip,ii,a1,a2;
	AnsiString SS;
 GRA=57.2957795130823252;
 PI=3.141592653589793;
RZ=6371.0;
RRL=1738.4;
del_t.d=0;
del_t.s=dts;
dtru.d=0;
dtru.s=12600.0;
droZ=0.021;
droL=0.021;
tm=0.0;
Pt = 0;
//--------
tform3->SeriesPt->Clear();//
tform3->Series_Ug->Clear();//
//tform3->Series_RUg->Clear();//
//tform3->SeriesRU->Clear(); //
//-------
RIPM(rv, pn);
tn=tv;




	MDKOR.n_kor=0;
	jj=0;
	MDKOR.TIPkor[jj]= 0;
	MDKOR.Mtkor[jj][0].d =0;
	MDKOR.Mtkor[jj][0].s = 0;
	MDKOR.Mtkor[jj][1].d = 0;
	MDKOR.Mtkor[jj][1].s = 0;
	MDKOR.MW[jj][0] = 0;
	MDKOR.MW[jj][1] = 0;
	MDKOR.MW[jj][2] = 0;
tip=2;

SKD2000(&tns,&D);
PROV(tn,pn,tip,tns,pn,MDKOR,MDKOR);
LapvKep(&Kac,pn);
KA_RkaVka2(Kac,r,v);
avb(r,Rka);
SMJ2000(&tns, &MJD);
ZVEWS(MJD, 0, &Sm);
LUNM(MJD, 2, XL);
Rl[0]=XL[0]*XL[3];
Rl[1]=XL[1]*XL[3];
Rl[2]=XL[2]*XL[3];

SOLM(MJD, 2, XS);
Rs[0]=XS[0]*XS[3];
Rs[1]=XS[1]*XS[3];
Rs[2]=XS[2]*XS[3];
tm= tnru.s/3600;
	rZ = sqrt(Rka[0]*Rka[0] + Rka[1]*Rka[1] + Rka[2]*Rka[2]);
	roZ = asin(Rz/(rZ));
	/////////////////////////////////////////////TENI////////////////////////////////////////
	lkomb(1.0, Rs, -1.0, Rka, Rks);
	rr = modul(Rka);
	rks = modul(Rks);
	rot = PI - arccs(skalpr( Rka, Rks)/rr/rks);
	if( rot <= roZ + droZ)
	{	Pt = 1;
		duS=0;
	}
	else{
		Pt = 0;
		lkomb(1.0, Rl, -1.0, Rka, Rkl);
		rkl = modul(Rkl);
		rot = arccs(skalpr( Rkl, Rks)/rkl/rks);
		rol = arcsn(RRL/rkl);
		if( rot <= rol + droL)
		Pt = 2;
		duS= 180*(arccs(skalpr( Rkl, Rks)/rkl/rks))/PI;
	}

SS=IntToStr(D.h)+":"+IntToStr(D.min)+":"+FloatToStr(floor(D.sec));
//------------------------------------------------------------------
tform3->SeriesPt->AddXY(tm,Pt,SS);
tform3->Series_Ug->AddXY(tm,duS,SS);
//------------------------------------------------------------------
/////////////////////////////////////////////////////////////////////////////////////////////
if (tns.d==tks.d) {
   np =(int)((tks.s-tns.s)/del_t.s);
}else{
   np =(int)(((86400-tns.s)+tks.s)/del_t.s);
}

for (ii = 0; ii < np; ii++) {
	SLOGM(&tns, &del_t, 1, &tt);
	PROV(tns,pn,tip,tt,pn,MDKOR,MDKOR);
	LapvKep(&Kac,pn);
	KA_RkaVka2(Kac,r,v);
	avb(r,Rka);
	SKD2000(&tt,&D);
	SMJ2000(&tt, &MJD);

	LUNM(MJD, 2, XL);
	Rl[0]=XL[0]*XL[3];
	Rl[1]=XL[1]*XL[3];
	Rl[2]=XL[2]*XL[3];

	SOLM(MJD, 2, XS);
	Rs[0]=XS[0]*XS[3];
	Rs[1]=XS[1]*XS[3];
	Rs[2]=XS[2]*XS[3];


	rZ = sqrt(Rka[0]*Rka[0] + Rka[1]*Rka[1] + Rka[2]*Rka[2]);
	roZ = asin(RZ/(rZ));

SS=IntToStr(D.h)+":"+IntToStr(D.min)+":"+FloatToStr(floor(D.sec));
/////////////////////////////////////////////TENI////////////////////////////////////////
	lkomb(1.0, Rs, -1.0, Rka, Rks);
	rr = modul(Rka);
	rks = modul(Rks);
	rot = PI - arccs(skalpr( Rka, Rks)/rr/rks);
	//
	tform3->SeriesPt->AddXY(tm,Pt,SS);
	//
	if( rot <= roZ + droZ)
	{	Pt = 1;
		duS=0;
    }
	else{
		Pt = 0;
		lkomb(1.0, Rl, -1.0, Rka, Rkl);
		rkl = modul(Rkl);
		rot = arccs(skalpr( Rkl, Rks)/rkl/rks);
		rol = arcsn(RRL/rkl);
		if( rot <= rol + droL)
		Pt = 2;
		duS= 180*(arccs(skalpr( Rkl, Rks)/rkl/rks))/PI;
	}
/////////////////////////////////////////////////////////////////////////////////////////////

	SCOVM (&tt,&tns, &a1 );
	SCOVM (&tt,&tks, &a2 );

	if ((a1<0||a4>0)) {
	  //
//	  tform3->SeriesRU->AddXY(tm,2.5);
//	  tform3->Series_RUg->AddXY(tm,3);
	   //
	}
	//
	tform3->SeriesPt->AddXY(tm,Pt,SS);
	tform3->Series_Ug->AddXY(tm,duS,SS);
	//

tm=tm+del_t.s/3600;



	SS= IntToStr(tnru.d)+" "+FloatToStr(tnru.s)+
" "+IntToStr(D.y)+" "+IntToStr(D.m)+" "+IntToStr(D.d)+" "+IntToStr(D.h)+" "+IntToStr(D.min)+" "+FloatToStr(D.sec)+" "+FloatToStr(duS)+" "
+FloatToStr(r[0])+" "+FloatToStr(r[1])+" "+FloatToStr(r[2])+" "+
FloatToStr(Rs[0])+" "+FloatToStr(Rs[1])+" "+FloatToStr(Rs[2])+" "+
FloatToStr(Rl[0])+" "+FloatToStr(Rl[1])+" "+FloatToStr(Rl[2]);

	tns=tt;
}
   //
   tform3->Show();
   //



}

void R3toDSR(double Rka[3],double *Sh,double *D,double *R)
{
double PI;
PI=3.141592653589793;
  *R=modul(Rka);
  if (*R==0) {
	*Sh=0;
	*D=0;
  }else{
	 *Sh=arcsn(Rka[2]/(*R));
	 *D=atan(Rka[1]/Rka[0]);
	 if (Rka[0]<0) {
	   *D=PI+*D;
	 }
//	 *D=arcsn(Rka[1]/(*R*sqrt(1-(Rka[2]/(*R))*(Rka[2]/(*R)))));
  }

}
//������� ��� ����������� ������
//�������� �������
//�������
//����� � ������� ��������
//���� �������
//��� ��� ���������� ������� (=60)
//����� � ��������
void StatF2i(double rv[6],KU_TimeDATA tv,KU_TimeDATA tns, double dts, TForm6 *tform6)//
{
double rn[6],ps[6],pn[6],pk[6],pk1[6],pt[6],rtn[3],Rs[3],Rl[3],Rka[3],Rks[3],Rkl[3],XS[4],XL[4],R_tn,sh_tn,d_tn,GRA,Rz,gamma;
double r[3],v[3],MJD,Sm,rZ,roZ,rr,rks,rot,droZ,droL,rkl,rol,RRL,tm,duS,PI,RZ,Shk,Dk,Rk,SMp;
int Pg, np,Pt,a3,a4;
KU_OSKP Kac;

KU_TimeDATA ts,ta1,ta2,tnru1,tnru2,tkru1,tkru2,tn,tk,tnd,tnp,dt,dtru,tnru,del_t,tt;
	KU_DateDATA D;
	KU_MKOR MDKOR;
	int jj,tip,ii,a1,a2;
	AnsiString SS;
 GRA=57.2957795130823252;
 PI=3.141592653589793;
RZ=6371.0;
RRL=1738.4;
del_t.d=0;
del_t.s=dts;
dtru.d=0;
dtru.s=12600.0;
droZ=0.021;
droL=0.021;
tm=0.0;
Pt = 0;

tform6->Series1->Clear();//

RIPM(rv, pn);
tn=tv;




	MDKOR.n_kor=0;
	jj=0;
	MDKOR.TIPkor[jj]= 0;
	MDKOR.Mtkor[jj][0].d =0;
	MDKOR.Mtkor[jj][0].s = 0;
	MDKOR.Mtkor[jj][1].d = 0;
	MDKOR.Mtkor[jj][1].s = 0;
	MDKOR.MW[jj][0] = 0;
	MDKOR.MW[jj][1] = 0;
	MDKOR.MW[jj][2] = 0;
tip=2;

SKD2000(&tns,&D);
PROV(tn,pn,tip,tns,pn,MDKOR,MDKOR);
SMJ2000(&tns, &MJD);
ZVEWS(MJD, 0, &SMp);
LapvKep(&Kac,pn);
KA_RkaVka2(Kac,r,v);
R3toDSR(r,&Shk,&Dk,&Rk);
Dk=Dk-SMp;
if (Dk>PI) {
  Dk=Dk-2*PI;
}
if (Dk<-PI) {
  Dk=Dk+2*PI;
}
//------------------------------------------------------------------
tform6->Series1->AddXY(Dk*GRA,Shk*GRA);

//��� ��� ����� ���������� ������ ��
np =(int)(86400/del_t.s);


for (ii = 0; ii < np; ii++) {
	SLOGM(&tns, &del_t, 1, &tt);
	PROV(tns,pn,tip,tt,pn,MDKOR,MDKOR);
	SMJ2000(&tt, &MJD);
	ZVEWS(MJD, 0, &SMp);
	LapvKep(&Kac,pn);
	KA_RkaVka2(Kac,r,v);
	R3toDSR(r,&Shk,&Dk,&Rk);
	Dk=Dk-SMp;
	if (Dk>PI) {
  Dk=Dk-2*PI;
}
if (Dk<-PI) {
  Dk=Dk+2*PI;
}
tform6->Series1->AddXY(Dk*GRA,Shk*GRA);
//��� ����� �����
	tns=tt;
}
   //
   tform6->Show();
   //

}
