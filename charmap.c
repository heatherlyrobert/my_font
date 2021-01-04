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
   char        order;
};
tGREEK    s_greek [30] =  {
   { '�', "alpha"    , "a"   , 'A'  ,  0},
   { '�', "beta"     , "b"   , 'B'  ,  0},
   { '�', "gamma"    , "c"   , 'G'  ,  0},
   { '�', "delta"    , "d"   , 'D'  ,  0},
   { '�', "epsilon"  , "e"   , 'E'  ,  0},
   { '�', "zeta"     , "z"   , 'Z'  ,  0},
   { '�', "eta"      , "e"   , 'H'  ,  0},
   { '�', "theta"    , "th"  , 'Y'  ,  0},
   { '�', "iota"     , "i"   , 'I'  ,  0},
   { '�', "kappa"    , "k"   , 'K'  ,  0},
   { '�', "lambda"   , "l"   , 'L'  ,  0},
   { '�', "mu"       , "m"   , 'M'  ,  0},
   { '�', "nu"       , "n"   , 'N'  ,  0},
   { '�', "xi"       , "x"   , 'X'  ,  0},
   { '�', "omicron"  , "o"   , 'O'  ,  0},
   { '�', "pi"       , "p"   , 'P'  ,  0},
   { '�', "rho"      , "r"   , 'R'  ,  0},
   { '�', "sigma"    , "s"   , 'S'  ,  0},
   { '�', "tau"      , "t"   , 'T'  ,  0},
   { '�', "upsilon"  , "u"   , 'U'  ,  0},
   { '�', "phi"      , "ph"  , 'F'  ,  0},
   { '�', "chi"      , "ch"  , 'C'  ,  0},
   { '�', "psi"      , "ps"  , 'Q'  ,  0},
   { '�', "omega"    , "o"   , 'W'  ,  0},
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
   int         x_val       =    0;
   int         x_pos       =    0;
   int         x_ch        =    0;
   char        x_text      [100];
   /*------------------------------ abcdefghijklmnopqrstuvwxyz"  */
   char        x_trans     [100] = "� �백�� ������� �������";
   /*---(titles)-------------------------*/
   printf ("#!/usr/local/bin/charmap\n");
   printf ("#   %s\n", P_ONELINE);
   printf ("#   %s : %s\n", P_VERNUM, P_VERTXT);
   printf ("\n");
   printf ("       -", x_hex);
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
   printf ("p�q  �&  and             p�q  �l   if.. then..            p�q  �_j  union\n");
   printf ("p�q  �k  nand            p�q  �h   requires/needs         p�q  �_k  intersection\n");
   printf ("p�q  �|  or              p�q  �_o  if and only if         p�q  �_l  superset\n");
   printf ("p�q  �^  xor             p�q  �_p  proves                 p�q  �_h  subset\n");
   printf ("p�q  �j  nor             p�q  �_f  forces                 p�q  �=   equivalent\n");
   printf ("~p       not             p�q  �_i  implies                �p   �_a  for each\n");
   printf ("p�q  �~  appox           p�q  �_c  contradicts            p�q  �_m  member of\n");
   printf ("\n");
   /*---(new brackets)-------------------*/
   printf ("315�  2.461�  23'49\"  235�    ���+��+�����+��+���    =�$g$5�*�g3�+�d7�+�c2�+�$c$4\n");
   printf (" �0 �  nul    �a 3� deg    �r 9� rad    �# 4� lbs    �  � fil    �! �   �? �\n");
   printf ("\n");
   printf ("macros  �ls<���ls<���ls<���ls<���:0a1��\n");
   printf (" �e � esc     �n � ret     �f � fld     �g � grp     �* � msk    �p � plc\n");
   printf (" �q � hlt     �+ � dsp     �. � pau     �s � pad     �' � 0.2s   �@ � 1s     �, � 5s\n");
   printf (" �: � sum     �% � sys     �� � dqt     �� � dbs     �-  fld   ����� blitz\n");
   printf ("\n");
   printf ("bezier curves...\n");
   printf ("square (n=2) : x(t) = (1-t)�x� + 2t(1-t)x� + t�x�\n");
   printf ("cubic  (n=3) : x(t) = (1-t)�x� + 3t(1-t)�x� + 3t�(1-t)x� + t�x�\n");
   printf ("quad   (n=4) : x(t) = (1-t)�x� + 4t(1-t)�x� + 6t�(1-t)�x� + 4t�(1-t)x� + t�x�\n");
   printf (" �1 x�  �2 x�  �3 x�  �4 x�  �x x�  �y x�  �5 x�  �6 x�  �7 x�  �8 x�  �9 x�  �z x�\n");
   printf ("\n");
   printf ("yREGEX  �red|white�   �n�m�   (&float)   �n�m�   �n[aeiou]�   �[abcde]{3,5}�\n");
   printf (" �[ �   �] �   �( �   �) �   �{ �   �} �   �d �   �b �   �< �   �> �   �/ �   �$ �\n");
   printf ("\n");
   /*---(greek table)--------------------*/
   for (i = 0; i < 12; ++i) {
      if (i == 6)  printf ("\n");
      x_pos = i;
      printf ("              %c   %-2s  �%c  %-10.10s          ",
            s_greek [x_pos].lower,
            s_greek [x_pos].sound, s_greek [x_pos].abbr ,
            s_greek [x_pos].name);
      x_pos = i + 12;
      printf (" %c   %-2s  �%c  %-10.10s\n",
            s_greek [x_pos].lower,
            s_greek [x_pos].sound, s_greek [x_pos].abbr ,
            s_greek [x_pos].name);
   }
   printf ("\n");
   for (i = 0; i < 24; ++i)  printf ("%c ", s_greek [i].lower);
   printf ("    ");
   for (i = 0; i < 24; ++i)  printf ("%c" , s_greek [i].lower);
   /*---(tsae)---------------------------*/
   /*> printf ("\n");                                                                                            <* 
    *> strlcpy (x_text, "siyowina qaze nihi gaya geyv zuda siyv gohv wenv caqu goya sida tanu wagv kuwf", 80);   <* 
    *> printf ("%s\n", x_text);                                                                                  <* 
    *> for (i = 0; i < strlen (x_text); ++i) {                                                                   <* 
    *>    if (x_text [i] == ' ')  printf ("�");                                                                  <* 
    *>    else                    printf ("%c", x_trans [x_text [i] - 'a']);                                     <* 
    *> }                                                                                                         <* 
    *> printf ("\n");                                                                                            <* 
    *> if (a_argc > 1) {                                                                                         <* 
    *>    for (i = 0; i < strlen (x_text); ++i) {                                                                <* 
    *>       if (x_text [i] == ' ')  printf ("�");                                                               <* 
    *>       else                    printf ("%c", x_text [i] + 32);                                             <* 
    *>    }                                                                                                      <* 
    *> }                                                                                                         <*/
   printf ("\n");
   printf ("# end-of-file.  done, finito, completare, whimper [ϴ���\n");
   /*---(complete)-----------------------*/
   return 0;
}


