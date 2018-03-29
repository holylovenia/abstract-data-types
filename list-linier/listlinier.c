// HOLY LOVENIA - 13515113


/* File : listlinier.c */
/* contoh ADT list berkait dengan representasi fisik pointer  */
/* Representasi address dengan pointer */
/* infotype adalah integer */


#include "listlinier.h"
#include <stdlib.h>
#include <stdio.h>


/* PROTOTYPE */

/****************** TEST LIST KOSONG ******************/

boolean IsEmpty (List L)
{
	return (First(L) == Nil);
}
/* Mengirim true jika list kosong */


/****************** PEMBUATAN LIST KOSONG ******************/

void CreateEmpty (List *L)
{
	First(*L) = Nil;
}
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */


/****************** Manajemen Memori ******************/

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
/* Jika alokasi berhasil, maka address tidak nil, dan misalnya */
/* menghasilkan P, maka Info(P)=X, Next(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */

void Dealokasi (address *P)
{
	free(*P);
}
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */


/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/

address Search (List L, infotype X)
{
	// KAMUS
	address P;
	
		// ALGORITMA
		P = First(L);
		while ((P != Nil) && (Info(P) != X))
		{
			P = Next(P);
		}
		return(P);
}
/* Mencari apakah ada elemen list dengan Info(P)= X */
/* Jika ada, mengirimkan address elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */

boolean FSearch (List L, address P)
{
	// KAMUS
	address X;
	boolean found;
	
		// ALGORITMA
		found = false;
		if (!IsEmpty(L))
		{
			X = First(L);
			while ((X != Nil) && (!found))
			{
				if (P == X)
				{
					found = true;
				}
				else
				{
					X = Next(X);
				}
			}
		}
		return (found);
}
/* Mencari apakah ada elemen list yang beralamat P */
/* Mengirimkan true jika ada, false jika tidak ada */

address SearchPrec (List L, infotype X)
{
	// KAMUS
	address P, Prec;
	
		// ALGORITMA
		if (NbElmt(L) > 1)
		{
			P = First(L);
			Prec = Nil;
			while ((Next(P) != Nil) && (Info(P) != X))
			{
				Prec = P;
				P = Next(P);
			}
			if (Info(P) != X)
			{
				return (Nil);
			}
			else
			{
				return (Prec);
			}	
		}
		else
		{
			return (Nil);
		}
}
/* Mengirimkan address elemen sebelum elemen yang nilainya=X */
/* Mencari apakah ada elemen list dengan Info(P)=X */
/* Jika ada, mengirimkan address Prec, dengan Next(Prec)=P dan Info(P)=X. */
/* Jika tidak ada, mengirimkan Nil */
/* Jika P adalah elemen pertama, maka Prec=Nil */
/* Search dengan spesifikasi seperti ini menghindari */
/* traversal ulang jika setelah Search akan dilakukan operasi lain */


/****************** PRIMITIF BERDASARKAN NILAI ******************/

/*** PENAMBAHAN ELEMEN ***/

void InsVFirst (List *L, infotype X)
{
	// KAMUS
	address P;
	
		// ALGORITMA
		P = Alokasi(X);
		InsertFirst(L, P);
}
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */

void InsVLast (List *L, infotype X)
{
	// KAMUS
	address Last;
	
		// ALGORITMA
		if (IsEmpty(*L))
		{
			InsVFirst(L, X);
		}
		else
		{
			Last = Alokasi(X);
			InsertLast(L, Last);
		}
		
}
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */


/*** PENGHAPUSAN ELEMEN ***/

void DelVFirst (List *L, infotype *X)
{
	// KAMUS
	address P;
	
		// ALGORITMA
		DelFirst(L, &P);
		*X = Info(P);
		Dealokasi(&P);
}
/* I.S. List L tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */

void DelVLast (List *L, infotype *X)
{
	// KAMUS
	address Last;
	
		// ALGORITMA
		DelLast(L, &Last);
		*X = Info(Last);
		Dealokasi(&Last);
}
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */


/****************** PRIMITIF BERDASARKAN ALAMAT ******************/

/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/

void InsertFirst (List *L, address P)
{
	// KAMUS
	
	
		// ALGORITMA
		Next(P) = First(*L);
		First(*L) = P;
}
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-address P sebagai elemen pertama */

void InsertAfter (List *L, address P, address Prec)
{
	// KAMUS

	
		// ALGORITMA
		Next(P) = Next(Prec);
		Next(Prec) = P;
}
/* I.S. Prec pastilah elemen list dan bukan elemen terakhir, */
/*      P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */

void InsertLast (List *L, address P)
{
	// KAMUS
	address Last;
	
		// ALGORITMA
		if (IsEmpty(*L))
		{
			InsertFirst(L, P);
		}
		else
		{
			Last = First(*L);
			while (Next(Last) != Nil)
			{
				Last = Next(Last);
			}
			InsertAfter(L, P, Last);
		}
}
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */


/*** PENGHAPUSAN SEBUAH ELEMEN ***/

void DelFirst (List *L, address *P)
{
	// KAMUS
	
	
		// ALGORITMA
		*P = First(*L);
		if (Next(*P) != Nil)
		{
			First(*L) = Next(*P);
			Next(*P) = Nil;
		}
		else
		{
			CreateEmpty(L);
		}
}
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */

void DelP (List *L, infotype X)
{
	// KAMUS
	address P, Prec;
	
		// ALGORITMA
		if (!IsEmpty(*L))
		{
			P = Search(*L, X);
			if (P != Nil)
			{
				if (First(*L) == P)
				{
					DelVFirst(L, &X);
				}
				else
				{
					Prec = First(*L);
					while (Next(Prec) != P)
					{
						Prec = Next(Prec);
					}
					DelAfter(L, &P, Prec);
					Dealokasi(&P);
				}
			}
		}
		
}
/* I.S. Sembarang */
/* F.S. Jika ada elemen list beraddress P, dengan Info(P)=X  */
/* Maka P dihapus dari list dan di-dealokasi */
/* Jika tidak ada elemen list dengan Info(P)=X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */

void DelLast (List *L, address *P)
{
	// KAMUS
	address Last, PrecLast;
	
		// ALGORITMA
		Last = First(*L);
		PrecLast = Nil;
		while (Next(Last) != Nil)
		{
			PrecLast = Last;
			Last = Next(Last);
		}
		*P = Last;
		if (Last != First(*L))
		{
			Next(PrecLast) = Nil;
		}
		else
		{
			CreateEmpty(L);
		}
}
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen pertama yg lama, */
/* jika ada */

void DelAfter (List *L, address *Pdel, address Prec)
{
	// KAMUS
	
	
		// ALGORITMA
		*Pdel = Next(Prec);
		Next(Prec) = Next(*Pdel);
		Next(*Pdel) = Nil;
}
/* I.S. List tidak kosong. Prec adalah anggota list  */
/* F.S. Menghapus Next(Prec): */
/*      Pdel adalah alamat elemen list yang dihapus  */


/****************** PROSES SEMUA ELEMEN LIST ******************/

void PrintInfo (List L)
{
	// KAMUS
	address P;
	
		// ALGORITMA
		P = First(L);
		if (IsEmpty(L))
		{
			printf("[]");
		}
		else
		{
			printf("[");
			P = First(L);
			while (P != Nil)
			{
				if (Next(P) == Nil)
				{
					printf("%d]", Info(P));
				}
				else
				{
					printf("%d,", Info(P));
				}
				P = Next(P);
			}
		}
}
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, iai list dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */

int NbElmt (List L)
{
	// KAMUS
	address P;
	int count;
	
		// ALGORITMA
		if (IsEmpty(L))
		{
			return (0);
		}
		else
		{
			P = First(L);
			count = 0;
			while (P != Nil)
			{
				count++;
				P = Next(P);
			}
			return (count);
		}
}
/* Mengirimkan banyaknya elemen list{} mengirimkan 0 jika list kosong */


/*** Prekondisi untuk Max/Min/rata-rata : List tidak kosong ***/

infotype Max (List L)
{
	// KAMUS
	address P;
	int MaxL;
	
		// ALGORITMA
		P = First(L);
		MaxL = Info(P);
		P = Next(P);
		while (P != Nil)
		{
			if (MaxL < Info(P))
			{
				MaxL = Info(P);
			}
			P = Next(P);
		}
		return (MaxL);
}
/* Mengirimkan nilai Info(P) yang maksimum */

address AdrMax (List L)
{
	return (Search(L, Max(L)));
}
/* Mengirimkan address P, dengan info(P) yang bernilai maksimum */

infotype Min (List L)
{
	// KAMUS
	address P;
	int MinL;
	
		// ALGORITMA
		P = First(L);
		MinL = Info(P);
		P = Next(P);
		while (P != Nil)
		{
			if (MinL > Info(P))
			{
				MinL = Info(P);
			}
			P = Next(P);
		}
		return (MinL);
}
/* Mengirimkan nilai info(P) yang minimum */

address AdrMin (List L)
{
	return (Search(L, Min(L)));
}
/* Mengirimkan address P, dengan info(P) yang bernilai minimum */

float Average (List L)
{
	// KAMUS
	address P;
	int sum, count;
	
		// ALGORITMA
		if (IsEmpty(L))
		{
			return (0);
		}
		else
		{
			P = First(L);
			sum = 0;
			count = 0;
			while (P != Nil)
			{
				count++;
				sum += Info(P);
				P = Next(P);
			}
			return ((float) sum / (float) count);
		}
}
/* Mengirimkan nilai rata-rata info(P) */


/****************** PROSES TERHADAP LIST ******************/

void DelAll (List *L)
{
	// KAMUS
	infotype X;
	
		// ALGORITMA
		while (!IsEmpty(*L))
		{
			DelVFirst(L, &X);
		}
}
/* Delete semua elemen list dan alamat elemen di-dealokasi */

void InversList (List *L)
{
	// KAMUS
	address P;
	List Dummy;
	
		// ALGORITMA
		if ((!IsEmpty(*L)) && (NbElmt(*L) > 1))
		{
			CreateEmpty(&Dummy);
			while (!IsEmpty(*L))
			{
				DelLast(L, &P);				
				InsertLast(&Dummy, P);
			}
			First(*L) = First(Dummy);
		}	
}
/* I.S. sembarang. */
/* F.S. elemen list dibalik : */
/* Elemen terakhir menjadi elemen pertama, dan seterusnya. */
/* Membalik elemen list, tanpa melakukan alokasi/dealokasi. */

List FInversList (List L)
{
	// KAMUS
	infotype X;
	List Dummy;
	boolean Safe;
	
		// ALGORITMA
		CreateEmpty(&Dummy);
		Safe = true;
		while ((!IsEmpty(L)) && (Safe))
		{
			DelVFirst(&L, &X);
			if (Alokasi(X) == Nil)
			{
				Safe = false;
			}
			else
			{
				InsVFirst(&Dummy, X);
			}
		}
		if (!Safe)
		{
			DelAll(&Dummy);
		}
		return (Dummy);
}
/* Mengirimkan list baru, hasil invers dari L */
/* dengan menyalin semua elemn list. Alokasi mungkin gagal. */
/* Jika alokasi gagal, hasilnya list kosong */
/* dan semua elemen yang terlanjur di-alokasi, harus didealokasi */

void CopyList (List *L1, List *L2)
{
	CreateEmpty(L2);
	First(*L2) = First(*L1);	
}
/* I.S. L1 sembarang. F.S. L2=L1 */
/* L1 dan L2 "menunjuk" kepada list yang sama.*/
/* Tidak ada alokasi/dealokasi elemen */

List FCopyList (List L)
{
	// KAMUS
	address P, PX;
	List Dummy;
	boolean Safe;
	
		// ALGORITMA
		CreateEmpty(&Dummy);
		Safe = true;
		P = First(L);
		while ((P != Nil) && (Safe))
		{
			PX = Alokasi(Info(P));
			if (PX == Nil)  // Alokasi gagal
			{
				Safe = false;
			}
			else
			{
				InsertLast(&Dummy, PX);
				P = Next(P);
			}
		}
		if (!Safe)
		{
			DelAll(&Dummy);
		}
		return (Dummy);
}
/* Mengirimkan list yang merupakan salinan L */
/* dengan melakukan alokasi. */
/* Jika ada alokasi gagal, hasilnya list kosong dan */
/* semua elemen yang terlanjur di-alokasi, harus didealokasi */

void CpAlokList (List Lin, List *Lout)
{
	First(*Lout) = First(FCopyList(Lin));
}
/* I.S. Lin sembarang. */
/* F.S. Jika semua alokasi berhasil,maka Lout berisi hasil copy Lin */
/* Jika ada alokasi yang gagal, maka Lout=Nil dan semua elemen yang terlanjur dialokasi, didealokasi */
/* dengan melakukan alokasi elemen. */
/* Lout adalah list kosong jika ada alokasi elemen yang gagal */

void Konkat (List L1, List L2, List * L3)
{
	// KAMUS
	infotype X;
	boolean Safe;
	
		// ALGORITMA
		Safe = true;
		if ((IsEmpty(L1)) && (IsEmpty(L2)))
		{
			CreateEmpty(L3);
		}
		else if (IsEmpty(L1))
		{
			CpAlokList(L2, L3);
		}
		else if (IsEmpty(L2))
		{
			CpAlokList(L1, L3);
		}
		else
		{
			CpAlokList(L1, L3);
			if (!IsEmpty(*L3))
			{
				Safe = true;
				while ((!IsEmpty(L2)) && (Safe))
				{
					DelVFirst(&L2, &X);
					if (Alokasi(X) == Nil)
					{
						Safe = false;
					}
					else
					{
						InsVLast(L3, X);
					}
				}
				if (!Safe)
				{
					DelAll(L3);
				}
			}
		}	
}
/* I.S. L1 dan L2 sembarang */
/* F.S. L1 dan L2 tetap, L3 adalah hasil konkatenasi L1 & L2 */
/* Jika semua alokasi berhasil, maka L3 adalah hasil konkatenasi*/
/* Jika ada alokasi yang gagal, semua elemen yang sudah dialokasi */
/* harus di-dealokasi dan L3=Nil*/
/* Konkatenasi dua buah list : L1 & L2 menghasilkan L3 yang "baru" */
/* Elemen L3 adalah hasil alokasi elemen yang “baru”. */
/* Jika ada alokasi yang gagal, maka L3 harus bernilai Nil*/
/* dan semua elemen yang pernah dialokasi didealokasi */

void Konkat1 (List *L1, List *L2, List *L3)
{
	// KAMUS
	address Last;
	
		// ALGORITMA
		if (IsEmpty(*L1))
		{
			First(*L3) = First(*L2);
		}
		else if (IsEmpty(*L2))
		{
			First(*L3) = First(*L1);
		}
		else
		{
			First(*L3) = First(*L1);
			Last = First(*L1);
			while (Next(Last) != Nil)
			{
				Last = Next(Last);
			}
			Next(Last) = First(*L2);
		}
		CreateEmpty(L1);
		CreateEmpty(L2);
}
/* I.S. L1 dan L2 sembarang */
/* F.S. L1 dan L2 kosong, L3 adalah hasil konkatenasi L1 & L2 */
/* Konkatenasi dua buah list : L1 dan L2    */
/* menghasilkan L3 yang baru (dengan elemen list L1 dan L2) */
/* dan L1 serta L2 menjadi list kosong.*/
/* Tidak ada alokasi/dealokasi pada prosedur ini */

void PecahList (List *L1, List *L2, List L)
{
	// KAMUS
	int i, N, NAwal, NAkhir;
	infotype X;
	
		// ALGORITMA
		CreateEmpty(L1);
		CreateEmpty(L2);
		if (!IsEmpty(L))
		{
			N = NbElmt(L);
			if (N == 1)
			{
				DelVFirst(&L, &X);
				InsVFirst(L2, X);
			}
			else
			{
				NAwal = N / 2;
				NAkhir = N - NAwal;
				for (i = 1; i <= NAwal; i++)
				{
					DelVFirst(&L, &X);
					InsVLast(L1, X);
				}
				for (i = 1; i <= NAkhir; i++)
				{
					DelVFirst(&L, &X);
					InsVLast(L2, X);
				}
			}
		}
		
}
/* I.S. L mungkin kosong */
/* F.S. Berdasarkan L, dibentuk dua buah list L1 dan L2 */
/* L tidak berubah: untuk membentuk L1 dan L2 harus alokasi */
/* L1 berisi separuh elemen L dan L2 berisi sisa elemen L */
/* Jika elemen L ganjil, maka separuh adalah NbElmt(L) div 2 */
