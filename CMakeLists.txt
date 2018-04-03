cmake_minimum_required(VERSION 3.10)
project(Barbershop)

#this is to let files find the libraries across foldres.
set(ROOT ".")
include_directories(${ROOT})

set(CMAKE_CXX_STANDARD 11)
SET(CMAKE_CXX_FLAGS -pthread)


add_executable(Barber Initializer/main.cpp Initializer/Controller.cpp Initializer/Controller.h Entities/Barber.cpp Entities/Barber.h Entities/Customer.cpp Entities/Customer.h)