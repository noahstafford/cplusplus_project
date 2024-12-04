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
    string choice = "";
    bool validchoice = false;

    while (choice != "w" && choice != "n" && choice != "e" && choice != "u" && choice != "d" && validchoice == false) {
        cout << "It is time to select a new room to traverse." << endl;
        for (int x = 0; x < rooms.size(); x++) {
            cout << rooms[x] << endl;
        }

        cout << "What is your choice? ";
        cin >> choice;
        validate_choice(choice, rooms);
}

}

bool Dungeon::validate_choice(string choice, vector<string> rooms) {

    if (choice == "w" && rooms.size() >= 0) {
        return true;
    }
    else if (choice == "n" && rooms.size() >= 1) {
        return true;
    }
    else if (choice == "e" && rooms.size() >= 3) {
        return true;
    }
    else if (choice == "u" && rooms.size() >= 4) {
        return true;
    }
    else if (choice == "d" && rooms.size() >= 5) {
        return true;
    }
}

vector<string> Dungeon::generate_dungeon() {
    int num_of_connecting_rooms = (rand() % 5) + 1; //gets number 1-5
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