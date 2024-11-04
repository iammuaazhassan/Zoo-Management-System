#include <string>
#include "date.h"
#include "Animal_health.h"
#ifndef ANIMAL_H
#define ANIMAL_H


class Animal
{
    private:
        std::string id;
        std::string name;
        int off_spring;
        int cell_id;
        char gender;
        int age;
        float weight;
        std::string group;
    protected:
        void set_id(std::string);
        void set_name(std::string);
        void set_offs(int);
        void set_cellid(int);
        void set_gen(char);
        void set_age(int);
        void set_weight(float);
        void set_group(std::string);
    public:
        std::string get_name();
        std::string get_group();
        std::string get_id();
        int get_offs();
        int get_cellid();
        char get_gen();
        int get_age();
        float get_weight();
    //  Animal();
        virtual ~Animal();
        Animal(std::string="",std::string="",int=0,int=1,char='\0',int=1,float=1,std::string="");
        Animal(Animal&);
        virtual std::string get_animal_data();
        virtual bool between_dates(date&,date&)=0;
        virtual bool isSick()=0;
        virtual void display_animal(std::string)=0;
        virtual void categorised_display(std::string)=0;
        virtual void display_wrt_keeper(std::string)=0;
        virtual void display_wrt_diet(std::string)=0;
        virtual void detailed_display(std::string,std::string,std::string)=0;
        virtual void sick_wrt_cat(std::string)=0;
        virtual void sick_wrt_age(int)=0;
        virtual void sick_wrt_gender(char)=0;
        virtual void sick_wrt_location(std::string)=0;
        virtual void sick_wrt_date(date&)=0;
        virtual int animal_born(date&)=0;
     //   virtual int sick_frequency(int&)=0;


};

     void destroy_records(Animal* [],int);
     void add_animal(Animal* [],int,int&);
     void delete_animal(Animal* [],int,std::string,int&);
     void find_animal(Animal* [],int,std::string);
     int sick_frequency(Animal* [],int);
     int born_between_dates(Animal*[],int,date&);
     void save_data_to_file(Animal*[],int);
     void load_data_from_file(Animal*[],int);
     Animal* create_animal_from_data(const std::string&);
#endif // ANIMAL_H
