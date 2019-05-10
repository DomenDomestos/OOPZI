# CMakeList.txt: проект CMake для OOPZI_task2; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#
add_library(tlib STATIC "Func_p_1.c" "Func_p_2.c")
target_include_directories(tlib PUBLIC "../header")
# TODO: Добавьте тесты и целевые объекты, если это необходимо.
