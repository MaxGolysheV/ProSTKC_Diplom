//---------------------------------------------------------------------------

#ifndef Graph2H
#define Graph2H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <VCLTee.Chart.hpp>
#include <VCLTee.Series.hpp>
#include <VclTee.TeeGDIPlus.hpp>
#include <VCLTee.TeEngine.hpp>
#include <VCLTee.TeeProcs.hpp>
//#include <VCLTee.Chart.hpp>
//#include <VCLTee.Series.hpp>
//#include <VclTee.TeeGDIPlus.hpp>
//#include <VCLTee.TeEngine.hpp>
//#include <VCLTee.TeeProcs.hpp>
//---------------------------------------------------------------------------
class TForm3 : public TForm
{
__published:	// IDE-managed Components
	TChart *ChartPt;
	TBarSeries *SeriesRU;
	TLineSeries *SeriesPt;
	TEdit *Edit1;
	TEdit *Edit2;
	TEdit *Edit3;
	TChart *Chart1;
	TBarSeries *Series_RUg;
	TLineSeries *Series_Ug;
	TButton *Button1;
	void __fastcall Button1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm3(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm3 *Form3;
//---------------------------------------------------------------------------
#endif
