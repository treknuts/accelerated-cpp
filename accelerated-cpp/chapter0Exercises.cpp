//
//  chapter0Exercises.cpp
//  accelerated-cpp
//
//  Created by Trevor Knutson on 7/30/20.
//  Copyright © 2020 Trevor Knutson. All rights reserved.
//

#include "chapter0Exercises.hpp"
#include <iostream>

namespace ch0 {

    void escapeChars() {
        std::cout << "This (\") is a quete, and this (\\) is a backslash." <<  std::endl;
    }

    void helloWorld() {
        {std::cout << "Hello, World!" << std::endl;}
    }

    void tabs() {
        std::cout << "\tThe first line of a paragraph \nshould be indented.\n";
    }

}
