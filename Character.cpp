#include <iostream>
#include <string>
#include "Character.h"

using namespace std;

Character::Character(string name) 
{
    this->name = name;
    level = 0;
    current_health = 100;
    max_health = 100;
    attack = 10;
    defense = 5;
    experience = 0;
    experience_to_level_up = 100;
    critical_hit_chance = 5;
}

void Character::level_up() {
    while (experience >= experience_to_level_up) {
        level++;
        experience = experience - experience_to_level_up;
        experience_to_level_up += (experience_to_level_up * .25);
        critical_hit_chance += 2;
        defense += (defense * .1);
        max_health += (max_health * .1);
    } 
}

int Character::attack_enemy() {
    int randomNum = rand() % 101;
    if (critical_hit_chance > randomNum) {
        return attack * 3;
    }
    else if (critical_hit_chance == 0) {
        return 0;   //missed attack
    }
    return attack;
}

int Character::defend(int damage_taken) {
    current_health = current_health - (damage_taken/3);
    return damage_taken/3;
}

int Character::take_damage(int damage_taken){
    current_health = current_health - damage_taken;
    return damage_taken;
}

int Character::heal(int healing_taken){
    if ((current_health + healing_taken) > max_health) {
        current_health = max_health;
    } else {
        current_health += healing_taken;
    }
    return current_health;
}

int Character::get_level() {
    return level;
}

int Character::get_health() {
    return current_health;
}

void Character::set_health(int new_health) {
    current_health = new_health;
}

void Character::set_attack(int attack_power) {
    attack = attack_power;
}

int Character::get_experience() {
    return experience;
}

void Character::set_experience(int experience_gained) {
    experience += experience_gained;
}

string Character::get_name() {
    return name;
}

void Character::get_stats() {
    cout << "Level: " << level << endl;
    cout << "Health: " << current_health << "/" << max_health << endl;
    cout << "Experience: " << experience << "/" << experience_to_level_up << endl;
    cout << "Attack: " << attack << endl;
    cout << "Defense: " << defense << endl;
}