#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int jumlah_barang = 0;
int total_keseluruhan = 0;
int jumlah_transaksi = 0;

struct Transaksi {
	int total_belanja, jumlah_beli;
};

struct data_barang{
    string nama_brg, kode_brg;
    int stok_brg, harga_brg;
    Transaksi tr;
};

data_barang db[100];

// ERROR HANDLING
void errorInput() {
    cout << endl;
    cin.clear();
    cin.ignore(1000, '\n');
    cout << "Input tidak valid." << endl << endl;
    system("pause");
}

// PENDUKUNG
void saveData_Barang() {
    ofstream file("data_barang.txt", ios::trunc);
    if (!file.is_open()) {
        cout << "Error : Gagal membuka file untuk append!" << endl;
        return;
    }
    
    for (int i = 0; i < jumlah_barang; i++) {
        file << db[i].kode_brg << endl
             << db[i].nama_brg << endl
             << db[i].harga_brg << endl
             << db[i].stok_brg << endl << endl;
    }
    
    file.close();
}

void initData() {
    ifstream file("data_barang.txt"); 
    if (!file.is_open()) {
        cout << "File data_barang.txt tidak ditemukan! Memulai dengan data kosong." << endl << endl;
        jumlah_barang = 0;
        system("pause");
        system("cls");
        return;
    }

    jumlah_barang = 0;
    while (file >> db[jumlah_barang].kode_brg && jumlah_barang < 100) {
        file.ignore();
        file >> ws;
        getline(file, db[jumlah_barang].nama_brg);
        file >> db[jumlah_barang].harga_brg
             >> db[jumlah_barang].stok_brg;
        file.ignore();

        db[jumlah_barang].tr.jumlah_beli = 0;
        jumlah_barang++;
    }
    
    file.close();
}

int diskon(int kelipatan){
    if (kelipatan <= 0){
        return 0;
    } else {
        return (kelipatan * 300) + diskon(kelipatan - 1);
    }
}

void swapData(data_barang *a, data_barang *b) {
  data_barang temp = *a;
  *a = *b;
  *b = temp;
}

void kb_urut(data_barang db[]){
    for (int i = 0; i < jumlah_barang - 1; i++){
        for (int j = 0; j < jumlah_barang - i - 1; j++){
            if (db[j].kode_brg > db[j+1].kode_brg){
                swapData(&db[j], &db[j+1]);
            }
        }
    }

    cout << "===== Mengurutkan Barang dari Kode Terkecil ======" << endl << endl;
    for (int k = 0; k < jumlah_barang; k++){
        cout << "Kode Barang : " << db[k].kode_brg << endl
             << "| Nama Barang  : " << db[k].nama_brg << endl
             << "| Harga Barang : " << db[k].harga_brg << endl
             << "| Jumlah Ketersediaan Barang : " << db[k].stok_brg << endl 
             << endl;
    }

    if (jumlah_barang == 0){
        cout << "Data barang masih kosong." << endl;
    }
}

void hmurah_urut(data_barang db[]){
    for (int i = 0; i < jumlah_barang - 1; i++){
        for (int j = 0; j < jumlah_barang - i - 1; j++){
            if (db[j].harga_brg > db[j+1].harga_brg){
                swapData(&db[j], &db[j+1]);
            }
        }
    }

    cout << "===== Mengurutkan Barang dari Harga Termurah ======" << endl << endl;
    for (int k = 0; k < jumlah_barang; k++){
        cout << "Harga Barang : " << db[k].harga_brg << endl
             << "| Nama Barang : " << db[k].nama_brg << endl
             << "| Kode Barang : " << db[k].kode_brg << endl
             << "| Jumlah Ketersediaan Barang : " << db[k].stok_brg << endl 
             << endl;
    }

    if (jumlah_barang == 0){
        cout << "Data barang masih kosong." << endl;
    }
}

void hmahal_urut(data_barang db[]){
    for (int i = 0; i < jumlah_barang - 1; i++){
        for (int j = 0; j < jumlah_barang - i - 1; j++){
            if (db[j].harga_brg < db[j+1].harga_brg){
                swapData(&db[j], &db[j+1]);
            }
        }
    }

    cout << "===== Mengurutkan Barang dari Harga Termahal ======" << endl << endl;
    for (int k = 0; k < jumlah_barang; k++){
        cout << "Harga Barang : " << db[k].harga_brg << endl
             << "| Nama Barang : " << db[k].nama_brg << endl
             << "| Kode Barang : " << db[k].kode_brg << endl
             << "| Jumlah Ketersediaan Barang : " << db[k].stok_brg << endl 
             << endl;
    }

    if (jumlah_barang == 0){
        cout << "Data barang masih kosong." << endl;
    }
}

void sb_banyak(data_barang db[]){
    for (int i = 0; i < jumlah_barang - 1; i++){
        for (int j = 0; j < jumlah_barang - i - 1; j++){
            if (db[j].stok_brg < db[j+1].stok_brg){
                swapData(&db[j], &db[j+1]);
            }
        }
    }

    cout << "===== Mengurutkan Barang dari Jumlah Ketersediaan Barang Terbanyak ======" << endl << endl;
    for (int k = 0; k < jumlah_barang; k++){
        cout << "Jumlah Ketersediaan Barang : " << db[k].stok_brg << endl 
             << "| Kode Barang  : " << db[k].kode_brg << endl
             << "| Nama Barang  : " << db[k].nama_brg << endl
             << "| Harga Barang : " << db[k].harga_brg << endl
             << endl;
    }

    if (jumlah_barang == 0){
        cout << "Data barang masih kosong." << endl;
    }
}

void sb_dikit(data_barang db[]){
    for (int i = 0; i < jumlah_barang - 1; i++){
        for (int j = 0; j < jumlah_barang - i - 1; j++){
            if (db[j].stok_brg > db[j+1].stok_brg){
                swapData(&db[j], &db[j+1]);
            }
        }
    }

    cout << "===== Mengurutkan Barang dari Jumlah Ketersediaan Barang Terkecil ======" << endl << endl;
    for (int k = 0; k < jumlah_barang; k++){
        cout << "Jumlah Ketersediaan Barang : " << db[k].stok_brg << endl
             << "| Nama Barang  : " << db[k].nama_brg << endl
             << "| Kode Barang  : " << db[k].kode_brg << endl
             << "| Harga Barang : " << db[k].harga_brg << endl 
             << endl;
    }

    if (jumlah_barang == 0){
        cout << "Data barang masih kosong." << endl;
    }
}

// MENU UTAMA

void menambah_data(data_barang db[]){
    system("cls");

    bool duplikat = false;
    string nama_baru, kode_baru;
    int x;

    do{
        cout << "Jumlah Barang yang ingin diinputkan : "; 
        
        if (!(cin >> x)){
            errorInput();
            system("cls");
            return;
        }

        if (x + jumlah_barang > 100){
            cout << "Data Sudah Penuh! Hanya Tersisa " << 100 - jumlah_barang << " slot data barang." << endl;
            system("pause");
            cout << endl;
            system("cls");
            break;
        }

    } while (x + jumlah_barang > 100);

    cin.ignore(100, '\n');

    for (int i = 0; i < x; i++){
        int indeks_sekarang = jumlah_barang + i;
        cout << endl;
        cout << "Mencatat data barang ke - " << jumlah_barang + 1 << endl;

        cout << "| Nama Barang  : "; getline(cin, db[indeks_sekarang].nama_brg); // !

        do{
            duplikat = false;
            cout << "| Kode Barang  : "; // !
            
            if (!(cin >> kode_baru)){
                errorInput();
                duplikat = true;
            }

            for (int k = 0; k < jumlah_barang + i; k++){
                if (kode_baru == db[k].kode_brg){
                    duplikat = true;
                    cout << "Kode sudah digunakan! Gunakan kode lain." << endl;
                    break;
                }
            }

            if(!duplikat){
                db[indeks_sekarang].kode_brg = kode_baru;
            }

        } while (duplikat == true);

        do {
            duplikat = false;
            cout << "| Harga Barang : "; // !

            if (!(cin >> db[indeks_sekarang].harga_brg)){
                errorInput();
                duplikat = true;
            }
        } while (duplikat == true);

        do {
            duplikat = false;
            cout << "| Jumlah Ketersediaan Barang : "; 

            if (!(cin >> db[indeks_sekarang].stok_brg)){
                errorInput();
                duplikat = true;
            }
        } while (duplikat == true);
        
        cin.ignore(100, '\n');
    }

    jumlah_barang = jumlah_barang + x;
    saveData_Barang();
    cout << "Data berhasil ditambahkan!" << endl << endl;
    system("pause");
    system("cls");
    
}

void mengurutkan_barang(data_barang db[]){
    system("cls");

    cout << "1. Tampilkan berdasarkan Kode Barang Terurut" << endl
         << "2. Tampilkan berdasarkan Harga Termurah" << endl
         << "3. Tampilkan berdasarkan Harga Termahal" << endl
         << "4. Tampilkan berdasarkan Stok Barang Terbanyak" << endl
         << "5. Tampilkan berdasarkan Stok Barang Tersedikit" << endl;

    int pilih;
    cout << "Masukkan pilihan Anda : ";
    cin >> pilih;
    system("cls");

    switch(pilih){
        case 1:
            kb_urut(db);
            system("pause");
            system("cls");
            break;
        case 2:
            hmurah_urut(db);
            system("pause");
            system("cls");
            break;
        case 3:
            hmahal_urut(db);
            system("pause");
            system("cls");
            break;
        case 4:
            sb_banyak(db);
            system("pause");
            system("cls");
            break;
        case 5:
            sb_dikit(db);
            system("pause");
            system("cls");
            break;
        default:
            return;
    }
}

void mencari_barang(data_barang db[]){
    system("cls");

    bool ketemu = false;
    int pilih;
    string cari;
    int cari_angka;

    cout << "Anda dapat mencari berdasarkan :" << endl
         << "1. Nama Barang" << endl
         << "2. Kode Barang" << endl
         << "3. Harga Barang" << endl
         << "4. Ketersediaan Barang" << endl;
    cout << "Anda ingin mencari barang berdasarkan apaa?? "; 
    if (!(cin >> pilih)) { 
        errorInput(); 
        return; 
    }
    cin.ignore(1000, '\n');
    system("cls");

    switch (pilih){
        case 1:
            cout << "Masukkan nama barang yang ingin dicari : "; getline (cin, cari);

            for (int i = 0; i < jumlah_barang; i++){
                if (db[i].nama_brg == cari){
                    cout << endl;
                    cout << "Nama Barang : " << db[i].nama_brg << endl
                         << "| Kode Barang  : " << db[i].kode_brg << endl
                         << "| Harga Barang : " << db[i].harga_brg << endl
                         << "| Jumlah Ketersediaan Barang : " << db[i].stok_brg << endl;
                    
                    ketemu = true;
                }
            }
        
            break;

        case 2:
            cout << "Masukkan kode barang yang ingin dicari : "; cin >> cari;

            for (int i = 0; i < jumlah_barang; i++){
                if (db[i].kode_brg == cari){
                    cout << endl;
                    cout << "Kode Baramg : " << db[i].kode_brg << endl
                         << "| Nama Barang  : " << db[i].nama_brg << endl
                         << "| Harga Barang : " << db[i].harga_brg << endl
                         << "| Jumlah Ketersediaan Barang : " << db[i].stok_brg << endl;

                    ketemu = true;
                }
            }

            break;

        case 3:
            cout << "Masukkan harga barang yang ingin dicari : "; cin >> cari_angka;

            for (int i = 0; i < jumlah_barang; i++){
                if (db[i].harga_brg == cari_angka){
                    cout << endl;
                    cout << "Harga Barang : " << db[i].harga_brg << endl
                         << "| Nama Barang : " << db[i].nama_brg << endl
                         << "| Kode Baramg : " << db[i].kode_brg << endl
                         << "| Jumlah Ketersediaan Barang : " << db[i].stok_brg << endl;

                    ketemu = true;
                }
            }

            break;

        case 4:
            cout << "Masukkan jumlah ketersediaan barang yang ingin dicari : "; cin >> cari_angka;

            for (int i = 0; i < jumlah_barang; i++){
                if (db[i].stok_brg == cari_angka){
                    cout << endl;
                    cout << "Jumlah Ketersediaan Barang : " << db[i].stok_brg << endl
                         << "| Nama Barang  : " << db[i].nama_brg << endl
                         << "| Kode Baramg  : " << db[i].kode_brg << endl
                         << "| Harga Barang : " << db[i].harga_brg << endl;

                    ketemu = true;
                }
            }

            break;
    }

    if (!ketemu){
        cout << "Data tidak ditemukan." << endl;
    }

    cout << endl;
    system ("pause");
    system ("cls");
}

void total_belanja() {
	string cari_kode;
	int total_bayar = 0;
	total_keseluruhan = 0;
	int jumlah_item, potongan_harga;
    int input_jumlah;
	bool ulang = false;
	
    do {
        ulang = false;
        cout << "Masukkan jumlah item : ";

        if (!(cin >> jumlah_item)){
            errorInput();
            ulang = true;
        }
    } while (ulang == true);

	for(int i = 0; i < jumlah_item; i++){
		cout << "\nItem ke - " << i+1 << endl;
		cout << "Masukkan Kode Barang : ";
		
		ulang = false;
		
		do{
			if (!(cin >> cari_kode)){
				errorInput();
				ulang = true;
			}
		} while (ulang == true);
		
        bool ketemu = false;
		for(int j = 0; j < jumlah_barang; j++) {
			if(db[j].kode_brg == cari_kode) {
                ketemu = true;
				cout << "| Kode Barang : " << db[j].kode_brg << endl
					 << "| Nama Barang : " << db[j].nama_brg << endl;
				
				do{
					ulang = false;
					cout << "| Jumlah Beli : ";

					if (!(cin >> input_jumlah)){
						errorInput();
						ulang = true;
					}

                    if (!ulang){
                        if(db[j].tr.jumlah_beli > db[j].stok_brg) {
                            cout << "Mohon Maaf, ketersediaan stok hanya " << db[j].stok_brg << endl << endl;
                            ulang = true;
                        } else {
                            db[j].tr.jumlah_beli += input_jumlah;

                            total_bayar = db[j].harga_brg * input_jumlah;
                            total_keseluruhan += total_bayar;			
                            db[j].stok_brg -= input_jumlah;
                                
                            cout << "Barang berhasil ditambahkan ke keranjang!\n" << endl;
                            cout << "| Subtotal    : Rp" << total_bayar<< endl;
                            cout << "| Sisa Stok   : " << db[j].stok_brg << endl;
                        }
                    }
				} while (ulang == true);
				break;
			} 
		}
		
        if (!ketemu) {
            cout << "Kode tidak ditemukan! Silakan Masukkan kembali!";
            i--;
        }
	}

    saveData_Barang();
    jumlah_transaksi++;
    
	cout << "\n---------------------------------------------------\n";
	cout << "Total Belanja : Rp" << total_keseluruhan << endl;

    if (total_keseluruhan >= 10000){
        potongan_harga = diskon(total_keseluruhan/10000);
        total_keseluruhan = total_keseluruhan - potongan_harga;
        cout << "Selamat, Anda mendapat Diskon sebesar Rp" << potongan_harga << "\n\n"
             << "[$] Total Belanjaan Anda setelah diskon : Rp" << total_keseluruhan << "\n\n\n";
    }

	saveData_Barang();
	system("pause");
	system("cls");
}

void riwayat_pembelian() {
     if(jumlah_transaksi == 0) {
        cout << "Belum ada transaksi." << endl << endl;
        system("pause");
        system("cls");
        return;
    }
    
    cout << "===== Riwayat Transaksi =====" << endl;
    
    int no = 1;
    int total_riwayat = 0;
    int potongan_harga;
    for(int i = 0; i < jumlah_barang; i++) {
        if (db[i].tr.jumlah_beli > 0){
			cout << "\nProduk ke - " << no << endl
				 << "| Kode Barang  : " << db[i].kode_brg << endl
				 << "| Nama Barang  : " << db[i].nama_brg << endl
				 << "| Jumlah Beli  : " << db[i].tr.jumlah_beli << endl
                 << "| Harga Satuan : " << db[i].harga_brg << endl
                 << "| Subtotal     : " << db[i].harga_brg * db[i].tr.jumlah_beli << endl;
                 
			total_riwayat += db[i].harga_brg * db[i].tr.jumlah_beli;
			no++;
        }
    }
    cout << "\n---------------------------------------------------\n";
    cout << "Total Keseluruhan Belanja : Rp" << total_riwayat << "\n";

    if (total_keseluruhan >= 10000){
        potongan_harga = diskon(total_riwayat/10000);
        total_riwayat = total_riwayat - potongan_harga;
        cout << "[$] Total Belanjaan Anda setelah diskon : Rp" << total_riwayat << "\n\n\n";
    }
    
    system("pause");
    system("cls");
}

void edit_data(){
    string edit, baru;
    int angka_baru, pilih;
    bool ulang = false, ketemu = false, dup = false;

    cout << "Masukkan Kode Barang yang ingin diedit : ";
    cin >> edit;
            
    for(int i = 0; i < jumlah_barang; i++){
        if (edit == db[i].kode_brg){
            ketemu = true;
            cout << "\nKode Barang : " << db[i].kode_brg << endl
                << "| Nama Barang   : " << db[i].nama_brg << endl
                << "| Harga barang  : " << db[i].harga_brg << endl
                << "| Jumlah Barang : " << db[i].stok_brg << endl << endl;

            cout << "Data Apa yang ingin Anda ubah?" << endl
                    << "Anda dapat memilih dari beberapa pilihan berikut :" << endl
                    << "[1] Kode Barang" << endl 
                    << "[2] Nama Barang" << endl
                    << "[3] Harga Barang" << endl
                    << "[4] Jumlah Barang" << endl
                    << "Masukkan pilihan Anda : ";
            
            do {
                ulang = false;
                if (!(cin >> pilih)){
                errorInput();
                ulang = true;
                }
            } while(ulang == true);

            cin.ignore(1000, '\n');
            
            switch(pilih){
                case 1:
                    do {
                        dup = false;
                        cout << "\nMasukkan Kode Barang yang baru : "; cin >> baru;

                        for (int d = 0; d < jumlah_barang; d++){
                            if (d != i && baru == db[d].kode_brg){
                                dup = true;
                                cout << "Kode sudah pernah digunakan! Gunakan kode lain!" << endl;
                                break;
                            }
                        }

                    } while (dup == true);
                    
                    db[i].kode_brg = baru;
                    break;
                case 2:
                    cout << "\nMasukkan Nama Barang yang baru : "; 
                    getline(cin, baru);
                    db[i].nama_brg = baru;
                    break;
                case 3:
                    cout << "\nMasukkan Harga Barang yang baru : "; 
                    
                    do {
                        ulang = false;
                        if (!(cin >> angka_baru)){
                        errorInput();
                        ulang = true;
                        }
                    } while(ulang == true);

                    db[i].harga_brg = angka_baru;
                    break;
                case 4:
                    cout << "\nMasukkan Jumlah Ketersediaan Barang yang baru : "; 
                    
                    do {
                        ulang = false;
                        if (!(cin >> angka_baru)){
                        errorInput();
                        ulang = true;
                        }
                    } while(ulang == true);

                    db[i].stok_brg = angka_baru;
                    break;
                default:
                    cout << "Input tidak valid. kembali ke menu utama!" << endl;
                    system("pause");
                    system("cls");
                    return;
            }
            saveData_Barang();
            cout << "Data berhasil diperbarui." << endl;
            break;
        }
    }

    if (!ketemu){
        cout << "Kode Barang tidak ditemukan!" << endl;
    }

    cout << endl;
    system("pause");
    system("cls");
}

int main(){
	initData();

    int pilih;
	do{
        cout << "========== Aplikasi Kasir Mini ==========" << endl;
        cout << "Menu : " << endl;
        cout << "1. Tambah Data Barang" << endl
			 << "2. Edit Data Barang" << endl
             << "3. Mengurutkan Barang" << endl
             << "4. Mencari Barang" << endl
             << "5. Masukkan Total Belanja" << endl
             << "6. Lihat Riwayat Pembelian" << endl
             << "0. Keluar" << endl;

        cout << "Silahkan pilih menu : ";
        
        if(!(cin >> pilih)){
			errorInput();
			system("cls");
			pilih = 7;
		}
        
        switch(pilih){
            case 1:
				system("cls");
                menambah_data(db);
                break;
            case 2:
                system("cls");
                edit_data();
                break;
            case 3:
				system("cls");
                mengurutkan_barang(db);
                break;
            case 4:
				system("cls");
                mencari_barang(db);
                break;
            case 5:
				system("cls");
                total_belanja();
                break;
            case 6:
				system("cls");
                riwayat_pembelian();
                break;
            case 0:
                return 0;
            
        }
    } while (pilih != 0);
}
