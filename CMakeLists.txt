cmake_minimum_required(VERSION 3.8.0)
project(33_1_shopping_baskets VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

add_executable(33_1_shopping_baskets main.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
