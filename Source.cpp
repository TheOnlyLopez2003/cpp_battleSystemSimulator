#include<iostream>
using namespace std;

//globals
string WeaponsAndArmor[6] = { "Flame Sword", "Fire Armor", "Ice Wand", "Jump Boots", "Wool Socks", "Party Hat" };
string items[3] = { "Health Potion", "Smoke Bomb", "Ham" };
int itemNums[3] = { 2,5,1 };
int PlayerHealth = 100;

//function decleration
void BattleSystem(int MonsterType);

int main() {

	int input;
	do {

		cout << endl << endl << "************BATTLE SYSTEM SIMULATOR************" << endl;
		cout << "Press 1-4 to test battle system, or 0 to quit" << endl; //numbers are different monsters
		PlayerHealth = 100; //reset health (testing purposes)
		cin >> input;
		BattleSystem(input);

	} while (input != 0);

	cout << "Goodbye" << endl;

}

//function definition
void BattleSystem(int MonsterType) {

	int MonsterHealth;
	int damage;
	char input;
	int input2;
	bool CanRun = false;
	bool SmokeCloud = false;

	switch (MonsterType) {

	case 1:
		cout << "An octorok appeared!" << endl;
		MonsterHealth = 20;
		break;
	case 2:
		cout << "An ice demon appeared!" << endl;
		MonsterHealth = 40;
		break;
	case 3:
		cout << "A fire bat appeared!" << endl;
		MonsterHealth = 10;
		break;
	case 4:
		cout << "A dragon appeared!" << endl;
		MonsterHealth = 100;
		break;
	}

	//battle loop
	while (MonsterHealth >= 0 && PlayerHealth >= 0 && CanRun == false) {

		cout << endl << endl << "The monster currently has " << MonsterHealth << " HP left..." << endl;
		cout << "Your HP is " << PlayerHealth << "..." << endl;
		cout << "Press 'f' to fight, 'i' to use item, 'v' to view item, or 'r' to run..." << endl;
		cin >> input;
		switch (input) {

			//fight case, fight case, fight case, fight case, fight case, fight case, fight case, 
		case 'f':
			//flame sword hits harder on ice enemies
			if (MonsterType == 2 && WeaponsAndArmor[0].compare("Flame Sword") == 0) {
				damage = rand() % 20;
				cout << "Your Flame Sword slices through the frost for " << damage << " damage..." << endl;
			}
			//ice wand hits harder on fire enemies
			else if (MonsterType == 3 && WeaponsAndArmor[2].compare("Ice Wand") == 0) {
				damage = rand() % 30;
				cout << "Your Ice Wand froze the enemy for " << damage << " damage..." << endl;
			}
			//no special weapon used
			else {
				damage = rand() % 10;
				cout << "You swung your sword for " << damage << " damage..." << endl;
			}

			MonsterHealth -= damage;
			break;
		case 'i':
			cout << "Press 1 to use health potion, 2 to use smoke bomb, 3 to use ham..." << endl;
			cin >> input2;

			//check if you have a health potion, if you do, add to player health and subtract from items
			if (itemNums[input2 - 1] <= 0) {
				cout << "Sorry, you don't have any left..." << endl;
			}
			else if (input2 == 1) {
				cout << "GLUG GLUG" << endl;
				PlayerHealth += 20;
				itemNums[0] -= 1;
			}
			else if (input2 == 2) {
				cout << "POOP" << endl;
				itemNums[1] -= 1;
				SmokeCloud = true;
			}
			else if (input2 == 3) {
				cout << "You drop the ham on the ground with a turd..." << endl;
				if (MonsterType == 4) {
					cout << "The dragon greedily grabs it and flies away..." << endl;
					CanRun = true;
				}
				else {
					cout << "The monsters briefly eye the ham with suspicion, then turn their attention back to you..." << endl;
				}
			}
			break;
		//view  items case, view items case, view items case, view items case, view items case, view items case, view items case
		case 'v':
			cout << "Your items..." << endl;
			for (int w = 0; w < 3; w++) {
				cout << itemNums[w] << " " << items[w] << endl;
			}
			break;
		//run case, run case, run case, run case, run case, run case, run case, run case, run case, run case, run case, run case, run case, run case
		case 'r':
			if (SmokeCloud) {
				if (rand() % 10 > 8) {
					cout << "The smoke hid your escape!" << endl;
					CanRun = true;
				}
			}
			else if (rand() % 10 > 4) {
				cout << "Your luck holds and you are able to run away successfully!" << endl;
				CanRun = true;
			}
			else {
				cout << "The enemy blocks your way and you cannot run..." << endl;
			}
			break;
		default:
			cout << "Sorry, I don't understand your nonsense" << endl;
		} //end of switch

		//MONSTER ATTACK MONSTER ATTACK MONSTER ATTACK MONSTER ATTACK MONSTER ATTACK MONSTER ATTACK MONSTER ATTACK MONSTER ATTACK
		if (MonsterType == 1) {
			damage = rand() % 20 + 10;
			cout << "The octorock spits a turd and hits your forehead for " << damage << " damage..." << endl;
			PlayerHealth -= damage;
		}
		if (MonsterType == 2) {
			damage = rand() % 5 + 10;
			cout << "The ice demon froze you for " << damage << " damage..." << endl;
			PlayerHealth -= damage;
		}
		if (MonsterType == 3) {
			damage = rand() % 20;
			cout << "The fire bat burned you for " << damage << " damage..." << endl;
			PlayerHealth -= damage;
			if (WeaponsAndArmor[1].compare("Fire Armor") == 0) {
				cout << "Your flame armor absorbs 20 damage!" << endl;
				damage -= 20;
			}
		}
		if (MonsterType == 4) {
			if (rand() % 10 < 5) { //dragon has 2 possible attacks... what?!
				damage = rand() % 80 + 10;
				cout << "The dragon's stinky and firey breath scorches you for " << damage << " damage..." << endl;
				if (WeaponsAndArmor[1].compare("Fire Armor") == 0) {
					cout << "Your flame armor absorbed 20 damage!" << endl;
					damage -= 20;
				}
			}
			else {
				damage = rand() % 50 + 20;
				cout << "The dragon's nails scratch you for " << damage << " damage..." << endl;
			}
			PlayerHealth -= damage;
		}

		if (MonsterHealth <= 0) {
			cout << "The Monster Was Defeated!!!" << endl;
		}
		if (PlayerHealth <= 0) {
			cout << "YOU HAVE DEATHED!!!!!!!!!" << endl;
		}

	} //end of battle loop

} //end of function definition