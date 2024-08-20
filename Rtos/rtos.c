#include "rtos.h"
#include "display.h"
#include "backlight.h"

TaskHandle_t display_task_handle;
TaskHandle_t backlight_task_handle;

void
threads_init(void) {
    xTaskCreate(display_task, "display task", configMINIMAL_STACK_SIZE*5, NULL, configMAX_PRIORITIES - 1, &display_task_handle);
    xTaskCreate(backlight_task, "backlight task", configMINIMAL_STACK_SIZE*1, NULL, configMAX_PRIORITIES - 1, &backlight_task_handle);
}

#if ( configCHECK_FOR_STACK_OVERFLOW > 0 )

    void vApplicationStackOverflowHook( TaskHandle_t xTask,
                                        char * pcTaskName )
    {
        /* Check pcTaskName for the name of the offending task,
         * or pxCurrentTCB if pcTaskName has itself been corrupted. */
        ( void ) xTask;
        ( void ) pcTaskName;
    }

#endif /* #if ( configCHECK_FOR_STACK_OVERFLOW > 0 ) */