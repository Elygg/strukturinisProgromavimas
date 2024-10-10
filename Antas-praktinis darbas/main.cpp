#include <iostream>
#include <string>
using namespace std;


bool Balsiu_palyginimas() {
    string balses[] = {"a", "e", "i", "o", "u",};

    string ivedimas;

    cout << "iveskite betokia raide" << endl;
    cin >> ivedimas;


    for(int i = 0; i < 1; i++) {
        if(balses[i] == ivedimas) {
            cout << "radom" << endl;
        } else {
            cout << "nebalse" << endl;
        }
    }
}

    void Maziausias_bendras_daliklis() {

    }

    void Zaidimas() {
    cout << "Zaidimas" << endl;
    }

    void fizzBuzz() {

    }




    int main() {

        int pasirinkimas;

    cout << "pasirinkite funkcija" << endl;
    cout << "pasirinkite funkcija" << endl;
    cout << "1-balses" << endl;
    cout << "2-maziausiai bedras daliklis" << endl;
    cout << "3-zaidimas" << endl;
    cout << "4-fizzbuzz" << endl;

        do {
            cout << "Pasirinkite funkcija" << endl;
            cin >> pasirinkimas;

            switch (pasirinkimas) {
                case 1:
                    Balsiu_palyginimas();
                break;
                case 2:
                    Maziausias_bendras_daliklis();
                break;
                case 3:
                    Zaidimas();
                break;
                case 4:
                    fizzBuzz();
                break;
                default:
                    cout << "Neteisingas pasirinkimas. Bandykite dar karta." << endl;
            }
        } while (pasirinkimas != 0);
        return 0;
    }


