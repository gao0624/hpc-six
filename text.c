#include <stdio.h>
#include <time.h>
#include <string.h>

typedef void (*FunctionPointer)();

// use clock() time.h
clock_t start_t, end_t;

int a1 = 1, a2 = 2, a3 = 3;
int a = 4, b = 5;
int x;
int temp = ( 1 && 2 && 3 );

void counTime(FunctionPointer func);
void judgeOpt_before();
void judgeOpt_after();
void optOrder_before();
void optOrder_after();
void start();

int main()
{
    /**
     * start
    */
    start();
    return 0;
}

void counTime(FunctionPointer func){

    start_t = clock();
    for (long i = 0; i < 1000000000; i++) {
        // 这里可以放您的代码
        func();
    }
    end_t = clock();

    double runTime = ((double)(end_t - start_t)) / CLK_TCK;
    printf("%f\n", runTime);
}

void judgeOpt_before(){
    
    if ( (a1 != 0) && (a2 != 0) && ( a3 != 0) ){
        int sum = a + b;
    }
}

void judgeOpt_after(){
    
    if( temp ){
        int sum = a + b;
    }
}

void optOrder_before(){
    
    if(a > 0)
        x = a;
    else
        x = b;
}

void optOrder_after(){
    x = (a > 0 ? a : b);
}

void start(){

    counTime(judgeOpt_before);
    printf("-----------------------------------------------------------------------------\n");
    counTime(judgeOpt_after);

    printf("\n");

    counTime(optOrder_before);
    printf("-----------------------------------------------------------------------------\n");
    counTime(optOrder_after);
}