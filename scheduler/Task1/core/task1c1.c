#include <stdio.h>
#include "task1c1.h"
#include "task1ca.h"

void task1_vInit(void)
{
    printf("Task 1 Init\n");
    task1_vinit1();
    task1_vinit2();
}

void task1_vDeinit(void)
{
    printf("Task 1 DeInit\n");
    task1_vdeinit1();
    task1_vdeinit2();
}

void task1_vCyclic100ms(void)
{
    printf("Task 1 Cyclic 100ms\n");
    task1_vcyclic100ms_1();
    task1_vcyclic100ms_2();
}