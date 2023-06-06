#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdarg.h>
#include <math.h>
#include <vcl.h>
#include "Unit1.h"
#include "proc1.h"
#include "XKY_HBO_4_1.h"
#include "XKY_HBO_4_2.h"
#include "XKY_HBO_4_6.h"
#include "coil.h"
#include "Graph.h"
#include "XKY_HBO_5_0.h"
#include "Strukts.h"
#include "Graph.h"

 void ClearSelection(TImage *img)
 {
	img->Picture->Bitmap = NULL;
 }
 void DrawSelection(TImage *img, double x1,double x2, double y1, double y2)
 {

    img->Canvas->Pen->Width = 5;
	img->Canvas->Pen->Color = clWhite;
	img->Canvas->Rectangle(0,0,img->Width,img->Height);

	img->Canvas->Pen->Color = clRed;
	img->Canvas->Rectangle(x1,y1,x2,y2);
 }

