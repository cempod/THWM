cmake_minimum_required(VERSION 3.22)

set(SCRS
    ${CMAKE_CURRENT_LIST_DIR}/rtos.c
    ${CMAKE_CURRENT_LIST_DIR}/Tasks/Display_task/display.cpp
    ${CMAKE_CURRENT_LIST_DIR}/Tasks/Display_task/theme_manager.cpp
    ${CMAKE_CURRENT_LIST_DIR}/Tasks/Backlight_task/backlight.cpp
    ${CMAKE_CURRENT_LIST_DIR}/Tasks/Display_task/Pages/page_manager.cpp
    ${CMAKE_CURRENT_LIST_DIR}/Tasks/Display_task/Pages/Main_page/main_page.cpp
    ${CMAKE_CURRENT_LIST_DIR}/Tasks/Display_task/Pages/Settings_page/settings_page.cpp
    ${CMAKE_CURRENT_LIST_DIR}/Tasks/Display_task/Pages/Settings_page/Sub_pages/display_sub_page.cpp
    ${CMAKE_CURRENT_LIST_DIR}/Tasks/Display_task/Pages/Settings_page/Sub_pages/about_sub_page.cpp
    ${CMAKE_CURRENT_LIST_DIR}/Tasks/Display_task/Pages/Settings_page/Sub_pages/date_time_sub_page.cpp
    ${CMAKE_CURRENT_LIST_DIR}/Tasks/Display_task/Pages/Objects/sensor_card.cpp
    ${CMAKE_CURRENT_LIST_DIR}/Tasks/Display_task/Pages/Objects/calendar_card.cpp
    ${CMAKE_CURRENT_LIST_DIR}/Tasks/Display_task/Pages/Objects/label.cpp
    ${CMAKE_CURRENT_LIST_DIR}/Tasks/Display_task/Pages/Objects/top_panel.cpp
    ${CMAKE_CURRENT_LIST_DIR}/Tasks/Display_task/Pages/Fonts/open_sans_18.c
    ${CMAKE_CURRENT_LIST_DIR}/Tasks/Display_task/Pages/Fonts/comfortaa_12.c
    ${CMAKE_CURRENT_LIST_DIR}/Tasks/Display_task/Pages/Fonts/comfortaa_16.c
)

add_library(Rtos INTERFACE)
target_sources(LL_Drivers INTERFACE ${SCRS})
target_include_directories(Rtos INTERFACE 
    ${CMAKE_CURRENT_LIST_DIR}/
    ${CMAKE_CURRENT_LIST_DIR}/Tasks/Display_task/
    ${CMAKE_CURRENT_LIST_DIR}/Tasks/Backlight_task/
    ${CMAKE_CURRENT_LIST_DIR}/Tasks/Display_task/Pages
    ${CMAKE_CURRENT_LIST_DIR}/Tasks/Display_task/Pages/Main_page/
    ${CMAKE_CURRENT_LIST_DIR}/Tasks/Display_task/Pages/Settings_page/
    ${CMAKE_CURRENT_LIST_DIR}/Tasks/Display_task/Pages/Settings_page/Sub_pages/
    ${CMAKE_CURRENT_LIST_DIR}/Tasks/Display_task/Pages/Objects/
    rootlib
)
target_compile_definitions(Rtos INTERFACE rootlib)
target_link_libraries(CMSIS INTERFACE
    rootlib
)