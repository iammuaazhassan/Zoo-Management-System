#include <iostream>
#include "Animal.h"
#include "Animal_health.h"
#include "date.h"
#include <string.h>
#include <fstream>
#include <sstream>

using namespace std;

int main()
{
    int MAX_ANIMALS = 100;
    int animal_count = 0;
    int choice, age, day, month, year;
    char gender;
    string id, name, group, status, keeper, diet, category, supply, past_habitat, species, area, location;
    date given_date;
    Animal* animals[MAX_ANIMALS];
    // Create some initial animals
    animals[0] = new Animal_health("lim4_1", "Lion", 2, 1, 'M', 5, 10.0, "Mammal",
                                   "Sick", "Ahmed", "Meat", "Carnivore", "Adequate",
                                   "Kenya", "Endangered", date(1, 1, 2022), "Lion Enclosure", "Zone A");
    animal_count++;
    animals[1] = new Animal_health("ele4_2", "Elephant", 3, 2, 'F', 4, 12.5, "Mammal",
                                   "Fit", "Salman", "Diet 2", "Herbivore", "Low",
                                   "Srilanka", "Common", date(2, 2, 2023), "Elephant Enclosure", "Zone B");
    animal_count++;
    animals[2] = new Animal_health("tig4_3", "Tiger", 1, 3, 'M', 6, 15.0, "Mammal",
                                   "Fit", "Umer", "Meat", "Carnivore", "Low",
                                   "Nepal", "Endangered", date(3, 3, 2021), "Tiger Enclosure", "Zone C");
    animal_count++;
    animals[3] = new Animal_health("gir4_4", "Giraffe", 2, 4, 'F', 3, 9.5, "Mammal",
                                   "Fit", "Ali", "Leave", "Herbivore", "Adequate",
                                   "Namibia", "Common", date(4, 4, 2020), "Giraffe Enclosure", "Zone D");
    animal_count++;
    animals[4] = new Animal_health("zeb4_5", "Zebra", 3, 5, 'M', 4, 11.0, "Mammal",
                                   "Sick", "Ahmed", "Grass", "Herbivore", "Low",
                                   "Zambia", "Endangered", date(5, 5, 2019), "Zebra Enclosure", "Zone E");
    animal_count++;

    load_data_from_file(animals,animal_count);

    do {//do while loop for displaying options
        cout << "========= MENU =========" << endl;
        cout << "1. Add animal." << endl;
        cout << "2. Delete animal through ID." << endl;
        cout << "3. Find animal through ID." << endl;
        cout << "4. Find animals within a particular location." << endl;
        cout << "5. List of animals of category, keeper, and dietary conditions." << endl;
        cout << "6. List of sick animals of certain category, age, gender, location and between today and any date." << endl;
        cout << "7. Frequency of animals reported sick." << endl;
        cout << "8. Number of animals born between today and a given date." << endl;
        cout << "9. Destroy all records for animals." << endl;
        cout << "10. Exit" << endl;
        cout << "========================" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                // Add animal
                add_animal(animals, MAX_ANIMALS, animal_count);
                break;
            case 2:
                // Delete animal through ID
                cout << "Enter id to delete animal: ";
                cin.ignore();
                getline(cin, id);
                delete_animal(animals, MAX_ANIMALS, id, animal_count);
                break;
            case 3:
                // Find animal through ID
                cout << "Enter id to find: ";
                cin.ignore();
                getline(cin, id);
                find_animal(animals, MAX_ANIMALS, id);
                break;
            case 4:
                // Find animals within a particular location
                cout << "Enter location: ";
                cin.ignore();
                getline(cin, location);
                for (int z = 0; z < MAX_ANIMALS; z++) {
                    animals[z]->display_animal(location);
                }
                break;
            case 5:
                // List of animals of category, keeper, and dietary conditions
                int ch;
                cout << "Menu:" << endl;
                cout << "1. Display all animals of a certain category." << endl;
                cout << "2. Display all animals under a certain caretaker." << endl;
                cout << "3. Display all animals with a certain diet." << endl;
                cout << "4. Display animals that match all of the above criteria." << endl;
                cout << "5. Exit (for any other number)." << endl;
                do {
                    cout << "Enter your choice: ";
                    cin >> ch;
                    switch (ch) {
                        case 1:
                            // Display all animals of a certain category
                            cout << "Enter category: ";
                            cin.ignore();
                            getline(cin, category);
                            for (int z = 0; z < MAX_ANIMALS; z++) {
                                animals[z]->categorised_display(category);
                            }
                            break;
                        case 2:
                            // Display all animals under a certain caretaker
                            cout << "Enter caretaker name: ";
                            cin.ignore();
                            getline(cin, keeper);
                            for (int z = 0; z < MAX_ANIMALS; z++) {
                                animals[z]->display_wrt_keeper(keeper);
                            }
                            break;
                        case 3:
                            // Display all animals with a certain diet
                            cout << "Enter diet: ";
                            cin.ignore();
                            getline(cin, diet);
                            for (int z = 0; z < MAX_ANIMALS; z++) {
                                animals[z]->display_wrt_diet(diet);
                            }
                            break;
                        case 4:
                            // Display animals that match all of the above criteria
                            cout << "Enter category: ";
                            cin.ignore();
                            getline(cin, category);
                            cout << "Enter caretaker name: ";
                            cin.ignore();
                            getline(cin, keeper);
                            cout << "Enter diet: ";
                            cin.ignore();
                            getline(cin, diet);
                            for (int z = 0; z < MAX_ANIMALS; z++) {
                                animals[z]->detailed_display(category, keeper, diet);
                            }
                            break;
                        default:
                            break;
                    }
                } while (ch > 0 && ch < 5);
                break;
            case 6:
                // List of sick animals of certain category, age, gender, location, and between today and any date
                int cho;
                cout << "1. Display sick animals by category" << endl;
                cout << "2. Display sick animals by age" << endl;
                cout << "3. Display sick animals by gender" << endl;
                cout << "4. Display sick animals by location" << endl;
                cout << "5. Display sick animals by date range" << endl;
                cout << "6. Exit" << endl;
                do {
                    cout << "Enter your choice: ";
                    cin >> cho;
                    switch(ch) {
                        case 1:
                            // Display sick animals by category
                            cout << "Enter category: ";
                            cin.ignore();
                            getline(cin, category);
                            for (int z = 0; z < MAX_ANIMALS; z++) {
                                animals[z]->sick_wrt_cat(category);
                            }
                            break;
                        case 2:
                            // Display sick animals by age
                            cout << "Enter animal age: ";
                            cin >> age;
                            for (int z = 0; z < MAX_ANIMALS; z++) {
                                animals[z]->sick_wrt_age(age);
                            }
                            break;
                        case 3:
                            // Display sick animals by gender
                            cout << "Enter animal gender (M, F): ";
                            cin >> gender;
                            for (int z = 0; z < MAX_ANIMALS; z++) {
                                animals[z]->sick_wrt_gender(gender);
                            }
                            break;
                        case 4:
                            // Display sick animals by location
                            cout << "Enter location: ";
                            cin.ignore();
                            getline(cin, location);
                            for (int z = 0; z < MAX_ANIMALS; z++) {
                                animals[z]->sick_wrt_location(location);
                            }
                            break;
                        case 5:
                            // Display sick animals by date range
                            cout << "Enter day, month, and year: ";
                            cin >> day >> month >> year;
                            given_date.set_date(day, month, year);
                            for (int z = 0; z < MAX_ANIMALS; z++) {
                                animals[z]->sick_wrt_date(given_date);
                            }
                            break;
                        default:
                            break;
                    }
                } while (cho > 0 && cho < 6);
                break;
            case 7:
                // Frequency of animals reported sick
                cout << "Number of sick animals: " << sick_frequency(animals, MAX_ANIMALS) << endl;
                break;
            case 8:
                 // Number of animals born between today and a given date
                cout << "Enter day, month, and year: ";
                cin >> day >> month >> year;
                given_date.set_date(day, month, year);
                cout << "Number of animals born between " << day << "-" << month << "-" << year;
                cout << " and today: " << born_between_dates(animals, MAX_ANIMALS, given_date) << endl;
                break;
            case 9:
                // Destroy all records for animals
                destroy_records(animals, MAX_ANIMALS);
                break;
                // Exit the program
            case 10:
                cout << "Program exited." << endl;
                break;
            default:
                cout << "Invalid Choice." << endl;
                break;
        }
        save_data_to_file(animals,animal_count);
    } while (choice!=10);

    return 0;
}
