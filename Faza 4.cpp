#include <iostream>
#include <vector>
using namespace std;

class Macara {
private:
    string tip;
    int capacitate;
    double razaActiune;

public:
    // Constructor f?r? parametri
    Macara() : tip("Necunoscuta"), capacitate(0), razaActiune(10.0) {}

    // Constructor cu parametri
    Macara(string t, int c, double r) : tip(t), capacitate(c), razaActiune(r) {}

    // Citire de la tastatur?
    void citire() {
        cout << "Introduceti tipul macaralei: ";
        cin >> tip;
        cout << "Introduceti capacitatea macaralei: ";
        cin >> capacitate;
        cout << "Introduceti raza de actiune a macaralei: ";
        cin >> razaActiune;
    }

    // Afi?are
    void afisare() const {
        cout << "Macara: Tip=" << tip << ", Capacitate=" << capacitate
            << ", RazaActiune=" << razaActiune << endl;
    }

    // Supraincarcarea operatorului <<
    friend ostream& operator<<(ostream& out, const Macara& macara) {
        out << "Macara: Tip=" << macara.tip
            << ", Capacitate=" << macara.capacitate
            << ", RazaActiune=" << macara.razaActiune;
        return out;
    }
};

int main() {
    // Vectori de obiecte de tip Macara
    int n;
    cout << "Cate macarale doriti sa introduceti? ";
    cin >> n;

    vector<Macara> macarale(n);
    for (int i = 0; i < n; i++) {
        cout << "Introduceti datele pentru macara " << i + 1 << ":" << endl;
        macarale[i].citire();
    }

    // Afi?are vector de macarale
    cout << "\nMacaralele introduse sunt:\n";
    for (const auto& macara : macarale) {
        cout << macara << endl;
    }

    // Matrice de obiecte de tip Macara
    int rows, cols;
    cout << "\nDimensiunile matricei de macarale (linii, coloane): ";
    cin >> rows >> cols;

    vector<vector<Macara>> matrice(rows, vector<Macara>(cols));

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << "Introduceti datele pentru macara [" << i + 1 << "][" << j + 1 << "]:" << endl;
            matrice[i][j].citire();
        }
    }

    // Afi?are matrice de macarale
    cout << "\nMatricea de macarale este:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << "Macara [" << i + 1 << "][" << j + 1 << "]: ";
            matrice[i][j].afisare();
        }
    }

    return 0;
}
