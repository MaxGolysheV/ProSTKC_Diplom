/*
** proc.h
*/

#ifndef _PROCH
#define _PROCH
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <math.h>
#include <Vcl.ExtCtrls.hpp>
#include "XKY_HBO_5_0.h"

double STF(AnsiString SS);
void STFi3gms(AnsiString SS,
			double *p0, double *p1,double *p2);
void STFi6(AnsiString SS,
			double *p0, double *p1,double *p2,double *p3,double *p4,double *p5);
void umnmatrv(double a[3][3],double v[3],
			  double v1[3]);
double uvsk(double a[3],double b[3]);
double arcsn(double x );
double arccs(double x);
double modul(double xv[3]);
double ugol(double x[3],double y[3]);
double arcsincirc(double si,double co);
int sign(double x);
void umnmama(double a[3][3],double b[3][3],  double ab[3][3]);
void transma(double a[3][3], double at[3][3]);
double skalpr(double x[3],double y[3]);
void lkomb(double a,double va[3],double b,double vb[3],double c[3]);
void vektumn(double v1[3],double v2[3],double v3[3]);
void zapoln(double m[3][3],double m00,double m01,double m02,
                           double m10,double m11,double m12,
                           double m20,double m21,double m22 );
void mxp(double x,double m[3][3]);
void myp(double y,double m[3][3]);
void mzp(double z,double m[3][3]);
int normv(double x[3]);
double randr(double *randm);
double randn(double mo,double si);
void radgrmi(double rad, int *gr, double *mi);
void perdsrx(double d, double s, double r, double xv[3]);
void perxdsr( double xv[3], double *d, double *s, double *r);
void normRasp( double *r);
void mtrxlim(int n,double buf[],double *efmax,double *efmin,double *efsr);
void minusA(double A[3][3],double B[3][3]);
double det(double A[3][3],int i,int j);
void minusA4(double A[4][4],double B[4][4]);
double det3(double A[4][4],int i,int j);
void minusA5(double A[5][5],double B[5][5]);
double det4(double A[5][5],int i,int j);
void umnmama5(double a[5][5],double b[5][5], double ab[5][5]);
void transma4(double a[4][4],  double at[4][4]);
void maAvmaB(double A[][3],double B[][3]);
void avb(double a[3],double b[3]);
void avb6(double a[3],double b[3]);
void uvv(double a[3],double b[3],double c[3]);
void normv1(double a[3], double b[3]);
 void umm(double a[3][3],double b[3][3], double c[3][3]);
 double modv(double a[3]);
void KepvLap(
			 KU_OSKP ka,
			 double p[6]
			 );
void RkaVka_KA(
			KU_OSKP *ka,
			double Rka[3],
			double Vka[3]
			);
 void KA_RkaVka2(
			KU_OSKP ka,
			double Rka[3],
			double Vka[3]
			);
 void LapvKep(
			 KU_OSKP *ka,
			 double p[6]
			 );
 int SCOVM (KU_TimeDATA *t1,KU_TimeDATA *t2, int *a );
 void umv1(double a[3][3],double b[3], double c[3]);
 double GetUm(double Sh,double D, double H,double Rka[3],double Sm);
#endif
