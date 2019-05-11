# CMakeList.txt: проект CMake для OOPZI_task2; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#
add_library(Lib_nasled STATIC "task_int_data.cpp")
target_include_directories(Lib_nasled PUBLIC "../header")
# TODO: Добавьте тесты и целевые объекты, если это необходимо.
