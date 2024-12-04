#include <iostream>
#include <string>
#include "Dungeon.h"
#include <vector>

using namespace std;

Dungeon::Dungeon(int num_of_rooms, int difficulty) {
    this->num_of_rooms = num_of_rooms;
    this->difficulty = difficulty;
}


void Dungeon::create_room(string choice) {
    cout << random_description() << endl;
    spawn_monster();
    create_encounter();
    
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

    while (!validchoice) {
        cout << "It is time to select a new room to traverse." << endl;
        for (int x = 0; x < rooms.size(); x++) {
            cout << rooms[x] << endl;
        }

        cout << "What is your choice? ";
        cin >> choice;
        validchoice = validate_choice(choice, rooms);
}

    if (choice == "u") {
        cout << "You climb the ladder. It falls behind you, leaving you trapped." << endl;
    }
    else if (choice == "d") {
        cout << "You drop down into the room below you." << endl;
    }
    else {
        cout << "You enter the room and the door slams shut behind you." << endl;
    }
    create_room(choice);

}

bool Dungeon::validate_choice(string choice, vector<string> rooms) {

    if (choice == "w" && rooms.size() >= 0) {
        return true;
    }
    else if (choice == "n" && rooms.size() >= 1) {
        return true;
    }
    else if (choice == "e" && rooms.size() >= 2) {
        return true;
    }
    else if (choice == "u" && rooms.size() >= 3) {
        return true;
    }
    else if (choice == "d" && rooms.size() >= 4) {
        return true;
    }

    return false;
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

string Dungeon::random_description() {
    int num = rand() % 11;
    if (num == 0) {
        return "The room is pitch black";
    }
    else if (num == 1) {
        return "The room is pitch black";
    }
    else if (num == 2) {
        return "The room is pitch black";
    }
    else if (num == 3) {
        return "The room is pitch black";
    }
    else if (num == 4) {
        return "The room is pitch black";
    }
    else if (num == 5) {
        return "The room is pitch black";
    }
    else if (num == 6) {
        return "The room is pitch black";
    }
    else if (num == 7) {
        return "The room is pitch black";
    }
    else if (num == 8) {
        return "The room is pitch black";
    }
    else if (num == 9) {
        return "The room is pitch black";
    }
    else if (num == 10) {
        return "The room is pitch black";
    }
}