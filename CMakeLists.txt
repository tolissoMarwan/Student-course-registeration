cmake_minimum_required(VERSION 3.27)
project("Student-course-registeration")

set(CMAKE_CXX_STANDARD 20)

# Add the source files to the project
add_executable(${PROJECT_NAME}
    main.cpp
    course.h
)

# You can also set the output directory for the executable if you want.
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
