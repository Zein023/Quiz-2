#include <stdio.h>
#include <stdlib.h>
#include "linked.h"
#include <malloc.h>

int main() {
    address head = NULL;
    address newNode;
    infotype nilai;

    // Insert awal
    printf("Insert awal: ");
    Create_Node(&newNode);
    scanf("%d", &nilai);
    Isi_Node(&newNode, nilai);
    Ins_Awal(&head, newNode);
    Tampil_List(head);
    
    // Insert akhir
    printf("Insert akhir: ");
    Create_Node(&newNode);
    scanf("%d", &nilai);
    Isi_Node(&newNode, nilai);
    Ins_Akhir(&head, newNode);
    Tampil_List(head);
    
    // Insert after
    printf("Insert after: ");
    Create_Node(&newNode);
    scanf("%d", &nilai);
    Isi_Node(&newNode, nilai);
    InsertAfter(&head, newNode);
    Tampil_List(head);
    
    // Insert awal
    printf("Insert awal: ");
    Create_Node(&newNode);
    scanf("%d", &nilai);
    Isi_Node(&newNode, nilai);
    Ins_Awal(&head, newNode);
    Tampil_List(head);
    
    // Insert akhir
    printf("Insert awal: ");
    Create_Node(&newNode);
    scanf("%d", &nilai);
    Isi_Node(&newNode, nilai);
    Ins_Akhir(&head, newNode);
    Tampil_List(head);
    
    // Delete akhir
    printf("Delete akhir: \n");
    Del_Akhir(&head, &nilai);
    Tampil_List(head);
    
    // Delete value
    Del_Value(&head, &nilai);
    Tampil_List(head);
    
    // Delete awal
    Del_Awal(&head, &nilai);
    Tampil_List(head);
    
    // Delete ganjil
    DeAlokasi(&head);
    Tampil_List(head);
    


    return 0;
}
