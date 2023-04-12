#include <iostream>
#include <string>

#include "Character.h"
#include "Enemy.h"

using namespace std;

string WelcomeMsg() {
    string characterName;

    cout << "Welcome to Dungeon Crawler Simulator!" << endl;
    cout << endl;
    cout << "Enter the name of your character: ";
    getline(cin, characterName);

    return characterName;
}

void HelloMsg(Character character) {
    cout << endl;
    cout << "Hello " << character.GetName() << "!" << endl;
    cout << endl;

}

int AskAmountMonsters() {
    int amountMonsters; 

    cout << endl;
    cout << "How many monster do you want to fight? ";
    cin >> amountMonsters;
    cout << endl;

    return amountMonsters;
}

Enemy* GenerateEnemies(int amountMonsters, int* amountSmallMonsters,
                    int* amountMediumMonsters, int* amountBigMonsters) {
    Enemy* arrayEnemies = new Enemy[amountMonsters];

    srand(time(NULL));
    int offset = 1;
    int healthRange = 10;
    int damageRange = 5;
    int sizesRange = 3;

    

    for (int i = 0; i < amountMonsters; i++) {
        int randHealth = offset + rand() % healthRange;
        int randDamage = offset + rand() % damageRange;

        arrayEnemies[i].SetHealth(randHealth);
        arrayEnemies[i].SetDamage(randDamage);

        if (randDamage < 3) {
            arrayEnemies[i].SetSize(Enemy::SMALL);
            (*amountSmallMonsters)++;
        }
        else {
            if (randDamage > 3) {
                arrayEnemies[i].SetSize(Enemy::BIG);
                (*amountBigMonsters)++;
            }
            else {
                arrayEnemies[i].SetSize(Enemy::MEDIUM);
                (*amountMediumMonsters)++;
            }
        }
    }

    return arrayEnemies;
}

void PrintEnemies(int amountMonsters, Enemy* arrayEnemies) {
    for (int i = 0; i < amountMonsters; i++) {
        cout << "Monster " << i + 1 << endl;
        cout << "Health: " << arrayEnemies[i].GetHealth() << endl;
        cout << "Damage: " << arrayEnemies[i].GetDamage() << endl;
        switch (arrayEnemies[i].GetSize()) {

        case Enemy::SMALL: {
            cout << "Size: SMALL" << endl;
            break;
        }
        case Enemy::MEDIUM: {
            cout << "Size: MEDIUM" << endl;
            break;
        }
        case Enemy::BIG: {
            cout << "Size: BIG" << endl;
            break;
        }
        }
        cout << endl;

    }
}

void PrintCharacter(Character character) {
    cout << endl;
    cout << character.GetName() << endl;
    cout << "Health: " << character.GetHealth() << endl;
    cout << "Damage: " << character.GetDamage() << endl;
    cout << endl;
}

void PrintTotalMonsters(int amountSmall, int killedSmall, int amountMedium,
    int killedMedium, int amountBig, int killedBig) {
    cout << endl;
    cout << "Small: " << killedSmall << "/" <<  amountSmall << endl;
    cout << "Medium: " << killedMedium << "/" <<  amountMedium << endl;
    cout << "Big: " << killedBig << "/" <<  amountBig << endl;
    cout << endl;
}

void Battle(Character* player, Enemy* enemy) {
    while (player->GetHealth() > 0 && enemy->GetHealth() > 0) {
        enemy->SetHealth(enemy->GetHealth() - player->GetDamage());
        player->DecreaseHealth(enemy->GetDamage());
    }
}

int main()
{
    Character playerCharacter;

    playerCharacter.SetName(WelcomeMsg());
    HelloMsg(playerCharacter);
    
    int amountMonsters = AskAmountMonsters();

    cout << "Preparing " << amountMonsters << " monsters..." << endl;
    cout << endl;

    int amountSmallMonsters = 0;
    int amountMediumMonsters = 0;
    int amountBigMonsters = 0;

    int killSmall = 0;
    int killMedium = 0;
    int killBig = 0;

    Enemy* arrayEnemies = GenerateEnemies(amountMonsters, &amountSmallMonsters,
        &amountMediumMonsters, &amountBigMonsters);

    /*PrintTotalMonsters(amountSmallMonsters, killSmall, amountMediumMonsters,
        killMedium, amountBigMonsters, killBig);
    cout << "-----------------------------" << endl;*/

    /*PrintEnemies(amountMonsters, arrayEnemies);
    PrintCharacter(playerCharacter);
    cout << "-----------------------------" << endl;*/

    for (int i = 0; i < amountMonsters; i++) {
        Battle(&playerCharacter, &arrayEnemies[i]);

        if (playerCharacter.GetHealth() > 0) {
            playerCharacter.LevelUp();

            switch (arrayEnemies[i].GetSize()) {
            case Enemy::SMALL:{
                killSmall++;
                break;
                }
            case Enemy::MEDIUM: {
                killMedium++;
                break;
            }
            case Enemy::BIG: {
                killBig++;
                break;
            }
            }
                        

            /*PrintEnemies(amountMonsters, arrayEnemies);
            PrintCharacter(playerCharacter);
            cout << "-----------------------------" << endl;*/

        }
        else {            
            cout << "You lose!" << endl;
            cout << "Enemies Slain: " << endl;
            PrintTotalMonsters(amountSmallMonsters, killSmall, amountMediumMonsters,
                killMedium, amountBigMonsters, killBig);
            break;
        }
                
    }
    if (playerCharacter.GetHealth() > 0) {
        cout << "You win!" << endl;
        cout << "Enemies Slain: " << endl;
        PrintTotalMonsters(amountSmallMonsters, killSmall, amountMediumMonsters,
            killMedium, amountBigMonsters, killBig);
    }

}

