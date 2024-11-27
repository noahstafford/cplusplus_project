#ifndef CHARACTER_H
#define CHARACTER_H
#include <iostream>
#include <string>

using namespace std;

class Character
{
    public:
        Character (string name, int level, int health, int attack, int experience);
        void level_up();
        int attack();
        int defend();
        void get_level();
        void set_level();
        void get_health();
        void set_health();
        void get_attack();
        void set_attack();
        void get_experience();
        void set_experience();
    private:
        string name;
        int level;
        int health;
        int attack;
        int experience;
};

#endif