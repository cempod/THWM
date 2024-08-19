cmake_minimum_required(VERSION 3.22)

set(SCRS
    ${CMAKE_CURRENT_LIST_DIR}/Src/system_stm32h7xx.c
)

add_library(CMSIS INTERFACE)
target_sources(LL_Drivers INTERFACE ${SCRS})
target_include_directories(CMSIS INTERFACE 
    ${CMAKE_CURRENT_LIST_DIR}/Inc
    rootlib
)
target_compile_definitions(CMSIS INTERFACE rootlib)
target_link_libraries(CMSIS INTERFACE
    rootlib
)