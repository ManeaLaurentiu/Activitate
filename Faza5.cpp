#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Clasa Macara din fazele anterioare
class Macara {
private:
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

    // Metod? de afi?are
    void afisare() const {
        cout << "Macara: Tip=" << tip << ", Capacitate=" << capacitate
            << ", RazaActiune=" << razaActiune << endl;
    }

    // Operator <<
    friend ostream& operator<<(ostream& out, const Macara& macara) {
        out << "Macara: Tip=" << macara.tip
            << ", Capacitate=" << macara.capacitate
            << ", RazaActiune=" << macara.razaActiune;
        return out;
    }
};

// Clasa Santier
class Santier {
private:
    string nume;
    string locatie;
    vector<Macara> macarale;

public:
    // Constructor f?r? parametri
    Santier() : nume("Necunoscut"), locatie("Necunoscuta") {}

    // Constructor cu parametri
    Santier(string nume, string locatie, const vector<Macara>& macarale)
        : nume(nume), locatie(locatie), macarale(macarale) {}

    // Geteri ?i seteri
    string getNume() const { return nume; }
    string getLocatie() const { return locatie; }
    vector<Macara> getMacarale() const { return macarale; }

    void setNume(string n) { nume = n; }
    void setLocatie(string l) { locatie = l; }
    void setMacarale(const vector<Macara>& m) { macarale = m; }

    // Ad?ugare ?i eliminare macara
    void adaugaMacara(const Macara& macara) {
        macarale.push_back(macara);
    }

    void eliminaMacara(int index) {
        if (index >= 0 && index < macarale.size()) {
            macarale.erase(macarale.begin() + index);
        }
        else {
            cout << "Index invalid!\n";
        }
    }

    // Afi?are
    void afisare() const {
        cout << "Santier: Nume=" << nume << ", Locatie=" << locatie << endl;
        cout << "Macarale:\n";
        for (const auto& macara : macarale) {
            cout << " - " << macara << endl;
        }
    }

    // Operator +
    Santier operator+(const Macara& macara) const {
        Santier rezultat = *this;
        rezultat.adaugaMacara(macara);
        return rezultat;
    }

    // Operator -
    Santier operator-(int index) const {
        Santier rezultat = *this;
        if (index >= 0 && index < rezultat.macarale.size()) {
            rezultat.macarale.erase(rezultat.macarale.begin() + index);
        }
        return rezultat;
    }

    // Operator <<
    friend ostream& operator<<(ostream& out, const Santier& santier) {
        out << "Santier: Nume=" << santier.nume << ", Locatie=" << santier.locatie << "\n";
        out << "Macarale:\n";
        for (const auto& macara : santier.macarale) {
            out << " - " << macara << "\n";
        }
        return out;
    }
};

// Func?ia main pentru testare
int main() {
    // Cre?m câteva macarale
    Macara m1("Turn", 500, 20.0);
    Macara m2("Mobila", 300, 15.0);
    Macara m3("Gigant", 1000, 50.0);

    // Cre?m un vector de macarale
    vector<Macara> vectorMacarale = { m1, m2 };

    // Cre?m un ?antier
    Santier santier1("Santier Central", "Bucuresti", vectorMacarale);

    // Afi??m ?antierul
    cout << santier1 << endl;

    // Ad?ug?m o macara în ?antier
    santier1 = santier1 + m3;
    cout << "\nDup? ad?ugarea unei macarale:\n" << santier1 << endl;

    // Elimin?m o macara din ?antier
    santier1 = santier1 - 1;
    cout << "\nDup? eliminarea unei macarale:\n" << santier1 << endl;

    return 0;
}
