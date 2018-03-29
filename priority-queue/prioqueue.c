// HOLY LOVENIA - 13515113


#include "prioqueue.h"


/* Prototype manajemen memori */

void Alokasi (address *P, infotype X)
{
	// KAMUS
	
	
		// ALGORITMA
		*P = (address) malloc (sizeof (ElmtQueue));
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
/* F.S. Alamat P dialokasi, jika berhasil maka Info(P)=X dan Next(P)=Nil */
/*      P=Nil jika alokasi gagal */

void Dealokasi (address  P)
{
	free(P);
}
/* I.S. P adalah hasil alokasi, P != Nil */
/* F.S. Alamat P didealokasi, dikembalikan ke sistem */

boolean IsEmpty (PrioQueue Q)
{
	return (Head(Q) == Nil);
}
/* Mengirim true jika Q kosong: HEAD(Q)=Nil */

int NbElmt(PrioQueue Q)
{
	// KAMUS
	address P;
	int count;
	
		// ALGORITMA
		if (IsEmpty(Q))
		{
			return (0);
		}
		else
		{
			P = Head(Q);
			count = 1;
			while (Next(P) != Nil)
			{
				count++;
				P = Next(P);
			}
			return (count);
		}	
}
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong */


/*** Kreator ***/

void CreateEmpty(PrioQueue * Q)
{
	Head(*Q) = Nil;
}
/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk */


/*** Primitif Add/Delete ***/

void Add (PrioQueue * Q, infotype X)
{
	// KAMUS
	address P, PrecPrec, Prec, Last;
	
		// ALGORITMA
		Alokasi(&P, X);
		if (IsEmpty(*Q))
		{
			Head(*Q) = P;
		}
		else
		{
			Prec = Head(Q);
			Last = Next(Head(*Q));
			while ((Info(Last).tKedatangan < X.tKedatangan) && (Last != Nil))
			{
				Prec = Last;
				Last = Next(Last);
			}
			Next(P) = Next(Prec);
			Next(Prec) = P;
			
			PrecPrec = Nil;
			Prec = Nil;
			Last = Next(Head(*Q));
			while ((Info(Last).nMat > X.nMat) && (Last != Nil))
			{
				PrecPrec = Prec;
				Prec = Last;
				Last = Next(Last);
			}
			Next(Prec) = Next(Last);
			Next(PrecPrec) = Last;
			Next(Last) = Prec;
		}	
}
/* Proses: Mengalokasi X dan menambahkan X sesuai aturan priority queue
   jika alokasi berhasil; jika alokasi gagal Q tetap */
/* I.S. Q mungkin kosong */

void Del(PrioQueue * Q, infotype * X)
{
	// KAMUS
	address P;
	
		// ALGORITMA
		*X = InfoHead(*Q);
		P = Head(*Q);
		if (NbElmt(*Q) == 1)
		{
			CreateEmpty(Q);
		}
		else
		{
			P = Head(*Q);
			Head(*Q) = Next(P);
			Next(P) = Nil;
		}
		Dealokasi(P);
}
/* Proses: Menghapus X pada bagian HEAD dari Q dan mendealokasi elemen HEAD */
/* Pada dasarnya operasi delete first */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = nilai elemen HEAD pd I.S., HEAD "mundur" */
