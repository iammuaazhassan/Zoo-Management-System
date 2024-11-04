#include "date.h"
#include <iostream>

using namespace std;

date::~date()
{
    // Destructor
}

date::date(int d, int m, int y)
{
    set_date(d, m, y);
}

void date::set_day(int d)
{
    day = d;
}

int date::get_day()
{
    return day;
}

void date::set_month(int m)
{
    month = m;
}

int date::get_month()
{
    return month;
}

void date::set_year(int y)
{
    year = y;
}

int date::get_year()
{
    return year;
}

void date::set_date(int d, int m, int y)
{
    set_day(d);
    set_month(m);
    set_year(y);
}

date::date(const date& other)
{
    set_day(other.day);
    set_month(other.month);
    set_year(other.year);
}

void date::display_date()
{
    cout << get_day() << "-" << get_month() << "-" << get_year() << endl;
}

bool date::operator<=(date& other)
{
    if (year < other.get_year())
        return true;
    else if (year == other.get_year() && month < other.get_month())
        return true;
    else if (year == other.get_year() && month == other.get_month() && day <= other.get_day())
        return true;
    else
        return false;
}

bool date::operator>=(date& other)
{
    if (year > other.get_year())
        return true;
    else if (year == other.get_year() && month > other.get_month())
        return true;
    else if (year == other.get_year() && month == other.get_month() && day >= other.get_day())
        return true;
    else
        return false;
}

string date::get_formatted_date()
{
    string formatted_date = to_string(this->get_day()) + "-" + to_string(this->get_month()) + "-" + to_string(this->get_year());
    return formatted_date;
}

