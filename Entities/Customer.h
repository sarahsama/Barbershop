//
// Created by Sama on 4/1/18.
//

#ifndef BARBER_CUSTOMER_H
#define BARBER_CUSTOMER_H
#include <mutex>

class Customer {
public:
    Customer(int id);
    void arrives(Barber& barber, mutex& mu);
private:
    int id = -1;//this is the identifier of the customer
};



#endif //BARBER_CUSTOMER_H
