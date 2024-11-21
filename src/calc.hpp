#ifndef TERMCALC_CALC_HPP
#define TERMCALC_CALC_HPP

#include <cstdio>
#include <cmath>
#include <string>
#include <map>

typedef long double flt_t;
typedef long int int_t;

typedef std::string strr;
typedef flt_t(*fptr)(flt_t, flt_t); // for a function with two arguments
typedef std::map<strr, fptr> op_t;


#endif //TERMCALC_CALC_HPP