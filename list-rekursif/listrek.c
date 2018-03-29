// HOLY LOVENIA - 13515113


/* File: listrek.c */
/* ADT list linier dengan representasi pointer */
/* Implementasi list linier secara rekursif */


#include <stdlib.h>
#include "listrek.h"
#include <stdio.h>



/* *** Manajemen Memori *** */


address Alokasi (infotype X)
{
	// KAMUS
	address P;
	
		// ALGORITMA
		P = (address) malloc (sizeof (ElmtList));
		if (P != Nil)
		{
			Info(P) = X;
			Next(P) = Nil;
			return (P);
		}
		else
		{
			return (Nil);
		}
}
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak Nil, dan misalnya menghasilkan P, 
  maka Info(P) = X, Next(P) = Nil */
/* Jika alokasi gagal, mengirimkan Nil */

void Dealokasi (address P)
{
	free(P);
}
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */



/* *** Primitif-primitif yang harus direalisasikan *** */


/* Pemeriksaan Kondisi List */

int IsEmpty(List L)
{
	if (L == Nil)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
/* Mengirimkan 1 jika L kosong dan 0 jika L tidak kosong */

int IsOneElmt(List L)
{
	if ((L != Nil) && (Next(L) == Nil))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
/* Mengirimkan 1 jika L berisi 1 elemen dan 0 jika > 1 elemen atau kosong */


/* *** Selektor *** */

infotype FirstElmt (List L)
{
	return (Info(L));
}
/* Mengirimkan elemen pertama sebuah list L yang tidak kosong */

List Tail(List L)
{
	// KAMUS
	List Ekor;
	
		// ALGORITMA
		if (IsOneElmt(L))
		{
			Ekor = Nil;
		}
		else
		{
			Ekor = Next(L);
		}
		return (Ekor);
}
/* Mengirimkan list L tanpa elemen pertamanya, mungkin menjadi list kosong */


/* *** Konstruktor *** */

List Konso(infotype e, List L)
{
	// KAMUS
	address P;
	List Hasil;
	
		// ALGORITMA
		P = Alokasi(e);
		if (P != Nil)
		{
			Next(P) = L;
			Hasil = P;
		}
		else
		{
			Hasil = L;
		}
		return (Hasil);
}
/* Mengirimkan list L dengan tambahan e sebagai elemen pertamanya. 
e dialokasi terlebih dahulu. Jika alokasi gagal, mengirimkan L. */

List KonsB(List L, infotype e)
{
		// KAMUS
	address P;
	
		// ALGORITMA
		if (IsEmpty(L) == 1)
		{
			P = Alokasi(e);
			if (P != Nil)
			{
				return (P);
			}
			else
			{
				return (Nil);
			}
		}
		else
		{
			Next(L) = (KonsB(Tail(L), e));
			return (L);
		}
}
/* Mengirimkan list L dengan tambahan e sebagai elemen pertamanya */
/* e harus dialokasi terlebih dahulu */
/* Jika alokasi e gagal, mengirimkan L */ 


/* *** Operasi Lain *** */

List Copy (List L)
{
	// KAMUS
	
	
		// ALGORITMA
		if (IsEmpty(L) == 1)
		{
			return (Nil);
		}
		else
		{
			return (Konso (FirstElmt(L), Copy(Tail(L))));
		}
}
/* Mengirimkan salinan list L (menjadi list baru) */
/* Jika ada alokasi gagal, mengirimkan L */ 

void MCopy (List Lin, List *Lout)
{
	*Lout = Copy(Lin);
}
/* I.S. Lin terdefinisi */
/* F.S. Lout berisi salinan dari Lin */
/* Proses : menyalin Lin ke Lout */

List Concat (List L1, List L2)
{
	// KAMUS
	
	
		// ALGORITMA
		if (IsEmpty(L1) == 1)
		{
			return (L2);
		}
		else if (IsEmpty(L2) == 1)
		{
			return (L1);
		}
		else
		{
			return (Konso(FirstElmt(L1), Concat(Tail(L1), L2))); 
		}
}
/* Mengirimkan salinan hasil konkatenasi list L1 dan L2 (menjadi list baru) */
/* Jika ada alokasi gagal, menghasilkan Nil */

void MConcat (List L1, List L2, List *LHsl)
{
	*LHsl = Concat(L1, L2);
}
/* I.S. L1, L2 terdefinisi */
/* F.S. LHsl adalah hasil melakukan konkatenasi L1 dan L2 dengan cara "disalin" */
/* Proses : Menghasilkan salinan hasil konkatenasi list L1 dan L2 */

void PrintList (List L)
{
	// KAMUS
	
	
		// ALGORITMA
		if (IsEmpty(L) == 1)
		{
		}
		else
		{
			printf("%d\n", FirstElmt(L));
			PrintList(Tail(L));
		}
		
}
/* I.S. L terdefinisi. */
/* F.S. Setiap elemen list dicetak. */

int NbElmtList (List L)
{
	// KAMUS
	int count;
	
		// ALGORITMA
		count = 0;
		if (IsEmpty(L) == 1)
		{
		}
		else
		{
			count = 1 + NbElmtList(Tail(L));
		}
		return (count);
		
}
/* Mengirimkan banyaknya elemen list L, Nol jika L kosong */

boolean Search (List L, infotype X)
{
	// KAMUS
	
	
		// ALGORITMA
		if (IsEmpty(L) == 1)
		{
			return (false);
		}
		else
		{
			if (FirstElmt(L) == X)
			{
				return (true);
			}
			else
			{
				return (Search(Tail(L), X));
			}
		}
}
/* Mengirim true jika X adalah anggota list, false jika tidak */


/*** Pencarian nilai ekstrim ***/
/* Prekondisi untuk Max/Min/Sum/Average : List tidak kosong */

infotype MaxList (List L)
{
	// KAMUS
	infotype MaxNow, MaxNext;
	
		// ALGORITMA
		MaxNow = FirstElmt(L);
		if (IsOneElmt(L) == 1)
		{
			return (MaxNow);
		}
		else
		{
			MaxNext = MaxList(Tail(L));
		}
		
		if (MaxNow > MaxNext)
		{
			return (MaxNow);
		}
		else
		{
			return (MaxNext);
		}
}
/* Mengirimkan nilai info(P) yang maksimum */

infotype MinList (List L)
{
	// KAMUS
	infotype MinNow, MinNext;
	
		// ALGORITMA
		MinNow = FirstElmt(L);
		if (IsOneElmt(L) == 1)
		{
			return (MinNow);
		}
		else
		{
			MinNext = MinList(Tail(L));
		}
		
		if (MinNow < MinNext)
		{
			return (MinNow);
		}
		else
		{
			return (MinNext);
		}	
}
/* Mengirimkan nilai info(P) yang minimum */

infotype SumList (List L)
{
	// KAMUS
	int sum;
	
		// ALGORITMA
		sum = 0;
		if (IsEmpty(L) == 1)
		{
		}
		else
		{
			sum = FirstElmt(L) + SumList(Tail(L));
		}
		return (sum);
	
}
/* Mengirimkan total jumlah elemen List L */

float AverageList (List L)
{
	// KAMUS
	
	
		// ALGORITMA
		return ((float) SumList(L) / (float) NbElmtList(L));
}
/* Mengirimkan nilai rata-rata elemen list L */


/*** Operasi-Operasi Lain ***/

List InverseList (List L)
{
	// KAMUS
	
	
		// ALGORITMA
		if (IsEmpty(L) == 1)
		{
			return (Nil);
		}
		else
		{
			return (KonsB (InverseList(Tail(L)), FirstElmt(L)));
		}
}
/* Mengirimkan list baru, hasil invers dari L dengan menyalin semua elemen list.
Semua elemen list baru harus dialokasi */
/* Jika alokasi gagal, hasilnya list kosong */

void SplitPosNeg (List L, List *L1, List *L2)
{
	// KAMUS
	List Ldummy;
	
		// ALGORITMA
		Ldummy = Copy(L);
		*L1 = Nil;
		*L2 = Nil;		
		if (IsEmpty(Ldummy) == 1)
		{
		}
		else
		{
			SplitPosNeg(Tail(Ldummy), L1, L2);
			if (FirstElmt(Ldummy) >= 0)
			{
				*L1 = Konso(FirstElmt(Ldummy), *L1);
			}
			else
			{
				*L2 = Konso(FirstElmt(Ldummy), *L2);
			}
		}
}
/* I.S. L mungkin kosong */
/* F.S. Berdasarkan L, dibentuk dua buah list L1 dan L2 */ 
/* L1 berisi semua elemen L yang positif atau 0, sedangkan L2 berisi
semua elemen L yang negatif; semua dengan urutan yang sama seperti di L */
/* L tidak berubah: Semua elemen L1 dan L2 harus dialokasi */
/* Jika L kosong, maka L1 dan L2 kosong */

void SplitOnX (List L, infotype X, List *L1, List *L2)
{
	// KAMUS
	
	
		// ALGORITMA
		*L1 = Nil;
		*L2 = Nil;		
		if (IsEmpty(L) == 1)
		{
		}
		else
		{
			SplitOnX(Tail(L), X, L1, L2);
			if (FirstElmt(L) < X)
			{
				*L1 = Konso(FirstElmt(L), *L1);
			}
			else
			{
				*L2 = Konso(FirstElmt(L), *L2);
			}
		}
}
/* I.S. L dan X terdefinisi, L1 dan L2 sembarang. */
/* F.S. L1 berisi semua elemen L yang lebih kecil dari X, dengan urutan
kemunculan yang sama, L2 berisi semua elemen L yang tidak masuk ke
L1, dengan urutan kemunculan yang sama. */

int ListCompare (List L1, List L2)
{
	// KAMUS
	
	
		// ALGORITMA
		if (NbElmtList(L1) == NbElmtList(L2))
		{
			if ((IsEmpty(L1) == 1) && (IsEmpty(L2) == 1))
			{
				return 0;
			}
			else
			{
				if (FirstElmt(L1) == FirstElmt(L2))
				{
					return (ListCompare(Tail(L1), Tail(L2)));
				}
				else if (FirstElmt(L1) > FirstElmt(L2))
				{
					return 1;
				}
				else // (FirstElmt(L1) < FirstElmt(L2))
				{
					return -1;
				}
			}
		}
		else if (NbElmtList(L1) < NbElmtList(L2))
		{
			return -1;
		}
		else // (NbElmtList(L1) > NbElmtList(L2))
		{
			return 1;
		}
}
/* Menghasilkan: -1 jika L1 < L2, 0 jika L1 = L2, dan 1 jika L1 > L2 */
/* Jika L[i] adalah elemen L pada urutan ke-i dan |L| adalah panjang L: */
/* L1 = L2: |L1| = |L2| dan untuk semua i, L1[i] = L2[i] */
/* L1 < L2: Jika i adalah urutan elemen yang berbeda yang terkecil
dari L1 dan L2, L1[i]<L2[i] atau: Jika pada semua elemen pada
urutan i yang sama, L1[i]=L2[i], namun |L1|<|L2| */
/* Contoh: [3,5,6,7] < [4,4,5,6]; [1,2,3]<[1,2,3,4] */
/* L1>L2: kebalikan dari L1<L2 */

boolean IsAllExist (List L1, List L2)
{
	// KAMUS
	
	
		// ALGORITMA
		if ((IsEmpty(L1) == 1) || (IsEmpty(L2) == 1))
		{
			return (false);
		}
		else
		{
			if ((IsOneElmt(L1) == 1) && Search(L2, FirstElmt(L1)))
			{
				return (true);
			}
			else if ((IsOneElmt(L1) == 0) && (Search(L2, FirstElmt(L1))))
			{
				return (IsAllExist(Tail(L1), L2));
			}
			else
			{
				return (false);
			}
		}
}
/* Menghasilkan true jika semua elemen dalam L1 terdapat dalam L2 (tanpa
memperhatikan urutan ataupun banyaknya elemen).
Kedua list mungkin kosong. Jika L1 kosong, maka hasilnya false. */
