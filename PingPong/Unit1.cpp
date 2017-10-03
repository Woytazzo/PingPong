//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

int x=-8;
int y=-8;
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
   {
   Timer_pilka->Enabled=false;
   ball->Visible=false;
   }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Timer_paletka1goraTimer(TObject *Sender)
{
if(paletka1->Top>10)   paletka1->Top -= 10;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Timer_paletka1dolTimer(TObject *Sender)
{
if(paletka1->Top+paletka1->Height+10<tlo->Height) paletka1->Top += 10;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Timer_paletka2goraTimer(TObject *Sender)
{
if(paletka2->Top>10)  paletka2->Top -= 10;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Timer_paletka2dolTimer(TObject *Sender)
{
if(paletka2->Top+paletka2->Height+10<tlo->Height)  paletka2->Top += 10;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
if (Key == VK_UP)  Timer_paletka2gora->Enabled=true;
if (Key == VK_DOWN)  Timer_paletka2dol->Enabled=true;
if (Key == 0x41)  Timer_paletka1gora->Enabled=true;
if (Key == 0x5A)  Timer_paletka1dol->Enabled=true;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormKeyUp(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
if (Key == VK_UP)  Timer_paletka2gora->Enabled=false;
if (Key == VK_DOWN)  Timer_paletka2dol->Enabled=false;
if (Key == 0x41)  Timer_paletka1gora->Enabled=false;
if (Key == 0x5A)  Timer_paletka1dol->Enabled=false;
}
//---------------------------------------------------------------------------
