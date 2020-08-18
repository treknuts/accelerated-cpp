//
//  main.cpp
//  accelerated-cpp
//
//  Created by Trevor Knutson on 7/30/20.
//  Copyright © 2020 Trevor Knutson. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <ios>
#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <stdexcept>
#include "median.hpp"

using std::cout;            using std::endl;
using std::cin;             using std::sort;
using std::setprecision;    using std::streamsize;
using std::vector;          using std::string;
using std::domain_error;    using std::istream;
using std::max;

struct Student_info {
    string name;
    double midterm, finalExam;
    vector<double> homework;
};

bool compare(const Student_info& x, const Student_info& y) {
    return x.name < y.name;
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

double grade(double midterm, double finalExam, double homework) {
    return 0.2 * midterm + 0.4 * finalExam + 0.4 * homework;
}


istream& read(istream& is, Student_info& s) {
    is >> s.name >> s.midterm >> s.finalExam;
    
    read_hw(is, s.homework);
    return is;
}

double grade(double midterm, double finalExam, const vector<double>& hw) {
    if (hw.size() == 0)
        throw domain_error("The student has done no homework.");
    return 0.2 * midterm + 0.4 * finalExam + 0.4 * median(hw);
}

double grade(const Student_info& s) {
    return grade(s.midterm, s.finalExam, s.homework);
}

int main() {
    vector<Student_info> students;
    Student_info record;
    string::size_type maxlen = 0;
    
    while (read(cin, record)) {
        maxlen = max(maxlen, record.name.size());
        students.push_back(record);
    }
    
    sort(students.begin(), students.end(), compare);
    
    for (vector<Student_info>::size_type i = 0; i != students.size(); ++i) {
        cout << students[i].name
        << string(maxlen + 1 - students[i].name.size(), ' ');
        
        try {
            double finalGrade = grade(students[i].midterm,
                                      students[i].finalExam,
                                      students[i].homework);
            streamsize prec = cout.precision();
            cout << setprecision(3) << finalGrade
                 << setprecision(prec);
        } catch (domain_error e) {
            cout << e.what();
            cout << endl;
        }
    }
    return 0;
}

