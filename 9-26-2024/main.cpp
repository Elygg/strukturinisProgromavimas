#include <iostream>
using namespace std;


int sumOfDigits(int number) {
    // Patikriname, ar skaičius yra dviejų skaitmenų
    if (number < 10 || number > 99) {
        cout << "Skaičius turi būti dviejų skaitmenų." << endl;
        return -1;
    }

    // Apskaičiuojame dešimtis ir vienetus
    int tens = number / 10;     // Dešimtys
    int ones = number % 10;     // Vienetai

    return tens + ones;
}
int sanOfDigits(int number) {
    // Patikriname, ar skaičius yra dviejų skaitmenų
    if (number < 10 || number > 99) {
        cout << "Skaicius turi buti dvieju skaitmenu." << endl;
        return -1;
    }

    // Apskaičiuojame dešimtis ir vienetus
    int tens = number / 10;     // Dešimtys
    int ones = number % 10;     // Vienetai

    return tens * ones;
}

int main() {
    int number;

    cout << "Iveskite dvieju skaitmenu skaiciu: ";
    cin >> number;

    int sum = sumOfDigits(number);
    int san = sanOfDigits(number);

    if (sum != -1) {
        cout << "Skaitmenu suma: " << sum << endl;
    }
    if (san != -1) {
        cout << "Skaitemenu sandauga:" << san << endl;
    }


    return 0;
}