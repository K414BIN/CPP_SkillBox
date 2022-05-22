# CMakeList.txt: проект CMake для CMakeProject; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#
cmake_minimum_required (VERSION 3.8)

# Добавьте источник в исполняемый файл этого проекта.
add_executable (CMakeProject "CMakeProject.cpp" "CMakeProject.h" "disk.h" "ram.h" "kbd.h" "cpu.h" "gpu.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET CMakeProject PROPERTY CXX_STANDARD 14)
endif()

# TODO: Добавьте тесты и целевые объекты, если это необходимо.
