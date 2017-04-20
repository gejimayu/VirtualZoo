#include "include/animal.h"
#include <vector>
#include <string>
#include <iostream>

using namespace std;

Animal::~Animal() {}

void Animal::AddFood(int& daging, int& sayur){
	if(makanan.size()==1){
		if(makanan[0]=="daging"){
			daging = daging + 0.3 * berat;
		}
		else{
			sayur = sayur + 0.3 * berat;
		}
	}
	else
		if(makanan.size()==2){
			daging = daging + 0.2 * berat;
			sayur = sayur + 0.1 * berat;
		}
}

char* Animal::getNama() {
    return nama;
}

int Animal::GetX(){
	return x;
}

int Animal::GetY(){
	return y;
}

void Animal::SetX(int i){
	x = i;
}

void Animal::SetY(int j){
	y = j;
}

bool Animal::GetBuas(){
	return buas;
}

LandAnimal::LandAnimal(){
	habitat.push_back("Land");
}

WaterAnimal::WaterAnimal(){
	habitat.push_back("Water");
}

AirAnimal::AirAnimal(){
	habitat.push_back("Air");
}

Karnivor::Karnivor(){
	makanan.push_back("daging");
}

Herbivor::Herbivor(){
	makanan.push_back("sayur");
}

Omnivor::Omnivor(){
	makanan.push_back("daging");
	makanan.push_back("sayur");
}

Tiger::Tiger(float _berat, bool _buas, int _x, int _y){
    nama = "Tiger";
	berat = _berat;
	buas = _buas;
	x = _x;
	y = _y;
	kingdom = "Animalia";
	phylum = "Chordata";
	kelas = "Mammalia";
	order = "Karnivora";
	family = "Felidae";
	genus = "Panthera";
	species = "Panthera tigris";
}

void Tiger::render(WINDOW* w, int i, int j, int offi, int offj){
	mvwprintw(w, i+offi, j+offj, "T");
}

void Tiger::Interact(WINDOW* w, int i, int j){
    mvwprintw(w, i, j, "Haum...");
    mvwprintw(w, i+1, j, "The tiger just roared because you came to close.");
    mvwprintw(w, i+2, j, "Don't be afraid. It is in the cage");
}

Sea_Lion::Sea_Lion(float _berat, bool _buas, int _x, int _y){
    nama = "Sea Lion";
	berat = _berat;
	buas = _buas;
	x = _x;
	y = _y;
	kingdom = "Animalia";
	phylum = "Chordata";
	kelas = "Mammalia";
	order = "Karnivora";
	family = "Otariidae";
	genus = "Arctocephalus";
	species = "Artocephalus tropicalis";
}

void Sea_Lion::render(WINDOW* w, int i, int j, int offi, int offj){
	mvwprintw(w, i+offi, j+offj, "S");
}

void Sea_Lion::Interact(WINDOW* w, int i, int j){
    mvwprintw(w, i, j, "Auauau...");
    mvwprintw(w, i+1, j, "The sea lion claps its hands (or fins ?) to welcome you");
}

Zebra::Zebra(float _berat, bool _buas, int _x, int _y){
    nama = "Zebra";
	berat = _berat;
	buas = _buas;
	x = _x;
	y = _y;
	kingdom = "Animalia";
	phylum = "Chordata";
	kelas = "Mammalia";
	order = "Perissodactyla";
	family = "Equidae";
	genus = "Equus";
	species = "Equus Zebra";
}

void Zebra::render(WINDOW* w, int i, int j, int offi, int offj){
	mvwprintw(w, i+offi, j+offj, "Z");
}

void Zebra::Interact(WINDOW* w, int i, int j){
    mvwprintw(w, i, j, "Kraus..kraus..");
    mvwprintw(w, i+1, j, "The zebra is eating grass. It looks delecious");
}

Lion::Lion(float _berat, bool _buas, int _x, int _y){
    nama = "Lion";
	berat = _berat;
	buas = _buas;
	x = _x;
	y = _y;
	kingdom = "Animalia";
	phylum = "Chordata";
	kelas = "Mammalia";
	order = "Carnivora";
	family = "Felidae";
	genus = "Panthera";
	species = "Panthera leo";
}

void Lion::render(WINDOW* w, int i, int j, int offi, int offj){
	mvwprintw(w, i+offi, j+offj, "L");
}

void Lion::Interact(WINDOW* w, int i, int j){
    mvwprintw(w, i, j, "...");
    mvwprintw(w, i+1, j, "The lion is staring at you. Maybe it wants to know how you tase");
}

Hipopotamus::Hipopotamus(float _berat, bool _buas, int _x, int _y){
    nama = "Hipopotamus";
	berat = _berat;
	buas = _buas;
	x = _x;
	y = _y;
	kingdom = "Animalia";
	phylum = "Chordata";
	kelas = "Mammalia";
	order = "Artiodactyla";
	family = "Hipopotamidae";
	genus = "Hipopotamus";
	species = "Hipopotamus amphibius";
}

void Hipopotamus::render(WINDOW* w, int i, int j, int offi, int offj){
	mvwprintw(w, i+offi, j+offj, "H");
}

void Hipopotamus::Interact(WINDOW* w, int i, int j){
    mvwprintw(w, i, j, "Hoaahm...");
    mvwprintw(w, i+1, j, "The hipopotamus opens wide its mouth.");
    mvwprintw(w, i+2, j, "Maybe it yawns because it feels sleepy");
}

Penguin::Penguin(float _berat, bool _buas, int _x, int _y){
    nama = "Penguin";
	berat = _berat;
	buas = _buas;
	x = _x;
	y = _y;
	kingdom = "Animalia";
	phylum = "Chordata";
	kelas = "Aves";
	order = "Sphenisciformes";
	family = "Spheniscidae";
	genus = "Pygoscelis";
	species = "Pygoscelis antartica";
}

void Penguin::render(WINDOW* w, int i, int j, int offi, int offj){
	mvwprintw(w, i+offi, j+offj, "N");
}

void Penguin::Interact(WINDOW* w, int i, int j){
    mvwprintw(w, i, j, "Tap..tap...");
    mvwprintw(w, i+1, j, "The penguin walks slowly toward you.");
    mvwprintw(w, i+2, j, "Maybe it wants fish in your lunch box");
}

Monkey::Monkey(float _berat, bool _buas, int _x, int _y){
    nama = "Monkey";
	berat = _berat;
	buas = _buas;
	x = _x;
	y = _y;
	kingdom = "Animalia";
	phylum = "Chordata";
	kelas = "Primates";
	order = "Primates";
	family = "Cebidae";
	genus = "Callithrix";
	species = "Callithrix pygmaea";
}

void Monkey::render(WINDOW* w, int i, int j, int offi, int offj){
	mvwprintw(w, i+offi, j+offj, "M");
}

void Monkey::Interact(WINDOW* w, int i, int j){
    mvwprintw(w, i, j, "Uuaa..uuaa..");
    mvwprintw(w, i+1, j, "The monkey jumps happily from the tree because you");
    mvwprintw(w, i+2, j, "want to give it banana");
}

OrangUtan::OrangUtan(float _berat, bool _buas, int _x, int _y){
    nama = "Orang Utan";
	berat = _berat;
	buas = _buas;
	x = _x;
	y = _y;
	kingdom = "Animalia";
	phylum = "Chordata";
	kelas = "Mammalia";
	order = "Primates";
	family = "Hominidae";
	genus = "Pongo";
	species = "Pongo borneo";
}

void OrangUtan::render(WINDOW* w, int i, int j, int offi, int offj){
	mvwprintw(w, i+offi, j+offj, "O");
}

void OrangUtan::Interact(WINDOW* w, int i, int j){
    mvwprintw(w, i, j, "Week!...");
    mvwprintw(w, i+1, j, "Orang Utan makes funny face to you");
    mvwprintw(w, i+2, j, "Maybe it wants to compete with your face");
}

Bear::Bear(float _berat, bool _buas, int _x, int _y){
    nama = "Bear";
	berat = _berat;
	buas = _buas;
	x = _x;
	y = _y;
	kingdom = "Animalia";
	phylum = "Chordata";
	kelas = "Mammalia";
	order = "Carnivora";
	family = "Ursidae";
	genus = "Ursus";
	species = "Ursus arctos";
}

void Bear::render(WINDOW* w, int i, int j, int offi, int offj){
	mvwprintw(w, i+offi, j+offj, "B");
}

void Bear::Interact(WINDOW* w, int i, int j){
    mvwprintw(w, i, j, "Grooarr...");
    mvwprintw(w, i+1, j, "The bear looks so angry and even it stands on its two feet");
    mvwprintw(w, i+2, j, "Maybe it feels hungry");
}

Giraffe::Giraffe(float _berat, bool _buas, int _x, int _y){
    nama = "Giraffe";
	berat = _berat;
	buas = _buas;
	x = _x;
	y = _y;
	kingdom = "Animalia";
	phylum = "Chordata";
	kelas = "Mammalia";
	order = "Artiodactyla";
	family = "Giraffidae";
	genus = "Giraffa";
	species = "Giraffa camelopardalis";
}

void Giraffe::render(WINDOW* w, int i, int j, int offi, int offj){
	mvwprintw(w, i+offi, j+offj, "G");
}

void Giraffe::Interact(WINDOW* w, int i, int j){
    mvwprintw(w, i, j, "Kress..kress..");
    mvwprintw(w, i+1, j, "Look how tall the Giraffe is. It even can reach top of the tree");
}

Peacock::Peacock(float _berat, bool _buas, int _x, int _y){
    nama = "Peacock";
	berat = _berat;
	buas = _buas;
	x = _x;
	y = _y;
	kingdom = "Animalia";
	phylum = "Chordata";
	kelas = "Aves";
	order = "Galiformes";
	family = "Phasianidae";
	genus = "Pavo";
	species = "Pavo Cristatus";
}

void Peacock::render(WINDOW* w, int i, int j, int offi, int offj){
	mvwprintw(w, i+offi, j+offj, "C");
}

void Peacock::Interact(WINDOW* w, int i, int j){
    mvwprintw(w, i, j, "Bats!");
    mvwprintw(w, i+1, j, "The peacock opens its tail widely!");
    mvwprintw(w, i+2, j, "It wants to show off its beauty");
}

Eagle::Eagle(float _berat, bool _buas, int _x, int _y){
    nama = "Eagle";
	berat = _berat;
	buas = _buas;
	x = _x;
	y = _y;
	kingdom = "Animalia";
	phylum = "Chordata";
	kelas = "Aves";
	order = "Accipitriformes";
	family = "Accipitridae";
	genus = "Aquila";
	species = "Aquila chrysaetos";
}

void Eagle::render(WINDOW* w, int i, int j, int offi, int offj){
	mvwprintw(w, i+offi, j+offj, "E");
}

void Eagle::Interact(WINDOW* w, int i, int j){
    mvwprintw(w, i, j, "Flap..flap...");
    mvwprintw(w, i+1, j, "The eagle flies from one spot to another");
    mvwprintw(w, i+2, j, "It wants freedom!");
}

Dolphin::Dolphin(float _berat, bool _buas, int _x, int _y){
    nama = "Dolphin";
	berat = _berat;
	buas = _buas;
	x = _x;
	y = _y;
	kingdom = "Animalia";
	phylum = "Chordata";
	kelas = "Mammalia";
	order = "Cetartiodactyla";
	family = "Platanistidae";
	genus = "Platanista";
	species = "Platanista gangetica";
}

void Dolphin::render(WINDOW* w, int i, int j, int offi, int offj){
	mvwprintw(w, i+offi, j+offj, "D");
}

void Dolphin::Interact(WINDOW* w, int i, int j){
    mvwprintw(w, i, j, "Kekekek...");
    mvwprintw(w, i+1, j, "The dolphin looks happy because the zoo officer feeds it");
}

Shark::Shark(float _berat, bool _buas, int _x, int _y){
    nama = "Shark";
	berat = _berat;
	buas = _buas;
	x = _x;
	y = _y;
	kingdom = "Animalia";
	phylum = "Chordata";
	kelas = "Chondrichthyes";
	order = "Pristiophoriformes";
	family = "Pristiophoridae";
	genus = "Pliotrema";
	species = "Pliotrema Regan";
}

void Shark::render(WINDOW* w, int i, int j, int offi, int offj){
	mvwprintw(w, i+offi, j+offj, "K");
}

void Shark::Interact(WINDOW* w, int i, int j){
    mvwprintw(w, i, j, "Glup..glup..glup...");
    mvwprintw(w, i+1, j, "The shark keeps swimming around its cage");
    mvwprintw(w, i+2, j, "Because if it stops, it will drown!");
}

Horse::Horse(float _berat, bool _buas, int _x, int _y){
    nama = "Horse";
	berat = _berat;
	buas = _buas;
	x = _x;
	y = _y;
	kingdom = "Animalia";
	phylum = "Chordata";
	kelas = "Mammalia";
	order = "Perissodactyla";
	family = "Equidae";
	genus = "Equus";
	species = "Equus ferus";
}

void Horse::render(WINDOW* w, int i, int j, int offi, int offj){
	mvwprintw(w, i+offi, j+offj, "H");
}

void Horse::Interact(WINDOW* w, int i, int j){
    mvwprintw(w, i, j, "Hieehh...");
    mvwprintw(w, i+1, j, "The horse stands on its two feet!");
    mvwprintw(w, i+2, j, "Maybe it doesn't like you");
}

Snake::Snake(float _berat, bool _buas, int _x, int _y){
    nama = "Snake";
	berat = _berat;
	buas = _buas;
	x = _x;
	y = _y;
	kingdom = "Animalia";
	phylum = "Chordata";
	kelas = "Reptilia";
	order = "Squamata";
	family = "Boidae";
	genus = "Boa";
	species = " Boa constrictor";
}

void Snake::render(WINDOW* w, int i, int j, int offi, int offj){
	mvwprintw(w, i+offi, j+offj, "U");
}

void Snake::Interact(WINDOW* w, int i, int j){
    mvwprintw(w, i, j, "Ssssss...");
    mvwprintw(w, i+1, j, "The snake is hanging on the tree branch");
    mvwprintw(w, i+2, j, "It's stomach gets bigger than it should");
    mvwprintw(w, i+3, j, "Maybe it ate a mouse not so long ago");
}

Panda::Panda(float _berat, bool _buas, int _x, int _y){
    nama = "Panda";
	berat = _berat;
	buas = _buas;
	x = _x;
	y = _y;
	kingdom = "Animalia";
	phylum = "Chordata";
	kelas = "Mammalia";
	order = "Carnivora";
	family = "Ursidae";
	genus = "Ailuropoda";
	species = "	Ailuropoda melanoleuca";
}

void Panda::render(WINDOW* w, int i, int j, int offi, int offj){
	mvwprintw(w, i+offi, j+offj, "P");
}

void Panda::Interact(WINDOW* w, int i, int j){
    mvwprintw(w, i, j, "Zzz...");
    mvwprintw(w, i+1, j, "Ssshh! The panda is taking a nap");
    mvwprintw(w, i+2, j, "Don't disturb it!");
}

Turtle::Turtle(float _berat, bool _buas, int _x, int _y){
    nama = "Turtle";
	berat = _berat;
	buas = _buas;
	x = _x;
	y = _y;
	kingdom = "Animalia";
	phylum = "Chordata";
	kelas = "Reptilia";
	order = "Tustudines";
	family = "Chelydridae";
	genus = "Macrochelys";
	species = "Macrochelys temminckii";
}

void Turtle::render(WINDOW* w, int i, int j, int offi, int offj){
	mvwprintw(w, i+offi, j+offj, "T");
}

void Turtle::Interact(WINDOW* w, int i, int j){
    mvwprintw(w, i, j, "Srak..srak..");
    mvwprintw(w, i+1, j, "The turtle is walking very slowly from each other");
    mvwprintw(w, i+2, j, "Maybe they just had a meeting");
}

Alligator::Alligator(float _berat, bool _buas, int _x, int _y){
    nama = "Alligator";
	berat = _berat;
	buas = _buas;
	x = _x;
	y = _y;
	kingdom = "Animalia";
	phylum = "Chordata";
	kelas = "Reptilia";
	order = "Crocodilia";
	family = "Alligatoridae";
	genus = "Alligator";
	species = "Alligator sinensis";
}

void Alligator::render(WINDOW* w, int i, int j, int offi, int offj){
	mvwprintw(w, i+offi, j+offj, "A");
}

void Alligator::Interact(WINDOW* w, int i, int j){
    mvwprintw(w, i, j, "siiing....");
    mvwprintw(w, i+1, j, "The alligator is really quit and doesn't move");
    mvwprintw(w, i+2, j, "It is taking a sun bath");
}

Kangoroo::Kangoroo(float _berat, bool _buas, int _x, int _y){
    nama = "Kangoroo";
	berat = _berat;
	buas = _buas;
	x = _x;
	y = _y;
	kingdom = "Animalia";
	phylum = "Chordata";
	kelas = "Mammalia";
	order = "Diprotodontia";
	family = "Macropodidae";
	genus = "Macropus";
	species = "Macropus fuliginosus";
}

void Kangoroo::render(WINDOW* w, int i, int j, int offi, int offj){
	mvwprintw(w, i+offi, j+offj, "K");
}

void Kangoroo::Interact(WINDOW* w, int i, int j){
    mvwprintw(w, i, j, "Tuing..tuing..");
    mvwprintw(w, i+1, j, "The kangoroo is jumping all over the cage");
    mvwprintw(w, i+2, j, "It is like it wants to punch someone");
}

