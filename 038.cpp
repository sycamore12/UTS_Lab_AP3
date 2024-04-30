// TODO 1: Ubah nama file ini menjadi NIM Anda. Cth: 001.cpp, 042.cpp, 080.cpp

// TODO 2: Buat program anda di file ini. INGAT BERI KOMENTAR PADA SETIAP PROSES DALAM PROGRAM ANDA

// TODO 3: Selesaikan dan kumpulkan sebelum deadline yang telah ditentukan; Details ada dalam file README.md

// Tetap semangat walau sulit ;p

#include <iostream>
#include <string>
using namespace std;

/*fungsi utk mengecek validitas dari nomor kartu menggunakan algoritma Luhn*/
bool cekValid(long long nomor) {
    int jumlah = 0;
    bool ganda = false;

    /*menghitung checksum*/
    while (nomor > 0) {
        int digit = nomor % 10;

        if (ganda) {
            digit *= 2;
            if (digit > 9)
                digit = (digit % 10) + 1;
        }

        jumlah += digit;
        ganda = !ganda;
        nomor /= 10;
    }

    return (jumlah % 10 == 0);
}

/*fungsi utk menentukan tipe kartu*/
string cekTipe(long long nomor) {
    string tipe;

    if ((nomor >= 4000000000000 && nomor <= 4999999999999) ||
        (nomor >= 4000000000000000 && nomor <= 4999999999999999)) {
        if (cekValid(nomor))
            tipe = "VISA";
    } 
    else if ((nomor >= 5100000000000000 && nomor <= 5599999999999999) ||
             (nomor >= 2221000000000000 && nomor <= 2720999999999999)) {
        if (cekValid(nomor))
            tipe = "MASTERCARD";
    } 
    else {
        tipe = "Tidak Diketahui";
    }

    return tipe;
}

int main() {
    long long nomorKartu;

    cout << "Masukkan nomor kartu kredit Anda: ";
    cin >> nomorKartu;

    string tipe = cekTipe(nomorKartu);

    if (tipe != "Tidak Diketahui") {
        cout << "Nomor kartu: " << nomorKartu << endl;
        cout << "Jenis kartu: " << tipe << endl;
        cout << "Checksum: "<< cekValid << endl;
    } 
    else {
        cout << "Nomor kartu: " << nomorKartu << endl;
        cout << "Nomor tidak valid." << endl;
    }

    return 0;
}
