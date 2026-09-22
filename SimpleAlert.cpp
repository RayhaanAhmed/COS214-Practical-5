#include "SimpleAlert.h"
#include <iostream>

void SimpleAlert::send(const std::string& message){
    std::cout<<"Simple Alert: " << message << std::endl;
}