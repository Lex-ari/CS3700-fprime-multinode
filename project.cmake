# This CMake file is intended to register project-wide objects.
# This allows for reuse between deployments, or other projects.

add_fprime_subdirectory("${CMAKE_CURRENT_LIST_DIR}/Components")
add_fprime_subdirectory("${CMAKE_CURRENT_LIST_DIR}/Commander/")
add_fprime_subdirectory("${CMAKE_CURRENT_LIST_DIR}/Node_0/")
add_fprime_subdirectory("${CMAKE_CURRENT_LIST_DIR}/Node_1/")
add_fprime_subdirectory("${CMAKE_CURRENT_LIST_DIR}/Node_3/")
add_fprime_subdirectory("${CMAKE_CURRENT_LIST_DIR}/Node_4/")
