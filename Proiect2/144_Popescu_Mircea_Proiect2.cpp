#include<iostream>
#include<vector>
using namespace std;

class IOInterface
{
public:
    virtual istream& citire(istream& in) = 0;
    virtual ostream& afisare(ostream& out) const = 0;
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Angajat {
protected:
    string numeAngajat;
    float salariuAngajat;
    int experientaAngajat;
    int varsta;

public:
    // functie
    virtual void maresteSalariu() {
        this->salariuAngajat += 500;
        cout << "Salariul dupa marire este:" << this->salariuAngajat;
    };




    // Constructor fara parametri
    Angajat() {
        this->numeAngajat = " ";
        this->salariuAngajat = 0.0;
        this->varsta = 0;
        this->experientaAngajat = 0;
    }

    //Constructor cu toti parametri
    Angajat(string numeAngajat, float salariuAngajat, int experientaAngajat, int varsta) {
        this->numeAngajat = numeAngajat;
        this->salariuAngajat = salariuAngajat;
        this->varsta = varsta;
        this->experientaAngajat = experientaAngajat;
    }

    //Copy constructor
    Angajat(const Angajat& a) {
        this->numeAngajat = a.numeAngajat;
        this->salariuAngajat = a.salariuAngajat;
        this->varsta = a.varsta;
        this->experientaAngajat = a.experientaAngajat;
    }

    //Supraincarcarea operatorului =
    Angajat& operator=(const Angajat& a) {
        if (this != &a) {
            this->numeAngajat = a.numeAngajat;
            this->salariuAngajat = a.salariuAngajat;
            this->varsta = a.varsta;
            this->experientaAngajat = a.experientaAngajat;
        }
        return *this;
    }

    virtual void introducereAngajat(istream& in) {
        cout << "Introduceti numele:";
        in >> this->numeAngajat;
        cout << "Introduceti salariul:";
        int salariuAngajat;
        while (true) {
            try {
                in >> salariuAngajat;
                in.get();
                if (salariuAngajat <= 0)
                    throw string("Salariul trebuie sa fie un numar pozitiv! Va rog introduceti alt salariu.");
                else break;

            }
            catch (string s) {
                cout << s;
            }
        }
        this->salariuAngajat = salariuAngajat;
        cout << "Introduceti varsta:";
        int varsta;
        while (true) {
            try {
                in >> varsta;
                in.get();
                if (varsta <= 0)
                    throw string("Varsta invalida");
                else break;
            }
            catch (string s) {
                cout << s;
            }
        }
        this->varsta = varsta;
        cout << "Introduceti experienta:";
        int experientaAngajat;
        while (true) {
            try {
                in >> experientaAngajat;
                in.get();
                if (experientaAngajat < 0)
                    throw string("Input invalid");
                else break;
            }
            catch (string s) {
                cout << s;
            }
        }
        this->experientaAngajat = experientaAngajat;
    }

    virtual void afiseazaAngajat(ostream& out) {
        out << "Numele angajatului = " << this->numeAngajat << endl;
        out << "Salariu = " << this->salariuAngajat << " euro" << endl;
        out << "Varsta = " << this->varsta << " ani" << endl;
        out << "Experienta = " << this->experientaAngajat << " ani" << endl;
    }

    friend istream& operator >> (istream& in, Angajat& a) {
        a.introducereAngajat(in);
        return in;
    }

    friend ostream& operator << (ostream& out, Angajat& a) {
        a.afiseazaAngajat(out);
        return out;

    }




    ~Angajat() {
        this->numeAngajat = "";
        this->salariuAngajat = 0.0;
        this->varsta = 0;
        this->experientaAngajat = 0;

    }

};

//////////////////////////////////////////////////////////////////////////////////////////////////////////
class Jucator : public virtual Angajat {
protected:
    string post;
    int numarTricou;
    int numarGoluri;

public:
    //Constructor fara parametri
    Jucator() : Angajat() {
        post = "";
        numarTricou = 0;
        numarGoluri = 0;
    }
    //Constructor cu toti parametri
    Jucator(string numeAngajat, float salariuAngajat, int experientaAngajat, int varsta, string post, int numarTricou, int numarGoluri) : Angajat(numeAngajat, salariuAngajat, experientaAngajat, varsta) {
        this->post = post;
        this->numarTricou = numarTricou;
        this->numarGoluri = numarGoluri;
    }

    //Copy constructor
    Jucator(const Jucator& j) : Angajat() {
        this->post = post;
        this->numarTricou = numarTricou;
        this->numarGoluri = numarGoluri;
    }

    //Operator =
    Jucator& operator =(const Jucator& j) {
        if (this != &j) {
            Angajat::operator=(j);
            this->post = j.post;
            this->numarTricou = j.numarTricou;
            this->numarGoluri = j.numarGoluri;
        }
        return *this;
    }

    //citire
    void introducereAngajat(istream& in) {
        Angajat::introducereAngajat(in);
        cout << "Introduceti postul jucatorului:";
        in >> this->post;
        cout << "Introduceti numar tricou:";
        in >> this->numarTricou;
        cout << "Introduceti numarul de goluri:";
        in >> this->numarGoluri;


    }

    //afisare
    void afiseazaAngajat(ostream& out) {
        Angajat::afiseazaAngajat(out);
        out << "Postul jucatorului : " << this->post << endl;
        out << "Numar tricou :" << this->numarTricou << endl;
        out << "Numar goluri :" << this->numarGoluri << endl;

        ;
    }

    //functionalitate
    void schimbaNumar() {
        int numarNou;
        cout << "Alege un numar nou" << endl;
        cin >> numarNou;
        this->numarTricou = numarNou;
        cout << "Noul numar al jucatorului este:" << numarTricou << endl;
    }

    //functionalitate 2
    void maresteSalariu() {
        this->salariuAngajat += 100;
        cout << "Salariul dupa marire este: " << this->salariuAngajat;
    }


    ~Jucator() {
        post = "";
        numarGoluri = 0;
        numarTricou = 0;

    }

};


class Antrenor : public virtual Angajat {
protected:
    int echipeAntrenate;
    int titluriCastigate;

public:
    //functie
    void suntAngajat() {
        cout << "Antrenor angajat";
    }
    //Constructor fara parametri
    Antrenor() : Angajat() {
        echipeAntrenate = 0;
        titluriCastigate = 0;
    }

    //Constructori cu toti parametri
    Antrenor(string numeAngajat, float salariuAngajat, int experientaAngajat, int varsta, int echipeAntrenate, int titluriCastigate) : Angajat(numeAngajat, salariuAngajat, experientaAngajat, varsta) {
        this->echipeAntrenate = echipeAntrenate;
        this->titluriCastigate = titluriCastigate;
    }

    //Copy constructor
    Antrenor(const Antrenor& a) :Angajat(a) {
        this->echipeAntrenate = a.echipeAntrenate;
        this->titluriCastigate = a.titluriCastigate;
    }

    //Operator =
    Antrenor& operator =(const Antrenor& a) {
        if (this != &a) {
            Angajat::operator=(a);
            this->echipeAntrenate = a.echipeAntrenate;
            this->titluriCastigate = a.titluriCastigate;
        }
        return *this;
    }

    //Citire
    void introducereAngajat(istream& in) {
        Angajat::introducereAngajat(in);
        cout << "Introduceti echipele antrenate:";
        in >> this->echipeAntrenate;
        cout << "Introduceti titlurile castigate:";
        in >> this->titluriCastigate;
    }

    //Afisare
    void afiseazaAngajat(ostream& out) {
        Angajat::afiseazaAngajat(out);
        out << "Echipe antrenate:" << this->echipeAntrenate << endl;
        out << "Titluri castigate:" << this->titluriCastigate << endl;
    }

    void maresteSalariu() {
        this->salariuAngajat += 200;
        cout << "Salariul dupa marire este: " << this->salariuAngajat;
    }

    //Destructor
    ~Antrenor() {
        echipeAntrenate = 0;
        titluriCastigate = 0;
    }

};

//////////////////////////////////////////////////////////////////////////////////////////////////////

class JucatorAntrenor :public Jucator, public Antrenor {
private:
    int meciuriJucate;
    string nationalitate;
public:

    //Constructor fara parametri
    JucatorAntrenor() :Jucator(), Antrenor() {
        meciuriJucate = 0;
    }

    //Constructor cu toti parametri
    JucatorAntrenor(string numeAngajat, float salariuAngajat, int experientaAngajat, int varsta, string post, int numarTricou, int numarGoluri, int echipeAndrenate, int titluriCastigate, int meciuriJucate, string nationalitate) :Angajat(numeAngajat, salariuAngajat, varsta, experientaAngajat), Jucator(numeAngajat, salariuAngajat, varsta, experientaAngajat, post, numarGoluri, numarTricou), Antrenor(numeAngajat, salariuAngajat, varsta, experientaAngajat, echipeAntrenate, titluriCastigate) {
        this->meciuriJucate = meciuriJucate;
        this->nationalitate = nationalitate;
    }

    //Copy constructor
    JucatorAntrenor(const JucatorAntrenor& j) :Angajat(j), Jucator(j), Antrenor(j) {
        this->meciuriJucate = j.meciuriJucate;
        this->titluriCastigate = j.titluriCastigate;
    }

    //Operator =
    JucatorAntrenor& operator =(const JucatorAntrenor& j) {
        if (this != &j) {
            Angajat::operator=(j);
            Jucator::operator=(j);
            Antrenor::operator=(j);
            this->meciuriJucate = j.meciuriJucate;
            this->titluriCastigate = j.titluriCastigate;
        }
        return *this;
    }

    //citire
    void introducereAngajat(istream& in) {
        Angajat::introducereAngajat(in);
        cout << "Introduceti numarul de goluri:";
        in >> this->numarGoluri;
        cout << "Introduceti numarul de pe tricou:";
        in >> this->numarTricou;
        cout << "Introduceti numarul de titluri castigate:";
        in >> this->titluriCastigate;
        cout << "Introduceti numarul echipelor antrenate:";
        in >> this->echipeAntrenate;
        cout << "Introduceti numarul de meciuri jucate:";
        in >> this->meciuriJucate;
        cout << "Introduceti nationalitatea:";
        in >> this->nationalitate;
    }

    //afisare
    void afiseazaAngajat(ostream& out) {
        Angajat::afiseazaAngajat(out);
        out << "Numar goluri marcate:" << this->numarGoluri << endl;
        out << "Numar tricou:" << this->numarTricou << endl;
        out << "Numar titluri castigate:" << this->titluriCastigate << endl;
        out << "Echipele antrenate:" << this->echipeAntrenate << endl;
        out << "Numar meciuri jucate:" << this->meciuriJucate << endl;
        out << "Nationalitate:" << this->nationalitate << endl;
    }

    void maresteSalariu() {
        this->salariuAngajat += 300;
        cout << "Salariul dupa marire este: " << this->salariuAngajat;
    }

    //Destructor
    ~JucatorAntrenor() {
        meciuriJucate = 0;
        nationalitate = "--";
    }
};


class Echipa : public IOInterface {
protected:
    string numeEchipa;
    int numarJucatori;
    int anInfiintare;
    int codEchipa;
    vector<Angajat> vectorAngajati;

public:

    // Constructor fara parametri
    Echipa() {
        this->numeEchipa = " ";
        this->numarJucatori = 0;
        this->anInfiintare = 0;
        this->codEchipa = 0;
        this->vectorAngajati = {};
        //this->listaAngajati = {};
    }
    // Constructor cu toti parametri
    Echipa(string numeEchipa, int numarJucatori, int anInfiintare, int codEchipa, vector<Angajat>vectorAngajat) {
        this->numeEchipa = numeEchipa;
        this->numarJucatori = numarJucatori;
        this->anInfiintare = anInfiintare;
        this->codEchipa = codEchipa;
        for (auto angajat : vectorAngajati) {
            this->vectorAngajati.push_back(angajat);
        }

    }

    // Copy constructor
    Echipa(const Echipa& e) {
        this->numeEchipa = e.numeEchipa;
        this->numarJucatori = e.numarJucatori;
        this->anInfiintare = e.anInfiintare;
        this->codEchipa = e.codEchipa;
        this->vectorAngajati = e.vectorAngajati;
    }

    // Supraincarcarea operatorului =
    Echipa& operator=(const Echipa& e) {
        if (this != &e) {
            this->numeEchipa = e.numeEchipa;
            this->numarJucatori = e.numarJucatori;
            this->anInfiintare = e.anInfiintare;
            this->codEchipa = e.codEchipa;
            this->vectorAngajati = e.vectorAngajati;
        }
        return *this;

    }

    friend ostream& operator<<(ostream& out, const Echipa& e) {
        return e.afisare(out);
    }

    friend istream& operator>>(istream& in, Echipa& e) {
        return e.citire(in);
    }


    // Supraincarea operatorului >>
    virtual istream& citire(istream& in) {
        cout << "Introduceti nume echipa:";
        in >> this->numeEchipa;
        cout << "Introduceti numar jucatori:";
        in >> this->numarJucatori;
        cout << "Introduceti an infiintare:";
        in >> this->anInfiintare;
        cout << "Introduceti angajatii echipei: ";
        cout << "Introduceti numarul de angajati:";
        int numarAngajati;
        Angajat angajat;
        in >> numarAngajati;

        for (int i = 0; i < numarAngajati; i++) {
            in >> angajat;
            vectorAngajati.push_back(angajat);
        }

        return in;
    }

    // Supraincarea operatorului <<
    virtual ostream& afisare(ostream& out) const {
        out << "Nume echipa:" << this->numeEchipa << endl;
        out << "Numar jucatori:" << this->numarJucatori << endl;
        out << "An infiintare:" << this->anInfiintare << endl;
        for (auto angajat : vectorAngajati) {
            out << angajat;
            out << "\n";
        }
        return out;
    }


    // Destructor
    ~Echipa() {
        numeEchipa = " ";
        numarJucatori = 0;
        anInfiintare = 0;
        vectorAngajati.resize(0);
    }

};

int main() {

    bool ok = true;
    while (ok == true) {
        int alegere;

        cout << "Apasa (1) pentru a introduce un angajat" << endl;
        cout << "Apasa (2) pentru a introduce un jucator" << endl;
        cout << "Apasa (3) pentru a introduce un antrenor" << endl;
        cout << "Apasa (4) pentru a introduce un jucator-antrenor" << endl;
        cout << "Apasa (5) pentru a introduce o echipa" << endl;
        cout << "Apasa (6) pentru a iesi" << endl;
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        cout << "Introduceti o optiune: ";
        try {
            cin >> alegere;
            if (alegere < 1 || alegere > 6)
                throw string("Optiune invalida. Alege alta optiune!");

            switch (alegere) {
            case 1:
            {
                Angajat a;
                cin >> a;
                cout << endl;
                cout << a;
                cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                break;
            }
            case 2: {
                Jucator j;
                cin >> j;
                cout << endl;
                cout << "Apasa 1 pentru a schimba numarul de pe tricou sau 0 pentru a continua";
                int x;
                cin >> x;
                if (x == 1) {
                    j.schimbaNumar();
                }
                cout << j;
                cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                break;
            }
            case 3: {
                Antrenor a;
                cin >> a;
                cout << endl;
                cout << a;
                cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                break;
            }
            case 4: {
                JucatorAntrenor ja;
                cin >> ja;
                cout << endl;
                cout << "Apasa 1 pentru a face o marire de salariu sau 0 pentru a continua";
                int x;
                cin >> x;
                if (x == 1) {
                    ja.maresteSalariu();
                }
                cout << ja;
                cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                break;
            }
            case 5: {
                Echipa echipa;
                cin >> echipa;
                cout << endl;
                cout << echipa;
                cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                break;
            }
            case 6: {
                cout << "Ati iesit din meniu" << endl;
                ok = false;
                cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
                break;
            }

            }

        }
        catch (string s) {
            cout << s << endl;
        }
    }

    return 0;
}
