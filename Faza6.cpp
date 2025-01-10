#include <iostream>
#include <vector>
#include <fstream>
#include <string>
using namespace std;

// Clasa Macara
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

    // Metode pentru fi?iere text
    void salvareInFisierText(const string& numeFisier) const {
        ofstream fisier(numeFisier, ios::app); // Deschidem în mod append
        if (fisier.is_open()) {
            fisier << tip << " " << capacitate << " " << razaActiune << endl;
            fisier.close();
        }
        else {
            cout << "Eroare la deschiderea fisierului pentru salvare text!\n";
        }
    }

    void incarcareDinFisierText(const string& numeFisier) {
        ifstream fisier(numeFisier);
        if (fisier.is_open()) {
            fisier >> tip >> capacitate >> razaActiune;
            fisier.close();
        }
        else {
            cout << "Eroare la deschiderea fisierului pentru incarcare text!\n";
        }
    }

    // Metode pentru fi?iere binare
    void salvareInFisierBinar(const string& numeFisier) const {
        ofstream fisier(numeFisier, ios::binary | ios::app);
        if (fisier.is_open()) {
            size_t len = tip.size();
            fisier.write((char*)&len, sizeof(len));  // Scriem lungimea stringului
            fisier.write(tip.c_str(), len);         // Scriem stringul
            fisier.write((char*)&capacitate, sizeof(capacitate));
            fisier.write((char*)&razaActiune, sizeof(razaActiune));
            fisier.close();
        }
        else {
            cout << "Eroare la deschiderea fisierului pentru salvare binar!\n";
        }
    }

    void incarcareDinFisierBinar(const string& numeFisier) {
        ifstream fisier(numeFisier, ios::binary);
        if (fisier.is_open()) {
            size_t len;
            fisier.read((char*)&len, sizeof(len));  // Citim lungimea stringului
            char* buffer = new char[len + 1];
            fisier.read(buffer, len);              // Citim stringul
            buffer[len] = '\0';
            tip = string(buffer);
            delete[] buffer;
            fisier.read((char*)&capacitate, sizeof(capacitate));
            fisier.read((char*)&razaActiune, sizeof(razaActiune));
            fisier.close();
        }
        else {
            cout << "Eroare la deschiderea fisierului pentru incarcare binar!\n";
        }
    }

    // Supraincarcare operator <<
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
    Santier() : nume("Necunoscut"), locatie("Necunoscuta") {}
    Santier(string n, string l, const vector<Macara>& m) : nume(n), locatie(l), macarale(m) {}

    // Geteri ?i seteri
    string getNume() const { return nume; }
    string getLocatie() const { return locatie; }
    vector<Macara> getMacarale() const { return macarale; }

    void setNume(string n) { nume = n; }
    void setLocatie(string l) { locatie = l; }
    void setMacarale(const vector<Macara>& m) { macarale = m; }

    // Metode pentru fi?iere text
    void salvareInFisierText(const string& numeFisier) const {
        ofstream fisier(numeFisier, ios::app);
        if (fisier.is_open()) {
            fisier << nume << " " << locatie << " " << macarale.size() << endl;
            for (const auto& macara : macarale) {
                fisier << macara.getTip() << " " << macara.getCapacitate() << " " << macara.getRazaActiune() << endl;
            }
            fisier.close();
        }
        else {
            cout << "Eroare la deschiderea fisierului pentru salvare text!\n";
        }
    }

    void incarcareDinFisierText(const string& numeFisier) {
        ifstream fisier(numeFisier);
        if (fisier.is_open()) {
            int nrMacarale;
            fisier >> nume >> locatie >> nrMacarale;
            macarale.clear();
            for (int i = 0; i < nrMacarale; ++i) {
                string tip;
                int capacitate;
                double razaActiune;
                fisier >> tip >> capacitate >> razaActiune;
                macarale.emplace_back(tip, capacitate, razaActiune);
            }
            fisier.close();
        }
        else {
            cout << "Eroare la deschiderea fisierului pentru incarcare text!\n";
        }
    }

    

    // Supraincarcare operator <<
    friend ostream& operator<<(ostream& out, const Santier& santier) {
        out << "Santier: Nume=" << santier.nume << ", Locatie=" << santier.locatie << "\n";
        for (const auto& macara : santier.macarale) {
            out << macara << "\n";
        }
        return out;
    }
};

// Testare
int main() {
    
    Macara m1("Turn", 500, 20.0);
    Macara m2("Mobila", 300, 15.0);
    m1.salvareInFisierText("macarale.txt");
    m1.salvareInFisierBinar("macarale.bin");

    
    Macara m3;
    m3.incarcareDinFisierText("macarale.txt");
    cout << "Macara incarcata din fisier text:\n" << m3 << endl;

    return 0;
}
