#ifndef CELL_H
#define CELL_H

#include"renderable.h"

#define LANDHABITAT 'l'
#define WATERHABITAT 'w'
#define AIRHABITAT 'a'
#define RESTAURANT 'r'
#define PARK 'p'
#define ROAD '_'
#define EXIT 'e'
#define ENTRANCE 'E'

/** Cell.
 *  Kelas abstrak untuk petak pada kebun binatang.
 */
class Cell : public Renderable {
public:
    /** Menampilkan petak pada layar.
     *  @param w Lokasi window tempat render.
     *  @param i Posisi baris zoo.
     *  @param j Posisi kolom zoo.
     *  @param offi Offset baris terhadap lokasi render.
     *  @param offj Offset kolom terhadap lokasi render.
     */
    virtual void render(WINDOW* w, int i, int j, int offi, int offj) = 0;
};

/** Habitat.
 *  Kelas abstrak untuk petak pada kebun binatang yang berisi habitat.
 */
class Habitat : public Cell {
public:
    /** Menampilkan petak pada layar.
     *  @param w Lokasi window tempat render.
     *  @param i Posisi baris zoo.
     *  @param j Posisi kolom zoo.
     *  @param offi Offset baris terhadap lokasi render.
     *  @param offj Offset kolom terhadap lokasi render.
     */
    virtual void render(WINDOW* w, int i, int j, int offi, int offj) = 0;
};

/** LandHabitat.
 *  Kelas untuk petak pada kebun binatang yang berisi habitat darat.
 */
class LandHabitat : public Habitat {
public:
    /** Menampilkan petak pada layar.
     *  @param w Lokasi window tempat render.
     *  @param i Posisi baris zoo.
     *  @param j Posisi kolom zoo.
     *  @param offi Offset baris terhadap lokasi render.
     *  @param offj Offset kolom terhadap lokasi render.
     */
    void render(WINDOW* w, int i, int j, int offi, int offj);
};

/** WaterHabitat.
 *  Kelas untuk petak pada kebun binatang yang berisi habitat air.
 */
class WaterHabitat : public Habitat {
public:
    /** Menampilkan petak pada layar.
     *  @param w Lokasi window tempat render.
     *  @param i Posisi baris zoo.
     *  @param j Posisi kolom zoo.
     *  @param offi Offset baris terhadap lokasi render.
     *  @param offj Offset kolom terhadap lokasi render.
     */
    void render(WINDOW* w, int i, int j, int offi, int offj);
};

/** AirHabitat.
 *  Kelas untuk petak pada kebun binatang yang berisi habitat udara.
 */
class AirHabitat : public Habitat {
public:
    /** Menampilkan petak pada layar.
     *  @param w Lokasi window tempat render.
     *  @param i Posisi baris zoo.
     *  @param j Posisi kolom zoo.
     *  @param offi Offset baris terhadap lokasi render.
     *  @param offj Offset kolom terhadap lokasi render.
     */
    void render(WINDOW* w, int i, int j, int offi, int offj);
};

/** Facility.
 *  Kelas abstrak untuk petak pada kebun binatang yang berisi fasilitas.
 */
class Facility : public Cell {
public:
    /** Menampilkan petak pada layar.
     *  @param w Lokasi window tempat render.
     *  @param i Posisi baris zoo.
     *  @param j Posisi kolom zoo.
     *  @param offi Offset baris terhadap lokasi render.
     *  @param offj Offset kolom terhadap lokasi render.
     */
    virtual void render(WINDOW* w, int i, int j, int offi, int offj) = 0;
};

/** Restaurant.
 *  Kelas untuk petak pada kebun binatang yang berisi fasilitas berupa restoran.
 */
class Restaurant : public Facility {
public:
    /** Menampilkan petak pada layar.
     *  @param w Lokasi window tempat render.
     *  @param i Posisi baris zoo.
     *  @param j Posisi kolom zoo.
     *  @param offi Offset baris terhadap lokasi render.
     *  @param offj Offset kolom terhadap lokasi render.
     */
    void render(WINDOW* w, int i, int j, int offi, int offj);
};

/** Park.
 *  Kelas untuk petak pada kebun binatang yang berisi fasilitas berupa taman.
 */
class Park : public Facility {
public:
    /** Menampilkan petak pada layar.
     *  @param w Lokasi window tempat render.
     *  @param i Posisi baris zoo.
     *  @param j Posisi kolom zoo.
     *  @param offi Offset baris terhadap lokasi render.
     *  @param offj Offset kolom terhadap lokasi render.
     */
    void render(WINDOW* w, int i, int j, int offi, int offj);
};

/** Road.
 *  Kelas untuk petak pada kebun binatang yang berisi fasilitas berupa jalan.
 */
class Road : public Facility {
public:
    /** Menampilkan petak pada layar.
     *  @param w Lokasi window tempat render.
     *  @param i Posisi baris zoo.
     *  @param j Posisi kolom zoo.
     *  @param offi Offset baris terhadap lokasi render.
     *  @param offj Offset kolom terhadap lokasi render.
     */
    void render(WINDOW* w, int i, int j, int offi, int offj);
};

/** Entrance.
 *  Kelas untuk petak pada kebun binatang yang berisi fasilitas berupa pintu masuk.
 */
class Entrance : public Road {};

/** Exit.
 *  Kelas untuk petak pada kebun binatang yang berisi fasilitas berupa pintu keluar.
 */
class Exit : public Road {};

#endif // CELL_H
