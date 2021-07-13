#ifndef STUDENTI_H_INCLUDED
#define STUDENTI_H_INCLUDED

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Studenti {
	string Matricola, Cognome, Nome, cittaResidenza;
	double Media;

public:
	Studenti(string _m, string _c, string _n, string _cr, double _md) :Matricola(_m), Cognome(_c), Nome(_n), cittaResidenza(_cr), Media(_md) {}
	Studenti() :Studenti(" ", " ", " ", " ", 0.0) {}

	string getMatricola() { return this->Matricola; }
	string getCognome() { return this->Cognome; }
	string getNome() { return this->Nome; }
	string getcittaResidenza() { return this->cittaResidenza; }
	double getMedia() { return this->Media; }

	friend istream& operator>>(istream& in, Studenti& s) {
		string mediaString;
		getline(in, s.Matricola, ';');
		getline(in, s.Cognome, ';');
		getline(in, s.Nome, ';');
		getline(in, s.cittaResidenza, ';');
		getline(in, mediaString, '\n');
		s.Media = stod(mediaString);
		return in;
	}

	friend ostream& operator<<(ostream& out, const Studenti& s) {
		out << "Matricola: " << s.Matricola << "; Cognome: " << s.Cognome << "; Nome: " << s.Nome << "; Citta' di Residenza: " << s.cittaResidenza << "; Media: " << s.Media << endl;
		return out;
	}

	bool operator>(const Studenti& s)const {
		return this->Media > s.Media;
	}
	bool operator<(const Studenti& s)const {
		return this->Media < s.Media;
	}
	bool operator>=(const Studenti& s)const {
		return this->Media >= s.Media;
	}

	bool operator==(const Studenti& s)const {
		return this->Media == s.Media;
	}

	bool operator<=(const Studenti& s)const {
		return this->Media <= s.Media;
	}

	int operator+(const Studenti& s) {
		return s.Media + this->getMedia();
	}
};

#endif // STUDENTI_H_INCLUDED

