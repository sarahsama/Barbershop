//
// Created by Sama on 4/1/18.
//


#include <Initializer/Controller.h>

int main(int argc, char* argv[]) {
    Controller ctr;
    ctr.readInput(argc, argv);
    ctr.scheduler();
    return 0;
}