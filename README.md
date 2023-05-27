
# v1.0
**Programoje testuojamos dvi strategijos:**
1. Bendro studentai konteinerio (vector, list ir deque tipų) skaidymas (rūšiavimas) į du naujus to paties tipo konteinerius: "vargšiukų" ir "kietiakų". (Jau prieš tai naudota strategija ***v0.4*** ir ***v0.5*** programose)
2. Bendro studentų konteinerio (vector, list ir deque) skaidymas (rūšiavimas) panaudojant tik vieną naują konteinerį: "vargšiukai". (Pridėtas nauja skaidymo funkcija *void dalintiStudentus*, kuri naudoja ***remove_if*** algoritmą, kuri tikriną studentų konteinerį, ir, jei jis atitinka bool tipo funkcija *yraVargsiukas* (kuri patikrina, ar galutinis studento balas pagal medianą yra mažiau už 5), nukelia tuos studentų įrašus į patį konteinerio galą ir atnaujina konteinerio pabaigą).

**SKIRTINGŲ STRATEGIJŲ GREIČIO PALYGINIMAS**
  1. Su ***std::vector*** konteineriu pagal pirmą strategiją, su 1000000 studentų įrašų buvo atliktas skaidymas, kuris užtruko *1,8sec*, o pagal antrą strategiją tik *0,8sec*, net viena sekunde greičiau, ir apie ~2,25 karto greitesnis skaidymas su visais įrašais, nepriklausomai nuo jų kiekio. (Rezultatatus galite pamatyti: ***vector_test.png*** - 1 strategija, ***vector_2_strategija.png*** - 2 strategija)
  2. Su ***std::list*** konteineriu pagal pirmą strategiją, su 1000000 studentų įrašų buvo atliktas skaidymas, kuris užtruko *6,67sec*, o pagal antrą strategiją *5,9sec*, tik *~0,8sec* greičiau. (Rezultatus galite pamatyti : ***List_test.png*** - 1 strategija, ***list_2_strategija*** - 2 strategija).
  3. Su ***std::deque*** konteineriu pagal pirmą strategiją, su 1000000 studentų įrašų buvo atliktas skaidymas, kuris užtruko *6,7sec*, o pagal antrą strategiją *3,3sec*, net *~3,4sec* greičiau, ir beveik 2 kartus greitesnis skaidymas su visais įrašais, nepriklausomai nuo jų kiekio. (Rezultatus galite pamatyti : ***Deque_test.png*** - 1 strategija, ***deque_2_strategija*** - 2 strategija).

**GREIČIO IŠVADA**
Galutinei programos versijai ***v1.0*** pasirinktas greičiausias ***std::vector*** konteineris ir greičiausia 2 skaidymo strategija, kuri panaudoja tik vieną naują konteinerį ir išskaido *"vargšiukus"* pasinaudojant ***remove_if*** algoritmu.

**PAPILDOMOS PROGRAMOS DALYS**
Sukurtas *CMakeLists.txt failas, pagal kurį yra sudaros *executable* failas *build* aplankale, kurį paleidus iškart paleidžiamas veikianti programa.

**ĮDIEGIMO INSTRUKCIJA**
1. Atsisiųskite ***v1.0 release*** zip failą ir jį atidarykite.
2. Atidarykite *build* aplankalą.
3. Paleiskite *studentai.exe* failą ir naudokitės programa.


# v0.5
Konteinerių testavimas: Išmatuota patobulintos v0.4 realizacijos veikimo sparta priklausomai nuo naudojamų trijų skirtingų tipų konteinerių (t.y. tureti arba vieną programą su treis skirtingais konteineriais, arba tris skirtingas programas su atitinkamais konteineriais): 

 1. ***std::vector***
 2. ***std::list***
 3. ***std::deque***

**GREICIO TIKRINIMAS**
Programa greičiausiai veikia su **std::vector** konteineriu ir atlieka visas funkcija efektyviausiai bei greičiausiai (rezultatus galima pamatyti ***vector_test.png***),skaitymo funkcija greičiau atliekama su **std::list** nei su **std::deque** konteineriu, tačiau programa, naudodama **std::list** studentų rūšiavimui didėjimo tvarka užtrunka labai ilgai ir yra labai laukiamas rezultatas (rezultatus galima pamatyti ***List_test.png*** ***Deque_test.png***). 

**CPU,RAM,VIRTUAL MEMORY TIKRINIMAS**
Veikiant programa su visais konteineriais apkrauna **CPU** procesorių labai panašiai, su visais konteineriais virš *90%*, mažiausiai **RAM** (Real Memory) išnaudoja ***std::vector*** konteineris, tik *392,7MB*, kas yra pakankamai mažai palyginus su kitais konteineriais, tuo tarpu ***std::list*** išnaudoja **RAM** *851,7MB*, o ***std::deque*** net *6,61GB*, mažiausiai **Virtual Memory** išnaudoja ***std::vector***, tačiau ir ***std::list*** labai panašiai (abu konteineriai *~33GB*), o ***std::deque*** konteineris daugiausiai net *40,38GB* (visus rezultatus galite pamtyti ***vector_cpu_mem.png***, ***list_cpu_mem.png*** ir ***deque_cpu_mem.png***).

Taigi galime daryti išvadą, jog ***std::vector*** konteineris yra greičiausias, efektyviausias ir mažiausiai **RAM** bei **Virtual memory** išnaudojantis konteineris.


# v0.4
Papildyta V0.3 versija - sukurtos šios funkcijos:
1. ***sukurimas_random_failo***: ši funkcija sugeneruoja pasirinktą skaičių (int studentu_skaicius) studentų vardų, pavardžių, 10 pažymių namų darbų (galima pasirinkt namų darbų pažymių kiekį) bei egzamino pažymių.
2. ***studentu_palyginimas***: ši funkcija išrenka, kurio studento galutinis balas, pagal medianą, yra didesnis(funkcija naudojama sort funkcijai).
3. ***spausdinti_studentus***: ši funkcija išspausdina gautus studentus į failą.
4. ***rusiuoti_studentus***: ši funkcija paskirsto pagal galutinį balą studentus ir išskirsto juos į du vector tipo konteinerius: vargsiukai ir kietiakai, taip pat šioje funkcijoje įvykdomas rūšiavimas pasinaudojant sort.

Atlikti programos veikimo ir jų funkcijų laiko matavimai.

# v0.3
Minimalus v0.2 versijos papildymas - atliktas reogranizavimas, funkcijos išskirstytos į kelis failus, pridėti try/catch blokai.

# v0.2
Programa atnaujinta taip, jog leidžiama dabar pasirinkt būdą kaip gauti duomenis, pasirinkus 2 būdą, skaitomi duomenys iš failo.

# v0.1
Sukurta C++ studentu programa, kurioje:
1. Su studentas struktūra leidžia suvesti studentų duomenis ranka arba jie atsititiktinai generuojami
2. Baigus duomenų įvedimą, suskaičiuojami galutiniai balai ir jie pateikiami į ekraną tokiu ar panašiu pavidalu (kur galutinis apskaičiuotas balas pateikiamas dviejų skaičių po kablelio tikslumu): Pavardė Vardas Galutinis su vidurkiu, su mediana.
3. Galutinis rezultatas gali būti skaičiuojamas naudojant namų darbų vidurkį arba medianą.
4. Sukurti 2 atskiri failai ***v0.1_dinaminiai.cpp*** ir ***v0.1_vektoriai.cpp*** kurie studento namų darbų rezultatų įvedimui naudotų dinaminius masyvus ir vektorius.

# Obj_Pro
Čia bus kuriama objektinio programavimo C++ programa, susijusi su studentų duomenimis.

# Obj_Pro_2
Čia bus tęsiama programa "Obj_Pro", bus naudojomos klasės.

