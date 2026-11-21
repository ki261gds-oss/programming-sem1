#include <stdio.h>

int gcd_stats(int a, int b);
int steps(int add);


int gcd_stats(int a, int b) {
    while (b !=0){
        int c = a % b;
        a = b;
        b = c;
        steps(1);

    }
    return a;



}

int steps(int add) {
static int count = 0;
if(add !=0)
count++;
return count;


}


int main(void) {
    int a, b;
    printf("Enter two integers: ");

    if (scanf("%d %d", &a, &b) != 2) {
        printf("Input error!\n");
        return 1;
    }
    int result = gcd_stats(a, b);
    printf("GCD of %d and %d is %d\n", a, b, result);

    printf("Number of steps taken: %d\n", steps(0));

    return 0;
}
