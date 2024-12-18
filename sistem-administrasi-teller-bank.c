#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// definisi struct untuk Node linkedlist Nasabah
typedef struct Node {
    int id;             // ID Nasabah
    char nama[50];      // Nama Nasabah
    struct Node* next;  // Pointer untuk ke Node berikutnya
} Node;

// definisi struct untuk Node double-linkedlist Nasabah kemarin
typedef struct DoubleNode {
    int id;
    char nama[50];
    struct DoubleNode* prev;
    struct DoubleNode* next;
} DoubleNode;

// definisi struct untuk Queue
typedef struct Queue {
    Node* front;
    Node* rear;
} Queue;

// definisi struct untuk Stack
typedef struct Stack {
    Node* top;
} Stack;

// Data statis untuk double-linkedlist Nasabah kemarin
DoubleNode* initStaticDoubleLinkedList() {
    DoubleNode* head = NULL;
    DoubleNode* tail = NULL;
    int staticData[3] = {101, 102, 103};
    char* staticNames[3] = {"Adam", "Bryan", "Chelsea"};

    for (int i = 0; i < 3; i++) {
        DoubleNode* newNode = (DoubleNode*)malloc(sizeof(DoubleNode));
        newNode->id = staticData[i];
        strcpy(newNode->nama, staticNames[i]);
        newNode->next = NULL;
        newNode->prev = tail;

        if (tail != NULL) {
            tail->next = newNode;
        } else {
            head = newNode;  // First node
        }
        tail = newNode;
    }
    return head;
}

// fungsi untuk membuat Node baru
Node* createNode(int id, char* nama) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->id = id;
    strcpy(newNode->nama, nama);
    newNode->next = NULL;

    return newNode;
}

// fungsi initQueue
void initQueue(Queue* queue) {
    queue->front = NULL;
    queue->rear = NULL;
}

// fungsi enQueue - tambahkan Nasabah
void enQueue(Queue* queue, int id, char* nama) {
    Node* newNode = createNode(id, nama);
    if (queue->rear == NULL) {
        queue->front = queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
    printf("Nasabah dengan ID %d dan nama %s telah ditambahkan ke antrian.\n", id, nama);
}

// fungsi deQueue - Nasabah selesai dilayani
Node* deQueue(Queue* queue) {
    if (queue->front == NULL) {
        printf("Antrian kosong. Tidak ada Nasabah yang dilayani.\n");
        return NULL;
    }

    Node* temp = queue->front;
    queue->front = queue->front->next;

    if (queue->front == NULL) {
        queue->rear = NULL;
    }

    temp->next = NULL;
    printf("Nasabah dengan ID %d dan nama %s selesai dilayani.\n", temp->id, temp->nama);
    return temp;
}

// fungsi printQueue - tampilkan antrian Nasabah
void printQueue(Queue* queue) {
    if (queue->front == NULL) {
        printf("Antrian kosong.\n");
        return;
    }
    Node* temp = queue->front;
    printf("Daftar antrian Nasabah:\n");
    while (temp != NULL) {
        printf("ID: %d, Nama: %s\n", temp->id, temp->nama);
        temp = temp->next;
    }
}

// fungsi initStack
void initStack(Stack* stack) {
    stack->top = NULL;
}

// fungsi push Stack
void push(Stack* stack, Node* nasabah) {
    if (nasabah == NULL) {
        return;
    }

    nasabah->next = stack->top;
    stack->top = nasabah;
    printf("Nasabah dengan ID %d dan nama %s telah ditambahkan ke riwayat pelayanan (Stack).\n", nasabah->id, nasabah->nama);
}

// fungsi pop Stack
Node* pop(Stack* stack) {
    if (stack->top == NULL) {
        printf("Riwayat pelayanan kosong.\n");
        return NULL;
    }
    Node* temp = stack->top;
    stack->top = stack->top->next;
    temp->next = NULL;
    printf("Nasabah dengan ID %d dan nama %s dihapus dari riwayat pelayanan (Stack).\n", temp->id, temp->nama);
    free(temp);
    return temp;
}

// fungsi printStack - tampilkan data Stack
void printStack(Stack* stack) {
    if (stack->top == NULL) {
        printf("Riwayat pelayanan kosong.\n");
        return;
    }
    Node* temp = stack->top;
    printf("Riwayat pelayanan Nasabah hari ini:\n");
    while (temp != NULL) {
        printf("ID: %d, Nama: %s\n", temp->id, temp->nama);
        temp = temp->next;
    }
}

// fungsi printDoubleLinkedList - tampilkan riwayat kemarin
void printDoubleLinkedList(DoubleNode* head) {
    if (head == NULL) {
        printf("Riwayat Nasabah kemarin kosong.\n");
        return;
    }
    DoubleNode* temp = head;
    printf("Riwayat Nasabah kemarin:\n");
    while (temp != NULL) {
        printf("ID: %d, Nama: %s\n", temp->id, temp->nama);
        temp = temp->next;
    }
}

// fungsi main
int main() {
    Queue queue;
    Stack stack;
    DoubleNode* kemarin = initStaticDoubleLinkedList();  // Data statis Nasabah kemarin

    initQueue(&queue);
    initStack(&stack);

    int choice, id;
    char nama[50];

    printf("Selamat Datang di Sistem Administrasi Teller Bank Sejahtera\n");

    do {
        system("cls");
        printf("\n===== OPSI MENU ADMINISTRASI =====\n");
        printf("1. Tambahkan Nasabah ke antrian\n");
        printf("2. Layani Nasabah\n");
        printf("3. Tampilkan antrian Nasabah\n");
        printf("4. Tampilkan riwayat pelayanan\n");
        printf("5. Hapus riwayat pelayanan\n");
        printf("6. Keluar\n");
        printf("Silahkan masukkan pilihan Anda: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1: {
                printf("Masukkan ID Nasabah: ");
                scanf("%d", &id);
                getchar();
                printf("Masukkan Nama Nasabah: ");
                fgets(nama, sizeof(nama), stdin);
                nama[strcspn(nama, "\n")] = 0;
                enQueue(&queue, id, nama);
                getch();
                break;
            }
            case 2: {  // Iqbal
                Node* nasabahDilayani = deQueue(&queue);
                push(&stack, nasabahDilayani);
                getch();
                break;
            }
            case 3:
                printQueue(&queue);
                getch();
                break;
            case 4:  // tsabit
            {
                int riwayatPilihan;
                printf("Silahkan pilih riwayat transaksi yang ingin ditampilkan:\n");
                printf("1. Hari ini (Stack)\n");
                printf("2. Kemarin (Double Linked List)\n");
                printf("3. Semua Riwayat\n");
                scanf("%d", &riwayatPilihan);

                switch (riwayatPilihan) {
                    case 1:
                        printStack(&stack);
                        break;
                    case 2:
                        printDoubleLinkedList(kemarin);
                        break;
                    case 3:
                        printStack(&stack);
                        printDoubleLinkedList(kemarin);
                        break;
                    default:
                        printf("Pilihan tidak valid!\n");
                }
                getch();
                break;
            }
            case 5:  // rama
                pop(&stack);
                getch();
                break;
            case 6:
                printf("Terimakasih telah menggunakan sistem administrasi Teller\n");
                break;
            default:
                printf("Pilihan tidak ada dalam opsi! //INVALID//\n");
        }
    } while (choice != 6);

    return 0;
}
