//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UnitGameField.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "CSPIN"
#pragma resource "*.dfm"
TFormGame *FormGame;
int posi,posj,iAttempsNumber;

//---------------------------------------------------------------------------
__fastcall TFormGame::TFormGame(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFormGame::FormActivate(TObject *Sender)
{
        for(int i = 0;i<sgGameField->RowCount;++i)
        {
                for(int j = 0;j<sgGameField->ColCount;++j)
                {
                        sgGameField->Cells[i][j] = 0;
                }
        }
}
//---------------------------------------------------------------------------
void __fastcall TFormGame::TimerTimer(TObject *Sender)
{
        if(iAttempsNumber && editTime->Text != 0)
        {
                sgGameField->Cells[posi][posj] = 0;
                Randomize();
                posi = random(sgGameField->RowCount);
                posj = random(sgGameField->ColCount);
                sgGameField->Cells[posi][posj] = 1;
                editTime->Text = editTime->Text - 1;;
        }
        else
        {
                Timer->Enabled = false;
                if(!iAttempsNumber)
                {
                        ShowMessage("Attepms  over.");
                }
                else
                {
                       ShowMessage("Time over");
                }
        }
}
//---------------------------------------------------------------------------
void __fastcall TFormGame::btStartClick(TObject *Sender)
{
        sgGameField->Cells[posi][posj] = 0;
        editTime->Text = 60;
        iAttempsNumber = 10;
        Label->Caption = 10;
        Timer->Interval = 800-(CSpinEdit->Value-1)*100;
        Timer->Enabled = true;

}
//---------------------------------------------------------------------------
void __fastcall TFormGame::sgGameFieldSelectCell(TObject *Sender, int ACol,
      int ARow, bool &CanSelect)
{
        if(Timer->Enabled)
        {
                if(iAttempsNumber)
                {
                        if(sgGameField->Cells[ARow][ACol] == 1)
                        {
                                ShowMessage("You win!!!");
                                Timer->Enabled = false;
                        }
                        Label->Caption = --iAttempsNumber;
                }
                else
                {
                        ShowMessage("Attemps over.");
                        Timer->Enabled = false;
                }
        }
}
//---------------------------------------------------------------------------


