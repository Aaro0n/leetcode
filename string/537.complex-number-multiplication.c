/*
 * @lc app=leetcode id=537 lang=c
 *
 * [537] Complex Number Multiplication
 */

#define FORMAT "%d+%di"
#define BUF_SIZE 128

char* complexNumberMultiply(char* a, char* b) {
    int a1, a2, b1, b2;
    char buf[BUF_SIZE];
    sscanf(a, FORMAT, &a1, &a2);
    sscanf(b, FORMAT, &b1, &b2);
    snprintf(buf, BUF_SIZE, FORMAT, a1 * b1 - a2 * b2, a1 * b2 + a2 * b1);
    return strdup(buf);
}
