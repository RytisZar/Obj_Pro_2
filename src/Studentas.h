class Zmogus {
protected:
    string vardas;
    string pavarde;

public:
    Zmogus() {}
    Zmogus(const string& v, const string& p)
        : vardas(v), pavarde(p) {}

    virtual ~Zmogus() {}
    virtual void printInfo() const = 0;
};

class Studentas : public Zmogus {
private:
    vector<int> paz;
    int egz;

public:
    Studentas() : Zmogus(), egz(0) {}
    Studentas(const string& v, const string& p, const vector<int>& pa, int e)
        : Zmogus(v, p), paz(pa), egz(e) {}

    //Kopijavimo konstruktorius
    Studentas(const Studentas& kitas)
        : Zmogus(kitas), paz(kitas.paz), egz(kitas.egz) {}

    //Kopijavimo priskyrimo operatorius
    Studentas& operator=(const Studentas& kitas) {
        if (this != &kitas) {
            Zmogus::operator=(kitas); //Kviciama bazine zmogus klase
            paz = kitas.paz;
            egz = kitas.egz;
        }
        return *this;
    }

    // Perkelimo kontruktorius
    Studentas(Studentas&& kitas)
        : Zmogus(move(kitas)), paz(move(kitas.paz)), egz(move(kitas.egz)) {}

    // Perkelimo operatorius
    Studentas& operator=(Studentas&& kitas) {
        if (this != &kitas) {
            Zmogus::operator=(move(kitas));
            paz = move(kitas.paz);
            egz = move(kitas.egz);
        }
        return *this;
    }

     //deklaruojamas operatorius "<<" kaip draugiskas "friend"
    friend ostream& operator<<(ostream& os, const Studentas& student);
    friend ostream& operator<<(ostream& os, const vector<Studentas>& students);

    // Getteriai
    string getVardas() const { return vardas; }
    string getPavarde() const { return pavarde; }
    vector<int> getPaz() const { return paz; }
    int getEgz() const { return egz; }

    // Setteriai
    void setVardas(const string& v) { vardas = v; }
    void setPavarde(const string& p) { pavarde = p; }
    void setPaz(const vector<int>& p) { paz = p; }
    void setEgz(int e) { egz = e; }

    void printInfo() const override {
        cout << "Vardas: " << vardas << endl;
        cout << "Pavarde: " << pavarde << endl;
        cout << "Pazymiai: ";
        for (const auto& pazy : paz) {
            cout << pazy << " ";
        }
        cout << endl;
        cout << "Egzaminas: " << egz << endl;
    }
};
ostream& operator<<(ostream& os, const Studentas& student);
ostream& operator<<(ostream& os, const vector<Studentas>& students);