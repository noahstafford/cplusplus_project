#include <iostream>
#include <string>
#include "Dungeon.h"
#include <vector>

using namespace std;

Dungeon::Dungeon(int num_of_rooms, int difficulty) {
    this->num_of_rooms = num_of_rooms;
    this->difficulty = difficulty;
}


void Dungeon::create_room() {
    

}

void Dungeon::create_encounter() {

}

void Dungeon::spawn_monster() {

}

void Dungeon::random_event() {

}

void Dungeon::select_next_room() {
    vector<string> rooms = generate_dungeon();
}

vector<string> Dungeon::generate_dungeon() {
    int num_of_connecting_rooms = (rand() % 5) + 1; //gets number 1-5
    if (num_of_connecting_rooms == 1) {
        cout << "You have " << num_of_connecting_rooms << " option on where to go next.";
    }
    else {
        cout << "You have " << num_of_connecting_rooms << " options on where to go next.";
    }

    vector<string> rooms;
    rooms.push_back("There is a door to the West. (w)");

    if (num_of_connecting_rooms > 1) {
        rooms.push_back("There is a door to the North. (n)");
    }
    if (num_of_connecting_rooms > 2) {
        rooms.push_back("There is a door to the East. (e)");
    }
    if (num_of_connecting_rooms > 3) {
        rooms.push_back("There is a ladder that leads up a level. (u)");
    }
    if (num_of_connecting_rooms > 4) {
        rooms.push_back("There is a hatch that leads down a level. (d)");
    }

    return rooms;
    //not the MOST random or the MOST efficent and doesn't make the MOST sense but it works
}