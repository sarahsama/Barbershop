//
// Created by Sama on 4/1/18.
//


#include "Controller.h"

void Controller::readInput(int argc, char *argv[]) {
    //some basic checks to see if input is right, in the real environment we need more comprehensive check ups
    if(argc==2){
        this->n_seats = stoi(argv[1]);
        cout<<"Number of the seats is:"<< this->n_seats<<endl;
    } else if (argc>2) {
        //users do not need to worry if number of args is bigger than what is expected, without quitting the program they are asked to enter a right number
        cout<<"Number of the arguments was bigger than what was expected, please try again by entering an input for number of the seats:"<< this->n_seats<<endl;
        while(this->n_seats<1){
            int input = -1;
            cin>>input;
            this->n_seats = input;
        }
    }else{
        //if users forgot to enter an input, we don't even let them worry about it, simply ask to enter a number
        cout<<"Please enter an input for number of the seats:";
        while(this->n_seats<1){
            int input = -1;
            cin>>input;
            this->n_seats = input;
        }
    }
    cout<<"number of the seats is:"<<this->n_seats<<endl;
}

void Controller::scheduler() {
    Barber barber(this->n_seats);//we only need one barber, it will be used by customers when needed
    vector<thread> threads;//we need to keep track of all of the threads to access them later on. This prevents compiler errors.
    mutex  mu;//this mutex has to be shared by all of the following threads
    int id = 0;
    while (true){
        Customer cust(id++);
        //we create a separate thread for each customer
        threads.push_back(thread (&Customer::arrives,&cust, ref(barber), ref(mu)));

        //every 3 secs create a new customer
        chrono::duration<int64_t> sleep_time = chrono::seconds(3);
        this_thread::sleep_for(sleep_time);
    }
    for (int i = 0; i < threads.size(); i++) {
        threads[i].join();
    }
}
