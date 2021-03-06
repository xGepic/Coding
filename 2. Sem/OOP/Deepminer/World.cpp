#include "World.h"

World::World() {

	sizeX = 5;
	sizeY = 5;
	sizeZ = 10;

	generate();
}

World::~World() {


}

void World::generate() {

	for (int i = 0; i < sizeX; i++) {
		for (int j = 0; j < sizeY; j++) {
			for (int k = 0; k < sizeZ; k++) {

				worldArray[i][j][k] = rand() % 9 + 1;
			}
		}
	}
}

void World::getMenu() {

	cout << "--| DeepMiner 1.0 by Stefan Simanek |--" << endl << endl;
	cout << "Compete against the computer and collect more points from the world than it does!" << endl << endl;
	cout << "BOT 1 | Mines the Highest Value it can find" << endl;
	cout << "BOT 2 | Mines the value of its coordinates as well as the next two values below" << endl;
	cout << "BOT 3 | Mines the deepest 2 Values from the Bottom of the World" << endl;
	cout << "___________________________________" << endl << endl;
}

void World::beginMenu() {

	cout << "Let the Game begin!" << endl;
	cout << "___________________" << endl << endl;
	printWorld();
}

void World::errorMsg() {

	cout << endl;
	cout << "[Error] That is not possible!" << endl;
}

void World::whichPlain() {

	int k = 0;

	while (true) {

		cout << "Which Plain would your like to Print? ";
		cin >> k;
		cout << endl;

		if ((k < 0) || (k > 9)) {

			cout << "[ERROR] The World only has 10 Plains! (0-9)" << endl << endl << endl;
		}
		else {
			printLayer(k);
		}
	}
}

void World::printLayer(int k) {

	cout << endl << endl << "Here is Layer Number " << k << ":" << endl;

	for (int i = 0; i < sizeX; i++) {

		for (int j = 0; j < sizeY; j++) {

			if (worldArray[i][j][k] == 88) {

				cout << "X" << " ";
			}
			else if (worldArray[i][j][k] == 89) {

				cout << "Y" << " ";
			}
			else {

				cout << worldArray[i][j][k] << " ";
			}
		}
		cout << endl;
	}
}

void World::printWorld() {

	int n = 0;

	cout << endl << "Here is your World!" << endl << endl;

	while (n < 10) {

		cout << "Layer " << n << ": " << endl;
		for (int i = 0; i < sizeX; i++) {

			for (int j = 0; j < sizeY; j++) {

				cout << worldArray[i][j][n] << " ";
			}
			cout << endl;
		}
		cout << endl;
		n++;
	}
}

void World::printStats(Bot* B, int n) {

	if (n == 0) {

		cout << "[SCORE] Player 1: " << B->getScore() << " Points" << endl;
	}
	else {

		cout << "[SCORE] Robot:    " << B->getScore() << " Points" << endl;
	}
}

Bot* World::chooseBot() {

	int temp;

	while (true) {

		cout << "Choose A Robot! | BotOne(1) - BotTwo(2) - BotThree(3)";
		cin >> temp;

		if ((temp < 1) || (temp > 3)) {

			cout << endl << "Error!" << endl << endl;
		}
		else {

			if (temp == 1) {

				cout << endl << "Player 1 chose the BotOne!" << endl << endl << endl;
				return new BotOne();
			}
			if (temp == 2) {

				cout << endl << "Player 1 chose the BotTwo!" << endl << endl << endl;
				return new BotTwo();
			}
			if (temp == 3) {

				cout << endl << "Player 1 chose the BotThree!" << endl << endl << endl;
				return new BotThree();
			}
		}
	}
}


void World::setPositionPlayer(Bot* B) {

	worldArray[B->getxPlayerPos()][B->getyPlayerPos()][B->getzValue()] = 'X';
}

void World::chooseMovePlayer(Bot* B) {

	char move;
	vector<int> temp;

	while (true) {

		cout << endl << "Where would you like to go?";
		cin >> move;

		if ((move != 'w') && (move != 'a') && (move != 's') && (move != 'd')) {

			errorMsg();
		}
		else {

			break;
		}
	}

	if (move == 'w') {

		if (B->getxPlayerPos() - 1 < 0) {

			errorMsg();
			return;
		}
		for (int j = 9; j > 0; j--) {

			worldArray[B->getxPlayerPos()][B->getyPlayerPos()][j] = 0;
		}
		B->setxPlayerPos(-1);
		system("CLS");
		setPositionPlayer(B);
		for (int i = 9; i > 0; i--) {

			temp.push_back(worldArray[B->getxPlayerPos()][B->getyPlayerPos()][i]);
		}
		B->mine(temp);
	}
	if (move == 'a') {

		if (B->getyPlayerPos() - 1 < 0) {

			errorMsg();
			return;
		}
		for (int j = 9; j > 0; j--) {

			worldArray[B->getxPlayerPos()][B->getyPlayerPos()][j] = 0;
		}
		B->setyPlayerPos(-1);
		system("CLS");
		setPositionPlayer(B);
		for (int i = 9; i > 0; i--) {

			temp.push_back(worldArray[B->getxPlayerPos()][B->getyPlayerPos()][i]);
		}
		B->mine(temp);
	}
	if (move == 's') {

		if (B->getxPlayerPos() + 1 > 4) {

			errorMsg();
			return;
		}
		for (int j = 9; j > 0; j--) {

			worldArray[B->getxPlayerPos()][B->getyPlayerPos()][j] = 0;
		}
		B->setxPlayerPos(1);
		system("CLS");
		setPositionPlayer(B);
		for (int i = 9; i > 0; i--) {

			temp.push_back(worldArray[B->getxPlayerPos()][B->getyPlayerPos()][i]);
		}
		B->mine(temp);
	}
	if (move == 'd') {

		if (B->getyPlayerPos() + 1 > 4) {

			errorMsg();
			return;
		}
		for (int j = 9; j > 0; j--) {

			worldArray[B->getxPlayerPos()][B->getyPlayerPos()][j] = 0;
		}
		B->setyPlayerPos(1);
		system("CLS");
		setPositionPlayer(B);
		for (int i = 9; i > 0; i--) {

			temp.push_back(worldArray[B->getxPlayerPos()][B->getyPlayerPos()][i]);
		}
		B->mine(temp);
	}
}

void World::startGame(Bot* Player1, Bot* Robot) {

	int temp = 1;
	int gameover = 1;
	int gen = 50;

	cout << "Loading...";
	this_thread::sleep_for(chrono::seconds(3));
	system("CLS");

	beginMenu();
	setPositionPlayer(Player1);
	setPositionRobot(Robot);

	while (true) {

		printStats(Player1, 0);
		printStats(Robot, 1);
		printLayer(9);

		chooseMovePlayer(Player1);
		if ((Player1->getScore() - gen) > 0) {

			generate();
			setPositionPlayer(Player1);
			setPositionRobot(Robot);
			gen += 50;
		}
		gameover = gameOver(Player1->getScore(), 1);
		if (gameover == 0) {

			break;
		}

		chooseMoveRobot(Robot);
		if ((Robot->getScore() - gen) > 0) {

			generate();
			setPositionPlayer(Player1);
			setPositionRobot(Robot);
			gen += 50;
		}
		gameover = gameOver(Robot->getScore(), 2);
		if (gameover == 0) {

			break;
		}
	}
}

int World::gameOver(int points, int player) {

	if (points >= 200) {

		cout << "Game Over !" << endl;

		if (player == 1) {
			
			cout << "Player 1 won!" << endl;
			return 0;
		}
		if (player == 2) {

			cout << "The Robot won!" << endl;
			return 0;
		}
		else {

			return 1;
		}
	}
	else {

		return 1;
	}
}
