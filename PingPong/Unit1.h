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
        TShape *tlo;
        TImage *ball;
        TImage *paletka1;
        TTimer *Timer_pilka;
        TImage *paletka2;
        TTimer *Timer_paletka1gora;
        TTimer *Timer_paletka1dol;
        TTimer *Timer_paletka2gora;
        TTimer *Timer_paletka2dol;
        TButton *Button1;
        TButton *Button2;
        TLabel *Label1;
        TLabel *wynik;
        TLabel *wyswietlaczOdbic;
        void __fastcall Timer_pilkaTimer(TObject *Sender);
        void __fastcall Timer_paletka1goraTimer(TObject *Sender);
        void __fastcall Timer_paletka1dolTimer(TObject *Sender);
        void __fastcall Timer_paletka2goraTimer(TObject *Sender);
        void __fastcall Timer_paletka2dolTimer(TObject *Sender);
        void __fastcall FormKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall FormKeyUp(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall Button2Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
