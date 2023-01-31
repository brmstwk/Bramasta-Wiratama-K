#include <iostream>
#include <stdlib.h>
using namespace std;

struct customer{
    string nama,
         alamat;
    char nomorhp[30], nip[30];
};


void judul(){
    cout << "=====================================================================" << endl;
    cout << "           HALLO! SELAMAT DATANG DI PROGRAM JASA LAUNDRY            " << endl;
    cout << "                       GAKATSU LAUNDRY PAKAIAN                       " << endl;
    cout << "=====================================================================" << endl;
}

void penutup(){
    cout << "=====================================================================" << endl;
    cout << "           TERIMA KASIH TELAH BERKUNJUNG DI PROGRAM INI              " << endl;
    cout << "       MOHON MAAF JIKA ANDA KURANG NYAMAN PADA LAYANAN KAMI          " << endl;
    cout << "=====================================================================" << endl;
};

int main(){
    int kode,tambah;
    char ulang,kembali,kategori,akhir;
    int harga [3]={8000,12000,15000},j=0;
    int berat,total,jumlah,bayar,kurang,potongan,saldo,kembalian;
    double jum_diskon;
    string jenis;
    customer cus[50];
    judul ();

    do{
    cout << "=====================================================" << endl;
    cout << "               Input Data Pelanggan                  " << endl;
    cout << "=====================================================" << endl;
    cout << "NIP \t : "; cin >> cus[0].nip;
    cout << "Nama \t : "; cin >> cus[0].nama;
    cout << "Alamat \t : "; cin >> cus[0].alamat;
    cout << "Nomor HP : "; cin >> cus[0].nomorhp;
    cout << "=====================================================" << endl;
    cout << endl;
    system ("CLS");
    kategori:
    cout << "=====================================================" << endl;
    cout << "KATEGORI CUCIAN" << endl;
    cout << "=====================================================" << endl;
    cout << "1. REGULER Rp.8.000/Kg " << endl;
    cout << "2. EXPRESS Rp.12.000/Kg " << endl;
    cout << "3. KILAT Rp.15.000/Kg " << endl;
    cout << "=====================================================" << endl;
    cout << "*Note : Jika Total Laundry>=50000, Dapat diskon 10%   " << endl;
    cout << "        Jika Total Laundry>=100000,Dapat diskon 25% " << endl;
    cout << "        Jika Total Laundry>=150000,Dapat diskon 35% " << endl;
    cout << "=====================================================" << endl;
    cout << "Pilih Kategori [1/2/3]\t\t: "; cin >> kode;
    switch (kode){
        case 1:
            jenis="Cuci Reguler";
            break;

        case 2:
            jenis="Cuci Express";
            j=1;
            break;

        case 3:
            jenis="Cuci Kilat";
            j=2;
            break;

        default:
            cout << "Kode Yang Anda Masukkan Salah!!" << endl;
            cout << "Input Lagi(y/t)\t: "; cin >> ulang;
            system ("ClS");
                if (ulang == 'Y' || ulang == 'y'){
                    goto kategori;
                } else {
                    goto akhir;
                }
            break;
        }

    cout << "Berat Cucian (Kg)\t\t: "; cin >> berat;
    system ("CLS");
    cout << "                     NOTA PEMBAYARAN LAUNDRY                      " << endl;
    cout << endl;
    cout << "==================================================================" << endl;
    cout << "                     GAKATSU LAUNDRY PAKAIAN                      " << endl;
    cout << "                     LAUNDRY PAKAIAN TERMURAH                     " << endl;
    cout << "==================================================================" << endl;
    cout << "NIP\t\t\t: " << cus[0].nip << endl;
    cout << "Nama\t\t\t: " << cus[0].nama << endl;
    cout << "Alamat\t\t\t: " << cus[0].alamat << endl;
    cout << "No HandPhone\t\t: " << cus[0].nomorhp << endl;
    cout << endl;
    cout << "Kode Kategori \t\t: " << kode << endl;
    cout << "Jenis Layanan \t\t: " << jenis << endl;
    cout << "Berat Pakaian (Kg)\t: " << berat << endl;
    cout << "Harga Cucian \t\t: " << harga[j] <<"/Kg" << endl;
    total=harga[j] * berat;
    cout << "Biaya \t\t\t: " << "Rp." << total << endl;
    cout << endl;
        if(total > 150000){
            potongan=total * 0.15;
            cout << "Selamat Anda Mendapatkan Diskon 15%" << endl;
            jumlah=total-potongan;
            cout << "Total Semua : Rp " << jumlah << "\n\n";
        } else if (total > 100000){
            potongan=total * 0.10;
            cout << "Selamat Anda Mendapatkan Diskon 10%" << endl;
            jumlah=total-potongan;
            cout << "Total Semua : Rp " << jumlah << "\n\n";
        } else if(total > 50000){
            potongan=total * 0.05;
            cout << "Selamat Anda Mendapatkan Diskon 5%" << endl;
            jumlah=total-potongan;
            cout << "Total Semua : Rp " << jumlah << "\n\n";
        } else {
            jumlah=total;
            cout << "Total Anda\t\t: Rp " << jumlah << endl;
        }
        cout << "Uang Anda\t\t: "; cin >> saldo;
        cout << endl;
        while (saldo<jumlah){
            cout << "Maaf Uang Anda Kurang, Silahkan Bayar Kembali" << endl;
            cout << "Uang Tambahan Anda\t: Rp. "; cin >> kurang;
            saldo+=kurang;
        };

        kembalian=saldo-jumlah;
        cout << "Kembalian\t\t: Rp." << kembalian << endl;\
        cout << endl;
        cout << "Ada Tambahan ?(y/n)\t: "; cin >> kembali;

    ulang;
    system ("CLS");
        }while(kembali=='Y'|| kembali=='y');
    cout << endl;
    akhir:
    penutup();
}
