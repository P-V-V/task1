add_definitions(-std=c++11)

set(SOURCE_FILES task1.cpp task1.h task1_internal.cpp task1_internal.h)

add_executable(task1 ${SOURCE_FILES})
add_library(task1_lib STATIC ${SOURCE_FILES})
