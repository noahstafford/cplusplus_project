#include <iostream>
#include <string>
#include "Monster.h"
#include <vector>

using namespace std;

Monster::Monster(int difficulty) {
    int num = (rand() % difficulty) + 1;
    if (num == 1) {
        name = "Rat";
        health = 10;
        attack = 2;
        defense = 2;
        experience_for_killing = 15;
        description = "The rat scurries around on the floor. It attempts to scratch you.";
    }
    else if (num == 2) {
        name = "Bat";
        health = 15;
        attack = 3;
        defense = 5;
        experience_for_killing = 20;
        description = "The bat flys at you and attempts to bite you.";
        //Monster monster("Bat", 15, 3, 5, 20, "The bat flys at you and attempts to bite you.");
        
    }
    else if (num == 3) {
        name = "Slime";
        health = 20;
        attack = 4;
        defense = 7;
        experience_for_killing = 25;
        description = "The slime bounces and jiggles towards you. An arm oozes out and attempts to hit you.";
        //Monster monster("Slime", 20, 4, 7, 25, "The slime bounces and jiggles towards you. An arm oozes out and attempts to hit you.");
        
    }
    else if (num == 4) {
        name = "Skeleton";
        health = 25;
        attack = 5;
        defense = 10;
        experience_for_killing = 30;
        description = "The skeleton readies his sword and swings.";
        //Monster monster("Skeleton", 25, 5, 10, 30, "The skeleton readies his sword and swings.");
        
    }
    else if (num == 5) {
        name = "Wizard";
        health = 30;
        attack = 6;
        defense = 15;
        experience_for_killing = 35;
        description = "The wizard raises his staff into the air and casts a spell.";
        //Monster monster("Wizard", 30, 6, 15, 35, "The wizard raises his staff into the air and casts a spell.");
        
    }
}

/*
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
*/

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
    if (health < 0) {
        health = 0;
    }
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

string Monster::get_info() {
    return name + " has " + to_string(health) + " hp ";
}