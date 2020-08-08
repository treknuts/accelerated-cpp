//
//  framedNameV2.cpp
//  accelerated-cpp
//
//  Created by Trevor Knutson on 8/8/20.
//  Copyright © 2020 Trevor Knutson. All rights reserved.
//

#include "framedNameV2.hpp"
#include <iostream>
#include <string>

using std::cout;    using std::endl;
using std::cin;     using std::string;

int greetingV2() {
    
    cout << "Please enter your name: ";
    
    string name;
    cin >> name;
    
    string greeting = "Hello, " + name + "!";
    
    cout << "How much spacing would you like? ";
    
    int arg;
    cin >> arg;
    const int pad = arg;
    
    const int rows = pad * 2 + 3;
    
    // Whenever storing length of string locally
    // Use the string::size_type
    const string::size_type cols = greeting.size() + pad * 2 + 2;

    cout << endl;
    
    for (int r = 0; r != rows; ++r) {
        
        string::size_type c = 0;
        
        while (c != cols) {
            if (r == pad + 1 && c == pad + 1) {
                cout << greeting;
                c += greeting.size();
            } else {
                if (r == 0 || r == rows - 1 || c == 0 || c == cols - 1)
                    cout << "*";
                else
                    cout << " ";
                ++c;
            }
        }
        cout << endl;
    }
    
    return 0;
}
