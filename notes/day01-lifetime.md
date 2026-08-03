# Day 01 - C++ Object Lifetime Notes

## Purpose

The goal of this experiment is to observe how C++ objects are created, copied, moved, assigned, and destroyed.

The `LifetimeProbe` class prints messages whenever one of its special member functions is called.

---

## Constructor

A constructor is called when a new object is created.

Example:

```cpp
LifetimeProbe a;
```

Output:

```
Constructor: 0
```

A new object is created and given an ID.

---

## Copy Constructor

A copy constructor is called when a new object is created from an existing object.

Example:

```cpp
LifetimeProbe b = a;
```

Output:

```
Copy Constructor: 1
```

Important points:

- A new object is created.
- The original object still exists.
- The copied object has its own lifetime.

---

## Move Constructor

A move constructor is called when a new object is created by moving resources from another object.

Example:

```cpp
LifetimeProbe b = std::move(a);
```

Output:

```
Move Constructor: 1 from 0
```

Important points:

- A new object is created.
- Resources can be transferred from the source object.
- `std::move` does not move data by itself.
- The actual move operation is performed inside the move constructor.

---

## Copy Assignment Operator

Copy assignment is called when an existing object receives data from another existing object.

Example:

```cpp
b = a;
```

Output:

```
Copy Assignment: 3
```

Important points:

- No new object is created.
- The existing object's state is updated.
- Constructor is not called.

---

## Move Assignment Operator

Move assignment transfers resources into an existing object.

Example:

```cpp
b = std::move(a);
```

Output:

```
Move Assignment: 3 from 2
```

Important points:

- No new object is created.
- The target object's resources are replaced.
- The source object becomes a moved-from object.

---

## Passing Objects to Functions

### Pass by value

Example:

```cpp
void passByValue(LifetimeProbe obj);
```

Calling:

```cpp
passByValue(a);
```

creates a copy.

Reason:

The function parameter is a new object, so the copy constructor is called.

---

### Pass by reference

Example:

```cpp
void passByReference(LifetimeProbe& obj);
```

No constructor is called.

Reason:

A reference does not create a new object. It is only another name for the existing object.

---

### Pass by const reference

Example:

```cpp
void passByConstReference(const LifetimeProbe& obj);
```

No constructor is called.

Reason:

A const reference also refers to an existing object without creating a copy.

---

## Destructor Order

Objects are destroyed in reverse order of creation.

Example:

Creation order:

```
0
1
2
3
```

Destruction order:

```
3
2
1
0
```

This happens because objects are destroyed when they leave their scope.

---

## Key Takeaways

- Constructor creates a new object.
- Copy constructor creates a new object by copying another object.
- Move constructor creates a new object by transferring resources.
- Copy assignment modifies an existing object using another object's state.
- Move assignment modifies an existing object by transferring resources.
- References do not create new objects.
- `std::move` enables move semantics but does not perform the move itself.
- Destructors are called when objects leave their scope.