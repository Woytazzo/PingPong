//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
#include <jpeg.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TShape *background;
        TImage *ball;
        TImage *paddle1;
        TTimer *Timer_ball;
        TImage *paddle2;
        TTimer *Timer_paddle1up;
        TTimer *Timer_paddle1down;
        TTimer *Timer_paddle2up;
        TTimer *Timer_paddle2down;
        TButton *Button1;
        TButton *Button2;
        TLabel *Label1;
        TLabel *score;
        TLabel *hitsViewer;
        void __fastcall Timer_ballTimer(TObject *Sender);
        void __fastcall Timer_paddle1upTimer(TObject *Sender);
        void __fastcall Timer_paddle1downTimer(TObject *Sender);
        void __fastcall Timer_paddle2upTimer(TObject *Sender);
        void __fastcall Timer_paddle2downTimer(TObject *Sender);
        void __fastcall FormKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall FormKeyUp(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall Button2Click(TObject *Sender);
        void __fastcall FormCreate(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
