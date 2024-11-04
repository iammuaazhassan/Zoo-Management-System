#include "Animal.h"
#include <iostream>
#include "Animal_health.h"
#include "date.h"
#include <string>
#include <windows.h>
#include <fstream>
#include <sstream>
using namespace std;

Animal::Animal(string i, string n, int o, int c, char gen, int a, float w, string gr)
{
    this->set_id(i);
    this->set_name(n);
    this->set_offs(o);
    this->set_cellid(c);
    this->set_gen(gen);
    this->set_age(a);
    this->set_weight(w);
    this->set_group(gr);
}

Animal::~Animal()
{
    // Destructor
}

Animal::Animal(Animal& other)
{
    this->set_id(other.get_id());
    this->set_name(other.get_name());
    this->set_offs(other.get_offs());
    this->set_cellid(other.get_cellid());
    this->set_gen(other.get_gen());
    this->set_age(other.get_age());
    this->set_weight(other.get_weight());
    this->set_group(other.get_group());
}

void Animal::set_id(string i)
{
    id = i;
}

string Animal::get_id()
{
    return id;
}

void Animal::set_name(string n)
{
    name = n;
}

string Animal::get_name()
{
    return name;
}

void Animal::set_offs(int o)
{
    off_spring = o;
}

int Animal::get_offs()
{
    return off_spring;
}

void Animal::set_cellid(int c)
{
    cell_id = c;
}

int Animal::get_cellid()
{
    return cell_id;
}

void Animal::set_gen(char g)
{
    gender = g;
}

char Animal::get_gen()
{
    return gender;
}

void Animal::set_age(int a)
{
    age = a;
}

int Animal::get_age()
{
    return age;
}

void Animal::set_weight(float w)
{
    weight = w;
}

float Animal::get_weight()
{
    return weight;
}

void Animal::set_group(string g)
{
    group = g;
}

string Animal::get_group()
{
    return group;
}

void destroy_records(Animal* animals[], int m)
{
    for (int i = 0; i < m; i++) {
        if (animals[i] != nullptr) {
            delete animals[i];
            animals[i] = nullptr;
        }
    }
    cout << "All records destroyed." << endl;
}

void add_animal(Animal* animals[], int a, int& count)
{
    string id, name, group, status, keeper, diet, category, supply;
    int off_spring, cell_id, age;
    float weight;
    char gender;

    cout << "Enter animal ID: ";
    cin.ignore();
    getline(cin, id);
    cout << "Enter animal name: ";
    getline(cin, name);
    cout << "Enter number of offsprings: ";
    cin >> off_spring;
    cout << "Enter cell ID: ";
    cin >> cell_id;
    cout << "Enter gender (M/F): ";
    cin >> gender;
    cout << "Enter animal age: ";
    cin >> age;
    cout << "Enter weight: ";
    cin >> weight;
    cout << "Enter animal group: ";
    cin.ignore();
    getline(cin, group);
    cout << "Enter animal health status: ";
    getline(cin, status);
    cout << "Enter animal caretaker name: ";
    getline(cin, keeper);
    cout << "Enter animal diet: ";
    getline(cin, diet);
    cout << "Enter animal category: ";
    getline(cin, category);
    cout << "Food supply: ";
    getline(cin, supply);

    animals[a] = new Animal_health(id, name, off_spring, cell_id, gender, age, weight, group, status, keeper, diet, category, supply);
    count++;
}

void delete_animal(Animal* animal[], int max, string id, int& count)
{
    for (int i = 0; i < count; ++i) {
        if (animal[i]->get_id() == id) {
            delete animal[i];
            for (int j = i; j < max - 1; j++) {
                animal[j] = animal[j + 1];
            }
            count--;
            break;
        }
    }
}

void find_animal(Animal* animal[], int max, string id)
{
    for (int i = 0; i < max; i++) {
        if (animal[i]->get_id() == id) {
            cout << "Animal found." << endl;
            cout << "Name: " << animal[i]->get_name() << " ID: " << animal[i]->get_id() << endl;
            cout << endl;
            break;
        } else {
            cout << "Not found." << endl;
        }
    }
}

int sick_frequency(Animal* animal[], int max)
{
    int s = 0;
    for (int z = 0; z < max; z++) {
        if (animal[z]->isSick()) {
            s++;
        }
    }
    return s;
}

int born_between_dates(Animal* animal[], int max, date& gt)
{
    int n = 0;
    SYSTEMTIME currentTime;
    GetSystemTime(&currentTime);
    int y = currentTime.wYear;
    int m = currentTime.wMonth;
    int d = currentTime.wDay;
    date current;
    current.set_date(d, m, y);
    for (int z = 0; z < max; z++) {
        if (animal[z]->between_dates(current, gt)) {
            n++;
        }
    }
    return n;
}

string Animal::get_animal_data()
{
    string data = this->get_id() + "," + this->get_name() + "," + to_string(this->get_offs()) + "," + to_string(this->get_cellid()) + "," +
                    this->get_gen() + "," + to_string(this->get_age()) + "," + to_string(this->get_weight()) + "," + this->get_group();

    return data;
}

void save_data_to_file(Animal* animals[], int count)
 {
    ofstream file("animals.txt");
    if (file.is_open()) {
        for (int i = 0; i < count; i++) {
            file << animals[i]->get_animal_data() << endl;
        }
        file.close();
        cout << "Animal data saved to file." << endl;
    } else {
        cout << "Error opening file." << endl;
    }
}

void load_data_from_file(Animal* animals[],int count)
 {
    ifstream file("animals.txt");
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            Animal* animal = create_animal_from_data(line);
            if (animal != nullptr) {
                animals[count++] = animal;
            }
        }
        file.close();
        cout << "Animal data loaded from file." << endl;
    } else {
        cout << "Error opening file." << endl;
    }
}

Animal* create_animal_from_data(const string& data) {

    istringstream iss(data);
    string id, name, group, status, keeper, diet, category, supply, past_habitat, species, area, location;
    int off_spring, cell_id, age;
    float weight;
    char gender;
    int day, month, year;
    iss >> id >> name >> off_spring >> cell_id >> gender >> age>> weight >> group >> status >> keeper >> diet >> category
                    >> supply>> past_habitat >> species >> day >> month >> year >> area >> location;
    date date1;
    date1.set_date(day,month,year);
    Animal_health* animal = new Animal_health(id, name, off_spring, cell_id, gender, age,weight, group, status, keeper, diet, category,
                                              supply, past_habitat, species, date1, area, location);

    return animal;
}
