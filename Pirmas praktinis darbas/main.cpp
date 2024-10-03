
#include <iomanip>
#include <iostream>


using namespace std;



// Valiutos kursai
const double GBP_BENDRAS = 0.8593;
const double GBP_PIRKTI = 0.8450;
const double GBP_PARDUOTI = 0.9060;

const double USD_BENDRAS = 1.0713;
const double USD_PIRKTI = 1.0547;
const double USD_PARDUOTI = 1.1309;

const double INR_BENDRAS = 88.8260;
const double INR_PIRKTI = 85.2614;
const double INR_PARDUOTI = 92.8334;

double gautiValiutosKursa(string valiuta, string operacija);


void palyginti() {
    string valiuta;
    cout << "pasirinkite valiuta (GBP, USD, INR): ";
    cin >> valiuta;
    double kursas = gautiValiutosKursa(valiuta, "bendras");

    if (kursas !=0) {
        cout << fixed << setprecision(2);
        cout << "1 Eur = " << kursas << endl;
    } else {
        cout << "netinkama valiuta = " << endl;
    }
}

void isigijimas() {
    string valiuta;
    double kiekis, rezultatas;

    cout << "pasirinkite valiuta, kuria norite pirkit(GBP, USD, INR): ";
    cin >> valiuta;
    double kursas = gautiValiutosKursa(valiuta, "pirkti");

    if (kursas != 0) {
        cout << "iveskite euru kieki: " << endl;
        cin >> kiekis;

        rezultatas = kiekis * kursas;
        cout << fixed << setprecision(2);
        cout << "uzsakytas kiekis " << kiekis << " Eur gautiste: " << rezultatas << "" << valiuta << endl;
    } else {
        cout << "netinkama valiuta = " << endl;
    }
}


void pardavimas() {
        string valiuta;
        double kiekis, rezultatas;

        cout << "pasirinkite valiuta, kuria norit parduoti (GBP, USD, INR):";
        cin >> valiuta;
        double kursas = gautiValiutosKursa(valiuta, "parduoti");
        if (kursas != 0) {
            cout << "iveskite norima valiutos kieki : ";
            cin >> kiekis;

            rezultatas = kiekis / kursas;
            cout << fixed << setprecision(2);
            cout << "pardavus " << kiekis << " " << valiuta << " gausite " << rezultatas << " Eur " << endl;

        } else {
            cout << "netinkama valiuta = " << endl;
        }
    }

double gautiValiutosKursa( string valiuta, string operacija) {
    if (valiuta == "GBP") {
        if (operacija == "bendras") return GBP_BENDRAS;
        else if (operacija == "pirkti") return GBP_PIRKTI;
        else if (operacija == "parduoti") return GBP_PARDUOTI;
    } else if (valiuta == "USD") {
        if (operacija == "bendras") return USD_BENDRAS;
        else if (operacija == "pirkti") return USD_PIRKTI;
        else if (operacija == "parduoti") return USD_PARDUOTI;
    } else if (valiuta == "INR") {
        if (operacija == "bendras") return INR_BENDRAS;
        else if (operacija == "pirkti") return INR_PIRKTI;
        else if (operacija == "parduoti") return INR_PARDUOTI;
    }

    return 0;
}

int main() {

    int pasirinkimas;
    cout << "pasirinkite funkcija" << endl;
    cout << "pasirinkite funkcija" << endl;
    cout << "1-palyginti" << endl;
    cout << "2-issigyti" << endl;
    cout << "3-parduoti" << endl;

    do {
        cout << "Pasirinkite funkcija:" << endl;
        cin >> pasirinkimas;

        switch (pasirinkimas) {
            case 1:
                palyginti();
            break;
            case 2:
                isigijimas();
            break;
            case 3: pardavimas();
            break;
            case 0:
                cout <<  "baigiama programa." << endl;
            break;
            default:
                cout << "Neteisingas pasirinkimas. Bandykite dar karta." << endl;
        }
    }  while (pasirinkimas != 0);
    return 0;
}





