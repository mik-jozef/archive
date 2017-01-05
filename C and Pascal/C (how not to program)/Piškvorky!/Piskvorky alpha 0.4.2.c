#include <stdio.h>

int akcia = '_', koniec, chyba = 0;

void pridajPrazdnyRiadok(int pocet_riadkov){
  while (pocet_riadkov > 0){
  printf("\n");
  pocet_riadkov--;
 }
}

int vstup(){
  int i;
  i = getchar();
  while (getchar() != '\n'){
    ;
  }
  return i;
}

/*vypis hracej plochy*/
void vypisHracejPlochy(int hrac, int zla_hodnota, int a1, int a2, int a3, int b1, int b2, int b3,int c1, int c2, int c3){

  printf("  1 2 3\na %c %c %c", a1, a2, a3);
  
  if (hrac != 'n' && hrac != 'N'){
    printf("          Teraz je na tahu %c.", hrac);
  }
  
  printf("\nb %c %c %c", b1, b2, b3);
  
  if (zla_hodnota == 1){
    printf("          Zla hodnota. Opakujte tah.");
  } else if (zla_hodnota == 2){
    printf("          Toto pole je uz obsadene. Opakujte tah.");
  }

  printf("\nc %c %c %c", c1, c2, c3);
  pridajPrazdnyRiadok(5);
}




int main(){
printf("Zvolte jazyk/Choose language:\n");

  /*pridám neskôr*/
  printf("\nJe mi luto, funkcia zvolenia jazyka je momentalne nedostupna..\nI'm sorry, you can't choose language for now..\n\n\n");

/*uvodna sprava*/
printf("Zvolte akciu napisanim a stlacenim klavesy Enter:\nNova hra - n\nPokracovat ulozenu hru (momentalne nedostupne) - p\nUkoncit program - u");
pridajPrazdnyRiadok(15);
akcia = vstup();

/*opakovanie uvodnej spravy pri stlaceni zlej klavesy*/
while (akcia != 'n' && akcia != 'N' && akcia != 'p' && akcia != 'P' && akcia != 'u' && akcia != 'U'){
  printf("Zadana hotnota je nespravna. Opakujte akciu prosim.\n\nZvolte akciu napisanim a stlacenim klavesy Enter:\nNova hra - n\nPokracovat ulozenu hru (momentalne nedostupne) - p\nUkoncit program - u");
  pridajPrazdnyRiadok(19);
  akcia = vstup();
}


/*zaciatok hry*/
if (akcia == 'n' || akcia == 'N'){
  printf("S kym chcete hrat:\nS clovekom - c\nS pocitacom (momentalne nedostupne) - p");
  pridajPrazdnyRiadok(22);
  akcia = vstup();

  while (akcia != 'c' && akcia != 'C' && akcia != 'p'&& akcia!= 'P'){
    printf("Zadana hotnota je nespravna. Opakujte akciu prosim.\nS kym chcete hrat:\nS clovekom - c\nS pocitacom - p");
    pridajPrazdnyRiadok(21);
    akcia = vstup();
}

  /*Zaèiatok s èlovekom*/
  if (akcia == 'c' || akcia == 'C'){

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

hracO:
      vypisHracejPlochy('O', chyba, a1, a2, a3, b1, b2, b3,c1, c2, c3);
      chyba = 0;

      /*skuska remizy*/
      if (a1 != '_' && a2 != '_' && a3 != '_' && b1 != '_' && b2 != '_' && b3 != '_' && c1 != '_' && c2 != '_' && c3 != '_'){
        printf("Remiza.\n Stlacte ENTER pre ukoncenie programu.");
        getchar();
        return 0;
      }


      printf("Zadajte riadok (a/b/c):");
      pridajPrazdnyRiadok(16);
      riadok = vstup();

      vypisHracejPlochy('O', 0, a1, a2, a3, b1, b2, b3,c1, c2, c3);
      printf("Zadajte riadok (a/b/c):%c\nZadajte stlpec (1/2/3):", riadok);
      pridajPrazdnyRiadok(15);
      stlpec = vstup();
        
      printf("riadok:%c, stlpec:%c\n", riadok, stlpec);

      switch (riadok){
        case 'a': switch(stlpec){    

                    case '1': if (a1 != '_'){
                                chyba = 2;
                                goto hracO;} else a1 = 'O'; 
                      break;

                    case '2': if (a2 != '_'){
                                chyba = 2;
                                goto hracO;} else a2 = 'O'; 
                      break;

                    case '3': if (a3 != '_'){
                                chyba = 2;
                                goto hracO;} else a3 = 'O'; 
                      break;

                    default: chyba = 1;
                             goto hracO;
                      break;};
          break;


        case 'b': switch(stlpec){

                    case '1': if (b1 != '_'){
                                chyba = 2;
                                goto hracO;} else b1 = 'O'; 
                      break;

                    case '2': if (b2 != '_'){
                                chyba = 2;
                                goto hracO;} else b2 = 'O'; 
                      break;

                    case '3': if (b3 != '_'){
                                chyba = 2;
                                goto hracO;} else b3 = 'O'; 
                      break;

                    default: chyba = 1;
                             goto hracO;
                      break;};
          break;

        case 'c': switch(stlpec){

                    case '1': if (c1 != '_'){
                                chyba = 2;
                                goto hracO;} else c1 = 'O'; 
                      break;

                    case '2': if (c2 != '_'){
                                chyba = 2;
                                goto hracO;} else c2 = 'O'; 
                      break;

                    case '3': if (c3 != '_'){
                                chyba = 2;
                                goto hracO;} else c3 = 'O'; 
                      break;
    
                    default: chyba = 1;
                             goto hracO;
                      break;};
          break;

        default: chyba = 1;
                 goto hracO;
          break;}


      while (!((a1 == 'O' && a2 == 'O' && a3 == 'O') /*vsetky riadky su jedneho hraca*/
            || (b1 == 'O' && b2 == 'O' && b3 == 'O')
            || (c1 == 'O' && c2 == 'O' && c3 == 'O')

            || (a1 == 'O' && b1 == 'O' && c1 == 'O') /*vsetky stlpce su jedneho hraca*/
            || (a2 == 'O' && b2 == 'O' && c2 == 'O')
            || (a3 == 'O' && b3 == 'O' && c3 == 'O')

            || (a1 == 'O' && b2 == 'O' && c3 == 'O') /*do kriza*/
            || (c1 == 'O' && b2 == 'O' && a3 == 'O'))) { /*Zaèiatok 2. while*/

hracX:
        vypisHracejPlochy('X', chyba, a1, a2, a3, b1, b2, b3,c1, c2, c3);
        chyba = 0;

        /*skuska remizy*/
        if (a1 != '_' && a2 != '_' && a3 != '_' && b1 != '_' && b2 != '_' && b3 != '_' && c1 != '_' && c2 != '_' && c3 != '_'){
          printf("Remiza.\n Stlacte ENTER pre ukoncenie programu.");
          getchar();
		  return 0;
        }

        printf("Zadajte riadok(a/b/c):");
        pridajPrazdnyRiadok(16);
        riadok = vstup();
		

        vypisHracejPlochy('X', chyba, a1, a2, a3, b1, b2, b3,c1, c2, c3);
        printf("Zadajte riadok(a/b/c):%c\nZadajte stlpec(1/2/3):", riadok);
        pridajPrazdnyRiadok(15);
        stlpec = vstup();

        printf("riadok:%c, stlpec:%c\n", riadok, stlpec);

        switch (riadok){
          case 'a': switch(stlpec){

                      case '1': if (a1 != '_'){
                                chyba = 2;
                                goto hracX;} else a1 = 'X'; 
                        break;

                      case '2': if (a2 != '_'){
                                chyba = 2;
                                goto hracX;} else a2 = 'X'; 
                        break;

                      case '3': if (a3 != '_'){
                                chyba = 2;
                                goto hracX;} else a3 = 'X'; 
                        break;

                      default: chyba = 1;
                               goto hracX;
                        break;};
            break;


          case 'b': switch(stlpec){

                      case '1': if (b1 != '_'){
                                chyba = 2;
                                goto hracX;} else b1 = 'X'; 
                        break;

                      case '2': if (b2 != '_'){

                                chyba = 2;
                                goto hracX;} else b2 = 'X'; 
                        break;

                      case '3': if (b3 != '_'){
                                chyba = 2;
                                goto hracX;} else b3 = 'X'; 
                        break;

                      default: chyba = 1;
                               goto hracX;
                        break;};
            break;

          case 'c': switch(stlpec){

                      case '1': if (c1 != '_'){
                                chyba = 2;
                                goto hracX;} else c1 = 'X'; 
                        break;

                      case '2': if (c2 != '_'){
                                chyba = 2;
                                goto hracX;} else c2 = 'X'; 
                        break;

                      case '3': if (c3 != '_'){
                                chyba = 2;
                                goto hracX;} else c3 = 'X'; 
                        break;

                      default: chyba = 1;
                               goto hracX;
                        break;}
            break;

          default: chyba = 1;
                   goto hracX;
            break;}

        goto sem;      
        } /*Koniec 2. while*/

      vypisHracejPlochy('N', 0, a1, a2, a3, b1, b2, b3,c1, c2, c3);
      pridajPrazdnyRiadok(3);
      printf("===== Hrac O vyhral hru! =====\n", a1, a2, a3, b1, b2, b3, c1, c2, c3);
      goto koniec;
      }/*Koniec 1. while*/    
        
    vypisHracejPlochy('N', 0, a1, a2, a3, b1, b2, b3,c1, c2, c3);
    pridajPrazdnyRiadok(3);
    printf("===== Hrac O vyhral hru! =====\n", a1, a2, a3, b1, b2, b3, c1, c2, c3);
    goto koniec;
  }/*Koniec hry s èlovekom*/
    
  else {
    printf("Hra s pocitacom zatial nie je mozna\n");
    goto koniec;
  }/*Koniec hry s pocitacom*/
}/*Koniec "if (akcia = n)"*/

else if (akcia == 'p'|| akcia == 'P'){
  printf("Je mi luto, momentalne nemozete nacitat ulozenu hru.\n");
  goto koniec;
}

else if (akcia == 'u' || akcia == 'U'){
  return 0;
}

koniec:
printf("Stlacte ENTER pre ukoncenie programu.");
pridajPrazdnyRiadok(23);
getchar();
return 0;
}/*Koniec programu*/