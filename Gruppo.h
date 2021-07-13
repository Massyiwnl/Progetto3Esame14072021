#include <iostream>
#include "ListaDL.h"
#include "Studenti.h"

using namespace std;

class Gruppo {
	int id;
	ListDL<Studenti> memberOfGroup;
	int numberOfMember = 0;

public:
	Gruppo(int ID) :id(ID) {}

	void insertMember(NodeDL<Studenti> s) {
		this->memberOfGroup.insert(s.getValue());
		this->numberOfMember++;

	}

	int getNumberOfMember() {
		return this->numberOfMember;
	}


	void printGroup() {
		cout << "ID Gruppo: " << this->id << " Numero studenti: " << this->numberOfMember << endl;
        NodeDL<Studenti>* current = this->memberOfGroup.getHead();
		double somma = 0;

		while (current != NULL) {
			cout << "Matricola: " << current->getValue().getMatricola() << " Cognome: " << current->getValue().getCognome() << " Media: " << current->getValue().getMedia() << endl;
			somma += current->getValue().getMedia();
			current = current->getNext();
		}

		cout << "Media voti del gruppo: " << somma / this->numberOfMember << endl;

		return;

	}

};
