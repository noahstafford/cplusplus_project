#ifndef MONSTER_H
#define MONSTER_H
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Monster
{
    public:
        Monster (int difficulty);
        Monster spawn_monster(int difficulty);
        int attack_player();
        int defend();
        int get_health();
        void set_health(int new_health);
        int get_attack_damage();
        void set_attack_damage(int new_attack_damage);
        int get_experience_for_killing();
        void set_experience_for_killing(int new_experience_for_killing);
        string get_name();
        string get_description();
        string get_info();
    private:
        string name;
        int health;
        int attack;
        int defense;
        int experience_for_killing;
        string description;
};

#endif