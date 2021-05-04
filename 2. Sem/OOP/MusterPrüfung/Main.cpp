#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "Player.h"

using namespace std;

int main() {

	//Seeding rand
	srand((unsigned int)time(NULL));

	//Initializing players
	Player* p1 = new PlayerA("Peco");
	Player* p2 = new PlayerB("Smile");

	//Playing 9 Rounds
	int round = 1;
	while (round < 10) {
		cout << "+++++ ROUND " << round << " +++++\n";

		//Playing until a point is scored
		while (true) {

			if (p1->attack(p2)) //Player one attacks player two
			{
				cout << p1->getName() << " scored.\n";
				break;
			}
			else //If no point was scored, player two attacks player one
				if (p2->attack(p1))
				{
					cout << p2->getName() << " scored.\n";
					break;
				}
		}

		//Preparing next round by resting and changing players
		++round;
		p1->rest();
		p2->rest();
		Player* temp = p1;
		p1 = p2;
		p2 = temp;
	}

	//Printing result
	if (p1->getPoints() > p2->getPoints())
		cout << p1->getName() << " won with " << p1->getPoints() << " points.\n";
	else
		cout << p2->getName() << " won with " << p2->getPoints() << " points.\n";

	//Cleaning up
	delete p1;
	delete p2;
	return 0;
}
