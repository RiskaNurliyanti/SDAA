#include <iostream>
#include <fstream>
#include <math.h>       /* sqrt */

using namespace std;

struct Item {
	int id;
	string nama;
	string jenis;
	string warna;
	int harga;
	int stok;
};
struct Node {
	int data;
	Item tanaman[50];
	struct Node* next;
};

void tambahTanaman(Node **head, int &jumlah);
void ubahTanaman(struct Node **head, int &jumlah);
void liatTanaman(struct Node* n);
void shellSorthargaasc(Item *tanaman, int &size);
void shellSorthargadesc(Item *tanaman, int &size);
void shellSortstokasc(Item *tanaman, int &size);
void shellSortstokdesc(Item *tanaman, int &size);
int jumpSearchharga(Item *tanaman, int x, int &size);


int menu_awal(){
	int pilih0;

	cout << "\t\t TOKO TANAMAN " <<endl;
	cout<<"\t-----------------------------"<<endl;
	cin.get();
	cout<<"\t\t Daftar Menu "<<endl;
	cout<<"\t-----------------------------"<<endl;
	cout<<"|1. 	Lihat Daftar Barang		"<<endl;
	cout<<"|2. 	Tambah Daftar Barang	"<<endl;
	cout<<"|3. 	Update Barang			"<<endl;
	cout<<"|4.	Hapus Daftar Barang		"<<endl;
	cout<<"|5.  	Urutan Daftar Barang            "<<endl;
	cout<<"|6.  	Cari Daftar Barang            "<<endl;
	cout<<"|7.	Simpan Barang ke File Eksternal	"<<endl;
	cout<<"|8.	Keluar					"<<endl;
	
	cout<<" "<<endl;
	cout<<"Pilih Menu Yang Anda Inginkan :"; 
	cin>>pilih0;
	return pilih0;
}

int main(){	
	int size, jumlah, temp1, posUbah, posHapus;
	int pilih1=0;
	char lanjut;	
	string temp0;
	struct Node* HEAD = NULL;
	while(pilih1 != 8){
		size = jumlah;
		pilih1 = menu_awal();
		
		switch(pilih1){
			case 1:
				cout << "Daftar Barang" <<endl;
				if(jumlah == 0){
					cout<<"Masih Kosong";
				} else {
					liatTanaman(HEAD);
				};
				break;
			case 2:
				cout << "Tambah Daftar Barang" << endl;
				tambahTanaman(&HEAD, jumlah);
				break;
			case 3:
				cout << "Update Daftar Barang" << endl;
				liatTanaman(HEAD);
				cout<<"Masukkan id barang yg mau diubah :  ";
				cin>>posUbah;
				ubahTanaman(&HEAD, jumlah);
				break;
			case 4:
				liatTanaman(HEAD);
				cout<<"\n\nMasukkan id yang ingin anda hapus :  ";
				cin>>posHapus;
				for (int i = posHapus; i < jumlah; i++){
					tanaman[i] = tanaman[i+1];
				};	
				jumlah -= 1;
				break;
			case 5:
				cout<<"Daftar Urutan Barang Berdasarkan Harga Secara Ascending"<<endl;
				shellSorthargaasc(&tanaman[0], size);
				liatTanaman(HEAD);
				cout<<"-----------------------------------------------"<<endl;
				cout<<"Daftar Urutan Barang Berdasarkan Harga Secara Descending"<<endl;
				shellSorthargadesc(&tanaman[0], size);
				liatTanaman(HEAD);
				cout<<"-----------------------------------------------"<<endl;
				cout<<"Daftar Urutan Barang Berdasarkan Stok Secara Ascending"<<endl;
				shellSortstokasc(&tanaman[0] ,size);
				liatTanaman(HEAD);
				cout<<"-----------------------------------------------"<<endl;
				cout<<"Daftar Urutan Barang Berdasarkan Stok Secara Descending"<<endl;
				shellSortstokdesc(&tanaman[0] ,size);
				liatTanaman(HEAD);
				break;	
			case 6:
				int x, foundItems;
				
				cout<<"Masukkan Harga Barang Yang Anda Cari : "<<endl;
				cin>>x;
				cout<<"Cari Daftar Barang"<<endl;
				size = sizeof(tanaman) / sizeof(tanaman[0]);
				foundItems = jumpSearchharga(&tanaman[0],x, size);
				cout << "\nData Barang " << x << " Berada Pada Index Ke- " << foundItems<<endl;
				break;
			case 7:
				ofstream file("tanaman.csv");
			  	file << "ID, Nama, Jenis, Warna, Harga, Stok\n";
			    for(int i = 0; i < jumlah; i++) {
			    	file <<tanaman[i].id<<","<<tanaman[i].nama<<","<<tanaman[i].jenis<<","<<tanaman[i].warna<<","<<tanaman[i].harga<<","<<tanaman[i].stok<<"\n";
				}
			  	file.close();
			  	break;
			
		}
		if (pilih1 == '8') {
			break;
		}
	}

	cout << "Terimakasih Telah Menggunakan Program Ini" << endl;

	cin.get();
	return 0;
}


void tambahTanaman(Node **head, int &jumlah) {
	Node *itembaru = new Node();
	itembaru->data.id = jumlah+=1;
	cout<<"\nMasukkan nama barang :  " ;	fflush(stdin);getline(cin,itembaru->data.nama);
	cout<<"Masukkan jenis barang :  "; 	fflush(stdin);getline(cin, itembaru->data.jenis);
	cout<<"Masukkan warna barang :  "; 	fflush(stdin);getline(cin,itembaru->data.warna);
	cout<<"Masukkan harga barang :  "; 	cin>>itembaru->data.harga;
	cout<<"Masukkan stok barang :  " ;	cin>>itembaru->data.stok;
	cout<<"\n-----------------------------------\n";
	cout<<
	cout<<"------------------------------------------------------------------"<<endl;
		cout<< "id \t: " <<itembaru->data.id << "\n";
		cout<< "Nama \t: " <<itembaru->data.id << "\n";
		cout<< "Jenis \t: "<<itembaru->data.jenis<< "\n";
		cout<< "Warna \t: "<<itembaru->data.warna<< "\n";
		cout<< "Harga \t: "<<itembaru->data.harga<<"\n";
		cout<< "Stok \t: "<<itembaru->data.stok<<"\n\n"<<endl;
		itembaru->next = NULL;
}
void ubahTanaman(struct Node **head, int &jumlah) {
	Node *itembaru = new Node();
	cout<<"\nMasukkan nama barang :  " ;	fflush(stdin);getline(cin,itembaru->data.nama);
	cout<<"Masukkan jenis barang :  "; 	fflush(stdin);getline(cin,itembaru->data.jenis);
	cout<<"Masukkan warna barang :  "; 	fflush(stdin);getline(cin,itembaru->data.warna);
	cout<<"Masukkan harga barang :  "; 	cin>>itembaru->data.harga;
	cout<<"Masukkan stok barang :  " ;	cin>>itembaru->data.stok;
	cout<<"\n-----------------------------------\n";
}
void liatTanaman(struct Node* itembaru){	

	cout<<"------------------------------------------------------------------"<<endl;
		cout<< "id \t: " <<itembaru->data.id << "\n";
		cout<< "Nama \t: " <<itembaru->data.id << "\n";
		cout<< "Jenis \t: "<<itembaru->data.jenis<< "\n";
		cout<< "Warna \t: "<<itembaru->data.warna<< "\n";
		cout<< "Harga \t: "<<itembaru->data.harga<<"\n";
		cout<< "Stok \t: "<<itembaru->data.stok<<"\n\n"<<endl;
		itembaru->next = NULL;
	
	}

Item temp;


void shellSorthargaasc(Item *tanaman, int &size){
	for (int gap = size/2; gap > 0; gap /= 2) {
		for (int i = gap; i < size; i += 1) {
			temp = tanaman[i];
			int j;
			for (j = i; j >= gap &&  tanaman[j-gap].harga > temp.harga; j -= gap){
				tanaman[j] = tanaman[j - gap];
			}
			tanaman[j] = temp;
		}
	}
}

void shellSorthargadesc(Item *tanaman, int &size){
	for (int gap = size/2; gap > 0; gap /= 2) {
		for (int i = gap; i < size; i += 1) {
			temp = tanaman[i];
			int j;
			for (j = i; j >= gap &&  tanaman[j-gap].harga < temp.harga; j -= gap){
				tanaman[j] = tanaman[j - gap];
			}
			tanaman[j] = temp;
		}
	}
}
void shellSortstokdesc(Item *tanaman, int &size){
	for (int gap = size/2; gap > 0; gap /= 2) {
		for (int i = gap; i < size; i += 1) {
			temp = tanaman[i];
			int j;
			for (j = i; j >= gap &&  tanaman[j-gap].stok < temp.stok; j -= gap){
				tanaman[j] = tanaman[j - gap];
			}
			tanaman[j] = temp;
		}
	}
}

void shellSortstokasc(Item *tanaman, int &size){
	for (int gap = size/2; gap > 0; gap /= 2) {
		for (int i = gap; i < size; i += 1) {
			temp = tanaman[i];
			int j;
			for (j = i; j >= gap &&  tanaman[j-gap].stok > temp.stok; j -= gap){
				tanaman[j] = tanaman[j - gap];
			}
			tanaman[j] = temp;
		}
	}
}




int jumpSearchharga(Item *tanaman, int x, int &size){
	int step = sqrt(size);
	int prev = 0;
	while (tanaman[min(step, size)-1].harga < x){
		prev = step;
		step += sqrt(size);
		if (prev >= size)
		return -1;
		}
	while (tanaman[prev].harga < x){
		prev++;
		if (prev == min(step, size))
		return -1;
		}
		if (tanaman[prev].harga == x)
		return prev;
		return -1;
}






