#include <iostream>
#include <string>
#include "Character.h"
#include "Monster.h"
#include <ctime>

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
    experience_to_level_up = 50;
    critical_hit_chance = 5;
    defending = false;
}

void Character::level_up() {
    while (experience >= experience_to_level_up) {
        cout << "LEVEL UP!" << endl;
        cout << "Level: " << level << " -> ";
        level++;
        cout << level << endl;
        experience = experience - experience_to_level_up;
        cout << "Experience needed for next level up: " << experience_to_level_up << " -> ";
        experience_to_level_up += (experience_to_level_up * .25);
        cout << experience_to_level_up << endl;
        cout << "Critical hit chance: " << critical_hit_chance << " -> ";
        critical_hit_chance += 2;
        cout << critical_hit_chance << endl;
        cout << "Defense: " << defense << " -> ";
        defense += 1;
        cout << defense << endl;
        cout << "Max Health: " << max_health << " -> ";
        max_health += (max_health * .1);
        cout << max_health << endl;
        current_health = max_health;
        cout << "You have been healed to full health!" << endl;
    } 
}

int Character::attack_enemy() {
    srand(time(0));
    int randomNum = rand() % 101;
    
    if (critical_hit_chance > randomNum) {
        cout << "CRITICAL HIT!" << endl;
        return attack * 3;
    }
    else if (randomNum == 0) {
        cout << "YOU MISSED!" << endl;
        return 0;   //missed attack
    }
    else {
        cout << "You hit!" << endl;
        return attack;
    }
    return attack;
}

int Character::defend(int damage_taken) {
    current_health = current_health - (damage_taken/3);
    return damage_taken/3;
}

int Character::take_damage(int damage_taken){
    damage_taken = damage_taken - (defense / 3);
    current_health = current_health - damage_taken;
    cout << "It attacks for " << damage_taken << " damage." << endl;
    return damage_taken;
}

int Character::heal(int healing_taken){
    int actual_healing;
    if ((current_health + healing_taken) > max_health) {
        actual_healing = max_health - current_health;
        current_health = max_health;
    } else {
        actual_healing = healing_taken;
        current_health += healing_taken;
    }
    
    cout << "You healed " << actual_healing << "hp. Your health is now " << current_health << "." << endl;
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
    cout << "You gained " << experience_gained << " xp!" << endl;
    if (experience >= experience_to_level_up) {
        level_up();
    }
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

int Character::players_turn() {
    int damage;
    cout << "What are you going to do?" << endl;
    bool validoption = false;
    string option = "";

    while (option != "a" && option != "d" && option != "h") {
        cout << "Attack (a)" << endl;
        cout << "Defend (d)" << endl;
        cout << "Heal (h)" << endl;
        cin >> option;
    }

    if (option == "a") {
        cout << "You attempt to attack the enemy." << endl;
        damage = attack_enemy();
        cout << "You damage the enemy for " << damage << " hp" << endl; 
        return damage;
        //monster.set_health(monster.get_health() - damage);
        //cout << monster.get_name() << "'s current health: " << monster.get_health() << endl;
    }
    else if (option == "d") {
        cout << "You are now defending." << endl;
        defending = true;
    }
    else if (option == "h") {
        cout << "You cast a healing spell" << endl;
        heal(max_health / 5);

    }
    return 0;
}

void Character::start_battle(Monster monster) {
    srand(time(0));
    bool isitplayersturn = false;
    int num = rand() % 2;
    bool first_turn = true;
    int damage_taken;

    if (num == 0) {
        isitplayersturn = true;
    }

    cout << "You encounter a " << monster.get_name() << "..." << endl;
    cout << "Coin flip....";

    while (current_health > 0 && monster.get_health() > 0) {
        if (isitplayersturn) {
            if (first_turn) { 
                cout << "Your turn is first." << endl; 
                first_turn = false;
            }
            else {
                cout << "It's now your turn." << endl;
            }
            damage_taken = players_turn();
            if (damage_taken > 0) {
                monster.set_health(monster.get_health() - damage_taken);
                cout << monster.get_name() << "'s current health: " << monster.get_health() << endl;
            }
            isitplayersturn = false;
            
        }
        else {
            if (first_turn) {
                cout << "It attacks first." << endl;
                first_turn = false;
            }
            else {
                cout << "It's now their turn. Prepare.." << endl;
            }
    
            cout << monster.get_description() << endl;
            if (defending) {
                cout << "You are defending." << endl;
                defending = false;
                damage_taken = defend(monster.attack_player());
                cout << "You took " << damage_taken << " damage." << endl;
            }
            else {
                take_damage(monster.attack_player());
            }
            isitplayersturn = true;
            cout << name << "'s current health: " << current_health << "/" << max_health << endl;
        }
        
    }
    if (current_health == 0) {
        cout << "YOU DIED!" << endl;
    }
    else {
        cout << "The " << monster.get_name() << " died." << endl;
        set_experience(monster.get_experience_for_killing());
    }
    
}