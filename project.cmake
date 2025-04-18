# This CMake file is intended to register project-wide objects.
# This allows for reuse between deployments, or other projects.

add_fprime_subdirectory("${CMAKE_CURRENT_LIST_DIR}/Deployments/Components")
add_fprime_subdirectory("${CMAKE_CURRENT_LIST_DIR}/Deployments/Commander/")
add_fprime_subdirectory("${CMAKE_CURRENT_LIST_DIR}/Deployments/Node_0/")
add_fprime_subdirectory("${CMAKE_CURRENT_LIST_DIR}/Deployments/Node_1/")
add_fprime_subdirectory("${CMAKE_CURRENT_LIST_DIR}/Deployments/Node_3/")
add_fprime_subdirectory("${CMAKE_CURRENT_LIST_DIR}/Deployments/Node_4/")
