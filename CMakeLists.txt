cmake_minimum_required(VERSION 3.20...3.30)
project(Pentagol LANGUAGES C)

add_library(pentagol_rules STATIC src/rules.c)
target_compile_features(pentagol_rules PUBLIC c_std_99)
add_executable(pentagol-cli src/console.c)
target_link_libraries(pentagol-cli PRIVATE pentagol_rules)

include(CTest)
if(BUILD_TESTING)
    add_test(NAME white-wins-after-rotation
        COMMAND ${CMAKE_COMMAND} -DGAME=$<TARGET_FILE:pentagol-cli>
                -P ${CMAKE_CURRENT_SOURCE_DIR}/tests/rotation-win.cmake)
endif()

option(PENTAGOL_GRAPHICS "Build the Windows WinBGIm board" ${MINGW})
if(PENTAGOL_GRAPHICS)
    enable_language(CXX)
    if(NOT MINGW OR NOT CMAKE_SIZEOF_VOID_P EQUAL 8)
        message(FATAL_ERROR "The graphical board requires 64-bit MinGW-w64.")
    endif()

    include(FetchContent)
    FetchContent_Declare(winbgim
        URL https://codeload.github.com/ahmedshakill/WinBGIm-64/zip/2f8facbdeb4813e6a79394bfb9543f3a582f9d27
        URL_HASH SHA256=16cc9bba749e90812a7d789fd3756d83f7526f28fbbf5a31c5148f50a8d2054f
        SOURCE_SUBDIR libbgi)
    FetchContent_MakeAvailable(winbgim)
    set_target_properties(bgi PROPERTIES CXX_STANDARD 11 CXX_STANDARD_REQUIRED ON)
    target_compile_options(bgi PRIVATE -fpermissive -Wno-narrowing)

    add_executable(pentagol src/graphical.cpp src/board.cpp)
    set_target_properties(pentagol PROPERTIES CXX_STANDARD 11 CXX_STANDARD_REQUIRED ON)
    target_link_libraries(pentagol PRIVATE pentagol_rules bgi)
endif()
