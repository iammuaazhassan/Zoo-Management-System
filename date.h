#include <string>
#ifndef DATE_H
#define DATE_H


class date
{
    private:
        int day;
        int month;
        int year;
    protected:
        void set_day(int);
        int get_day();
        void set_month(int);
        int get_month();
        void set_year(int);
        int get_year();
    public:
        //date();
        ~date();
        date(int=1,int=1,int=1900);
        date(const date&);
        std::string get_formatted_date();
        void set_date(int,int,int);
        void display_date();
        bool operator<=(date&);
        bool operator>=(date&);
};

#endif // DATE_H
