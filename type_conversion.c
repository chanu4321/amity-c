#include <stdio.h>
int main() {
    int a = (int) 1.999999; // explicit conversipon using (int), no round off
    printf("%d",a);
    return 0;
}