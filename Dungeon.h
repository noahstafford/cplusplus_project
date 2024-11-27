#ifndef DUNGEON_H
#define DUNGEON_H
#include <iostream>
#include <string>

using namespace std;

class Dungeon
{
    public:
        Dungeon(int num_of_rooms, int difficulty);
        void create_room();
        void create_encounter();
        void spawn_monster();
        void random_event();
    private:
        string room_description;
        int num_of_rooms;
        int difficulty;
};

#endif