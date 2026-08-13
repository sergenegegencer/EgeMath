# Particle Kinematics Notes

## Particle State

The particle state contains three `Vec2` values:

```cpp
struct Particle
{
    Vec2 position;
    Vec2 velocity;
    Vec2 acceleration;
};
```

These values represent different physical quantities.

- `position` describes where the particle is located.
- `velocity` describes how fast and in which direction the position is changing.
- `acceleration` describes how fast and in which direction the velocity is changing.

They may all use the same `Vec2` type, but they do not represent the same physical quantity.

---

## Position and Velocity Are Different

Position represents location and has units of meters:

```text
position -> m
```

Velocity represents the rate of change of position and has units of meters per second:

```text
velocity -> m/s
```

A velocity vector therefore cannot be added directly to a position without accounting for elapsed time.

The displacement produced during a timestep is:

```text
velocity * dt
```

Unit check:

```text
(m/s) * s = m
```

The result has the same unit as position, so it can be added to the position.

---

## Acceleration Is Not Added Directly to Position

Acceleration represents the rate of change of velocity:

```text
acceleration -> m/s²
```

Therefore, adding acceleration directly to position would be dimensionally incorrect:

```text
m + m/s²
```

The units are incompatible.

Acceleration first changes velocity:

```text
acceleration * dt
```

Unit check:

```text
(m/s²) * s = m/s
```

The result is a velocity change.

---

## Why dt Is Measured in Seconds

`dt` represents the amount of simulated time that passes during one update.

The physics quantities in the simulation use SI units:

```text
position     -> m
velocity     -> m/s
acceleration -> m/s²
```

Therefore, `dt` must be expressed in seconds for the unit chain to remain consistent.

For example:

```text
dt = 1 / 60 s
```

represents one simulation step at 60 updates per simulated second.

---

## Position Update

For constant acceleration during a timestep, the position update used in this experiment is:

```text
position += velocity * dt + 0.5 * acceleration * dt²
```

The first term:

```text
velocity * dt
```

has units:

```text
(m/s) * s = m
```

The acceleration term:

```text
acceleration * dt²
```

has units:

```text
(m/s²) * s² = m
```

Both terms therefore represent displacement and can be added to position.

---

## Velocity Update

Velocity is updated with:

```text
velocity += acceleration * dt
```

Unit check:

```text
(m/s²) * s = m/s
```

The result is a velocity change, so it can be added to the current velocity.

---

## Simulation Result

The simulation used:

```text
initial position     = (0, 0) m
initial velocity     = (3, 0) m/s
acceleration         = (2, 0) m/s²
dt                   = 1/60 s
simulation duration  = 1 s
```

After 60 fixed timesteps:

```text
velocity = (5, 0) m/s
position = (4, 0) m
```

These values match the analytical constant-acceleration equations.

---

## Important Limitation

The position equation used in this experiment assumes that acceleration remains constant during each timestep.

This is suitable for the current constant-acceleration experiment.

In a more general physics simulation, acceleration may change because of forces such as gravity, drag, springs, contacts, or collisions. In those cases, a numerical integration method must be chosen explicitly.

---

## Key Takeaways

- Position, velocity, and acceleration can all use `Vec2`, but they represent different physical quantities.
- Position is measured in meters.
- Velocity is measured in meters per second.
- Acceleration is measured in meters per second squared.
- Acceleration changes velocity.
- Velocity changes position.
- `dt` must be expressed in seconds when SI units are used.
- Dimensional analysis helps verify that update equations are physically consistent.
- A fixed timestep makes the simulation advance by a constant amount of simulated time on every update.