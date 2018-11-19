/* File : queue.h */
/* Definisi ADT Queue dengan representasi array secara eksplisit dan alokasi dinamik */
/* Model Implementasi Versi III dengan circular buffer */

#include "boolean.h"
#include "queue.h"
#include <stdlib.h>
/* Konstanta untuk mendefinisikan address tak terdefinisi */

/* Definisi elemen dan address */
/* ********* Prototype ********* */
boolean IsEmptyQue (Queue Q){
/* Mengirim true jika Q kosong: lihat definisi di atas */
	if((HeadQue(Q) == Nil) && (TailQue(Q) == Nil)){
		return true;
	} else {
		return false;
	}
}

boolean IsFullQue (Queue Q){
/* Mengirim true jika tabel penampung elemen Q sudah penuh */
/* yaitu mengandung elemen sebanyak MaxEl */
	if(HeadQue(Q) == 1){
		return (TailQue(Q) == MaxElQue(Q));
	} else return (TailQue(Q) == (HeadQue(Q) - 1));
}

int NBElmtQue (Queue Q){
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong. */
	if(IsEmptyQue(Q)){
		return 0;
	} else {
		if(TailQue(Q) >= HeadQue(Q))
			return (TailQue(Q) - HeadQue(Q) + 1);
		else 
			return (MaxElQue(Q) - HeadQue(Q) + TailQue(Q) + 1);
	}
}
/* *** Kreator *** */
void CreateEmptyQue (Queue * Q, int Max){
/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk dan salah satu kondisi sbb: */
/* Jika alokasi berhasil, Tabel memori dialokasi berukuran Max+1 */
/* atau : jika alokasi gagal, Q kosong dg MaxEl=0 */
/* Proses : Melakukan alokasi, membuat sebuah Q kosong */
	(*Q).T = (infotypeQue *) malloc ((Max+1) * sizeof(infotypeQue));
	if ((*Q).T != NULL) {
		MaxElQue(*Q) = Max;
		HeadQue(*Q) = Nil;
		TailQue(*Q) = Nil;
	} else /* alokasi gagal */ {
		MaxElQue(*Q) = 0;
	}
}
/* *** Destruktor *** */
void DeAlokasiQue(Queue * Q){
/* Proses: Mengembalikan memori Q */
/* I.S. Q pernah dialokasi */
/* F.S. Q menjadi tidak terdefinisi lagi, MaxEl(Q) diset 0 */
	MaxElQue(*Q) = 0;
	free((*Q).T); 
}
/* *** Primitif Add/Delete *** */
void AddQue (Queue * Q, infotypeQue X){
/* Proses: Menambahkan X pada Q dengan aturan FIFO */
/* I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh */
/* F.S. X menjadi TailQue yang baru, TailQue "maju" dengan mekanisme circular buffer */
	address i, j;
	 /* Algoritma */
	if (IsEmptyQue(*Q)) {
		HeadQue(*Q)=1;
	} else /* Q tidak kosong */ {
		if(TailQue(*Q) == MaxElQue(*Q)){
			TailQue(*Q) = 0;
		}
	}
	TailQue(*Q)++;
	InfoTailQue(*Q)=X;
}

void DelQue (Queue * Q, infotypeQue * X){
/* Proses: Menghapus X pada Q dengan aturan FIFO */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = nilai elemen HeadQue pd I.S., HeadQue "maju" dengan mekanisme circular buffer; 
        Q mungkin kosong */
	 *X = InfoHeadQue(*Q);
	 if (HeadQue(*Q)==TailQue(*Q)) { /* Set mjd queue kosong */
	 	CreateEmptyQue(Q,MaxElQue(*Q));
	 }
	 else {
	 	if(HeadQue(*Q) == MaxElQue(*Q)) HeadQue(*Q) = 1;
	 	else HeadQue(*Q)++;
	 }
}

void TulisFileQue (Queue Q,FILE *f){
	infotypeQue X;
	while(!IsEmptyQue){
		DelQue (&Q,&X);
		fprintf(f,"%d ",X.id);
		TulisFileJam(X.Jam,f);
		fprintf(f,"\n");
	}
}