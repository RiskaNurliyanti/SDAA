#include <iostream>
#include <fstream>
#include <math.h>       /* sqrt */
#include<conio.h>
#include<bits/stdc++.h>
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
	struct Node *next;
    struct Node *prev;
	Item tanaman[100];
};
Node* head = NULL, *tail = NULL, *del;

int size = 0;
void buatDaftarTanaman(Node **head, Node **tail);
void tambahTanaman(Node **head, Node **tail, int insert);
void ubahTanaman(Node *data, int &pilih);
void liatTanaman(Node *dataHead, Node *dataTail, char pos);
void hapusTanaman(struct Node** data, int &posHapus);
void sortMenu(Node *data, int arr[], int menu, string order);
void shellSort(int arr[], int &size, string order);
int jumpSearch(int arr[], int x, int &size);

int menu_awal(){
	int pilih0;

	cout << "\t\t TOKO TANAMAN " <<endl;
	cout<<"\t-----------------------------"<<endl;
	cin.get();
	cout<<"\t\t Daftar Menu "<<endl;
	cout<<"\t-----------------------------"<<endl;
	cout<<"|1.	Buat Daftar Barang	    "<<endl;
	cout<<"|2. 	Lihat Daftar Barang		"<<endl;
	cout<<"|3. 	Tambah Daftar Barang	"<<endl;
	cout<<"|4. 	Update Barang			"<<endl;
	cout<<"|5.	Hapus Daftar Barang		"<<endl;
	cout<<"|6.  	Urutan Daftar Barang            "<<endl;
	cout<<"|7.  	Cari Daftar Barang            "<<endl;
	cout<<"|8.	Simpan Barang ke File Eksternal	"<<endl;
	cout<<"|9.	Keluar					"<<endl;
	
	cout<<" "<<endl;
	cout<<"Pilih Menu Yang Anda Inginkan :"; 
	cin>>pilih0;
	return pilih0;
}

int main(){	
	int jumlah, temp1, posUbah, posHapus;
    Node *temp = head;
	int pilih1=0;
	char lanjut;	
	string temp0;
    int arr[size] = {};
    pilih1 = menu_awal();
    ofstream file ("tanaman.csv", fstream::app);
    
    switch(pilih1) {
        case 1:
            cout << "Tambah Daftar Barang" << endl;
            cout << "Masukan Jumlah Daftar Barang Yang Ingin Dijual : ";
            cin >> jumlah; //Pengguna memasukan jumlah beli
            for(int i = 0; i < jumlah; i++) {
                buatDaftarTanaman(&head, &tail);
                cout<<"\n\nBerhasil!!!";
            }
            main();
            break;
        case 2:
            cout << "Daftar Barang" <<endl;
            if(size == 0){
                cout<<"Masih Kosong";
                main();
            } else {
                char pos;
                cout << "[1] Head ke tail" << endl;
                cout << "[2] Tail ke head" << endl;
                cout << "Menampilkan dari: "; cin >> pos;
                liatTanaman(head, tail, pos);
                main();
            }
            break;
        case 3:
            int insert;
            cout << "Tambah Daftar Barang" << endl;
            cout << "[1] Depan" << endl;
            cout << "[2] Belakang" << endl;
            if(size >= 2) {
                cout << "[3] Posisi Mana Saja" << endl;
            }
            cout << "Menambah dari: "; cin >> insert;
            tambahTanaman(&head, &tail, insert);
            main();
            break;
        case 4:
            cout << "Update Daftar Barang" << endl;
            liatTanaman(head, tail, '1');
            cout<<"Masukkan id barang yg mau diubah :  ";
            cin>>posUbah;
            ubahTanaman(head, posUbah);
            cout << "Data Berhasil Diubah!" << endl;
            main();
            break;
        case 5:
            liatTanaman(head, tail, '1');
            cout<<"Menghapus posisi ke :  ";
            cin>>posHapus;
            hapusTanaman(&head, posHapus);
            main();
            break;
        case 6:
            liatTanaman(head, tail, '1');
            cout<<"Daftar Urutan Barang Berdasarkan Harga Secara Ascending"<<endl;
            arr[size] = {};
            sortMenu(head, arr, 1, "Ascending");
            cout<<"-----------------------------------------------"<<endl;
            cout<<"Daftar Urutan Barang Berdasarkan Harga Secara Descending"<<endl;
            arr[size] = {};
            sortMenu(head, arr, 1, "Descending");
            cout<<"-----------------------------------------------"<<endl;
            cout<<"Daftar Urutan Barang Berdasarkan Stok Secara Ascending"<<endl;
            arr[size] = {};
            sortMenu(head, arr, 2, "Ascending");
            cout<<"-----------------------------------------------"<<endl;
            cout<<"Daftar Urutan Barang Berdasarkan Stok Secara Descending"<<endl;
            arr[size] = {};
            sortMenu(head, arr, 2, "Descending");
            main();
            break;	
        case 7:
            int x, foundItems;
            arr[size] = {};
            sortMenu(head, arr, 1, "Ascending");
            cout<<"Masukkan Harga Barang Yang Anda Cari : "<<endl;
            cin>>x;
            cout<<"Cari Daftar Barang"<<endl;
            liatTanaman(head, tail, '1');
            foundItems = jumpSearch(arr, x, size);
            cout << "\nData Barang " << x << " Berada Pada Index Ke-" << foundItems<<endl;
            main();
            break;
        case 8:
            file << "ID, Nama, Jenis, Warna, Harga, Stok\n";
            while(temp != NULL) {
            	file <<temp->tanaman->id<<","<<temp->tanaman->nama<<","<<temp->tanaman->jenis<<","<<temp->tanaman->warna<<","<<temp->tanaman->harga<<","<<temp->tanaman->stok<<"\n";
                temp = temp->next;
            }
            file.close();
            main();
            break;
        case 9:
	        cout << "Terimakasih Telah Menggunakan Program Ini" << endl;
            exit(0);
            break;
    }
	return 0;
}

void buatDaftarTanaman(Node **head, Node **tail) {
    Node *newNode = new Node();
    newNode->data = size;

    cout<<"\nMasukkan nama barang :  ";	fflush(stdin);getline(cin,newNode->tanaman->nama);
    cout<<"Masukkan jenis barang :  "; 	fflush(stdin);getline(cin,newNode->tanaman->jenis);
    cout<<"Masukkan warna barang :  "; 	fflush(stdin);getline(cin,newNode->tanaman->warna);
    cout<<"Masukkan harga barang :  "; 	cin>>newNode->tanaman->harga;
    cout<<"Masukkan stok barang :  " ;	cin>>newNode->tanaman->stok;
    cout<<"\n-----------------------------------\n";
    newNode->tanaman->id = size+1;
    size++;
    newNode->next == NULL;
    if(*head == NULL) {
        *head = newNode;
        *tail = newNode;
        return;
    }
    newNode->prev = *tail;
    newNode->next = NULL;
    (*tail)->next = newNode;
    (*tail) = newNode;
    return;
}

void liatTanaman(Node *dataHead, Node *dataTail, char pos){	
	cout<<"------------------------------------------------------------------"<<endl;
    if(pos == '1') {
        while(dataHead != NULL) {
            cout<< "id \t: " <<dataHead->tanaman->id << "\n";
            cout<< "Nama \t: " <<dataHead->tanaman->nama << "\n";
            cout<< "Jenis \t: "<<dataHead->tanaman->jenis<< "\n";
            cout<< "Warna \t: "<<dataHead->tanaman->warna<< "\n";
            cout<< "Harga \t: "<<dataHead->tanaman->harga<<"\n";
            cout<< "Stok \t: "<<dataHead->tanaman->stok<<"\n\n"<<endl;
            dataHead = dataHead->next;
        }
    } else if(pos == '2') {
        while(dataTail != NULL) {
            cout<< "id \t: " <<dataTail->tanaman->id << "\n";
            cout<< "Nama \t: " <<dataTail->tanaman->nama << "\n";
            cout<< "Jenis \t: "<<dataTail->tanaman->jenis<< "\n";
            cout<< "Warna \t: "<<dataTail->tanaman->warna<< "\n";
            cout<< "Harga \t: "<<dataTail->tanaman->harga<<"\n";
            cout<< "Stok \t: "<<dataTail->tanaman->stok<<"\n\n"<<endl;
            dataTail = dataTail->prev;
        }
    }
}

void tambahTanaman(Node **head, Node **tail, int insert) {
    Node *newNode = new Node();
    newNode->data = size;

    cout<<"\nMasukkan nama barang :  ";	fflush(stdin);getline(cin,newNode->tanaman->nama);
    cout<<"Masukkan jenis barang :  "; 	fflush(stdin);getline(cin,newNode->tanaman->jenis);
    cout<<"Masukkan warna barang :  "; 	fflush(stdin);getline(cin,newNode->tanaman->warna);
    cout<<"Masukkan harga barang :  "; 	cin>>newNode->tanaman->harga;
    cout<<"Masukkan stok barang :  " ;	cin>>newNode->tanaman->stok;
    cout<<"\n-----------------------------------\n";
    newNode->tanaman->id = size+1;
    size++;
    newNode->next == NULL;
    if(*head == NULL) {
        *head = newNode;
        *tail = newNode;
        return;
    } else {
        if(insert == 1) {
            newNode->prev = NULL;
            newNode->next = *head;
            (*head)->prev = newNode;
            (*head) = newNode;
            return;
        } else if(insert == 2) {
            newNode->prev = *tail;
            newNode->next = NULL;
            (*tail)->next = newNode;
            (*tail) = newNode;
            return;
        } else if(insert == 3) {
            int dari;
            cout << "Menambah di posisi ke-"; cin >> dari;
            Node *cur = *head;
            for(int n = 1; n < dari-1; n++) {
                cur = cur->next;
            }
            Node *afterNode = cur->next;
            newNode->prev = cur;
            newNode->next = afterNode;
            cur->next = newNode;
            afterNode->prev = newNode;
            return;
        }
    }
}

void ubahTanaman(Node *data, int &pilih) {
    while(data != NULL) {
        if(data->tanaman->id == pilih) {
            cout<<"\nMasukkan nama barang :  " ;	fflush(stdin);getline(cin,data->tanaman->nama);
            cout<<"Masukkan jenis barang :  "; 	fflush(stdin);getline(cin,data->tanaman->jenis);
            cout<<"Masukkan warna barang :  "; 	fflush(stdin);getline(cin,data->tanaman->warna);
            cout<<"Masukkan harga barang :  "; 	cin>>data->tanaman->harga;
            cout<<"Masukkan stok barang :  " ;	cin>>data->tanaman->stok;
            cout<<"\n-----------------------------------\n";
            return;
        }
        data = data->next;
    }
	cout << "\nId siswa tidak ditemukan!\n";
	return;
}

void hapusTanaman(struct Node** data, int &posHapus){
	if (data == NULL) {
		cout << "\nData tidak ditemukan!\n";
		return;
	} else {
        Node *cur = *data;
        for(int n = 1; n < posHapus-1; n++) {
            cur = cur->next;
        }
        Node *hapus = cur->next;
        Node *afterNode = hapus->next;
        cur->next = afterNode;
        afterNode->prev = cur;
        size--;
        delete hapus;
        cout<<"\nData telah terhapus!\n";
        return;
    }
}

void sortMenu(Node *data, int arr[], int menu, string order) {
	Node *head2 = data;
	string arr2d[size][6] = {};

    int i = 0;
	if(menu == 1) {
		while(head2 != NULL) {
			arr[i] = head2->tanaman->harga;
			i++;
			head2 = head2->next;
		}
	} else if(menu == 2)  {
		while(head2 != NULL) {
			arr[i] = head2->tanaman->stok;
			i++;
			head2 = head2->next;
		}
	}
    shellSort(arr, size, order);
    for(int r = 0; r < size; r++) {
        cout << arr[r] << " ";
    } cout << endl;
    return;
}

void shellSort(int arr[], int &size, string order){
	for (int gap = size/2; gap > 0; gap /= 2) {
        if(order == "Ascending") {
            for (int i = gap; i < size; i += 1) {
                int temp = arr[i];
                int j;
                for (j = i; j >= gap &&  arr[j-gap] > temp; j -= gap){
                    arr[j] = arr[j - gap];
                }
                arr[j] = temp;
            }
        }
        else if(order == "Descending") {
            for (int i = gap; i < size; i += 1) {
                int temp = arr[i];
                int j;
                for (j = i; j >= gap &&  arr[j-gap] < temp; j -= gap){
                    arr[j] = arr[j - gap];
                }
                arr[j] = temp;
            }
        }
	}
}

int jumpSearch(int arr[], int x, int &size){
	int step = sqrt(size);
	int prev = 0;
	while (arr[min(step, size)-1] < x){
		prev = step;
		step += sqrt(size);
		if (prev >= size) {
		    return -1;
		}
    }
	while (arr[prev] < x){
		prev++;
		if (prev == min(step, size)) {
		    return -1;
		}
    }
    if (arr[prev] == x) {
        return prev;
    }
	return -1;
}
