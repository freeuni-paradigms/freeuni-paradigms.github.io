#include "calculator.h"

int get_num(char * expression, int * index) {
    int num = 0;
    while (expression[*index] != '\0' && expression[*index] != '+' && expression[*index] != '-') {
        num = 10 * num + (int)(expression[*index] - '0');
        (*index)++;
    }
    return num;
}

int calculate(char * expression) {
    int index = 0;
    int res = get_num(expression, &index);

    while (expression[index] != '\0') {
        char operator = expression[index++];

        int cur_num = get_num(expression, &index);

        if (operator == '+') {
            res += cur_num;
        } else {
            res -= cur_num;
        }
    }

    return res; 
}