#include <stdio.h>

int main(){
printf("Zvolte jazyk/Choose language:");

  /* pridám neskôr*/
  printf("\nJe mi luto, funkcia zvolenia jazyka je momentalne nedostupna..\nI'm sorry, you can't choose your language for now..\n\n\n");


int hlavna_akcia, koniec;
Zaciatok:
printf("Zvolte akciu napisanim a stlacenim klavesy Enter:\nNova hra - n\nPokracovat ulozenu hru (momentalne nedostupne) - p\nUkoncit program - u  Znak:");
hlavna_akcia = getchar();
while (getchar() != '\n')
;

printf("\n");

while (hlavna_akcia != 'n' && hlavna_akcia != 'N' && hlavna_akcia != 'p' && hlavna_akcia != 'P' && hlavna_akcia != 'u' && hlavna_akcia != 'U'){
printf("Zadana hotnota je nespravna. Opakujte akciu prosim.  Znak:");
hlavna_akcia = getchar();
while (getchar() != '\n')
;
}



if (hlavna_akcia == 'n' || hlavna_akcia == 'N'){ /*zaciatok hry*/

  long hra;
  printf("S kym chcete hrat:\nS clovekom - c\nS pocitacom - p  Znak:");
  hra = getchar();
  while (getchar() != '\n')
  ;

  printf("\n");

    while (hra != 'c' && hra != 'C' && hra != 'p'&& hra!= 'P'){
    printf("Zadana hotnota je nespravna. Opakujte akciu prosim.");
    hra = getchar();
    while (getchar() != '\n')
    ;
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

      printf("\n  1 2 3\na %c %c %c\nb %c %c %c\nc %c %c %c\n", a1, a2, a3, b1, b2, b3, c1, c2, c3);
      /*vypis hracej plochy*/

                if (a1 != '_' && a2 != '_' && a3 != '_' && b1 != '_' && b2 != '_' && b3 != '_' && c1 != '_' && c2 != '_' && c3 != '_'){
                  printf("Remiza. Stlacte lubovolnu klavesu pre ukoncenie hry.");
                  koniec = getchar();
                  while (getchar() != '\n')
                  ;
                  return 0;
                }

      printf("Teraz je na tahu O.\n\nZadajte riadok(a/b/c):");

      riadok = getchar();
      while (getchar() != '\n')
      ;

      printf("Zadajte stlpec(1/2/3):");
      stlpec = getchar();
      while (getchar() != '\n')
      ;

      printf("riadok:%c, stlpec:%c\n", riadok, stlpec);

      switch (riadok){
        case 'a': switch(stlpec){

                  case '1': (a1 == '_') ? a1 = 'O': printf("Toto pole je uz obsadene. Premarnili ste svoj tah.\n");
                    break;

                  case '2': (a2 == '_') ? a2 = 'O': printf("Toto pole je uz obsadene. Premarnili ste svoj tah.\n");
                    break;

                  case '3': (a3 == '_') ? a3 = 'O': printf("Toto pole je uz obsadene. Premarnili ste svoj tah.\n");
                    break;

                  default: printf("Zla hodnota. Premarnili ste svoj tah.\n");
                    break;};
          break;


        case 'b': switch(stlpec){

                  case '1': (b1 == '_') ? b1 = 'O': printf("Toto pole je uz obsadene. Premarnili ste svoj tah.\n");
                    break;

                  case '2': (b2 == '_') ? b2 = 'O': printf("Toto pole je uz obsadene. Premarnili ste svoj tah.\n");
                    break;

                  case '3': (b3 == '_') ? b3 = 'O': printf("Toto pole je uz obsadene. Premarnili ste svoj tah.\n");
                    break;

                  default: printf("Zla hodnota. Premarnili ste svoj tah.\n");
                    break;};
          break;

        case 'c': switch(stlpec){

                  case '1': (c1 == '_') ? c1 = 'O': printf("Toto pole je uz obsadene. Premarnili ste svoj tah.\n");
                    break;

                  case '2': (c2 == '_') ? c2 = 'O': printf("Toto pole je uz obsadene. Premarnili ste svoj tah.\n");
                    break;

                  case '3': (c3 == '_') ? c3 = 'O': printf("Toto pole je uz obsadene. Premarnili ste svoj tah.\n");
                    break;

                  default: printf("Zla hodnota. Premarnili ste svoj tah.\n");
                    break;};
          break;

        default: printf("Zla hodnota. Premarnili ste svoj tah.\n");
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

              printf("\n  1 2 3\na %c %c %c\nb %c %c %c\nc %c %c %c\n", a1, a2, a3, b1, b2, b3, c1, c2, c3);
              /*vypis hracej plochy*/

                if (a1 != '_' && a2 != '_' && a3 != '_' && b1 != '_' && b2 != '_' && b3 != '_' && c1 != '_' && c2 != '_' && c3 != '_'){
                  printf("\n\n\n====================================================\nRemiza. Stlacte lubovolnu klavesu pre ukoncenie hry..");
                  koniec = getchar();
                  while (getchar() != '\n')
                  ;
                  return 0;
                }

              printf("Teraz je na tahu X.\n\nZadajte riadok(a/b/c):");
              riadok = getchar();
              while (getchar() != '\n')
              ;

              printf("Zadajte stlpec(1/2/3):");
              stlpec = getchar();
              while (getchar() != '\n')
              ;

      printf("riadok:%c, stlpec:%c\n", riadok, stlpec);

      switch (riadok){
        case 'a': switch(stlpec){

                  case '1': (a1 == '_') ? a1 = 'X': printf("Toto pole je uz obsadene. Premarnili ste svoj tah.\n");
                    break;

                  case '2': (a2 == '_') ? a2 = 'X': printf("Toto pole je uz obsadene. Premarnili ste svoj tah.\n");
                    break;

                  case '3': (a3 == '_') ? a3 = 'X': printf("Toto pole je uz obsadene. Premarnili ste svoj tah.\n");
                    break;

                  default: printf("Zla hodnota. Premarnili ste svoj tah.\n");
                    break;};
          break;


        case 'b': switch(stlpec){

                  case '1': (b1 == '_') ? b1 = 'X': printf("Toto pole je uz obsadene. Premarnili ste svoj tah.\n");
                    break;

                  case '2': (b2 == '_') ? b2 = 'X': printf("Toto pole je uz obsadene. Premarnili ste svoj tah.\n");
                    break;

                  case '3': (b3 == '_') ? b3 = 'X': printf("Toto pole je uz obsadene. Premarnili ste svoj tah.\n");
                    break;

                  default: printf("Zla hodnota. Premarnili ste svoj tah.\n");
                    break;};
          break;

        case 'c': switch(stlpec){

                  case '1': (c1 == '_') ? c1 = 'X': printf("Toto pole je uz obsadene. Premarnili ste svoj tah.\n");
                    break;

                  case '2': (c2 == '_') ? c2 = 'X': printf("Toto pole je uz obsadene. Premarnili ste svoj tah.\n");
                    break;

                  case '3': (c3 == '_') ? c3 = 'X': printf("Toto pole je uz obsadene. Premarnili ste svoj tah.\n");
                    break;

                  default: printf("Zla hodnota. Premarnili ste svoj tah.\n");
                    break;};
          break;

        default: printf("Zla hodnota. Premarnili ste svoj tah.\n");
          break;}


riadok = 0; stlpec = 0; /*vynulovanie*/

                    goto sem;      


            } /*                         Koniec 2. while*/
      printf("\n  1 2 3\na %c %c %c\nb %c %c %c\nc %c %c %c\nTeraz je na tahu X.\n\nZadajte riadok(a/b/c):", a1, a2, a3, b1, b2, b3, c1, c2, c3);
      /*vypis hracej plochy*/
      printf("\n\n\n===== Hrac O vyhral hru! =====\n\nStlacte lubovolnu klavesu pre ukoncenie programu..");
      koniec = getchar();
      while (getchar() != '\n')
      ;
      return 0;
      }/*                                         Koniec 1. while*/
    printf("\n  1 2 3\na %c %c %c\nb %c %c %c\nc %c %c %c\nTeraz je na tahu X.\n\nZadajte riadok(a/b/c):", a1, a2, a3, b1, b2, b3, c1, c2, c3);
    /*vypis hracej plochy*/
    printf("\n\n\n===== Hrac X vyhral hru! =====\n\nStlacte lubovolnu klavesu pre ukoncenie programu..");
    }/*                                              Koniec S èlovekom*/
    else
    printf("Hra s pocitacom zatial nie je mozna\nStlacte lubovolnu klavesu pre skoncenie programu.  Znak:");
    koniec = getchar();
    while (getchar() != '\n')
    ;
    return 0;
}/*                                                   koniec hry*/

else if (hlavna_akcia == 'p'|| hlavna_akcia == 'P'){
printf("Je mi luto, momentalne nemozete nacitat ulozenu hru.\n\n\n\n");
goto Zaciatok;
}

else if (hlavna_akcia == ('u' || 'U')){
return 0;
}


}