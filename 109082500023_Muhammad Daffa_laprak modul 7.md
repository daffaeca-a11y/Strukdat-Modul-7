# <h1 align="center">Laporan Praktikum Modul 7 - Stack</h1>
<p align="center">Muhammad Daffa Sha'ib Nandana - 109082500023</p>

## Dasar Teori
Teori yang dipakai adalah penyisipan terurut menggunakan stack bantu. Karena stack hanya bisa diakses dari puncak, elemen yang lebih besar dari data baru dipindahkan sementara ke stack temp, data baru disisipkan, lalu elemen dari temp dikembalikan. Hasilnya, isi stack dari dasar ke puncak selalu terurut menaik: 2, 3, 3, 4, 8, 9. Karena dicetak dari puncak, tampil [TOP] 9 8 4 3 3 2. Angka 3 muncul dua kali karena kondisi S.info[S.top] > x memakai tanda “lebih besar” (bukan “lebih besar sama dengan”), sehingga nilai kembar tetap disimpan.



## Unguided 

### 1. Struktur data pada stack.h

#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

#include <iostream>
using namespace std;

const int MAX_STACK = 20;

typedef int infotype;

struct Stack {
    infotype info[MAX_STACK];
    int top;           
};

void createStack(Stack &S);
bool isEmpty(const Stack &S);
bool isFull(const Stack &S);
void push(Stack &S, infotype x);
infotype pop(Stack &S);
void printInfo(const Stack &S);
void balikStack(Stack &S);
void pushAscending(Stack &S, infotype x);
void getInputStream(Stack &S);

#endif 

##### Output 1
![Screenshot Output Unguided 1_1] https://github.com/daffaeca-a11y/Strukdat-Modul-7/blob/main/outpu%20modul%207.jpeg

Pada bagian awal, terdapat #ifndef, #define, dan #endif yang berfungsi sebagai include guard. Bagian ini mencegah file header yang sama ter-include lebih dari sekali dalam satu program sehingga tidak terjadi error akibat deklarasi ganda. Setelah itu, #include <iostream> dan using namespace std; digunakan agar program bisa melakukan input dan output seperti cin dan cout tanpa harus menulis std:: di depannya.


### 2. Struktur data pada stack.cpp

#include <iostream>
#include "stack.h"
using namespace std;

void createStack(Stack &S) {
    S.top = -1;
}

bool isEmpty(const Stack &S) {
    return S.top == -1;
}

bool isFull(const Stack &S) {
    return S.top == MAX_STACK - 1;
}

void push(Stack &S, infotype x) {
    if (isFull(S)) {
        cout << "Stack penuh" << endl;
        return;
    }
    S.top++;
    S.info[S.top] = x;
}

infotype pop(Stack &S) {
    if (isEmpty(S)) {
        cout << "Stack kosong" << endl;
        return -1;
    }
    infotype x = S.info[S.top];
    S.top--;
    return x;
}

void printInfo(const Stack &S) {
    cout << "[TOP] ";
    for (int i = S.top; i >= 0; i--) {
        cout << S.info[i] << " ";
    }
    cout << endl;
}

void balikStack(Stack &S) {
    int i = 0;
    int j = S.top;
    while (i < j) {
        infotype temp = S.info[i];
        S.info[i] = S.info[j];
        S.info[j] = temp;
        i++;
        j--;
    }
}

void pushAscending(Stack &S, infotype x) {
    if (isFull(S)) {
        cout << "Stack penuh" << endl;
        return;
    }

    Stack temp;
    createStack(temp);

    while (!isEmpty(S) && S.info[S.top] > x) {
        push(temp, pop(S));
    }

    push(S, x);

    while (!isEmpty(temp)) {
        push(S, pop(temp));
    }
}

void getInputStream(Stack &S) {
    int c = cin.get();
    while (c != '\n' && c != EOF && !isFull(S)) {
        if (c >= '0' && c <= '9') {
            push(S, c - '0');
        }
        c = cin.get();
    }
}

##### Output 2
![Screenshot Output Unguided 2_1] https://github.com/daffaeca-a11y/Strukdat-Modul-7/blob/main/outpu%20modul%207.jpeg

Kode di atas adalah file implementasi (stack.cpp) yang berisi isi atau logika dari semua fungsi yang sebelumnya hanya dideklarasikan di stack.h. Pada bagian awal, file ini meng-include iostream untuk input/output dan "stack.h" agar mengenali struktur Stack, konstanta MAX_STACK, serta prototipe fungsinya.

### 3. Main.cpp

#include <iostream>
#include "stack.h"
using namespace std;

int main() {
    Stack S;

    
    cout << "=== Latihan 1 ===" << endl;
    cout << "Hello world!" << endl;
    createStack(S);
    push(S, 3);
    push(S, 4);
    push(S, 8);
    pop(S);
    push(S, 2);
    push(S, 3);
    pop(S);
    push(S, 9);
    printInfo(S);
    cout << "balik stack" << endl;
    balikStack(S);
    printInfo(S);

    cout << "\n=== Latihan 2 ===" << endl;
    cout << "Hello world!" << endl;
    createStack(S);
    pushAscending(S, 3);
    pushAscending(S, 4);
    pushAscending(S, 8);
    pushAscending(S, 2);
    pushAscending(S, 3);
    pushAscending(S, 9);
    printInfo(S);
    cout << "balik stack" << endl;
    balikStack(S);
    printInfo(S);

  
    cout << "\n=== Latihan 3 ===" << endl;
    cout << "Hello world!" << endl;
    createStack(S);
    getInputStream(S);
    printInfo(S);
    cout << "balik stack" << endl;
    balikStack(S);
    printInfo(S);

    return 0;
}

##### Output 3
![Screenshot Output Unguided 3_1] https://github.com/daffaeca-a11y/Strukdat-Modul-7/blob/main/outpu%20modul%207.jpeg

Kode di atas adalah file utama (main.cpp) yang berfungsi menjalankan dan menguji fungsi-fungsi yang sudah dibuat di stack.h dan stack.cpp. File ini meng-include iostream dan "stack.h", lalu di dalam fungsi main dibuat satu variabel stack bernama S yang dipakai bergantian untuk tiga latihan. Setiap latihan diawali dengan mencetak judul dan tulisan “Hello world!”, kemudian memanggil createStack(S) agar stack kembali kosong sebelum dipakai lagi.

## Kesimpulan
Berdasarkan ketiga kode (stack.h, stack.cpp, dan main.cpp) serta output yang dihasilkan, dapat disimpulkan bahwa Stack berhasil diimplementasikan sebagai Abstract Data Type (ADT) menggunakan struct dan array dalam bahasa C++, dengan kapasitas maksimum 20 elemen dan variabel top sebagai penunjuk elemen teratas, di mana nilai top = -1 menandakan stack kosong. Prinsip LIFO (Last In, First Out) terbukti berjalan dengan benar. Pada Latihan 1, elemen yang terakhir dimasukkan, seperti angka 8 dan 3, adalah yang pertama dikeluarkan oleh pop, sehingga isi akhir stack adalah 3, 4, 2, 9 dan ditampilkan sebagai [TOP] 9 2 4 3. Operasi dasar stack, yaitu createStack, isEmpty, isFull, push, pop, dan printInfo, juga bekerja sesuai fungsinya, termasuk penanganan kondisi stack overflow dan stack underflow melalui pengecekan isFull dan isEmpty.

## Referensi
[1] Triase. (2020). Diktat Edisi Revisi : STRUKTUR DATA. Medan: UNIVERSTAS ISLAM NEGERI SUMATERA UTARA MEDAN. 
<br>[2] Indahyati, Uce., Rahmawati Yunianita. (2020). "BUKU AJAR ALGORITMA DAN PEMROGRAMAN DALAM BAHASA C++". Sidoarjo: Umsida Press. Diakses pada 10 Maret 2024 melalui https://doi.org/10.21070/2020/978-623-6833-67-4.

