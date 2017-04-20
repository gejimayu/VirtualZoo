#ifndef ZOO_H
#define ZOO_H

#include"cell.h"
#include"cage.h"

/** Zoo.
 *  Kelas untuk membentuk virtual zoo.
 */
class Zoo {
public:
    /** Constructor.
     *  @param filename File yang dijadikan referensi untuk membuat virtual zoo.
     */
    Zoo(char* filename);
    /** Destructor.
     */
    ~Zoo();
    /** getMap.
     *  Getter untuk mendapatkan peta.
     */
    Cell*** getMap();
    /** getRow.
     *  Getter untuk mendapatkan row.
     */
    int getRow();
    /** getCol.
     *  Getter untuk mendapatkan col.
     */
    int getCol();
    /** getKandang.
     *  Getter untuk mendapatkan kandang.
     */
    Cage** getKandang();
    /** getNCage.
     *  Getter untuk mendapatkan NCage.
     */
    int getNCage();
    /** getTempat.
     *  Getter untuk mendapatkan tempat.
     */
    char** getTempat();
    /** MoveAnimal.
     *  Prosedur Menggerakan hewan dalam kandang secara acak.
     */
    void MoveAnimal();
private:
    /** Matriks Cell yang membentuk virtual zoo.
     *  @see Cell.
     */
    Cell*** peta;
    /** List Cage yang ada di virtual zoo.
     *  @see Cage.
     */
    Cage** kandang;
    /** Jumlah baris di virtual zoo.
     */
    int row;
    /** Jumlah kolom di virtual zoo.
     */
    int col;
    /** Jumlah kandang yang ada di virtual zoo.
     */
    int NCage;
    /** Peta virtual zoo versi karakter.
     *  Digunakan untuk mengidentifikasi jenis objek pada peta.
     */
    char** tempat;
};

#endif // ZOO_H
