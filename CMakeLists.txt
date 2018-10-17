# Mister Massive- СMake lists
project(mistermassive)

# Минимальная версия CMake
cmake_minimum_required(VERSION 3.4)

# Указываем стандарт C++17
set_target_properties(${TARGET} PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED YES
    CXX_EXTENSIONS NO
)

# Исполняемые файлы проекта
set(SRC 
"src/main.cpp"
"src/matrix.h")

add_executable(${PROJECT_NAME} ${SRC})