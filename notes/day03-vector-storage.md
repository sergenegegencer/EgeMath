# Day 03 - std::vector Storage Notes

## Purpose

The purpose of this experiment is to observe how `std::vector<Vec2>` manages contiguous storage, size, capacity, reserve operations, and reallocation.

## Size and Capacity

`size()` returns the number of constructed elements currently stored in the vector.

`capacity()` returns how many elements can be stored before another allocation is required.

Observed capacity values:

```text
0
1
2
3
4
6
```

The capacity growth strategy is implementation-defined. It does not have to double after every reallocation.

## Contiguous Storage

The observed element addresses were:

```text
0: 0000020B1153C9F0
1: 0000020B1153C9F8
2: 0000020B1153CA00
3: 0000020B1153CA08
4: 0000020B1153CA10
```

Each address increased by 8 bytes.

This shows that the `Vec2` objects are stored contiguously in memory.

In this project, `sizeof(Vec2)` is expected to be 8 bytes because `Vec2` contains two `float` components.

## Reserve

Calling:

```cpp
vectors.reserve(100);
```

produced:

```text
Size: 0
Capacity: 100
```

`reserve()` allocates storage but does not construct elements.

Therefore, capacity can increase while size remains unchanged.

## Reallocation

Before exceeding the vector capacity, the first element address was:

```text
000002D438BA7E60
```

After another insertion caused reallocation, the first element address became:

```text
000002D438BA4A10
```

The address change shows that the vector allocated a new memory block and moved or copied the existing elements into it.

## Pointer and Reference Invalidation

A pointer can be obtained from a vector element:

```cpp
Vec2* oldPointer = &values[0];
```

If a later insertion causes reallocation, `oldPointer` may no longer point to a valid element.

Dereferencing such a pointer would cause undefined behavior.

The same problem applies to references and iterators that point to vector elements.

## Why reserve() Matters

If the expected number of elements is known, calling `reserve()` beforehand can reduce the number of reallocations.

This can provide two benefits:

- Fewer element moves or copies
- Fewer pointer, reference, and iterator invalidations

However, `reserve()` should not be used blindly. It is useful when a reasonable element count estimate exists.

## Key Takeaways

- `std::vector` stores elements contiguously.
- `size()` is the number of constructed elements.
- `capacity()` is the currently allocated element capacity.
- Capacity growth is implementation-defined.
- `reserve()` increases capacity without increasing size.
- Reallocation may move all elements to a new memory block.
- Reallocation may invalidate pointers, references, and iterators.
- `reserve()` can reduce reallocations when the expected element count is known.