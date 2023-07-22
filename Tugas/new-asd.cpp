#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int choice, sortChoice, sortOption, sortType;
bool exitProgram = false;
struct MenuItem
{
    string name;
    int price;
};

void showMenuProgram(), showMenu(), choiceMenu(), sortingMenu(), showMenuSorting(), showMenuSortingOption(), showMenuSortingType();
void displayMenu(MenuItem arr[], int n);
void bubbleSort(MenuItem arr[], int n, bool byName, bool ascending);

const int sizeFood = 23;
const int sizeDrink = 55;
MenuItem foods[sizeFood] = {
    {"Rambut Nenek", 6000},
    {"Klapertaart", 8000},
    {"Brownies Loomer", 8000},
    {"Banana Bread", 10000},
    {"Fruit Sando", 10000},
    {"Kerupuk Sambel", 8000},
    {"Risol Mayo", 10000},
    {"Cireng", 10000},
    {"Onion Ring", 10000},
    {"French Fries", 10000},
    {"Pao-pao", 10000},
    {"Siomay Kukus/Goreng", 10000},
    {"Brokoli Krispi", 12000},
    {"Banana Roll", 12000},
    {"Tahu Tuna", 10000},
    {"Moza Stick", 12000},
    {"Sweetie Croffle", 15000},
    {"Tastie Croffle", 15000},
    {"Mie Tibal", 10000},
    {"Nasi Kulit", 15000},
    {"Nasi Ajam Sebail", 15000},
    {"Ajam Katsu Setitik", 15000},
    {"Ajam Katsu Sebalik", 15000}};
MenuItem drinks[sizeDrink] = {
    {"Chocolade Ijs-Koekjis", 18000},
    {"Witte Ijs-Koekjis", 18000},
    {"Es Meneer", 18000},
    {"The Supernova", 18000},
    {"Es Merdeka", 18000},
    {"Matchapresso", 18000},
    {"Sugar Cane Coffee", 18000},
    {"Coffee Gear", 18000},
    {"Red Postion", 18000},
    {"Bon-bon(hot)", 13000},
    {"Bon-bon(ice)", 15000},
    {"Latte(hot)", 15000},
    {"Latte(ice)", 15000},
    {"Mochacino(hot)", 15000},
    {"Mochacino(ice)", 15000},
    {"Black Latte(hot)", 15000},
    {"Affogato(ice)", 18000},
    {"Es Kopsu Setitik", 15000},
    {"Es Kopsu Sebalik", 15000},
    {"Es Kopsu Rare", 15000},
    {"Es Kopsu Merah", 15000},
    {"Es Kopsu Kuning", 15000},
    {"Es Kopsu Hijau", 15000},
    {"Es Kopsu Hitam Putih", 15000},
    {"Es Kopsu Kotak", 15000},
    {"Es Kopsu Witte-Koekjis", 15000},
    {"Black Tea(hot)", 10000},
    {"Black Tea(ice)", 10000},
    {"Lychee Tea(hot)", 12000},
    {"Lychee Tea(ice)", 12000},
    {"Strawberry Tea(ice)", 15000},
    {"Blue Butterfly(hot)", 13000},
    {"Red Blanc(hot)", 13000},
    {"Footloose(hot)", 13000},
    {"Thaitea Dititik(ice)", 15000},
    {"Taro(hot)", 13000},
    {"Taro(ice)", 15000},
    {"Matcha(hot)", 13000},
    {"Matcha(ice)", 15000},
    {"Red Velvet(hot)", 13000},
    {"Red Velvet(ice)", 15000},
    {"Choco Berry(hot)", 13000},
    {"Choco Berry(ice)", 15000},
    {"Milky Oreo(ice)", 15000},
    {"The Klepon(ice)", 15000},
    {"Yakult Leci", 15000},
    {"Yakult Melon", 15000},
    {"Yakult Strawberry", 15000},
    {"Whitte Squash", 15000},
    {"Red Squash", 15000},
    {"Fresh Sour Squash", 15000},
    {"Choco Gato", 15000},
    {"Matcha Gato", 15000},
    {"Milo Gato", 15000},
    {"Strawberry Gato", 15000}};

int main()
{
    showMenuProgram();
    choiceMenu();
    return 0;
}

// todo - Function Tampilan Menu
void showMenuProgram()
{
    cout << "Menu:\n";
    cout << "1. Tampilkan Semua Menu\n";
    cout << "2. Cari Menu\n";
    cout << "3. Pengurutan Menu\n";
    cout << "4. Keluar\n";
    cout << "Masukkan pilihan: ";
    while (!(cin >> choice))
    {
        cout << "\n400_ERR_INVALID_INPUT!" << endl;
        cout << "\nMasukkan Ulang Pilihan! : ";
        cin.clear();
        cin.ignore(123, '\n');
    }
}

void choiceMenu()
{
    switch (choice)
    {
    case 1:
        showMenu();
        break;
    case 2:
        showMenu();
        break;
    case 3:
        sortingMenu();
        break;
    case 4:
        showMenu();
        break;
    default:
        cout << "Pilihan Tidak Tersedia" << endl;
        break;
    }
}

void showMenu()
{
    cout << "\nMenu Makanan:\n";
    displayMenu(foods, sizeFood);

    cout << "\nMenu Minuman:\n";
    displayMenu(drinks, sizeDrink);
}



void showMenuSorting()
{
    cout << "\nPengurutan Menu:\n";
    cout << "1. Makanan\n";
    cout << "2. Minuman\n";
    cout << "3. Semua\n";
    cout << "Masukkan pilihan: ";
    while (!(cin >> sortChoice))
    {
        cout << "\n400_ERR_INVALID_INPUT!" << endl;
        cout << "\nMasukkan Ulang Pilihan! : ";
        cin.clear();
        cin.ignore(123, '\n');
    }
}
void showMenuSortingOption()
{
    cout << "\nPilihan pengurutan:\n";
    cout << "1. Berdasarkan Nama\n";
    cout << "2. Berdasarkan Harga\n";
    cout << "Masukkan pilihan: ";
    while (!(cin >> sortOption))
    {
        cout << "\n400_ERR_INVALID_INPUT!" << endl;
        cout << "\nMasukkan Ulang Pilihan! : ";
        cin.clear();
        cin.ignore(123, '\n');
    }
}
void showMenuSortingType()
{
    cout << "\nPilihan pengurutan:\n";
    cout << "1. Ascending\n";
    cout << "2. Descending\n";
    cout << "Masukkan pilihan: ";
    while (!(cin >> sortType))
    {
        cout << "\n400_ERR_INVALID_INPUT!" << endl;
        cout << "\nMasukkan Ulang Pilihan! : ";
        cin.clear();
        cin.ignore(123, '\n');
    }
}


// todo - Function Algoritma
void sortingMenu()
{
    showMenuSorting();

    if (sortChoice == 1)
    {
        // Pengurutan Makanan
        showMenuSortingOption();

        bool byName = (sortOption == 1);
        bool ascending;

        showMenuSortingType();

        ascending = (sortType == 1);

        bubbleSort(foods, sizeFood, byName, ascending);

        cout << "\nMakanan setelah diurutkan:\n";
        displayMenu(foods, sizeFood);
    }
    else if (sortChoice == 2)
    {
        // Pengurutan Minuman
        showMenuSortingOption();

        bool byName = (sortOption == 1);
        bool ascending;

        showMenuSortingType();

        ascending = (sortType == 1);

        bubbleSort(drinks, sizeDrink, byName, ascending);

        cout << "\nMinuman setelah diurutkan:\n";
        displayMenu(drinks, sizeDrink);
    }
    else if (sortChoice == 3)
    {
        // Pengurutan Semua Menu
        showMenuSortingOption();

        bool byName = (sortOption == 1);
        bool ascending;

        showMenuSortingType();

        ascending = (sortType == 1);

        bubbleSort(foods, sizeFood, byName, ascending);
        bubbleSort(drinks, sizeDrink, byName, ascending);

        cout << "\nMakanan setelah diurutkan:\n";
        displayMenu(foods, sizeFood);
        cout << "\nMinuman setelah diurutkan:\n";
        displayMenu(drinks, sizeDrink);
    }
    else
    {
        cout << "Pilihan tidak valid.\n";
    }
}

void bubbleSort(MenuItem arr[], int n, bool byName, bool ascending)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (byName)
            {
                if (ascending)
                {
                    if (arr[j].name > arr[j + 1].name)
                    {
                        swap(arr[j], arr[j + 1]);
                    }
                }
                else
                {
                    if (arr[j].name < arr[j + 1].name)
                    {
                        swap(arr[j], arr[j + 1]);
                    }
                }
            }
            else
            {
                if (ascending)
                {
                    if (arr[j].price > arr[j + 1].price)
                    {
                        swap(arr[j], arr[j + 1]);
                    }
                }
                else
                {
                    if (arr[j].price < arr[j + 1].price)
                    {
                        swap(arr[j], arr[j + 1]);
                    }
                }
            }
        }
    }
}

void displayMenu(MenuItem arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "{\"" << arr[i].name << "\", " << arr[i].price << "}" << endl;
    }
}