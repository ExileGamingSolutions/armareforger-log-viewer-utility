cmake_minimum_required(VERSION 3.31)
project(armareforger-log-viewer-utility)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

file(GLOB_RECURSE sources "${CMAKE_SOURCE_DIR}/src/main/*.c"
  "${CMAKE_SOURCE_DIR}/src/main/*.cpp")
add_definitions(-DSOME_DEFINITION)
add_executable(armareforger-log-viewer-utility ${sources})
target_include_directories(armareforger-log-viewer-utility
  PRIVATE "${CMAKE_SOURCE_DIR}/src/include/")
