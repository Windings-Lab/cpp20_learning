cmake_minimum_required(VERSION 3.28)
project(WD_SORCERY LANGUAGES C CXX ASM)

set(CMAKE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_PDB_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_EXTENSIONS ON)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_SCAN_FOR_MODULES ON)

add_executable(WD_SORCERY)

target_sources(WD_SORCERY
        PRIVATE
            main.cpp
            src/concept_and_modules/concepts_test.cpp
            src/concept_and_modules/custom_math.cpp
        PUBLIC
            FILE_SET CXX_MODULES
            FILES
                include/threewaycomparison/SpaceShip.ixx
                include/testers/Tester.ixx
                include/testers/spaceship/SpaceShipTester.ixx
                include/concept_and_modules/concepts_test.ixx
                include/concept_and_modules/custom_math.ixx
)


target_compile_features(WD_SORCERY PRIVATE cxx_std_23)

set(compiler_is_msvc "$<CXX_COMPILER_ID:MSVC>")
target_compile_options(WD_SORCERY PRIVATE
        $<${compiler_is_msvc}:
            /std:c++latest
            /Zc:preprocessor
            /utf-8
            /EHsc
            /nologo
            /UNICODE
            $<$<CONFIG:Release>:
                /O2
                /MD
            >
        >

        $<$<CXX_COMPILER_ID:Clang>:
            $<$<CONFIG:Debug>:
            -march=native
            -O0
            -g
            -gdwarf-4
            -fstandalone-debug
            >
        >
)

target_link_options(WD_SORCERY PRIVATE
        $<$<CXX_COMPILER_ID:Clang>:
            -static-libgcc
            -static-libstdc++
        >
)