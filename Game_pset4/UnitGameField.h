//---------------------------------------------------------------------------

#ifndef UnitGameFieldH
#define UnitGameFieldH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "CSPIN.h"
#include <Grids.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TFormGame : public TForm
{
__published:	// IDE-managed Components
        TCSpinEdit *CSpinEdit;
        TStringGrid *sgGameField;
        TButton *btStart;
        TTimer *Timer;
        TLabel *Label;
        TEdit *editTime;
        void __fastcall FormActivate(TObject *Sender);
        void __fastcall TimerTimer(TObject *Sender);
        void __fastcall btStartClick(TObject *Sender);
        void __fastcall sgGameFieldSelectCell(TObject *Sender, int ACol,
          int ARow, bool &CanSelect);
       

private:	// User declarations
public:		// User declarations
        __fastcall TFormGame(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormGame *FormGame;
//---------------------------------------------------------------------------
#endif
