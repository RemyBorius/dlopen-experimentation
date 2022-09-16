cmake_minimum_required(VERSION 3.22)
project(dlopen-experimentation)

set(CMAKE_CXX_STANDARD 20)

### case 1 ###
# the hello shared library
add_library(hello SHARED
        ./case_1/hello.cpp)

# the executable that ll use the hello shared lib
add_executable(case_1_dlopen
        ./case_1/main.cpp)

### case 2 ###
# the hello2 shared library
add_library(hello2 SHARED
        ./case_2/hello2.cpp)

# the executable that ll use the hello shared lib
add_executable(case_2_dlopen
        ./case_2/main_dlopen_class.cpp)

### case 3 ###
# the hello3 shared library
add_library(hello3 SHARED
        ./case_3/hello3.cpp)
add_library(helloTampon SHARED
        ./case_3/helloTampon.cpp)
target_link_libraries(helloTampon hello3)

# the executable that ll use the hello shared lib
add_executable(case_3_dlopen
        ./case_3/main_dlopen_class3.cpp)

### case 4 ###
# the hello4 shared library
add_library(hello4 SHARED
        ./case_4/hello4.cpp)
add_library(helloTampon4 SHARED
        ./case_4/helloTampon4.cpp)
target_link_libraries(helloTampon4 hello4)

# the executable that ll use the hello shared lib
add_executable(case_4_dlopen
        ./case_4/main_dlopen_class4.cpp)
