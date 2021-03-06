/* File : queue.h */
/* Definisi ADT Queue dengan representasi array secara eksplisit dan alokasi dinamik */
/* Model Implementasi Versi III dengan circular buffer */

#ifndef queue_H
#define queue_H
#include "../boolean/boolean.h"
#include "../jam/jam.h"

#define Nil 0
#define IdxMaxQue 20
/* Konstanta untuk mendefinisikan address tak terdefinisi */

/* Definisi elemen dan address */

typedef int address;   /* indeks tabel */
/* Contoh deklarasi variabel bertype Queue : */
/* Versi I : tabel dinamik, Head dan Tail eksplisit, ukuran disimpan */

/* Definisi Queue kosong: HEAD=Nil; TAIL=Nil. */
/* Catatan implementasi: T[0] tidak pernah dipakai */
typedef struct { int id;
				 Waktu Jam;
				} queCustomer;
				
typedef queCustomer infotypeQue;

typedef struct { infotypeQue T[IdxMaxQue+1];   /* tabel penyimpan elemen */
                 address HEAD;  /* alamat penghapusan */
                 address TAIL;  /* alamat penambahan */
                 int MaxEl;     /* Max elemen queue */
               } Queue;
/* ********* AKSES (Selektor) ********* */
/* Jika Q adalah Queue, maka akses elemen : */
#define HeadQue(Q) (Q).HEAD
#define TailQue(Q) (Q).TAIL
#define InfoHeadQue(Q) (Q).T[(Q).HEAD]
#define InfoTailQue(Q) (Q).T[(Q).TAIL]
#define MaxElQue(Q) (Q).MaxEl

/* ********* Prototype ********* */
boolean IsEmptyQue (Queue Q);
/* Mengirim true jika Q kosong: lihat definisi di atas */
boolean IsFullQue (Queue Q);
/* Mengirim true jika tabel penampung elemen Q sudah penuh */
/* yaitu mengandung elemen sebanyak MaxEl */
int NBElmtQue (Queue Q);
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong. */

/* *** Kreator *** */
void CreateEmptyQue (Queue * Q, int Max);
/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk dan salah satu kondisi sbb: */
/* Jika alokasi berhasil, Tabel memori dialokasi berukuran Max+1 */
/* atau : jika alokasi gagal, Q kosong dg MaxEl=0 */
/* Proses : Melakukan alokasi, membuat sebuah Q kosong */

/* *** Destruktor *** */
void DeAlokasiQue(Queue * Q);
/* Proses: Mengembalikan memori Q */
/* I.S. Q pernah dialokasi */
/* F.S. Q menjadi tidak terdefinisi lagi, MaxEl(Q) diset 0 */

/* *** Primitif Add/Delete *** */
void AddQue (Queue * Q, infotypeQue X);
/* Proses: Menambahkan X pada Q dengan aturan FIFO */
/* I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh */
/* F.S. X menjadi TAIL yang baru, TAIL "maju" dengan mekanisme circular buffer */
void DelQue (Queue * Q, infotypeQue * X);
/* Proses: Menghapus X pada Q dengan aturan FIFO */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = nilai elemen HEAD pd I.S., HEAD "maju" dengan mekanisme circular buffer; 
        Q mungkin kosong */
		
void Del2Que (Queue * Q, infotypeQue *X);

void TulisFileQue (Queue Q,FILE *f);
		
void PrintQue (Queue Q);

boolean IsAdaDuaQue(Queue Q);

#endif