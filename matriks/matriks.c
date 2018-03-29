// HOLY LOVENIA - 13515113


#include "boolean.h"
#include "matriks.h"
#include <stdio.h>


/* ********** DEFINISI PROTOTIPE PRIMITIF ********** */              
/* *** Konstruktor membentuk MATRIKS *** */
void MakeMATRIKS (int NB, int NK, MATRIKS * M)
{
	NBrsEff(*M) = NB;
	NKolEff(*M) = NK;
} 
/* Membentuk sebuah MATRIKS "kosong" yang siap diisi berukuran NB x NK di "ujung kiri" memori */
/* I.S. NB dan NK adalah valid untuk memori matriks yang dibuat */
/* F.S. Matriks M sesuai dengan definisi di atas terbentuk */

/* *** Selektor *** */
#define NBrsEff(M) (M).NBrsEff
#define NKolEff(M) (M).NKolEff
#define Elmt(M,i,j) (M).Mem[(i)][(j)]


/* *** Selektor "DUNIA MATRIKS" *** */

boolean IsIdxValid (int i, int j)
{
	return ((i >= BrsMin) && (i <= BrsMax) && (j >= KolMin) && (j <= KolMax));
}
/* Mengirimkan true jika i, j adalah indeks yang valid untuk matriks apa pun */


/* *** Selektor: Untuk sebuah matriks M yang terdefinisi: *** */

indeks GetFirstIdxBrs (MATRIKS M)
{
	return (BrsMin);
}
/* Mengirimkan indeks baris terkecil M */

indeks GetFirstIdxKol (MATRIKS M)
{
	return (KolMin);
}
/* Mengirimkan indeks kolom terkecil M */

indeks GetLastIdxBrs (MATRIKS M)
{
	return (BrsMin + NBrsEff(M) - 1);
}
/* Mengirimkan indeks baris terbesar M */

indeks GetLastIdxKol (MATRIKS M)
{
	return (KolMin + NKolEff(M) - 1);
}
/* Mengirimkan indeks kolom terbesar M */

boolean IsIdxEff (MATRIKS M, indeks i, indeks j)
{
	return ((i >= GetFirstIdxBrs(M)) && (i <= GetLastIdxBrs(M)) && (j >= GetFirstIdxKol(M)) && (j <= GetLastIdxKol(M)));
}
/* Mengirimkan true jika i, j adalah indeks efektif bagi M */

ElType GetElmtDiagonal (MATRIKS M, indeks i)
{
	return (Elmt(M, i, i));
}
/* Mengirimkan elemen M(i,i) */


/* ********** Assignment  MATRIKS ********** */
void CopyMATRIKS (MATRIKS MIn, MATRIKS * MHsl)
{
	// KAMUS
	indeks i, j;
		
		// ALGORITMA
		MakeMATRIKS(NBrsEff(MIn), NKolEff(MIn), MHsl); 
		
		for (i = GetFirstIdxBrs(MIn); i <= GetLastIdxBrs(MIn); i++)
		{
			for (j = GetFirstIdxBrs(MIn); j <= GetLastIdxBrs(MIn); j++)
			{
				Elmt(*MHsl, i, j) = Elmt(MIn, i, j);
			}
		}
}
/* Melakukan assignment MHsl  MIn */

/* ********** KELOMPOK BACA/TULIS ********** */ 
void BacaMATRIKS (MATRIKS * M, int NB, int NK)
{
	// KAMUS
	indeks i, j;
	
		// ALGORITMA
		MakeMATRIKS(NB, NK, M);
		for (i = GetFirstIdxBrs(*M); i <= GetLastIdxBrs(*M); i++)
		{
			for (j = GetFirstIdxKol(*M); j <= GetLastIdxKol(*M); j++)
			{
				scanf("%d", &Elmt(*M, i, j));
			}
		}
}
/* I.S. IsIdxValid(NB,NK) */ 
/* F.S. M terdefinisi nilai elemen efektifnya, berukuran NB x NK */
/* Proses: Melakukan MakeMATRIKS(M,NB,NK) dan mengisi nilai efektifnya */
/* Selanjutnya membaca nilai elemen per baris dan kolom */
/* Contoh: Jika NB = 3 dan NK = 3, maka contoh cara membaca isi matriks :
1 2 3
4 5 6
8 9 10 
*/
void TulisMATRIKS (MATRIKS M)
{
	// KAMUS
	indeks i, j;
		
		// ALGORITMA
		for (i = GetFirstIdxBrs(M); i <= GetLastIdxBrs(M); i++)
		{
			for (j = GetFirstIdxKol(M); j <= GetLastIdxKol(M); j++)
			{
				if (j < GetLastIdxKol(M))
				{
					printf("%d ", Elmt(M, i, j));
				}
				else
				{
					printf("%d", Elmt(M, i, j));
				}
			}
			if (i < GetLastIdxBrs(M))
			{
				printf("\n");
			}
		}
		
}
/* I.S. M terdefinisi */
/* F.S. Nilai M(i,j) ditulis ke layar per baris per kolom, masing-masing elemen per baris 
   dipisahkan sebuah spasi */
/* Proses: Menulis nilai setiap elemen M ke layar dengan traversal per baris dan per kolom */
/* Contoh: menulis matriks 3x3 (ingat di akhir tiap baris, tidak ada spasi)
1 2 3
4 5 6
8 9 10
*/


/* ********** KELOMPOK OPERASI ARITMATIKA TERHADAP TYPE ********** */                                  

MATRIKS TambahMATRIKS (MATRIKS M1, MATRIKS M2)
{
	// KAMUS
	MATRIKS M3;
	indeks i, j;
	
		// ALGORITMA
		MakeMATRIKS(NBrsEff(M1), NKolEff(M1), &M3);
		for (i = GetFirstIdxBrs(M1); i <= GetLastIdxBrs(M1); i++)
		{
			for (j = GetFirstIdxKol(M1); j <= GetLastIdxKol(M1); j++)
			{
				Elmt(M3, i, j) = Elmt(M1, i, j) + Elmt(M2, i, j);
			}
		}
		return (M3);
}
/* Prekondisi : M1  berukuran sama dengan M2 */
/* Mengirim hasil penjumlahan matriks: M1 + M2 */ 

MATRIKS KurangMATRIKS (MATRIKS M1, MATRIKS M2)
{
	// KAMUS
	MATRIKS M3;
	indeks i, j;
	
		// ALGORITMA
		MakeMATRIKS(NBrsEff(M1), NKolEff(M1), &M3);
		for (i = GetFirstIdxBrs(M1); i <= GetLastIdxBrs(M1); i++)
		{
			for (j = GetFirstIdxKol(M1); j <= GetLastIdxKol(M1); j++)
			{
				Elmt(M3, i, j) = Elmt(M1, i, j) - Elmt(M2, i, j);
			}
		}
		return (M3);
}
/* Prekondisi : M berukuran sama dengan M */
/* Mengirim hasil pengurangan matriks: salinan M1 – M2 */ 

MATRIKS KaliMATRIKS (MATRIKS M1, MATRIKS M2)
{
	// KAMUS
	MATRIKS M3;
	indeks i, j, k;
	ElType sum;
	
		// ALGORITMA
		MakeMATRIKS(NBrsEff(M1), NKolEff(M2), &M3);
		for (i = GetFirstIdxBrs(M1); i <= GetLastIdxBrs(M1); i++)
		{
			for (j = GetFirstIdxKol(M2); j <= GetLastIdxKol(M2); j++)
			{
				sum = 0;
				for (k = GetFirstIdxBrs(M2); k <= GetLastIdxBrs(M2); k++)
				{
					sum = sum + (Elmt(M1, i, k) * Elmt(M2, k, j));
				}
				Elmt(M3, i, j) = sum;
			}
		}
		return (M3);
}
/* Prekondisi : Ukuran kolom efektif M1 = ukuran baris efektif M2 */
/* Mengirim hasil perkalian matriks: salinan M1 * M2 */

MATRIKS KaliKons (MATRIKS M, ElType X)
{
	// KAMUS
	MATRIKS MOut;
	indeks i, j;
	
		// ALGORITMA
		MakeMATRIKS(NBrsEff(M), NKolEff(M), &MOut);
		for (i = GetFirstIdxBrs(M); i <= GetLastIdxBrs(M); i++)
		{
			for (j = GetFirstIdxKol(M); j <= GetLastIdxKol(M); j++)
			{
				Elmt(MOut, i, j) = Elmt(M, i, j) * X;
			}
		}
		return (MOut);
}
/* Mengirim hasil perkalian setiap elemen M dengan X */

void PKaliKons (MATRIKS * M, ElType K)
{
	*M = KaliKons(*M, K);
}
/* I.S. M terdefinisi, K terdefinisi */
/* F.S. Mengalikan setiap elemen M dengan K */


/* ********** KELOMPOK OPERASI RELASIONAL TERHADAP MATRIKS ********** */

boolean EQ (MATRIKS M1, MATRIKS M2)
{
	// KAMUS
	indeks i, j;
	boolean sama;
	
		// ALGORITMA
		
		if (EQSize(M1, M2))
		{
			sama = true;
			i = GetFirstIdxBrs(M1);
			while ((i <= GetLastIdxBrs(M1)) && sama)
			{
				j = GetFirstIdxKol(M1);
				while ((j <= GetLastIdxKol(M1)) && sama)
				{
					if (Elmt(M1, i, j) != Elmt(M2, i, j))
					{
						sama = false;
					}
					j++;
				}
				i++;
			}
			return (sama);
		}
		else
		{
			return (false);
		}
}
/* Mengirimkan true jika M1 = M2, yaitu NBElmt(M1) = NBElmt(M2) dan */
/* untuk setiap i,j yang merupakan indeks baris dan kolom M1(i,j) = M2(i,j) */
/* Juga merupakan strong EQ karena GetFirstIdxBrs(M1) = GetFirstIdxBrs(M2) 
   dan GetLastIdxKol(M1) = GetLastIdxKol(M2) */

boolean NEQ (MATRIKS M1, MATRIKS M2)
{
	return (!EQ(M1, M2));
}
/* Mengirimkan true jika M1 tidak sama dengan M2 */

boolean EQSize (MATRIKS M1, MATRIKS M2)
{
	return ((NBrsEff(M1) == NBrsEff(M2)) && (NKolEff(M1) == NKolEff(M2)));
}
/* Mengirimkan true jika ukuran efektif matriks M1 sama dengan ukuran efektif M2 */
/* yaitu GetBrsEff(M1) = GetNBrsEff (M2) dan GetNKolEff (M1) = GetNKolEff (M2) */


/* ********** Operasi lain ********** */

int NBElmt (MATRIKS M)
{
	return ((GetLastIdxBrs(M) - GetFirstIdxBrs(M) + 1) * (GetLastIdxKol(M) - GetFirstIdxKol(M) + 1));
}
/* Mengirimkan banyaknya elemen M */


/* ********** KELOMPOK TEST TERHADAP MATRIKS ********** */

boolean IsBujurSangkar (MATRIKS M)
{
	return ((GetLastIdxBrs(M) - GetFirstIdxBrs(M) + 1) == (GetLastIdxKol(M) - GetFirstIdxKol(M) + 1));
}
/* Mengirimkan true jika M adalah matriks dg ukuran baris dan kolom sama */

boolean IsSimetri (MATRIKS M)
{
	// KAMUS
	indeks i, j;
	boolean sama;
	
		// ALGORITMA
		if (IsBujurSangkar(M))
		{
			sama = true;
			i = GetFirstIdxBrs(M);
			while ((i <= GetLastIdxBrs(M)) && sama)
			{
				j = GetFirstIdxKol(M);
				while ((j <= GetLastIdxKol(M)) && sama)
				{
					if (Elmt(M, i, j) != Elmt(M, j, i))
					{
						sama = false;
					}
					j++;
				}
				i++;
			}
			return (sama);
		}
		else
		{
			return (false);
		}
}
/* Mengirimkan true jika M adalah matriks simetri : IsBujurSangkar(M) 
   dan untuk setiap elemen M, M(i,j)=M(j,i) */

boolean IsSatuan (MATRIKS M)
{
	// KAMUS
	indeks i, j;
	boolean sama;
	
		// ALGORITMA
		if (IsBujurSangkar(M))
		{
			sama = true;
			i = GetFirstIdxBrs(M);
			while ((i <= GetLastIdxBrs(M)) && sama)
			{
				j = GetFirstIdxKol(M);
				while ((j <= GetLastIdxKol(M)) && sama)
				{
					if (((i == j) && (GetElmtDiagonal(M, i) != 1)) || ((i != j) && (Elmt(M, i, j) != 0)))
					{
						sama = false;
					}
					j++;
				}
				i++;
			}
			return (sama);
		}
		else
		{
			return (false);
		}
}
/* Mengirimkan true jika M adalah matriks satuan: IsBujurSangkar(M) dan
setiap elemen diagonal M bernilai 1 dan elemen yang bukan diagonal bernilai 0 */ 

boolean IsSparse (MATRIKS M)
{
	// KAMUS
	int kuota, countsparse, i, j;
	
		// ALGORITMA
		countsparse = 0;
		kuota = 0.05 * NBElmt(M);
		for (i = GetFirstIdxBrs(M); i <= GetLastIdxBrs(M); i++)
		{
			for (j = GetFirstIdxKol(M); j <= GetLastIdxKol(M); j++)
			{
				if (Elmt(M, i, j) != 0)
				{
					countsparse = countsparse + 1;
				}
			}
		}
		if (countsparse > kuota)
		{
			return (false);
		}
		else
		{
			return (true);
		}
		
}
/* Mengirimkan true jika M adalah matriks sparse: mariks “jarang” dengan definisi: 
   hanya maksimal 5% dari memori matriks yang efektif bukan bernilai 0 */ 

MATRIKS Inverse1 (MATRIKS M)
{
	return(KaliKons(M, -1));
}
/* Menghasilkan salinan M dengan setiap elemen "di-invers", yaitu dinegasikan (dikalikan -1) */

float Determinan (MATRIKS M)
{
	// KAMUS
	float sum, patokan, patokan2, hasil;
	float Temp [NBrsEff(M) + 1] [NKolEff(M) + 1];
	indeks i, j, k, l, kolom, baris;
	MATRIKS MatriksK;
	
		// ALGORITMA
		if (NBrsEff(M) < 0)
		{
			return (Elmt(M, GetFirstIdxBrs(M), GetLastIdxBrs(M)) * ((Elmt(M, GetFirstIdxBrs(M) + 1, GetLastIdxBrs(M) + 1) * Elmt(M, GetFirstIdxBrs(M) + 2, GetLastIdxBrs(M) + 2)) - (Elmt(M, GetFirstIdxBrs(M) + 2, GetLastIdxBrs(M) + 1) * Elmt(M, GetFirstIdxBrs(M) + 1, GetLastIdxBrs(M) + 2))) - Elmt(M, GetFirstIdxBrs(M), GetLastIdxBrs(M) + 1) * (Elmt(M, GetFirstIdxBrs(M) + 1, GetLastIdxBrs(M)) * Elmt(M, GetFirstIdxBrs(M) + 2, GetLastIdxBrs(M) + 2) - Elmt(M, GetFirstIdxBrs(M) + 2, GetLastIdxBrs(M)) * Elmt(M, GetFirstIdxBrs(M) + 1, GetLastIdxBrs(M) + 2)) + Elmt(M, GetFirstIdxBrs(M), GetLastIdxBrs(M) + 2) * (Elmt(M, GetFirstIdxBrs(M) + 1, GetLastIdxBrs(M)) * Elmt(M, GetFirstIdxBrs(M) + 2, GetLastIdxBrs(M) + 1) - Elmt(M, GetFirstIdxBrs(M) + 2, GetLastIdxBrs(M)) * Elmt(M, GetFirstIdxBrs(M) + 1, GetLastIdxBrs(M) + 1)));
		}
		else if (NBrsEff(M) == 2)
		{
			hasil = (float)(Elmt(M, GetFirstIdxBrs(M), GetFirstIdxKol(M)) * Elmt(M, GetLastIdxBrs(M), GetLastIdxKol(M))) - (Elmt(M, GetFirstIdxBrs(M), GetLastIdxKol(M)) * Elmt(M, GetLastIdxBrs(M), GetFirstIdxKol(M)));
			return (hasil);
		}
		else if (NBrsEff(M) == 1)
		{
			hasil = (float)Elmt(M, GetFirstIdxBrs(M), GetFirstIdxKol(M));
			return (hasil);
		}
		else if (NBrsEff(M) >= 3)
		{
			/* OPERASI BARIS ELEMENTER
			for (i = GetFirstIdxBrs(M); i <= GetLastIdxBrs(M); i++)
			{
				for (j = GetFirstIdxKol(M); j <= GetLastIdxKol(M); j++)
				{
					Temp[i][j] = Elmt(M, i, j);
				}
			}
			
			for (i = GetFirstIdxBrs(M); i <= GetLastIdxBrs(M) - 1; i++)
			{
				patokan = Temp[i][i];
				for (j = i + 1; j <= GetLastIdxBrs(M); j++)
				{
					patokan2 = Temp[j][i];
					for (k = i; k <= GetLastIdxKol(M); k++)
					{
						//patokan = Temp[i][i];
						printf("%f\n", patokan);
						//patokan2 = Temp[j][i];
						printf("%f\n", patokan2);
						if ((patokan == 0) && (patokan2 == 0))
						{
							Temp[j][k] = Temp[j][k] + 0;
						}
						else
						{
							Temp[j][k] = Temp[j][k] - ((patokan2 / patokan) * Temp[i][k]) + 0;
						}
						printf("%f\n\n", Temp[j][k]);
					}
				}
			}
			
			for (i = GetFirstIdxBrs(M); i <= GetLastIdxBrs(M); i++)
			{
				for (j = GetFirstIdxKol(M); j <= GetLastIdxKol(M); j++)
				{
					printf("%.0f ", Temp[i][j]);
				}
				printf("\n");
			}
			
			sum = 1;
			for (i = GetFirstIdxBrs(M); i <= GetLastIdxBrs(M); i++)
			{
				sum = sum * (Temp[i][i] + 0);
			}
			return (sum);
			*/
			
			/* REKURSI */
			hasil = 0;
			for (i = GetFirstIdxBrs(M); i <= GetLastIdxBrs(M); i++)
			{
				MakeMATRIKS(NBrsEff(M) - 1, NKolEff(M) - 1, &MatriksK);
				baris = 1;
				kolom = 0;
				for (j = GetFirstIdxBrs(M); j <= GetLastIdxBrs(M); j++)
				{
					for (k = GetFirstIdxKol(M); k <= GetLastIdxKol(M); k++)
					{
						if ((j != i) && (k != 1))
						{
							kolom++;
							Elmt(MatriksK, baris, kolom) = Elmt(M, j, k);
							if (kolom == GetLastIdxKol(MatriksK))
							{
								baris++;
								kolom = 0;
							}
						}
						
					}
				}
				
				if ((i + 1) % 2 == 1)
				{
					hasil -= (float)Elmt(M, i, 1) * Determinan(MatriksK);
				}
				else
				{
					hasil += (float)Elmt(M, i, 1) * Determinan(MatriksK);
				}
			}
			
			return (hasil);
			
		}
}
/* Prekondisi: IsBujurSangkar(M) */
/* Menghitung nilai determinan M */

void PInverse1 (MATRIKS * M)
{
	*M = Inverse1(*M);
}
/* I.S. M terdefinisi */
/* F.S. M di-invers, yaitu setiap elemennya dinegasikan (dikalikan -1) */

void Transpose (MATRIKS * M)
{
	// KAMUS
	indeks i, j;
	MATRIKS temp;
	
		// ALGORITMA
		MakeMATRIKS(NKolEff(*M), NBrsEff(*M), &temp);
		for (i = GetFirstIdxKol(*M); i <= GetLastIdxKol(*M); i++)
		{
			for (j = GetFirstIdxBrs(*M); j <= GetLastIdxBrs(*M); j++)
			{
				Elmt(temp, i, j) = Elmt(*M, j, i);
			}
		}
		*M = temp;
}
/* I.S. M terdefinisi dan IsBujursangkar(M) */
/* F.S. M "di-transpose", yaitu setiap elemen M(i,j) ditukar nilainya dengan elemen M(j,i) */

/* Operasi berbasis baris dan per kolom */

float RataBrs (MATRIKS M, indeks i)
{
	// KAMUS
	float ave;
	indeks kolom;
	ElType sum;
	
		// ALGORITMA
		sum = 0;
		for (kolom = GetFirstIdxKol(M); kolom <= GetLastIdxKol(M); kolom++)
		{
			sum = sum + Elmt(M, i, kolom);
		}
		ave = (float) sum / (float) NKolEff(M);
		
		return (ave);
}
/* Menghasilkan rata-rata dari elemen pada baris ke-i */
/* Prekondisi: i adalah indeks baris efektif dari M */

float RataKol (MATRIKS M, indeks j)
{
	// KAMUS
	float ave;
	indeks baris;
	ElType sum;
	
		// ALGORITMA
		sum = 0;
		for (baris = GetFirstIdxBrs(M); baris <= GetLastIdxBrs(M); baris++)
		{
			sum = sum + Elmt(M, baris, j);
		}
		ave = (float) sum / (float) NBrsEff(M);
		
		return (ave);	
}
/* Menghasilkan rata-rata dari elemen pada kolom ke-j */
/* Prekondisi: j adalah indeks kolom efektif dari M */

void MaxMinBrs (MATRIKS M, indeks i, ElType * max, ElType * min)
{
	// KAMUS
	indeks kolom;
	
		// ALGORITMA
		kolom = GetFirstIdxKol(M);
		*max = Elmt(M, i, kolom);
		*min = Elmt(M, i, kolom);
		while (kolom <= GetLastIdxKol(M))
		{
			if (*max < Elmt(M, i, kolom))
			{
				*max = Elmt(M, i, kolom);
			}
			if (*min > Elmt(M, i, kolom))
			{
				*min = Elmt(M, i, kolom);
			}
			kolom++;
		}
}
/* I.S. i adalah indeks baris efektif dari M, M terdefinisi */
/* F.S. max berisi elemen maksimum pada baris i dari M
           min berisi elemen minimum pada baris i dari M */

void MaxMinKol (MATRIKS M, indeks j, ElType * max, ElType * min)
{
		// KAMUS
	indeks baris;
	
		// ALGORITMA
		baris = GetFirstIdxBrs(M);
		*max = Elmt(M, baris, j);
		*min = Elmt(M, baris, j);
		while (baris <= GetLastIdxBrs(M))
		{
			if (*max < Elmt(M, baris, j))
			{
				*max = Elmt(M, baris, j);
			}
			if (*min > Elmt(M, baris, j))
			{
				*min = Elmt(M, baris, j);
			}
			baris++;
		}
}
/* I.S. j adalah indeks kolom efektif dari M, M terdefinisi */
/* F.S. max berisi elemen maksimum pada kolom j dari M
           min berisi elemen minimum pada kolom j dari M */

int CountXBrs (MATRIKS M, indeks i, ElType X)
{
	// KAMUS
	indeks kolom;
	int count;
	
		// ALGORITMA
		count = 0;
		kolom = GetFirstIdxKol(M);
		while (kolom <= GetLastIdxKol(M))
		{
			if (Elmt(M, i, kolom) == X)
			{
				count++;
			}
			kolom++;
		}
		
		return (count);
}
/* Menghasilkan banyaknya kemunculan X pada baris i dari M */

int CountXKol (MATRIKS M, indeks j, ElType X)
{
	// KAMUS
	indeks baris;
	int count;
	
		// ALGORITMA
		count = 0;
		baris = GetFirstIdxBrs(M);
		while (baris <= GetLastIdxBrs(M))
		{
			if (Elmt(M, baris, j) == X)
			{
				count++;
			}
			baris++;
		}
		
		return (count);	
}
/* Menghasilkan banyaknya kemunculan X pada kolom j dari M */
