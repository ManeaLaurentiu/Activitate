#include <iostream>
#include <string>

// // Faza 2 - Început // //

class Macara {
private:
    std::string tip;
    int capacitate;
    const int inaltimeMaxima;
    static int numarMacarale;
    double* razaActiune;

public:
    // Constructor fara parametri
    Macara() : inaltimeMaxima(30), razaActiune(new double(10.0)) {
        tip = "Necunoscuta";
        capacitate = 0;
        numarMacarale++;
    }

    // Constructor cu parametri
    Macara(std::string tip, int capacitate, double raza = 10.0)
        : inaltimeMaxima(30), razaActiune(new double(raza)) {
        this->tip = tip;
        this->capacitate = capacitate;
        numarMacarale++;
    }

    // Constructor de copiere (deep copy)
    Macara(const Macara& other) : inaltimeMaxima(other.inaltimeMaxima) {
        tip = other.tip;
        capacitate = other.capacitate;
        razaActiune = new double(*other.razaActiune); // Deep copy
        numarMacarale++;
    }

    // Destructor
    ~Macara() {
        delete razaActiune;
    }

    // Get-eri
    std::string getTip() const { return tip; }
    int getCapacitate() const { return capacitate; }
    int getInaltimeMaxima() const { return inaltimeMaxima; }
    double getRazaActiune() const { return *razaActiune; }

    // Set-eri
    void setTip(std::string t) { tip = t; }
    void setCapacitate(int c) { capacitate = c; }
    void setRazaActiune(double raza) { *razaActiune = raza; }

    // Func?ie static? pentru num?rul total de macarale
    static int getNumarMacarale() {
        return numarMacarale;
    }

    // Func?ie prieten?
    friend void afiseazaMacara(const Macara& macara);
};

// Ini?ializare atribut static
int Macara::numarMacarale = 0;

// Func?ie global? prieten?
void afiseazaMacara(const Macara& macara) {
    std::cout << "Macara: " << macara.tip
        << ", Capacitate: " << macara.capacitate
        << ", Inaltime maxima: " << macara.inaltimeMaxima
        << ", Raza actiune: " << *macara.razaActiune << std::endl;
}

// // Faza 2 - Sfâr?it // //


// // Faza 3 - Început // //

// Operator de atribuire (deep copy)
Macara& Macara::operator=(const Macara& other) {
    if (this != &other) {
        tip = other.tip;
        capacitate = other.capacitate;

        delete razaActiune; // Eliber?m memoria existent?
        razaActiune = new double(*other.razaActiune); // Deep copy
    }
    return *this;
}

// Operator +
Macara Macara::operator+(const Macara& other) const {
    return Macara(tip + " + " + other.tip, capacitate + other.capacitate, *razaActiune + *other.razaActiune);
}

// Operator -
Macara Macara::operator-(const Macara& other) const {
    return Macara(tip + " mai mica", capacitate - other.capacitate, *razaActiune - *other.razaActiune);
}

// Operator <<
std::ostream& operator<<(std::ostream& out, const Macara& macara) {
    out << "Macara: " << macara.tip
        << ", Capacitate: " << macara.capacitate
        << ", Inaltime maxima: " << macara.inaltimeMaxima
        << ", Raza actiune: " << *macara.razaActiune;
    return out;
}

// // Faza 3 - Sfâr?it // //

int main() {
    // // Faza 2 - Testare // //
    Macara m1("Turn", 500, 20.0);
    Macara m2("Mobil?", 300);
    Macara m3 = m1; // Constructor de copiere

    // Afi?are folosind func?ia global? prieten?
    afiseazaMacara(m1);
    afiseazaMacara(m2);
    afiseazaMacara(m3);

    // Afi?are folosind get-eri
    std::cout << "Tip: " << m1.getTip()
        << ", Capacitate: " << m1.getCapacitate()
        << ", Raza actiune: " << m1.getRazaActiune() << std::endl;

    // // Faza 2 - Sfâr?it // //

    // // Faza 3 - Testare // //
    Macara m4("Gigant", 1000, 50.0);
    Macara m5 = m1 + m4; // Operator +
    Macara m6 = m4 - m1; // Operator -

    std::cout << m5 << std::endl; // Operator <<
    std::cout << m6 << std::endl;

    m6 = m2; // Operator de atribuire
    std::cout << m6 << std::endl;

    // // Faza 3 - Sfâr?it // //

    return 0;
}
