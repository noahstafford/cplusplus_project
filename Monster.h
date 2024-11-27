#ifndef MONSTER_H
#define MONSTER_H
#include <iostream>
#include <string>

using namespace std;

class Monster
{
    public:
        Monster (string name, int health, int attack, int defense, int experience_for_killing, int difficulty);
        int attack_player();
        int defend();
        int get_health();
        void set_health(int new_health);
        int get_attack_damage();
        void set_attack_damage(int new_attack_damage);
        int get_experience_for_killing();
        void set_experience_for_killing(int new_experience_for_killing);
    private:
        string name;
        int health;
        int attack;
        int defense;
        int experience_for_killing;
        int difficulty;
};

#endif