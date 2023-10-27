#include <stdio.h>
#include <time.h>
#include <string.h>

typedef void (*FunctionPointer)();

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
    // use clock() time.h
    clock_t start, end;

    start = clock();
    func();
    end = clock();

    double runTime = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("%f\n", runTime);
}

void judgeOpt_before(){
    int a1 = 1, a2 = 2, a3 = 3;
    int a = 4, b = 5;
    
    if ( (a1 != 0) && (a2 != 0) && ( a3 != 0) ){
        a = a + b;
    }
}

void judgeOpt_after(){
    int a1 = 1, a2 = 2, a3 = 3;
    int a = 4, b = 5;
    int temp = (a1 && a2 && a3);

    if( temp != 0){
        a = a + b;
    }
}

void optOrder_before(){
    int x;
    int a = 4, b = 5;
    
    if(a > 0)
        x = a;
    else
        x = b;
    printf("生成选择指令，移除分支可以实现优化\n");
}

void optOrder_after(){
    int x;
    int a = 4, b = 5;
    
    x = (a > 0 ? a : b);
    printf("使用三目运算\n");
}

void start(){

    counTime(judgeOpt_before);
    counTime(judgeOpt_after);

    counTime(optOrder_before);
    printf("-----------------------------------------------------------------------------\n");
    counTime(optOrder_after);
}