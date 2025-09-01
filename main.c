#include <stdio.h>
#include "scheduler.h"


int main(void){
    
    unsigned short u8control;
    unsigned short u8funcionalidad; // Corregida errata en el nombre de la variable
    do
    {
        printf("\nRecursos(1) Tareas(2) Salir(0): ");
        scanf("%hu", &u8control);
        
        switch (u8control)
        {
            case 1:
                printf("Recurso: Create (1), Start(2), Stop(3), Delete(4), List(5): ");
                scanf("%hu", &u8funcionalidad);
                switch (u8funcionalidad)
                {
                    /*Crear recurso*/
                    case 1:
                        printf("crear");
                        break;

                    /*Iniciar Recurso*/
                    case 2:
                        printf("iniciar");
                        break;

                    /*Detener Recurso*/
                    case 3:
                        printf("detener");
                        break;

                    /*Eliminar Recurso*/
                    case 4:
                        printf("eliminar");
                        break;

                    /*Listar Recursos*/
                    case 5:
                        printf("listar");
                        break;
                    /**/
                    default:
                        break;
                }

                break;
            
            case 2:
                printf("Tarea: Create (1), Start(2), Stop(3), Delete(4), List(5): ");
                scanf("%hu", &u8funcionalidad);
                switch (u8funcionalidad)
                {
                    /*Crear recurso*/
                    case 1:
                        printf("crear");
                        break;

                    /*Iniciar Recurso*/
                    case 2:
                        printf("iniciar");
                        break;

                    /*Detener Recurso*/
                    case 3:
                        printf("detener");
                        break;

                    /*Eliminar Recurso*/
                    case 4:
                        printf("eliminar");
                        break;
                    /*Listar Recursos*/

                    case 5:
                        printf("listar");
                        break;
                    /**/
                    default:
                        break;
                }
                break;
            
            
            case 0: // Caso explícito para salir
                break;

            default:
                printf("Opción no válida. Por favor, intente de nuevo.\n");
            break;
        }

    } while (u8control != 0);

    scheduler_init();
    scheduler_run();

    return 0;
}