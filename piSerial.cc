#include <stdio.h>
#include <cstdlib>      //atol()

int main(int argc, char** argv){
    if(argc != 2){
        printf("Usage: %s noOfSteps\n", argv[0]);
        return 1;
    }

    long noOfSteps = atol(argv[1]);
    double step = 1.0/noOfSteps;
    double pi = 0.0;

    for(int i=0; i<noOfSteps; i++){
        double x = (i + 0.5)*step;
        pi += 4.0/(1.0 + x*x);
    }
    pi *= step;
    printf("%f\n", pi);
    return 0;
}
