# The following five lines of boilerplate have to be in your project's
# CMakeLists in this exact order for cmake to work correctly
cmake_minimum_required(VERSION 3.16)

include($ENV{IDF_PATH}/tools/cmake/project.cmake)
project(les2)


# For more information about build system see
# https://docs.espressif.com/projects/esp-idf/en/latest/api-
guides/build-system.html
# The following five lines of boilerplate have to be in your
project's
# CMakeLists in this exact order for cmake to work correctly
cmake_minimum_required(VERSION 3.5)
set(EXTRA_COMPONENT_DIRS "components/component_1")
include($ENV{IDF_PATH}/tools/cmake/project.cmake)
project(4_groter)