#include <iostream>
#include <string>
#include "Character.h"
#include "Dungeon.h"
#include "Monster.h"

using namespace std;

int main() {

    string name;
    cout << "Enter a name for your character: "; // Type a number and press enter
    cin >> name;
    int difficulty = 0;
    while (difficulty > 5 || difficulty < 1) {
        cout << "How difficult do you want the game to be? Scale of 1-5 ";
        cin >> difficulty;
    }
    int rooms = 0;
    while (rooms <= 0) {
        cout << "How many rooms should the dungeon have? ";
        cin >> rooms;
    }

    Character player(name);
    cout << player.get_name() << endl;
    cout << player.get_experience() << endl;
    player.set_experience(123);
    cout << player.get_experience() << endl;
    player.level_up();
    cout << player.get_level() << endl;
    cout << player.get_experience() << endl;

}