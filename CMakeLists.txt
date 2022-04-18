# CMakeList.txt : CMake project for dearimgraph, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project ("aetherstats")

set(AS_SOURCES
    "src/aetherstats.h"
    "src/main.cpp"
    "src/aetherstats.cpp"
)

file(GLOB IMGUI_SOURCES 
    deps/imgui/imgui*.*
    deps/imgui/backends/imgui_impl_glfw.*
    deps/imgui/backends/imgui_impl_opengl3.*
)
include_directories(
    deps
    deps/imgui
    deps/glfw/include
    deps/glfw/deps
)

add_subdirectory(deps/glfw)
set(GLAD_GL "${GLFW_SOURCE_DIR}/deps/glad/gl.h")


add_executable (aetherstats WIN32 MACOSX_BUNDLE
  ${AS_SOURCES}
  ${IMGUI_SOURCES}
  ${GLAD_GL}
)
target_link_libraries(aetherstats glfw)

if (MSVC)
    # Tell MSVC to use main instead of WinMain
    set_target_properties(aetherstats PROPERTIES
                          LINK_FLAGS "/ENTRY:mainCRTStartup")
elseif (CMAKE_C_SIMULATE_ID STREQUAL "MSVC")
    # Tell Clang using MS CRT to use main instead of WinMain
    set_target_properties(aetherstats PROPERTIES
                          LINK_FLAGS "-Wl,/entry:mainCRTStartup")
endif()