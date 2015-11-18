#include <omp.h>
#include <stdio.h>

int main(){
    #pragma omp parallel
    {
        // ranges from 0 to OMP_THREAD_NUM-1 (4 in this case) env variable
        int ID = omp_get_thread_num();
        printf("Hello(%d)", ID);
        printf(" World(%d)\n", ID);
    }
    return 0;
}
