//
//  median.cpp
//  accelerated-cpp
//
//  Created by Trevor Knutson on 8/17/20.
//  Copyright © 2020 Trevor Knutson. All rights reserved.
//

#include "median.hpp"
#include <vector>
#include <stdexcept>
#include <algorithm>

using std::vector;    using std::domain_error;
using std::sort;

double median(vector<double> vec) {
    typedef vector<double>::size_type vec_sz;
    vec_sz size = vec.size();
    
    sort(vec.begin(), vec.end());
    
    if (size == 0)
        throw domain_error("Cannot find median of an empty vector!");
    
    vec_sz mid = size / 2;
    
    return size % 2 == 0 ? (vec[mid] + vec[mid + 1]) / 2 : vec[mid];
}
