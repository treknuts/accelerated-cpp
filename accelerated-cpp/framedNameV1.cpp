//
//  framedNameV1.cpp
//  accelerated-cpp
//
//  Created by Trevor Knutson on 8/8/20.
//  Copyright © 2020 Trevor Knutson. All rights reserved.
//

#include "framedNameV1.hpp"
#include <iostream>
#include <string>

int greetingV1() {
    std::cout << "Please enter your name: ";
    std::string name;
    std::cin >> name;
    
    const std::string greeting = "Hello, " + name + "!";
    
    const std::string spaces(greeting.size(), ' ');
    const std::string second = ("* " + spaces + " *");
    
    const std::string first(second.size(), '*');
    
    std::cout << first << std::endl;
    std::cout << second << std::endl;
    std::cout << "* " + greeting + " *" << std::endl;
    std::cout << second << std::endl;
    std::cout << first << std::endl;
    return 0;
}
