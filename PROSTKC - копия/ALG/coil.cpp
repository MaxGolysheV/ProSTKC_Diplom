//#include "stdafx.h"
#include <vcl.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* ������ ��� ���������� ������� � ������� ����������  */
int    M_PECH[50];
/* ������ ��� ���������� ������� � inskor  */
int mpint[40];
/* ������ ��� ���������� ������� � INTU_KOR  */
int M_P_INTK[10];


double MKC[35];/* ����. 7 ������ */
double TKOC[300];/* ��������� */  // zavisit ot razmera faila tkos




void coil(void)
	{
	 int Kpost;
	 int N_TKOC, N_TKOCmax;
	 int i,j;
	 char  kolich [100];
	 FILE *inpt;
  //	 inpt= fopen("mc.txt","r");
 //	 fopen_s(&inpt,"MKC.txt", "r");
	 /*  ������ MKC �� ����a  MKC.txt*/
 //	 fopen_s(&inpt, "MKC.txt", "r");

 /*	 if (inpt == NULL)
	 {
		 fprintf(stderr, "1 Cannot open input file MKC.txt\n");
		 exit(0);
	 }  */

 //	 fgets (kolich,100,inpt);
 //	 fscanf_s(inpt, "%d \n", &Kpost);                            /* Kpost */
//	 fgets (kolich,100,inpt);
//	 for (i=0; i<Kpost*5;i++)
//	 {
//         fscanf_s(inpt, " %s \n", kolich, 100);
/* 03.10.2006 */
//         MKC[i]   = atof ( kolich);
//	 }
//     fclose(inpt);/* MKC.txt  */
//	 inpt=NULL;
/*  ������ TKOC[] �� ����a  TKOC_2000.txt*/
	 fopen_s(&inpt, "TKOC_2000.txt", "r");

 /*	if (inpt == NULL)
	 {
	     fprintf(stderr, "1 Cannot open input file TKOC_2000.txt.txt.\n");
		 exit(0);
	 }  */


	 fgets (kolich,100,inpt);
	 fscanf_s(inpt, "%d \n", &N_TKOCmax);                        /* N_TKOCmax */
		for (i=0; i<N_TKOCmax; i++)
		{
           TKOC[i] = 1.0e+17;
		}
     fgets (kolich,100,inpt);
	 fscanf_s(inpt, "%d \n", &N_TKOC);                           /* N_TKOC */
	 for (i=0; i<N_TKOC;i++)
	 {
         fgets (kolich,100,inpt);
		 fscanf_s(inpt, " %d  %s \n", &j, kolich, 100);
         TKOC[i]   = atof ( kolich);
	 }
     fclose(inpt);/* TKOC_2000.txt  */


/* ��������� ������� ��������� ������ ��� ��������� int92 */
	 	for (i=0; i<40;i++)
		{
		     mpint[i] = 0;
		}
/* ��������� ������a ��������� ������ ��� ��������� INTU_KOR  */
	 	for (i=0; i<10;i++)
		{
		     M_P_INTK[i] = 0;
		}
	 	for (i=0; i<50;i++)
		{
		     M_PECH[i] = 0;
		}
	   return;
}