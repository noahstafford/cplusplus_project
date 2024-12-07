#ifndef DUNGEON_H
#define DUNGEON_H
#include <iostream>
#include <string>
#include <vector>
#include "Monster.h"

using namespace std;

class Dungeon
{
    public:
        Dungeon(int num_of_rooms, int difficulty);
        void create_room(string choice);
        void create_encounter();
        Monster spawn_monster();
        int random_event();
        vector<string> generate_dungeon();
        bool validate_choice(string choice, vector<string> rooms);
        void select_next_room();
        string random_description();
    private:
        string room_description;
        int num_of_rooms;
        int difficulty;
};

#endif