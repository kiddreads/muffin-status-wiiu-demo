cmake_minimum_required(VERSION 3.13)
project(muffin_status_demo C)

if(NOT DEFINED DEVKITPRO)
    set(DEVKITPRO $ENV{DEVKITPRO})
endif()
include("${DEVKITPRO}/wut/share/wut.cmake" REQUIRED)

add_executable(muffin_status_demo src/main.c)

if(NOT DEFINED MUFFIN_HEAD)
    set(MUFFIN_HEAD "unknown")
endif()
if(NOT DEFINED MUFFIN_DATE)
    set(MUFFIN_DATE "unknown")
endif()
target_compile_definitions(muffin_status_demo PRIVATE
    MUFFIN_HEAD="${MUFFIN_HEAD}"
    MUFFIN_DATE="${MUFFIN_DATE}"
)

target_link_libraries(muffin_status_demo whb)

wut_create_rpx(muffin_status_demo)
