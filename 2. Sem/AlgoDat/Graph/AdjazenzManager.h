#ifndef ADJAZENZMANAGER_H
#define ADJAZENZMANAGER_H
#include "AdjazenzListe.h"

class AdjazenzManager {

public:
	AdjazenzManager();
	virtual ~AdjazenzManager();

	// den graphen aus dem file auslesen und AdjazenzList erstellen
	bool readFile(string fileName);
	// alle knoten und zugeh�rige nachbarn
	void printAdjazentListe();
	// 
	void shortestPath(string start, string finish);
	// dijstra algorithmus f�r den k�rzesten pfad von start aus, rechnet gesamte tabelle aus
	void dijkstra(string start, string finish);
	// printet den k�rzesten pfad mit allen infos, wird in dijkstra noch aufgerufen mit dessen ergebnissen
	void print_path(string start, string finish, string alleStationen[], string vorgaenger[], string gefahren_mit);
	// gibt den index aus einem array der l�nge anzahlStationen zur�ck, wo sie die station befindet
	int getIndexAt(string warteschlange[], string station);
	// ob es die station in der adjazent lsite gibt oder nicht
	bool existsInList(string station);

protected:


private:
	AdjazenzListe* root;
	// Anzahl an Stationen in root
	int anzahlStationen;
};

#endif // ADJAZENZMANAGER_H