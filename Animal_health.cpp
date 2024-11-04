#include "Animal_health.h"
#include <string>
#include "date.h"
#include <iostream>
#include <windows.h>

using namespace std;

Animal_health::Animal_health(string id, string name, int off_spring, int cell_id, char gender, int age, float weight, string group,
                             string sta, string k, string diet, string c, string sup,string h,string s,const date& d,string a,string l)
    : Animal(id, name, off_spring, cell_id, gender, age, weight, group)
{
    this->set_status(sta);
    this->set_keeper(k);
    this->set_diet(diet);
    this->set_cat(c);
    this->set_supply(sup);
    this->set_history(h);
    this->set_species(s);
    this->set_area(a);
    this->set_location(l);
}

Animal_health::~Animal_health()
{
    // Destructor
}

Animal_health::Animal_health(Animal_health& other):Animal(other)
{
    this->set_status(other.get_status());
    this->set_keeper(other.get_keeper());
    this->set_diet(other.get_diet());
    this->set_cat(other.get_cat());
    this->set_supply(other.get_supply());
    this->set_history(other.get_history());
    this->set_species(other.get_species());
    this->set_area(other.get_area());
    this->set_location(other.get_location());
}

void Animal_health::set_status(string s)
{
    fit_status = s;
}

string Animal_health::get_status()
{
    return fit_status;
}

void Animal_health::set_keeper(string k)
{
    keeper_det = k;
}

string Animal_health::get_keeper()
{
    return keeper_det;
}

void Animal_health::set_cat(string c)
{
    category = c;
}

string Animal_health::get_cat()
{
    return category;
}

void Animal_health::set_diet(string d)
{
    diet_cond = d;
}

string Animal_health::get_diet()
{
    return diet_cond;
}

void Animal_health::set_supply(string s)
{
    food_supply = s;
}

string Animal_health::get_supply()
{
    return food_supply;
}

void Animal_health::set_history(string h)
{
    habitat_history = h;
}

string Animal_health::get_history()
{
    return habitat_history;
}

void Animal_health::set_species(string s)
{
    species = s;
}

string Animal_health::get_species()
{
    return species;
}

void Animal_health::set_area(string a)
{
    cell_area = a;
}

string Animal_health::get_area()
{
    return cell_area;
}

void Animal_health::set_location(string l)
{
    cell_location = l;
}

string Animal_health::get_location()
{
    return cell_location;
}

void Animal_health::categorised_display(string c)
{
    if (this->get_cat() == c) {
        cout << "Name of animal in category " << c << " is: " << this->get_name() << " and id is: " << this->get_id() << endl;
    } else {
        cout << "No animal of category: " << c << endl;
    }
}

void Animal_health::display_wrt_keeper(string k)
{
    if (this->get_keeper() == k) {
        cout << "Name of animal under keeper " << k << " is: " << this->get_name() << " and id is: " << this->get_id() << endl;
    } else {
        cout << "No animal under keeper: " << k << endl;
    }
}

void Animal_health::display_wrt_diet(string d)
{
    if (this->get_diet() == d) {
        cout<< "Name of animal with diet " << d << " is: " << this->get_name() << " and id is: " << this->get_id() << endl;
    } else {
        cout << "No animal with diet: " << d << endl;
    }
}

void Animal_health::detailed_display(string c, string k, string d)
{
    if (this->get_cat() == c && this->get_keeper() == k && this->get_diet() == d) {
        cout << "Name of animal with all three combinations is: " << this->get_name() << " and id is: " << this->get_id() << endl;
    } else {
        cout << "No animal with all three combinations." << endl;
    }
}

bool Animal_health::isSick()
{
    return (this->get_status() == "sick" || this->get_status() == "Sick");
}

void Animal_health::display_animal(string loc)
{
    if (this->get_location() == loc) {
        cout << "Name is: " << this->get_name() << " and id is: " << this->get_id() << endl;
    } else {
        cout << "No animals in this particular location." << endl;
    }
}

void Animal_health::sick_wrt_cat(string c)
{
    cout << "Sick Animals of category: ";
    cin.ignore();
    getline(cin, c);
    if (this->isSick() && this->get_cat() == c) {
        cout << this->get_name() << " with id " << this->get_id() << endl;
    } else {
        cout << "No sick animals of this category." << endl;
    }
}

void Animal_health::sick_wrt_age(int a)
{
    cout << "Sick Animals of age: ";
    cin >> a;

    if (this->isSick() && this->get_age() == a) {
        cout << this->get_name() << " with id " << this->get_id() << endl;
    } else {
        cout << "No sick animals of this age." << endl;
    }
}

void Animal_health::sick_wrt_gender(char g)
{
    cout << "Sick Animals of Gender (M, F): ";
    cin >> g;
    if (this->isSick() && this->get_gen() == g) {
        cout << this->get_name() << " with id " << this->get_id() << endl;
    } else {
        cout << "No sick animals of this gender." << endl;
    }
}

void Animal_health::sick_wrt_location(string l)
{
    cout << "Sick Animals of location: ";
    cin.ignore();
    getline(cin, l);
    if (this->isSick() && this->get_location() == l) {
        cout << this->get_name() << " with id " << this->get_id() << endl;
    } else {
        cout << "No sick animals in the location." << endl;
    }
}

void Animal_health::sick_wrt_date(date& gt)
{
    date tdate, sdate;
    SYSTEMTIME currentTime;
    GetSystemTime(&currentTime);
    int y = currentTime.wYear;
    int m = currentTime.wMonth;
    int d = currentTime.wDay;
    tdate.set_date(d, m, y);
    cout << "Sickness date (d, m, y): ";
    cin >> d >> m >> y;
    sdate.set_date(d, m, y);
    if (sdate >= gt && sdate <= tdate) {
       cout << this->get_name() << " with id " << this->get_id() << endl;
    } else {
        cout << "No sick animals in the particular time." << endl;
    }
}

bool Animal_health::between_dates(date& t, date& gt)
{
    return (gt <= t);
}

int Animal_health::animal_born(date& gt)
{
    SYSTEMTIME currentTime;
    GetSystemTime(&currentTime);
    int y = currentTime.wYear;
    int m = currentTime.wMonth;
    int d = currentTime.wDay;
    date current;
    current.set_date(d, m, y);
    int count = 0;
    if (birth_date <= gt && birth_date >= current) {
        count++;
    }
    return count;
}

string Animal_health::get_animal_data() {

    string baseData = Animal::get_animal_data();

    string data = baseData + "," + this->get_status() + "," + this->get_keeper() + "," + this->get_diet() + "," + this->get_cat() + "," +
                       this->get_supply() + "," + this->get_history() + "," + this->get_species() + "," + this->birth_date.get_formatted_date() +
                       "," + this->get_area() + "," + this->get_location();

    return data;
}
