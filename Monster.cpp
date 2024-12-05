#include <iostream>
#include <string>
#include "Monster.h"
#include <vector>

using namespace std;

Monster::Monster(string name, int health, int attack, int defense, int experience_for_killing, string description) {
    this->name = name;
    this->health = health;
    this->attack = attack;
    this->defense = defense;
    this->experience_for_killing = experience_for_killing;
    this->description = description;
}


Monster spawn_monster(int difficulty) {
    int num = (rand() % difficulty) + 1;
    if (num == 1) {
        Monster monster("Rat", 10, 2, 2, 15, "The rat scurries around on the floor. It attempts to scratch you.");
        return monster;
    }
    else if (num == 2) {
        Monster monster("Bat", 15, 3, 5, 20, "The bat flys at you and attempts to bite you.");
        return monster;
    }
    else if (num == 3) {
        Monster monster("Slime", 20, 4, 7, 25, "The slime bounces and jiggles towards you. An arm oozes out and attempts to hit you.");
        return monster;
    }
    else if (num == 4) {
        Monster monster("Skeleton", 25, 5, 10, 30, "The skeleton readies his sword and swings.");
        return monster;
    }
    else if (num == 5) {
        Monster monster("Wizard", 30, 6, 15, 35, "The wizard raises his staff into the air and casts a spell.");
        return monster;
    }

    Monster monster("Rat", 10, 2, 2, 15, "The rat scurries around on the floor. It attempts to scratch you.");
    return monster;
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

string Monster::get_name() {
    return name;
}

string Monster::get_description() {
    return description;
}