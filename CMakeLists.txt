cmake_minimum_required(VERSION 3.20)

project(EgeMath
    VERSION 0.1.0
    LANGUAGES CXX 
)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_library(EgeMath
    src/Math.cpp
    src/Vec2.cpp
)

target_include_directories(EgeMath
    PUBLIC
        $(PROJECT_SOURCE_DIR)/include
)

add_executable(EgeMathSandbox
    sandbox/main.cpp
)

add_executable(LifetimeProbe
    tests/LifetimeProbe.cpp
)

add_executable(Vec2Test
    tests/Vec2Test.cpp
)

add_executable(VectorStorageProbe
    tests/VectorStorageProbe.cpp
)

add_executable(MathTests
    tests/MathTests.cpp
)

target_link_libraries(Vec2Test
    EgeMath
)

target_link_libraries(VectorStorageProbe
    PRIVATE
        EgeMath
)

target_link_libraries(MathTests
    PRIVATE
        EgeMath
)