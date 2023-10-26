#include <stdio.h>

void toh(int n, char x, char y, char z) {
    if(n==1) {
        printf("%c to %c\n",x,z);
        return;
    }
    toh(n-1,x,z,y);
    printf("%c to %c\n",x,z);
    toh(n-1,y,x,z);
}
int main()
{
    int n;
    printf("enter no. of disks: ");
    scanf("%d",&n);
    toh(n,'A','B','C');
    return 0;
}
