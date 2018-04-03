//
// Created by Sama on 4/1/18.
//

#include "Barber.h"

Barber::Barber(int n_seats) {
    this->n_seats = n_seats;
}



void Barber::startworking(mutex& mu) {
    mu.lock();
    cout << "Barber cutting the hair of customer " <<this->q.front()<< endl;
    this->q.pop_front();

    cout<< "Waiting room:";
    for (int i=0;i<q.size();i++) {
        cout << q[i] <<  " ";
    }cout << endl;

    this->is_working = true;
    mu.unlock();

    //wait for 1-5 seconds to finish a job
    int random = 1 + rand() % 5;
    chrono::duration<int64_t> sleep_time = chrono::seconds(random);
    this_thread::sleep_for(sleep_time);



    if (q.size() == 0) {
        mu.lock();
        cout << "Barber sleeping" << endl;
        cout<< "Waiting room:" << endl;
        is_working = false;
        mu.unlock();
    }else{
        thread t(&Barber::startworking,this,ref(mu));
        t.join();
    }
}
