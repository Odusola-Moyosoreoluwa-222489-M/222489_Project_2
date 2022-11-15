#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int determineNoOfSteps(char *testCase);

int main(){
    clock_t start, end;
    double execution_time;
    start = clock();
    int noOfTests;

    FILE *fp;
    fp = fopen("adam.in", "r");
    if (fp == NULL)
    {
        printf("File doesn't exist");
        exit(0);
    }
    
    fscanf(fp, "%d", &noOfTests);

    for (int i = 0; i < noOfTests; i++)
    {
        char steps[100];
        fscanf(fp, "%s", steps);
        printf("%d \n", determineNoOfSteps(steps));

    }

    end = clock();
    execution_time = ((double)(end - start))/CLOCKS_PER_SEC;

    printf("Time taken to run is %f", execution_time);

    return 0;
}

int determineNoOfSteps(char *testCase){
    int position = 0;

    for (int i = 0; i < strlen(testCase); i++)
    {
        if (testCase[i] == 'U')
        {
            position++;
        }
        else
        {
            return position;
        }
    }
    return position;
}