#ifndef ANIMAL_HEALTH_H
#define ANIMAL_HEALTH_H
#include <string>
#include <Animal.h>


class Animal_health : public Animal
{
    private:
        std::string fit_status;
        std::string keeper_det;
        std::string diet_cond;
        std::string category;
        std::string food_supply;
        std::string habitat_history;
        std::string species;
        date birth_date;
        std::string cell_area;
        std::string cell_location;
    protected:
        void set_status(std::string);
        void set_keeper(std::string);
        void set_diet(std::string);
        void set_cat(std::string);
        void set_supply(std::string);
        void set_history(std::string);
        void set_species(std::string);
        void set_area(std::string);
        void set_location(std::string);
    public:
        std::string get_status();
        std::string get_keeper();
        std::string get_diet();
        std::string get_supply();
        std::string get_history();
        std::string get_species();
        std::string get_area();
        std::string get_location();
        std::string get_cat();
//      Animal_health();
        ~Animal_health();
        Animal_health(std::string="",std::string="",int=0,int=1,char='\0',int=1,float=1,std::string="",
                      std::string="",std::string="",std::string="",std::string="",std::string="",
                      std::string= "",std::string= "",const date& birth_date = date(),std::string="", std::string = "");
        Animal_health(Animal_health& other);
        std::string get_animal_data();
        bool isSick();
        bool between_dates(date&,date&);
        void display_animal(std::string);
        void categorised_display(std::string);
        void display_wrt_keeper(std::string);
        void display_wrt_diet(std::string);
        void detailed_display(std::string,std::string,std::string);
        void sick_wrt_cat(std::string);
        void sick_wrt_age(int);
        void sick_wrt_gender(char);
        void sick_wrt_location(std::string);
        void sick_wrt_date(date&);
        int animal_born(date&);

};


#endif // ANIMAL_HEALTH_H
