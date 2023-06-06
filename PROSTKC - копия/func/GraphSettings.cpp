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
#include "XKY_HBO_5_0.h"
#include "Strukts.h"
#include "Graph.h"
#include "Graph2.h"
#include "Unit4.h"

class GraphSettings
{
   public:
   bool combineType;
   double step;
   double delta;
   GraphSettings(){}
   GraphSettings(bool ct, double st,double dlt)
   {
	 combineType = ct;
	 step= st;
	 delta = dlt;
   }
   void showWin()
   {
	 Form4->Visible = true;
   }
};
void Update(GraphSettings gs1,GraphSettings gs2)
{
   gs1.combineType = gs2.combineType;
   gs1.step = gs2.step;
   gs1.delta = gs2.delta;

}

