set(RBT_TESTS "${RBT_LIB}_tests")

file(GLOB_RECURSE SOURCE_FILES "${CMAKE_CURRENT_SOURCE_DIR}/source/*.cpp")

include(FetchContent)

# gtest
set(BUILD_GMOCK OFF CACHE BOOL "Disable GMock")
set(INSTALL_GTEST OFF CACHE BOOL "Disable installation of GTest")
set(gtest_build_samples OFF CACHE BOOL "Disable GTest samples")
set(gtest_build_tests OFF CACHE BOOL "Disable GTest internal tests")

FetchContent_Declare(
    gtest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG main
)
FetchContent_MakeAvailable(gtest)
# ----

add_executable(${RBT_TESTS} ${SOURCE_FILES})
target_link_libraries(
    ${RBT_TESTS}
        PUBLIC
            ${RBT_LIB}
        PRIVATE
            gtest_main
)