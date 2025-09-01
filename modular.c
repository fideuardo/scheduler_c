#include <stdio.h>
#include "scheduler.h"

#define TASKS_N 2
#define TICK_VAL 100

static Task_TypeDef tasks[ TASKS_N ];
static Scheduler_HandleTypeDef Sche;

void Init_500ms(void);
void Init_1000ms(void);
void Task_500ms(void);
void Task_1000ms(void);

int main( void )
{
    unsigned char TaskID1;
    unsigned char TaskID2;

    /*init the scheduler with two tasks and a tick time of 100ms and run for 10 seconds only*/
    Sche.tick = TICK_VAL;
    Sche.tasks = TASKS_N;
    Sche.timeout = 10000;
    Sche.taskPtr = tasks;
    HIL_SCHEDULER_InitScheduler( &Sche );

    /*register two task with thier corresponding init fucntions and their periodicyt, 100msand 500ms*/
    TaskID1 = HIL_SCHEDULER_RegisterTask( &Sche, Init_500ms, Task_500ms, 500 );
    TaskID2 = HIL_SCHEDULER_RegisterTask( &Sche, Init_1000ms, Task_1000ms, 1000 );

    /*run the scheduler for the mount of time stablished in Sche.timeout*/
    HIL_SCHEDULER_StartScheduler( &Sche );
    return 0;
}

void Init_500ms(void)
{
    printf("Init task 500 millisecond");
}

void Init_1000ms(void)
{
    printf("Init task 1000 millisecond");
}

void Task_500ms(void)
{
    static int loop = 0;
    printf("This is a counter from task 500ms: %d", loop++);
}

void Task_1000ms(void)
{
    static int loop = 0;
    printf("This is a counter from task 1000ms: %d", loop++);
}