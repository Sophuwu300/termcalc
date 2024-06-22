#include <iostream>

#define print(a) std::cout << a << std::endl

int checkInput(int argc) {
    if (argc != 4) print ("Usage: calc <num1> <op> <num2>\n\n\tOperators: + - x / %\n\tExample: calc 10 / 5\n");
    return argc != 4;
}

long getFloat(char* str, double* num) {
    double iPart = 0;
    double fPart = 0;
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
        iPart = iPart * 10 + double(str[i]) - '0';
        i++;
    }
    i++;
    while (str[i] != '\0') {
        if (str[i] < '0' || str[i] > '9') return 1;
        fPart = fPart * 10 + double(str[i]) - '0';
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

int getInput(char* argv[], double* num1, double* num2, char* op) {
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

void calc(double num1, double num2, char op) {
    switch (op) {
        case '+':
            print (num1 + num2);
            return;
        case '-':
            print (num1 - num2);
            return;
        case 'x':
            print (num1 * num2);
            return;
        case '/':
            print (num1 / num2);
            return;
        case '%':
            print ((long)(num1) % (long)(num2));
            return;
    }
}

int main(int argc, char* argv[]) {
    if (checkInput(argc)) return 1;

    double num1 = 0.0;
    double num2 = 0.0;
    char op = argv[2][0];

    if (getInput(argv, &num1, &num2, &op)) return 1;

    calc(num1, num2, op);

    return 0;
}