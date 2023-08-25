 #include <stdio.h>
 #include <math.h>
int main() {
    int num,rem,a;
    printf("Enter a number: ");
    scanf("%d", &num);
    while(num>0){
        rem=num%10;
        a=a+pow(rem,3);
    }

    if(num==a){
        printf("Armstrong Number ");
     }
    else {
        printf("not an Armstrong number");
     }
 return 0;
}
