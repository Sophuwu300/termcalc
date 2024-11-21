#include "calc.hpp"

int getFloat(strr str, flt_t& n) {
    n = 0.0f;
    for (long j = long(str[0] == '-'); j < str.length(); j++)
        if (str[j] >= '0' && str[j] <= '9') n = n * 10 + flt_t(str[j] - '0');
        else if (str[j] == '.')
            for (long i = j++; j < str.length(); j++)
                if (str[j] >= '0' && str[j] <= '9') n += (flt_t(str[j] - '0') / pow(10, j-i));
                else return 1;
        else return 1;
    n*=1-2*(str[0]=='-');
    return 0;
}

op_t ops = {
    {strr("+"), fptr([](flt_t a, flt_t b){ return flt_t(a + b); })},
    {strr("-"), fptr([](flt_t a, flt_t b){ return flt_t(a - b); })},
    {strr("x"), fptr([](flt_t a, flt_t b){ return flt_t(a * b); })},
    {strr("*"), fptr([](flt_t a, flt_t b){ return flt_t(a * b); })},
    {strr("/"), fptr([](flt_t a, flt_t b){ return flt_t(a / b); })},
    {strr("^"), fptr([](flt_t a, flt_t b){ return flt_t(pow(a, b)); })},
    {strr("%"), fptr([](flt_t a, flt_t b){ return flt_t(int_t(a)%int_t(b)); })}
};

int calc(strr n1,strr opi, strr n2) {
    char bf[128]="error: invalid input";
    flt_t num1, num2;
    fptr op = ops[opi];
    if (op == nullptr || getFloat(n1, num1) || getFloat(n2, num2))return puts("error: invalid input");
    flt_t ans = op(num1, num2);
    int n = snprintf(bf, 128, "%.12Lf", ans);
    for (n--;n>0;n--) {
        if (bf[n] != '0') {
            if (bf[n] != '.')n++;
            break;
        }
    }
    bf[n]='\0';
    puts(bf);
    return 0;
}

void help(char* argv) {
    printf("Usage:\t%s [number] [operator] [number]\n", argv);
    printf("\t%s [operator]\n\n", argv);
    puts("If numbers are not provided, they will be read from stdin.");
    puts("Supported operators: + - x / ^ %");
    exit(0);
}

int main(int argc, char* argv[]) {
    if (argc == 2&&(ops[strr(argv[1])]!=nullptr)) {
        strr in[2]={"",""};
        int i = 0;
        char c = getchar();
        while(c != EOF) {
            if (c == '\n'||c == ' ')if(i) break; else i++;else in[i] += c;
            c = getchar();
        }
        return 0!=calc(in[0], argv[1], in[1]);
    }
    if (argc == 4) return 0!=calc(argv[1], argv[2], argv[3]);
    help(argv[0]);
    return 0;
}