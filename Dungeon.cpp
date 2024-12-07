#include <iostream>
#include <string>
#include "Dungeon.h"
#include <vector>
#include "Monster.h"
#include <ctime>

using namespace std;

Dungeon::Dungeon(int num_of_rooms, int difficulty) {
    this->num_of_rooms = num_of_rooms;
    this->difficulty = difficulty;
}


void Dungeon::create_room(string choice) {
    cout << random_description() << endl << endl;

}

void Dungeon::create_encounter() {

}

void Dungeon::random_event() {

}

void Dungeon::select_next_room() {
    srand(time(0));
    vector<string> rooms = generate_dungeon();
    string choice = "";
    bool validchoice = false;

    while (!validchoice) {
        cout << "It is time to select a new room to traverse." << endl;
        for (int x = 0; x < rooms.size(); x++) {
            cout << rooms[x] << endl;
        }

        cout << endl << endl;
        cout << "What is your choice? ";
        cin >> choice;
        cout << endl;
        validchoice = validate_choice(choice, rooms);
    }

    cout << endl;
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
    srand(time(0));
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
    srand(time(0));
    int num = rand() % 11;
    if (num == 0) {
        return "The room is pitch black. This narrow, twisting passage seems to stretch endlessly, the walls a swirling black mist that shifts with every step. The air feels thick, and the sound of your footsteps is muffled by an unplaceable silence that stretches out of time itself.";
    }
    else if (num == 1) {
        return "You're in a library. Ancient books float lazily around the room, their pages turning on their own. The shelves are alive, rearranging themselves as you step closer, offering secrets and knowledge just out of reach.";
    }
    else if (num == 2) {
        return "This chamber is filled with shimmering, silver-framed mirrors that reflect not the room itself, but alternate versions of reality. As you move, the reflections seem to delay, casting strange shadows of yourself that act independently.";
    }
    else if (num == 3) {
        return "Massive gears spin above, their teeth grinding in the air as the room pulses with a mechanical hum. The floor is smooth but cold, and strange symbols are etched into the walls, glowing faintly at irregular intervals.";
    }
    else if (num == 4) {
        return "A serene pool of water floats in mid-air, rippling with no visible source. Around the edges, ethereal fish swim through the air as if weightless, and soft melodies echo from the depths below.";
    }
    else if (num == 5) {
        return "A winding staircase spirals upward, yet no matter how many steps you take, the top is always out of reach. The walls hum with ancient energy, and faint whispers seem to call from above, urging you to climb higher.";
    }
    else if (num == 6) {
        return "Hundreds of glowing crystal plants stretch upward, their colorful blooms flickering like stars. The air smells of ozone, and the ground shifts ever so slightly beneath your feet, as if the plants are gently moving, alive.";
    }
    else if (num == 7) {
        return "The walls pulse with an otherworldly hum that shifts in tone and pitch, creating a strange melody that echoes through the air. The room seems to be alive, resonating with the sound of your presence as if it is singing to you.";
    }
    else if (num == 8) {
        return "Stars twinkle in the sky above, though no ceiling exists. The floor is dotted with small craters, as if meteorites have crashed down into the room, each crater radiating a soft, mystical light.";
    }
    else if (num == 9) {
        return "Gravity in this room is upside down, with the floor above you and the ceiling below. The walls drip with liquid light that pulses, and the air is thick with a strange, magnetic pull, urging you to defy the laws of nature.";
    }
    else if (num == 10) {
        return "A once-sturdy stone bridge now crumbles over a deep, dark ravine. Sections of it are missing, and the rest seems precariously close to falling. The distant sound of water rushing below fills the room, and the scent of damp stone hangs heavy in the air.";
    }
}