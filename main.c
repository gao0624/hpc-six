#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef void (*FunctionPointer)();

// use clock() time.h
// clock_t start_t, end_t;

int a1 = 1, a2 = 2, a3 = 3;
int a = 4, b = 5;
int x;
int ifZero,score,ranNum;
char msg[] = { 'D','D','D','D','D','D','D','C','B','A' };

void counTime(FunctionPointer func);
void initValue();
void judgeOpt_before();
void judgeOpt_after();
void optOrder_before();
void optOrder_after();
void rmBranch_before();
void rmBranch_after();
void start();

int main()
{
    /**
     * start
    */
    start();
    return 0;
}

void initValue(){
    /**
     * creat random num 1-100 srand: prevent same num
    */
    srand(time(NULL));
    ranNum = rand() % 100 + 1;
    printf("%d\n",ranNum);

    /**
     * ranNum -> score
    */
    score = ranNum;

    /**
     * if && zero
    */
    ifZero = ( a1 && a2 && a3 );
}

void counTime(FunctionPointer func){
    /**
     * ns
    */
    struct timespec start_time, end_time;
    unsigned long long elapsed_time;

    clock_gettime(CLOCK_MONOTONIC, &start_time);
    func();
    clock_gettime(CLOCK_MONOTONIC, &end_time);

    elapsed_time = (end_time.tv_sec - start_time.tv_sec) * 1000000000ULL + (end_time.tv_nsec - start_time.tv_nsec);
    printf("Execution Time: %llu ns\n", elapsed_time);

    // start_t = clock();
    // for (long i = 0; i < 3000000000; i++) {
    //     func();
    // }
    // end_t = clock();

    // double runTime = ((double)(end_t - start_t)) / CLOCKS_PER_SEC;
    // printf("%f\n", runTime);
}

void judgeOpt_before(){
    
    if ( (a1 != 0) && (a2 != 0) && ( a3 != 0) ){
        int sum = a + b;
    }
}

void judgeOpt_after(){
    
    if( ifZero ){
        int sum = a + b;
    }
}

void optOrder_before(){

    if(a > 0){
        x = a;
    }else
        x = b;
}

void optOrder_after(){
    x = (a > 0 ? a : b);
}

void rmBranch_before(){

    if( score >= 90 ){
        //printf("A")
    }
    else if( score >= 80 ){
        //printf("B")
    }
    else if( score >= 70 ){
        //printf("C")
    }
    else{
        //printf("D")
    }
}

void rmBranch_after(){
    msg[score/10];
    //printf("%c",msg[score/10])
}

void start(){
    /**
     * initValue
    */
    initValue();

    counTime(judgeOpt_before);
    printf("-----------------------------------------------------------------------------\n");
    counTime(judgeOpt_after);

    printf("\n");

    counTime(optOrder_before);
    printf("-----------------------------------------------------------------------------\n");
    counTime(optOrder_after);

    printf("\n");
    counTime(rmBranch_before);
    printf("-----------------------------------------------------------------------------\n");
    counTime(rmBranch_after);
}