#ifndef DOG_H
#define DOG_H

#include <iostream>
#include <string>

#include <thread>
#include <chrono>

class Dog
{
    public:
        Dog(const std::string& name, int age):
            d_name(name),
            d_age(age)
        {

        }

        ~Dog() {}


    private:
        std::string       d_name;
        int               d_age;

    public:
        void bark() const;

        void sing(void (*cb)(const std::string& songToSing)) const;

        void grow();

        void startBarking() const;

        void startGrowing();

        void startSinging(void (*cb)(const std::string& songToSing)) const;

};

#endif // DOG_H
