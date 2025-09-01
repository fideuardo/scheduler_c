#include "scheduler.h"
#include "schedulertp.h"
#include "task1c1.h"
#include "task2c1.h"
#if defined(_WIN32) || defined(_WIN64)
#include <windows.h> // Para Sleep() en Windows
#else
#include <unistd.h>  // Para sleep() en Linux/Unix
#endif

const task_t tasks[] = {
    {task1_vInit, task1_vDeinit, task1_vCyclic100ms},
    {task2_vInit, task2_vDeinit, task2_vCyclic100ms}
};

void scheduler_init(){
    // Initialize all tasks
    for (int i = 0; i < sizeof(tasks)/sizeof(tasks[0]); i++) {
        if (tasks[i].init) {
            tasks[i].init();
        }
    }
}

void scheduler_run(void) {
    // Main scheduling loop
    while (1) {
        // Call cyclic functions every 100ms
        for (int i = 0; i < sizeof(tasks)/sizeof(tasks[0]); i++) {
            if (tasks[i].cyclic100ms) {
                tasks[i].cyclic100ms();
            }
        }
        sleep(100); // Esperar 100ms usando la función de abstracción correcta
    }

    // Deinitialize all tasks before exiting (not reached in this infinite loop in this design)
    for (int i = 0; i < sizeof(tasks)/sizeof(tasks[0]); i++) {
        if (tasks[i].deinit) {
            tasks[i].deinit();
        }
    }
}

void SleepTask(int ms) {
#ifdef _WIN32
    sleep(ms); // En Windows, Sleep() usa milisegundos
#else
    usleep(ms * 1000); // usleep usa microsegundos, por eso se multiplica por 1000
#endif
}