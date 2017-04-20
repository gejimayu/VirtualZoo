#ifndef ANIMAL_H
#define ANIMAL_H

#include"renderable.h"
#include <string>
#include <vector>
#include<ncurses.h>

using namespace std;
/** Animal.
  * Kelas abstrak untuk hewan.
  */
class Animal : public Renderable {
	public :
	    /** Destructor
	     */
        virtual ~Animal();
	    /** Menambahkan jumlah makanan yang dimakan hewan ke variabel yang sesuai.
         * @param daging Jumlah daging yang dimakan.
         * @param sayur Jumlah sayur yang dimakan.
         */
		void AddFood(int& daging, int& sayur);
	    /** Mengembalikan posisi baris hewan.
         */
		int GetX();
	    /** Mengembalikan posisi kolom hewan.
         */
		int GetY();
	    /** Mengubah posisi baris hewan.
	     * Nilai yang dimasukkan harus valid.
         * @param i Posisi baris yang baru.
         */
		void SetX(int i);
	    /** Mengubah posisi kolom hewan.
	     * Nilai yang dimasukkan harus valid.
         * @param j Posisi kolom yang baru.
         */
		void SetY(int j);
	    /** Menampilkan hewan pada layar.
         *  @param w Lokasi window tempat render.
         *  @param i Posisi baris zoo.
         *  @param j Posisi kolom zoo.
         *  @param offi Offset baris terhadap lokasi render.
         *  @param offj Offset kolom terhadap lokasi render.
         */
		virtual void render(WINDOW* w, int i, int j, int offi, int offj)=0;
	    /** Menampilkan pengalaman yang dialami saat berinteraksi dengan hewan.
         *  @param w Lokasi window tempat menmpilkan pengalaman.
         *  @param i Posisi baris.
         *  @param j Posisi kolom.
         */
		virtual void Interact(WINDOW* w, int i, int j)=0;
		/** Mengembalikan nama hewan
         */
        char* getNama();
		/**	Mengembalikan true jika hewan buas
		 */
		bool GetBuas();

	protected :
	    /** Berat hewan.
         */
		float berat;
	    /** Jenis makanan hewan.
         */
		vector<string> makanan;
	    /** Keterangan buas tidaknya hewan.
         */
		bool buas;
	    /** Jenis habitat hewan.
         */
		vector<string> habitat;
	    /** Nama kelas hewan.
         */
        char* nama;
	    /** Posisi baris hewan.
         */
		int x;
	    /** Posisi kolom hewan.
         */
		int y;
	    /** Klasifikasi kingdom hewan.
         */
		string kingdom;
	    /** Klasifikasi filum hewan.
         */
		string phylum;
	    /** Klasifikasi kelas hewan.
         */
		string kelas;
	    /** Klasifikasi ordo hewan.
         */
		string order;
	    /** Klasifikasi famili hewan.
         */
		string family;
	    /** Klasifikasi genus hewan.
         */
		string genus;
	    /** Klasifikasi spesies hewan.
         */
		string species;
};


/** LandAnimal.
  * Kelas abstrak untuk hewan darat.
  */
class LandAnimal : public virtual Animal {
	public :
	    /** Constructor.
         */
		LandAnimal();
	    /** Menampilkan hewan pada layar.
         *  @param w Lokasi window tempat render.
         *  @param i Posisi baris zoo.
         *  @param j Posisi kolom zoo.
         *  @param offi Offset baris terhadap lokasi render.
         *  @param offj Offset kolom terhadap lokasi render.
         */
		virtual void render(WINDOW* w, int i, int j, int offi, int offj)=0;
	    /** Menampilkan pengalaman yang dialami saat berinteraksi dengan hewan.
         *  @param w Lokasi window tempat menmpilkan pengalaman.
         *  @param i Posisi baris.
         *  @param j Posisi kolom.
         */
		virtual void Interact(WINDOW* w, int i, int j)=0;

};

/** WaterAnimal.
  * Kelas abstrak untuk hewan air.
  */
class WaterAnimal : public virtual Animal {
	public :
	    /** Constructor.
         */
		WaterAnimal();
	    /** Menampilkan hewan pada layar.
         *  @param w Lokasi window tempat render.
         *  @param i Posisi baris zoo.
         *  @param j Posisi kolom zoo.
         *  @param offi Offset baris terhadap lokasi render.
         *  @param offj Offset kolom terhadap lokasi render.
         */
		virtual void render(WINDOW* w, int i, int j, int offi, int offj)=0;
	    /** Menampilkan pengalaman yang dialami saat berinteraksi dengan hewan.
         *  @param w Lokasi window tempat menmpilkan pengalaman.
         *  @param i Posisi baris.
         *  @param j Posisi kolom.
         */
		virtual void Interact(WINDOW* w, int i, int j)=0;

};

/** AirAnimal.
  * Kelas abstrak untuk hewan udara.
  */
class AirAnimal : public virtual Animal {
	public :
	    /** @brief Constructor.
         */
		AirAnimal();
	    /** Menampilkan hewan pada layar.
         *  @param w Lokasi window tempat render.
         *  @param i Posisi baris zoo.
         *  @param j Posisi kolom zoo.
         *  @param offi Offset baris terhadap lokasi render.
         *  @param offj Offset kolom terhadap lokasi render.
         */
		virtual void render(WINDOW* w, int i, int j, int offi, int offj)=0;
	    /** Menampilkan pengalaman yang dialami saat berinteraksi dengan hewan.
         *  @param w Lokasi window tempat menmpilkan pengalaman.
         *  @param i Posisi baris.
         *  @param j Posisi kolom.
         */
		virtual void Interact(WINDOW* w, int i, int j)=0;

};

/** Karnivor.
  * Kelas abstrak untuk hewan pemakan daging.
  */
class Karnivor : public virtual Animal {
	public :
	    /** Constructor.
         */
		Karnivor();
	    /** Menampilkan hewan pada layar.
         *  @param w Lokasi window tempat render.
         *  @param i Posisi baris zoo.
         *  @param j Posisi kolom zoo.
         *  @param offi Offset baris terhadap lokasi render.
         *  @param offj Offset kolom terhadap lokasi render.
         */
		virtual void render(WINDOW* w, int i, int j, int offi, int offj)=0;
	    /** Menampilkan pengalaman yang dialami saat berinteraksi dengan hewan.
         *  @param w Lokasi window tempat menmpilkan pengalaman.
         *  @param i Posisi baris.
         *  @param j Posisi kolom.
         */
		virtual void Interact(WINDOW* w, int i, int j)=0;

};

/** Herbivor.
  * Kelas abstrak untuk hewan pemakan sayur.
  */
class Herbivor : public virtual Animal {
	public :
	    /** Constructor.
         */
		Herbivor();
	    /** Menampilkan hewan pada layar.
         *  @param w Lokasi window tempat render.
         *  @param i Posisi baris zoo.
         *  @param j Posisi kolom zoo.
         *  @param offi Offset baris terhadap lokasi render.
         *  @param offj Offset kolom terhadap lokasi render.
         */
		virtual void render(WINDOW* w, int i, int j, int offi, int offj)=0;
	    /** Menampilkan pengalaman yang dialami saat berinteraksi dengan hewan.
         *  @param w Lokasi window tempat menmpilkan pengalaman.
         *  @param i Posisi baris.
         *  @param j Posisi kolom.
         */
		virtual void Interact(WINDOW* w, int i, int j)=0;

};

/** Omnivor.
  * Kelas abstrak untuk hewan pemakan segala.
  */
class Omnivor : public virtual Animal {
	public :
	    /** Constructor.
         */
		Omnivor();
	    /** Menampilkan hewan pada layar.
         *  @param w Lokasi window tempat render.
         *  @param i Posisi baris zoo.
         *  @param j Posisi kolom zoo.
         *  @param offi Offset baris terhadap lokasi render.
         *  @param offj Offset kolom terhadap lokasi render.
         */
		virtual void render(WINDOW* w, int i, int j, int offi, int offj)=0;
	    /** Menampilkan pengalaman yang dialami saat berinteraksi dengan hewan.
         *  @param w Lokasi window tempat menmpilkan pengalaman.
         *  @param i Posisi baris.
         *  @param j Posisi kolom.
         */
		virtual void Interact(WINDOW* w, int i, int j)=0;

};

/** Tiger.
  * Kelas untuk macan.
  */
class Tiger : public LandAnimal, public Karnivor {
	public :
	    /** Constructor.
	     *  @param _berat Berat hewan.
	     *  @param _buas Buas tidaknya hewan.
	     *  @param _x Posisi baris hewan.
	     *  @param _y Posisi kolom hewan.
         */
		Tiger(float _berat, bool _buas, int _x, int _y);
	    /** Menampilkan hewan pada layar.
         *  @param w Lokasi window tempat render.
         *  @param i Posisi baris zoo.
         *  @param j Posisi kolom zoo.
         *  @param offi Offset baris terhadap lokasi render.
         *  @param offj Offset kolom terhadap lokasi render.
         */
		void render(WINDOW* w, int i, int j, int offi, int offj);
	    /** Menampilkan pengalaman yang dialami saat berinteraksi dengan hewan.
         *  @param w Lokasi window tempat menmpilkan pengalaman.
         *  @param i Posisi baris.
         *  @param j Posisi kolom.
         */
		void Interact(WINDOW* w, int i, int j);

};

/** Sea_Lion.
  * Kelas untuk anjing laut.
  */
class Sea_Lion : public LandAnimal, public WaterAnimal, public Karnivor{
	public :
	    /** Constructor.
	     *  @param _berat Berat hewan.
	     *  @param _buas Buas tidaknya hewan.
	     *  @param _x Posisi baris hewan.
	     *  @param _y Posisi kolom hewan.
         */
		Sea_Lion(float _berat, bool _buas, int _x, int _y);
	    /** Menampilkan hewan pada layar.
         *  @param w Lokasi window tempat render.
         *  @param i Posisi baris zoo.
         *  @param j Posisi kolom zoo.
         *  @param offi Offset baris terhadap lokasi render.
         *  @param offj Offset kolom terhadap lokasi render.
         */
		void render(WINDOW* w, int i, int j, int offi, int offj);
	    /** Menampilkan pengalaman yang dialami saat berinteraksi dengan hewan.
         *  @param w Lokasi window tempat menmpilkan pengalaman.
         *  @param i Posisi baris.
         *  @param j Posisi kolom.
         */
		void Interact(WINDOW* w, int i, int j);

};

/** Zebra.
  * Kelas untuk zebra.
  */
class Zebra : public LandAnimal, public Herbivor{
	public :
	    /** Constructor.
	     *  @param _berat Berat hewan.
	     *  @param _buas Buas tidaknya hewan.
	     *  @param _x Posisi baris hewan.
	     *  @param _y Posisi kolom hewan.
         */
		Zebra(float _berat, bool _buas, int _x, int _y);
	    /** Menampilkan hewan pada layar.
         *  @param w Lokasi window tempat render.
         *  @param i Posisi baris zoo.
         *  @param j Posisi kolom zoo.
         *  @param offi Offset baris terhadap lokasi render.
         *  @param offj Offset kolom terhadap lokasi render.
         */
		void render(WINDOW* w, int i, int j, int offi, int offj);
	    /** Menampilkan pengalaman yang dialami saat berinteraksi dengan hewan.
         *  @param w Lokasi window tempat menmpilkan pengalaman.
         *  @param i Posisi baris.
         *  @param j Posisi kolom.
         */
		void Interact(WINDOW* w, int i, int j);

};

/** Lion.
  * Kelas untuk singa.
  */
class Lion : public LandAnimal, public Karnivor{
	public :
	    /** Constructor.
	     *  @param _berat Berat hewan.
	     *  @param _buas Buas tidaknya hewan.
	     *  @param _x Posisi baris hewan.
	     *  @param _y Posisi kolom hewan.
         */
		Lion(float _berat, bool _buas, int _x, int _y);
	    /** Menampilkan hewan pada layar.
         *  @param w Lokasi window tempat render.
         *  @param i Posisi baris zoo.
         *  @param j Posisi kolom zoo.
         *  @param offi Offset baris terhadap lokasi render.
         *  @param offj Offset kolom terhadap lokasi render.
         */
		void render(WINDOW* w, int i, int j, int offi, int offj);
	    /** Menampilkan pengalaman yang dialami saat berinteraksi dengan hewan.
         *  @param w Lokasi window tempat menmpilkan pengalaman.
         *  @param i Posisi baris.
         *  @param j Posisi kolom.
         */
		void Interact(WINDOW* w, int i, int j);

};

/** Hipopotamus.
  * Kelas untuk kuda nil.
  */
class Hipopotamus : public LandAnimal, public WaterAnimal, public Herbivor{
	public :
	    /** Constructor.
	     *  @param _berat Berat hewan.
	     *  @param _buas Buas tidaknya hewan.
	     *  @param _x Posisi baris hewan.
	     *  @param _y Posisi kolom hewan.
         */
		Hipopotamus(float _berat, bool _buas, int _x, int _y);
	    /** Menampilkan hewan pada layar.
         *  @param w Lokasi window tempat render.
         *  @param i Posisi baris zoo.
         *  @param j Posisi kolom zoo.
         *  @param offi Offset baris terhadap lokasi render.
         *  @param offj Offset kolom terhadap lokasi render.
         */
		void render(WINDOW* w, int i, int j, int offi, int offj);
	    /** Menampilkan pengalaman yang dialami saat berinteraksi dengan hewan.
         *  @param w Lokasi window tempat menmpilkan pengalaman.
         *  @param i Posisi baris.
         *  @param j Posisi kolom.
         */
		void Interact(WINDOW* w, int i, int j);

};

/** Penguin.
  * Kelas untuk pinguin.
  */
class Penguin : public LandAnimal, public Karnivor{
	public :
	    /** Constructor.
	     *  @param _berat Berat hewan.
	     *  @param _buas Buas tidaknya hewan.
	     *  @param _x Posisi baris hewan.
	     *  @param _y Posisi kolom hewan.
         */
		Penguin(float _berat, bool _buas, int _x, int _y);
	    /** Menampilkan hewan pada layar.
         *  @param w Lokasi window tempat render.
         *  @param i Posisi baris zoo.
         *  @param j Posisi kolom zoo.
         *  @param offi Offset baris terhadap lokasi render.
         *  @param offj Offset kolom terhadap lokasi render.
         */
		void render(WINDOW* w, int i, int j, int offi, int offj);
	    /** Menampilkan pengalaman yang dialami saat berinteraksi dengan hewan.
         *  @param w Lokasi window tempat menmpilkan pengalaman.
         *  @param i Posisi baris.
         *  @param j Posisi kolom.
         */
		void Interact(WINDOW* w, int i, int j);

};

/** Monkey.
  * Kelas untuk monyet.
  */
class Monkey : public LandAnimal, public Herbivor{
	public :
	    /** Constructor.
	     *  @param _berat Berat hewan.
	     *  @param _buas Buas tidaknya hewan.
	     *  @param _x Posisi baris hewan.
	     *  @param _y Posisi kolom hewan.
         */
		Monkey(float _berat, bool _buas, int _x, int _y);
	    /** Menampilkan hewan pada layar.
         *  @param w Lokasi window tempat render.
         *  @param i Posisi baris zoo.
         *  @param j Posisi kolom zoo.
         *  @param offi Offset baris terhadap lokasi render.
         *  @param offj Offset kolom terhadap lokasi render.
         */
		void render(WINDOW* w, int i, int j, int offi, int offj);
	    /** Menampilkan pengalaman yang dialami saat berinteraksi dengan hewan.
         *  @param w Lokasi window tempat menmpilkan pengalaman.
         *  @param i Posisi baris.
         *  @param j Posisi kolom.
         */
		void Interact(WINDOW* w, int i, int j);

};

/** OrangUtan.
  * Kelas untuk orang utan.
  */
class OrangUtan : public LandAnimal, public Herbivor{
	public :
	    /** Constructor.
	     *  @param _berat Berat hewan.
	     *  @param _buas Buas tidaknya hewan.
	     *  @param _x Posisi baris hewan.
	     *  @param _y Posisi kolom hewan.
         */
		OrangUtan(float _berat, bool _buas, int _x, int _y);
	    /** Menampilkan hewan pada layar.
         *  @param w Lokasi window tempat render.
         *  @param i Posisi baris zoo.
         *  @param j Posisi kolom zoo.
         *  @param offi Offset baris terhadap lokasi render.
         *  @param offj Offset kolom terhadap lokasi render.
         */
		void render(WINDOW* w, int i, int j, int offi, int offj);
	    /** Menampilkan pengalaman yang dialami saat berinteraksi dengan hewan.
         *  @param w Lokasi window tempat menmpilkan pengalaman.
         *  @param i Posisi baris.
         *  @param j Posisi kolom.
         */
		void Interact(WINDOW* w, int i, int j);

};

/** Bear.
  * Kelas untuk beruang.
  */
class Bear : public LandAnimal, public Karnivor{
	public :
	    /** Constructor.
	     *  @param _berat Berat hewan.
	     *  @param _buas Buas tidaknya hewan.
	     *  @param _x Posisi baris hewan.
	     *  @param _y Posisi kolom hewan.
         */
		Bear(float _berat, bool _buas, int _x, int _y);
	    /** Menampilkan hewan pada layar.
         *  @param w Lokasi window tempat render.
         *  @param i Posisi baris zoo.
         *  @param j Posisi kolom zoo.
         *  @param offi Offset baris terhadap lokasi render.
         *  @param offj Offset kolom terhadap lokasi render.
         */
		void render(WINDOW* w, int i, int j, int offi, int offj);
	    /** Menampilkan pengalaman yang dialami saat berinteraksi dengan hewan.
         *  @param w Lokasi window tempat menmpilkan pengalaman.
         *  @param i Posisi baris.
         *  @param j Posisi kolom.
         */
		void Interact(WINDOW* w, int i, int j);

};

/** Giraffe.
  * Kelas untuk jerapah.
  */
class Giraffe : public LandAnimal, public Herbivor{
	public :
	    /** Constructor.
	     *  @param _berat Berat hewan.
	     *  @param _buas Buas tidaknya hewan.
	     *  @param _x Posisi baris hewan.
	     *  @param _y Posisi kolom hewan.
         */
		Giraffe(float _berat, bool _buas, int _x, int _y);
	    /** Menampilkan hewan pada layar.
         *  @param w Lokasi window tempat render.
         *  @param i Posisi baris zoo.
         *  @param j Posisi kolom zoo.
         *  @param offi Offset baris terhadap lokasi render.
         *  @param offj Offset kolom terhadap lokasi render.
         */
		void render(WINDOW* w, int i, int j, int offi, int offj);
	    /** Menampilkan pengalaman yang dialami saat berinteraksi dengan hewan.
         *  @param w Lokasi window tempat menmpilkan pengalaman.
         *  @param i Posisi baris.
         *  @param j Posisi kolom.
         */
		void Interact(WINDOW* w, int i, int j);
};

/** Peacock.
  * Kelas untuk burung merak.
  */
class Peacock : public AirAnimal, public Herbivor{
	public :
	    /** Constructor.
	     *  @param _berat Berat hewan.
	     *  @param _buas Buas tidaknya hewan.
	     *  @param _x Posisi baris hewan.
	     *  @param _y Posisi kolom hewan.
         */
		Peacock(float _berat, bool _buas, int _x, int _y);
	    /** Menampilkan hewan pada layar.
         *  @param w Lokasi window tempat render.
         *  @param i Posisi baris zoo.
         *  @param j Posisi kolom zoo.
         *  @param offi Offset baris terhadap lokasi render.
         *  @param offj Offset kolom terhadap lokasi render.
         */
		void render(WINDOW* w, int i, int j, int offi, int offj);
	    /** Menampilkan pengalaman yang dialami saat berinteraksi dengan hewan.
         *  @param w Lokasi window tempat menmpilkan pengalaman.
         *  @param i Posisi baris.
         *  @param j Posisi kolom.
         */
		void Interact(WINDOW* w, int i, int j);
};

/** Eagle.
  * Kelas untuk burung elang.
  */
class Eagle : public AirAnimal, public Karnivor{
	public :
	    /** Constructor.
	     *  @param _berat Berat hewan.
	     *  @param _buas Buas tidaknya hewan.
	     *  @param _x Posisi baris hewan.
	     *  @param _y Posisi kolom hewan.
         */
		Eagle(float _berat, bool _buas, int _x, int _y);
	    /** Menampilkan hewan pada layar.
         *  @param w Lokasi window tempat render.
         *  @param i Posisi baris zoo.
         *  @param j Posisi kolom zoo.
         *  @param offi Offset baris terhadap lokasi render.
         *  @param offj Offset kolom terhadap lokasi render.
         */
		void render(WINDOW* w, int i, int j, int offi, int offj);
	    /** Menampilkan pengalaman yang dialami saat berinteraksi dengan hewan.
         *  @param w Lokasi window tempat menmpilkan pengalaman.
         *  @param i Posisi baris.
         *  @param j Posisi kolom.
         */
		void Interact(WINDOW* w, int i, int j);
};

/** Dolphin.
  * Kelas untuk lumba-lumba.
  */
class Dolphin : public WaterAnimal, public Karnivor{
	public :
	    /** Constructor.
	     *  @param _berat Berat hewan.
	     *  @param _buas Buas tidaknya hewan.
	     *  @param _x Posisi baris hewan.
	     *  @param _y Posisi kolom hewan.
         */
		Dolphin(float _berat, bool _buas, int _x, int _y);
	    /** Menampilkan hewan pada layar.
         *  @param w Lokasi window tempat render.
         *  @param i Posisi baris zoo.
         *  @param j Posisi kolom zoo.
         *  @param offi Offset baris terhadap lokasi render.
         *  @param offj Offset kolom terhadap lokasi render.
         */
		void render(WINDOW* w, int i, int j, int offi, int offj);
	    /** Menampilkan pengalaman yang dialami saat berinteraksi dengan hewan.
         *  @param w Lokasi window tempat menmpilkan pengalaman.
         *  @param i Posisi baris.
         *  @param j Posisi kolom.
         */
		void Interact(WINDOW* w, int i, int j);
};

/** Shark.
  * Kelas untuk ikan hiu.
  */
class Shark : public WaterAnimal, public Karnivor{
	public :
	    /** Constructor.
	     *  @param _berat Berat hewan.
	     *  @param _buas Buas tidaknya hewan.
	     *  @param _x Posisi baris hewan.
	     *  @param _y Posisi kolom hewan.
         */
		Shark(float _berat, bool _buas, int _x, int _y);
	    /** Menampilkan hewan pada layar.
         *  @param w Lokasi window tempat render.
         *  @param i Posisi baris zoo.
         *  @param j Posisi kolom zoo.
         *  @param offi Offset baris terhadap lokasi render.
         *  @param offj Offset kolom terhadap lokasi render.
         */
		void render(WINDOW* w, int i, int j, int offi, int offj);
	    /** Menampilkan pengalaman yang dialami saat berinteraksi dengan hewan.
         *  @param w Lokasi window tempat menmpilkan pengalaman.
         *  @param i Posisi baris.
         *  @param j Posisi kolom.
         */
		void Interact(WINDOW* w, int i, int j);
};

/** Horse.
  * Kelas untuk kuda.
  */
class Horse : public LandAnimal, public Herbivor{
	public :
	    /** Constructor.
	     *  @param _berat Berat hewan.
	     *  @param _buas Buas tidaknya hewan.
	     *  @param _x Posisi baris hewan.
	     *  @param _y Posisi kolom hewan.
         */
		Horse(float _berat, bool _buas, int _x, int _y);
	    /** Menampilkan hewan pada layar.
         *  @param w Lokasi window tempat render.
         *  @param i Posisi baris zoo.
         *  @param j Posisi kolom zoo.
         *  @param offi Offset baris terhadap lokasi render.
         *  @param offj Offset kolom terhadap lokasi render.
         */
		void render(WINDOW* w, int i, int j, int offi, int offj);
	    /** Menampilkan pengalaman yang dialami saat berinteraksi dengan hewan.
         *  @param w Lokasi window tempat menmpilkan pengalaman.
         *  @param i Posisi baris.
         *  @param j Posisi kolom.
         */
		void Interact(WINDOW* w, int i, int j);
};

/** Snake.
  * Kelas untuk ular.
  */
class Snake : public LandAnimal, public Karnivor{
	public :
	    /** Constructor.
	     *  @param _berat Berat hewan.
	     *  @param _buas Buas tidaknya hewan.
	     *  @param _x Posisi baris hewan.
	     *  @param _y Posisi kolom hewan.
         */
		Snake(float _berat, bool _buas, int _x, int _y);
	    /** Menampilkan hewan pada layar.
         *  @param w Lokasi window tempat render.
         *  @param i Posisi baris zoo.
         *  @param j Posisi kolom zoo.
         *  @param offi Offset baris terhadap lokasi render.
         *  @param offj Offset kolom terhadap lokasi render.
         */
		void render(WINDOW* w, int i, int j, int offi, int offj);
	    /** Menampilkan pengalaman yang dialami saat berinteraksi dengan hewan.
         *  @param w Lokasi window tempat menmpilkan pengalaman.
         *  @param i Posisi baris.
         *  @param j Posisi kolom.
         */
		void Interact(WINDOW* w, int i, int j);
};

/** Panda.
  * Kelas untuk panda.
  */
class Panda : public LandAnimal, public Herbivor{
	public :
	    /** Constructor.
	     *  @param _berat Berat hewan.
	     *  @param _buas Buas tidaknya hewan.
	     *  @param _x Posisi baris hewan.
	     *  @param _y Posisi kolom hewan.
         */
		Panda(float _berat, bool _buas, int _x, int _y);
	    /** Menampilkan hewan pada layar.
         *  @param w Lokasi window tempat render.
         *  @param i Posisi baris zoo.
         *  @param j Posisi kolom zoo.
         *  @param offi Offset baris terhadap lokasi render.
         *  @param offj Offset kolom terhadap lokasi render.
         */
		void render(WINDOW* w, int i, int j, int offi, int offj);
	    /** Menampilkan pengalaman yang dialami saat berinteraksi dengan hewan.
         *  @param w Lokasi window tempat menmpilkan pengalaman.
         *  @param i Posisi baris.
         *  @param j Posisi kolom.
         */
		void Interact(WINDOW* w, int i, int j);
};

/** Turtle.
  * Kelas untuk kura-kura.
  */
class Turtle : public LandAnimal, public Omnivor{
	public :
	    /** Constructor.
	     *  @param _berat Berat hewan.
	     *  @param _buas Buas tidaknya hewan.
	     *  @param _x Posisi baris hewan.
	     *  @param _y Posisi kolom hewan.
         */
		Turtle(float _berat, bool _buas, int _x, int _y);
	    /** Menampilkan hewan pada layar.
         *  @param w Lokasi window tempat render.
         *  @param i Posisi baris zoo.
         *  @param j Posisi kolom zoo.
         *  @param offi Offset baris terhadap lokasi render.
         *  @param offj Offset kolom terhadap lokasi render.
         */
		void render(WINDOW* w, int i, int j, int offi, int offj);
	    /** Menampilkan pengalaman yang dialami saat berinteraksi dengan hewan.
         *  @param w Lokasi window tempat menmpilkan pengalaman.
         *  @param i Posisi baris.
         *  @param j Posisi kolom.
         */
		void Interact(WINDOW* w, int i, int j);
};

/** Alligator.
  * Kelas untuk buaya.
  */
class Alligator : public LandAnimal, public WaterAnimal, public Karnivor{
	public :
	    /** Constructor.
	     *  @param _berat Berat hewan.
	     *  @param _buas Buas tidaknya hewan.
	     *  @param _x Posisi baris hewan.
	     *  @param _y Posisi kolom hewan.
         */
		Alligator(float _berat, bool _buas, int _x, int _y);
	    /** Menampilkan hewan pada layar.
         *  @param w Lokasi window tempat render.
         *  @param i Posisi baris zoo.
         *  @param j Posisi kolom zoo.
         *  @param offi Offset baris terhadap lokasi render.
         *  @param offj Offset kolom terhadap lokasi render.
         */
		void render(WINDOW* w, int i, int j, int offi, int offj);
	    /** Menampilkan pengalaman yang dialami saat berinteraksi dengan hewan.
         *  @param w Lokasi window tempat menmpilkan pengalaman.
         *  @param i Posisi baris.
         *  @param j Posisi kolom.
         */
		void Interact(WINDOW* w, int i, int j);
};

/** Kangoroo.
  * Kelas untuk kangguru.
  */
class Kangoroo : public LandAnimal, public Herbivor{
	public :
	    /** Constructor.
	     *  @param _berat Berat hewan.
	     *  @param _buas Buas tidaknya hewan.
	     *  @param _x Posisi baris hewan.
	     *  @param _y Posisi kolom hewan.
         */
		Kangoroo(float _berat, bool _buas, int _x, int _y);
	    /** Menampilkan hewan pada layar.
         *  @param w Lokasi window tempat render.
         *  @param i Posisi baris zoo.
         *  @param j Posisi kolom zoo.
         *  @param offi Offset baris terhadap lokasi render.
         *  @param offj Offset kolom terhadap lokasi render.
         */
		void render(WINDOW* w, int i, int j, int offi, int offj);
	    /** Menampilkan pengalaman yang dialami saat berinteraksi dengan hewan.
         *  @param w Lokasi window tempat menmpilkan pengalaman.
         *  @param i Posisi baris.
         *  @param j Posisi kolom.
         */
		void Interact(WINDOW* w, int i, int j);
};

#endif // ANIMAL_H

