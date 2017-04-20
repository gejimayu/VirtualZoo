#include"include/zoo.h"
#include<iostream>
#include<fstream>
#include<ncurses.h>
#include<time.h>
using namespace std;

void floodfill(char** c, int row, int col, int* x, int* y, int& n, int i, int j, char key) {
    if (i >= 0 && i < row && j >= 0 && j < col) {
        if (c[i][j] == key) {
            c[i][j] = '.';
            x[n] = i;
            y[n] = j;
            n++;
            floodfill(c, row, col, x, y, n, i+1, j, key);
            floodfill(c, row, col, x, y, n, i-1, j, key);
            floodfill(c, row, col, x, y, n, i, j+1, key);
            floodfill(c, row, col, x, y, n, i, j-1, key);
        }
    }
}

void floodfill(char** c, int row, int col, int i, int j, char key) {
    if (i >= 0 && i < row && j >= 0 && j < col) {
        if (c[i][j] == key) {
            c[i][j] = '.';
            floodfill(c, row, col, i+1, j, key);
            floodfill(c, row, col, i-1, j, key);
            floodfill(c, row, col, i, j+1, key);
            floodfill(c, row, col, i, j-1, key);
        }
    }
}

Zoo::Zoo(char* filename)
{
    ifstream F;
    F.open(filename);
    F >> row >> col;
    peta = new Cell** [row];
    for (int i = 0; i < row; i++) {
        peta[i] = new Cell* [col];
    }
    char** kar = new char* [row];
    for (int i = 0; i < row; i++) {
        kar[i] = new char [col];
    }
    char** temp = new char* [row];
    for (int i = 0; i < row; i++) {
        temp[i] = new char [col];
    }
    tempat = new char* [row];
    for (int i = 0; i < row; i++) {
        tempat[i] = new char [col];
    }

    //init map
    char c;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            F >> c;
            kar[i][j] = c;
            temp[i][j] = c;
            tempat[i][j] = c;
            switch (c) {
                case LANDHABITAT : {
                    peta[i][j] = new LandHabitat;
                    break;
                }
                case LANDCAGE : {
                    peta[i][j] = new LandHabitat;
                    break;
                }
                case WATERHABITAT : {
                    peta[i][j] = new WaterHabitat;
                    break;
                }
                case WATERCAGE : {
                    peta[i][j] = new WaterHabitat;
                    break;
                }
                case AIRHABITAT : {
                    peta[i][j] = new AirHabitat;
                    break;
                }
                case AIRCAGE : {
                    peta[i][j] = new AirHabitat;
                    break;
                }
                case RESTAURANT : {
                    peta[i][j] = new Restaurant;
                    break;
                }
                case PARK : {
                    peta[i][j] = new Park;
                    break;
                }
                case ROAD : {
                    peta[i][j] = new Road;
                    break;
                }
                case EXIT : {
                    peta[i][j] = new Exit;
                    break;
                }
                case ENTRANCE : {
                    peta[i][j] = new Entrance;
                    break;
                }
            }
        }
    }

    //init cage
    int* x = new int[row*col];
    int* y = new int[row*col];
    int n = 0;
    NCage = 0;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            switch(temp[i][j]) {
                case LANDCAGE:
                    floodfill(temp, row, col, i, j, LANDCAGE);
                    n++;
                    break;
                case WATERCAGE:
                    floodfill(temp, row, col, i, j, WATERCAGE);
                    n++;
                    break;
                case AIRCAGE:
                    floodfill(temp, row, col, i, j, AIRCAGE);
                    n++;
                    break;
            }
        }
    }
    kandang = new Cage* [n];
    n = 0;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            switch(kar[i][j]) {
                case LANDCAGE:
                    floodfill(kar, row, col, x, y, n, i, j, LANDCAGE);
                    kandang[NCage] = new LandCage(n, x, y);
                    NCage++;
                    n = 0;
                    break;
                case WATERCAGE:
                    floodfill(kar, row, col, x, y, n, i, j, WATERCAGE);
                    kandang[NCage] = new WaterCage(n, x, y);
                    NCage++;
                    n = 0;
                    break;
                case AIRCAGE:
                    floodfill(kar, row, col, x, y, n, i, j, AIRCAGE);
                    kandang[NCage] = new AirCage(n, x, y);
                    NCage++;
                    n = 0;
                    break;
            }
        }
    }

    //Isi Animal ke cage
    Animal** A;
    int NbAnimal;
    string Species;
    float Berat;
    bool Buas;
    int PosX,PosY;
	F >> NbAnimal;
	A=new Animal*[NbAnimal];
	for(int i=0;i<NbAnimal;i++){
		bool Masuk=false;
		F >> Species;
		F >> Berat;
		F >> Buas;
		F >> PosX >> PosY;
		if(!Buas){
			bool found=false;
			int j;
			for(j=0;j<NCage && !found;j++){
				if(kandang[j]->IsPos(PosX,PosY)){
					found = true;
				}
			}
			j--;
			if(found){
				bool foundbuas=false;
				for(int k=0;k<kandang[j]->GetNbAnimal() && !foundbuas;k++){
					if(kandang[j]->GetAnimal(k).GetBuas()){
						foundbuas=true;
					}
				}
				if(!foundbuas && kandang[j]->GetNbAnimal()<=(kandang[j]->GetSize()*0.3)){
					Masuk=true;
				}
				else{
					Masuk=false;
				}
			}
			else{
				Masuk=false;
			}
		}
		else{
			bool found=false;
			int j;
			for(j=0;j<NCage && !found;j++){
				if(kandang[j]->IsPos(PosX,PosY)){
					found = true;
				}
			}
			j--;
			if(found && kandang[j]->GetNbAnimal() > 0){
				Masuk=false;
			}
			else{
				Masuk=true;
			}
		}


		if(Masuk){
			if(Species=="Tiger"){
				A[i]=new Tiger(Berat,Buas,PosX,PosY);
			}
			else if(Species=="Sea_Lion"){
				A[i]=new Sea_Lion(Berat,Buas,PosX,PosY);
			}
			else if(Species=="Zebra"){
				A[i]=new Zebra(Berat,Buas,PosX,PosY);
			}
			else if(Species=="Lion"){
				A[i]=new Lion(Berat,Buas,PosX,PosY);
			}
			else if(Species=="Hipopotamus"){
				A[i]=new Hipopotamus(Berat,Buas,PosX,PosY);
			}
			else if(Species=="Penguin"){
				A[i]=new Penguin(Berat,Buas,PosX,PosY);
			}
			else if(Species=="Monkey"){
				A[i]=new Monkey(Berat,Buas,PosX,PosY);
			}
			else if(Species=="OrangUtan"){
				A[i]=new OrangUtan(Berat,Buas,PosX,PosY);
			}
			else if(Species=="Bear"){
				A[i]=new Bear(Berat,Buas,PosX,PosY);
			}
			else if(Species=="Giraffe"){
				A[i]=new Giraffe(Berat,Buas,PosX,PosY);
			}
			else if(Species=="Peacock"){
				A[i]=new Peacock(Berat,Buas,PosX,PosY);
			}
			else if(Species=="Eagle"){
				A[i]=new Eagle(Berat,Buas,PosX,PosY);
			}
			else if(Species=="Dolphin"){
				A[i]=new Dolphin(Berat,Buas,PosX,PosY);
			}
			else if(Species=="Shark"){
				A[i]=new Shark(Berat,Buas,PosX,PosY);
			}
			else if(Species=="Horse"){
				A[i]=new Horse(Berat,Buas,PosX,PosY);
			}
			else if(Species=="Snake"){
				A[i]=new Snake(Berat,Buas,PosX,PosY);
			}
			else if(Species=="Panda"){
				A[i]=new Panda(Berat,Buas,PosX,PosY);
			}
			else if(Species=="Turtle"){
				A[i]=new Turtle(Berat,Buas,PosX,PosY);
			}
			else if(Species=="Alligator"){
				A[i]=new Alligator(Berat,Buas,PosX,PosY);
			}
			else if(Species=="Kangoroo"){
				A[i]=new Kangoroo(Berat,Buas,PosX,PosY);
			}
			bool found=false;
			for(int j=0;j<NCage && !found; j++){
				if(kandang[j]->IsPos(PosX,PosY)){
					kandang[j]->AddAnimal(A[i]);
					found=true;
				}
			}
		}
	}

}

Zoo::~Zoo()
{
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            delete peta[i][j];
        }
    }
    for (int i = 0; i < row; i++) {
        delete [] peta[i];
    }
    delete [] peta;
    for (int i = 0; i < NCage; i++) {
        delete kandang[i];
    }
    delete kandang;
    for (int i = 0; i < row; i++) {
        delete [] tempat[i];
    }
    delete [] tempat;
}

Cell*** Zoo::getMap()
{
    return peta;
}

int Zoo::getRow()
{
    return row;
}

int Zoo::getCol()
{
    return col;
}

Cage** Zoo::getKandang()
{
    return kandang;
}

int Zoo::getNCage()
{
    return NCage;
}

char** Zoo::getTempat(){
	return tempat;
}

void Zoo::MoveAnimal(){
	int Move;
	for(int i=0;i<NCage;i++){
		for(int j=0;j<kandang[i]->GetNbAnimal();j++){
			Move=rand() % 10;
			if (Move == 0) {
                bool ok = false;
                while (!ok) {
                    Move = rand()%4+1;
                    int X = kandang[i]->GetAnimal(j).GetX();
                    int Y = kandang[i]->GetAnimal(j).GetY();
                    if ((Move == 1) && kandang[i]->IsPos(X-1,Y)) {
                        ok = true;
                    }
                    else if ((Move == 2) && kandang[i]->IsPos(X+1,Y)) {
                        ok = true;
                    }
                    else if ((Move == 3) && kandang[i]->IsPos(X,Y-1)) {
                        ok = true;
                    }
                    else if ((Move == 4) && kandang[i]->IsPos(X,Y+1)) {
                        ok = true;
                    }
                }
                kandang[i]->MoveAnimal(j,Move);
			}
		}
	}
}
