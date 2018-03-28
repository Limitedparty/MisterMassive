# Mister Massive- СMake lists
project(mistermassive)

# Минимальная версия CMake
cmake_minimum_required(VERSION 3.4)

# Исполняемые файлы проекта
set(SRC 
"src/main.cpp"
"src/mistermassive.h")

add_executable(${PROJECT_NAME} ${SRC})