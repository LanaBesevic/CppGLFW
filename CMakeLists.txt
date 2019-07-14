cmake_minimum_required(VERSION 3.13)

project(cpp-glfw)

file(GLOB_RECURSE SRC_LIST "src/*.cpp")

add_library(cpp-glfw STATIC ${SRC_LIST})
set_property(TARGET cpp-glfw PROPERTY CXX_STANDARD 17)
set_property(TARGET cpp-glfw PROPERTY CXX_STANDARD_REQUIRED ON)

target_include_directories(cpp-glfw
        PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
        )

# GLFW3
if (NOT TARGET glfw)
    set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
    set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
    set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
    add_subdirectory(libs/glfw)
else()
    message(STATUS "[cpp-glfw] Target glfw is already defined. Using existing target.")
endif()

target_link_libraries(cpp-glfw glfw)