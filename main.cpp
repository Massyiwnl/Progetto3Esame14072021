#include <iostream>
#include "ListaDL.h"
#include "Studenti.h"
#include "Gruppo.h"

using namespace std;

bool carica(ListDL<Studenti>* lista1, ListDL<Studenti>* lista2, string filename);
void creaGruppi(ListDL<Studenti>* lista1, ListDL<Studenti>* lista2, ListDL<Gruppo>* groupList);
void stampaGruppi(ListDL<Gruppo>* groupList);

void creaGruppi(ListDL<Studenti>* lista1, ListDL<Studenti>* lista2, ListDL<Gruppo>* groupList) {
	NodeDL<Studenti>* current1 = lista1->getHead(); int len1 = lista1->getLength();
	NodeDL<Studenti>* current2 = lista2->getHead();int len2 = lista2->getLength();
	int ids = 0;
	NodeDL<Studenti>* a, * b1, * b2;
	while (len1 && len2) {
		Gruppo temp(ids);
		a = current1;
		if (len2 < 2)break;
		if (len1 < 1)break;
		b1 = current2;
		b2 = current2->getNext();

		if ((b1->getValue() + b2->getValue()) >= 40) {
			temp.insertMember(*b1);
			temp.insertMember(*b2);

			current2 = current2->getNext()->getNext();
			len2 -= 2;

		}
		else {
			temp.insertMember(*a);
			temp.insertMember(*b1);
			temp.insertMember(*b2);
			current1 = current1->getNext();

			current2 = current2->getNext()->getNext();
			len2 -= 2;
			len1--;

		}

		groupList->insertTail(temp);

		ids++;
	}

	Gruppo temp(ids);

	for (int i = 0;i < len1; i++) {
		a = current1;
		current1 = current1->getNext();

		temp.insertMember(*a);
	}

	for (int i = 0;i < len2; i++) {
		a = current2;
		current2 = current2->getNext();
		temp.insertMember(*a);
	}
	groupList->insertTail(temp);

}


void stampaGruppi(ListDL<Gruppo>* groupList) {
	NodeDL<Gruppo>* current = groupList->getHead();
	while (current != NULL) {
		current->getValue().printGroup();

		current = current->getNext();
		cout << endl;

	}
	cout << endl;
}

bool carica(ListDL<Studenti>* lista1, ListDL<Studenti>* lista2, string filename) {
	ifstream ifs(filename, ifstream::in);
	int i = 1;
	while (ifs.good()){
		Studenti s;
		ifs >> s;
		if (s.getMedia() >= 24){
			lista1->insertInOrder(s);
		}
		else{
			lista2->insert(s);
		}
	}
	ifs.close();
	return true;
}

int main(){
	ListDL<Studenti> D;
	ListDL<Studenti> D2;
	ListDL<Gruppo> groupList;

	cout << "Stampo gli studenti con le relative informazioni a riguardo: " << endl;
	cout << endl;
 	carica(&D, &D2, "Studenti.txt");

	cout << D << endl << endl << endl;

	cout << "Studenti con media minore di 24" << endl;
	cout << endl;
	cout << D2 << endl;


	creaGruppi(&D, &D2, &groupList);


	stampaGruppi(&groupList);


	return 0;
}
