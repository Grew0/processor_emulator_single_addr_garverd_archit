cmake_minimum_required(VERSION 3.16)

project(main LANGUAGES CXX)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug)
endif()

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_FLAGS "-Wall -Wextra")
set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

set(SOURCES
proc/commands.cpp
proc/proc.cpp

gdeb/debbuger.cpp
gdeb/panes/disasm_pane.cpp
gdeb/panes/registers_pane.cpp
gdeb/panes/mem_pane.cpp
)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})
add_executable(main main.cpp ${SOURCES})

target_link_libraries(main sfml-graphics sfml-window sfml-system)
target_precompile_headers(main PRIVATE 
	<SFML/Graphics.hpp>
)
