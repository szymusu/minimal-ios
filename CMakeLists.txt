cmake_minimum_required(VERSION 4.2)
project(minimal_ios C)

set(CMAKE_C_STANDARD 11)

execute_process(
        COMMAND xcrun --sdk iphonesimulator --show-sdk-path
        OUTPUT_VARIABLE IOS_SDK
        OUTPUT_STRIP_TRAILING_WHITESPACE
)

#set(CMAKE_OSX_SYSROOT "${IOS_SDK}")

add_executable(minimal_ios
        src/main.c
        src/print.c
        src/print.h
        src/NSString.c
        src/NSString.h)

target_link_libraries(${PROJECT_NAME} "-framework Foundation")
#target_link_libraries(${PROJECT_NAME} "-framework UIKit")
target_link_libraries(${PROJECT_NAME} objc)
