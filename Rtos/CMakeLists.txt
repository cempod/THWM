cmake_minimum_required(VERSION 3.22)

set(SCRS
    ${CMAKE_CURRENT_LIST_DIR}/rtos.c
    ${CMAKE_CURRENT_LIST_DIR}/Tasks/Display_task/display.cpp
    ${CMAKE_CURRENT_LIST_DIR}/Tasks/Backlight_task/backlight.cpp
)

add_library(Rtos INTERFACE)
target_sources(LL_Drivers INTERFACE ${SCRS})
target_include_directories(Rtos INTERFACE 
    ${CMAKE_CURRENT_LIST_DIR}/
    ${CMAKE_CURRENT_LIST_DIR}/Tasks/Display_task/
    ${CMAKE_CURRENT_LIST_DIR}/Tasks/Backlight_task/
    rootlib
)
target_compile_definitions(Rtos INTERFACE rootlib)
target_link_libraries(CMSIS INTERFACE
    rootlib
)