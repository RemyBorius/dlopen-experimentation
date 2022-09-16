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

#### case 2 bis ###
#add_library(triangle SHARED
#        ./case_2_bis/triangle.cpp)
## the executable that ll use the hello shared lib
#add_executable(case_2_bis
#        ./case_2_bis/main_2_bis.cpp)

### case 3 ###
# the hello2 shared library
add_library(hello3 SHARED
        ./case_3/hello3.cpp)

add_library(helloTampon SHARED
        ./case_3/helloTampon.cpp)

# the executable that ll use the hello shared lib
add_executable(case_3_dlopen
        ./case_3/main_dlopen_class3.cpp)
