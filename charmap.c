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
   char        lower;
   char        name        [10];
   char        sound       [ 5];
   char        abbr;
   char        tsae        [ 5];
};
tGREEK    s_greek [30] =  {
   { '�', "alpha"    , "a"   , 'A'  , "-" },
   { '�', "beta"     , "b"   , 'B'  , "-" },
   { '�', "gamma"    , "c"   , 'G'  , "g" },
   { '�', "delta"    , "d"   , 'D'  , "d" },
   { '�', "epsilon"  , "e"   , 'E'  , "ts"},
   { '�', "zeta"     , "z"   , 'Z'  , "-" },
   { '�', "eta"      , "e"   , 'H'  , "h" },
   { '�', "theta"    , "th"  , 'Y'  , "-" },
   { '�', "iota"     , "i"   , 'I'  , "-" },
   { '�', "kappa"    , "k"   , 'K'  , "k" },
   { '�', "lambda"   , "l"   , 'L'  , "hl"},
   { '�', "mu"       , "m"   , 'M'  , "m" },
   { '�', "nu"       , "n"   , 'N'  , "n" },
   { '�', "xi"       , "x"   , 'X'  , "hy"},
   { '�', "omicron"  , "o"   , 'O'  , "-" },
   { '�', "pi"       , "p"   , 'P'  , "-" },
   { '�', "rho"      , "r"   , 'R'  , "pn"},
   { '�', "sigma"    , "s"   , 'S'  , "s" },
   { '�', "tau"      , "t"   , 'T'  , "t" },
   { '�', "upsilon"  , "u"   , 'U'  , "-" },
   { '�', "phi"      , "ph"  , 'F'  , "-" },
   { '�', "chi"      , "ch"  , 'C'  , "c" },
   { '�', "psi"      , "ps"  , 'Q'  , "qu"},
   { '�', "omega"    , "o"   , 'W'  , "w" },
};


char   s_rows  [16][20] = {
   "ctrl" , "ctrl",
   "punc" , "nums",
   "upper", "upper",
   "lower", "lower",
   "ctrl" , "ctrl",
   "macro", "group",
   "math" , "logic",
   "greek", "greek",
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
main                 (int a_argc, char *a_argv[])
{
   /*---(locals)-----------+-----+-----+-*/
   int         i, j;
   char        x_hex       =    0;
   int         x_pos       =    0;
   int         x_ch        =    0;
   /*------------------------------ abcdefghijklmnopqrstuvwxyz"  */
   /*---(titles)-------------------------*/
   printf ("#!/usr/local/bin/charmap\n");
   printf ("#   %s\n", P_ONELINE);
   /*> printf ("#   %s : %s\n", P_VERNUM, P_VERTXT);                                  <*/
   printf ("\n");
   printf ("       -");
   for (i = 0; i < 16; ++i) {
      if ((i % 4) == 0)  printf  ("    ---");
      x_hex = hexify (i);
      printf ("  %c", x_hex);
   }
   printf ("\n");
   /*---(char table)---------------------*/
   for (i = 0; i < 16; ++i) {
      if ((i % 2) == 0)  printf  ("\n");
      x_hex = hexify (i);
      if (a_argc > 1 && i >= 8 && i <= 9)  printf ("%5s  ", "tsae");
      else                                 printf ("%5s  ", s_rows [i]);
      printf ("%c", x_hex);
      for (j = 0; j < 16; ++j) {
         if ((j % 4) == 0)  printf  ("    %03d", (i * 16) + j);
         x_ch = (i * 16) + j;
         if      (x_ch <   32)                               printf ("  %c", '�');
         else if (a_argc < 2 && x_ch >= 127 && x_ch <= 160)  printf ("  %c", '�');
         else                                                printf ("  %c", x_ch);
      }
      printf ("\n");
   }
   printf ("\n");
   /*---(typical similar letters)--------*/
   printf (" p�q  �&  and      TT -- -- --     p�q  �_r  unlikely       p�q  �_u  uniques\n");
   printf (" p�q  �k  nand/con -- TF FT FF     p�q  �_l  likely         p�q  �_x  there exists\n");
   printf (" p�q  �|  or       TT TF FT --     �=�  �_i  infinity       p�q  �_h  subset of\n");
   printf (" p�q  �v  xor      -- TF FT --     �x(  �_f  function       p�q  �_m  member of\n");
   printf (" p�q  �j  nor      -- -- -- FF     p�q  �'   product        p�q  �=   equivalent\n");
   printf (" p�q  �i  iff/nxor TT -- -- FF     p�q  �u   functor        �p(  �_a  for each ...\n");
   printf (" p�q  �l  if/prove TT -- FT FF     p�q  �o   set math       p�q  �h   contributes back\n");
   printf ("\n");
   /*---(new brackets)-------------------*/
   printf ("315�  2.461�  23'49\"  235�    ���+��+�����+��+���    =�$g$5�*�g3�+�d7�+�c2�+�$c$4\n");
   printf (" �0 �  nul    �a 3� deg    �r 9� rad    �# 4� lbs    �  � fil    �! �   �? �   �$ �\n");
   printf ("\n");
   printf ("macros  �ls<���ls<���ls<���ls<���:0a1��\n");
   printf (" �e � esc     �n � ret     �f � fld     �g � grp     �* � msk    �p � plc\n");
   printf (" �q � hlt     �+ � dsp     �. � pau     �s � pad     �' � 1key   �@ � 5key   �, � 0.5s\n");
   printf (" �: � sum     �%% � sys     �� � dqt     �� � dbs     �-  fld   ����� blitz\n");
   printf ("\n");
   printf ("bezier (n=2) : x(t) = (1-t)�x� + 2t(1-t)x� + t�x�\n");
   printf ("cubic  (n=3) : x(t) = (1-t)�x� + 3t(1-t)�x� + 3t�(1-t)x� + t�x�\n");
   printf ("quad   (n=4) : x(t) = (1-t)�x� + 4t(1-t)�x� + 6t�(1-t)�x� + 4t�(1-t)x� + t�x�\n");
   printf (" �1 x�  �2 x�  �3 x�  �4 x�  �x x�  �y x�  �5 x�  �6 x�  �7 x�  �8 x�  �9 x�  �z x�\n");
   printf ("\n");
   printf ("yREGEX  �red|white�   �n�m�   (&float)   �n�m�   �n[aeiou]�   �[abcde]{3,5}�\n");
   printf (" �[ �   �] �   �( �   �) �   �{ �   �} �   �d �   �b �   �< �   �> �   �/ �   �~ �\n");
   printf ("\n");
   /*---(greek table)--------------------*/
   for (i = 0; i < 12; ++i) {
      /*> if (i == 6)  printf ("\n");                                                 <*/
      x_pos = i;
      printf ("        %c   %-2s  �%c  %-7.7s  (%-2s)        ",
            s_greek [x_pos].lower,
            s_greek [x_pos].sound, s_greek [x_pos].abbr ,
            s_greek [x_pos].name , s_greek [x_pos].tsae);
      x_pos = i + 12;
      printf (" %c   %-2s  �%c  %-7.7s  (%-2s)        ",
            s_greek [x_pos].lower,
            s_greek [x_pos].sound, s_greek [x_pos].abbr ,
            s_greek [x_pos].name , s_greek [x_pos].tsae);
      switch (i) {
      case 2  :  printf ("�  a");    break;
      case 3  :  printf ("�  e");    break;
      case 4  :  printf ("�  f");    break;
      case 5  :  printf ("�  i");    break;
      case 6  :  printf ("�  o");    break;
      case 7  :  printf ("�  u");    break;
      case 8  :  printf ("�  v");    break;
      case 9  :  printf ("�  '");    break;
      }
      printf ("\n");
   }
   printf ("\n");
   for (i = 0; i < 24; ++i)  printf ("%c ", s_greek [i].lower);
   printf ("    ");
   for (i = 0; i < 24; ++i)  printf ("%c" , s_greek [i].lower);
   printf ("\n");
   printf ("\n");
   printf ("   sihyo'wina ���ʷ����   kama ����   zetu'nvgf ���̷����   pna'quatse �Ƿ����\n");
   printf ("\n");
   printf ("# end-of-file.  done, finito, completare, whimper [ϴ���\n");
   /*---(complete)-----------------------*/
   return 0;
}


