#include <iostream>
#include <string>
#include <thread>
#include <mutex>

using namespace std;

mutex myMutex;

void print(const string& strToPrint) {
    lock_guard<mutex> myLock(myMutex);
    cout << "[from function print]: " << strToPrint << "\n";
}

void doSomeWork(void (*cb)(const string& strToPrint))
{
    for(int i = 0; i < 10; ++i) {
        string str = "[workThread] Doing job " + to_string(i);
        cb(str);
    }
}

void doSomeDude(void (*cb)(const string& strToPrint))
{
    for(int i = 0; i < 10; ++i) {
        string str = "[fuckThread] Doing dude " + to_string(i);
        cb(str);
    }
}

void startFucking(void (*cb)(const string& strToPrint))
{
    std::thread fuckThread(doSomeDude, cb);
    fuckThread.join();  // at the point of join, main thread stops and waits for child thread to finish
}

int main()
{
    cout << "Hello world!" << endl;

    std::thread workThread(doSomeWork, print);
    startFucking(print);

    workThread.join();  // at the point of join, main thread stops and waits for child thread to finish
}
