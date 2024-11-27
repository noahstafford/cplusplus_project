#include <iostream>
#include <string>
#include "Character.h"

using namespace std;

Character::Character(string name, int level, int health, int attack, int experience, int critical_hit_chance) 
{
    this->name = name;
    this->level = level;
    this->health = health;
    this->attack = attack;
    this->experience = experience;
    this->critical_hit_chance = critical_hit_chance;
}

void Character::level_up() {
    if (experience >= experience_to_level_up) {
        level++;
        experience = 0;
        experience_to_level_up += (experience_to_level_up * .25);
        critical_hit_chance++;
    } 
}

int Character::attack_enemy() {
    return attack; //this will eventually factor in critical hits and missing and stuff
}

int Character::defend(int damage_taken) {
    return 1;
}

int Character::take_damage(int damage_taken){
    return 1;
}

int Character::heal(int healing_taken){
    return 1;
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