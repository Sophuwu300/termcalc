// Creator: Sophuwu
// This program is a simple calculator that takes in two numbers and an operator and returns the result of the operation.

#include "calc.h"


int checkInput(int argc) {
    if (argc != 4) print ("Usage: calc <num1> <op> <num2>\n\n\tOperators: + - x / %\n\tExample: calc 10 / 5\n");
    return argc != 4;
}

int getFloat(char* str, flt_t* num) {
    flt_t iPart = 0.0f;
    flt_t fPart = 0.0f;
    int_t fPartLen = 0ll;
    long i = 0l;
    int sign = 1;

    if (str[0] == '-') {
        sign = -1;
        i++;
    }

    while (str[i] != '.') {
        if (str[i] == '\0') {
            *num = (flt_t)(sign * iPart);
            return 0;
        }
        if (str[i] < '0' || str[i] > '9') return 1;
        iPart = iPart * 10 + (int_t)(str[i]) - '0';
        i++;
    }
    i++;
    while (str[i] != '\0') {
        if (str[i] < '0' || str[i] > '9') return 1;
        fPart = fPart * 10 + (flt_t)(str[i]) - '0';
        fPartLen++;
        i++;
    }
    while (fPartLen > 0) {
        fPart /= 10;
        fPartLen--;
    }
    *num = (flt_t)(sign * (iPart + fPart));
    return 0;
}

int getInput(char* argv[], flt_t* num1, flt_t* num2, char* op) {
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

flt_t calcs(const flt_t num1, const flt_t num2, char op) {
    switch (op) {
        case '+': return (flt_t)(num1 + num2);
        case '-': return (flt_t)(num1 - num2);
        case 'x': return (flt_t)(num1 * num2);
        case '/': return (flt_t)(num1 / num2);
    }
    return 0.0f;
}

int main(int argc, char* argv[]) {
    if (checkInput(argc)) return 1;
    flt_t num1 = 0.0f;
    flt_t num2 = 0.0f;
    char op = argv[2][0];

    if (getInput(argv, &num1, &num2, &op)) return 1;
    flt_t r = calcs(num1, num2, op);
    printf("%.32Lf\n", r);

    return 0;
}