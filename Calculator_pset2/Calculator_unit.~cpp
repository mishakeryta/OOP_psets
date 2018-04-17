//---------------------------------------------------------------------------

#include <vcl.h>
#include <ctype.h>                                                                                                              git
#pragma hdrstop

#include "Calculator_unit.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TCalculator *Calculator;
bool wasOperator = false;
bool operatorNow = false;
bool comaInDigit = false;
//---------------------------------------------------------------------------
__fastcall TCalculator::TCalculator(TComponent* Owner)
        : TForm(Owner)
{
}

double LineToDouble(AnsiString line,int* indexStartEnd)
{
        double val = 0;
        bool  isFloat = false,isNegative = false;
        double minusStep =  0.1;
        if(line[*indexStartEnd] == '-')
        {
                ++(*indexStartEnd);
                isNegative = true;
        }
        for(int i = *indexStartEnd;i<=line.Length();++i)
        {

                if(line[i]== ',')
                {
                        isFloat = true;
                }
                else if('0'<=line[i] && line[i]<='9')
                {
                        if(isFloat)
                        {
                                val+=(line[i]-'0')*minusStep;
                                minusStep*=0.1;
                        }
                        else
                        {
                                val*=10;
                                val+=line[i] - '0';
                        }
                }
                else
                {
                        *indexStartEnd = i;
                        break;
                }
                
        }
        return isNegative?-val:val;
}
static void PlusToInOut(String num)
{
    Calculator->InOutLabel->Caption = Calculator->InOutLabel->Caption + num;
    operatorNow = false;
}
static void Operating(String operatorCall)
{       if(!Calculator->InOutLabel->Caption.IsEmpty() &&
        Calculator->InOutLabel->Caption!= "-")
        {
                if(!operatorNow)
                {
                        Calculator->ButtonIs->Click();
                        Calculator->InOutLabel->Caption = Calculator->InOutLabel->Caption + operatorCall;
                        operatorNow = true;
                        wasOperator = true;
                        comaInDigit = false;
                }
                else
                {
                        String line =  Calculator->InOutLabel->Caption;
                        line[line.Length()] = operatorCall[1];
                        Calculator->InOutLabel->Caption = line;

                }
        }

}
void __fastcall TCalculator::ButtonClearClick(TObject *Sender)
{
        InOutLabel->Caption = "";
        wasOperator = false;
        operatorNow = false;
        comaInDigit = false;

}
//----------------------------------------------------------------------
void __fastcall TCalculator::Button0Click(TObject *Sender)
{
        PlusToInOut("0");
}
//---------------------------------------------------------------------------
void __fastcall TCalculator::Button1Click(TObject *Sender)
{
        PlusToInOut("1");
}
//---------------------------------------------------------------------------

void __fastcall TCalculator::Button2Click(TObject *Sender)
{
        PlusToInOut("2");
}
//---------------------------------------------------------------------------

void __fastcall TCalculator::Button3Click(TObject *Sender)
{
        PlusToInOut("3");
}
//---------------------------------------------------------------------------

void __fastcall TCalculator::Button4Click(TObject *Sender)
{
        PlusToInOut("4");
}
//---------------------------------------------------------------------------

void __fastcall TCalculator::Button5Click(TObject *Sender)
{
        PlusToInOut("5");
}
//---------------------------------------------------------------------------


void __fastcall TCalculator::Button6Click(TObject *Sender)
{
        PlusToInOut("6");
}
//---------------------------------------------------------------------------

void __fastcall TCalculator::Button7Click(TObject *Sender)
{
        PlusToInOut("7");
}
//---------------------------------------------------------------------------

void __fastcall TCalculator::Button8Click(TObject *Sender)
{
        PlusToInOut("8");
}
//---------------------------------------------------------------------------

void __fastcall TCalculator::Button9Click(TObject *Sender)
{
        PlusToInOut("9");
}
//---------------------------------------------------------------------------



void __fastcall TCalculator::ButtonPlusClick(TObject *Sender)
{
        Operating("+");
}
//---------------------------------------------------------------------------

void __fastcall TCalculator::ButtonDotClick(TObject *Sender)
{
        if(comaInDigit || operatorNow || InOutLabel->Caption.IsEmpty()|| InOutLabel->Caption == "-") return;
        PlusToInOut(",");
        comaInDigit = true;
}
//---------------------------------------------------------------------------

void __fastcall TCalculator::ButtonDivClick(TObject *Sender)
{
        Operating("/");
}
//---------------------------------------------------------------------------

void __fastcall TCalculator::ButtonMinusClick(TObject *Sender)
{
        if(Calculator->InOutLabel->Caption.IsEmpty())
        {
                PlusToInOut("-");
        }
        else
        {
                Operating("-");
        }

}
//---------------------------------------------------------------------------

void __fastcall TCalculator::ButtonMultiClick(TObject *Sender)
{
        Operating("*");
}
//---------------------------------------------------------------------------

void __fastcall TCalculator::ButtonIsClick(TObject *Sender)
{
        if(operatorNow)
        {
                return;
        }
        String line = Calculator->InOutLabel->Caption;
        if(line.IsEmpty())
        {
                wasOperator = false;
                return;
        }
        if(!wasOperator)
        {
                return;
        }
        double val1 = 0,val2 = 0,result = 0;
        int index = 1;
        val1 = LineToDouble(line,&index);
        ++index;
        val2 =  LineToDouble(line,&index);
        switch(line[--index])
        {
        case'+':result = val1 + val2;break;
        case'-':result = val1-val2;break;
        case'*':result =val1 * val2;break;
        case'/':if(val2==0)
                {
                        Calculator->ButtonClear->Click();
                        return;
                }else
                {
                        result = val1/val2;
                }
                break;
        }
        String resultStr = FloatToStr(result);

        for(int i = 1;i<=resultStr.Length();++i)
        {
                 if(!wasOperator)
                 {
                 comaInDigit = false;
                 break;
                 }
                 if(resultStr[i] == ',')
                 {
                 comaInDigit = true;
                 break;
                 }
                comaInDigit = false;

        }
        wasOperator = false;
        operatorNow = false;
        Calculator->InOutLabel->Caption = FloatToStr(result);

}
//---------------------------------------------------------------------------


void __fastcall TCalculator::FormKeyPress(TObject *Sender, char &Key)
{
        for(int i = '1';i<='9';++i)
                if(Key==i)PlusToInOut(Key);
        switch(Key)
        {
        case'+':ButtonPlus->Click();break;
        case'-':ButtonMinus->Click();break;
        case'/':ButtonDiv->Click();break;
        case'*':ButtonMulti->Click();break;
        case'=':ButtonIs->Click();break;
        case'c':
        case'C':
        case 8:ButtonClear->Click();break;

        default:return;
        }
}
//---------------------------------------------------------------------------

