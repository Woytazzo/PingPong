//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

int x=-4;
int y=-4;

int punktyLewy=0;
int punktyPrawy=0;
int iloscOdbic=0;


bool lewyPunktuje;
void ekran()
{
AnsiString wynikString;
AnsiString ilOdbic=IntToStr(iloscOdbic);
Form1->wyswietlaczOdbic->Caption="Ilosc odbic: "+ilOdbic;
wynikString=IntToStr(punktyLewy)+":"+IntToStr(punktyPrawy);
Form1->wynik->Caption=wynikString;
Form1->Timer_pilka->Enabled=false;
Form1->ball->Visible=false;
Form1->Button1->Visible=true;
Form1->Button2->Visible=true;
Form1->Label1->Visible=true;
Form1->wyswietlaczOdbic->Visible=true;
Form1->wynik->Visible=true;
}





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
   if(ball->Left+ball->Width <= paletka1->Left-10)
   {
   Label1->Caption="    PUNKT DLA GRACZA PRAWEGO   ->";
   punktyPrawy++;
   ekran();
   lewyPunktuje=false;

   }
   //+ zmiana kierunku
    else if(ball->Top+ball->Height/2>=paletka1->Top+paletka1->Height/2-10 &&
   ball->Top+ball->Height/2<=paletka1->Top+paletka1->Height/2+10
   && ball->Left<=paletka1->Left+paletka1->Width)
   {
  if(x>0)x=-x-1;
  else x=-x+1;
  }

  //+ zmiana kierunku 2
   /* else if
    (
    ((ball->Top+ball->Height/2>=paletka1->Top &&
    ball->Top+ball->Height/2<=paletka1->Top+20)
    ||
   (ball->Top+ball->Height/2<=paletka1->Top+paletka1->Height &&
    ball->Top+ball->Height/2>=paletka1->Top+paletka1->Height-20))
   && ball->Left<=paletka1->Left+paletka1->Width
   )
   {
  if(x>0&&y>0){x=-x+1; y=-y+1; }
  else if(x>0&&y<0) {x=-x+1; y=-y-1; }
  else if(x<0&&y>0) {x=-x-1; y=-y+1; }
  else  {x=-x-1; y=-y-1; }
  }
   */
   //odbicie od lewej paletki
   else if(ball->Top+ball->Height/2>=paletka1->Top
   && ball->Top+ball->Height/2<=paletka1->Top+paletka1->Height
   && ball->Left<=paletka1->Left+paletka1->Width)
    {

   x=-x;
   iloscOdbic++;
    if(iloscOdbic%10==0&&iloscOdbic>0){
 if(x>=0)x++;
 else if(x<0)x--;
    }
    }



   //lipa prawej paletki
   if(ball->Left >= paletka2->Left+paletka2->Width+10)
   {
   punktyLewy++;
   Label1->Caption="<-  PUNKT DLA GRACZA LEWEGO      ";
   lewyPunktuje=true;
   ekran();
   }
   //+ zmiana kierunku
    else if(ball->Top+ball->Height/2>=paletka2->Top+paletka2->Height/2-10 &&
   ball->Top+ball->Height/2<=paletka2->Top+paletka2->Height/2+10
   && ball->Left+ball->Width>=paletka2->Left)
   {
  if(x>0)x=-x-1;
  else x=-x+1;
  }

  //+ zmiana kierunku 2
  /*  else if
    (
    ((ball->Top+ball->Height/2>=paletka2->Top &&
    ball->Top+ball->Height/2<=paletka2->Top+20)
    ||
   (ball->Top+ball->Height/2<=paletka2->Top+paletka2->Height &&
    ball->Top+ball->Height/2>=paletka2->Top+paletka2->Height-20))
   && ball->Left+ball->Width>=paletka2->Left
   )
   {
  if(x>0&&y>0){x=-x+1; y=-y+1; }
  else if(x>0&&y<0) {x=-x+1; y=-y-1; }
  else if(x<0&&y>0) {x=-x-1; y=-y+1; }
  else  {x=-x-1; y=-y-1; }
  }
  */
   //odbicie od prawej paletki
   else if(ball->Top+ball->Height/2>=paletka2->Top
  && ball->Top+ball->Height/2<=paletka2->Top+paletka2->Height
  && ball->Left+ball->Width>=paletka2->Left)
  {



      x=-x;
   iloscOdbic++;
    if(iloscOdbic%10==0&&iloscOdbic>0){
 if(x>=0)x++;
 else if(x<0)x--;
    }



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

void __fastcall TForm1::Button1Click(TObject *Sender)
{
     ball->Left=472;
     ball->Top=200;
     ball->Visible=true;
     x=-4;
     y=-4;
     Timer_pilka->Enabled=true;
     Button1->Visible=false;
     Button2->Visible=false;
     iloscOdbic=0;
     punktyLewy=0;
     punktyPrawy=0;
     Label1->Visible=false;
     wyswietlaczOdbic->Visible=false;
     wynik->Visible=false;


}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender)
{
   ball->Left=472;
     ball->Top=200;
     ball->Visible=true;
     if (lewyPunktuje==true)
     {x=-4; y=-4; }
     else
     {x=4; y=-4;}
     Timer_pilka->Enabled=true;
     Button1->Visible=false;
     Button2->Visible=false;
     iloscOdbic=0;
     Label1->Visible=false;
     wyswietlaczOdbic->Visible=false;
     wynik->Visible=false;
}
//---------------------------------------------------------------------------





