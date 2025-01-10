#include <iostream>
#include <cstring>

class Macara {
public:
    std::string tip;
    int capacitate;
    const int inaltimeMaxima;
    static int numarMacarale;
    double* razaActiune;

    // Constructor fără parametri
    Macara() : inaltimeMaxima(30), razaActiune(new double(10.0)) {
        tip = "Necunoscuta";
        capacitate = 0;
        numarMacarale++;
    }

    // Constructor cu doi parametri
    Macara(std::string tip, int capacitate) : inaltimeMaxima(30), razaActiune(new double(10.0)) {
        this->tip = tip;
        this->capacitate = capacitate;
        numarMacarale++;
    }

    // Constructor cu toți parametrii
    Macara(std::string tip, int capacitate, double raza) : inaltimeMaxima(30), razaActiune(new double(raza)) {
        this->tip = tip;
        this->capacitate = capacitate;
        numarMacarale++;
    }

    // Funcție statică pentru afișarea numărului de macarale
    static int getNumarMacarale() {
        return numarMacarale;
    }

    ~Macara() {
        delete razaActiune;
    }
};
int Macara::numarMacarale = 0;

class LopataHidraulica {
public:
    std::string material;
    int capacitateIncarcare;
    const int greutate;
    static int numarLopeti;
    int* adancimeSapare;

    // Constructor fără parametri
    LopataHidraulica() : greutate(200), adancimeSapare(new int(5)) {
        material = "Necunoscut";
        capacitateIncarcare = 0;
        numarLopeti++;
    }

    // Constructor cu doi parametri
    LopataHidraulica(std::string material, int capacitate) : greutate(200), adancimeSapare(new int(5)) {
        this->material = material;
        this->capacitateIncarcare = capacitate;
        numarLopeti++;
    }

    // Constructor cu toți parametrii
    LopataHidraulica(std::string material, int capacitate, int adancime) : greutate(200), adancimeSapare(new int(adancime)) {
        this->material = material;
        this->capacitateIncarcare = capacitate;
        numarLopeti++;
    }

    // Funcție statică pentru afișarea numărului de lopeți
    static int getNumarLopeti() {
        return numarLopeti;
    }

    ~LopataHidraulica() {
        delete adancimeSapare;
    }
};
int LopataHidraulica::numarLopeti = 0;

class MasinaTransport {
public:
    std::string model;
    int capacitate;
    const int vitezaMaxima;
    static int numarMasini;
    double* consumCombustibil;

    // Constructor fără parametri
    MasinaTransport() : vitezaMaxima(120), consumCombustibil(new double(0.0)) {
        model = "Necunoscut";
        capacitate = 0;
        numarMasini++;
    }

    // Constructor cu doi parametri
    MasinaTransport(std::string model, int capacitate) : vitezaMaxima(120), consumCombustibil(new double(0.0)) {
        this->model = model;
        this->capacitate = capacitate;
        numarMasini++;
    }

    // Constructor cu toți parametrii
    MasinaTransport(std::string model, int capacitate, double consum) : vitezaMaxima(120), consumCombustibil(new double(consum)) {
        this->model = model;
        this->capacitate = capacitate;
        numarMasini++;
    }

    // Funcție statică pentru afișarea numărului de mașini de transport
    static int getNumarMasini() {
        return numarMasini;
    }

    ~MasinaTransport() {
        delete consumCombustibil;
    }
};
int MasinaTransport::numarMasini = 0;

int main() {
    // Testare clasa Macara
    Macara macara1;
    Macara macara2("Turn", 500);
    Macara macara3("Mobilă", 300, 15.0);

    std::cout << "Numar total de macarale: " << Macara::getNumarMacarale() << std::endl;

    // Testare clasa LopataHidraulica
    LopataHidraulica lopata1;
    LopataHidraulica lopata2("Metal", 100);
    LopataHidraulica lopata3("Aliaj", 150, 8);

    std::cout << "Numar total de lopeti: " << LopataHidraulica::getNumarLopeti() << std::endl;

    // Testare clasa MasinaTransport
    MasinaTransport masina1;
    MasinaTransport masina2("Camion", 1000);
    MasinaTransport masina3("Utilitara", 500, 12.5);

    std::cout << "Numar total de masini de transport: " << MasinaTransport::getNumarMasini() << std::endl;

    return 0;
}
