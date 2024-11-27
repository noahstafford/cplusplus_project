#ifndef CHARACTER_H
#define CHARACTER_H
#include <iostream>
#include <string>

using namespace std;

class Character
{
    public:
        Character (string name, int level, int health, int attack, int experience, int critical_hit_chance);
        void level_up();
        int attack_enemy();
        int defend(int damage_taken);
        int take_damage(int damage_taken);
        int heal(int healing_taken);
        int get_level();
        void set_level();
        int get_health();
        void set_health(int new_health);
        int get_attack();
        void set_attack(int attack_power);
        int get_experience();
        void set_experience(int experience_gained);
        int get_experience_to_level_up();
        void set_experience_to_level_up();
    private:
        string name;
        int level;
        int health;
        int attack;
        int critical_hit_chance;
        int experience;
        int experience_to_level_up;
};

#endif