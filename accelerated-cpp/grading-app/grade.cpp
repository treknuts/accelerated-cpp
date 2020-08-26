//
//  grade.cpp
//  accelerated-cpp
//
//  Created by Trevor Knutson on 8/26/20.
//  Copyright © 2020 Trevor Knutson. All rights reserved.
//

#include <stdio.h>
#include <stdexcept>
#include <vector>
#include "grade.h"
#include "median.hpp"
#include "Student_info.h"

using std::domain_error;    using std::vector;

double grade(double midterm, double finalExam, double homework) {
    return 0.2 * midterm + 0.4 * finalExam + 0.4 * homework;
}

double grade(double midterm, double finalExam, const vector<double>& hw) {
    if (hw.size() == 0)
        throw domain_error("The student has done no homework.");
    return 0.2 * midterm + 0.4 * finalExam + 0.4 * median(hw);
}

double grade(const Student_info& s) {
    return grade(s.midterm, s.finalExam, s.homework);
}
