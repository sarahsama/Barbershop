//
// Created by Sama on 4/1/18.
//

#ifndef BARBER_CONTROLLER_H
#define BARBER_CONTROLLER_H
#include <string>
#include <iostream>
#include <thread>
#include <vector>
#include <mutex>
#include <Entities/Barber.h>
#include <Entities/Customer.h>

using namespace std;

class Controller {
public:
    //we use this to read the input value
    void readInput(int argc, char *argv[]);
    //an scheduler that controls the overall flow of the program by adding new customers
    void scheduler();

private:
    //temporarily add number of the seats here, this will be sent to the n_seats in tha barber class
    int n_seats = -1;

};


#endif //BARBER_CONTROLLER_H
