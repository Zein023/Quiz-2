#include <stdio.h>
#include "linked.h"
//#define info(p) (p)->info
//#define next(p) (p)->next

boolean isEmpty(address p){
	return p == NULL;
}
// Tujuan : memeriksa apakah linked masih kosong
// Linked list kosong , jika Head == NULL

void Create_Node (address *p){
	*p = (address) malloc(sizeof(ElmtList));
	
	if (isEmpty(*p)){
		printf("Alokasi tidak berhasil!\n");
	}else{
		(*p)->info = 0;
		(*p)->next = NULL;
	}
}
// Tujuan : memesan memory dengan alokasi dinamis
// Jika berhasil mengirimkan address, dan jika gagal mengirimkan NULL
// Parameter : P (parameter Output)

void Isi_Node (address *p , infotype nilai){
	if(!isEmpty(*p)){
		(*p)->info = nilai;
		(*p)->next = NULL;
	} else {
		printf("Node belum dialokasikan!\n");
	}
}
// Tujuan : Mengisi node yang sudah dipesan dengan Nilai yang dikirimkan
// Periksa keberadaan P, Nilai diisi jika P tidak NULL
//				*p.next diisi NULL
// Parameter : P (parameter Input-Output); Nilai (parameter Input)

void Tampil_List (address p){
	address temp = p;
	while (!isEmpty(temp)){
		printf("%d -> ", temp->info);
		temp = temp->next; // Pergi ke node berikutnya
	}
	printf("NULL\n");
}
// Tujuan : Menampilkan seluruh isi Linked List
// Parameter : p (parameter input)

void Ins_Awal (address *p, address PNew){
	if (!isEmpty(PNew)){
		PNew->next =  *p;
		*p = PNew;
	} 
}
// Tujuan : Insert 1 node baru (PNew) di awal Linked List
// Parameter : P (input-output)
//             PNew (input)

void Ins_Akhir (address *p, address PNew){
	if (isEmpty(*p)) { 
        *p = PNew;
    } else {
        address temp = *p;
        while (!isEmpty(temp->next)){
            temp = temp->next;
        }
        temp->next = PNew;
    }
    PNew->next = NULL;
}
/* Tujuan : menambahkan elemen list (PNew) di akhir LinkedList */
/* IS : p mungkin Kosong */
/* FS : menyambungkan elemen baru (PNew) di akhir Linked List */

address Search (address p, infotype nilai){
	boolean cek;
	cek = false;
	while(!isEmpty(p)){
		if ((p->next)->info != nilai){
			p = p->next;
		} else {
			cek = true;
			break;
		}
	}
	
	if (cek == true){
		return p;
	} else {
		return NULL;
	}
}
/* Mencari apakah ada elemen list dengan Info(P) = nilai */
/* Jika ada, mengirimkan address elemen tsb. */
/* Jika tidak ada, mengirimkan Nil */
/* Menggunakan variabel bertype boolean */

void InsertAfter (address * pBef, address PNew){
 if (!isEmpty(*pBef)) {
        PNew->next = (*pBef)->next;
        (*pBef)->next = PNew;
    } else {
        printf("Error: pBef adalah NULL\n");
    }
}
/* Tujuan : Menyambungkan 1 Node baru(PNew) stlah node tertentu(PBef) */
/* IS : pBef sudah dialokasi */
/* FS : Insert PNew sebagai elemen sesudah PBef */
/* Asumsi : pBef adalah posisi insert */

void Del_Awal (address * p, infotype * X){
	if (!isEmpty(*p)){
        address temp = *p;  
        *X = temp->info;
        *p = temp->next;
        free(temp);
    } else {
        printf("Node tidak ada!\n");
    }
}
/* IS : P TIDAK Kosong */
/* FS : Elemen pertama List dihapus, nilai info disimpan ke X */
/* 	dan alamat elemen pertama di dealokasi */

void Del_Akhir (address * p, infotype * X){
	 if (isEmpty(*p)){
        printf("List kosong!\n");
        return;
    }

    address temp = *p;
    address prev = NULL;
    
    while (!isEmpty(temp->next)){
        prev = temp;
        temp = temp->next;
    }

    *X = temp->info;
    free(temp);

    if (prev == NULL) { 
        *p = NULL;
    } else {
        prev->next = NULL;
    }
}
/* IS : P TIDAK Kosong */
/* FS : Elemen terakhir list dihapus : nilai info disimpan pada X */
/* 	dan alamat elemen terakhir di dealokasi */

void Del_After (address * pBef, infotype * X){
	if (!isEmpty((*pBef)->next)){
		address temp = (*pBef)->next;	
		*X = temp->info;
		(*pBef)->next = temp->next;
		free(temp);
	} else {
		printf("Node yang ditunjuk pBef adalah NULL");
	}
}
/* IS : pBef TIDAK Kosong (hasil search posisi node sebelum yang didel)*/
/* FS : menghapus Node setelah pBef */
/*      nilai info node yang dihapus disimpan pada X */
/* 	  dan alamat elemen setelah pBef di dealokasi */

void DeAlokasi (address * p){
	address temp;
	
	if (!isEmpty(*p)){
		while (!isEmpty((*p)->next)){
			temp = (*p)->next;
			free(*p);
			*p = temp;	
		}
	} else {
		printf("Node tidak ada!\n");
	}

	printf("Semua node sudah di dealokasi!\n");
}
/* IS : P terdefinisi */
/* FS : P dikembalikan ke sistem */
/* Melakukan dealokasi / pengembalian address P ke system */

int NbElmt (address p){
	int count = 0;
	
	if (!isEmpty(p)){
		while (!isEmpty(p->next)){
			count++;
			p = p->next;
		} 
	}
	return count;
}
/* Mengirimkan banyaknya elemen list, mengirimkan 0 jika list kosong */
// Recursif Mode

infotype Min (address p){
	infotype temp = p->info;
	while(!isEmpty(p)){
		if (temp > p->info){
			temp = p->info;
		} else {
			p = p->next;
		}
	}
	return temp;
}
/* Mengirimkan nilai Info(P) yang minimum */

infotype Rerata (address p){
	infotype avg = 0;
	while(!isEmpty(p)){
		avg += p->info;
		p = p->next;
	}
	return avg;
}
/* Mengirimkan nilai rata-rata Info(P) */

address BalikList (address p){
	address prev = NULL;
	address current = p;
	address after = NULL;
	
	while (!isEmpty(current)){
		after = current->next; // Simpan next node
        current->next = prev;     // Balikkan arah pointer
        prev = current;           // Geser prev ke node sekarang
        current = after;       // Geser current ke node selanjutnya
	}
	
	return prev; // prev sekarang menjadi head baru
}
/* IS : p sembarang */
/* FS : Elemen List dibalik : elemen terakhir menjadi elemen pertama, dst */

void Del_Value (address *p, infotype *X){
	int value;
	printf("Masukkan value yang ingin dicari : ");
	scanf("%d", &value);
	*p = Search(*p, value);
	Del_After(p,X);
} 
