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
        cout << "How difficult do you want the game to be, scale of 1-5? ";
        cin >> difficulty;
    }
    int rooms = 0;
    while (rooms <= 0) {
        cout << "How many rooms should the dungeon have? ";
        cin >> rooms;
    }

    Character player(name);
    Dungeon dungeon(rooms, difficulty);
    //Monster monster("", 0, 0, 0, 0, "");
    //Monster monster(difficulty);

    for (int x = 0; x < rooms; x++) {
        cout << endl;
        dungeon.select_next_room();
        // monster.spawn_monster(difficulty);
        Monster monster(difficulty);
        monster.get_info();
        player.start_battle(monster);
        if (player.get_health() <= 0) {
            x = rooms;
        }
        cout << endl;
    }

    if (player.get_health() > 0) {
        cout << "Congratulations, you reached the end." << endl;
    }
    player.get_stats();
}