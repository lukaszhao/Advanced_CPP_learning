#include <iostream>
#include <thread>
#include <chrono>

#include "dog.h"

using namespace std;

void singFunction(const std::string& songToSing) {
    std::cout << "[Singing from main thread] " << songToSing << "\n";
}

void test_barking() {
    Dog dog1("Lee", 2);
    dog1.startBarking();
    dog1.startGrowing();
    dog1.startSinging(singFunction);

    while(true){
        std::cout << "[main] la la la la la la la la la la la \n";

        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}

int main()
{
    cout << "Hello world!" << endl;
    test_barking();
    return 0;
}
