#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
int main()
{
    int n, m;
    float x;
    bool while_flow = true;
    while(while_flow){
        printf("Enter the first number\n");
        scanf("%d", &n);
        printf("Enter the second number\n");
        scanf("%d", &m);
        if(n > 0 && m > 0){
            while_flow = false;
        }else{
            while_flow = true;
            printf("You must enter values higher than 0!\n");
        }
    }
    x = n / (float) m;
    printf("The the result of %d/%d= %.50f", n, m, x);
}

