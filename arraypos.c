// HOLY LOVENIA - 13515113


#include "arraypos.h"
#include <stdio.h>


/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create tabel kosong  */
void MakeEmpty (TabInt * T)
{
	// KAMUS
	IdxType i;
	
		// ALGORITMA
		for (i = IdxMin; i <= IdxMax; i++)
		{
			Elmt(*T, i) = ValUndef;
		}
}
/* I.S. T sembarang */
/* F.S. Terbentuk tabel T kosong dengan kapasitas IdxMax-IdxMin+1 */
/* Proses: Inisialisasi semua elemen tabel T dengan ValUndef */


/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */

int NbElmt (TabInt T)
{
	// KAMUS
	int count;
	IdxType i;
	
		// ALGORITMA
		count = 0;
		for (i = IdxMin; i <= IdxMax; i++)
		{
			if (Elmt(T, i) > ValUndef)
			{
				count = count + 1;
			}
		}
		return(count);
}
/* Mengirimkan banyaknya elemen efektif tabel */
/* Mengirimkan nol jika tabel kosong */
/* *** Daya tampung container *** */

int MaxNbEl (TabInt T)
{
	return(IdxMax - IdxMin + 1);
}
/* Mengirimkan maksimum elemen yang dapat ditampung oleh tabel */
/* *** Selektor INDEKS *** */

IdxType GetFirstIdx (TabInt T)
{
	return(IdxMin);
}
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T pertama */

IdxType GetLastIdx (TabInt T)
{
	return(IdxMin + NbElmt(T) - 1);
}
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T terakhir */


/* ********** Test Indeks yang valid ********** */

boolean IsIdxValid (TabInt T, IdxType i)
{
	return((i >= IdxMin) && (i <= IdxMax));
}
/* Mengirimkan true jika i adalah indeks yang valid utk ukuran tabel */
/* yaitu antara indeks yang terdefinisi utk container*/

boolean IsIdxEff (TabInt T, IdxType i)
{
	return((i >= GetFirstIdx(T)) && (i <= GetLastIdx(T)));
}
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk tabel */
/* yaitu antara FirstIdx(T)..LastIdx(T) */


/* ********** TEST KOSONG/PENUH ********** */
/* *** Test tabel kosong *** */

boolean IsEmpty (TabInt T)
{
	return(NbElmt(T) == 0);
}
/* Mengirimkan true jika tabel T kosong, mengirimkan false jika tidak */
/* *** Test tabel penuh *** */

boolean IsFull (TabInt T)
{
	return(GetLastIdx(T) == IdxMax);
}
/* Mengirimkan true jika tabel T penuh, mengirimkan false jika tidak */


/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi tabel dari pembacaan *** */

void BacaIsi (TabInt * T)
{
	// KAMUS
	int i, N;
	
		// ALGORITMA
		scanf("%d", &N);
		while(!((N >= 0) && (N <= MaxNbEl(*T))))
		{
			scanf("%d", &N);
		}
		
		if(N == 0)
		{
			MakeEmpty(T);
		}
		else if((N > 0) && (N <= MaxNbEl(*T)))
		{
			MakeEmpty(T);
			for(i = GetFirstIdx(*T); i <= N; i++)
			{
				scanf("%d", &Elmt(*T, i));			
			}
		}
}
/* I.S. T sembarang */
/* F.S. Tabel T terdefinisi */
/* Proses : membaca banyaknya elemen T dan mengisi nilainya */
/* 1. Baca banyaknya elemen diakhiri enter, misalnya N */
/*    Pembacaan diulangi sampai didapat N yang benar yaitu 0 <= N <= MaxNbEl(T) */
/*    Jika N tidak valid, tidak diberikan pesan kesalahan */
/* 2. Jika 0 < N <= MaxNbEl(T){} Lakukan N kali: Baca elemen mulai dari indeks 
      IdxMin satu per satu diakhiri enter */
/*    Jika N = 0{} hanya terbentuk T kosong */

void TulisIsiTab (TabInt T)
{
// KAMUS
	int i;
	
		// ALGORITMA
		if(IsEmpty(T))
		{
			printf("[]");
		}
		else
		{	
			printf("[");
			for(i = GetFirstIdx(T); i <= GetLastIdx(T); i++)
			{
				if (i < GetLastIdx(T))
				{
					printf("%d,", Elmt(T, i));
				}
				else if (i = GetLastIdx(T))
				{
					printf("%d", Elmt(T, i));
				}
			}
			printf("]");
		}
}
/* Proses : Menuliskan isi tabel dengan traversal, tabel ditulis di antara kurung siku{} 
   antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan karakter di depan,
   di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. T boleh kosong */
/* F.S. Jika T tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika tabel kosong : menulis [] */


/* ********** OPERATOR ARITMATIKA ********** */
/* *** Aritmatika tabel : Penjumlahan, pengurangan, perkalian, ... *** */

TabInt PlusMinusTab (TabInt T1, TabInt T2, boolean plus)
{
	// KAMUS
	TabInt T3;
	int i;
	
		// ALGORITMA
		MakeEmpty(&T3);
		if (plus == true)
		{
			for(i = GetFirstIdx(T1); i <= GetLastIdx(T1); i++)
			{
				Elmt(T3, i) = Elmt(T1, i) + Elmt(T2, i);
			}
			return(T3);
		}
		else
		{
			for(i = GetFirstIdx(T1); i <= GetLastIdx(T1); i++)
			{
				Elmt(T3, i) = Elmt(T1, i) - Elmt(T2, i);
			}
		}
		return(T3);
}
/* Prekondisi : T1 dan T2 berukuran sama dan tidak kosong */
/* Jika plus = true, mengirimkan  T1+T2, yaitu setiap elemen T1 dan T2 pada indeks yang sama dijumlahkan */
/* Jika plus = false, mengirimkan T1-T2, yaitu setiap elemen T1 dikurangi elemen T2 pada indeks yang sama */


/* ********** OPERATOR RELASIONAL ********** */
/* *** Operasi pembandingan tabel : < =, > *** */

boolean IsEQ (TabInt T1, TabInt T2)
{
	// KAMUS	
	int i = GetFirstIdx(T1);
	
		// ALGORITMA
		if(NbElmt(T1) == NbElmt(T2))
		{
			while((i <= GetLastIdx(T1)) && ((Elmt(T1, i) == Elmt(T2, i))))
			{
				i = i + 1;
			}
			return((Elmt(T1, i) == Elmt(T2, i)));
		}
		else
		{
			return(false);
		}
}
/* Mengirimkan true jika T1 sama dengan T2 yaitu jika ukuran T1 = T2 dan semua elemennya sama */


/* ********** SEARCHING ********** */
/* ***  Perhatian : Tabel boleh kosong!! *** */

IdxType Search1 (TabInt T, ElType X)
{
	// KAMUS
	int i;
	
		// ALGORITMA
		if(IsEmpty(T))
		{
			return(IdxUndef);
		}
		else
		{
			i = GetFirstIdx(T);
			while((X != Elmt(T, i)) && (i < GetLastIdx(T)))
			{
				i = i + 1;
			}
			if(Elmt(T, i) == X)
			{
				return(i);
			}
			else
			{
				return(IdxUndef);
			}
		}
}
/* Search apakah ada elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = X */
/* Jika tidak ada, mengirimkan IdxUndef */
/* Menghasilkan indeks tak terdefinisi (IdxUndef) jika tabel T kosong */
/* Skema Searching yang digunakan bebas */

boolean SearchB (TabInt T, ElType X)
{
	// KAMUS
	int i;
	boolean found;
	
		// ALGORITMA
		if(IsEmpty(T))
		{
			return(false);
		}
		else
		{
			found = false;
			i = GetFirstIdx(T);
			while((found == false) && (i <= GetLastIdx(T)))
			{
				if(Elmt(T, i) == X)
				{
					found = true;
				}
				i = i + 1;
			}
			if (found == true)
			{
				return(true);
			}
			else
			{
				return(false);
			}
		}
}
/* Search apakah ada elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan true, jika tidak ada menghasilkan false */
/* Skema searching yang digunakan bebas */


/* ********** NILAI EKSTREM ********** */

void MaxMin (TabInt T, ElType * Max, ElType * Min)
{
	// KAMUS
	IdxType i;
	
		// ALGORITMA
		*Max = 0;
		*Min = Elmt(T,GetFirstIdx(T));
		for (i = GetFirstIdx(T); i <= GetLastIdx(T); i++)
		{
			if (Elmt(T, i) > *Max)
			{
				*Max = Elmt(T, i);
			}
			else if (Elmt(T, i) < *Min)
			{
				*Min = Elmt(T, i);
			}
		}
}
/* I.S. Tabel T tidak kosong */
/* F.S. Max berisi nilai maksimum T{}
        Min berisi nilai minimum T */


/* ********** OPERASI LAIN ********** */

ElType SumTab (TabInt T)
{
	// KAMUS
	int sum;
	IdxType i;
	
		// ALGORITMA
		sum = 0;
		if (!(IsEmpty(T)))
		{
			for (i = GetFirstIdx(T); i <= GetLastIdx(T); i++)
			{
				sum += Elmt(T, i);
			}
		}
		return(sum);
}
/* Menghasilkan hasil penjumlahan semua elemen T */
/* Jika T kosong menghasilkan 0 */

int CountX (TabInt T, ElType X)
{
	// KAMUS
	int count;
	IdxType i;
	
		// ALGORITMA
		count = 0;
		if (!(IsEmpty(T)))
		{
			for (i = GetFirstIdx(T); i <= GetLastIdx(T); i++)
			{
				if (Elmt(T, i) == X)
				{
					count++;
				}
			}
		}	
		return(count);	
}
/* Menghasilkan berapa banyak kemunculan X di T */
/* Jika T kosong menghasilkan 0 */

boolean IsAllGenap (TabInt T)
{
	// KAMUS
	IdxType i;
	
		// ALGORITMA
		if (!(IsEmpty(T)))
		{
			i = GetFirstIdx(T);
			while ((i < GetLastIdx(T)) && (Elmt(T, i) % 2 == 0))
			{
				i++;
			}
			return(Elmt(T, i) % 2 == 0);
		}
}
/* Menghailkan true jika semua elemen T genap */


/* ********** SORTING ********** */

void Sort (TabInt * T, boolean asc)
{
	// KAMUS
	int temp, i, j;
		// ALGORITMA
		if (!(IsEmpty(*T)))
		{
			if (asc == false) // mengecil
			{
				for(i = GetFirstIdx(*T); i <= GetLastIdx(*T); i++)
				{
					for(j = GetFirstIdx(*T); j <= GetLastIdx(*T); j++)
					{
						if(Elmt(*T, i) > Elmt(*T, j))
						{
							temp = Elmt(*T, i);
							Elmt(*T, i) = Elmt(*T, j);
							Elmt(*T, j) = temp;
						}					
					}
				}
			}
			else // asc == true (membesar)
			{
				for(i = GetFirstIdx(*T); i <= GetLastIdx(*T); i++)
				{
					for(j = GetFirstIdx(*T); j <= GetLastIdx(*T); j++)
					{
						if(Elmt(*T, i) < Elmt(*T, j))
						{
							temp = Elmt(*T, i);
							Elmt(*T, i) = Elmt(*T, j);
							Elmt(*T, j) = temp;
						}					
					}
				}
			}
		}
}
/* I.S. T boleh kosong */
/* F.S. Jika asc = true, T terurut membesar */
/*      Jika asc = false, T terurut mengecil */
/* Proses : Mengurutkan T dengan salah satu algoritma sorting,
   algoritma bebas */


/* ********** MENAMBAH DAN MENGHAPUS ELEMEN DI AKHIR ********** */
/* *** Menambahkan elemen terakhir *** */

void AddAsLastEl (TabInt * T, ElType X)
{
	//KAMUS
	int i;
	
		// ALGORITMA
		i = NbElmt(*T) + 1;
		Elmt(*T, i) = X;
}
/* Proses: Menambahkan X sebagai elemen terakhir tabel */
/* I.S. Tabel T boleh kosong, tetapi tidak penuh */
/* F.S. X adalah elemen terakhir T yang baru */
/* ********** MENGHAPUS ELEMEN ********** */

void DelLastEl (TabInt * T, ElType * X)
{
	// KAMUS
	int i;
	
		// ALGORITMA
		i = NbElmt(*T);
		*X = Elmt(*T, i);
		Elmt(*T, i) = ValUndef;
}
/* Proses : Menghapus elemen terakhir tabel */
/* I.S. Tabel tidak kosong */
/* F.S. X adalah nilai elemen terakhir T sebelum penghapusan, */
/*      Banyaknya elemen tabel berkurang satu */
/*      Tabel T mungkin menjadi kosong */
