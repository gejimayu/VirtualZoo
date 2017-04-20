#include<iostream>
#include"include/driver.h"
using namespace std;

int main() {
    char* file = "src/data/map.txt";
    Driver Z(file);
    Z.Menu();

    return 0;
}
