//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

int x=8;
int y=8;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Timer_pilkaTimer(TObject *Sender)
{
   ball->Left+=x;
   ball->Top+=y;

   //od gornej sciany
   if(ball->Top-5 <= tlo->Top) y=-y;
   //od dolnej sciany
   if(ball->Top+ball->Height+5 >= tlo->Height) y=-y;

   //lipa lewej paletki
   if(ball->Left <= paletka1->Left+paletka1->Width)
   Timer_pilka->Enabled=false;

   //lipa prawej paletki
   if(ball->Left >= paletka2->Left-paletka1->Width)
   Timer_pilka->Enabled=false;
}
//---------------------------------------------------------------------------
