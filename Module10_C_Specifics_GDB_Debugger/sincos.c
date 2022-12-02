#include <stdio.h>
#include <math.h>
#define PI 3.14159265

// Task 2. Build the GetSinCos() function
void GetSinCos(int d, double *dSin, double *dCos){
    *dSin = sin(d*PI/180);
    *dCos = cos(d*PI/180);
}


int main(){
    double dSin;
    double dCos;
    int degree;

    // Task 1. Read in user input to variable degree
    scanf("%d", &degree);

    // Task 3. Call the GetSinCos() function
    GetSinCos(degree, &dSin, &dCos);

    printf( "The sin is %g \n",dSin );
    printf( "The cos is %g \n",dCos );
    
    return 0;
}

// compile with `gcc sincos.c -o sincos -lm`
