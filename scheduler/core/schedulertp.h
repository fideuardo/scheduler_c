#ifndef SCHEDULERTP_H
#define SCHEDULERTP_H

#include <stdint.h>

    typedef struct _task
    {
        uint32_t period; /*How often the task shopud run in ms*/
        uint32_t elapsed; /*the current elapsed time*/
        void (*initFunc)(void); /*pointer to init task function*/
        void (*taskFunc)(void); /*pointer to task function*/
    }Task_TypeDef;

    typedef struct _scheduler
    {
        uint8_t tasks; /*number of task to handle*/
        uint32_t tick; /*the time base in ms*/
        uint32_t timeout; /*the number of milliseconds the scheduler should run*/
        uint8_t tasksCount; /*internal task counter*/
        Task_TypeDef *taskPtr; /*Pointer to buffer for the TCB tasks*/
    }Scheduler_HandleTypeDef;




#endif
