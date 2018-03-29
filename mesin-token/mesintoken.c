// HOLY LOVENIA - 13515113


/* File: mesintoken.h */
/* Definisi Mesin Token: Model Akuisisi Versi I */


#include "mesintoken.h"


/* State Mesin Kata */
boolean EndToken;
Token CToken;


void IgnoreBlank()
{
	while ((CC == BLANK) && (CC != MARK))
	{
		ADV();
	}
}
/* Mengabaikan satu atau beberapa BLANK
   I.S. : CC sembarang 
   F.S. : CC ≠ BLANK atau CC = MARK */


void STARTTOKEN()
{
	START();
	IgnoreBlank();
	if (CC == MARK)
	{
		EndToken = true;
	}
	else
	{
		EndToken = false;
		SalinToken();
	}
}
/* I.S. : CC sembarang 
   F.S. : EndToken = true, dan CC = MARK; 
          atau EndToken = false, CToken adalah Token yang sudah diakuisisi,
          CC karakter pertama sesudah karakter terakhir Token */


void ADVTOKEN()
{
	IgnoreBlank();
	if (CC == MARK)
	{
		EndToken = true;
	}
	else
	{
		SalinToken();
		IgnoreBlank();
	}
}
/* I.S. : CC adalah karakter pertama kata yang akan diakuisisi 
   F.S. : CToken adalah Token terakhir yang sudah diakuisisi, 
          CC adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika CC = MARK, maka EndToken = true      
   Proses : Akuisisi kata menggunakan procedure SalinKata */


void SalinToken()
{
	// KAMUS
	int i, j, number;
	
		// ALGORITMA
		i = 1;
		while ((i < NMax) && (CC != BLANK) && (CC != MARK))
		{
			if ((CC == '+') || (CC == '-') || (CC == '*') || (CC == '/') || (CC == '^'))
			{
				CToken.tkn = CC;
				CToken.val = -1;
				ADV();
			}
			else // bilangan bulat
			{
				CToken.tkn = 'b';
				j = 1;
				number = 0;
				while ((j <= NMax) && (CC != BLANK) && (CC != MARK))
				{
					number = (number * 10) + (CC - '0');
					j++;
					ADV();
				}
				CToken.val = number;
			}
			i++;
		}
}
/* Mengakuisisi Token dan menyimpan hasilnya dalam CToken
   I.S. : CC adalah karakter pertama dari Token
   F.S. : CToken berisi Token yang sudah diakuisisi{} 
          CC = BLANK atau CC = MARK{} 
          CC adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */
