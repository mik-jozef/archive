#include <stdio.h>

int main(){
printf("Zvolte jazyk/Choose language:");

  /* pridám neskôr*/
  printf("\nJe mi luto, funkcia zvolenia jazyka je momentalne nedostupna..\nI'm sorry, you can't choose your language for now..\n\n\n");


int hlavna_akcia, koniec, pocet_n_riadkov = 16;
Zaciatok:
printf("Zvolte akciu napisanim a stlacenim klavesy Enter:\nNova hra - n\nPokracovat ulozenu hru (momentalne nedostupne) - p\nUkoncit program - u  Znak:");

while (pocet_n_riadkov > 0){
  printf("\n");
  pocet_n_riadkov--;
}

hlavna_akcia = getchar();
while (getchar() != '\n')
;



if (hlavna_akcia != 'n' && hlavna_akcia != 'N' && hlavna_akcia != 'p' && hlavna_akcia != 'P' && hlavna_akcia != 'u' && hlavna_akcia != 'U'){
  printf("Zadana hotnota je nespravna. Opakujte akciu prosim.\n\n");
  pocet_n_riadkov = 19;
  goto Zaciatok;
}



if (hlavna_akcia == 'n' || hlavna_akcia == 'N'){ /*zaciatok hry*/
  pocet_n_riadkov = 22;
  int hra;
  S_kym:
  
  printf("S kym chcete hrat:\nS clovekom - c\nS pocitacom - p  Znak:");
  
  while (pocet_n_riadkov > 0){
    printf("\n");
    pocet_n_riadkov--;
  }
  
  hra = getchar();
  while (getchar() != '\n')
  ;



    while (hra != 'c' && hra != 'C' && hra != 'p'&& hra!= 'P'){
      printf("Zadana hotnota je nespravna. Opakujte akciu prosim.\n");
	  pocet_n_riadkov = 21;
      goto S_kym;
    }

    if (hra == 'c' || hra == 'C'){ /*Zaèiatok s èlovekom*/

      int riadok, stlpec;
      int a1 = '_', a2 = '_', a3 = '_', b1 = '_', b2 = '_', b3 = '_', c1 = '_', c2 = '_', c3 = '_';
sem:
      while (!((a1 == 'X' && a2 == 'X' && a3 == 'X') /*vsetky riadky su jedneho hraca*/
            || (b1 == 'X' && b2 == 'X' && b3 == 'X')
            || (c1 == 'X' && c2 == 'X' && c3 == 'X')

            || (a1 == 'X' && b1 == 'X' && c1 == 'X') /*vsetky stlpce su jedneho hraca*/
            || (a2 == 'X' && b2 == 'X' && c2 == 'X')
            || (a3 == 'X' && b3 == 'X' && c3 == 'X')

            || (a1 == 'X' && b2 == 'X' && c3 == 'X') /*do kriza*/
            || (c1 == 'X' && c2 == 'X' && c1 == 'X'))){ /*Zaèiatok 1. while*/

        /*vypis hracej plochy*/
        printf("\n   1 2 3\n a %c %c %c          Teraz je na tahu O.\n b %c %c %c\n c %c %c %c\n\n\n\n\n", a1, a2, a3, b1, b2, b3, c1, c2, c3);


        if (a1 != '_' && a2 != '_' && a3 != '_' && b1 != '_' && b2 != '_' && b3 != '_' && c1 != '_' && c2 != '_' && c3 != '_'){
          printf("\n\n\n============================================================\nRemiza. Stlacte lubovolnu klavesu pre ukoncenie hry. ");
          koniec = getchar();
          while (getchar() != '\n'){
            ;
          }
          return 0;
        }


hracO:
        printf("Zadajte riadok (a/b/c):\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
        riadok = getchar();
        while (getchar() != '\n'){
          ;
        }

        printf("\n   1 2 3\n a %c %c %c          Teraz je na tahu O.\n b %c %c %c\n c %c %c %c\n\n\n\n\nZadajte riadok (a/b/c):%c\nZadajte stlpec (1/2/3):\n\n\n\n\n\n\n\n\n\n\n\n\n\n", a1, a2, a3, b1, b2, b3, c1, c2, c3, riadok);
        stlpec = getchar();
        while (getchar() != '\n'){
          ;
        }



        printf("riadok:%c, stlpec:%c\n", riadok, stlpec);

        switch (riadok){
          case 'a': switch(stlpec){    

                      case '1': if (a1 != '_'){
                                  printf("Toto pole je uz obsadene. Opakujte tah.\n");
                                  goto hracO;} else a1 = 'O'; 
                        break;

                      case '2': if (a2 != '_'){
                                  printf("Toto pole je uz obsadene. Opakujte tah.\n");
                                  goto hracO;} else a2 = 'O'; 
                        break;

                      case '3': if (a3 != '_'){
                                  printf("Toto pole je uz obsadene. Opakujte tah.\n");
                                  goto hracO;} else a3 = 'O'; 
                        break;

                      default: printf("Zla hodnota. Opakujte tah.\n");
                               goto hracO;
                        break;};
            break;


          case 'b': switch(stlpec){

                      case '1': if (b1 != '_'){
                                  printf("Toto pole je uz obsadene. Opakujte tah.\n");
                                  goto hracO;} else b1 = 'O'; 
                        break;

                      case '2': if (b2 != '_'){
                                  printf("Toto pole je uz obsadene. Opakujte tah.\n");
                                  goto hracO;} else b2 = 'O'; 
                        break;

                      case '3': if (b3 != '_'){
                                  printf("Toto pole je uz obsadene. Opakujte tah.\n");
                                  goto hracO;} else b3 = 'O'; 
                        break;

                      default: printf("Zla hodnota. Opakujte tah.\n");
                               goto hracO;
                        break;};
            break;

          case 'c': switch(stlpec){

                      case '1': if (c1 != '_'){
                                  printf("Toto pole je uz obsadene. Opakujte tah.\n");
                                  goto hracO;} else c1 = 'O'; 
                        break;

                      case '2': if (c2 != '_'){
                                  printf("Toto pole je uz obsadene. Opakujte tah.\n");
                                  goto hracO;} else c2 = 'O'; 
                        break;

                      case '3': if (c3 != '_'){
                                  printf("Toto pole je uz obsadene. Opakujte tah.\n");
                                  goto hracO;} else c3 = 'O'; 
                        break;
    
                      default: printf("Zla hodnota. Opakujte tah.\n");
                               goto hracO;
                        break;};
            break;

          default: printf("Zla hodnota. Opakujte tah.\n");
                   goto hracO;
            break;}

        riadok = 0; stlpec = 0; /*vynulovanie, nema pointu*/

        while (!((a1 == 'O' && a2 == 'O' && a3 == 'O') /*vsetky riadky su jedneho hraca*/
              || (b1 == 'O' && b2 == 'O' && b3 == 'O')
              || (c1 == 'O' && c2 == 'O' && c3 == 'O')

              || (a1 == 'O' && b1 == 'O' && c1 == 'O') /*vsetky stlpce su jedneho hraca*/
              || (a2 == 'O' && b2 == 'O' && c2 == 'O')
              || (a3 == 'O' && b3 == 'O' && c3 == 'O')

              || (a1 == 'O' && b2 == 'O' && c3 == 'O') /*do kriza*/
              || (c1 == 'O' && b2 == 'O' && a3 == 'O'))) { /*Zaèiatok 2. while*/

          /*vypis hracej plochy*/
          printf("\n   1 2 3\n a %c %c %c          Teraz je na tahu X\n b %c %c %c.\n c %c %c %c\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n", a1, a2, a3, b1, b2, b3, c1, c2, c3);

          if (a1 != '_' && a2 != '_' && a3 != '_' && b1 != '_' && b2 != '_' && b3 != '_' && c1 != '_' && c2 != '_' && c3 != '_'){
            printf("\n\n\n============================================================\nRemiza. Stlacte lubovolnu klavesu pre ukoncenie hry.. ");
            koniec = getchar();
            while (getchar() != '\n'){
              ;
            }
            return 0;
          }

          printf("Teraz je na tahu X.\n\n\n");
hracX:
          printf("Zadajte riadok(a/b/c):");
          riadok = getchar();
          while (getchar() != '\n'){
            ;
          }

          printf("Zadajte stlpec(1/2/3):");
          stlpec = getchar();
          while (getchar() != '\n'){
            ;
          }

          printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n");

          printf("riadok:%c, stlpec:%c\n", riadok, stlpec);

          switch (riadok){
            case 'a': switch(stlpec){

                        case '1': if (a1 != '_'){
                                  printf("Toto pole je uz obsadene. Opakujte tah.\n");
                                  goto hracO;} else a1 = 'O'; 
                          break;

                        case '2': if (a2 != '_'){
                                  printf("Toto pole je uz obsadene. Opakujte tah.\n");
                                  goto hracO;} else a3 = 'O'; 
                          break;

                        case '3': if (a3 != '_'){
                                  printf("Toto pole je uz obsadene. Opakujte tah.\n");
                                  goto hracO;} else a3 = 'O'; 
                          break;

                        default: printf("Zla hodnota. Opakujte tah.\n");
                                 goto hracX;
                          break;};
              break;


            case 'b': switch(stlpec){

                        case '1': if (b1 != '_'){
                                  printf("Toto pole je uz obsadene. Opakujte tah.\n");
                                  goto hracO;} else b1 = 'O'; 
                          break;

                        case '2': if (b2 != '_'){
                                  printf("Toto pole je uz obsadene. Opakujte tah.\n");
                                  goto hracO;} else b2 = 'O'; 
                          break;

                        case '3': if (b3 != '_'){
                                  printf("Toto pole je uz obsadene. Opakujte tah.\n");
                                  goto hracO;} else b3 = 'O'; 
                          break;

                        default: printf("Zla hodnota. Opakujte tah.\n");
                                 goto hracX;
                          break;};
              break;

            case 'c': switch(stlpec){

                        case '1': if (c1 != '_'){
                                  printf("Toto pole je uz obsadene. Opakujte tah.\n");
                                  goto hracO;} else c1 = 'O'; 
                          break;

                        case '2': if (c2 != '_'){
                                  printf("Toto pole je uz obsadene. Opakujte tah.\n");
                                  goto hracO;} else c2 = 'O'; 
                          break;

                        case '3': if (c3 != '_'){
                                  printf("Toto pole je uz obsadene. Opakujte tah.\n");
                                  goto hracO;} else c3 = 'O'; 
                          break;

                        default: printf("Zla hodnota. Opakujte tah.\n");
                                 goto hracX;
                          break;};
              break;

            default: printf("Zla hodnota. Opakujte tah.\n");
                     goto hracX;
              break;}


          riadok = 0; stlpec = 0; /*vynulovanie*/

          goto sem;      


            } /*Koniec 2. while*/

          /*vypis hracej plochy*/
          printf("\n  1 2 3\na %c %c %c\nb %c %c %c\nc %c %c %c\n\n\n\n===== Hrac O vyhral hru! =====\n\nStlacte lubovolnu klavesu pre ukoncenie programu.. ", a1, a2, a3, b1, b2, b3, c1, c2, c3);

          koniec = getchar();
          while (getchar() != '\n'){
            ;
          }
          return 0;
        }/*Koniec 1. while*/    
        
      /*vypis hracej plochy, vyhra, koniec*/
      printf("\n  1 2 3\na %c %c %c\nb %c %c %c\nc %c %c %c\n\n\n\n===== Hrac X vyhral hru! =====\n\nStlacte lubovolnu klavesu pre ukoncenie programu.. ", a1, a2, a3, b1, b2, b3, c1, c2, c3);
    }/*Koniec hry s èlovekom*/
    
  else
    printf("Hra s pocitacom zatial nie je mozna\nStlacte lubovolnu klavesu pre skoncenie programu.\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    koniec = getchar();
    while (getchar() != '\n'){
      ;
    }
  return 0;
}/*Koniec hry s pocitacom*/

else if (hlavna_akcia == 'p'|| hlavna_akcia == 'P'){
  printf("Je mi luto, momentalne nemozete nacitat ulozenu hru.\n\n");
  pocet_n_riadkov = 19;
  goto Zaciatok;
}

else if (hlavna_akcia == ('u' || 'U')){
  return 0;
}


}/*Koniec programu*/