#include <iostream>
#include <string>
#include "Monster.h"

using namespace std;

Monster::Monster(string name, int health, int attack, int defense, int experience_for_killing, int difficulty) {
    this->name = name;
    this->health = health;
    this->attack = attack;
    this->defense = defense;
    this->experience_for_killing = experience_for_killing;
    this->difficulty = difficulty;
}

int Monster::attack_player(){
    return attack;
}

int Monster::defend(){
    return 1;
}

int Monster::get_health(){
    return health;
}

void Monster::set_health(int new_health){
    health = new_health;
}

void Monster::set_attack_damage(int new_attack_damage) {
    attack = new_attack_damage;
}

int Monster::get_experience_for_killing() {
    return experience_for_killing;
}

void Monster::set_experience_for_killing(int new_experience_for_killing) {
    experience_for_killing = new_experience_for_killing;
}