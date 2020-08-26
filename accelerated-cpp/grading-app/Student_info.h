//
//  Student_info.h
//  accelerated-cpp
//
//  Created by Trevor Knutson on 8/26/20.
//  Copyright © 2020 Trevor Knutson. All rights reserved.
//

#ifndef GUARD_Student_info_h
#define GUARD_Student_info_h

#include <iostream>
#include <string>
#include <vector>

struct Student_info {
    std::string name;
    double midterm, finalExam;
    std::vector<double> homework;
}

bool compare(const Student_info&, const Student_info&);
std::istream& read(std::istream&, Student_info&);
std::istream& read_hw(std::istream&, std::vector<double>&);


#endif /* Student_info_h */
