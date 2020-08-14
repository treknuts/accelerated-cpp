//
//  gradeCalculator.cpp
//  accelerated-cpp
//
//  Created by Trevor Knutson on 8/9/20.
//  Copyright © 2020 Trevor Knutson. All rights reserved.
//

#include "gradeCalculator.hpp"
#include "framedNameV2.hpp"
#include <ios>
#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <stdexcept>

using std::cout;            using std::endl;
using std::cin;             using std::sort;
using std::setprecision;    using std::streamsize;
using std::vector;          using std::string;
using std::domain_error;    using std::istream;

double grade(double midterm, double finalExam, double homework) {
    return 0.2 * midterm + 0.4 * finalExam + 0.4 * homework;
}

double median(vector<double> vec) {
    // vec_sz is type vector<double>::size_type
    typedef vector<double>::size_type vec_sz;
    vec_sz size = vec.size();
    
    sort(vec.begin(), vec.end());
    
    if (size == 0)
        throw domain_error("Cannot find median of an empty vector!");
    
    vec_sz mid = size / 2;
    
    return size % 2 == 0 ? (vec[mid] + vec[mid + 1]) / 2 : vec[mid];
    
}

double grade(double midterm, double finalExam, const vector<double>& hw) {
    if (hw.size() == 0)
        throw domain_error("The student has done no homework.");
    return 0.2 * midterm + 0.4 * finalExam + 0.4 * median(hw);
}

istream& read_hw(istream& in, vector<double>& hw) {
    if (in) {
        hw.clear();
        
        double x;
        while(in >> x)
            hw.push_back(x);
        
        in.clear();
    }
    return in;
}

int calculateGrade() {
    greetingV2();
    
    cout << "Please enter your midterm and final exam grades: ";
    double midterm, finalExam;
    cin >> midterm >> finalExam;
    
    cout << "Enter all your homework grades: "
            "followed by end-of-file";
    
    vector<double> homework;
    
    read_hw(cin, homework);
    
    streamsize prec = cout.precision();
    cout << "Your final grade is " << setprecision(3)
         << grade(midterm, finalExam, homework)
         << setprecision(prec) << endl;
    
    return 0;
}
