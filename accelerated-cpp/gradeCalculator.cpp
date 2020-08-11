//
//  gradeCalculator.cpp
//  accelerated-cpp
//
//  Created by Trevor Knutson on 8/9/20.
//  Copyright © 2020 Trevor Knutson. All rights reserved.
//

#include "gradeCalculator.hpp"
#include <ios>
#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <algorithm>

using std::cout;            using std::endl;
using std::cin;             using std::sort;
using std::setprecision;    using std::streamsize;
using std::vector;          using std::string;

int calculateGrade() {
    cout << "Please enter your first name: ";
    string name;
    cin >> name;
    cout << "Hello, " + name + "!" << endl;
    
    cout << "Please enter your midterm and final exam grades: ";
    double midterm, finalExam;
    cin >> midterm >> finalExam;
    
    cout << "Enter all your homework grades: "
            "followed by end-of-file";
    
    /*
     v1 of the program computed the average hw grade
     Hence, why we needed 2 loop invariants
     int count = 0;
     double sum = 0;
     */
     double x;
    vector<double> homework;
    
    while (cin >> x) {
        /*
         ++count;
         sum += x;
        */
        homework.push_back(x);
    }
    
    // A fancy way of aliasing vector<type>::size_type as vec_sz
    typedef vector<double>::size_type vec_sz;
    // vec_sz is type vector<double>::size_type
    vec_sz size = homework.size();
    
    if (size == 0) {
        cout << "You must enter your grades. "
                "Please try again." << endl;;
        return 1;
    }
    
    sort(homework.begin(), homework.end());
    
    vec_sz mid = size / 2;
    double median;
    median = size % 2 == 0 ? (homework[mid] + homework[mid - 1]) / 2
                           : homework[mid];
    
    
    streamsize prec = cout.precision();
    cout << "Your final grade is " << setprecision(3)
         << 0.2 * midterm + 0.4 * finalExam + 0.4 * median
         << setprecision(prec) << endl;
    
    return 0;
}
