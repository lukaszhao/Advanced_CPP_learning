#include "dog.h"
#include <string>

void Dog::bark() const
{
    while(true) {
        std::cout << "[bark] My name is " << d_name << "\n"
                  << "       My age is " << d_age << "\n";
        std::this_thread::sleep_for(std::chrono::seconds(3));
    }
}

void Dog::sing(void (*cb)(const std::string& songToSing)) const
{
    while(true) {
        std::cout << "[sing] I am " << d_age << " years old\n";
        std::string song = "I am singing my age is " + std::to_string(d_age);

        cb(song);

        std::this_thread::sleep_for(std::chrono::seconds(3));
    }
}


void Dog::grow()
{
    while(true) {
        ++d_age;
        std::cout <<"[grow] I just got " << d_age << "years old\n";
        std::this_thread::sleep_for(std::chrono::seconds(3));
    }
}

void Dog::startGrowing()
{
    std::thread growThread(&Dog::grow, this);
    growThread.detach();
}

void Dog::startBarking() const
{
    std::thread barkThread(&Dog::bark, this);
    barkThread.detach();
}

void Dog::startSinging(void (*cb)(const std::string& songToSing)) const
{
    std::thread singThread(&Dog::sing, this, cb);   // read http://thispointer.com/c11-multithreading-part-3-carefully-pass-arguments-to-threads/
    singThread.detach();
}
