project(lab2)

set(SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
set(SOURCE ${SOURCE_DIR}/adds.c)

add_library(UTIL_LIB STATIC ${SOURCE})

add_executable(main ${SOURCE_DIR}/main.c)
target_link_libraries(main UTIL_LIB)
