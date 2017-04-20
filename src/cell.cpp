#include"include/cell.h"
#include<ncurses.h>
using namespace std;

void LandHabitat::render(WINDOW* w, int i, int j, int offi, int offj) {
    init_color(8, 300, 1000, 300);
    init_pair(1, 8, COLOR_GREEN);
    wattron(w, COLOR_PAIR(1));
    mvwprintw(w, i+offi, j+offj, "v");
    wattroff(w, COLOR_PAIR(1));
}

void WaterHabitat::render(WINDOW* w, int i, int j, int offi, int offj) {
    init_pair(2, COLOR_CYAN, COLOR_BLUE);
    wattron(w, COLOR_PAIR(2));
    mvwprintw(w, i+offi, j+offj, "~");
    wattroff(w, COLOR_PAIR(2));
}

void AirHabitat::render(WINDOW* w, int i, int j, int offi, int offj) {
    init_color(9, 600, 600, 600);
    init_pair(3, 9, COLOR_WHITE);
    wattron(w, COLOR_PAIR(3));
    mvwprintw(w, i+offi, j+offj, "~");
    wattroff(w, COLOR_PAIR(3));
}

void Restaurant::render(WINDOW* w, int i, int j, int offi, int offj) {
    init_pair(4, COLOR_WHITE, COLOR_RED);
    wattron(w, COLOR_PAIR(4));
    mvwprintw(w, i+offi, j+offj, "$");
    wattroff(w, COLOR_PAIR(4));
}

void Park::render(WINDOW* w, int i, int j, int offi, int offj) {
    init_color(11, 100, 800, 100);
    init_color(10, 1000, 400, 400);
    init_pair(5, 10, 11);
    wattron(w, COLOR_PAIR(5));
    mvwprintw(w, i+offi, j+offj, "*");
    wattroff(w, COLOR_PAIR(5));
}

void Road::render(WINDOW* w, int i, int j, int offi, int offj) {
    init_pair(6, COLOR_YELLOW, COLOR_BLACK);
    wattron(w, COLOR_PAIR(6));
    mvwprintw(w, i+offi, j+offj, "-");
    wattroff(w, COLOR_PAIR(6));
}
