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
    Character player(name, 0, 100, 10, 10, 0, 1);
    cout << player.get_name();
}