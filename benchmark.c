#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>

double getWallTime() {
	double currentTime;
    struct timeval tp;

    gettimeofday(&tp, NULL);
    currentTime = (double)(tp.tv_sec + tp.tv_usec/1000000.0);
    return currentTime;
}

void dummy(int a, int b, int c, int d) {
    return;
}

int main() {

	printf("Running Vector Triad Test...\n");
	//Declaring local variables
	int64_t niter = 100000; //1e2 to 1e8, 100 to 100,000,000
	int64_t runs = 100000;
	double startTime = 0.0;
	double endTime = 0.0;
	printf("%s: %llu\n", "N", niter);

	//Allocating memory for each array
	float *arrayA = (float*) malloc(niter * sizeof(float));
	float *arrayB = (float*) malloc(niter * sizeof(float));
	float *arrayC = (float*) malloc(niter * sizeof(float));
	float *arrayD = (float*) malloc(niter * sizeof(float));

    //Populating each array with test input
    int i = 1;
    int j = 1;
    for(i = 1; i < niter; i++) {
    	arrayA[i] = 5.0;
    	arrayB[i] = 1.0;
    	arrayC[i] = 2.0;
    	arrayD[i] = 3.0;
    }

    //Get the start time for how long the program runs
    printf("Starting Clock...\n");
    clock_t begin = clock();

    //Get the start time and write to a file
    startTime = getWallTime();

    //Looping through a given niter of runs
    for(i = 1; i < runs; i++) {
    	//temp

    	//Looping through the given size of the array
    	for(j = 1; j < niter; j++) {

    		//3 Loads and 1 Store
    		//arrayA[j] = arrayB[j] + arrayC[j] * arrayD[j];
            arrayA[j] = arrayB[j] + arrayC[j] * arrayD[j];

            if(arrayA[i] < 0) {
                dummy(arrayA[i],arrayB[i],arrayC[i], arrayD[i]);
            }
    	}
    }

    //Needed for the correct values to display
    printf("%s%f\n", "Value of arrayA[10]: ", arrayA[10]);

    //Get the end time and write to a file
    endTime = getWallTime();

    //Calculate the MFLOPS for the niter of operations
    double MFLOPS = (runs * niter * 2.0) / ((endTime - startTime) * 1000000);
    printf("%0.6f\n", MFLOPS);

    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("Time Spent: %f\n", time_spent);

    //Freeing the allocated memory
    free(arrayA);
    arrayA = NULL;
    free(arrayB);
    arrayB = NULL;
    free(arrayC);
    arrayC = NULL;
    free(arrayD);
    arrayD = NULL;
    

    printf("Finished...\n");
    return 0;
}
