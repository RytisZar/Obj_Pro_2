#include "Biblioteka.h"
#include "Studentas.h"
void pildymas(Studentas &studentai);
double pazymiu_vidurkis(const vector<int>& paz);
double pazymiu_mediana(const vector<int>&pazymiai);
double galBalas (double skaicius_1, int skaicius_2);
void skaitymas_is_failo(vector <Studentas>& studentai, const std::string & file_name);
void isvedimas(const vector<Studentas>& studentai);
vector<Studentas> ivedimas();
bool palygintiStudentus(const Studentas& student1, const Studentas& student2);
void rusiavimasStudentu(vector<Studentas>& studentai);
void sukurimas_random_failo(const std::string&failo_pav, int studentu_skaicius);
bool studentuPalyginimas(const Studentas& s1, const Studentas& s2);
void spausdintiStudentus(const vector<Studentas>& studentai, ofstream& outfile);
void rusiuotiStudentus(vector<Studentas>& studentai);
void dalintiStudentus(vector<Studentas>& studentai, vector<Studentas>& vargsiukai);
bool yraVargsiukas(const Studentas& temp);

