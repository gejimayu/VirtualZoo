#include "include/cage.h"
#include <iostream>
using namespace std;

//CAGE
Cage::Cage(int n, int *X, int *Y){
	H=new int*[2];
	H[0]=new int[n];//Inisisasi Penyimpanan Absis
	H[1]=new int[n];//Inisisasi Penyimpanan Ordinat
	for(int i=0;i<n;i++){
		H[0][i]=X[i];//Penyimpanan Absis
		H[1][i]=Y[i];//Penyimpanan Ordinat
	}
	size=n;
}

Cage::~Cage(){
	delete [] H[0];//hapus penyimpanan absis
	delete [] H[1];//hapus penyimpanan ordinat
	delete [] H;
}

bool Cage::IsPos(int X, int Y){
	bool found=false;//Inisialisasi
	int i=0;
	while(i<size && !found){
		if(H[0][i]==X && H[1][i]==Y){//Pengecekanan keberadaan koordinat
			found=true;//keluar loop jika ada
		}
		else{
			i++;//inkremen i jika tidak ada
		}
	}
	return found;//pengembalian nilai found
}

int Cage::GetNbAnimal(){
	return NbAnimal;
}

int Cage::GetSize(){
	return size;
}



//LANDCAGE
LandCage::LandCage(int n, int *X, int *Y):Cage(n,X,Y){
	int U;
	U = (0.3)*(n);//Menghitung maksimum jumlah Animal
	A=new LandAnimal*[U];//Pemesanan array
}

LandCage::~LandCage(){
    for (int i = 0; i < NbAnimal; i++) {
        delete A[i];
    }
	delete [] A;//menghapus array
}

void LandCage::render(WINDOW* w, int i, int j, int offi, int offj){
    init_color(12, 0, 1000, 0);
    init_pair(7, COLOR_WHITE, 12);
    wattron(w, COLOR_PAIR(7));
    int ada = -1;
    for (int k = 0; (k < NbAnimal) && (ada == -1); k++) {
        if ((A[k]->GetX() == i) && (A[k]->GetY() == j)) {
            ada = k;
        }
    }
    if (ada == -1) {
        mvwprintw(w, i+offi, j+offj, " ");
    }
    else {
        A[ada]->render(w, i, j, offi, offj);
    }
    wattroff(w, COLOR_PAIR(7));
}

void LandCage::AddAnimal(Animal* L){
	A[NbAnimal]=dynamic_cast<LandAnimal*>(L);//Pengisian array
	NbAnimal++;//Menambah nilai atribut jumlah Animal
}

Animal& LandCage::GetAnimal(int i){
	return *A[i];
}

void LandCage::MoveAnimal(int i, int movement){
	if(i>=0 && i<NbAnimal){//pengecekan i adalah indeks salah satu Animal di cage
		int X=A[i]->GetX();
		int Y=A[i]->GetY();
		switch(movement){
			case 1:
				if(IsPos(X-1,Y)){//Pengecekan bisa bergerak ke atas
					A[i]->SetX(X-1);//Bergerak ke atas
				}
				break;
			case 2:
				if(IsPos(X+1,Y)){//Pengecekan bisa bergerak ke bawah
					A[i]->SetX(X+1);//Bergerak ke bawah
				}
				break;
			case 3:
				if(IsPos(X,Y-1)){//Pengecekan bisa bergerak ke kiri
					A[i]->SetY(Y-1);//Bergerak ke kiri
				}
				break;
			case 4:
				if(IsPos(X,Y+1)){//Pengecekan bisa bergerak ke kanan
					A[i]->SetY(Y+1);//Bergerak ke kanan
				}
				break;
		}
	}
}

//WATERCAGE
WaterCage::WaterCage(int n, int *X, int *Y):Cage(n,X,Y){
	int U;
	U = (0.3)*(n);//Menghitung maksimum jumlah Animal
	A=new WaterAnimal*[U];//Pemesanan array
}

WaterCage::~WaterCage(){
    for (int i = 0; i < NbAnimal; i++) {
        delete A[i];
    }
	delete [] A;//menghapus array
}

void WaterCage::render(WINDOW* w, int i, int j, int offi, int offj){
    init_color(13, 0, 0, 800);
    init_pair(8, COLOR_WHITE, 13);
    wattron(w, COLOR_PAIR(8));
    int ada = -1;
    for (int k = 0; (k < NbAnimal) && (ada == -1); k++) {
        if ((A[k]->GetX() == i) && (A[k]->GetY() == j)) {
            ada = k;
        }
    }
    if (ada == -1) {
        mvwprintw(w, i+offi, j+offj, " ");
    }
    else {
        A[ada]->render(w, i, j, offi, offj);
    }
    wattroff(w, COLOR_PAIR(8));
}

void WaterCage::AddAnimal(Animal* L){
	A[NbAnimal]=dynamic_cast<WaterAnimal*>(L);//Pengisian array
	NbAnimal++;//Menambah nilai atribut jumlah Animal
}

Animal& WaterCage::GetAnimal(int i){
	return *A[i];
}

void WaterCage::MoveAnimal(int i, int movement){
	if(i>=0 && i<NbAnimal){//pengecekan i adalah indeks salah satu Animal di cage
		int X=A[i]->GetX();
		int Y=A[i]->GetY();
		switch(movement){
			case 1:
				if(IsPos(X-1,Y)){//Pengecekan bisa bergerak ke atas
					A[i]->SetX(X-1);//Bergerak ke atas
				}
				break;
			case 2:
				if(IsPos(X+1,Y)){//Pengecekan bisa bergerak ke bawah
					A[i]->SetX(X+1);//Bergerak ke bawah
				}
				break;
			case 3:
				if(IsPos(X,Y-1)){//Pengecekan bisa bergerak ke kiri
					A[i]->SetY(Y-1);//Bergerak ke kiri
				}
				break;
			case 4:
				if(IsPos(X,Y+1)){//Pengecekan bisa bergerak ke kanan
					A[i]->SetY(Y+1);//Bergerak ke kanan
				}
				break;
		}
	}
}

//AIRCAGE
AirCage::AirCage(int n, int *X, int *Y):Cage(n,X,Y){
	int U;
	U = (0.3)*(n);//Menghitung maksimum jumlah Animal
	A=new AirAnimal*[U];//Pemesanan array
}

AirCage::~AirCage(){
    for (int i = 0; i < NbAnimal; i++) {
        delete A[i];
    }
	delete [] A;//menghapus array
}

void AirCage::render(WINDOW* w, int i, int j, int offi, int offj){
    init_color(14, 800, 800, 800);
    init_pair(9, COLOR_BLACK, 14);
    wattron(w, COLOR_PAIR(9));
    int ada = -1;
    for (int k = 0; (k < NbAnimal) && (ada == -1); k++) {
        if ((A[k]->GetX() == i) && (A[k]->GetY() == j)) {
            ada = k;
        }
    }
    if (ada == -1) {
        mvwprintw(w, i+offi, j+offj, " ");
    }
    else {
        A[ada]->render(w, i, j, offi, offj);
    }
    wattroff(w, COLOR_PAIR(9));
}

void AirCage::AddAnimal(Animal* L){
	A[NbAnimal]=dynamic_cast<AirAnimal*>(L);//Pengisian array
	NbAnimal++;//Menambah nilai atribut jumlah Animal
}

Animal& AirCage::GetAnimal(int i){
	return *A[i];
}

void AirCage::MoveAnimal(int i, int movement){
	if(i>=0 && i<NbAnimal){//pengecekan i adalah indeks salah satu Animal di cage
		int X=A[i]->GetX();
		int Y=A[i]->GetY();
		switch(movement){
			case 1:
				if(IsPos(X-1,Y)){//Pengecekan bisa bergerak ke atas
					A[i]->SetX(X-1);//Bergerak ke atas
				}
				break;
			case 2:
				if(IsPos(X+1,Y)){//Pengecekan bisa bergerak ke bawah
					A[i]->SetX(X+1);//Bergerak ke bawah
				}
				break;
			case 3:
				if(IsPos(X,Y-1)){//Pengecekan bisa bergerak ke kiri
					A[i]->SetY(Y-1);//Bergerak ke kiri
				}
				break;
			case 4:
				if(IsPos(X,Y+1)){//Pengecekan bisa bergerak ke kanan
					A[i]->SetY(Y+1);//Bergerak ke kanan
				}
				break;
		}
	}
}
