#include <iostream>
#include <cmath>
#include <cfloat>
#include <iomanip>
#include <cstdlib>
#include <complex>
#include <ccomplex>
#include <chrono>
#include <ctime>


typedef long double float flt_t;

#define print(s) std::cout << s << std::endl

int checkInput(int argc) {
    if (argc != 4) print ("Usage: calc <num1> <op> <num2>\n\n\tOperators: + - x / %\n\tExample: calc 10 / 5\n");
    return argc != 4;
}
#include <cstdio>
#include <cfloat> // DBL_MAX and DBL_MIN
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <functional>
#include <ccomplex>
#include <complex>
#include <ctgmath>
long getFloat(char* str, flt_t* num) {
    flt_t iPart = 0.0f;
    flt_t fPart = 0.0f;
    long fPartLen = 0;
    long i = 0;
    long sign = 1;

    if (str[0] == '-') {
        sign = -1;
        i++;
    }

    while (str[i] != '.') {
        if (str[i] == '\0') {
            *num = sign * iPart;
            return 0;
        }
        if (str[i] < '0' || str[i] > '9') return 1;
        iPart = iPart * 10 + flt_t(str[i]) - '0';
        i++;
    }
    i++;
    while (str[i] != '\0') {
        if (str[i] < '0' || str[i] > '9') return 1;
        fPart = fPart * 10 + flt_t(str[i]) - '0';
        fPartLen++;
        i++;
    }
    while (fPartLen > 0) {
        fPart /= 10;
        fPartLen--;
    }
    *num = sign * (iPart + fPart);
    return 0;
}

int getInput(char* argv[], flt_t& num1, flt_t& num2, char* op) {
    if (getFloat(argv[1], num1) || getFloat(argv[3], num2)) {
        print ("Error: Invalid number\n");
        return 1;
    }
    *op = argv[2][0];
    if (*op != '+' && *op != '-' && *op != 'x' && *op != '/' && *op != '%') {
        print ("Error: Invalid operator\n");
        return 1;
    }
    return 0;
}

flt_t fadd(flt_t num1, flt_t num2) {
    return num1 + num2;
}

flt_t fsub(flt_t num1, flt_t num2) {
    return num1 - num2;
}

flt_t fmul(flt_t num1, flt_t num2) {
    return num1 * num2;
}

flt_t fdiv(flt_t num1, flt_t num2) {
    return num1 / num2;
}

flt_t fmod(flt_t num1, flt_t num2) {
    return fmod(num1, num2);
}

flt_t flcalcs(flt_t num1, flt_t num2, char op) {

    flt_t result;
    switch (op) {
        case '+': result = fadd(num1, num2); break;
        case '-': result = fsub(num1, num2); break;
        case 'x': result = fmul(num1, num2); break;
        case '/': result = fdivl(num1, num2); break;
        case '%': result = fmod(num1, num2); break;
    }
    return result? result : DBL_MAX;
}

int main(int argc, char* argv[]) {
    if (checkInput(argc)) return 1;

    flt_t num1, num2;
    char op = argv[2][0];

    if (getInput(argv, num1, num2, &op)) return 1;

    std::cout << std::setprecision(16);
    flt_t result = flcalcs(num1, num2, op);
    std::cout <<  << result << std::endl;
    //printf("%Lf\n", result);

    return 0;
}