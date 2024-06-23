#include <iostream>
#include <cmath>
#include <cfloat>
#include <iomanip>
#include <cstdlib>
#include <complex>
#include <chrono>
#include <ctime>
#include <cstdio>
#include <functional>
#include <ctgmath>
#include "calc.h"

typedef long double float flt_t;

#define print(s) std::cout << s << std::endl

int checkInput(int argc) {
    if (argc != 4) print ("Usage: calc <num1> <op> <num2>\n\n\tOperators: + - x / %\n\tExample: calc 10 / 5\n");
    return argc != 4;
}

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

void calcs(flt_t& result, flt_t num1, flt_t num2, char op) {
    switch (op) {
        case '+': result = faddl(num1, num2); break;
        case '-': result = fsubl(num1, num2); break;
        case 'x': result = fmull(num1, num2); break;
        case '/': result = fdivl(num1, num2); break;
        case '%': result = fmodl(num1, num2); break;
    }
}

int main(int argc, char* argv[]) {
    if (checkInput(argc)) return 1;

    flt_t num1, num2;
    num1 = num2 = 0.0f;
    char op = argv[2][0];

    if (getInput(argv, num1, num2, &op)) return 1;

    std::cout << std::setprecision(16);
    flt_t result = 0.0f;
    flt_t result = calcs(num1, num2, op);
    std::cout << result << std::endl;
    //printf("%Lf\n", result);

    return 0;
}