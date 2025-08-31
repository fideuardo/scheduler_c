#include <stdio.h>
#include "task2c1.h"
#include "task2ca.h"

void task2_vInit(void)
{
    printf("Task 2 Init\n");
    task2_vinit1();
    task2_vinit2();
}

void task2_vDeinit(void)
{
    printf("Task 2 DeInit\n");
    task2_vdeinit1();
    task2_vdeinit2();
}

void task2_vCyclic100ms(void)
{
    printf("Task 2 Cyclic 100ms\n");
    task2_vcyclic100ms_1();
    task2_vcyclic100ms_2();
}