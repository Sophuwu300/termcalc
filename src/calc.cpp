#include <iostream>
#include "calc.h"

long getFloat(char* str, flt_t& num) {
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
            num = sign * iPart;
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
    num = sign * (iPart + fPart);
    return 0;
}

int getInput(char* argv[], flt_t& num1, flt_t& num2, char* op) {
    if (getFloat(argv[1], num1) || getFloat(argv[3], num2)) {
        std::cout<<("Error: Invalid number\n") << std::endl;
        return 1;
    }
    *op = argv[2][0];
    if (*op != '+' && *op != '-' && *op != 'x' && *op != '/' && *op != '%') {
        std::cout<<("Error: Invalid operator\n") << std::endl;
        return 1;
    }
    return 0;
}

flt_t calcs(flt_t num1, flt_t num2, char op) {
    switch (op) {
        case '+': return (flt_t)(num1 + num2);
        case '-': return (flt_t)(num1 - num2);
        case 'x': return (flt_t)(num1 * num2);
        case '/': return (flt_t)(num1 / num2);
        default: return 0.0f;
    }
}

int main(int argc, char* argv[]) {
    if (argc != 4) return 1;

    flt_t num1, num2;
    num1 = num2 = 0.0f;
    char op = argv[2][0];
    if (getInput(argv, num1, num2, &op)) return 1;
    flt_t result = calcs(num1, num2, op);
    std::cout << result << std::endl;
    return 0;
}