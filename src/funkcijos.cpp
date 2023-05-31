#include "funkciju_bib.h"

void pildymas(Studentas& studentai) {
    try { //Exceptional handling panaudojimas
        string vardas, pavarde;
        cout << "Iveskite varda ir pavarde: ";
        cin >> vardas >> pavarde;
        studentai.setVardas(vardas);
        studentai.setPavarde(pavarde);
        cout << "Pasirinkite kaip ivesite pazymius: " << endl;
        cout << "1. Ranka " << endl;
        cout << "2. Atsitiktinai sugeneruoti " << endl;
        cout << "Iveskite skaiciu: ";
        int pasirinkimas;
        while (cin >> pasirinkimas) {
            if (pasirinkimas != 1 && pasirinkimas != 2) {
                cout << "Pasirinkite 1 arba 2: ";
                continue;
            }
            break;
        }
        if (pasirinkimas == 1) {
            vector<int>pazy;
            int pazymys;
            cout << "Iveskite pazymius (baigti su bet kuriuo kita mygtuku): ";
            while (cin >> pazymys) {
                if (pazymys < 1 || pazymys > 10) {
                    cout << "Ivestas pazymys turi buti nuo 1 iki 10. Veskite is naujo" << endl;
                    continue;
                }
                pazy.push_back(pazymys);
            }
            studentai.setPaz(pazy);
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            int egza;
            cout << "Iveskite egzamino pazymi (nuo 1 iki 10): ";
            while (cin >> egza) {
                if (!cin.fail() && egza >= 1 && egza <= 10) {
                    studentai.setEgz(egza);
                    break;
                }
                else {
                    cout << "Neteisingas pazymys. Iveskite skaiciu nuo 1 iki 10: ";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
            }
        }
        else if (pasirinkimas == 2) {
            vector<int>pazy;
            int egza;
            pazy.resize(5); // Pasirinkti skaiciu kieki, kurie bus randomizuojami
            unsigned seed = chrono::system_clock::now().time_since_epoch().count();
            default_random_engine generator(seed);
            uniform_int_distribution<int> distribution(1, 10); // Nuo kiek iki kiek generuojami skaiciai
            for (int i = 0; i < pazy.size(); i++) {
                pazy[i] = distribution(generator);
                cout << "Atsitiktinai sugeneruotas pazymys: " << pazy[i] << endl; //parodoma sugeneruoti pazymiai ND
            }
            studentai.setPaz(pazy);
            egza = distribution(generator);
            cout << "Atsitiktinai sugeneruotas egzamino pazymys: " << egza << endl;
            studentai.setEgz(egza);
        }
        else {
            throw runtime_error("Neteisingas pasirinkimas. Pasirinkite 1 arba 2."); //Exceptional handling, jei buvo blogai pasirinktas ivediniejimo budas
        }
    }
    catch (const exception& e) {
        throw runtime_error("Klaida vykdant pildyma"); // Exeptional handling, jei nebuvo gerai ivykdytas pildymas
    }
}
double pazymiu_vidurkis(const vector<int>& paz) {
    double sum = 0;
    for (const auto& pazymys : paz) {
        sum += pazymys;
    }
    return sum/ static_cast<double>(paz.size());
}
double pazymiu_mediana(const vector<int>&pazymiai) {
    vector<int> sorted_pazymiai = pazymiai; 
    sort(sorted_pazymiai.begin(), sorted_pazymiai.end()); 
    int dydis = sorted_pazymiai.size();
    if (dydis % 2 == 0) {
        return (sorted_pazymiai[dydis / 2 - 1] + sorted_pazymiai[dydis / 2]) / 2.0;
    }
    else {
        return sorted_pazymiai[dydis / 2];
    }
}
double galBalas (double skaicius_1, int skaicius_2) {
    return static_cast<double>(skaicius_1*0.4+skaicius_2*0.6);
}
void skaitymas_is_failo(vector <Studentas>& studentai, const std::string & file_name) {
    ifstream infile(file_name);
    if (!infile.is_open()) {
        cout<< "Npeavyko atidaryti failo."<<endl;
        return;
        //Galimas panaudojimas throw 
        //throw runtime_error("Nepavyko atidaryti failo");
    }
    string vardas, pavarde;
    string line;
    getline(infile, line);//praleidziama pati pirma eilute file_name
    while (getline(infile, line)) 
    {
        vector<int>pazy;
        int egza;
        Studentas temp;
        stringstream ss(line);
        ss>>vardas>>pavarde;
        temp.setVardas(vardas);
        temp.setPavarde(pavarde);
        int pazymys;
        while (ss>>pazymys) {
            pazy.push_back(pazymys);
        }
        temp.setPaz(pazy);
        egza=pazy.back();//perskaitomas paskutinis pazymys
        pazy.pop_back();//panaikinamas paskutinis pazymys is paz
        temp.setEgz(egza);
        studentai.push_back(temp);
    }
}
void isvedimas(const vector<Studentas>& studentai) {
    cout << "Vardas    Pavarde     Galutinis (Vid.) / Galutinis (Med.)" << endl;
    cout << "---------------------------------------------------------" << endl;
    for (const Studentas& temp : studentai) {
        cout << temp.getVardas() << setw(14) <<
            temp.getPavarde()<< setw(7) << fixed << setprecision(2) <<
            galBalas(pazymiu_vidurkis(temp.getPaz()), temp.getEgz()) << setw(19) << fixed <<
            setprecision(2) << galBalas(pazymiu_mediana(temp.getPaz()), temp.getEgz()) << endl;
    }
}
vector<Studentas> ivedimas() {
    const int MAXAS = 100;//reguliuoti kiek galima ivesti studentu
    vector<Studentas> studentai;
    string input;
    while (true) {
        Studentas temp;
        pildymas(temp);
        studentai.push_back(temp);
        cout << "Irasykite 't' jei daugiau nenoresite nieko vesti, arba paspauskite bet kuri kita mygtuka, kad butu galima toliau vesti: ";
        cin >> input;
        if (input == "t" || studentai.size() == MAXAS) {
            break;
        }
    }
    return studentai;
}
void sukurimas_random_failo(const std::string&failo_pav, int studentu_skaicius) {
    ofstream outfile(failo_pav);
    if (!outfile.is_open()) {
        std::cout<<"Nepavyko sukurti failo."<<endl;
    }
    outfile << "Pavarde Vardas";
    for (int i=1; i<=10; i++) {
        outfile <<" ND"<<i;
    }
    outfile<<"Egz.\n";
    unsigned seed = chrono::system_clock::now().time_since_epoch().count();
    default_random_engine generator(seed);
    uniform_int_distribution<int> distribution(1, 10);
    for (int i=1; i<=studentu_skaicius; i++) {
        outfile <<"Pavarde"<<i<<" Vardas"<<i;
        for (int j=0; j<10; j++) {
            outfile<< " " <<distribution(generator);
        }
        outfile << " " <<distribution(generator) <<"\n";
    }
    outfile.close();
}
bool studentuPalyginimas(const Studentas& s1, const Studentas& s2) { //galutiniu balu su mediana palyginimas
    double balas1 = galBalas(pazymiu_mediana(s1.getPaz()), s1.getEgz());
    double balas2 = galBalas(pazymiu_mediana(s2.getPaz()), s2.getEgz());
    return balas1 < balas2;
}
void spausdintiStudentus(const vector<Studentas>& studentai, ofstream& outfile) {
    outfile << "Vardas    Pavarde     Galutinis (Vid.) / Galutinis (Med.)" << endl;
    outfile << "---------------------------------------------------------" << endl;
    for (const Studentas& temp : studentai) {
        outfile << temp.getVardas() << setw(14) <<
            temp.getPavarde() << setw(7) << fixed << setprecision(2) <<
            galBalas(pazymiu_vidurkis(temp.getPaz()), temp.getEgz()) << setw(19) << fixed <<
            setprecision(2) << galBalas(pazymiu_mediana(temp.getPaz()), temp.getEgz()) << endl;
    }
}
bool palygintiStudentus(const Studentas& student1, const Studentas& student2) { //palyginimas pagal varda, jei tokie patys - pagal pavarde
    if (student1.getVardas() == student2.getVardas()) {
        return student1.getPavarde() < student2.getPavarde();
    }
    return student1.getVardas() < student2.getVardas();
}

void rusiavimasStudentu(vector<Studentas>& studentai) { //rusiavimas alfabetiskai
    sort(studentai.begin(), studentai.end(), palygintiStudentus); 
}

bool yraVargsiukas(const Studentas& temp) { //patikrinimas ar yra vargsiukas studentas
    return galBalas(pazymiu_mediana(temp.getPaz()), temp.getEgz()) < 5;
}

void dalintiStudentus(vector<Studentas>& studentai, vector<Studentas>& vargsiukai) { //2 strategijos realizavimas
    auto it = remove_if(studentai.begin(), studentai.end(), yraVargsiukas); //panaudojama remove_if funkcija
    vargsiukai.insert(vargsiukai.end(), it, studentai.end()); //vargsiuku ikelimas i konteineri
    studentai.erase(it, studentai.end()); //vargsiuku panaikinimas is bendro studentu konteinerio, paliekami tik kietiakai
}

void rusiuotiStudentus(vector<Studentas>& studentai) {
  
    vector<Studentas> vargsiukai;

    auto start = chrono::high_resolution_clock::now();
    dalintiStudentus(studentai, vargsiukai);
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::milliseconds>(end - start).count();
    cout << "Irasu dalijimo i dvi grupes laikas uztruko: " << duration << " milisekundziu" << endl;

    sort(studentai.begin(), studentai.end(), studentuPalyginimas); //pagal mediana rusiavimas studentu konteinerio
    sort(vargsiukai.begin(), vargsiukai.end(), studentuPalyginimas); //pagal mediana rusiavimas vargsiuku konteinerio

    ofstream outfile_daugiau("Kietiakai.txt");
    if (!outfile_daugiau.is_open()) {
        cout << "Nepavyko atidaryti kietiako failo." << endl;
        return;
    }
    spausdintiStudentus(studentai, outfile_daugiau);
    outfile_daugiau.close();

    ofstream outfile_maziau("Vargsiukai.txt");
    spausdintiStudentus(vargsiukai, outfile_maziau);
    if (!outfile_maziau.is_open()) {
        cout << "Nepavyko atidaryti vargsiuku failo." << endl;
        return;
    }
    outfile_maziau.close();
}
ostream& operator<<(ostream& os, const Studentas& student) {
    os << "Vardas: " << student.vardas << ", pavarde: " << student.pavarde << ", pazymiai: ";
    for (size_t i = 0; i < student.paz.size(); ++i) {
        os << student.paz[i];
        if (i != student.paz.size() - 1) {
            os << ", ";
        }
    }
    
    os << ", egzaminas: " << student.egz;
    return os;
}

// Overloadinta funkcija
ostream& operator<<(ostream& os, const vector<Studentas>& students) {
    for (const auto& student : students) {
        os << student << endl;
    }
    return os;
}
