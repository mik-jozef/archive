#include <stdio.h>

int u1 = 0, u2 = 0, u3 = 0, u4 = 0, u5 = 0, u6 = 0, u7 = 0, u8 = 0, u9 = 0, u10 = 0, u11 = 0, u12 = 0, u13 = 0, u14 = 0, u15 = 0, u16 = 0, u17 = 0, u18 = 0, u19 = 0, u20 = 0, u21 = 0, u22 = 0, u23 = 0, u24 = 0, u25 = 0, u26 = 0, u27 = 0, u28 = 0, u29 = 0, u30 = 0;
#include "funkcia.c"


int main(){

int cstart, c1, c2, c3, c4, c5, c6, c7, c8, c9, c10,c11, c12, c13, c14, c15, c16, c17, c18, c19, c20, c21, c22, c23, c24, c25, c26, c27, c28, c29, c30;

FILE *vstup, *vystup;
vstup = fopen("sifra.txt", "r");


c1 = (getc(vstup) -48);
c1 = 10 * c1 + (getc(vstup) -48);
c1 = 10 * c1 + (getc(vstup) -48);
/*3/64*/
c2 = (getc(vstup) -48);
c2 = 10 * c2 + (getc(vstup) -48);

c3 = (getc(vstup) -48);

c4 = (getc(vstup) -48);
c4 = 10 * c4 + (getc(vstup) -48);
c4 = 10 * c4 + (getc(vstup) -48);

c5 = (getc(vstup) -48);
c5 = 10 * c5 + (getc(vstup) -48);

c6 = (getc(vstup) -48);

c7 = (getc(vstup) -48);
c7 = 10 * c7 + (getc(vstup) -48);
c7 = 10 * c7 + (getc(vstup) -48);

c8 = (getc(vstup) -48);
c8 = 10 * c8 + (getc(vstup) -48);

c9 = (getc(vstup) -48);

c10 = (getc(vstup) -48);
c10 = (10 * c10 + getc(vstup) -48);
c10 = (10 * c10 + getc(vstup) -48);

c11 = (getc(vstup) -48);
c11 = 10 * c11 + (getc(vstup) -48);

c12 = (getc(vstup) -48);

c13 = (getc(vstup) -48);
c13 = 10 * c13 + (getc(vstup) -48);
c13 = 10 * c13 + (getc(vstup) -48);

c14 = (getc(vstup) -48);                                    /*50. riadok*/
c14 = 10 * c14 + (getc(vstup) -48);

c15 = (getc(vstup) -48);

c16 = (getc(vstup) -48);
c16 = 10 * c16 + (getc(vstup) -48);
c16 = 10 * c16 + (getc(vstup) -48);

c17 = (getc(vstup) -48);
c17 = 10 * c17 + (getc(vstup) -48);

c18 = (getc(vstup) -48);

c19 = (getc(vstup) -48);
c19 = 10 * c19 + (getc(vstup) -48);
c19 = 10 * c19 + (getc(vstup) -48);

c20 = (getc(vstup) -48);
c20 = 10 * c20 + (getc(vstup) -48);

c21 = (getc(vstup) -48);

c22 = (getc(vstup) -48);
c22 = 10 * c22 + (getc(vstup) -48);
c22 = 10 * c22 + (getc(vstup) -48);

c23 = (getc(vstup) -48);
c23 = 10 * c23 + (getc(vstup) -48);

c24 = (getc(vstup) -48);

c25 = (getc(vstup) -48);
c25 = 10 * c25 + (getc(vstup) -48);
c25 = 10 * c25 + (getc(vstup) -48);

c26 = (getc(vstup) -48);
c26 = 10 * c26 + (getc(vstup) -48);

c27 = (getc(vstup) -48);

c28 = (getc(vstup) -48);
c28 = 10 * c28 + (getc(vstup) -48);
c28 = 10 * c28 + (getc(vstup) -48);

c29 = (getc(vstup) -48);
c29 = 10 * c29 + (getc(vstup) -48);

c30 = (getc(vstup) -48);

/* kontrola pri tvorbe programu..                             99. riadok
printf("%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d", c1, c2, c3, c4, c5, c6, c7, c8, c9, c10, c11, c12, c13, c14, c15, c6, c17, c18, c19, c20, c21, c22, c23, c24, c25, c26, c27, c28, c29, c30);
*/
cstart = (getc(vstup) - 48) * 10 + (getc(vstup) - 48);

int  prve, druhe, predprve, preddruhe, vysl_prve, vysl_druhe, c63, c64;

c63 = (getc(vstup) - 48);
c64 = (getc(vstup) - 48);

predprve =  cstart / 10;
preddruhe = cstart;

prve = (predprve % 30) + 1;
druhe = (preddruhe % 30) + 1;



switch (prve){
  case 1: {vysl_prve = c1;
           u1 = 1;
          }
    break;
  case 2: {vysl_prve = c2;
           u2 = 1;
          }
    break;
  case 3: {vysl_prve = c3;
           u3 = 1;
          }
    break;
  case 4: {vysl_prve = c4;
           u4 = 1;
          }
    break;
  case 5: {vysl_prve = c5;
           u5 = 1;
          }
    break;
  case 6: {vysl_prve = c6;
           u6 = 1;
          }
    break;
  case 7: {vysl_prve = c7;
           u7 = 1;
          }
    break;
  case 8: {vysl_prve = c8;
           u8 = 1;
          }
    break;
  case 9: {vysl_prve = c9;
           u9 = 1;
          }
    break;
  case 10: {vysl_prve = c10;
           u10 = 1;
           }
    break;
  case 11: {vysl_prve = c11;
           u11 = 1;
           }
    break;
  case 12: {vysl_prve = c12;
           u12 = 1;
           }
    break;
  case 13: {vysl_prve = c13;
           u13 = 1;
           }
    break;
  case 14: {vysl_prve = c14;
           u14 = 1;
           }
    break;
  case 15: {vysl_prve = c15;
           u15 = 1;
           }
    break;
  case 16: {vysl_prve = c16;
           u16 = 1;
           }
    break;
  case 17: {vysl_prve = c17;
           u17 = 1;
           }
    break;
  case 18: {vysl_prve = c18;
           u18 = 1;
           }
    break;
  case 19: {vysl_prve = c19;
           u19 = 1;
           }
    break;
  case 20: {vysl_prve = c20;
           u20 = 1;
           }
    break;
  case 21: {vysl_prve = c21;
           u21 = 1;
           }
    break;
  case 22: {vysl_prve = c22;
           u22 = 1;
           }
    break;
  case 23: {vysl_prve = c23;
           u23 = 1;
           }
    break;
  case 24: {vysl_prve = c24;
           u24 = 1;
           }
    break;
  case 25: {vysl_prve = c25;
           u25 = 1;
           }
    break;
  case 26: {vysl_prve = c26;
           u26 = 1;
           }
    break;
  case 27: {vysl_prve = c27;
           u27 = 1;
           }
    break;
  case 28: {vysl_prve = c28;
           u28 = 1;
           }
    break;
  case 29: {vysl_prve = c29;
           u29 = 1;
           }
    break;
  case 30: {vysl_prve = c30;
           u30 = 1;
           }
    break;
  default: fprintf(vystup, "switch error");
}



switch (druhe){
  case 1: {vysl_druhe = c1;
           u1 = 1;
          }
    break;
  case 2: {vysl_druhe = c2;
           u2 = 1;
          }
    break;
  case 3: {vysl_druhe = c3;
           u3 = 1;
          }
    break;
  case 4: {vysl_druhe = c4;
           u4 = 1;
          }
    break;
  case 5: {vysl_druhe = c5;
           u5 = 1;
          }
    break;
  case 6: {vysl_druhe = c6;
           u6 = 1;
          }
    break;
  case 7: {vysl_druhe = c7;
           u7 = 1;
          }
    break;
  case 8: {vysl_druhe = c8;
           u8 = 1;
          }
    break;
  case 9: {vysl_druhe = c9;
           u9 = 1;
          }
    break;
  case 10: {vysl_druhe = c10;
           u10 = 1;
           }
    break;
  case 11: {vysl_druhe = c11;
           u11 = 1;
           }
    break;
  case 12: {vysl_druhe = c12;
           u12 = 1;
           }
    break;
  case 13: {vysl_druhe = c13;
           u13 = 1;
           }
    break;
  case 14: {vysl_druhe = c14;
           u14 = 1;
           }
    break;
  case 15: {vysl_druhe = c15;
           u15 = 1;
           }
    break;
  case 16: {vysl_druhe = c16;
           u16 = 1;
           }
    break;
  case 17: {vysl_druhe = c17;
           u17 = 1;
           }
    break;
  case 18: {vysl_druhe = c18;
           u18 = 1;
           }
    break;
  case 19: {vysl_druhe = c19;
           u19 = 1;
           }
    break;
  case 20: {vysl_druhe = c20;
           u20 = 1;
           }
    break;
  case 21: {vysl_druhe = c21;
           u21 = 1;
           }
    break;
  case 22: {vysl_druhe = c22;
           u22 = 1;
           }
    break;
  case 23: {vysl_druhe = c23;
           u23 = 1;
           }
    break;
  case 24: {vysl_druhe = c24;
           u24 = 1;
           }
    break;
  case 25: {vysl_druhe = c25;
           u25 = 1;
           }
    break;
  case 26: {vysl_druhe = c26;
           u26 = 1;
           }
    break;
  case 27: {vysl_druhe = c27;
           u27 = 1;
           }
    break;
  case 28: {vysl_druhe = c28;
           u28 = 1;
           }
    break;
  case 29: {vysl_druhe = c29;
           u29 = 1;
           }
    break;
  case 30: {vysl_druhe = c30;
           u30 = 1;
           }
    break;
  default: fprintf(vystup, "switch error");
}

/*kontrola pri tvorbe programu..
printf("vysl_prve: %d, vysl_druhe: %d, cstart: %d, predprve: %d, preddruhe: %d, prve: %d, druhe: %d", vysl_prve, vysl_druhe, cstart, predprve, preddruhe, prve, druhe);
*/
printf("%d", c4 * c10);

vystup = fopen("vystup.txt", "w");
fprintf(vystup, "%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d", c1, c2, c3, c4, c5, c6, c7, c8, c9, c10, c11, c12, c13, c14, c15, c16, c17, c18, c19, c20, c21, c22, c23, c24, c25, c26, c27, c28, c29, c30, c63, c64);

int pocet_vloz_znak, vloz_znak, zmena1, zmena2;

vloz_znak = vysl_prve * vysl_druhe;
pocet_vloz_znak = fprintf(vystup, "%d", vloz_znak);


while(pocet_vloz_znak < 640){
  prve = mozna((vysl_prve % 30) + 1);
  druhe = mozna((vysl_druhe % 30) + 1);

  switch (prve){
    case 1: {vysl_prve = c1;
             u1 = 1;
             zmena1 = 3;
            }
      break;
    case 2: {vysl_prve = c2;
             zmena1 = 5;
             u2 = 1;
            }
      break;
    case 3: {vysl_prve = c3;
             zmena1 = 19;
             u3 = 1;
            }
      break;
      case 4: {vysl_prve = c4;
             zmena1 = 8;
             u4 = 1;
            }
      break;
    case 5: {vysl_prve = c5;
             zmena1 = 26;
             u5 = 1;
            }
      break;
    case 6: {vysl_prve = c6;
             zmena1 = 29;
             u6 = 1;
            }
      break;
    case 7: {vysl_prve = c7;
             zmena1 = 24;
             u7 = 1;
            }
      break;
    case 8: {vysl_prve = c8;
             zmena1 = 12;
             u8 = 1;
            }
      break;
    case 9: {vysl_prve = c9;
             zmena1 = 9;
             u9 = 1;
            }
      break;
    case 10: {vysl_prve = c10;
             zmena1 = 1;
             u10 = 1;
             }
      break;
    case 11: {vysl_prve = c11;
             zmena1 = 21;
             u11 = 1;
             }
      break;
    case 12: {vysl_prve = c12;
             zmena1 = 13;
             u12 = 1;
             }
      break;
    case 13: {vysl_prve = c13;
             zmena1 = 2;
             u13 = 1;
             }
      break;
    case 14: {vysl_prve = c14;
             zmena1 = 7;
             u14 = 1;
             }
      break;
    case 15: {vysl_prve = c15;
             zmena1 = 30;
             u15 = 1;
             }
      break;
    case 16: {vysl_prve = c16;
             zmena1 = 20;
             u16 = 1;
             }
      break;
    case 17: {vysl_prve = c17;
             zmena1 = 4;
             u17 = 1;
             }
      break;
    case 18: {vysl_prve = c18;
             zmena1 = 6;
             u18 = 1;
             }
      break;
    case 19: {vysl_prve = c19;
             zmena1 = 27;
             u19 = 1;
             }
      break;
    case 20: {vysl_prve = c20;
             zmena1 = 28;
             u20 = 1;
             }
      break;
    case 21: {vysl_prve = c21;
             zmena1 = 15;
             u21 = 1;
             }
      break;
    case 22: {vysl_prve = c22;
             zmena1 = 10;
             u22 = 1;
             }
      break;
    case 23: {vysl_prve = c23;
             zmena1 = 14;
             u23 = 1;
             }
      break;
    case 24: {vysl_prve = c24;
             zmena1 = 17;
             u24 = 1;
             }
      break;
    case 25: {vysl_prve = c25;
             zmena1 = 23;
             u25 = 1;
             }
      break;
    case 26: {vysl_prve = c26;
             zmena1 = 11;
             u26 = 1;
             }
      break;
    case 27: {vysl_prve = c27;
             zmena1 = 16;
             u27 = 1;
             }
      break;
    case 28: {vysl_prve = c28;
             zmena1 = 22;
             u28 = 1;
             }
      break;
    case 29: {vysl_prve = c29;
             zmena1 = 25;
             u29 = 1;
             }
      break;
    case 30: {vysl_prve = c30;
             zmena1 = 18;
             u30 = 1;
             }
      break;
  default: fprintf(vystup, "switch error");
  }



  switch (druhe){
    case 1: {vysl_druhe = c1;
             zmena2 = 5;
             u1 = 1;
            }
      break;
    case 2: {vysl_druhe = c2;
             zmena2 = 21;
             u2 = 1;
            }
      break;
    case 3: {vysl_druhe = c3;
             zmena2 = 20;
             u3 = 1;
            }
      break;
    case 4: {vysl_druhe = c4;
             zmena2 = 25;
             u4 = 1;
            }
      break;
    case 5: {vysl_druhe = c5;
             zmena2 = 30;
             u5 = 1;
            }
      break;
    case 6: {vysl_druhe = c6;
             zmena2 = 28;
             u6 = 1;
            }
      break;
    case 7: {vysl_druhe = c7;
             zmena2 = 13;
             u7 = 1;
            }
      break;
    case 8: {vysl_druhe = c8;
             zmena2 = 9;
             u8 = 1;
            }
      break;
    case 9: {vysl_druhe = c9;
             zmena2 = 17;
             u9 = 1;
            }
      break;
    case 10: {vysl_druhe = c10;
             zmena2 = 22;
             u10 = 1;
             }
      break;
    case 11: {vysl_druhe = c11;
             zmena2 = 18;
             u11 = 1;
             }
      break;
    case 12: {vysl_druhe = c12;
             zmena2 = 19;
            u12 = 1;
             }
      break;
    case 13: {vysl_druhe = c13;
             zmena2 = 16;
             u13 = 1;
             }
      break;
    case 14: {vysl_druhe = c14;
             zmena2 = 24;
             u14 = 1;
             }
      break;
    case 15: {vysl_druhe = c15;
             zmena2 = 10;
             u15 = 1;
             }
      break;
    case 16: {vysl_druhe = c16;
             zmena2 = 29;
             u16 = 1;
             }
      break;
    case 17: {vysl_druhe = c17;
             zmena2 = 27;
             u17 = 1;
             }
      break;
    case 18: {vysl_druhe = c18;
             zmena2 = 23;
             u18 = 1;
             }
      break;
    case 19: {vysl_druhe = c19;
             zmena2 = 26;
             u19 = 1;
             }
      break;
    case 20: {vysl_druhe = c20;
             zmena2 = 15;
             u20 = 1;
             }
      break;
    case 21: {vysl_druhe = c21;
             zmena2 = 14;
             u21 = 1;
             }
      break;
    case 22: {vysl_druhe = c22;
             zmena2 = 11;
             u22 = 1;
             }
      break;
    case 23: {vysl_druhe = c23;
             zmena2 = 7;
             u23 = 1;
             }
      break;
    case 24: {vysl_druhe = c24;
             zmena2 = 8;
             u24 = 1;
             }
      break;
    case 25: {vysl_druhe = c25;
             zmena2 = 2;
             u25 = 1;
             }
      break;
    case 26: {vysl_druhe = c26;
             zmena2 = 6;
             u26 = 1;
             }
      break;
    case 27: {vysl_druhe = c27;
             zmena2 = 1;
             u27 = 1;
             }
      break;
    case 28: {vysl_druhe = c28;
             zmena2 = 12;
             u28 = 1;
             }
      break;
    case 29: {vysl_druhe = c29;
             zmena2 = 3;
             u29 = 1;
             }
      break;
    case 30: {vysl_druhe = c30;
             zmena2 = 4;
             u30 = 1;
             }
      break;
  default: fprintf(vystup, "switch error");
  }

  vloz_znak = vysl_prve * vysl_druhe;
  pocet_vloz_znak += fprintf(vystup, "%d", vloz_znak);

  switch(zmena1){
    case 1: c1 = vysl_druhe + ((5000 - c1) / 10);
      break;
    case 2: c2 = vysl_druhe + ((5000 - c2) / 10);
      break;
    case 3: c3 = vysl_druhe + ((5000 - c3) / 10);
      break;
    case 4: c4 = vysl_druhe + ((5000 - c4) / 10);
      break;
    case 5: c5 = vysl_druhe + ((5000 - c5) / 10);
      break;
    case 6: c6 = vysl_druhe + ((5000 - c6) / 10);
      break;
    case 7: c7 = vysl_druhe + ((5000 - c7) / 10);
      break;
    case 8: c8 = vysl_druhe + ((5000 - c8) / 10);
      break;
    case 9: c9 = vysl_druhe + ((5000 - c9) / 10);
      break;
    case 10: c10 = vysl_druhe + ((5000 - c10) / 10);
      break;
    case 11: c11 = vysl_druhe + ((5000 - c11) / 10);
      break;
    case 12: c12 = vysl_druhe + ((5000 - c12) / 10);
      break;
    case 13: c13 = vysl_druhe + ((5000 - c13) / 10);
      break;
    case 14: c14 = vysl_druhe + ((5000 - c14) / 10);
      break;
    case 15: c15 = vysl_druhe + ((5000 - c15) / 10);
      break;
    case 16: c16 = vysl_druhe + ((5000 - c16) / 10);
      break;
    case 17: c17 = vysl_druhe + ((5000 - c17) / 10);
      break;
    case 18: c18 = vysl_druhe + ((5000 - c18) / 10);
      break;
    case 19: c19 = vysl_druhe + ((5000 - c19) / 10);
      break;
    case 20: c20 = vysl_druhe + ((5000 - c20) / 10);
      break;
    case 21: c21 = vysl_druhe + ((5000 - c21) / 10);
      break;
    case 22: c22 = vysl_druhe + ((5000 - c22) / 10);
      break;
    case 23: c23 = vysl_druhe + ((5000 - c23) / 10);
      break;
    case 24: c24 = vysl_druhe + ((5000 - c24) / 10);
      break;
    case 25: c25 = vysl_druhe + ((5000 - c25) / 10);
      break;
    case 26: c26 = vysl_druhe + ((5000 - c26) / 10);
      break;
    case 27: c27 = vysl_druhe + ((5000 - c27) / 10);
      break;
    case 28: c28 = vysl_druhe + ((5000 - c28) / 10);
      break;
    case 29: c29 = vysl_druhe + ((5000 - c29) / 10);
      break;
    case 30: c30 = vysl_druhe + ((5000 - c30) / 10);
      break;
  default: fprintf(vystup, "switch error");
  }


  switch(zmena2){
    case 1: c1 = vysl_prve + ((5000 - c1) / 10);
      break;
    case 2: c2 = vysl_prve + ((5000 - c2) / 10);
      break;
    case 3: c3 = vysl_prve + ((5000 - c3) / 10);
      break;
    case 4: c4 = vysl_prve + ((5000 - c4) / 10);
      break;
    case 5: c5 = vysl_prve + ((5000 - c5) / 10);
      break;
    case 6: c6 = vysl_prve + ((5000 - c6) / 10);
      break;
    case 7: c7 = vysl_prve + ((5000 - c7) / 10);
      break;
    case 8: c8 = vysl_prve + ((5000 - c8) / 10);
      break;
    case 9: c9 = vysl_prve + ((5000 - c9) / 10);
      break;
    case 10: c10 = vysl_prve + ((5000 - c10) / 10);
      break;
    case 11: c11 = vysl_prve + ((5000 - c11) / 10);
      break;
    case 12: c12 = vysl_prve + ((5000 - c12) / 10);
      break;
    case 13: c13 = vysl_prve + ((5000 - c13) / 10);
      break;
    case 14: c14 = vysl_prve + ((5000 - c14) / 10);
      break;
    case 15: c15 = vysl_prve + ((5000 - c15) / 10);
      break;
    case 16: c16 = vysl_prve + ((5000 - c16) / 10);
      break;
    case 17: c17 = vysl_prve + ((5000 - c17) / 10);
      break;
    case 18: c18 = vysl_prve + ((5000 - c18) / 10);
      break;
    case 19: c19 = vysl_prve + ((5000 - c19) / 10);
      break;
    case 20: c20 = vysl_prve + ((5000 - c20) / 10);
      break;
    case 21: c21 = vysl_prve + ((5000 - c21) / 10);
      break;
    case 22: c22 = vysl_prve + ((5000 - c22) / 10);
      break;
    case 23: c23 = vysl_prve + ((5000 - c23) / 10);
      break;
    case 24: c24 = vysl_prve + ((5000 - c24) / 10);
      break;
    case 25: c25 = vysl_prve + ((5000 - c25) / 10);
      break;
    case 26: c26 = vysl_prve + ((5000 - c26) / 10);
      break;
    case 27: c27 = vysl_prve + ((5000 - c27) / 10);
      break;
    case 28: c28 = vysl_prve + ((5000 - c28) / 10);
      break;
    case 29: c29 = vysl_prve + ((5000 - c29) / 10);
      break;
    case 30: c30 = vysl_prve + ((5000 - c30) / 10);
      break;
  default: fprintf(vystup, "switch error");
  }
  
}






return 0;
}