#include "Biblioteka.h"
class Studentas {
private: 
    string vardas;
    string pavarde;
    vector<int>paz;
    int egz;
public:
    Studentas() : egz(0) {};
    //getteriai
    const string& getVardas() const {return vardas;}
    const string& getPavarde() const {return pavarde;}
    const vector <int>& getPaz() const {return paz;}
    int getEgz() const {return egz;}
    //setteriai
    void setVardas(const string& v) {vardas = v;}
    void setPavarde(const string& p) {pavarde=p;}
    void setPaz(const vector<int>& p) {paz=p;}
    void setEgz(int e) {egz = e;}
};