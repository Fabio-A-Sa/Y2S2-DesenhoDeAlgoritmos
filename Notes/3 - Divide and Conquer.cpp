#include <iostream>
#include <thread>
using namespace std;

int getCoreNumber() {
    return std::thread::hardware_concurrency();
}

int main () {
    cout << "Hello World" << endsl;
    cout << getCoreNumber() << endl;
    return 0;
}