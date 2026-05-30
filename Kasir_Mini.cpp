#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Transaksi {
	int jumlah_item, total_belanja;
}

struct data_barang{
    string nama_brg, kode_brg;
    int stok_brg, harga_brg;
    Transaksi tr;
};

data_barang db[100];
int jumlah_barang = 0;

void menambah_data(data_barang db[]){
    system("cls");

    bool duplikat = false;

    string nama_baru, kode_baru;
    int x;

    do{	 	
        cout << "Jumlah Barang yang ingin diinputkan: "; cin >> x;

        if (x + jumlah_barang > 1000){
            cout << "Data Sudah Penuh! Hanya Tersisa " << 1000 - jumlah_barang << " slot data barang." << endl;
            system("pause");
            cout << endl;
            system("cls");
            break;
        }

    } while (x + jumlah_barang > 1000);

    cin.ignore(100, '\n');

    for (int i = 0; i < x; i++){
        
        cout << endl;
        cout << "Mencatat data barang ke-" << i+1 << endl << endl;
        do{
            duplikat = false;
            cout << "Nama Barang: "; getline(cin, nama_baru);
            
            for (int j = 0; j < jumlah_barang; j++){
                if (nama_baru == db[j].nama_brg){
                    duplikat = true;
                    cout << "Nama sudah pernah digunakan! Gunakan nama barang lain.";
                    system("pause");
                    cout << endl;
                }
                break;
            }

        } while (duplikat == true);

        db[i].nama_brg = nama_baru;

        do{
            duplikat = false;
            cout << "Kode Barang: "; cin >> kode_baru;
            for (int k = 0; k < jumlah_barang; k++){
                if (kode_baru == db[k].kode_brg){
                    duplikat = true;
                    cout << "Kode sudah digunakan! Gunakan kode barang lain." << endl << endl;
                    system("pause");
                    cout << endl;
                }
                break;
            }

        } while (duplikat == true);

        db[i].kode_brg = kode_baru;

        cout << "Harga Barang: "; cin >> db[i].harga_brg;
        cout << "Jumlah Ketersediaan Barang: "; cin >> db[i].stok_brg;
        
        cin.ignore(100, '\n');
        
    }

    system("pause");
    system("cls");
    jumlah_barang = jumlah_barang + x;
    
}

void kb_urut(data_barang db[]){
    for (int i = 0; i < jumlah_barang - 1; i++){
        for (int j = 0; j < jumlah_barang - i - 1; j++){
            if (db[j].kode_brg > db[j+1].kode_brg){
                swap (db[j], db[j+1]);
            }
        }
    }

    for (int k = 0; k < jumlah_barang; k++){
        cout << "Nama Barang: " << db[k].nama_brg << endl
             << "Kode Barang: " << db[k].kode_brg << endl
             << "Harga Barang: " << db[k].harga_brg << endl
             << "Jumlah Ketersediaan Barang: " << db[k].stok_brg << endl 
             << endl;
    }

    if (jumlah_barang == 0){
        cout << "Data barang masih kosong" << endl;
    }
}

void hmurah_urut(data_barang db[]){
    for (int i = 0; i < jumlah_barang - 1; i++){
        for (int j = 0; j < jumlah_barang - i - 1; j++){
            if (db[j].harga_brg > db[j+1].harga_brg){
                swap (db[j], db[j+1]);
            }
        }
    }

    for (int k = 0; k < jumlah_barang; k++){
        cout << "Nama Barang: " << db[k].nama_brg << endl
             << "Kode Barang" << db[k].kode_brg << endl
             << "Harga Barang: " << db[k].harga_brg << endl
             << "Jumlah Ketersediaan Barang: " << db[k].stok_brg << endl 
             << endl;
    }

    if (jumlah_barang == 0){
        cout << "Data barang masih kosong" << endl;
    }
}

void hmahal_urut(data_barang db[]){
    for (int i = 0; i < jumlah_barang - 1; i++){
        for (int j = 0; j < jumlah_barang - i - 1; j++){
            if (db[j].harga_brg < db[j+1].harga_brg){
                swap (db[j], db[j+1]);
            }
        }
    }

    for (int k = 0; k < jumlah_barang; k++){
        cout << "Nama Barang: " << db[k].nama_brg << endl
             << "Kode Barang: " << db[k].kode_brg << endl
             << "Harga Barang: " << db[k].harga_brg << endl
             << "Jumlah Ketersediaan Barang: " << db[k].stok_brg << endl 
             << endl;
    }

    if (jumlah_barang == 0){
        cout << "Data barang masih kosong" << endl;
    }
}

void sb_banyak(data_barang db[]){
    for (int i = 0; i < jumlah_barang - 1; i++){
        for (int j = 0; j < jumlah_barang - i - 1; j++){
            if (db[j].stok_brg > db[j+1].stok_brg){
                swap (db[j], db[j+1]);
            }
        }
    }

    for (int k = 0; k < jumlah_barang; k++){
        cout << "Nama Barang: " << db[k].nama_brg << endl
             << "Kode Barang: " << db[k].kode_brg << endl
             << "Harga Barang: " << db[k].harga_brg << endl
             << "Jumlah Ketersediaan Barang: " << db[k].stok_brg << endl 
             << endl;
    }

    if (jumlah_barang == 0){
        cout << "Data barang masih kosong" << endl;
    }
}

void sb_dikit(data_barang db[]){
    for (int i = 0; i < jumlah_barang - 1; i++){
        for (int j = 0; j < jumlah_barang - i - 1; j++){
            if (db[j].stok_brg < db[j+1].stok_brg){
                swap (db[j], db[j+1]);
            }
        }
    }

    for (int k = 0; k < jumlah_barang; k++){
        cout << "Nama Barang: " << db[k].nama_brg << endl
             << "Kode Barang: " << db[k].kode_brg << endl
             << "Harga Barang: " << db[k].harga_brg << endl
             << "Jumlah Ketersediaan Barang: " << db[k].stok_brg << endl 
             << endl;
    }

    if (jumlah_barang == 0){
        cout << "Data barang masih kosong" << endl;
    }
}

void mengurutkan_barang(data_barang db[]){
    system("cls");

    cout << "1. Tampilkan berdasarkan Kode Barang Terurut" << endl
         << "2. Tampilkan berdasarkan Harga Termurah" << endl
         << "3. Tampilkan berasarkan Harga Termahal" << endl
         << "4. Tampilkan berdasarkan Stok Barang Terbanyak" << endl
         << "5. Tampilkan berdasarkan Stok Barang Tersedikit" << endl;

    int pilih;
    cout << "masukkan pilihan Anda: ";
    cin >> pilih;

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
    cout << "Anda dapat mencari berdasarkan:" << endl
         << "1. Nama Barang" << endl
         << "2. Kode Barang" << endl
         << "3. Harga Barang" << endl
         << "4. Ketersediaan Barang" << endl;
    cout << "Anda ingin mencari barang berdasarkan apaa?? "; cin >> pilih;

    switch (pilih){
        case 1:
            cout << "Masukkan nama barang yang ingin dicari: "; cin >> cari;

            for (int i = 0; i < jumlah_barang; i++){
                if (db[i].nama_brg == cari){
                    cout << endl;
                    cout << "Nama Barang   : " << db[i].nama_brg << endl
                         << "Kode Baramg   : " << db[i].kode_brg << endl
                         << "Harga Barang  : " << db[i].harga_brg << endl
                         << "Jumlah Ketersediaan Barang: " << db[i].stok_brg << endl << endl;
                    
                    ketemu = true;
                }
            }
        
            break;

        case 2:
            cout << "Masukkan kode barang yang ingin dicari: "; cin >> cari;

            for (int i = 0; i < jumlah_barang; i++){
                if (db[i].kode_brg == cari){
                    cout << "Nama Barang: " << db[i].nama_brg << endl
                         << "Kode Baramg: " << db[i].kode_brg << endl
                         << "Harga Barang: " << db[i].harga_brg << endl
                         << "Jumlah Ketersediaan Barang: " << db[i].stok_brg << endl;
                }
            }

            break;

        case 3:
            cout << "Masukkan harga barang yang ingin dicari: "; cin >> cari_angka;

            for (int i = 0; i < jumlah_barang; i++){
                if (db[i].harga_brg == cari_angka){
                    cout << endl;
                    cout << "Nama Barang: " << db[i].nama_brg << endl
                         << "Kode Baramg: " << db[i].kode_brg << endl
                         << "Harga Barang: " << db[i].harga_brg << endl
                         << "Jumlah Ketersediaan Barang: " << db[i].stok_brg << endl;
                }
            }

            break;

        case 4:
            cout << "Masukkan jumlah ketersediaan barang yang ingin dicari: "; cin >> cari_angka;

            for (int i = 0; i < jumlah_barang; i++){
                if (db[i].stok_brg == cari_angka){
                    cout << endl;
                    cout << "Nama Barang: " << db[i].nama_brg << endl
                        << "Kode Baramg: " << db[i].kode_brg << endl
                        << "Harga Barang: " << db[i].harga_brg << endl
                        << "Jumlah Ketersediaan Barang: " << db[i].stok_brg << endl;
                }
            }

            break;
    }

    if (ketemu == false){
        cout << "data tidak ditemukan." << endl;
    }

    system ("pause");
    system ("cls");
}

void total_belanja() {
	string cari_kode;
	int total_bayar = 0;
	int total_keseluruhan = 0;
	int jumlah, jumlah_item;
	
	cout << "Masukkan jumlah item: ";
	cin >> jumlah_item;	
	for(int i = 0; i < jumlah_item; i++){
		cout << "\nMasukkan Kode Barang: ";
		cin >> cari_kode;
		for(int j = 0; j < jumlah_barang; j++) {
			if(db[j].kode_brg == cari_kode) {
				cout << "\nKode Barang : " << db[j].kode_brg
					 << "\nNama Barang : " << db[j].nama_brg
					 << "\nJumlah Barang : ";
				 cin >> jumlah;
				if(jumlah > db[j].stok_brg) {
					cout << "\nMohon Maaf, ketersediaan stok hanya " << db[j].stok_brg << endl;
				} else {
					total_bayar = db[j].harga_brg * jumlah;
					total_keseluruhan += total_bayar;			
					db[j].stok_brg -= jumlah;
						
					cout << "Barang berhasil ditambahkan ke keranjang\n";
					cout << "Subtotal : Rp" << total_bayar << endl;
					cout << "Sisa Stok   : " << db[j].stok_brg << endl;
				}
				break;
			} 
		}
	}
	cout << "\nTotal Belanja : Rp " << total_keseluruhan;
	
	system("pause");
	system("cls");
}

void riwayat_pembelian() {
     if(jumlah_barang == 0) {
        cout << "Data barang masih kosong." << endl << endl;
        system("pause");
        system("cls");
        return;
    }
    kb_urut(db);

    cout << "=== Riwayat Transaksi ===" << endl;
    
    for(int i = 0; i < jumlah_siswa; i++) {
        cout << "\nTransaksi ke - " << i + 1 << endl
			 << "Kode        : " << db[i].kode_brg << endl
             << "Nama        : " << db[i].nama_brg << endl
             << "Jumlah Item  : " << db[i]. << endl
             << "Total Harga  : " <<  << endl;
    }
    
    system("pause");
    system("cls");
}

int main(){
	initData();
	
    int pilih;
	do{
        cout << "========== Aplikasi Kasir Mini ==========" << endl;
        cout << "Menu: " << endl;
        cout << "1. Menambah data barang" << endl
            << "2. Mengurutkan barang" << endl
            << "3. Mencari barang" << endl
            << "4. Total belanja" << endl
            << "5. Riwayat Pembelian" << endl 
            << "6. Keluar" << endl;

        cout << "Silahkan pilih menu: ";
        
        cin >> pilih;
        switch(pilih){
            case 1:
				system("cls");
                menambah_data(db);
                break;
            case 2:
				system("cls");
                mengurutkan_barang(db);
                break;
            case 3:
				system("cls");
                mencari_barang(db);
                break;
            case 4:
				system("cls");
                total_belanja();
                break;
            case 5:
				system("cls");
                riwayat_pembelian();
                break;
            case 6:
                return 0;
        }
    } while (pilih != 6);
}

void initData() {
    ifstream file("data_barang.txt"); // pakai 'ifstream' karena mau membaca file
    if (!file.is_open()) {
        cout << "File data_barang.txt tidak ditemukan! Memulai dengan data kosong." << endl << endl;
        jumlah_barang = 0;
        system("pause");
        return;
    }

    jumlah_barang = 0;
    while (file >> db[jumlah_barang].kode_brg && jumlah_barang < 100) {
        file.ignore();
        getline(file, db[jumlah_barang].nama_brg);
        file >> db[jumlah_barang].harga_brg
             >> db[jumlah_barang].stok_brg;
        file.ignore();
        jumlah_barang++;
    }
    file.close();
}
