#include "server.h"

server::server() {

	lifePoints = 100;
	zonenArray = { {"Zone1", 20, 0}, {"Zone2", 20, 0}, {"Zone3", 20, 0}, {"Zone4", 20, 0}, {"Zone5", 20, 0} };
}

server::~server() {


}

void server::lifePointsMinusOne() {

	lifePoints -= 1;
}

int server::getLifePoints() {

	return this->lifePoints;
}

int server::getZoneDefPoints(int whichZone) {

	return zonenArray[whichZone].defensePoints;
}

int server::getZonePressureVal(int whichZone) {


	return zonenArray[whichZone].pressureValue;
}

void server::pressureValSetZero(int whichZone) {


	zonenArray[whichZone].pressureValue = 0;
}

void server::give3DefPoints(int whichZone) {

	zonenArray[whichZone].defensePoints += 3;
}

void server::incPressureVal(int whichZone) {

	zonenArray[whichZone].pressureValue += 1;
}
