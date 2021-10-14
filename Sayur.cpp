#include <iostream>
#include <string>
#include <iomanip>

using namespace std;





void liat_barang(string nama_barang[40], int stok[40], int harga[40], int size){	
	cout<<"------------------------------------------------------------------"<<endl;
	for (int i=0;i<size;i++){
		cout<<i+1<<"\t"<<nama_barang[i]<<"\t\t"<<stok[i]<<"\t\t"<<harga[i]<<endl; //Menampilkan semua nilai array
	}
}


void liat_orang(string nama_pembeli[40], string barang_dibeli[40], int harga_barang_dibeli[40], int jumlah_barang_dibeli[40], int total_barang_dibeli[40], int size_orang) {
	for (int i=0;i<size_orang;i++){
		cout<<i+1<<"\t"<<nama_pembeli[i]<<"\t\t"<<barang_dibeli[i]<<"\t\t"<<harga_barang_dibeli[i]<<"\t\t"<<jumlah_barang_dibeli[i]<<"\t\t"<<total_barang_dibeli[i]<<endl; //Menampilkan semua nilai array
	}
}


int menu_awal(){
	int pilih0;

	cout << "\t\t TOKO TANAMAN " <<endl;
	cout<<"\t-----------------------------"<<endl;
	cin.get();
	cout<<"\t\t Daftar Menu "<<endl;
	cout<<"\t-----------------------------"<<endl;
	cout<<"|1.	Buat Daftar Barang		|"<<endl;
	cout<<"|2. 	Lihat Daftar Barang		|"<<endl;
	cout<<"|3. 	Update Daftar Barang 		|"<<endl;
	cout<<"|4.	Hapus Daftar Barang		|"<<endl;
	cout<<"|5.	Daftar Penjualan		|"<<endl;
	cout<<"|6.	Keluar				|"<<endl;
	cout<<" "<<endl;
	
	cout<<"Pilih Menu Yang Anda Inginkan :"; 
	cin>>pilih0;
	return pilih0;
}

int main(){	

	string nama_barang[40] 			= {"Lili Paris", "Miana Api", "Aglonemea"};
	int stok[40] 					= {6, 7, 4};
	int harga[40] 					= {4000, 10000, 80000};
	string nama_pembeli[40] 		= {"Udin", "Budi"};
	string barang_dibeli[40] 		= {nama_barang[0], nama_barang[2]};
	int harga_barang_dibeli[40] 	= {harga[0], harga[2]};
	int jumlah_barang_dibeli[40] 	= {4, 1};
	int total_barang_dibeli[40] 	= {16000, 80000};
	
	int size = 3, size_orang = 2;
	int menu_jual, temp1, pos_ubah, pos_hapus;
	int pilih1=0;
	char lanjut='0';	
	string temp0;
	
	while(pilih1 != 6){
		
		pilih1 = menu_awal();
		
		switch(pilih1){
			case 1:
				cout << "Buat Daftar Barang" << endl;
				cout<<"Masukan Jumlah Daftar Barang Yang Ingin Dijual : ";
				cin>>menu_jual; //Pengguna memasukan jumlah beli
				
				for (int i = 0; i<menu_jual;i++){
					
					cout<<endl;
					cout<<"Masukan Barang Ke- "<<i+1<<endl;
					
					cout<<"Masukkan nama barang :  ";
					cin.ignore();
					getline (cin,temp0);
					nama_barang[size] = temp0;
			
					cout<<"Masukkan harga barang :  ";
					cin>>temp1;
					harga[size] = temp1;
					
					cout<<"Stok Barang : ";
					cin>>temp1;
					stok[size] = temp1;
					
					
					size++;
				};	
				cout<<"------------------------------------------------------------------"<<endl;
				for (int i = 0; i<menu_jual; i++){
					cout<<" "<<endl;
					cout<<i+1<<endl;
					cout<<"Nama Barang : "<<nama_barang[i]<<endl;
					cout<<"Stok Barang : "<<stok[i]<<endl;
					cout<<"Harga       :"<<harga[i]<<endl;
				}	
				cout<<"-------------------------------------------------------------------"<<endl;
				cin.get();
				
				
				break;
			case 2:
				cout << "Daftar Barang" <<endl;
				liat_barang(nama_barang, stok, harga, size);
				break;
			case 3:
				cout << "Update Daftar Barang" << endl;
				
				cout<<"Masukkan index barang yg mau diubah :  ";
				cin>>pos_ubah;
				cout << pos_ubah << " \nNama Tanaman : " <<nama_barang[pos_ubah]<< " \tHarga : " << harga[pos_ubah]<< " \tStok : " <<stok[pos_ubah]<<"\n\n\n"<<endl;
				
				cout<<"\n\nMasukkan nama barang baru:  ";
				cin.ignore();
				getline (cin, temp0);
				nama_barang[pos_ubah] = temp0;
				cout<<"Harga barang baru:  ";
				cin>>temp1;
				harga[pos_ubah] = temp1;
				cin.ignore();
				cout<<"Stok barang baru: ";
				cin>>temp1;
				stok[pos_ubah] = temp1;
				break;
			case 4:
				cout << "Hapus Daftar Barang" << endl;
				cout<<"Masukkan _id yang ingin anda hapus :  ";
				cin>>pos_hapus;
				cout<<"Berhasil!!\n\n\n";
				for (int i = pos_hapus; i < size; i++){ //dipindah ke elemen yang dihapus
					nama_barang[i] = nama_barang[i + 1];
					harga[i] = harga[i + 1];
					stok[i] = stok[i + 1];
		    	};
		    	size--;
				break;
			case 5:
				cout << "Daftar Penjualan" << endl;
				liat_orang(nama_pembeli, barang_dibeli, harga_barang_dibeli, jumlah_barang_dibeli, total_barang_dibeli, size_orang);
				break;
			case 6:
				cout<<"\tTerimakasih Telah Menggunakan Program Ini"<<endl; //Y
				break;
			default:
				cout << "Pilihan tidak ditemukan" << endl; //Y
				break;
		}
		
		
		if (pilih1 != '6') {
			cout << "\n\nLanjutkan?(y/n) : ";
			cin >> lanjut;
			while (lanjut == '0') {
				if ( (lanjut == 'y') | (lanjut == 'Y')){
					pilih1 = menu_awal();
				} else if ((lanjut == 'n') | (lanjut == 'N')){
					pilih1 = '6';
				} else {
					cout<<"Pilihan anda salah!";
					continue;
				}
		}
		}
	}

	cout << "Terimakasih Telah Menggunakan Program Ini" << endl;

	cin.get();
	return 0;
}




