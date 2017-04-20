#include"include/driver.h"
#include<ncurses.h>
#include<time.h>
#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;

Driver::Driver(char* s) : Kebun(s) {}

void Driver::CountFood() {
    //Count Foot window initialization
    int NAnimal = 0;
    for(int i=0;i<Kebun.getNCage();i++){
        for(int j=0;j < Kebun.getKandang()[i]->GetNbAnimal();j++){
            NAnimal++;
        }
    }
	int maxrow, maxcol;
	getmaxyx(stdscr, maxrow, maxcol);
	WINDOW* food = newwin(NAnimal+7, 27, (maxrow-NAnimal-7)/2, (maxcol-27)/2);
	keypad(food, TRUE);
	box(food, 0, 0);
	mvwprintw(food, 1, 1, "%-12s%-6s %-6s", "Hewan", "Daging", "Sayur");

	int daging = 0;
	int sayur = 0;
	int count = 0;
    for(int i=0;i<Kebun.getNCage();i++){
        for(int j=0;j < Kebun.getKandang()[i]->GetNbAnimal();j++){
            int tdaging = 0;
            int tsayur = 0;
            Kebun.getKandang()[i]->GetAnimal(j).AddFood(tdaging, tsayur);
            daging += tdaging;
            sayur += tsayur;
            char* temp = Kebun.getKandang()[i]->GetAnimal(j).getNama();
            mvwprintw(food, 2+count, 1, "%-12s%6d%6d", temp, tdaging, tsayur);
            count++;
        }
    }
    mvwprintw(food, NAnimal+3, 1, "Total makanan");
    mvwprintw(food, NAnimal+4, 1, "Daging : %4d", daging);
    mvwprintw(food, NAnimal+5, 1, "Sayur  : %4d", sayur);
    wrefresh(food);
    wgetch(food);

    //count food window termination
    werase(food);
    wrefresh(food);
}

void Driver::Display() {
    //display window initialization
    int maxrow, maxcol, row, col;
	getmaxyx(stdscr, maxrow, maxcol);
	row = Kebun.getRow();
	col = Kebun.getCol();
	WINDOW* display = newwin(7, 36, (maxrow-(7))/2, (maxcol-(36))/2);
	keypad(display, TRUE);
	curs_set(1);
	cbreak();
	echo();

	bool valid = false;
	int startx, starty, endx, endy;
	while (!valid) {
        wmove(display, 3, 1);
        clrtoeol();
        wmove(display, 4, 1);
        clrtoeol();
        box(display, 0, 0);
        mvwprintw(display, 1, 1, "Virtual zoo mulai dari 0,0 - %d,%d", row-1, col-1);
        mvwprintw(display, 2, 1, "%-24s%-5s%-5s", "Masukkan koordinat", "X", "Y");
        mvwprintw(display, 3, 1, "%s", "Kiri Atas");
        mvwprintw(display, 4, 1, "%s", "Kanan Bawah");
        wrefresh(display);
        wmove(display, 3, 25);
        wscanw(display, "%d", &startx);
        wmove(display, 3, 30);
        wscanw(display, "%d", &starty);
        wmove(display, 4, 25);
        wscanw(display, "%d", &endx);
        wmove(display, 4, 30);
        wscanw(display, "%d", &endy);
        if ((startx >= 0) && (startx <= endx) && (endx < row) && (starty >= 0) && (starty <= endy) && (endy < col)) {
            valid = true;
        }
        else {
            mvwprintw(display, 5, 1, "MASUKAN TIDAK VALID!!!");
        }
	}
	werase(display);
	wrefresh(display);


	halfdelay(1);
	curs_set(0);
	noecho();
	display = newwin(endx-startx+3, endy-starty+3, (maxrow-(endx-startx+3))/2, (maxcol-(endy-starty+3))/2);

    int c;
    Cell*** Peta = Kebun.getMap();
	int NCage = Kebun.getNCage();
	Cage** Kandang = Kebun.getKandang();
    clrtoeol();
    mvprintw(0, 0, "Press any key to exit dislay");
    refresh();

	do {
        box(display, 0, 0);
        Kebun.MoveAnimal();
        for(int i = startx; i <= endx; ++i) {
            for(int j = starty; j <= endy; j++) {
                int ada = -1;
                for (int k = 0; (k < NCage) && (ada == -1); k++){
                    if (Kandang[k]->IsPos(i, j)) {
                        ada = k;
                    }
                }
                if (ada != -1) {
                    Kandang[ada]->render(display, i, j, 1-startx, 1-starty);
                }
                else {
                    Peta[i][j]->render(display, i, j, 1-startx, 1-starty);
                }
            }
        }
        refresh();
        wrefresh(display);
	} while ((c = wgetch(display)) == ERR);

	//display window termination
    cbreak();
    werase(display);
    wrefresh(display);
}
/*
void Driver::TourPath(int X, int Y,int ExX,int ExY,int i,bool& PathExist,int*& PathStack){
	if(X==ExX && Y==ExY){
		PathExist=true;
	}
	else if(i<=0 || X<0 || X>=Kebun.getRow() || Y<0 || Y>=Kebun.getCol() || (Kebun.getTempat()[X][Y]!='_' && Kebun.getTempat()[X][Y]!='e')){
		PathExist=false;
	}
	else{
		bool PE;
		//Cek Atas
		TourPath(X-1,Y,ExX,ExY,i-1,PE,PathStack);
		if(PE){
			PathStack[i-1]=1;
			PathExist=true;
		}
		else{
			//Cek Bawah
			TourPath(X+1,Y,ExX,ExY,i-1,PE,PathStack);
			if(PE){
				PathStack[i-1]=2;
				PathExist=true;
			}
			else{
				//Cek Kiri
				TourPath(X,Y-1,ExX,ExY,i-1,PE,PathStack);
				if(PE){
					PathStack[i-1]=3;
					PathExist=true;
				}
				else{
					//Cek Kanan
					TourPath(X,Y+1,ExX,ExY,i-1,PE,PathStack);
					if(PE){
						PathStack[i-1]=4;
						PathExist=true;
					}
				}
			}
		}
	}
}*/

void Driver::TourPath(char** tempat, int X, int Y, int ExX, int ExY, int*Path, bool& PathExist, int& PathLength) {
    if ((X == ExX) && (Y == ExY)) {
        PathExist = true;
    }
    else if ((tempat[X][Y] == ROAD) || (tempat[X][Y] == ENTRANCE)) {
        char temp = tempat[X][Y];
        tempat[X][Y] = 'h';
        if (!PathExist && (X > 0)) {
            Path[PathLength] = 1;
            PathLength++;
            TourPath(tempat, X-1, Y, ExX, ExY, Path, PathExist, PathLength);
            if (!PathExist) {
                PathLength--;
            }
        }
        if (!PathExist && (X < Kebun.getRow()-1)) {
            Path[PathLength] = 2;
            PathLength++;
            TourPath(tempat, X+1, Y, ExX, ExY, Path, PathExist, PathLength);
            if (!PathExist) {
                PathLength--;
            }
        }
        if (!PathExist && (Y > 0)) {
            Path[PathLength] = 3;
            PathLength++;
            TourPath(tempat, X, Y-1, ExX, ExY, Path, PathExist, PathLength);
            if (!PathExist) {
                PathLength--;
            }
        }
        if (!PathExist && (Y < Kebun.getCol()-1)) {
            Path[PathLength] = 4;
            PathLength++;
            TourPath(tempat, X, Y+1, ExX, ExY, Path, PathExist, PathLength);
            if (!PathExist) {
                PathLength--;
            }
        }
        tempat[X][Y] = temp;
    }
}

void Driver::Tour() {
    //Tour window initialization
	ofstream F;
	F.open("debug.txt");
    halfdelay(1);
    int maxrow, maxcol, row, col;
	getmaxyx(stdscr, maxrow, maxcol);
	row = Kebun.getRow();
	col = Kebun.getCol();
	int offset;
	if (col < 65) {
        offset = (65 - col)/2;
	}
	else {
        offset = 0;
	}
	WINDOW* tour = newwin(row+7, col+2*offset+2, (maxrow-(row+7))/2, (maxcol-(col+2*offset+2))/2);
	keypad(tour, TRUE);
	halfdelay(1);

    int c;
    Cell*** Peta = Kebun.getMap();
	int NCage = Kebun.getNCage();
	Cage** Kandang = Kebun.getKandang();
    int EnX, EnY, ExX, ExY;

	F << "ok1" << endl;

	/*//local variable initialization
	int EnX,EnY;
	int ExX,ExY;
	bool AdaEn=false,AdaEx=false;
	for(int i=0;i<Kebun.getRow() && (!AdaEn || !AdaEx);i++){
		for(int j=0;j<Kebun.getCol() && (!AdaEn || !AdaEx);j++){
			if(Kebun.getTempat()[i][j]=='e'){
				EnX=i;
				EnY=j;
			}
			if(Kebun.getTempat()[i][j]=='E'){
				ExX=i;
				ExY=j;
			}
		}
	}
	int *PathStack;
	int PathLength=0;
	bool PathExist=false;
	for(int i=1;i<Kebun.getRow()*Kebun.getCol() && !PathExist;i++){
		PathStack=new int[i];
		TourPath(EnX,EnY,ExX,ExY,i,PathExist,PathStack);
		if(!PathExist){
			delete PathStack;
		}
		else{
			PathLength=i;
		}
	}
	*/
	int En = 0;
	int Ex = 0;
	F << "Row : " << Kebun.getRow() << " Col : " << Kebun.getCol() << endl;
	for(int i=0;i<Kebun.getRow();i++){
        if(Kebun.getTempat()[i][Kebun.getCol()-1]==ENTRANCE){
            En++;
        }
        if(Kebun.getTempat()[i][Kebun.getCol()-1]==EXIT){
            Ex++;
        }
        if(Kebun.getTempat()[i][0]==ENTRANCE){
            En++;
        }
        if(Kebun.getTempat()[i][0]==EXIT){
            Ex++;
        }
	}
    for(int j=0;j<Kebun.getCol();j++){
        if(Kebun.getTempat()[Kebun.getRow()-1][j]==ENTRANCE){
            En++;
        }
        if(Kebun.getTempat()[Kebun.getRow()-1][j]==EXIT){
            Ex++;
        }
        if(Kebun.getTempat()[0][j]==ENTRANCE){
            En++;
        }
        if(Kebun.getTempat()[0][j]==EXIT){
            Ex++;
        }
	}
	F << En << " " << Ex << endl;
	En = rand() % En;
	Ex = rand() % Ex;
	F << En << " " << Ex << endl;
	for(int i=0;i<Kebun.getRow();i++){
        if(Kebun.getTempat()[i][Kebun.getCol()-1]==ENTRANCE){
            if (En == 0) {
                EnX = i;
                EnY = Kebun.getCol()-1;
            }
            En--;
        }
        if(Kebun.getTempat()[i][Kebun.getCol()-1]==EXIT){
            if (Ex == 0) {
                ExX = i;
                ExY = Kebun.getCol()-1;
            }
            Ex--;
        }
        if(Kebun.getTempat()[i][0]==ENTRANCE){
            if (En == 0) {
                EnX = i;
                EnY = 0;
            }
            En--;
        }
        if(Kebun.getTempat()[i][0]==EXIT){
            if (Ex == 0) {
                ExX = i;
                ExY = 0;
            }
            Ex--;
        }
	}
    for(int j=0;j<Kebun.getCol();j++){
        if(Kebun.getTempat()[Kebun.getRow()-1][j]==ENTRANCE){
            if (En == 0) {
                EnX = Kebun.getRow()-1;
                EnY = j;
            }
            En--;
        }
        if(Kebun.getTempat()[Kebun.getRow()-1][j]==EXIT){
            if (Ex == 0) {
                ExX = Kebun.getRow()-1;
                ExY = j;
            }
            Ex--;
        }
        if(Kebun.getTempat()[0][j]==ENTRANCE){
            if (En == 0) {
                EnX = 0;
                EnY = j;
            }
            En--;
        }
        if(Kebun.getTempat()[0][j]==EXIT){
            if (Ex == 0) {
                ExX = 0;
                ExY = j;
            }
            Ex--;
        }
	}
	F << "From : " << EnX << " " << EnY << " to : " << ExX << " " << ExY << endl;
	bool PathExist = false;
	int* Path = new int [(row+1)*(col+1)];
	int PathLength = 0;
	int PX = EnX,PY = EnY;
	TourPath(Kebun.getTempat(), EnX, EnY, ExX, ExY, Path, PathExist, PathLength);

	//display tour
	if (PathExist) {
        F << "Path Exist" << endl;
        for (int k = 0; k <= PathLength; k++) {
            F << k << endl;
            wmove(tour, row+2, 1);
            wclrtoeol(tour);
            wmove(tour, row+3, 1);
            wclrtoeol(tour);
            wmove(tour, row+4, 1);
            wclrtoeol(tour);
            wmove(tour, row+5, 1);
            wclrtoeol(tour);
            bool Ada=false;
            //Interact Kiri
            for(int i=0;i<Kebun.getNCage() && !Ada;i++){
                if(Kebun.getKandang()[i]->IsPos(PX-1,PY)){
                    bool Ada2=false;
                    for(int j=0;j < Kebun.getKandang()[i]->GetNbAnimal() && !Ada2;j++){
                        if(Kebun.getKandang()[i]->GetAnimal(j).GetX()==PX-1 && Kebun.getKandang()[i]->GetAnimal(j).GetY()==PY){
                            Kebun.getKandang()[i]->GetAnimal(j).Interact(tour, row+2, 1);
                            Ada2=true;
                        }
                    }
                    Ada=true;
                }
            }
            //Interact Kanan
            for(int i=0;i<Kebun.getNCage() && !Ada;i++){
                if(Kebun.getKandang()[i]->IsPos(PX+1,PY)){
                    bool Ada2=false;
                    for(int j=0;j < Kebun.getKandang()[i]->GetNbAnimal() && !Ada2;j++){
                        if(Kebun.getKandang()[i]->GetAnimal(j).GetX()==PX+1 && Kebun.getKandang()[i]->GetAnimal(j).GetY()==PY){
                            Kebun.getKandang()[i]->GetAnimal(j).Interact(tour, row+2, 1);
                            Ada2=true;
                        }
                    }
                    Ada=true;
                }
            }
            //Interact Atas
            for(int i=0;i<Kebun.getNCage() && !Ada;i++){
                if(Kebun.getKandang()[i]->IsPos(PX,PY-1)){
                    bool Ada2=false;
                    for(int j=0;j < Kebun.getKandang()[i]->GetNbAnimal() && !Ada2;j++){
                        if(Kebun.getKandang()[i]->GetAnimal(j).GetX()==PX && Kebun.getKandang()[i]->GetAnimal(j).GetY()==PY-1){
                            Kebun.getKandang()[i]->GetAnimal(j).Interact(tour, row+2, 1);
                            Ada2=true;
                        }
                    }
                    Ada=true;
                }
            }
            //Interact Bawah
            for(int i=0;i<Kebun.getNCage() && !Ada;i++){
                if(Kebun.getKandang()[i]->IsPos(PX,PY+1)){
                    bool Ada2=false;
                    for(int j=0;j < Kebun.getKandang()[i]->GetNbAnimal() && !Ada2;j++){
                        if(Kebun.getKandang()[i]->GetAnimal(j).GetX()==PX && Kebun.getKandang()[i]->GetAnimal(j).GetY()==PY+1){
                            Kebun.getKandang()[i]->GetAnimal(j).Interact(tour, row+2, 1);
                            Ada2=true;
                        }
                    }
                    Ada=true;
                }
            }
            do {
                box(tour, 0, 0);
                wmove(tour, row+1, 0);
                waddch(tour, ACS_LTEE);
                wmove(tour, row+1, 1);
                whline(tour, ACS_HLINE, col+2*offset);
                wmove(tour, row+1, col+2*offset+1);
                waddch(tour, ACS_RTEE);
                Kebun.MoveAnimal();
                for(int i = 0; i < row; ++i) {
                    for(int j = 0; j < col; j++) {
                        int ada = -1;
                        for (int k = 0; (k < NCage) && (ada == -1); k++){
                            if (Kandang[k]->IsPos(i, j)) {
                                ada = k;
                            }
                        }
                        if (PX == i && PY == j) {
                            mvwprintw(tour, i+1, j+offset+1, "P");
                        }
                        else if (ada != -1) {
                            Kandang[ada]->render(tour, i, j, 1, offset+1);
                        }
                        else {
                            Peta[i][j]->render(tour, i, j, 1, offset+1);
                        }
                    }
                }
                wrefresh(tour);
            } while ((c = wgetch(tour)) == ERR);
            if ((k < PathLength) && (k >= 0)) {
                switch(Path[k]){
                    case 1:
                        PX-=1;
                        break;
                    case 2:
                        PX+=1;
                        break;
                    case 3:
                        PY-=1;
                        break;
                    case 4:
                        PY+=1;
                        break;
                }
            }
        }
	}
	else {
        F << "No path" << endl;
	}
	F.close();
	wmove(tour, row+2, 1);
    wclrtoeol(tour);
    wmove(tour, row+3, 1);
    wclrtoeol(tour);
    wmove(tour, row+4, 1);
    wclrtoeol(tour);
    wmove(tour, row+5, 1);
    wclrtoeol(tour);
    box(tour, 0, 0);

    mvwprintw(tour, row+2, 1, "The tour has finished");
    mvwprintw(tour, row+3, 1, "Hope you enjoyed it");
    mvwprintw(tour, row+4, 1, "We'll be glad to have you here again");
    mvwprintw(tour, row+5, 1, "Good bye!!");

	//tour window termination
	delete [] Path;
    cbreak();
    wrefresh(tour);
    wgetch(tour);
    werase(tour);
    wrefresh(tour);
}

void Driver::Menu() {
    char *choices[] = {
			"Display Zoo",
			"Tour Zoo",
			"Count Food",
			"Exit",
		  };
    int n_choices = sizeof(choices) / sizeof(char *);
    srand(time(NULL));

    //ncurses initialization
    initscr();
	clear();
	noecho();
	cbreak();
	curs_set(0);
	start_color();

	//menu window initialization
	int maxrow, maxcol;
	getmaxyx(stdscr, maxrow, maxcol);
	WINDOW* menu = newwin(10, 26, (maxrow-10)/2, (maxcol-26)/2);
	keypad(menu, TRUE);

	int highlight = 0;
    int choice = 0;
    int c;

	do {
        int x = 2;
        int y = 3;
        box(menu, 0, 0);
        mvwprintw(menu, 1, 2, "Welcome to Virtual Zoo");
        for(int i = 0; i < n_choices; ++i)
        {
            if(highlight == i) /* High light the present choice */
            {	wattron(menu, A_REVERSE);
                mvwprintw(menu, y, x, "%s", choices[i]);
                wattroff(menu, A_REVERSE);
            }
            else
                mvwprintw(menu, y, x, "%s", choices[i]);
            ++y;
        }
        wrefresh(menu);
        c = wgetch(menu);
        switch(c)
		{	case KEY_UP:
                highlight = (highlight + n_choices - 1) % n_choices;
				break;
			case KEY_DOWN:
                highlight = (highlight + n_choices + 1) % n_choices;
				break;
			case 10:
				choice = highlight;
				if (choice == 0) {
                    werase(menu);
                    wrefresh(menu);
                    Display();
				}
				else if (choice == 1) {
                    werase(menu);
                    wrefresh(menu);
                    Tour();
				}
				else if (choice == 2) {
                    werase(menu);
                    wrefresh(menu);
                    CountFood();
				}
				break;
		}
		move(0,0);
		clrtoeol();
		mvprintw(0,0,"Choice : %s", choices[choice]);
		refresh();
	} while (choice != n_choices-1);

	//terminate ncurses
	endwin();
}

