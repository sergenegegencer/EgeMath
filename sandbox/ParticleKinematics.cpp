#include <iostream>

#include <EgeMath/Vec2.hpp>

using namespace EgeMath;

struct Particle
{
    Vec2 position;
    Vec2 velocity;
    Vec2 acceleration;

    Particle() : position(Vec2(0.0f, 0.0f)), velocity(Vec2(0.0f, 0.0f)), acceleration(Vec2(0.0f, 0.0f)) {}

    Particle(Vec2 pos, Vec2 v, Vec2 a) : position(pos), velocity(v), acceleration(a) {}
};

void updateParticle(Particle& p, float dt)
{
    p.position += p.velocity * dt + p.acceleration * dt * dt * 0.5f;
    p.velocity += p.acceleration * dt;
}

int main()
{
    const float dt { 1.0f / 60.0f };
    Particle p(Vec2(0.0f, 0.0f), Vec2(3.0f, 0.0f), Vec2(2.0f, 0.0f));

    std::cout << "Particle Position: (" << p.position.x << ", " << p.position.y << ")\n"
                "Particle Velocity: (" << p.velocity.x << ", " << p.velocity.y << ")\n"
                << "Particle Acceleration: (" << p.acceleration.x << ", " << p.acceleration.y << ")\n"
                << "dt: " << dt << " s\n\n";

    for(int i = 0; i < 60; i++)
    {
        updateParticle(p, dt);

        std::cout << "FRAME " << i + 1 << '\n'
                    << "Updated Velocity: (" << p.velocity.x << ", " << p.velocity.y << ")\n"
                    << "Updated Position: (" << p.position.x << ", " << p.position.y << ")\n\n";
    } 

    return 0;
}