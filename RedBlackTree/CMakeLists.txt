project(RedBlackTree LANGUAGES CXX)

set(RBT_LIB ${PROJECT_NAME})

add_library(${RBT_LIB} INTERFACE)
target_include_directories(
    ${RBT_LIB} 
        INTERFACE 
            ${CMAKE_CURRENT_SOURCE_DIR}/include
)

if (${RED_BLACK_TREE_TESTS_ENABLE})
    add_subdirectory(test)
endif()