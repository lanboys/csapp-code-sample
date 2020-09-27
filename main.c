#include "csapp.h"
#include <stdio.h>

int main(int argc, char **argv) {
    int a, b, c;

    printf("请输入三个数字：");
    scanf("%d, %d, %d", &a, &b, &c);
    printf("%d,%d,%d\n", a, b, c);
    return 0;
}