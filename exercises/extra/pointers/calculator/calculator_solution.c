#include "calculator.h"

int get_num(char ** expr) {
    int num = 0;
    while (1) {
        char cur = **expr;
        if (cur == '\0' || cur == '+' || cur == '-') {
            break;
        }

        num = 10 * num + (cur - '0');
        (*expr)++;
    }
    return num;
}

int calculate(char * expr) {
    int res = get_num(&expr);

    while (*expr != '\0') {
        char operator = *expr;
        expr++;

        int cur_num = get_num(&expr);

        if (operator == '+') {
            res += cur_num;
        } else {
            res -= cur_num;
        }
    }

    return res;
}
