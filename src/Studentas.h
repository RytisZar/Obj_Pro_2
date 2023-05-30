#include "Biblioteka.h"
class Studentas {
private: 
    string vardas;
    string pavarde;
    vector<int>paz;
    int egz;
public:
    Studentas() : egz(0) {};

    ~Studentas() {} //destruktorius

    Studentas(const Studentas& kitas) //kopijavimo kontruktorius
    : vardas(kitas.vardas), pavarde(kitas.pavarde), paz(kitas.paz), egz(kitas.egz) {}

    //Kopijavimo priskyrimo operatorius
    Studentas& operator=(const Studentas& kitas) {
        if (this != &kitas) {
            vardas = kitas.vardas;
            pavarde = kitas.pavarde;
            paz = kitas.paz;
            egz = kitas.egz;
        }
        return *this;
    }

    //Perkelimo kontruktorius is vieno i kita
    Studentas(Studentas&& kitas)
        : vardas(move(kitas.vardas)), pavarde(move(kitas.pavarde)),
          paz(move(kitas.paz)), egz(move(kitas.egz)) {}

    //Perkelimo priskyrimo operatorius
     Studentas& operator=(Studentas&& kitas) {
        if (this != &kitas) {
            vardas = move(kitas.vardas);
            pavarde = move(kitas.pavarde);
            paz = move(kitas.paz);
            egz = move(kitas.egz);
        }
        return *this;
    }

    //deklaruojamas operatorius "<<" kaip draugiskas "friend"
    friend ostream& operator<<(ostream& os, const Studentas& student);
    friend ostream& operator<<(ostream& os, const vector<Studentas>& students);

    //getteriai
    string getVardas() const {return vardas;}
    string getPavarde() const {return pavarde;}
    vector <int> getPaz() const {return paz;}
    int getEgz() const {return egz;}
    
    //setteriai
    void setVardas(const string& v) {vardas = v;}
    void setPavarde(const string& p) {pavarde=p;}
    void setPaz(const vector<int>& p) {paz=p;}
    void setEgz(int e) {egz = e;}
};
ostream& operator<<(ostream& os, const Studentas& student);
ostream& operator<<(ostream& os, const vector<Studentas>& students);
