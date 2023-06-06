//---------------------------------------------------------------------------

#ifndef Unit4H
#define Unit4H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Mask.hpp>
//---------------------------------------------------------------------------
class TForm4 : public TForm
{
__published:	// IDE-managed Components
	TButton *btnAcceptSetting;
	TButton *btnCancelSettings;
	TLabeledEdit *tbXStep;
	TLabeledEdit *etDelta;
	TRadioGroup *rgrp;
	TRadioButton *rbRu;
	TRadioButton *rbKa;
	TScrollBar *sb1;
	void __fastcall btnAcceptSettingClick(TObject *Sender);
	void __fastcall btnCancelSettingsClick(TObject *Sender);
	void __fastcall FormActivate(TObject *Sender);
	void __fastcall sb1Change(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm4(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm4 *Form4;
//---------------------------------------------------------------------------
#endif
