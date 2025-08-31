#include "scheduler.h"
#include "schedulertp.h"
#include "task1c1.h"
#include "task2c1.h"
#include <windows.h> // Required for Sleep() on Windows

const task_t tasks[] = {
    {task1_vInit, task1_vDeinit, task1_vCyclic100ms},
    {task2_vInit, task2_vDeinit, task2_vCyclic100ms}
};

void scheduler_init(){

}

void scheduler_run(void) {
    // Initialize all tasks
    for (int i = 0; i < sizeof(tasks)/sizeof(tasks[0]); i++) {
        if (tasks[i].init) {
            tasks[i].init();
        }
    }

    // Main scheduling loop
    while (1) {
        // Call cyclic functions every 100ms
        for (int i = 0; i < sizeof(tasks)/sizeof(tasks[0]); i++) {
            if (tasks[i].cyclic100ms) {
                tasks[i].cyclic100ms();
            }
        }
        Sleep(100); // Wait for 100ms
    }

    // Deinitialize all tasks before exiting (not reached in this infinite loop in this design)
    for (int i = 0; i < sizeof(tasks)/sizeof(tasks[0]); i++) {
        if (tasks[i].deinit) {
            tasks[i].deinit();
        }
    }
}