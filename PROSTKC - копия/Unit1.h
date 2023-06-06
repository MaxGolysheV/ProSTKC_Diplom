//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.CheckLst.hpp>
#include <Vcl.Dialogs.hpp>
#include <Vcl.ExtDlgs.hpp>
#include <Vcl.Mask.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TPanel *Panel2;
	TLabel *Label84;
	TLabel *Label85;
	TLabel *Label86;
	TLabel *Label87;
	TLabel *Label89;
	TLabel *Label90;
	TEdit *Ei_1;
	TEdit *Eo_1;
	TEdit *Er_1;
	TEdit *Etet_1;
	TEdit *Eu_1;
	TEdit *Ev_1;
	TPanel *Panel16;
	TLabel *Label74;
	TLabel *Label75;
	TLabel *Label76;
	TLabel *Label77;
	TLabel *Label81;
	TEdit *Eyc;
	TEdit *Emc;
	TEdit *Edc;
	TEdit *Edk;
	TPanel *Panel17;
	TButton *Bv;
	TLabeledEdit *LE_tab;
	TLabeledEdit *LE_nru1;
	TLabeledEdit *LE_kru1;
	TLabeledEdit *LE_kru2;
	TLabeledEdit *LE_nru2;
	TCheckListBox *kaList;
	TOpenTextFileDialog *ofd1;
	TPanel *Panel1;
	TButton *btnOpen;
	TButton *btnSaveFile;
	TButton *btnFileCreate;
	TPanel *Panel3;
	TButton *btnAdd;
	TButton *btnDelete;
	TButton *btnEdit;
	TSaveTextFileDialog *sfd1;
	TCheckBox *selectAll;
	TButton *btnEnterVector;
	TButton *Button2;
	TPanel *Panel5;
	TLabel *Label10;
	TLabel *Label11;
	TPanel *Panel6;
	TLabel *Label12;
	TMemo *Mem1;
	TLabel *Label14;
	TPanel *Panel7;
	TLabel *Label13;
	TLabel *Label4;
	TLabel *Label5;
	TEdit *Es_1;
	TEdit *Ed_1;
	TPanel *Panel4;
	TLabel *Label1;
	TLabel *Label2;
	TLabel *Label3;
	TLabel *Label6;
	TLabel *Label7;
	TLabel *Label8;
	TLabel *Label9;
	TEdit *kaEyc;
	TEdit *kaEmc;
	TEdit *kaEdc;
	TEdit *kaEhc;
	TEdit *kaEmic;
	TEdit *kaEsc;
	TPanel *Panel8;
	TLabel *Label15;
	TButton *Button1;
	TButton *btnSettings;
	TLabel *Label16;
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall ClearGraph(TImage *img);
	void __fastcall DrawGraph(TImage *img, double tn1, double tk1,double tn2, double tk2, double tab,int num,AnsiString a1,AnsiString a2);
	void __fastcall btnOpenClick(TObject *Sender);
	void __fastcall ofd1CanClose(TObject *Sender, bool &CanClose);
	void __fastcall kaListClick(TObject *Sender);
	void __fastcall btnAddClick(TObject *Sender);
	void __fastcall btnDeleteClick(TObject *Sender);
	void __fastcall btnEditClick(TObject *Sender);
	void __fastcall btnSaveFileClick(TObject *Sender);
	void __fastcall sfd1CanClose(TObject *Sender, bool &CanClose);
	void __fastcall btnFileCreateClick(TObject *Sender);
	void __fastcall selectAllClick(TObject *Sender);
	void __fastcall kaListClickCheck(TObject *Sender);
	void __fastcall RedrawGraph(int maxka);
	void __fastcall btnSettingsClick(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall btnEnterVectorClick(TObject *Sender);
	void __fastcall EdkChange(TObject *Sender);
	void __fastcall EycChange(TObject *Sender);
	void __fastcall EdkClick(TObject *Sender);
	void __fastcall EycClick(TObject *Sender);
	void __fastcall Ed_1Change(TObject *Sender);
	void __fastcall Ed_1Click(TObject *Sender);
	void __fastcall kaEycChange(TObject *Sender);
	void __fastcall kaEycClick(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall Button2Click(TObject *Sender);



private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);

};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                 