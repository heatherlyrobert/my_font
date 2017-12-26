#include    "font.h"



typedef    unsigned char uchar;


#define        NONE      32
/*---(1-way lines)------------*/
#define        LR       204
#define        TB       200
/*---(ends)-------------------*/
#define        TE       152
#define        BE       153
#define        LE       157
#define        RE       156
/*---(arrows)-----------------*/
#define        LA       197
#define        RA       196
#define        TA       199
#define        BA       198
/*---(2-way corners)----------*/
#define        BR       203
#define        BL       154
#define        TL       155
#define        TR       202
/*---(3-way corners)----------*/
#define        TBL      205
#define        TBR      201
#define        TLR      158
#define        BLR      159
/*---(4-way corners)----------*/
#define        TBLR     206



typedef struct cGREEK  tGREEK;
struct cGREEK {
   uchar       upper;
   char        lower;
   char        name        [10];
   char        sound       [ 5];
   char        abbr;
   char        order;
};
tGREEK    s_greek [30] =  {
   { '�', '�', "alpha"    , "a"   , 'A'  ,  0},
   { '�', '�', "beta"     , "b"   , 'B'  ,  0},
   { '�', '�', "gamma"    , "c"   , 'G'  ,  0},
   { '�', '�', "delta"    , "d"   , 'D'  ,  0},
   { '�', '�', "epsilon"  , "e"   , 'E'  ,  0},
   { '�', '�', "zeta"     , "z"   , 'Z'  ,  0},
   { '�', '�', "eta"      , "e"   , 'H'  ,  0},
   { '�', '�', "theta"    , "th"  , 'Q'  ,  0},
   { '�', '�', "iota"     , "i"   , 'I'  ,  0},
   { '�', '�', "kappa"    , "k"   , 'K'  ,  0},
   { '�', '�', "lambda"   , "l"   , 'L'  ,  0},
   { '�', '�', "mu"       , "m"   , 'M'  ,  0},
   { '�', '�', "nu"       , "n"   , 'N'  ,  0},
   { '�', '�', "xi"       , "x"   , 'X'  ,  0},
   { '�', '�', "omicron"  , "o"   , 'O'  ,  0},
   { '�', '�', "pi"       , "p"   , 'P'  ,  0},
   { '�', '�', "rho"      , "r"   , 'R'  ,  0},
   { '�', '�', "sigma"    , "s"   , 'S'  ,  0},
   { '�', '�', "tau"      , "t"   , 'T'  ,  0},
   { '�', '�', "upsilon"  , "u"   , 'U'  ,  0},
   { '�', '�', "phi"      , "ph"  , 'F'  ,  0},
   { '�', '�', "chi"      , "ch"  , 'C'  ,  0},
   { '�', '�', "psi"      , "ps"  , 'Y'  ,  0},
   { '�', '�', "omega"    , "o"   , 'W'  ,  0},
};

char
hexify               (int a_num)
{
   char        x_hex       =   0;
   if      (a_num >= 0 && a_num <=  9)   x_hex = a_num + '0';
   else if (a_num >  9 && a_num <  16)   x_hex = a_num + 'a' - 10;
   else                                  x_hex = '?';
   return x_hex;
}

int
main (void)
{
   int i, j;
   char        x_hex       =    0;
   int         x_val       =    0;
   srand (0);
   printf ("-", x_hex);
   for (i = 0; i < 16; ++i) {
      if ((i % 4) == 0)  printf  ("    ---");
      x_hex = hexify (i);
      printf ("  %c", x_hex);
   }
   printf ("\n");
   for (i = 0; i < 16; ++i) {
      if ((i % 2) == 0)  printf  ("\n");
      x_hex = hexify (i);
      printf ("%c", x_hex);
      for (j = 0; j < 16; ++j) {
         if ((j % 4) == 0)  printf  ("    %03d", (i * 16) + j);
         if      ((i * 16) + j  <  32)  printf ("  %c", 189);
         else if ((i * 16) + j == 127)  printf ("  %c", 189);
         else printf ("  %c", (i * 16) + j);
      }
      printf ("\n");
   }
   printf ("\n");
   printf ("0%c%c%c%c%c%c\n", 64, 79, 163, 135, 142, 151);
   printf ("o%c%c%c%c\n", 99, 101, 239, 246);
   printf ("1IiLl|\n");
   printf ("E%c%c\n", 132, 145);
   printf ("5Ss\n");
   printf ("2Z%cz\n", 133);
   printf ("({[]})\n");
   printf ("Illegal1 = O0\n");
   printf ("\n");
   printf ("pre�red�suf   pre�red�suf   pre�red�suf\n");
   printf ("pre�red�suf   pre�red�suf   pre�red�suf\n");
   printf ("\n");
   for (i = 0; i < 24; ++i) {
      printf (" %c %c   %-2s  %c  %s\n",
            128 + i, s_greek [i].lower,
            s_greek [i].sound, s_greek [i].abbr ,
            s_greek [i].name);
   }
   return 0;
}
