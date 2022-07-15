# CMakeList.txt: проект CMake для mobile; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#
cmake_minimum_required (VERSION 3.8)

project ("mobile")

# Добавьте источник в исполняемый файл этого проекта.
add_executable (mobile  "main.cpp" "mobile.cpp" "mobile.h" "serviceSMS.h" "serviceSMS.cpp" "serviceCall.h" "serviceCall.cpp" "contact.h" "contact.cpp")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET mobile PROPERTY CXX_STANDARD 14)
endif()

# TODO: Добавьте тесты и целевые объекты, если это необходимо.
