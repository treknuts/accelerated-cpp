//
//  grade.h
//  accelerated-cpp
//
//  Created by Trevor Knutson on 8/26/20.
//  Copyright © 2020 Trevor Knutson. All rights reserved.
//

#ifndef GUARD_grade_h
#define GUARD_grade_h

#include <vector>
#include "Student_info.h"

double grade(double, double, double);
double grade(double, double, const std::vector<double>&);
double grade(const Student_info&);

#endif /* grade_h */
