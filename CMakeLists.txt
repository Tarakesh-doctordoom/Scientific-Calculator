cmake_minimum_required(VERSION 3.10)
project(ScientificCalculator VERSION 3.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCES
    main.cpp
    CalculatorApp.cpp
    ScientificCalculator.cpp
    InputValidator.cpp
)

set(HEADERS
    CalculatorApp.h
    ScientificCalculator.h
    InputValidator.h
)

add_executable(ScientificCalculator ${SOURCES} ${HEADERS})
