#include <stdio.h>

int main(){
    int x;
    x = 4;
    int y = 9;
    int temp = x;

    x = y;
    y = temp; 
    printf("%d %d", x, y);

    return 0;
}