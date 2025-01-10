#include <iostream>
#include <vector>
#include <fstream>
#include <string>
using namespace std;

// Clasa Macara
class Macara {
protected:
    string tip;
    int capacitate;
    double razaActiune;

public:
    Macara() : tip("Necunoscuta"), capacitate(0), razaActiune(10.0) {}
    Macara(string t, int c, double r) : tip(t), capacitate(c), razaActiune(r) {}

    // Geteri ?i seteri
    string getTip() const { return tip; }
    int getCapacitate() const { return capacitate; }
    double getRazaActiune() const { return razaActiune; }
    void setTip(string t) { tip = t; }
    void setCapacitate(int c) { capacitate = c; }
    void setRazaActiune(double r) { razaActiune = r; }

    virtual void afisare() const {
        cout << "Macara: Tip=" << tip
            << ", Capacitate=" << capacitate
            << ", RazaActiune=" << razaActiune << endl;
    }

    virtual ~Macara() {}
};

// Clasa Santier
class Santier {
protected:
    string nume;
    string locatie;
    vector<Macara> macarale;

public:
    Santier() : nume("Necunoscut"), locatie("Necunoscuta") {}
    Santier(string n, string l, const vector<Macara>& m) : nume(n), locatie(l), macarale(m) {}

    string getNume() const { return nume; }
    string getLocatie() const { return locatie; }
    vector<Macara> getMacarale() const { return macarale; }

    void setNume(string n) { nume = n; }
    void setLocatie(string l) { locatie = l; }
    void setMacarale(const vector<Macara>& m) { macarale = m; }

    virtual void afisare() const {
        cout << "Santier: Nume=" << nume << ", Locatie=" << locatie << endl;
        for (const auto& macara : macarale) {
            macara.afisare();
        }
    }

    virtual ~Santier() {}
};

// Clasa MacaraElectrica - mo?tene?te clasa Macara
class MacaraElectrica : public Macara {
private:
    double capacitateBaterie; 
    double timpFunctionare;   

public:
    MacaraElectrica() : Macara(), capacitateBaterie(0), timpFunctionare(0) {}
    MacaraElectrica(string t, int c, double r, double baterie, double timp)
        : Macara(t, c, r), capacitateBaterie(baterie), timpFunctionare(timp) {}

    double getCapacitateBaterie() const { return capacitateBaterie; }
    double getTimpFunctionare() const { return timpFunctionare; }
    void setCapacitateBaterie(double baterie) { capacitateBaterie = baterie; }
    void setTimpFunctionare(double timp) { timpFunctionare = timp; }

    void afisare() const override {
        Macara::afisare();
        cout << "Macara Electrica: CapacitateBaterie=" << capacitateBaterie
            << " kWh, TimpFunctionare=" << timpFunctionare << " ore" << endl;
    }
};

// Clasa SantierIndustrial - mo?tene?te clasa Santier
class SantierIndustrial : public Santier {
private:
    string tipIndustrie;
    int numarLucratori;

public:
    SantierIndustrial() : Santier(), tipIndustrie("Necunoscut"), numarLucratori(0) {}
    SantierIndustrial(string n, string l, const vector<Macara>& m, string industrie, int lucratori)
        : Santier(n, l, m), tipIndustrie(industrie), numarLucratori(lucratori) {}

    string getTipIndustrie() const { return tipIndustrie; }
    int getNumarLucratori() const { return numarLucratori; }
    void setTipIndustrie(string industrie) { tipIndustrie = industrie; }
    void setNumarLucratori(int lucratori) { numarLucratori = lucratori; }

    void afisare() const override {
        Santier::afisare();
        cout << "Santier Industrial: TipIndustrie=" << tipIndustrie
            << ", NumarLucratori=" << numarLucratori << endl;
    }
};

int main() {
    // Obiecte de tip MacaraElectrica
    MacaraElectrica me1("Turn Electric", 800, 25.0, 100.0, 10.0);
    MacaraElectrica me2("Mobil Electric", 500, 15.0, 75.0, 8.0);

    // Obiecte de tip SantierIndustrial
    vector<Macara> macarale = { me1, me2 };
    SantierIndustrial si1("Santier 1", "Bucuresti", macarale, "Constructii", 100);

    // Afisare obiecte
    cout << "Obiecte de tip MacaraElectrica:\n";
    me1.afisare();
    me2.afisare();

    cout << "\nObiect de tip SantierIndustrial:\n";
    si1.afisare();

    // Upcasting
    cout << "\nTestare upcasting:\n";
    Macara* macaraPtr = &me1; 
    macaraPtr->afisare();

    Santier* santierPtr = &si1; 
    santierPtr->afisare();

    return 0;
}
