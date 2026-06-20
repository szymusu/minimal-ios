cmake_minimum_required(VERSION 4.2)
project(minimal_ios C)

set(CMAKE_C_STANDARD 11)

add_executable(minimal_ios
        main.c)

target_link_libraries(${PROJECT_NAME} "-framework Foundation")
target_link_libraries(${PROJECT_NAME} "-framework UIKit")
target_link_libraries(${PROJECT_NAME} objc)
