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

int pointsLeft=0;
int pointsRight=0;
int amountOfHits=0;

bool leftScores;

void restart()
{

AnsiString scoreString;
AnsiString amountOfHitsString=IntToStr(amountOfHits);
Form1->hitsViewer->Caption="Ilosc odbic: "+amountOfHitsString;
scoreString=IntToStr(pointsLeft)+":"+IntToStr(pointsRight);
Form1->score->Caption=scoreString;
Form1->Timer_ball->Enabled=false;
Form1->ball->Visible=false;
Form1->Button1->Visible=true;
Form1->Button2->Visible=true;
Form1->Label1->Visible=true;
Form1->hitsViewer->Visible=true;
Form1->score->Visible=true;
amountOfHits=0;

}
//---------------------------------------------------------------------------

__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Timer_ballTimer(TObject *Sender)
{
   ball->Left+=x;
   ball->Top+=y;

   //top bounce
   if(ball->Top-5 <= background->Top) y=-y;
   //bottom bounce
   if(ball->Top+ball->Height+5 >= background->Height) y=-y;

   //left paddle fail
   if(ball->Left+ball->Width <= paddle1->Left-10)
   {
        Label1->Caption="    PUNKT DLA GRACZA PRAWEGO   ->";
        pointsRight++;
        restart();
        leftScores=false;
   }
   // direction change
    else if
    (ball->Top+ball->Height/2>=paddle1->Top+paddle1->Height/2-10 &&
    ball->Top+ball->Height/2<=paddle1->Top+paddle1->Height/2+10 &&
    ball->Left<=paddle1->Left+paddle1->Width)
   {
        if(x>0)
        x=-x-1;

        else
        x=-x+1;
  }
   //left paddle hits
   else if
   (ball->Top+ball->Height/2>=paddle1->Top &&
   ball->Top+ball->Height/2<=paddle1->Top+paddle1->Height &&
   ball->Left<=paddle1->Left+paddle1->Width)
    {
        if(x<0)
        x=-x;
        amountOfHits++;

        //change of direction depends on hitting over or below the center of paddle
        if
        (
                (ball->Top+ball->Height/2<paddle1->Top+paddle1->Height/2-40 &&
                y>0) ||
                (ball->Top+ball->Height/2>paddle1->Top+paddle1->Height/2+40 &&
                y<0)
        )
        y=-y;

        if(amountOfHits%10==0&&amountOfHits>0)
        {
                if(x>=0)
                x++;

                else if(x<0)
                x--;
        }
    }
   //right paddle fail
   if(ball->Left >= paddle2->Left+paddle2->Width+10)
   {
        pointsLeft++;
        Label1->Caption="<-  PUNKT DLA GRACZA LEWEGO      ";
        leftScores=true;
        restart();
   }
   // direction change
   else if(ball->Top+ball->Height/2>=paddle2->Top+paddle2->Height/2-10 &&
   ball->Top+ball->Height/2<=paddle2->Top+paddle2->Height/2+10 &&
   ball->Left+ball->Width>=paddle2->Left)
   {
        if(x>0)
        x=-x-1;

        else
        x=-x+1;
   }
  //right paddle hits
  else if(ball->Top+ball->Height/2>=paddle2->Top
  && ball->Top+ball->Height/2<=paddle2->Top+paddle2->Height
  && ball->Left+ball->Width>=paddle2->Left)
  {
        if(x>0)
        x=-x;
        
        amountOfHits++;

        //change of direction depends on hitting over or below the center of paddle
        if
        (
                (ball->Top+ball->Height/2<paddle2->Top+paddle2->Height/2-40 &&
                y>=0) ||
                (ball->Top+ball->Height/2>paddle2->Top+paddle2->Height/2+40 &&
                y<0)
        )
        y=-y;

        if(amountOfHits%10==0&&amountOfHits>0)
        {
        if(x>=0)
        x++;
        else if(x<0)
        x--;
        }
  }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Timer_paddle1upTimer(TObject *Sender)
{
        if(paddle1->Top>10)   paddle1->Top -= 10;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Timer_paddle1downTimer(TObject *Sender)
{
        if(paddle1->Top+paddle1->Height+10<background->Height) paddle1->Top += 10;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Timer_paddle2upTimer(TObject *Sender)
{
        if(paddle2->Top>10)
        paddle2->Top -= 10;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Timer_paddle2downTimer(TObject *Sender)
{
        if(paddle2->Top+paddle2->Height+10<background->Height)
        paddle2->Top += 10;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
if (Key == VK_UP)       Timer_paddle2up->Enabled=true;
if (Key == VK_DOWN)     Timer_paddle2down->Enabled=true;
if (Key == 0x41)        Timer_paddle1up->Enabled=true;
if (Key == 0x5A)        Timer_paddle1down->Enabled=true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormKeyUp(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
if (Key == VK_UP)       Timer_paddle2up->Enabled=false;
if (Key == VK_DOWN)     Timer_paddle2down->Enabled=false;
if (Key == 0x41)        Timer_paddle1up->Enabled=false;
if (Key == 0x5A)        Timer_paddle1down->Enabled=false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{
     ball->Left=472;
     ball->Top=200;
     ball->Visible=true;
     x=-4;
     y=-4;
     Timer_ball->Enabled=true;
     Button1->Visible=false;
     Button2->Visible=false;
     amountOfHits=0;
     pointsLeft=0;
     pointsRight=0;
     Label1->Visible=false;
     hitsViewer->Visible=false;
     score->Visible=false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender)
{
    ball->Left=472;
    ball->Top=200;
    ball->Visible=true;

    if (leftScores==true)
    {x=-4; y=-4; }

    else
    {x=4; y=-4;}
    
    Timer_ball->Enabled=true;
    Button1->Visible=false;
    Button2->Visible=false;
    amountOfHits=0;
    Label1->Visible=false;
    hitsViewer->Visible=false;
    score->Visible=false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormCreate(TObject *Sender)
{
    Application->MessageBox("Witaj w grze Ping Pong.\n"
    "  \n"
    "Lewy gracz steruje wciskaj�c klawisze A oraz Z.\n"
    "Prawy gracz steruje wciskaj�c srza�ki w g�r�i w d�.\n"
    " \n"
    "Dla urozmaicenia zabawy:\n"
    "Kiedy odbijesz pi�k� na �rodku paletki, zmienisz jej k�t odbicia i pr�dko��.\n"
    "Im d�u�ej trwa gra, tym szybciej pi�ka si� przemieszcza.  \n"
    "Mo�esz zmienia� dowolnie pole gry.\n"
    " \n"
    "Powodzenia!", "PingPong", MB_OK);
}
//---------------------------------------------------------------------------

