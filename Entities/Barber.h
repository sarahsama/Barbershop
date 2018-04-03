//
// Created by Sama on 4/1/18.
//

#ifndef BARBER_BARBER_H
#define BARBER_BARBER_H

#include <iostream>
#include <thread>
#include <mutex>
#include <deque>

using namespace std;

class Barber {


public:
    Barber(int n_seats);
    deque<int> q;//deque is more efficient when we want to print the values of the q
    int n_seats = -1;//max number of available seats
    bool is_working = false;//we need this when queue is empty and barber is working on the last customer

    void startworking(mutex& mu);
};


#endif //BARBER_BARBER_H
