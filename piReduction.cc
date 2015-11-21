#include <stdio.h>
#include <omp.h>
#include <cstdlib>      //atol()

int main(int argc, char** argv){
    if(argc != 3){
        printf("Usage: %s noOfThreads noOfSteps\n", argv[0]);
        return 1;
    }

    int noOfThreads = atoi(argv[1]);
    long noOfSteps = atol(argv[2]);
    double step = 1.0/noOfSteps;
    double pi = 0.0;

    omp_set_num_threads(noOfThreads);
    #pragma omp parallel for reduction(+ : pi)
    for(int i=0; i<noOfSteps; i++){
        double x = (i + 0.5)*step;
        pi += 4.0/(1.0 + x*x);
    }
    pi *= step;
    printf("%f\n", pi);
    return 0;
}
