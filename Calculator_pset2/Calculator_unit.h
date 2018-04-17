//---------------------------------------------------------------------------

#ifndef Calculator_unitH
#define Calculator_unitH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
//---------------------------------------------------------------------------
class TCalculator : public TForm
{
__published:	// IDE-managed Components
        TButton *Button1;
        TButton *Button2;
        TButton *Button3;
        TButton *Button4;
        TButton *Button5;
        TButton *Button6;
        TButton *Button7;
        TButton *Button8;
        TButton *Button9;
        TButton *Button0;
        TButton *ButtonClear;
        TButton *ButtonDiv;
        TButton *ButtonMulti;
        TButton *ButtonMinus;
        TButton *ButtonPlus;
        TButton *ButtonIs;
        TLabel *InOutLabel;
        TButton *ButtonDot;
        void __fastcall Button0Click(TObject *Sender);
        void __fastcall ButtonClearClick(TObject *Sender);
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall Button2Click(TObject *Sender);
        void __fastcall Button3Click(TObject *Sender);
        void __fastcall Button4Click(TObject *Sender);
        void __fastcall Button5Click(TObject *Sender);
        void __fastcall Button6Click(TObject *Sender);
        void __fastcall Button7Click(TObject *Sender);
        void __fastcall Button8Click(TObject *Sender);
        void __fastcall Button9Click(TObject *Sender);
        void __fastcall ButtonPlusClick(TObject *Sender);
        void __fastcall ButtonDotClick(TObject *Sender);
        void __fastcall ButtonDivClick(TObject *Sender);
        void __fastcall ButtonMinusClick(TObject *Sender);
        void __fastcall ButtonMultiClick(TObject *Sender);
        void __fastcall ButtonIsClick(TObject *Sender);
        void __fastcall FormKeyPress(TObject *Sender, char &Key);
       
private:	// User declarations
public:
        // User declarations
       
        __fastcall TCalculator(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TCalculator *Calculator;
//---------------------------------------------------------------------------
#endif
