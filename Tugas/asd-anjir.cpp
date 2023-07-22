#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

struct MenuItem {
    string name;
    int price;
};

bool compareMenuName(MenuItem a, MenuItem b) {
    transform(a.name.begin(), a.name.end(), a.name.begin(), ::tolower);
    transform(b.name.begin(), b.name.end(), b.name.begin(), ::tolower);
    return a.name < b.name;
}

bool compareMenuPrice(MenuItem a, MenuItem b) {
    return a.price < b.price;
}

int binarySearch(MenuItem arr[], int left, int right, string target) {
    transform(target.begin(), target.end(), target.begin(), ::tolower);
    while (left <= right) {
        int mid = left + (right - left) / 2;
        string currName = arr[mid].name;
        transform(currName.begin(), currName.end(), currName.begin(), ::tolower);
        int result = currName.compare(target);

        if (result == 0) {
            return mid;
        }

        if (result < 0) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return -1;
}

void displayMenu(MenuItem arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << "{\"" << arr[i].name << "\", " << arr[i].price << "}" << endl;
    }
}

void bubbleSort(MenuItem arr[], int n, bool byName, bool ascending) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (byName) {
                if (ascending) {
                    if (arr[j].name > arr[j + 1].name) {
                        swap(arr[j], arr[j + 1]);
                    }
                } else {
                    if (arr[j].name < arr[j + 1].name) {
                        swap(arr[j], arr[j + 1]);
                    }
                }
            } else {
                if (ascending) {
                    if (arr[j].price > arr[j + 1].price) {
                        swap(arr[j], arr[j + 1]);
                    }
                } else {
                    if (arr[j].price < arr[j + 1].price) {
                        swap(arr[j], arr[j + 1]);
                    }
                }
            }
        }
    }
}

int main() {
    const int numFood = 23;
    const int numDrink = 55;

    MenuItem foods[numFood] = {
        // Daftar menu makanan (Anda dapat menggantinya dengan daftar yang diberikan)
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
        {"Ajam Katsu Sebalik", 15000}
    };

    MenuItem drinks[numDrink] = {
        // Daftar menu minuman (Anda dapat menggantinya dengan daftar yang diberikan)
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
	    {"Strawberry Gato", 15000}
    };

    cout << "Program Sort dan Search Tibal Coffee\n\n";

    int choice;
    bool exitProgram = false;

    do {
        cout << "Menu:\n";
        cout << "1. Tampilkan Semua Menu\n";
        cout << "2. Cari Menu\n";
        cout << "3. Pengurutan Menu\n";
        cout << "4. Keluar\n";
        cout << "Masukkan pilihan: ";
        cin >> choice;

        switch (choice) {
        case 1:
            // Tampilkan menu makanan
            cout << "\nMenu Makanan:\n";
            displayMenu(foods, numFood);

            // Tampilkan menu minuman
            cout << "\nMenu Minuman:\n";
            displayMenu(drinks, numDrink);

            // Pilihan apakah ingin melanjutkan program atau tidak
            cout << "\nApakah ingin melanjutkan program? (Y/N): ";
            char continueProgram;
            cin >> continueProgram;
            if (continueProgram == 'N' || continueProgram == 'n') {
                exitProgram = true;
            }
            system("cls");
            break;

        case 2:
        	// Tampilkan menu makanan
            cout << "\nMenu Makanan:\n";
            displayMenu(foods, numFood);

            // Tampilkan menu minuman
            cout << "\nMenu Minuman:\n";
            displayMenu(drinks, numDrink);
            
            
            do {
                cout << "\nCari Makanan atau Minuman:\n";
                cout << "Masukkan pola pencarian: ";
                string pattern;
                cin.ignore();
                getline(cin, pattern);

                // Pencarian Makanan
                bool foodFound = false;
                for (int i = 0; i < numFood; i++) {
                    if (foods[i].name.find(pattern) != string::npos) {
                        cout << "Makanan '" << pattern << "' ditemukan: " << foods[i].name << " - Rp" << foods[i].price << endl;
                        foodFound = true;
                    }
                }

                // Pencarian Minuman
                bool drinkFound = false;
                for (int i = 0; i < numDrink; i++) {
                    if (drinks[i].name.find(pattern) != string::npos) {
                        cout << "Minuman '" << pattern << "' ditemukan: " << drinks[i].name << " - Rp" << drinks[i].price << endl;
                        drinkFound = true;
                    }
                }

                if (!foodFound && !drinkFound) {
                    cout << "Menu tidak ditemukan.\n";
                }

                // Pilihan apakah ingin mencari lagi atau tidak
                cout << "\nApakah ingin mencari lagi? (Y/N): ";
                char continueSearch;
                cin >> continueSearch;
                if (continueSearch == 'N' || continueSearch == 'n') {
                    cout << "\nKembali ke menu utama? (Y/N): ";
                    char backToMenu;
                    cin >> backToMenu;
                    if (backToMenu == 'Y' || backToMenu == 'y') {
                    	system("cls");
                        break;
                    } else {
                        cout << "Terima kasih telah menggunakan program ini";
                        exitProgram = true;
                        break;
                    }
                }
            } while (true);
            break;

        case 3:
            do {
                cout << "\nPengurutan Menu:\n";
                cout << "1. Makanan\n";
                cout << "2. Minuman\n";
                cout << "3. Semua\n";
                cout << "Masukkan pilihan: ";
                int sortChoice;
                cin >> sortChoice;

                if (sortChoice == 1) {
                    // Pengurutan Makanan
                    cout << "\nPilihan pengurutan:\n";
                    cout << "1. Berdasarkan Nama\n";
                    cout << "2. Berdasarkan Harga\n";
                    cout << "Masukkan pilihan: ";
                    int sortOption;
                    cin >> sortOption;

                    bool byName = (sortOption == 1);
                    bool ascending;

                    cout << "\nPilihan pengurutan:\n";
                    cout << "1. Ascending\n";
                    cout << "2. Descending\n";
                    cout << "Masukkan pilihan: ";
                    int sortType;
                    cin >> sortType;

                    ascending = (sortType == 1);

                    bubbleSort(foods, numFood, byName, ascending);

                    cout << "\nMakanan setelah diurutkan:\n";
                    displayMenu(foods, numFood);
                } else if (sortChoice == 2) {
                    // Pengurutan Minuman
                    cout << "\nPilihan pengurutan:\n";
                    cout << "1. Berdasarkan Nama\n";
                    cout << "2. Berdasarkan Harga\n";
                    cout << "Masukkan pilihan: ";
                    int sortOption;
                    cin >> sortOption;

                    bool byName = (sortOption == 1);
                    bool ascending;

                    cout << "\nPilihan pengurutan:\n";
                    cout << "1. Ascending\n";
                    cout << "2. Descending\n";
                    cout << "Masukkan pilihan: ";
                    int sortType;
                    cin >> sortType;

                    ascending = (sortType == 1);

                    bubbleSort(drinks, numDrink, byName, ascending);

                    cout << "\nMinuman setelah diurutkan:\n";
                    displayMenu(drinks, numDrink);
                } else if (sortChoice == 3) {
                    // Pengurutan Semua Menu
                    cout << "\nPilihan pengurutan:\n";
                    cout << "1. Berdasarkan Nama\n";
                    cout << "2. Berdasarkan Harga\n";
                    cout << "Masukkan pilihan: ";
                    int sortOption;
                    cin >> sortOption;

                    bool byName = (sortOption == 1);
                    bool ascending;

                    cout << "\nPilihan pengurutan:\n";
                    cout << "1. Ascending\n";
                    cout << "2. Descending\n";
                    cout << "Masukkan pilihan: ";
                    int sortType;
                    cin >> sortType;

                    ascending = (sortType == 1);

                    bubbleSort(foods, numFood, byName, ascending);
                    bubbleSort(drinks, numDrink, byName, ascending);

                    cout << "\nMakanan setelah diurutkan:\n";
                    displayMenu(foods, numFood);
                    cout << "\nMinuman setelah diurutkan:\n";
                    displayMenu(drinks, numDrink);
                } else {
                    cout << "Pilihan tidak valid.\n";
                }

                // Pilihan apakah ingin menggunakan kembali atau tidak
                cout << "\nApakah ingin menggunakan kembali? (Y/N): ";
                char continueSort;
                cin >> continueSort;
                if (continueSort == 'N' || continueSort == 'n') {
                    cout << "\nKembali ke menu utama? (Y/N): ";
                    char backToMenu;
                    cin >> backToMenu;
                    if (backToMenu == 'Y' || backToMenu == 'y') {
                        system("cls");
                        break;
                    } else {
                        cout << "Terima kasih telah menggunakan program ini.\n";
                        exitProgram = true;
                        break;
                    }
                } 
            } while (true);
            break;

        case 4:
            cout << "Terima kasih telah menggunakan program ini.\n";
            exitProgram = true;
            break;

        default:
            cout << "Pilihan tidak valid. Silakan pilih lagi";
        }
        
        // Jika user memilih 'N' pada pilihan, langsung keluar dari program
        if (exitProgram) {
            break;
        }
        
    } while (true);

    return 0;
}

