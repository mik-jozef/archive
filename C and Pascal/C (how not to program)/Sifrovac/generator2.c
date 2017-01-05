/*program na gener·ciu n·hodn˝ch ËÌsel*/
#include <stdio.h>

int u1 = 0, u2 = 0, u3 = 0, u4 = 0, u5 = 0, u6 = 0, u7 = 0, u8 = 0, u9 = 0, u10 = 0, u11 = 0, u12 = 0, u13 = 0, u14 = 0, u15 = 0, u16 = 0, u17 = 0, u18 = 0, u19 = 0, u20 = 0, u21 = 0, u22 = 0, u23 = 0, u24 = 0, u25 = 0, u26 = 0, u27 = 0, u28 = 0, u29 = 0, u30 = 0, cstart, c1, c2, c3, c4, c5, c6, c7, c8, c9, c10,c11, c12, c13, c14, c15, c16, c17, c18, c19, c20, c21, c22, c23, c24, c25, c26, c27, c28, c29, c30, c63, c64;

/*PremennÈ c1 aû c30 obsahuj˙ (bud˙ obsahovaù) ËÌsla zo s˙boru sifra.txt, z ktor˝ch sa bud˙ tvoriù "n·hodnÈ" ËÌsla. PremennÈ u1 aû u30 nes˙ inform·cie o tom, Ëi sa ËÌsla c1 aû c30 uû pouûili alebo eöte nie. 0 = nepouûitÈ, 1 = pouûitÈ. KeÔ sa pouûi˙ vöetky tak sa vöetky nastavia na nepouûitÈ. Hodnota v cstart rozhoduje o tom, ktorÈ z ËÌsel c1 aû c30 sa ako prvÈ pouûi˙ na tvorbu "n·hodn˝ch" ËÌsel.*/

FILE *vstup, *vystup, *error;

int mozna(int start){             /*  Funkcia naËÌta ËÌslo od 1 do 30, vr·ti najbliûöie vyööie ËÌslo, kde premenn· u(nacitane_cislo) = 0. Ak u30 = 1,  */
switch (start){               /*  pokracuje ako keby nacitane cislo bolo 1 (ak je naËÌtanÈ ËÌslo 28 a u28 = 1, u29 = 1, u30 = 1, u1 = 1, funkcia   */
  case 1: goto sem1;          /*  vr·ti 2)                                                                                                 */
    break;
  case 2: goto sem2;
    break;
  case 3: goto sem3;
    break;
  case 4: goto sem4;
    break;
  case 5: goto sem5;
    break;
  case 6: goto sem6;
    break;
  case 7: goto sem7;
    break;
  case 8: goto sem8;
    break;
  case 9: goto sem9;
    break;
  case 10: goto sem10;
    break;
  case 11: goto sem11;
    break;
  case 12: goto sem12;
    break;
  case 13: goto sem13;
    break;
  case 14: goto sem14;
    break;
  case 15: goto sem15;
    break;
  case 16: goto sem16;
    break;
  case 17: goto sem17;
    break;
  case 18: goto sem18;
    break;
  case 19: goto sem19;
    break;
  case 20: goto sem20;
    break;
  case 21: goto sem21;
    break;
  case 22: goto sem22;
    break;
  case 23: goto sem23;
    break;
  case 24: goto sem24;
    break;
  case 25: goto sem25;
    break;
  case 26: goto sem26;
    break;
  case 27: goto sem27;
    break;
  case 28: goto sem28;
    break;
  case 29: goto sem29;
    break;
  case 30: goto sem30;
    break;
  default: fprintf(error, "Funkcia mozna() dostala cislo 0 alebo >30");
}
sem1:
if (u1 == 1){
  sem2:
  if(u2 == 1){
    sem3:
    if(u3 == 1){
      sem4:
      if(u4 == 1){
        sem5:
        if(u5 == 1){
          sem6:
          if(u6 == 1){
            sem7:
            if(u7 == 1){
              sem8:
              if(u8 == 1){
                sem9:
                if(u9 == 1){
                  sem10:
                  if(u10 == 1){
                    sem11:
                    if(u11 == 1){
                      sem12:
                      if(u12 == 1){
                        sem13:
                        if(u13 == 1){
                          sem14:
                          if(u14 == 1){
                            sem15:
                            if(u15 == 1){
                              sem16:
                              if(u16 == 1){
                                sem17:
                                if(u17 == 1){
                                  sem18:
                                  if(u18 == 1){
                                    sem19:
                                    if(u19 == 1){
                                      sem20:
                                      if(u20 == 1){
                                        sem21:
                                        if(u21 == 1){
                                          sem22:
                                          if(u22 == 1){
                                            sem23:
                                            if(u23 == 1){
                                              sem24:
                                              if(u24 == 1){
                                                sem25:
                                                if(u25 == 1){
                                                  sem26:
                                                  if(u26 == 1){
                                                    sem27:
                                                    if(u27 == 1){
                                                      sem28:
                                                      if(u28 == 1){
                                                        sem29:
                                                        if(u29 == 1){
                                                          sem30:
                                                          if(u30 == 1){
                                                                      goto sem1;
                                                                     }return 30;
                                                                   }return 29;
                                                                 }return 28;
                                                               }return 27;
                                                             }return 26;
                                                           }return 25;
                                                         }return 24;
                                                       }return 23;
                                                     }return 22;
                                                   }return 21;
                                                 }return 20;
                                               }return 19;
                                             }return 18;
                                           }return 17;
                                         }return 16;
                                       }return 15;
                                     }return 14;
                                   }return 13;
                                 }return 12;
                               }return 11;
                             }return 10;
                           }return 9;
                         }return 8;
                       }return 7;
                     }return 6;
                   }return 5;
                 }return 4;
               }return 3;
             }return 2;
           }return 1;


} /*koniec funkcie*/


int main(){

vstup = fopen("sifra.txt", "r");
vystup = fopen("vystup.txt", "w");
error = fopen("error.txt", "w");

c1 = (getc(vstup) -48);                   /*naËÌtanie prv˝ch 64 ËÌsel zo s˙boru sifra.txt*/
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

cstart = (getc(vstup) - 48) * 10 + (getc(vstup) - 48);

c63 = (getc(vstup) - 48);
c64 = (getc(vstup) - 48);

/* kontrola pri tvorbe programu..                             99. riadok
printf("%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d", c1, c2, c3, c4, c5, c6, c7, c8, c9, c10, c11, c12, c13, c14, c15, c6, c17, c18, c19, c20, c21, c22, c23, c24, c25, c26, c27, c28, c29, c30);
*/

int  prve, druhe, predprve, preddruhe, vysl_prve, vysl_druhe;  /*predprve (neupravene prve) je 61. ËÌslo zo s˙boru sifra.txt, a v premennej prve, kde je zv‰ËöenÈ o 1 je ËÌslo prvej c-premennej ktor· sa pouûie na tvorbu "n·hodn˝ch ËÌsel"(ak predprve == 3, tak prve == 4 a c4 sa pouûie na tvorbu ËÌsla). preddruhe je dvojcifernÈ cislo, ktorÈho zostatok po delenÌ 30 zv‰Ëöen˝ o 1 je ËÌslo druhej c-premennej (ak preddruhe == 72, tak druhe == 12 + 1 == 13 a c13 sa pouûie na tvorbu ËÌsla).*/

predprve =  cstart / 10;            /*  v˝poËty popÌsanÈ v predoölom koment·ri  */
preddruhe = cstart;

prve = ((predprve % 30) + 1);         /*  -||-                                    */
druhe = ((preddruhe % 30) + 1);



switch (prve){                      /*  Do vysl_prve je naËÌtan· hodnota PREMENNEJ c(cislo)(napr. c15) podla princÌpu predt˝m popÌsan˝m  */
  case 1: {vysl_prve = c1;
           u1 = 1;
          }
    break;
  case 2: {vysl_prve = c2;
           u2 = 1;                  /*  c2 sa po pouûitÌ oznaËÌ ako pouûit·, preto funkcia mozna() (pozri zaciatok suboru) nevrati 2     */
          }                         /*  dok˝m sa hodnoty  premenn˝ch u(cislo) neresetuj˙ */
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
  default: fprintf(error, "switch(prve) error");
}



switch (druhe){                      /*  Do vysl_druhe je naËÌtan· hodnota PREMENNEJ c(cislo)(napr. c21) podla princÌpu predt˝m popÌsan˝m  */
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
  default: fprintf(error, "switch(druhe) error");
}



/*kontrola pri tvorbe programu..
printf("vysl_prve: %d, vysl_druhe: %d, cstart: %d, predprve: %d, preddruhe: %d, prve: %d, druhe: %d", vysl_prve, vysl_druhe, cstart, predprve, preddruhe, prve, druhe);
*/






int pocet_znak, pocet_vloz_znak, vloz; /*pocet_vloz_znak obsahuje pocet vloûen˝ch znakov, vloz obsahuje ËÌslo ktorÈ bude vloûenÈ*/

fprintf(vystup, "%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d", c1, c2, c3, c4, c5, c6, c7, c8, c9, c10, c11, c12, c13, c14, c15, c16, c17, c18, c19, c20, c21, c22, c23, c24, c25, c26, c27, c28, c29, c30, cstart, c63, c64);/*  ZaËiatok v˝stupnÈho s˙boru bude obsahovaù aj prv˝ch 64 znakov  */
                                                                              /*  zo s˙boru sifra.txt, teda "kæ˙Ë" ku gener·ciÌ ËÌsel            */
scanf("%d", &pocet_znak);

vloz = vysl_prve * vysl_druhe;
pocet_vloz_znak = fprintf(vystup, "%d", vloz);             /*  VloûÌ 1. vygenerovanÈ ËÌslo do v˝stupnÈho s˙boru.  */






while(pocet_vloz_znak < pocet_znak){                              /*  Vklad· ËÌsla dok˝m ich nebude aspoÚ 640 (10 virtu·lnych (bez ukonËenia) riadkov  */
    printf("\nI'm here!(1)... Pocet_vloz_znak:%d\n", pocet_vloz_znak);
  prve = mozna(((vysl_prve % 30) + 1));                    /*  Pozri koment k funkcii mozna()  */
    printf("\nI'm here!(2)... Pocet_vloz_znak:%d\n", pocet_vloz_znak);
  druhe = mozna(((vysl_druhe % 30) + 1));

    printf("\nI'm here!(3)... Pocet_vloz_znak:%d\n", pocet_vloz_znak);

  switch (prve){
    case 1: {vysl_prve = c1;
             c3 = vysl_druhe + (c3 < 4000 || c3 > 7000) ? ((5000 - c3) / 10) : 1;         /*  MenÌ obsah premenn˝ch na Ôalöie spracovanie nech je to zaujÌmavejöie  */
             u1 = 1;                                       /*  (a ust·æuje ich pri hodnote 5000)                                     */
            }
      break;
    case 2: {vysl_prve = c2;
             c5 = vysl_druhe + (c5 < 4000 || c5 > 7000) ? ((5000 - c5) / 10) : 1;
             u2 = 1;                                       /*  VysvetlenÈ pri prvom switch  */
            }
      break;
    case 3: {vysl_prve = c3;
             c19 = vysl_druhe + (c19 < 4000 || c19 > 7000) ? ((5000 - c19) / 10) : 1;
             u3 = 1;
            }
      break;
      case 4: {vysl_prve = c4;
             c8 = vysl_druhe + (c8 < 4000 || c8 > 7000) ? ((5000 - c8) / 10) : 1;
             u4 = 1;
            }
      break;
    case 5: {vysl_prve = c5;
             c26 = vysl_druhe + (c26 < 4000 || c26 > 7000) ? ((5000 - c26) / 10) : 1;
             u5 = 1;
            }
      break;
    case 6: {vysl_prve = c6;
             c29 = vysl_druhe + (c29 < 4000 || c29 > 7000) ? ((5000 - c29) / 10) : 1;
             u6 = 1;
            }
      break;
    case 7: {vysl_prve = c7;
             c24 = vysl_druhe + (c24 < 4000 || c24 > 7000) ? ((5000 - c24) / 10) : 1;
             u7 = 1;
            }
      break;
    case 8: {vysl_prve = c8;
             c12 = vysl_druhe + ((5000 - c12) / 10);
             u8 = 1;
            }
      break;
    case 9: {vysl_prve = c9;
             c9 = vysl_druhe + (c9 < 4000 || c9 > 7000) ? ((5000 - c9) / 10) : 1;
             u9 = 1;
            }
      break;
    case 10: {vysl_prve = c10;
             c1 = vysl_druhe + (c1 < 4000 || c1 > 7000) ? ((5000 - c1) / 10) : 1;
             u10 = 1;
             }
      break;
    case 11: {vysl_prve = c11;
             c21 = vysl_druhe + (c21 < 4000 || c21 > 7000) ? ((5000 - c21) / 10) : 1;
             u11 = 1;
             }
      break;
    case 12: {vysl_prve = c12;
             c13 = vysl_druhe + (c13 < 4000 || c13 > 7000) ? ((5000 - c13) / 10) : 1;
             u12 = 1;
             }
      break;
    case 13: {vysl_prve = c13;
             c2 = vysl_druhe + (c2 < 4000 || c2 > 7000) ? ((5000 - c2) / 10) : 1;
             u13 = 1;
             }
      break;
    case 14: {vysl_prve = c14;
             c7 = vysl_druhe + (c7 < 4000 || c7 > 7000) ? ((5000 - c7) / 10) : 1;
             u14 = 1;
             }
      break;
    case 15: {vysl_prve = c15;
             c30 = vysl_druhe + (c30 < 4000 || c30 > 7000) ? ((5000 - c30) / 10) : 1;
             u15 = 1;
             }
      break;
    case 16: {vysl_prve = c16;
             c20 = vysl_druhe + (c20 < 4000 || c20 > 7000) ? ((5000 - c20) / 10) : 1;
             u16 = 1;
             }
      break;
    case 17: {vysl_prve = c17;
             c4 = vysl_druhe + (c4 < 4000 || c4 > 7000) ? ((5000 - c4) / 10) : 1;
             u17 = 1;
             }
      break;
    case 18: {vysl_prve = c18;
             c6 = vysl_druhe + (c6 < 4000 || c6 > 7000) ? ((5000 - c6) / 10) : 1;
             u18 = 1;
             }
      break;
    case 19: {vysl_prve = c19;
             c27 = vysl_druhe + (c27 < 4000 || c27 > 7000) ? ((5000 - c27) / 10) : 1;
             u19 = 1;
             }
      break;
    case 20: {vysl_prve = c20;
             c28 = vysl_druhe + (c28 < 4000 || c28 > 7000) ? ((5000 - c28) / 10) : 1;
             u20 = 1;
             }
      break;
    case 21: {vysl_prve = c21;
             c15 = vysl_druhe + (c15 < 4000 || c15 > 7000) ? ((5000 - c15) / 10) : 1;
             u21 = 1;
             }
      break;
    case 22: {vysl_prve = c22;
             c10 = vysl_druhe + (c10 < 4000 || c10 > 7000) ? ((5000 - c10) / 10) : 1;
             u22 = 1;
             }
      break;
    case 23: {vysl_prve = c23;
             c14 = vysl_druhe + (c14 < 4000 || c14 > 7000) ? ((5000 - c14) / 10) : 1;
             u23 = 1;
             }
      break;
    case 24: {vysl_prve = c24;
             c17 = vysl_druhe + (c17 < 4000 || c17 > 7000) ? ((5000 - c17) / 10) : 1;
             u24 = 1;
             }
      break;
    case 25: {vysl_prve = c25;
             c23 = vysl_druhe + (c23 < 4000 || c23 > 7000) ? ((5000 - c23) / 10) : 1;
             u25 = 1;
             }
      break;
    case 26: {vysl_prve = c26;
             c11 = vysl_druhe + (c11 < 4000 || c11 > 7000) ? ((5000 - c11) / 10) : 1;
             u26 = 1;
             }
      break;
    case 27: {vysl_prve = c27;
             c16 = vysl_druhe + (c16 < 4000 || c16 > 7000) ? ((5000 - c16) / 10) : 1;
             u27 = 1;
             }
      break;
    case 28: {vysl_prve = c28;
             c22 = vysl_druhe + (c22 < 4000 || c22 > 7000) ? ((5000 - c22) / 10) : 1;
             u28 = 1;
             }
      break;
    case 29: {vysl_prve = c29;
             c25 = vysl_druhe + (c25 < 4000 || c25 > 7000) ? ((5000 - c25) / 10) : 1;
             u29 = 1;
             }
      break;
    case 30: {vysl_prve = c30;
             c18 = vysl_druhe + (c18 < 4000 || c18 > 7000) ? ((5000 - c18) / 10) : 1;
             u30 = 1;
             }
      break;
    default: fprintf(error, "switch(prve) error");
  }

    printf("\nI'm here!(5)... Pocet_vloz_znak:%d\n", pocet_vloz_znak);

  switch (druhe){
    case 1: {vysl_druhe = c1;
             c5 = vysl_prve + (c5 < 4000 || c5 > 7000) ? ((5000 - c5) / 10) : 1;
             u1 = 1;
            }
      break;
    case 2: {vysl_druhe = c2;
             c21 = vysl_prve + (c21 < 4000 || c21 > 7000) ? ((5000 - c21) / 10) : 1;
             u2 = 1;
            }
      break;
    case 3: {vysl_druhe = c3;
             c20 = vysl_prve + (c20 < 4000 || c20 > 7000) ? ((5000 - c20) / 10) : 1;
             u3 = 1;
            }
      break;
    case 4: {vysl_druhe = c4;
             c25 = vysl_prve + (c25 < 4000 || c25 > 7000) ? ((5000 - c25) / 10) : 1;
             u4 = 1;
            }
      break;
    case 5: {vysl_druhe = c5;
             c30 = vysl_prve + (c30 < 4000 || c30 > 7000) ? ((5000 - c30) / 10) : 1;
             u5 = 1;
            }
      break;
    case 6: {vysl_druhe = c6;
             c28 = vysl_prve + (c28 < 4000 || c28 > 7000) ? ((5000 - c28) / 10) : 1;
             u6 = 1;
            }
      break;
    case 7: {vysl_druhe = c7;
             c13 = vysl_prve + (c13 < 4000 || c13 > 7000) ? ((5000 - c13) / 10) : 1;
             u7 = 1;
            }
      break;
    case 8: {vysl_druhe = c8;
             c9 = vysl_prve + (c9 < 4000 || c9 > 7000) ? ((5000 - c9) / 10) : 1;
             u8 = 1;
            }
      break;
    case 9: {vysl_druhe = c9;
             c17 = vysl_prve + (c17 < 4000 || c17 > 7000) ? ((5000 - c17) / 10) : 1;
             u9 = 1;
            }
      break;
    case 10: {vysl_druhe = c10;
             c22 = vysl_prve + (c22 < 4000 || c22 > 7000) ? ((5000 - c22) / 10) : 1;
             u10 = 1;
             }
      break;
    case 11: {vysl_druhe = c11;
             c18 = vysl_prve + (c18 < 4000 || c18 > 7000) ? ((5000 - c18) / 10) : 1;
             u11 = 1;
             }
      break;
    case 12: {vysl_druhe = c12;
             c19 = vysl_prve + (c19 < 4000 || c19 > 7000) ? ((5000 - c19) / 10) : 1;
            u12 = 1;
             }
      break;
    case 13: {vysl_druhe = c13;
             c16 = vysl_prve + (c16 < 4000 || c16 > 7000) ? ((5000 - c16) / 10) : 1;
             u13 = 1;
             }
      break;
    case 14: {vysl_druhe = c14;
             c24 = vysl_prve + (c24 < 4000 || c24 > 7000) ? ((5000 - c24) / 10) : 1;
             u14 = 1;
             }
      break;
    case 15: {vysl_druhe = c15;
             c10 = vysl_prve + (c10 < 4000 || c10 > 7000) ? ((5000 - c10) / 10) : 1;
             u15 = 1;
             }
      break;
    case 16: {vysl_druhe = c16;
             c29 = vysl_prve + (c29 < 4000 || c29 > 7000) ? ((5000 - c29) / 10) : 1;
             u16 = 1;
             }
      break;
    case 17: {vysl_druhe = c17;
             c27 = vysl_prve + (c27 < 4000 || c27 > 7000) ? ((5000 - c27) / 10) : 1;
             u17 = 1;
             }
      break;
    case 18: {vysl_druhe = c18;
             c23 = vysl_prve + (c23 < 4000 || c23 > 7000) ? ((5000 - c23) / 10) : 1;
             u18 = 1;
             }
      break;
    case 19: {vysl_druhe = c19;
             c26 = vysl_prve + (c26 < 4000 || c26 > 7000) ? ((5000 - c26) / 10) : 1;
             u19 = 1;
             }
      break;
    case 20: {vysl_druhe = c20;
             c15 = vysl_prve + (c15 < 4000 || c15 > 7000) ? ((5000 - c15) / 10) : 1;
             u20 = 1;
             }
      break;
    case 21: {vysl_druhe = c21;
             c14 = vysl_prve + (c14 < 4000 || c14 > 7000) ? ((5000 - c14) / 10) : 1;
             u21 = 1;
             }
      break;
    case 22: {vysl_druhe = c22;
             c11 = vysl_prve + ((5000 - c11) / 10);
             u22 = 1;
             }
      break;
    case 23: {vysl_druhe = c23;
             c7 = vysl_prve + (c7 < 4000 || c7 > 7000) ? ((5000 - c7) / 10) : 1;
             u23 = 1;
             }
      break;
    case 24: {vysl_druhe = c24;
             c8 = vysl_prve + (c8 < 4000 || c8 > 7000) ? ((5000 - c8) / 10) : 1;
             u24 = 1;
             }
      break;
    case 25: {vysl_druhe = c25;
             c2 = vysl_prve + (c2 < 4000 || c2 > 7000) ? ((5000 - c2) / 10) : 1;
             u25 = 1;
             }
      break;
    case 26: {vysl_druhe = c26;
             c6 = vysl_prve + (c6 < 4000 || c6 > 7000) ? ((5000 - c6) / 10) : 1;
             u26 = 1;
             }
      break;
    case 27: {vysl_druhe = c27;
             c1 = vysl_prve + (c1 < 4000 || c1 > 7000) ? ((5000 - c1) / 10) : 1;
             u27 = 1;
             }
      break;
    case 28: {vysl_druhe = c28;
             c12 = vysl_prve + (c12 < 4000 || c12 > 7000) ? ((5000 - c12) / 10) : 1;
             u28 = 1;
             }
      break;
    case 29: {vysl_druhe = c29;
             c3 = vysl_prve + (c3 < 4000 || c3 > 7000) ? ((5000 - c3) / 10) : 1;
             u29 = 1;
             }
      break;
    case 30: {vysl_druhe = c30;
             c4 = vysl_prve + (c4 < 4000 || c4 > 7000) ? ((5000 - c4) / 10) : 1;
             u30 = 1;
             }
      break;
    default: fprintf(error, "switch(druhe) error");
  }

  vloz = vysl_prve * vysl_druhe;
  pocet_vloz_znak += fprintf(vystup, "%d", vloz);
    printf("\nI'm here!(6)... Pocet_vloz_znak:%d\n", pocet_vloz_znak);


  if(u1 == 1 && u2 == 1 && u3 == 1 && u4 == 1 && u5 == 1 && u6 == 1 && u7 == 1 && u8 == 1 && u9 == 1 && u10 == 1 && u11 == 1 && u12 == 1 && u13 == 1 && u14 ==     1 && u15 == 1 && u16 == 1 && u17 == 1 && u18 == 1 && u19 == 1 && u20 == 1 && u21 == 1 && u22 == 1 && u23 == 1 && u24 == 1 && u25 == 1 && u26 == 1 && u27     == 1     && u28 == 1 && u29 == 1 && u30 == 1){
    u1 = 0;
    u2 = 0;
    u3 = 0;
    u4 = 0;
    u5 = 0;
    u6 = 0;
    u7 = 0;
    u8 = 0;
    u9 = 0;
    u10 = 0;
    u11 = 0;
    u12 = 0;
    u13 = 0;
    u14 = 0;
    u15 = 0;
    u16 = 0;
    u17 = 0;
    u18 = 0;
    u19 = 0;
    u20 = 0;
    u21 = 0;
    u22 = 0;
    u23 = 0;
    u24 = 0;
    u25 = 0;
    u26 = 0;
    u27 = 0;
    u28 = 0;
    u29 = 0;
    u30 = 0;
  }
}






return 0;
}