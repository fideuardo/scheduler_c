#ifndef SCHEDULER_H
#define SCHEDULER_H
#include <stdint.h>
#include "schedulertp.h"


void HIL_SCHEDULER_InitScheduler( Scheduler_HandleTypeDef *hscheduler );
void HIL_SCHEDULER_StartScheduler( Scheduler_HandleTypeDef *hscheduler );

uint8_t HIL_SCHEDULER_RegisterTask( Scheduler_HandleTypeDef *hscheduler, void (*initPtr)(void), void (*taskPtr)(void), uint32_t period );
uint8_t HIL_SCHEDULER_StartTask( Scheduler_HandleTypeDef *hscheduler, uint8_t task );
uint8_t HIL_SCHEDULER_StopTask( Scheduler_HandleTypeDef *hscheduler, uint8_t task );
uint8_t HIL_SCHEDULER_PeriodTask( Scheduler_HandleTypeDef *hscheduler, uint8_t task, uint32_t period );

#endif /* SCHEDULER_H */
