#include <cstdio>

int checkInput(int argc) {
    if (argc != 4) printf("%s", "Usage: calc <num1> <op> <num2>\n\n\tOperators: + - x / %\n\tExample: calc 10 / 5\n");
    return argc != 4;
}

int getFloat(char* str, float* num) {
    float iPart = 0;
    float fPart = 0;
    int fPartLen = 0;
    int i = 0;
    int sign = 1;

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
        iPart = iPart * 10 + float(str[i]) - '0';
        i++;
    }
    i++;
    while (str[i] != '\0') {
        if (str[i] < '0' || str[i] > '9') return 1;
        fPart = fPart * 10 + float(str[i]) - '0';
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

int getInput(char* argv[], float* num1, float* num2, char* op) {
    if (getFloat(argv[1], num1) || getFloat(argv[3], num2)) {
        printf("%s", "Error: Invalid number\n");
        return 1;
    }
    *op = argv[2][0];
    if (*op != '+' && *op != '-' && *op != 'x' && *op != '/' && *op != '%') {
        printf("%s", "Error: Invalid operator\n");
        return 1;
    }
    return 0;
}

void calc(float num1, float num2, char op) {
    switch (op) {
        case '+':
            printf("%f\n", num1 + num2);
            return;
        case '-':
            printf("%f\n", num1 - num2);
            return;
        case 'x':
            printf("%f\n", num1 * num2);
            return;
        case '/':
            printf("%f\n", num1 / num2);
            return;
        case '%':
            printf("%d\n", int(num1) % int(num2));
            return;
    }
}

int main(int argc, char* argv[]) {
    if (checkInput(argc)) return 1;

    float num1 = 0;
    float num2 = 0;
    char op = argv[2][0];

    if (getInput(argv, &num1, &num2, &op)) return 1;

    calc(num1, num2, op);

    return 0;
}