# EgeMath

A custom C++ mathematics library developed as a foundation for game and physics programming.

The main goal of this project is to build a lightweight, understandable math library from scratch and strengthen modern C++ skills required for physics engine development.

## Goals

- Implement mathematical primitives from scratch
- Improve modern C++ knowledge
- Build reusable components for physics simulations
- Understand low-level details behind game engine mathematics

## Current Status

Implemented:

- Vec2 core mathematical type
- Vector arithmetic operations
- Scalar multiplication and division
- Compound assignment operators
- Length and squared length calculations
- Basic unit tests using assertions

Example:

```cpp
EgeMath::Vec2 velocity(10.0f, 5.0f);
EgeMath::Vec2 displacement = velocity * deltaTime;
```

## Planned Features

- Vec3
- Matrix operations
- Transform utilities
- Interpolation functions
- Numerical methods
- Physics-oriented math utilities

## Build Requirements

- C++23 compatible compiler
- CMake 3.20+

## Project Structure

```
include/    Public headers
src/        Source files
tests/      Test programs
sandbox/    Experimental programs
```

## License

This project is for educational and portfolio purposes.