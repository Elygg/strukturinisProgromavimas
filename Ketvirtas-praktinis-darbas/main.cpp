#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
using namespace std;


struct menuItemType
{
    string menuItem;  // Patiekalas (pavadinimas)
    double menuPrice; // Kaina (su dviem skaitmenimis po kablelio)
};

const int MENU_SIZE = 8;


void getData(menuItemType menuList[])
{
    menuList[0].menuItem = "Kiausiniene";
    menuList[0].menuPrice = 1.45;

    menuList[1].menuItem = "Kiaulienos sonine su keptu kiausiniu";
    menuList[1].menuPrice = 2.45;

    menuList[2].menuItem = "Keksiukas su vysnia";
    menuList[2].menuPrice = 0.99;

    menuList[3].menuItem = "Prancuziskas skrebutis";
    menuList[3].menuPrice = 1.99;

    menuList[4].menuItem = "Vaisiu salotos";
    menuList[4].menuPrice = 2.49;

    menuList[5].menuItem = "Pusryčiu dribsniai";
    menuList[5].menuPrice = 0.69;

    menuList[6].menuItem = "Kava";
    menuList[6].menuPrice = 0.50;

    menuList[7].menuItem = "Arbata";
    menuList[7].menuPrice = 0.75;
}


void showMenu(const menuItemType menuList[])
{
    cout << "----------------------------------------" << endl;
    cout << "           Pusryciu MENIU" << endl;
    cout << "----------------------------------------" << endl;
    for(int i = 0; i < MENU_SIZE; i++)
    {

        cout << i + 1 << ". "
             << left << setw(36) << menuList[i].menuItem
             << fixed << setprecision(2) << menuList[i].menuPrice << "Eur." << endl;
    }
    cout << "----------------------------------------" << endl;
    cout << "Jei norite uzsisakyti, iveskite patiekalo numeri ir kieki.\n";
    cout << "Norddami baigti uzsakyma, iveskite 0 0." << endl;
    cout << "Pvz.: \"1 2\" reiskia patiekalo Nr.1 dvi porcijas." << endl;
    cout << "----------------------------------------" << endl << endl;
}


void printCheck(const menuItemType menuList[], const int quantityList[])
{
    double subTotal = 0.0;
    for(int i = 0; i < MENU_SIZE; i++)
    {
        if(quantityList[i] > 0)
        {
            subTotal += menuList[i].menuPrice * quantityList[i];
        }
    }


    double tax = subTotal * 0.21;
    double total = subTotal + tax;


    cout << endl;
    cout << "----------------------------------------" << endl;
    cout << "Sveiki atvyke i restorana „Brukne“" << endl << endl;


    for(int i = 0; i < MENU_SIZE; i++)
    {
        if(quantityList[i] > 0)
        {
            cout << quantityList[i] << " "
                 << left << setw(36) << menuList[i].menuItem
                 << fixed << setprecision(2) << menuList[i].menuPrice << "Eur." << endl;
        }
    }


    cout << endl;
    cout << left << setw(36) << "Mokesciai"
         << fixed << setprecision(2) << tax << "Eur." << endl;
    cout << left << setw(36) << "Galutine suma"
         << fixed << setprecision(2) << total << "Eur." << endl;
    cout << "----------------------------------------" << endl;


    ofstream outFile("cekis.txt");
    if(outFile.is_open())
    {
        outFile << "Sveiki atvykę i restorana „Brukne“\n\n";
        for(int i = 0; i < MENU_SIZE; i++)
        {
            if(quantityList[i] > 0)
            {
                outFile << quantityList[i] << " "
                        << left << setw(36) << menuList[i].menuItem
                        << fixed << setprecision(2) << menuList[i].menuPrice << "Eur.\n";
            }
        }
        outFile << "\n"
                << left << setw(36) << "Mokesčiai"
                << fixed << setprecision(2) << tax << "Eur.\n"
                << left << setw(36) << "Galutinė suma"
                << fixed << setprecision(2) << total << "Eur.\n";
        outFile.close();
    }
    else
    {
        cerr << "Nepavyko atidaryti failo sąskaitos irasymui.\n";
    }
}

int main()
{

    menuItemType menuList[MENU_SIZE];
    getData(menuList);


    showMenu(menuList);


    int quantityList[MENU_SIZE] = {0};

    while(true)
    {
        int choice, quantity;
        cout << "Jusu pasirinkimas (numeris kiekis): ";
        cin >> choice >> quantity;


        if(choice == 0 && quantity == 0)
        {
            break;
        }


        if(choice >= 1 && choice <= MENU_SIZE && quantity > 0)
        {

            quantityList[choice - 1] += quantity;
        }
        else
        {
            cout << "Neteisingas ivedimas. Bandykite dar karta.\n";
        }
    }

    printCheck(menuList, quantityList);

    return 0;
}
