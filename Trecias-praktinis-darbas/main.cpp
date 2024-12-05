#include <iostream>
#include <string>
using namespace std;

const char abecele[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
                        'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
const int abeceles_dydis = sizeof(abecele) / sizeof(abecele[0]);

int rasti_raides_pozicija(char raide) {
    for (int i = 0; i < abeceles_dydis; i++) {
        if (abecele[i] == raide) {
            return i;
        }
    }
    return -1;
}

string sifravimas_abeceles_pagrindu(const string& text, const string& key) {
    string encrypted_text = "";
    int key_length = key.length();
    int key_index = 0;

    for (char c : text) {
        if (isalpha(c)) {
            char upper_c = toupper(c);
            char upper_key = toupper(key[key_index]);

            int text_position = rasti_raides_pozicija(upper_c);
            int key_position = rasti_raides_pozicija(upper_key);

            if (text_position != -1 && key_position != -1) {
                int new_position = (text_position + key_position) % abeceles_dydis;
                encrypted_text += abecele[new_position];
                key_index = (key_index + 1) % key_length;
            }
        } else {
            encrypted_text += c;
        }
    }

    return encrypted_text;
}

string desifravimas_abeceles_pagrindu(const string& text, const string& key) {
    string decrypted_text = "";
    int key_length = key.length();
    int key_index = 0;

    for (char c : text) {
        if (isalpha(c)) {
            char upper_c = toupper(c);
            char upper_key = toupper(key[key_index]);

            int text_position = rasti_raides_pozicija(upper_c);
            int key_position = rasti_raides_pozicija(upper_key);

            if (text_position != -1 && key_position != -1) {
                int new_position = (text_position - key_position + abeceles_dydis) % abeceles_dydis;
                decrypted_text += abecele[new_position];
                key_index = (key_index + 1) % key_length;
            }
        } else {
            decrypted_text += c;
        }
    }

    return decrypted_text;
}

string sifravimas_ascii(const string& text, const string& key) {
    string encrypted_text = "";
    int key_length = key.length();
    int key_index = 0;

    for (char c : text) {
        char encrypted_char = c + (key[key_index] - '0');
        encrypted_text += encrypted_char;
        key_index = (key_index + 1) % key_length;
    }

    return encrypted_text;
}

string desifravimas_ascii(const string& text, const string& key) {
    string decrypted_text = "";
    int key_length = key.length();
    int key_index = 0;

    for (char c : text) {
        char decrypted_char = c - (key[key_index] - '0');
        decrypted_text += decrypted_char;
        key_index = (key_index + 1) % key_length;
    }

    return decrypted_text;
}

int main() {
    while (true) {
        cout << "\nVigenere algoritmo sistema\n";
        cout << "1. Sifruoti naudojant angliska abecele\n";
        cout << "2. Sifruoti naudojant ASCII koduote\n";
        cout << "3. Desifruoti naudojant angliska abecele\n";
        cout << "4. Desifruoti naudojant ASCII koduote\n";
        cout << "5. Iseiti\n";
        cout << "Pasirinkite veiksma (1-5): ";

        int pasirinkimas;
        cin >> pasirinkimas;
        cin.ignore(); // Išvalome įvesties buferį

        if (pasirinkimas == 5) {
            cout << "Programa baigta.\n";
            break;
        }

        string text, key;
        cout << "Iveskite teksta: ";
        getline(cin, text);
        cout << "Iveskite rakta: ";
        getline(cin, key);

        if (text.empty() || key.empty()) {
            cout << "Klaida: tekstas ir raktas negali būti tušti.\n";
            continue;
        }

        switch (pasirinkimas) {
            case 1:
                cout << "Uzsifruotas tekstas: " << sifravimas_abeceles_pagrindu(text, key) << endl;
                break;
            case 2:
                cout << "Uzsifruotas tekstas: " << sifravimas_ascii(text, key) << endl;
                break;
            case 3:
                cout << "Desifruotas tekstas: " << desifravimas_abeceles_pagrindu(text, key) << endl;
                break;
            case 4:
                cout << "Desifruotas tekstas: " << desifravimas_ascii(text, key) << endl;
                break;
            default:
                cout << "Neteisingas pasirinkimas.\n";
        }
    }

    return 0;
}
