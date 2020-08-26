//
//  main.cpp
//  accelerated-cpp
//
//  Created by Trevor Knutson on 7/30/20.
//  Copyright © 2020 Trevor Knutson. All rights reserved.
//

#include <iostream>
#include <vector>
#include <ios>
#include <string>
#include <iomanip>
#include <algorithm>
#include <stdexcept>
#include "grading-app/median.h"
#include "grading-app/grade.h"
#include "grading-app/Student_info.h"

using std::cin;             using std::setprecision;
using std::cout;            using std::sort;
using std::domain_error;    using std::streamsize;
using std::endl;            using std::string;
using std::max;             using std::vector;


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

