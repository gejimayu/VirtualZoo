#ifndef RENDER_H
#define RENDER_H

#include<ncurses.h>

/** Renderable.
 *  Kelas abstrak untuk objek yang bisa ditampilkan di layar.
 */
class Renderable {
public:
    /** Menampilkan objek pada layar.
     *  @param w Lokasi window tempat render.
     *  @param i Posisi baris zoo.
     *  @param j Posisi kolom zoo.
     *  @param offi Offset baris terhadap lokasi render.
     *  @param offj Offset kolom terhadap lokasi render.
     */
        virtual void render(WINDOW* w, int i, int j, int offi, int offj) = 0;
};

#endif // RENDR_H
