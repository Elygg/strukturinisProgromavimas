#include <iostream>

using namespace std;


void Balsiu_palyginimas (){
}

void Maziausias_bendras_daliklis () {

}

void Zaidimas() {

}

void fizzBuzz() {

}




int main()
{
    int pasirinkimas;

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
