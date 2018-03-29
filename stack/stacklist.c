// HOLY LOVENIA - 13515113


/* File : stacklist.c */


#include "stacklist.h"
#include <stdlib.h>


/* Prototype manajemen memori */
void Alokasi (address *P, infotype X)
{
	// KAMUS
	
	
		// ALGORITMA
		*P = (address) malloc (sizeof (ElmtStack));
		if (*P != Nil)
		{
			Info(*P) = X;
			Next(*P) = Nil;
		}
		else
		{
			*P = Nil;
		}
}
/* I.S. Sembarang */
/* F.S. Alamat P dialokasi, jika berhasil maka Info(P)=X dan 
        Next(P)=Nil */
/*      P=Nil jika alokasi gagal */

void Dealokasi (address P)
{
	free(P);
}
/* I.S. P adalah hasil alokasi, P != Nil */
/* F.S. Alamat P didealokasi, dikembalikan ke sistem */ 


/* ********* PROTOTYPE REPRESENTASI LOJIK STACK ***************/

boolean IsEmpty (Stack S)
{
	return (Top(S) == Nil);
}
/* Mengirim true jika Stack kosong: TOP(S) = Nil */

void CreateEmpty (Stack * S)
{
	Top(*S) = Nil;
}
/* I.S. sembarang */ 
/* F.S. Membuat sebuah stack S yang kosong */

void Push (Stack * S, infotype X)
{
	// KAMUS
	address P;
	
		// ALGORITMA
		Alokasi(&P, X);
		Next(P) = Top(*S);
		Top(*S) = P;
}
/* Menambahkan X sebagai elemen Stack S */
/* I.S. S mungkin kosong, X terdefinisi */
/* F.S. X menjadi TOP yang baru jika alokasi X berhasil, */
/*      jika tidak, S tetap */
/* Pada dasarnya adalah operasi Insert First pada list linier */

void Pop (Stack * S, infotype * X)
{
	// KAMUS
	address P;
		
		// ALGORITMA
		*X = InfoTop(*S);
		P = Top(*S);
		if (Next(P) != Nil)
		{
			Top(*S) = Next(P);	
		}
		else
		{
			CreateEmpty(S);
		}
		Next(P) = Nil;
		Dealokasi(P);
}
/* Menghapus X dari Stack S. */
/* I.S. S tidak mungkin kosong */
/* F.S. X adalah nilai elemen TOP yang lama, */
/*      elemen TOP yang lama didealokasi */
/* Pada dasarnya adalah operasi Delete First pada list linier */