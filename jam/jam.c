// HOLY LOVENIA - 13515113

/* File: jam.c */
/* Tanggal: 31 Agustus 2016 */
/* Definisi ADT JAM */

#include "jam.h"
#include <stdio.h>

/* ***************************************************************** */
/* DEFINISI PRIMITIF                                                 */
/* ***************************************************************** */
/* KELOMPOK VALIDASI TERHADAP TYPE                                   */
/* ***************************************************************** */
boolean IsJAMValid (int H, int M, int S)
/* Mengirim true  jika H,M,S dapat membentuk J yang valid */
/* dipakai untuk mentest SEBELUM membentuk sebuah Jam */
{
	return (((H >= 0) && (H <= 23)) && ((M >= 0) && (M <= 59)) && ((S >= 0) && (S <=59)));
}


/* *** Konstruktor: Membentuk sebuah JAM dari komponen-komponennya *** */
JAM MakeJAM (int HH, int MM, int SS)
/* Membentuk sebuah JAM dari komponen-komponennya yang valid */
/* Prekondisi : HH, MM, SS valid untuk membentuk JAM */
{
	// KAMUS
	JAM J;
	
		// ALGORITMA
		Hour(J) = HH;
		Minute(J) = MM;
		Second(J) = SS;
	
		return (J);
}

/* ***************************************************************** */
/* KELOMPOK BACA/TULIS                                               */
/* ***************************************************************** */
void BacaJAM (JAM * J)
{
/* I.S. : J tidak terdefinisi */
/* F.S. : J terdefinisi dan merupakan jam yang valid */
/* Proses : mengulangi membaca komponen HH, MM, SS sehingga membentuk J */
/* yang valid. Tidak mungkin menghasilkan J yang tidak valid. */
/* Pembacaan dilakukan dengan mengetikkan komponen HH, MM, SS
   dalam satu baris, masing-masing dipisahkan 1 spasi, diakhiri enter. */
/* Jika JAM tidak valid maka diberikan pesan: "Jam tidak valid", dan pembacaan
   diulangi hingga didapatkan jam yang valid. */
/* Contoh: 
   60 3 4
   Jam tidak valid
   1 3 4
   --> akan terbentuk JAM <1,3,4> */

	// KAMUS
	int HH, MM, SS;
		// ALGORITMA		
		scanf("%d %d %d", &HH, &MM, &SS);
		while (!(IsJAMValid (HH, MM, SS)))
		{
			printf("Jam tidak valid\n");
			scanf("%d %d %d", &HH, &MM, &SS);
		}
		*J = MakeJAM(HH, MM, SS);
}
   
void TulisJAM (JAM J)
{
/* I.S. : J sembarang */
/* F.S. :   Nilai J ditulis dg format HH:MM:SS */
/* Proses : menulis nilai setiap komponen J ke layar dalam format HH:MM:SS
   tanpa karakter apa pun di depan atau belakangnya, termasuk spasi, enter, dll.*/ 
	
	// ALGORITMA
	printf("%d:%d:%d", Hour(J), Minute(J), Second(J));
   
}

/* ***************************************************************** */
/* KELOMPOK KONVERSI TERHADAP TYPE                                   */
/* ***************************************************************** */
long JAMToDetik (JAM J)
{
/* Diberikan sebuah JAM, mengkonversi menjadi jumlah detik dari pukul 0:0:0 */
/* Rumus : detik = 3600*HH + 60*MM + SS */
/* Nilai maksimum = 3600*23+59*60+59 */
	
	// ALGORITMA
	return(3600*Hour(J) + 60*Minute(J) + Second(J));
	
}

JAM DetikToJAM (long N)
{ 
/* Mengirim  konversi detik ke JAM */
/* Catatan: Jika N >= 86400, maka harus dikonversi dulu menjadi jumlah detik yang 
   mewakili jumlah detik yang mungkin dalam 1 hari, yaitu dengan rumus: 
   N1 = N mod 86400, baru N1 dikonversi menjadi JAM */

/* ***************************************************************** */
/* KELOMPOK OPERASI TERHADAP TYPE                                    */
/* ***************************************************************** */
/* *** Kelompok Operator Relational *** */
	
	// KAMUS
	JAM J;
	
		// ALGORITMA
		N = N % 86400;
		Hour(J) = N / 3600;
		Minute(J) = (N % 3600) / 60;
		Second(J) = N % 60;
		
		return(J);
	
}

boolean JEQ (JAM J1, JAM J2)
{
/* Mengirimkan true jika J1=J2, false jika tidak */

	// KAMUS
	
		// ALGORITMA
		return ((Hour(J1) == Hour(J2)) && (Minute(J1) == Minute(J2)) && (Second(J1) == Second(J2)));

}

boolean JNEQ (JAM J1, JAM J2)
{
/* Mengirimkan true jika J1 tidak sama dengan J2 */

	// KAMUS
	
		// ALGORITMA
		return (!JEQ(J1, J2));

}

boolean JLT (JAM J1, JAM J2)
{
/* Mengirimkan true jika J1<J2, false jika tidak */

	// KAMUS
	
		// ALGORITMA
		return(JAMToDetik(J1) < JAMToDetik(J2));

}

boolean JGT (JAM J1, JAM J2)
{
/* Mengirimkan true jika J1>J2, false jika tidak */
/* *** Operator aritmatika JAM *** */

	// KAMUS
	
		// ALGORITMA
		return(JAMToDetik(J1) > JAMToDetik(J2));

}

JAM NextDetik (JAM J)
{
/* Mengirim 1 detik setelah J dalam bentuk JAM */

	// KAMUS
	long N;
	
		// ALGORITMA
		N = JAMToDetik(J);
		return(DetikToJAM(++N));

}

JAM NextNDetik (JAM J, int N)
{
/* Mengirim N detik setelah J dalam bentuk JAM */

	// KAMUS
	long temp;
	
		// ALGORITMA
		temp = JAMToDetik(J);
		return(DetikToJAM(temp + N));
		
}

JAM PrevDetik (JAM J)
{
/* Mengirim 1 detik sebelum J dalam bentuk JAM */

	// KAMUS
	long N;
	
		// ALGORITMA
		N = JAMToDetik(J);
		
		if (N < 1)
		{
			N = N + 86400;
		}
		
		return(DetikToJAM(--N));
		
}

JAM PrevNDetik (JAM J, int N)
{
/* Mengirim N detik sebelum J dalam bentuk JAM */
/* *** Kelompok Operator Aritmetika *** */

	// KAMUS
	long temp;
	
		// ALGORITMA
		temp = JAMToDetik(J);
		
		if ((temp - N) < 0)
		{
			temp = temp + 86400;
		}
		
		return(DetikToJAM(temp - N));

}

long Durasi (JAM JAw, JAM JAkh)
{
/* Mengirim JAkh-JAw dlm Detik, dengan kalkulasi */
/* Jika JAw > JAkh, maka JAkh adalah 1 hari setelah JAw */

	// KAMUS
	long awal, akhir;
	
		// ALGORITMA
		awal = JAMToDetik(JAw);
		akhir = JAMToDetik(JAkh);
		if (awal <= akhir)
		{
			return(akhir - awal);
		}
		else if(awal > akhir)
		{
			return(akhir + 86400 - awal);
		}
		
}
