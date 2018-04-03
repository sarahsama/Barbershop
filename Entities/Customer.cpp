//
// Created by Sama on 4/1/18.
//

#include <Initializer/Controller.h>
#include "Customer.h"


void Customer::arrives(Barber &barber, mutex& mu){

    if(barber.q.size() < barber.n_seats  && barber.is_working== false){
        //barber is sleeping, customer has to to wake him up
        mu.lock();
        cout<<"Customer "<< this->id <<" is waking up the barber." << endl;
        barber.q.push_back(this->id);
        mu.unlock();

        thread t(&Barber::startworking,&barber,ref(mu));
        t.join();
    }else if(barber.q.size()<barber.n_seats  && barber.is_working== true){
        //barber is working and seats are empty
        mu.lock();
        cout<<"Customer "<< this->id <<" is sitting down." << endl;;
        barber.q.push_back(this->id);
        mu.unlock();
    }else{
        //barber is working and seats are not empty
        mu.lock();
        cout<<"Customer "<< this->id <<" is leaving." <<  endl;
        mu.unlock();
    }
    //

}

Customer::Customer(int id) {
    this->id = id;
}
