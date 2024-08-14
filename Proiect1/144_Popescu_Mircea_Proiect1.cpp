#include<iostream>
#include<stdio.h>
#include<vector>
#include<math.h>
#include<String>
#include<list>

using namespace std;

class Produs {
private:
    string numeProdus;
    double pretProdus;
    bool val;
    int codProdus;
    int contor;
public:

    // Constructor cu parametri impliciti
    Produs(string, double, bool, int, int);

    // + 2 constructori cu parametri


    // Copy constructor
    Produs(const Produs&);

    //  Supraincarcarea operatorului >> pentru obiecte de tip Produs
    friend istream& operator >> (istream& in, Produs& p);

    // Supraincarcarea operatorului << pentru obiecte de tip Produs
    friend ostream& operator << (ostream& out, Produs& p);

    // Supraincarcarea operatorului ++ () pentru obiecte de tip Produs
    Produs operator ++ ();

    //Supraincarcarea operatorului ++ (int) pentru obiecte de tip Produs
    Produs operator ++ (int);

    // Supraincarcarea operatorului += pentru obiecte de tip Produs
    Produs operator += (float x);

    //Supraincarcarea operatorului == pentru obiecte de tip Produs
    bool operator == (const Produs& p);

    // Supraincarcarea operatorului < pentru obiecte de tip Produs
    bool operator < (const Produs& p);

    // Supraincarcarea operatorului > pentru obiecte de tip Produs
    bool operator > (const Produs& p);

    //Supraincarcarea operatorului + pentru obiecte de tip Produs
    double operator + (const Produs& p);

    // Supraincarcarea operatorului egal pentru obiecte de tip Produs
    Produs operator = (const Produs&);

    //Operatorul cast explicit
    explicit operator int() {

        return (int)this->codProdus;
    }

    //Functionalitate

    void citireProdus(istream& in);
    void afisareProdus(ostream& out);

    void setNume(string);
    string getNume();

    void setPret(double);
    double getPret();

    void setCod(int);
    int getCod();


    // Destructor
    ~Produs();
};

void Produs::setNume(string nume) {
    this->numeProdus = nume;
}

string Produs::getNume() {
    return this->numeProdus;
}

void Produs::setPret(double pret) {
    this->pretProdus = pret;
}

double Produs::getPret() {
    return this->pretProdus;
}

void Produs::setCod(int cod) {
    this->codProdus = cod;
}

int Produs::getCod() {
    return this->codProdus;
}

//Supraincarcarea operatorului + pentru obiecte de tip Produs
double Produs::operator + (const Produs& p) {
    double sum = this->pretProdus + p.pretProdus;
    return sum;
}

//Operator cast explicit
    /*explicit operator int() {
        return (int)this->numeProdus;
    }*/

Produs Produs::operator = (const Produs& p) {
    if (this != &p) {
        this->numeProdus = p.numeProdus;
        this->pretProdus = p.pretProdus;
        this->val = p.val;
        this->codProdus = p.codProdus;
        this->contor = p.contor;
    }
    return *this;
}

Produs::Produs(string numeProdus = "", double pretProdus = 0.0, bool val = false, int codProdus = 0, int contor = 0) {
    this->numeProdus = numeProdus;
    this->pretProdus = pretProdus;
    this->val = val;
    this->codProdus = codProdus;
    this->contor = contor;
}

istream& operator >> (istream& in, Produs& p) {
    p.citireProdus(in);
    return in;
}

void Produs::citireProdus(istream& in) {
    cout << "\nIntroduceti numele produsului: ";
    //in >> numeProdus;
    getline (in, numeProdus);
    cout << "\nIntroduceti pretul produsului: ";
    string nr_pret;
    in >> nr_pret;
    //getline(in, nr_pret);
    cout << "\nIntroduceti codul produsului:";
    in >> codProdus;

    for (auto lit : nr_pret)
    {
        if (isdigit(lit) == false && lit != '.')
            val = false;
        else
            val = true;
    }

    while (val == false)
    {
        val = true;
        for (auto lit : nr_pret)
        {
            if (isdigit(lit) == false && lit != '.')
                val = false;
        }

        if (val == false)
        {
            cout << "\nPretul trebuie sa fie o valoare numerica (double).\nVa rugam introduceti alta valoare!\n" << "Pret: ";
            in >> nr_pret;
        }
        else
            val = true;
    }
    this->pretProdus = atof(nr_pret.c_str());

}


ostream& operator << (ostream& out, Produs& p)
{
    p.afisareProdus(out);
    return out;
}

void Produs::afisareProdus(ostream& out) {
    out << "\nNumele produsului: " << numeProdus << "\n";
    out << "Pretul produsului: " << pretProdus << " lei" << "\n";
    out << "Codul produsului:" << codProdus << "\n";
}



bool Produs::operator == (const Produs& p) {
    if (this->numeProdus != p.numeProdus) return false;
    if (this->pretProdus != p.pretProdus) return false;
    if (this->val != p.val) return false;
    if (this->codProdus != p.codProdus) return false;

    return true;
}

Produs Produs::operator ++ () {
    this->pretProdus++;
    return *this;
}

Produs Produs::operator ++ (int) {
    Produs aux = *this;
    this->pretProdus++;
    return aux;
}
bool Produs::operator < (const Produs& produs) {
    return this->pretProdus < produs.pretProdus;
}

bool Produs::operator > (const Produs& produs) {
    return this->pretProdus > produs.pretProdus;
}



Produs::Produs(const Produs& p) { //: codProdus(contor++) {
    this->numeProdus = p.numeProdus;
    this->pretProdus = p.pretProdus;
    this->val = p.val;
    this->codProdus = p.codProdus;

}

Produs::~Produs() {
    this->numeProdus = "";
    this->pretProdus = 0.0;
    this->val = 0;
    this->codProdus = 0;

}

/////////////////////////////////////////////////////////////////////////////////////////////////////////

class  Magazin {
private:
    string numeMagazin;
    string adresaMagazin;
    int numarProduse;
    list <Produs> listaProduse;
    bool val;
public:

    friend istream& operator >> (istream& in, Magazin& p);
    friend ostream& operator << (ostream& out, Magazin& p);

    void introducereMagazin(istream& in);
    void afisareMagazin(ostream& out);

    Magazin operator ++ ();
    Magazin operator ++ (int);
    Magazin operator += (float x);
    bool operator == (const Magazin& m);
    Magazin operator = (const Magazin& m);
    Magazin(const Magazin&);
    bool operator < (const Magazin& m);
    bool operator > (const Magazin& m);


    Magazin(string, string, int, list<Produs>);
    ~Magazin();

};

Magazin Magazin::operator ++ () {
    this->numarProduse++;
    return *this;
}

Magazin Magazin::operator ++ (int) {
    Magazin aux = *this;
    this->numarProduse++;
    return aux;
}

bool Magazin::operator == (const Magazin& m) {
    if (this->numeMagazin != m.numeMagazin) return false;
    if (this->adresaMagazin != m.adresaMagazin) return false;
    if (this->numarProduse != m.numarProduse) return false;
    //if (this->listaProduse != m.listaProduse) return false;

    return true;
}

bool Magazin::operator < (const Magazin& m) {
    return this->numarProduse < m.numarProduse;
}

bool Magazin::operator > (const Magazin& m) {
    return this->numarProduse > m.numarProduse;
}

Magazin::Magazin(string numeMagazin = "", string adresaMagazin = "", int numarProduse = 0, list<Produs> listaProduse = {}) {
    this->numeMagazin = numeMagazin;
    this->adresaMagazin = adresaMagazin;
    this->numarProduse = numarProduse;
    this->listaProduse = listaProduse;
}

istream& operator >> (istream& in, Magazin& p) {
    p.introducereMagazin(in);
    return in;
}

void Magazin::introducereMagazin(istream& in) {
    cout << "\nIntroduceti numele magazinului: ";
    getline(in, numeMagazin);
    cout << "\nIntroduceti adresa magazinului:";
    getline(in, adresaMagazin);
    cout << "\nIntroduceti numarul de produse: ";
    in >> numarProduse;
    for (int i = 0; i < numarProduse; i++)
    {
        Produs p;
        in >> p;
        listaProduse.push_back(p);
    }
}
ostream& operator << (ostream& out, Magazin& p)
{
    p.afisareMagazin(out);
    return out;
}

void Magazin::afisareMagazin(ostream& out) {
    out << "\nNume magazin: " << numeMagazin;
    out << "\nAdresa magazin:" << adresaMagazin;
    out << "\nNr. produse: " << numarProduse;
    //for (int i = 0; i < numarProduse; i++)
        //out << "Produsul cu numarul " << i << " : "; //<< listaProduse << '\n';
    int numarProduse = 1;
    while (!listaProduse.empty())
    {

        out << "Produsul cu numarul " << numarProduse << " : "<<endl;
        out << listaProduse.front() << '\n';
        listaProduse.pop_front();
        numarProduse++;

    }


}
//copy-constructor
Magazin::Magazin(const Magazin& m) {
    this->numeMagazin = m.numeMagazin;
    this->adresaMagazin = m.adresaMagazin;
    this->numarProduse = m.numarProduse;
    this->listaProduse = m.listaProduse;
}

//supraincarcarea operatorului = pt obiecte de tip Magazin
Magazin Magazin::operator = (const Magazin& m) {
    if (this != &m) {
        this->numeMagazin = m.numeMagazin;
        this->adresaMagazin = m.adresaMagazin;
        this->numarProduse = m.numarProduse;
        this->listaProduse = m.listaProduse;
    }
    return *this;

}


Magazin::~Magazin() {
    numeMagazin = "";
    numarProduse = 0;
    listaProduse.clear();
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////

class Angajat {
private:
    string numeAngajat, dataAngajare;
    int varstaAngajat, experientaAngajat;
    double salariuAngajat;


public:

    friend istream& operator >> (istream& in, Angajat& a);
    friend ostream& operator << (ostream& out, Angajat& a);

    void introducereAngajat(istream& in);
    void afisareAngajat(ostream& out);

    //Setters & getters
    void setNume(string);
    string getNume();

    void setdataAngajare(string);
    string getdataAngajare();

    void setVarsta(int);
    int getVarsta();

    void setExperienta(int);
    int getExperienta();

    void setSalariu(double);
    double getSalariu();

    //Supraincarcarea operatorului ++ pentru obiecte de tip Angajat
    Angajat operator ++ ();

    //Supraincarcarea operatorului ++ p
    Angajat operator ++(int);
    Angajat operator += (float x);
    Angajat operator = (const Angajat& a);
    bool operator == (const Angajat& a);
    bool operator < (const Angajat& a);
    bool operator > (const Angajat& a);

    // Functionalitate
    void categorieAngajat(int experientaAngajat);

    Angajat(string, string, int, int, double);
    ~Angajat();

};
bool Angajat::operator == (const Angajat& a) {
    if (this->numeAngajat != a.numeAngajat) return false;
    if (this->dataAngajare != a.dataAngajare) return false;
    if (this->varstaAngajat != a.varstaAngajat) return false;
    if (this->experientaAngajat != a.experientaAngajat) return false;
    if (this->salariuAngajat != a.salariuAngajat) return false;

    return true;
}

Angajat Angajat::operator = (const Angajat& a) {
    if (this != &a) {
        this->numeAngajat = a.numeAngajat;
        this->dataAngajare = a.dataAngajare;
        this->varstaAngajat = a.varstaAngajat;
        this->experientaAngajat = a.experientaAngajat;
        this->salariuAngajat = a.salariuAngajat;
    }
    return *this;
}

void Angajat::categorieAngajat(int experientaAngajat) {
    if (experientaAngajat >= 6) {
        cout << "Angajat experimentat.";
    }
}

Angajat Angajat::operator ++ () {
    this->experientaAngajat++;
    return *this;
}

Angajat Angajat::operator ++(int) {
    Angajat aux = *this;
    this->experientaAngajat++;
    return aux;

}

bool Angajat::operator < (const Angajat& a) {
    return this->salariuAngajat < a.salariuAngajat;
}

bool Angajat::operator > (const Angajat& a) {
    return this->salariuAngajat > a.salariuAngajat;
}

Angajat::Angajat(string numeAngajat = "", string dataAngajare = "", int varstaAngajat = 0, int experientaAngajat = 0, double salariuAngajat = 0) {
    this->numeAngajat = numeAngajat;
    this->dataAngajare = dataAngajare;
    this->varstaAngajat = varstaAngajat;
    this->experientaAngajat = experientaAngajat;
    this->salariuAngajat = salariuAngajat;
}

istream& operator >> (istream& in, Angajat& a) {
    a.introducereAngajat(in);
    return in;
}


void Angajat::introducereAngajat(istream& in) {
    cout << "\nIntroduceti numele angajatului: ";
    getline(in, numeAngajat);
    cout << "\nIntroduceti data angajarii: ";
    in >> dataAngajare;
    cout << "\nIntroduceti varsta angajatului: ";
    in >> varstaAngajat;
    cout << "\nIntroduceti experienta angajatului: ";
    in >> experientaAngajat;
    cout << "\nIntroduceti salariul angajatului: ";
    in >> salariuAngajat;

}

ostream& operator << (ostream& out, Angajat& a)
{
    a.afisareAngajat(out);
    return out;
}

void Angajat::afisareAngajat(ostream& out) {
    out << "\nNume angajat: " << numeAngajat;
    out << "\nData angajarii: " << dataAngajare;
    out << "\nVarsta angajat: " << varstaAngajat << " ani";
    out << "\nExperienta angajat: " << experientaAngajat << " ani";
    out << "\nSalariu angajat: " << salariuAngajat << " euro";
}

void Angajat::setNume(string nume) {
    this->numeAngajat = nume;
}
string Angajat::getNume() {
    return this->numeAngajat;
}

void Angajat::setdataAngajare(string data) {
    this->dataAngajare = data;
}
string Angajat::getdataAngajare() {
    return this->dataAngajare;
}

void Angajat::setVarsta(int varsta) {
    this->varstaAngajat = varsta;
}
int Angajat::getVarsta() {
    return this->varstaAngajat;
}

void Angajat::setExperienta(int experienta) {
    this->experientaAngajat = experienta;
}
int Angajat::getExperienta() {
    return this->experientaAngajat;
}

void Angajat::setSalariu(double salariu) {
    this->salariuAngajat = salariu;
}
double Angajat::getSalariu() {
    return this->salariuAngajat;
}





Angajat::~Angajat() {
    this->numeAngajat = "";
    this->dataAngajare = "";
    this->varstaAngajat = 0;
    this->experientaAngajat = 0;
    this->salariuAngajat = 0;


}


////////////////////////////////////////////////////////////////////////////////////////////

class Client {
private:
    string numeClient;
    string prenumeClient;
    string cardClient;
    long codClient;
    int varstaClient;

public:
    void introducereClient(istream& in);
    void afisareClient(ostream& out);

    //  Supraincarcarea operatorului >>
    friend istream& operator >> (istream& in, Client& c);

    // Supraincarcarea operatorului <<
    friend ostream& operator << (ostream& out, Client& c);

    // Supraincarcarea operatorului ++
    Client& operator ++ ();

    Client operator ++(int);

    // Supraincarcarea operatorului +=
    Client operator += (float x);

    //Supraincarcarea operatorului =
    Client operator = (const Client& c);

    // Supraincarcarea operatorului <
    bool operator < (const Client& c);

    // Supraincarcarea operatorului >
    bool operator > (const Client& c);

    //Supraincarcarea operatorului ==
    bool operator == (const Client& c);

    // Constructor cu parametri impliciti
    Client(string, string, long, string, int);

    // Copy constructor
    Client(const Client&);

    // Destructor
    ~Client();



};

//Supraincarcarea operatorului == pentru obiecte de tip Client
bool Client::operator == (const Client& c) {
    if (this->numeClient != c.numeClient) return false;
    if (this->prenumeClient != c.prenumeClient) return false;
    if (this->codClient != c.codClient) return false;
    if (this->cardClient != c.cardClient) return false;
    if (this->varstaClient = c.varstaClient) return false;

    return true;
}


//Supraincarcarea operatorului = pentru obiecte de tip Client
Client Client::operator = (const Client& c) {
    if (this != &c) {
        this->numeClient = c.numeClient;
        this->prenumeClient = c.prenumeClient;
        this->codClient = c.codClient;
        this->cardClient = c.cardClient;
        this->varstaClient = c.varstaClient;
    }
    return *this;
}

//Constructor cu toti parametri
Client::Client(string numeClient = "", string prenumeClient = "", long codClient = 0, string cardClient = "", int varstaClient = 0) {
    this->numeClient = numeClient;
    this->prenumeClient = prenumeClient;
    this->codClient = codClient;
    this->cardClient = cardClient;
    this->varstaClient = varstaClient;
}

//Copy constructor
Client::Client(const Client& c) {
    this->numeClient = c.numeClient;
    this->prenumeClient = c.prenumeClient;
    this->codClient = c.codClient;
    this->cardClient = c.cardClient;
    this->varstaClient = c.varstaClient;
}

//Supraincarcarea operatorului ++ prefixat
Client& Client::operator ++ () {
    this->codClient++;
    return *this;
}

//Supraincarcarea operatorului ++ postfixat
Client Client::operator ++ (int) {
    Client& aux = *this;
    this->codClient++;
    return aux;
}

//Supraincarcarea operatorului >> pe obiecte de tip Client
istream& operator >> (istream& in, Client& c) {
    c.introducereClient(in);
    return in;
}

//Supraincarcarea operatorului << pe obiecte de tip Client
ostream& operator << (ostream& out, Client& c) {
    c.afisareClient(out);
    return out;
}

//Functia de citire a obiectelor de tip Client
void Client::introducereClient(istream& in) {
    cout << "\nIntroduceti numele clientului: ";
    getline(in, numeClient);
    cout << "\nIntroduceti prenumele clientului: ";
    getline(in, prenumeClient);
    cout << "\nIntroduceti codul clientului: ";
    in >> codClient;
    cout << "\nIntroduceti cardul clientului: ";
    in >> cardClient;
    cout << "\nIntroduceti varsta clientului:";
    in >> varstaClient;
}

//Functia de afisare a obiectelor de tip Client
void Client::afisareClient(ostream& out) {
    out << "\nNumele clientului: " << numeClient << "\n";
    out << "\nPrenumele clientului:" << prenumeClient << "\n";
    out << "\nCodul clientului:" << codClient << "\n";
    out << "\nCardul clientului:" << cardClient << "\n";
    out << "\nVarsta clientului:" << varstaClient << " ani" << "\n";
}

//Destructor
Client::~Client() {
    this->numeClient = "";
    this->prenumeClient = "";
    this->codClient = 0;
    this->cardClient = "";
    this->varstaClient = 0;
}

int main() {

    /*Magazin m;
    cin >> m;
    cout << m;*/

    /*Client d;
    cin >> d;
    cout << d;

    Produs p;
    cin >> p;
    cout << endl;
    cout << p;

    Angajat a;
    cin >> a;
    cout << a;*/

    Produs produs;
    Magazin magazin;
    Client client;
    Angajat angajat;

    int alegere;
    bool ok = true;


    while (ok == true) {
        cout << endl;
        cout << "Apasa (1) pentru a introduce un produs " << endl;
        cout << "Apasa (2) pentru a introduce un magazin " << endl;
        cout << "Apasa (3) pentru a introduce un angajat" << endl;
        cout << "Apasa (4) pentru a introduce un client " << endl;
        cout << "Apasa (5) pentru a afisa produsul ales " << endl;
        cout << "Apasa (6) pentru a afisa magazinul ales. " << endl;
        cout << "Apasa (7) pentru a afisa angajatul ales." << endl;
        cout << "Apasa (8) pentru a afisa clientul ales." << endl;
        cout << "Apasa (9) pentru a afisa angajatii experimentati." << endl;
        cout << "Apasa (10) pentru a iesi din program." << endl;
        cout << "\nOptiunea dumneavoastra este:";
        cin >> alegere;
        cin.get();
        cout << endl;


        switch (alegere) {
        case 1: {
            cin >> produs;
            break;
        }
        case 2: {
            cin >> magazin;
            break;
        }
        case 3: {
            cin >> angajat;
            break;
        }
        case 4: {
            cin >> client;
            break;
        }
        case 5: {
            cout << produs;
            break;
        }
        case 6: {
            cout << magazin;
            break;
        }
        case 7: {
            cout << angajat;
            break;
        }
        case 8: {
            cout << client;
            break;
        }
        case 9: {
            cout << "Angajatii experimentati sunt:" << endl;
            void categorieAngajat();
            break;
        }
        case 10: {
            cout << "\n=============================================================================================\n";
            ok = false;
            break;
        }

        }
    }

    return 0;

}
