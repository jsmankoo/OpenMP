#include <stdio.h>
#include <omp.h>
#include <cstdlib> // atoi()



//Code doesnt scale well with the number of threads cause of FALSE SHARING
int main(int argc, char** argv){
    if(argc != 3){
        printf("Usage: %s noOfThreads totalSteps\n", argv[0]);
        return 0;
    }

    int numThreads = atoi(argv[1]);
    long totalSteps = atol(argv[2]);


    // Use points in arrays to record data from different threads
    double sum[numThreads];
    double step = 1.0/totalSteps;
    double pi = 0.0;

    //Request num of threads
    omp_set_num_threads(numThreads);
    #pragma omp parallel
    {
        // ID ranges from 0 to nThreads-1
        int ID = omp_get_thread_num();
        //May not be the same as numThreads
        int nThreads = omp_get_num_threads();
        sum[ID] = 0.0;

        //confirm that you got the numThreads that you requested
        if(ID == 0) numThreads = nThreads;

        for(int i=ID; i < totalSteps; i += nThreads){
            double x = (i + 0.5)*step;
            sum[ID] += 4.0/(1.0 + x*x);
        }
    }

    for(int i=0; i<numThreads; i++){
        printf("Sum[%d] = %f\n", i, sum[i]);
        pi += sum[i];
    }
    pi *= step;
    printf("Pi = %f\n", pi);

    return 1;
}
