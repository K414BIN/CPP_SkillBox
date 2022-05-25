# CMakeList.txt: проект CMake для CMakeProject; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#
cmake_minimum_required (VERSION 3.8)

# Добавьте источник в исполняемый файл этого проекта.
add_executable (CMakeProject "CMakeProject.cpp" "disk.cpp" "ram.cpp" "kbd.cpp" "cpu.cpp" "gpu.cpp")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET CMakeProject PROPERTY CXX_STANDARD 14)
endif()

# TODO: Добавьте тесты и целевые объекты, если это необходимо.
