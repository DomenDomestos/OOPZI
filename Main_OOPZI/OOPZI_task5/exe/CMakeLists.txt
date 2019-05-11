# CMakeList.txt: проект CMake для OOPZI_task2; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#

# Добавьте источник в исполняемый файл этого проекта.
add_executable (version_2 "task_main.cpp")
target_link_libraries(version_2  Lib_nasled)
# TODO: Добавьте тесты и целевые объекты, если это необходимо.
