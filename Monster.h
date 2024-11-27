#ifndef MONSTER_H
#define MONSTER_H
#include <iostream>
#include <string>

using namespace std;

class Monster
{
    public:
        Monster (string name, int health, int attack_damage, int experience_for_killing);
        int attack();
        int defend();
        void get_health();
        void set_health();
        void get_attack_damage();
        void set_attack_damage();
        void get_experience_for_killing();
        void set_experience_for_killing();
    private:
        string name;
        int health;
        int attack_damage;
        int experience_for_killing;
};

#endif