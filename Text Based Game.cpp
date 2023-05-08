#include <windows.h>

#include <ctime>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

const int rounds = 10;

bool wrongInput;
string currentName;

class Player
{
	public:
	float health, mana, attack, shield, maxShield, maxHealth, maxMana;
	bool usingShield;
	int points;

	Player(float health, float mana, float attack, float shield, float maxShield, float maxHealth, float maxMana, bool usingShield, int points)
	{
		this->health = health;
		this->mana = mana;
		this->shield = shield;
		this->attack = attack;
		this->maxShield = maxShield;
		this->maxHealth = maxHealth;
		this->maxMana = maxMana;
		this->usingShield = usingShield;
		this->points = points;
	}
};

class Enemy
{
	public:
	float health, attack;
	int points;
	Enemy(float health, float attack, float points)
	{
		this->health = health;
		this->attack = attack;
		this->points = points;
	}
};

Player player(0, 0, 0, 0, 0, 0, 0, false, 0);
Enemy enemy(0, 0, 0);

void isEnemyDead()
{
	if (enemy.health > 0)
	{
		cout << endl << endl << currentName << " is alive and has " << enemy.health << " HP left." << endl << endl;
		Sleep(3000);
	}
	else
	{
		cout << endl << endl << "Congratulations! You killed " << currentName << "!" << endl;
		Sleep(3000);
		cout << "Your Shield is being healed to maximum:" << endl;
		Sleep(2000);
		for (int i = 5; i <= 100; i += 5)
		{
			cout << i << "%" << endl;
			Sleep(501 - (i * 5));
		}
		Sleep(750);
		player.shield = player.maxShield;
		cout << "Done!";
		Sleep(2000);

		cout << endl << endl << "Your Attack Damage is being increased by 10%" << endl;
		Sleep(2000);
		for (int i = 5; i <= 100; i += 5)
		{
			cout << i << "%" << endl;
			Sleep(501 - (i * 5));
		}
		Sleep(750);
		player.attack = player.attack + (player.attack * 0.1);
		cout << "Done!";
		Sleep(2000);
		cout << endl << endl << "Your Health Points are being increased by 10%" << endl;
		Sleep(2000);
		for (int i = 5; i <= 100; i += 5)
		{
			cout << i << "%" << endl;
			Sleep(501 - (i * 5));
		}
		Sleep(750);
		player.health = player.health + (player.maxHealth * 0.1);
		if (player.health > player.maxHealth)
			player.health = player.maxHealth;
		cout << "Done!";
		Sleep(2000);

		cout << endl << endl << "Your Mana is also being increased by 10%" << endl;
		Sleep(2000);
		for (int i = 5; i <= 100; i += 5)
		{
			cout << i << "%" << endl;
			Sleep(501 - (i * 5));
		}
		Sleep(750);
		player.mana = player.mana + (player.maxMana * 0.1);
		if (player.mana > player.maxMana)
			player.mana = player.maxMana;
		cout << "Done!";
		Sleep(2000);

		cout << endl << endl << "Your Stats now are: " << endl;
		Sleep(500);
		cout << "attack: " << player.attack << " Dmg" << endl;
		Sleep(500);
		cout << "Health: " << player.health << "/" << player.maxHealth << " HP" << endl;
		Sleep(500);
		cout << "Shield: " << player.shield << " HP" << endl;
		Sleep(500);
		cout << "Mana: " << player.mana << "/" << player.maxMana << " M" << endl << endl;
		Sleep(1000);

		cout << "Press any key to start the next Battle..." << endl << endl;
		system("pause");
	}
}

void playerAttack()
{
	cout << "You have 3 attack choices:" << endl;
	Sleep(500);
	cout << "1. pepper Spray (P: -5M) (E: -" << player.attack * 0.20 << ")" << endl;
	Sleep(500);
	cout << "2. Sword (P: -15M) (E: -" << player.attack << ")" << endl;
	Sleep(500);
	cout << "3. Punch the earth so hard that you create a huge crack on the surface and " << currentName << " dies from fall damage(P: -125M) (E:DEAD)" << endl << endl;

	do
	{
		wrongInput = false;
		cout << "What will your next move be? 1, 2 or 3? ";
		int attackChoice;
		cin >> attackChoice;
		if (attackChoice == 1)
		{
			player.mana -= 5;
			enemy.health = enemy.health - (player.attack * 0.20);
		}
		else if (attackChoice == 2)
		{
			if (player.mana < 15)
			{
				cout << "You cannot execute this attack... Try pepper Spray... XD" << endl;
				wrongInput = true;
				continue;
			}
			player.mana -= 15;
			enemy.health -= player.attack;
		}
		else if (attackChoice == 3)
		{
			if (player.mana <= 150)
			{
				cout << "You cannot execute this attack... Try another one" << endl;
				wrongInput = true;
				continue;
			}
			else
			{
				player.mana -= 150;
				enemy.health = 0;
			}
		}
		else
		{
			cout << "Wrong input... Try again." << endl << endl;
			wrongInput = true;
		}
	} while (wrongInput);
	isEnemyDead();
}

void playerHeal()
{
	cout << "You are getting healed by 30%" << endl;
	Sleep(2000);
	for (int i = 5; i <= 100; i += 5)
	{
		cout << i << "%" << endl;
		Sleep(501 - (i * 5));
	}
	Sleep(1000);
	player.health = player.health + (player.maxHealth * 0.30);
	if (player.health > player.maxHealth)
		player.health = player.maxHealth;
	cout << "Done! You now have " << player.health << " Health Points" << endl << endl;
	Sleep(2000);

	cout << "Your mana is getting increased by 20%" << endl;
	Sleep(2000);
	for (int i = 5; i <= 100; i += 5)
	{
		cout << i << "%" << endl;
		Sleep(501 - (i * 5));
	}
	Sleep(1000);
	player.mana = player.mana + (player.maxMana * 0.20);
	if (player.mana > player.maxMana)
		player.mana = player.maxMana;
	cout << "Done! You now have " << player.mana << " M" << endl << endl;
	Sleep(2000);
}

void useShield()
{
	player.mana = player.mana - 10;
	player.usingShield = true;
	cout << "You are now using a shield which will protect you from " << currentName << "'s attack" << endl << endl;
}

void enemyAttack()
{
	srand(time(0));
	cout << currentName << ": My turn." << endl;
	Sleep(2000);

	if (player.usingShield)
	{
		if (player.shield > enemy.attack)
		{
			player.shield -= enemy.attack;
			cout << currentName << " dealt " << enemy.attack << " damage on the shield and didn't affect your health" << endl;
			Sleep(1000);
			if (player.health != player.maxHealth)
			{  // if player's health is already max, we don't want the shield to heal him.
				player.health = player.health + (player.maxHealth * 0.10);
				if (player.health > player.maxHealth)
					player.health = player.maxHealth;

				cout << "while using the shield you managed to heal by 10%! You now have " << player.health << "/" << player.maxHealth << " HP" << endl;
			}
			cout << "Your shield has " << player.shield << " HP left." << endl << endl;
		}
		else
		{
			if (player.shield == enemy.attack)

				cout << "Unfortunately, your shield couldn't protect you completely and broke" << endl;
			else
				cout << "Unfortunately, your shield couldn't protect you completely and broke, though you only lost" << player.shield - enemy.attack << " HP." << endl;

			Sleep(2000);
			player.health -= player.shield - enemy.attack;
			player.shield = 0;

			if (player.health > 0)
				cout << "You have " << player.health << " HP left. ";

			player.health = player.health + (player.maxHealth * 0.10);
			cout << "Good news is while using the shield you managed to heal by 10%! You now have " << player.health << "/" << player.maxHealth << " HP" << endl;
		}

		if (player.health > 0)
		{
			int deflectEnemyDamage = rand() % 5;
			if (deflectEnemyDamage == 1)
			{
				cout << "You are lucky and your shield deflected " << currentName << "'s attack and you dealt " << enemy.attack * 0.50 << " damage" << endl;
				enemy.health = enemy.health - (enemy.attack * 0.50);
				isEnemyDead();
			}
		}

		player.usingShield = false;
	}
	else
	{
		cout << "You didn't use shield, so " << currentName << " dealt " << enemy.attack << " damage directly to your health" << endl;
		player.health = player.health - enemy.attack;

		if (player.health > 0)
			cout << "You have " << player.health << " HP left" << endl;
	}
}

int main()
{
	srand(time(0));

	ifstream textFile("names.txt");  // declaring which file textFile will open

	int difficulty, points;

	cout << "Welcome to my Text Based Game!" << endl;

	do
	{
		wrongInput = false;
		cout << "Select difficulty:" << endl << "1. Easy" << endl;
		Sleep(500);
		cout << "2. Medium" << endl;
		Sleep(500);
		cout << "3. Hard" << endl;
		Sleep(500);
		cout << "4. random" << endl;

		cin >> difficulty;

		switch (difficulty)
		{
			case 1:
				player.points = 800;
				enemy.points = 200;
				break;

			case 2:
				player.points = 600;
				enemy.points = 200;
				break;

			case 3:
				player.points = 500;
				enemy.points = 300;
				break;

			case 4:
				player.points = rand() % 400 + 200;  // from 200 to 600
				enemy.points = rand() % 400 + 200;
				break;
			default:
				wrongInput = true;
				break;
		}
	} while (wrongInput);

	points = player.points;
	cout << "You have " << points << " Points to spend on Health, Mana, Shield and Attack.  Enter 0 to spread equally" << endl;
	Sleep(2000);
	cout << "Choose wisely : " << endl << endl;

	do
	{
		player.health = 0;
		cout << "1. Health: ";
		cin >> player.health;

		if (player.health == 0)
		{
			player.health = points / 4;
			points -= player.health;
			cout << "You have " << points << " points left" << endl << endl;
		}
		else
		{
			if (player.health >= points)
				cout << "You can't use more than or equal to" << points << " points" << endl << "Try Again..." << endl << endl;
			else
			{
				points -= player.health;
				cout << "You have " << points << " points left" << endl << endl;
			}
		}
	} while (player.health >= points);

	do
	{
		player.mana = 0;
		cout << "2. Mana: ";
		cin >> player.mana;

		if (player.mana == 0)
		{
			player.mana = points / 3;
			points -= player.mana;
			cout << "You have " << points << " points left" << endl << endl;
		}
		else
		{

			if (player.mana >= points)
				cout << "You can't use more than or equal to" << points << " points" << endl << "Try Again..." << endl << endl;
			else
			{
				points -= player.mana;
				cout << "You have " << points << " points left" << endl << endl;
			}
		}
	} while (player.mana >= points);

	do
	{
		wrongInput = false;
		player.attack = 0;
		cout << "3. Attack: ";
		cin >> player.attack;

		if (player.attack == 0)
		{
			player.attack = points / 2;
			points -= player.attack;
			cout << "There are " << points << " Points left which will be used for your shield." << endl << endl;
			player.shield = points;
		}
		else
		{
			if (player.attack >= points)
			{
				cout << "You can't use more than or equal to " << points << " points" << endl << "Try Again..." << endl << endl;
				wrongInput = true;
			}
			else
			{
				points -= player.attack;
				cout << "There are " << points << " Points left which will be used for your shield." << endl << endl;
				player.shield = points;
			}
		}
	} while (wrongInput);

	cout << "Your choices:" << endl << "1. Health: " << player.health << endl << "2. Mana: " << player.mana << endl << "3. Attack: " << player.attack << endl << "4. shield: " << player.shield << endl << endl;

	player.maxShield = player.shield;
	player.maxHealth = player.health;
	player.maxMana = player.mana;

	int moveInput;

	for (int i = 1; i < rounds; i++)
	{
		ifstream textFile("text.txt");
		int randomNumber = (rand() % 400);
		for (int i = 0; i <= randomNumber; i++)
		{
			getline(textFile, currentName);
		}
		textFile.close();

		// initialising enemy's variables.
		enemy.health = (rand() % enemy.points / 2 + enemy.points / 4); // the lowest it can go is 1/4 of the total points and the highest it can go is 3/4 of the total points so that either health or attack won't use way too many points leaving almost nothing for the other
		enemy.attack = enemy.points - enemy.health;

		enemy.points += 50;

		cout << endl << endl << "Starting round " << i << endl;
		if (i == 1)
		{
			cout << "Your first enemy is " << currentName << endl;
			Sleep(3000);
		}
		else
		{
			cout << "Your next enemy is " << currentName << endl;
			Sleep(3000);
		}
		cout << currentName << " has " << enemy.health << " hp and " << enemy.attack << " attack damage" << endl;
		Sleep(500);
		cout << "Good Luck!" << endl;
		Sleep(2000);

		cout << "What do you do?" << endl;
		Sleep(500);
		cout << "1. attack (Basic attack: " << player.attack << " Dmg M:-5, -15, -150)" << endl;
		Sleep(500);
		cout << "2. heal (Gain " << player.maxHealth * 0.30 << " HP & " << player.maxMana * 0.20 << " M)" << endl;
		Sleep(500);
		if (player.shield > 0)
			cout << "3. Use shield (Absorb " << player.shield << " Dmg + " << player.maxHealth * 0.10 << " HP + chance of deflecting enemy's attack M:-10)" << endl << endl;
		else
			cout << "3. Can't use shield as it's broken." << endl << endl;

		do
		{
			wrongInput = false;
			cin >> moveInput;
			if (moveInput == 1)
				playerAttack();

			else if (moveInput == 2)
				playerHeal();

			else if (moveInput == 3 && player.shield > 0)
				useShield();

			else
			{
				cout << "Wrong input. Try again..." << endl << endl;
				wrongInput = true;
			}
		} while (wrongInput);

		if (enemy.health > 0)
			enemyAttack();

		if (player.health <= 0)
		{
			cout << "You died from " << currentName << endl;
			Sleep(1000);
			cout << ":( Too bad." << endl;
			Sleep(1000);
			cout << "Anyway.Your journey ends here...";
			Sleep(1000);
			cout << "Bye!";
			return 0;
		}
		if (player.mana <= 5)
		{  // if mana is below 5
			cout << "You are out of Mana! I am afraid you cannot continue to the next level and have to retreat as you can't execute another move." << endl;
			Sleep(1000);
			cout << "Thanks for Playing!" << endl;
			Sleep(1000);
			cout << "Bye!";
			return 0;
		}
	}
}
