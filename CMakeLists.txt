# See https://cmake.org/examples/ or https://stackoverflow.com/questions/42744315/cmake-with-subdirectories
# CMakeLists files in this project can
# refer to the root source directory of the project as ${MATH_TOOLS_SOURCE_DIR} and
# to the root binary directory of the project as ${MATH_TOOLS_BINARY_DIR}.
cmake_minimum_required(VERSION 3.5)

project (git-submodule-test)

# Recurse into the "src" and "src/math_tools" subdirectories. This does not actually
# cause another cmake executable to run. The same process will walk through
# the project's entire directory structure.
add_subdirectory (src)
add_subdirectory (math-tools)

# See https://stackoverflow.com/questions/6594796/how-do-i-make-cmake-output-into-a-bin-dir
# and https://cmake.org/cmake/help/latest/variable/CMAKE_BUILD_TYPE.html
# Make CMake save the files in a ./bin/Debug (or ./bin/Release) directory
set_target_properties( 
    main math-tools
    PROPERTIES
    LIBRARY_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/bin/${CMAKE_BUILD_TYPE}"
    RUNTIME_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/bin/${CMAKE_BUILD_TYPE}"
)
