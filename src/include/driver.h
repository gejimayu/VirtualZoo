#ifndef DRIVER_H
#define DRIVER_H

#include"zoo.h"

/** Driver.
 *  Kelas untuk menjalankan virtual zoo.
 */
class Driver {
public:
    /** Constructor.
     *  @param filename File yang dijadikan referensi untuk membuat virtual zoo.
     */
    Driver(char* filename);
    /** Menampilkan pilihan menu.
     */
    void Menu();
    /** Menampilkan virtual zoo.
     */
    void Display();
    /** mengadakan tour di dalam virtual zoo.
     */
    void Tour();
    /** Menghitung total makanan yang dibutuhkan virtual zoo.
     */
    void CountFood();
private:
    //** Mencari jalur ke jalan keluar untuk Tour dalam virtual zoo.
     /*  @param X Baris zoo yang sedang ditinjau.
     *  @param Y Kolom zoo yang sedang ditinjau.
     *  @param ExX Baris letak jalan keluar.
     *  @param ExY Kolom letak jalan keluar.
     *  @param i Membatasi agar rekurens tidak dilakukan terus menerus dan berfungsi untuk inkremen IDS.
     *  @param PathExist Mengembalikan true jika menemukan jalur ke jalan keluar dan false jika tidak.
     *  @param PathStack Stack yang berisi runtutan gerakan untuk jalur ke jalan keluar.
     *  1. Atas
     *  2. Bawah
     *  3. Kiri
     *  4. Kanan
     */
    //void TourPath(int X,int Y, int ExX, int ExY,int i, bool& PathExist, int*& PathStack);
    void TourPath(char** tempat, int EnX, int EnY, int ExX, int ExY, int*Path, bool& PathExist, int& PathLength);
    /** Data virtual zoo bertipe Zoo.
     *  @see Zoo.
     */
    Zoo Kebun;
};

#endif // DRIVER_H
