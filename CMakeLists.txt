cmake_minimum_required(VERSION 3.0.0)
project(sodoku VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()
file(GLOB source
    "src/**/*.h"
    "src/**/*.cpp"
    "src/**/**/*.h"
    "src/**/**/*.cpp"
)

add_executable(sodoku src/main.cpp ${source})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
