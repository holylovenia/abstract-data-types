// HOLY LOVENIA - 13515113


/* File : queue.c */
/* Definisi ADT Queue dengan representasi array secara eksplisit dan alokasi dinamik */
/* Model Implementasi Versi III dengan circular buffer */

#include "queue.h"
#include <stdlib.h>


/* ********* Prototype ********* */

boolean IsEmpty (Queue Q)
{
	return ((Head(Q) == Nil) && (Tail(Q) == Nil));
}
/* Mengirim true jika Q kosong: lihat definisi di atas */

boolean IsFull (Queue Q)
{
	if (Head(Q) < Tail(Q))
	{
		return ((Head(Q) == 1) && (Tail(Q) == MaxEl(Q)));
	}
	else // Tail(Q) <= Head(Q)
	{
		return (Head(Q) == Tail(Q) + 1);
	}
}
/* Mengirim true jika tabel penampung elemen Q sudah penuh */
/* yaitu mengandung elemen sebanyak MaxEl */

int NBElmt (Queue Q)
{
	// KAMUS
	
	
			// ALGORITMA
			if ((Head(Q) == Nil) && (Tail(Q) == Nil))
			{
				return (0);
			}
			else if (Head(Q) <= Tail (Q))
			{
				return (Tail(Q) - Head(Q) + 1);
			}
			else if (Head(Q) > Tail(Q))
			{
				return (MaxEl(Q) - (Head(Q) - Tail(Q)) + 1);
			}
}
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong */


/* *** Kreator *** */

void CreateEmpty (Queue * Q, int Max)
{
	// KAMUS
			
			
			// ALGORITMA
			
			(*Q).T = (infotype *) malloc ((Max + 1) * sizeof (infotype));
			
			if ((*Q).T != NULL)
			{
				MaxEl(*Q) = Max;
				Head(*Q) = Nil;
				Tail (*Q) = Nil;
			}
			else	// alokasi gagal
			{
				MaxEl(*Q) = Nil;
			}
}
/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk dan salah satu kondisi sbb: */
/* Jika alokasi berhasil, Tabel memori dialokasi berukuran Max+1 */
/* atau : jika alokasi gagal, Q kosong dg MaxEl=0 */
/* Proses : Melakukan alokasi,Membuat sebuah Q kosong */


/* *** Destruktor *** */

void DeAlokasi(Queue * Q)
{
	// KAMUS
			
			
			// ALGORITMA
			MaxEl(*Q) = Nil;
			free((*Q).T);
}
/* Proses: Mengembalikan memori Q */
/* I.S. Q pernah dialokasi */
/* F.S. Q menjadi tidak terdefinisi lagi, MaxEl(Q) diset 0 */


/* *** Primitif Add/Delete *** */

void Add (Queue * Q, infotype X)
{
	// KAMUS
	
	
		// ALGORITMA
		if (IsEmpty(*Q))
		{
			Head(*Q) = 1;
			Tail(*Q) = 1;
		}
		else
		{
			Tail(*Q) = (Tail(*Q) % MaxEl(*Q) + 1);
		}
		InfoTail(*Q) = X;
}
/* Proses: Menambahkan X pada Q dengan aturan FIFO */
/* I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh */
/* F.S. X menjadi TAIL yang baru, TAIL "maju" */
/* F.S. X menjadi TAIL yang baru, TAIL "maju" dengan mekanisme circular buffer */

void Del(Queue * Q, infotype * X)
{
	// KAMUS
	
		
		// ALGORITMA
		*X = InfoHead(*Q);
		if (Head(*Q) == Tail(*Q))
		{
			Head(*Q) = Nil;
			Tail(*Q) = Nil;
		}
		else
		{
			Head(*Q) = ((Head(*Q) % MaxEl(*Q)) + 1);
		}
		
}
/* Proses: Menghapus X pada Q dengan aturan FIFO */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = nilai elemen HEAD pd I.S., HEAD "maju" dengan mekanisme circular buffer; Q mungkin kosong */