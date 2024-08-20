cmake_minimum_required(VERSION 3.22)

set(SCRS
    ${CMAKE_CURRENT_LIST_DIR}/st7796.c
)

add_library(st7796 INTERFACE)
target_sources(st7796 INTERFACE ${SCRS})
target_include_directories(st7796 INTERFACE 
    ${CMAKE_CURRENT_LIST_DIR}/
    rootlib
)
target_compile_definitions(st7796 INTERFACE rootlib)
target_link_libraries(st7796 INTERFACE
    rootlib
)