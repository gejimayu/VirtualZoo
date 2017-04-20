#ifndef CAGE_H
#define CAGE_H

#include "cell.h"
#include "animal.h"

#define LANDCAGE 'L'
#define WATERCAGE 'W'
#define AIRCAGE 'A'

/** Cage.
 *  Kelas abstrak untuk kandang.
 */
class Cage : public Renderable{
protected:
    /** Matriks untuk menyimpan koordinat.
     *  H[0] untuk baris. H[1] untuk kolom.
     */
	int **H;
    /** Ukuran kandang.
     */
	int size;
    /** Jumlah hewan dalam kandang.
     */
	int NbAnimal=0;
public:
    /** Constructor.
     *  @param n Jumlah hewan dalam kandang.
     *  @param X List posisi baris hewan.
     *  @param Y List posisi kolom hewan.
     */
	Cage(int n, int *X, int *Y);
    /** Destructor.
     */
	virtual ~Cage();
    /** Menampilkan kandang pada layar.
     *  @param w Lokasi window tempat render.
     *  @param i Posisi baris zoo.
     *  @param j Posisi kolom zoo.
     *  @param offi Offset baris terhadap lokasi render.
     *  @param offj Offset kolom terhadap lokasi render.
     */
	virtual void render(WINDOW* w, int i, int j, int offi, int offj)=0;
    /** Memeriksa apakah posisi (X,Y) ada di kandang.
     *  @param X Posisi baris.
     *  @param Y Posisi kolom.
     */
	bool IsPos(int X, int Y);
    /** Menambahkan hewan ke dalam kandang.
     *  @param A Pointer menuju hewan yang akan ditambahkan.
     */
	virtual void AddAnimal(Animal* A)=0;
    /** Mengembalikan hewan ke-i yang ada di kandang.
     *  @param i Indeks untuk hewan yang ada di kandang.
     */
	virtual Animal& GetAnimal(int i)=0;
    /** Menggerakan hewan ke-i di dalam kandang.
     *  @param i Indeks hewan di kandang.
     *  @param movement Gerakan yang dilakukan.
     *  1. Atas
     *  2. Bawah
     *  3. Kiri
     *  4. Kanan
     */
	virtual void MoveAnimal(int i, int movement)=0;
    /** Mengembalikan jumlah hewan yang ada di kandang.
     */
	int GetNbAnimal();
	/**Mengembalikan ukuran dari kandang
	 */
	int GetSize();
};

/** LandCage.
 *  Kelas abstrak untuk kandang hewan darat.
 */
class LandCage : public Cage{
protected:
    /** List hewan yang ada di kandang.
     */
	LandAnimal **A;
public:
    /** Constructor.
     *  @param n Jumlah hewan dalam kandang.
     *  @param X List posisi baris hewan.
     *  @param Y List posisi kolom hewan.
     */
	LandCage(int n, int *X, int *Y);
    /** Destructor.
     */
	~LandCage();
    /** Menampilkan kandang pada layar.
     *  @param w Lokasi window tempat render.
     *  @param i Posisi baris zoo.
     *  @param j Posisi kolom zoo.
     *  @param offi Offset baris terhadap lokasi render.
     *  @param offj Offset kolom terhadap lokasi render.
     */
	void render(WINDOW* w, int i, int j, int offi, int offj);
    /** Menambahkan hewan ke dalam kandang.
     *  @param A Pointer menuju hewan yang akan ditambahkan.
     */
	void AddAnimal(Animal* A);
    /** Mengembalikan hewan ke-i yang ada di kandang.
     *  @param i Indeks untuk hewan yang ada di kandang.
     */
	Animal& GetAnimal(int i);
    /** Menggerakan hewan ke-i di dalam kandang.
     *  @param i Indeks hewan di kandang.
     *  @param movement Gerakan yang dilakukan.
     *  1. Atas
     *  2. Bawah
     *  3. Kiri
     *  4. Kanan
     */
	void MoveAnimal(int i, int movement);
};

/** WaterCage.
 *  Kelas abstrak untuk kandang hewan air.
 */
class WaterCage : public Cage{
protected:
    /** List hewan yang ada di kandang.
     */
	WaterAnimal **A;
public:
    /** Constructor.
     *  @param n Jumlah hewan dalam kandang.
     *  @param X List posisi baris hewan.
     *  @param Y List posisi kolom hewan.
     */
	WaterCage(int n, int *X, int *Y);
    /** Destructor.
     */
	~WaterCage();
    /** Menampilkan kandang pada layar.
     *  @param w Lokasi window tempat render.
     *  @param i Posisi baris zoo.
     *  @param j Posisi kolom zoo.
     *  @param offi Offset baris terhadap lokasi render.
     *  @param offj Offset kolom terhadap lokasi render.
     */
	void render(WINDOW* w, int i, int j, int offi, int offj);
    /** Menambahkan hewan ke dalam kandang.
     *  @param A Pointer menuju hewan yang akan ditambahkan.
     */
	void AddAnimal(Animal* A);
    /** Mengembalikan hewan ke-i yang ada di kandang.
     *  @param i Indeks untuk hewan yang ada di kandang.
     */
	Animal& GetAnimal(int i);
    /** Menggerakan hewan ke-i di dalam kandang.
     *  @param i Indeks hewan di kandang.
     *  @param movement Gerakan yang dilakukan.
     *  1. Atas
     *  2. Bawah
     *  3. Kiri
     *  4. Kanan
     */
	void MoveAnimal(int i, int movement);
};

/** AirCage.
 *  Kelas abstrak untuk kandang hewan udara.
 */
class AirCage : public Cage{
protected:
    /** List hewan yang ada di kandang.
     */
	AirAnimal **A;
public:
    /** Constructor.
     *  @param n Jumlah hewan dalam kandang.
     *  @param X List posisi baris hewan.
     *  @param Y List posisi kolom hewan.
     */
	AirCage(int n, int *X, int *Y);
    /** Destructor.
     */
	~AirCage();
    /** Menampilkan kandang pada layar.
     *  @param w Lokasi window tempat render.
     *  @param i Posisi baris zoo.
     *  @param j Posisi kolom zoo.
     *  @param offi Offset baris terhadap lokasi render.
     *  @param offj Offset kolom terhadap lokasi render.
     */
	void render(WINDOW* w, int i, int j, int offi, int offj);
    /** Menambahkan hewan ke dalam kandang.
     *  @param A Pointer menuju hewan yang akan ditambahkan.
     */
	void AddAnimal(Animal* A);
    /** Mengembalikan hewan ke-i yang ada di kandang.
     *  @param i Indeks untuk hewan yang ada di kandang.
     */
	Animal& GetAnimal(int i);
    /** Menggerakan hewan ke-i di dalam kandang.
     *  @param i Indeks hewan di kandang.
     *  @param movement Gerakan yang dilakukan.
     *  1. Atas
     *  2. Bawah
     *  3. Kiri
     *  4. Kanan
     */
	void MoveAnimal(int i, int movement);
};

#endif
