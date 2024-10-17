#include <iostream>
#include <string>
using namespace std;


bool Balsiu_palyginimas() {
    string balses[] = {"a", "ą", "e", "ę", "ė",  "i", "į", "y", "o", "u", "ų", "ū", };

    string ivedimas;

    cout << "iveskite betokia raide" << endl;
    cin >> ivedimas;
    // ziuri ar yra balse
    for(int i = 0; i < 12; i++) {
        if(balses[i] == ivedimas) {
            cout << "balse" << endl;
            return true;
        }
    }

    cout << "nebalse" << endl;

    return  false;
}

void Maziausias_bendras_daliklis() {
    int skaicius1;
    int skaicius2;

    int dbd;
    cout << "iveskite pirma skaiciu" << endl;
    cin >> skaicius1;
    cout << "iveskite antra skaiciu" << endl;
    cin >> skaicius2;

    while (abs(skaicius1) &&  abs(skaicius2))
        if (abs(skaicius1) > abs(skaicius2)) skaicius1 %= skaicius2;
            else skaicius2 %= skaicius1;
    dbd = skaicius1 + skaicius2;

    cout << "didziausias bendras daliklis " << dbd << endl;

    }

void Zaidimas() {
    srand(time(0));
    int randomNumber = rand() % 101;
    int spejimas;

    cout << "iveskite spejima" << endl;
    cout << randomNumber << endl;
    cin >> spejimas;
    //lygina ar spejimas lygus, mazesnis, didesnis
    while (randomNumber !=  spejimas ) {
        if(randomNumber < spejimas) {
            cout << "spejimas per didelis" << endl;
        }
        else if (randomNumber > spejimas) {
            cout << "spejimas per mazas" << endl;
        }

        cout << "iveskite spejima is naujo" << endl;
        cin >> spejimas;
        }
        {
            cout << "spejimas lygus" << endl;
        }
    }



    void fizzBuzz(int n) {
    cout << "iveskite teigiama sveika skaiciu" << endl;
    cin >> n;

    // tikrina ar skaicius teigiamas
    if (n <= 0) {
        cout << "prasome ivesti teigiama skaiciu";
        cin >>n;
    }

    for (int i = 1; i <= n; i++) {
        if (i % 3 == 0 && i % 5 == 0) {
            cout << "FizzBuzz " << endl; //ar dalinasi is 3 ir 5
        }
        else if (i % 5 == 0) {
            cout << "Buzz " << endl; // ar dalinasi is 5
        }
        else if (i % 3 == 0) {
            cout << "Fizz " << endl; // ar dalinasi is 3
        }
        else {
            cout << i << endl;
        }
    }
}



    int main() {
    int pasirinkimas;
    int n;
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
                    fizzBuzz(n);
                break;
                default:
                    cout << "Neteisingas pasirinkimas. Bandykite dar karta." << endl;
            }
        } while (pasirinkimas != 0);
        return 0;
    }


