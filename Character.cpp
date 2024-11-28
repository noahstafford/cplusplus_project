#include <iostream>
#include <string>
#include "Character.h"

using namespace std;

Character::Character(string name) 
{
    this->name = name;
    level = 0;
    health = 100;
    attack = 10;
    defense = 5;
    experience = 0;
    experience_to_level_up = 100;
    critical_hit_chance = 5;
}

void Character::level_up() {
    while (experience >= experience_to_level_up) {
        level++;
        experience = experience-experience_to_level_up;
        experience_to_level_up += (experience_to_level_up * .25);
        critical_hit_chance += 5;
        defense += (defense * .1);
        health += (health * .1);
    } 
}

int Character::attack_enemy() {
    int randomNum = rand() % 101;
    if (critical_hit_chance > randomNum) {
        return attack * 3;
    }
    return attack;
}

int Character::defend(int damage_taken) {
    health = health - (damage_taken/3);
    return damage_taken/3;
}

int Character::take_damage(int damage_taken){
    health = health - damage_taken;
    return damage_taken;
}

int Character::heal(int healing_taken){
    health += healing_taken;
    return health;
}

int Character::get_level() {
    return level;
}

int Character::get_health() {
    return health;
}

void Character::set_health(int new_health) {
    health = new_health;
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