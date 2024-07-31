/*
run command manually from terminal:
g++ main.cpp dummy.cpp -o main
*/
#include "dummy.h"
#include <iostream>
using namespace std;

int main()
{
    int retValue = dummyFunct();
    cout << "Dummy value= " << retValue << endl;
    return 0;
}