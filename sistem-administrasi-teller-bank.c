#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// definisi struct untuk Node linkedlist Nasabah
typedef struct Node {
    int id; // ID Nasabah
    char nama[50]; // Nama Nasabah
    struct Node*next; // Pointer untuk ke Node berikutnya
} Node;

// definisi struct untuk Queue
typedef struct Queue {
    Node*front;
    Node*rear;
} Queue;

// definisi struct untuk Stack
typedef struct Stack {
    Node*top;
} Stack;

// fungsi untuk membuat Node baru
Node* createNode (int id, char* nama) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode -> id = id;
    strcpy(newNode -> nama, nama);
    newNode -> next = NULL;

    return newNode;
}

// fungsi initQueue

// fungsi enQueue - tambahkan Nasabah

// fungsi deQueue - Nasabah selesai dilayani

// fungsi printQueue - tampilkan antrian Nasabah

// fungsi initStack

// fungsi push Stack - 

// fungsi pop Stack

// fungsi printStack

// fungsi main
int main () {
    
    int choice, id;
    char nama[50];

    printf("Selamat Datang di Sistem Administrasi Teller Bank Sejahtera\n");

    do {
        printf("\n===== OPSI MENU ADMINISTRASI =====\n");
        printf("1. Tambahkan Nasabah ke antrian\n");
        printf("2. Layani Nasabah\n");
        printf("3. Tampilkan antrian Nasabah\n");
        printf("4. Tampilkan riwayat pelayanan\n");
        printf("5. Hapus riwayat pelayanan\n");
        printf("6. Keluar\n");
        printf("Silahkan masukkan pilihan Anda: ");
        scanf("%d", choice);

        switch (choice) {
            case 1:
                printf("Masukkan ID Nasabah: ");
                scanf("%d", id);
                printf("Masukkan Nama Nasabah: ");
                scanf("%[^\n]s", nama);
            //enqueue
            break;

            case 2:
                // dequeue + push stack
            break;

            case 3:
                // print queue
            break;

            case 4:
                // printstack
            break;

            case 5:
                // pop stack
            break;

            case 6:
                printf ("Terimakasih telah menggunakan sistem administrasi Teller\n");
            break;

            default:
                printf("Pilihan tidak ada dalam opsi!//INVALID//\n)");
        }
    } while (choice!=6);
    
    
    return 0;
}