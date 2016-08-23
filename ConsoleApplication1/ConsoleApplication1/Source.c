#include <stdio.h>
#include "Nutility.h"

#define		TIMES			10000
#define		HEADS_TAILS		(rand() % 2)

// Ali Mesut ÝNCE
// Oyun Ödevi
// Özellikleri
/*
Sizin de Neco'nun da oyuna baþlarken 100 TL'niz var.
Siz oyuna girmek için Neco'ya 10 TL ödüyorsunuz. Neco parayý alýnca yazý tura atýyor:
Eðer arka arkaya 3 kez yazý gelirse Neco size 65 TL ödüyor.
Eðer arka arkaya 2 kez tura gelirse Neco size 30 TL ödüyor.
Oyunun herhangi bir anýnda oyuna girecek 10 TL niz yoksa (9 TL'niz olsa bile) oyunu kaybediyorsunuz.
Oyunun herhangi bir anýnda arka arkaya 2 tura gelmesine karþýn Neco'nun size verecek 30TL'si yoksa
Neco oyunu kaybediyor.
Oyunun herhangi bir anýnda arka arkaya 3 yazý gelmesine karþýn Neco'nun size verecek 65 TL'si yoksa
Neco oyunu kaybediyor.
*/

int game(void) //return 1 if gamer win the game, return 0 if gamer lose the game
{	
	int cash  = 100;
	int gamer = 100;
	int first_coin;
	int second_coin;
	int third_coin;
	int flag = 0;

	while (1) {
		if (gamer < 10)
			return 0;
		gamer -= 10;
		cash += 10;
		first_coin = HEADS_TAILS; // result 1 is tail, result 0 is head
		
		if (gamer < 10)
			return 0;
		gamer -= 10;
		cash += 10;
		second_coin = HEADS_TAILS;

		while (first_coin != second_coin) {
			if (flag % 2 == 0){
				if (gamer < 10)
					return 0;
				gamer -= 10;
				cash += 10;
				first_coin = HEADS_TAILS;
				flag++;
			}
			else if (flag % 2 == 1){
				if (gamer <   10)
					return 0;
				gamer -= 10;
				cash += 10;
				second_coin = HEADS_TAILS;
				flag++;
			}
		}

		if (first_coin == 0) {
			if (cash < 35)
				return 1;
			gamer += 35;
			cash -= 35;
			continue;
		}

		if (gamer <   10)
			return 0;
		gamer -= 10;
		cash += 10;
		third_coin = HEADS_TAILS;

		if (second_coin == third_coin && second_coin == 1) {
			if (cash < 65)
				return 1;
			gamer += 65;
			cash -= 65;
			continue;
		}


	
	}
		


}





int main()
{
	int cnt = 0;

	for (int k = 0; k < TIMES; k++)
		cnt += game();

	printf("Kazanma ihtimali : %f\n", (double)cnt / TIMES);


	return 0;
}