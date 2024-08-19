#include "board.h"
#include "rtos.h"

int 
main(void) {
  board_init();

  threads_init();

  vTaskStartScheduler();
  
}
