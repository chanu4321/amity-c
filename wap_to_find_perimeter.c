#include <stdio.h>
int main() {
    float a,b;
    printf("enter side a"); 
    scanf("%f",&a); //taking input for side a 
    printf("enter side b");
    scanf("%f",&b); //taking input for side b

    printf("perimeter is %f", 2*(a+b)); //calculating perimeter
    
    return 0;
}