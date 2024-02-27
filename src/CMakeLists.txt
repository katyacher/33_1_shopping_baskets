cmake_minimum_required(VERSION 3.8.0)

add_executable(33_1_shopping_baskets main.cpp  ${MY_INCLUDE_DIR}/Storage.h Storage.cpp )

target_include_directories(33_1_shopping_baskets PUBLIC ${MY_INCLUDE_DIR})