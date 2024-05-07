#pragma once

#include <glm/glm.hpp>
#include <memory>

class SceneNode;

class RigidBody {
    public:
        std::weak_ptr<SceneNode> node;
        glm::vec3 velocity;
        float mass;
        float friction_coefficient;
        float restitution_coefficient;
        bool use_gravity;
        bool is_on_ground;

        RigidBody() = default;
        RigidBody(std::weak_ptr<SceneNode> node) : node(node), velocity(0.0f), mass(1.0f), use_gravity(false), is_on_ground(false), friction_coefficient(0.1f), restitution_coefficient(0.0f) {}
        ~RigidBody() = default;

        void updatePhysics(float delta_time);
        bool checkCollision(std::shared_ptr<RigidBody> other, float& collisionDepth, glm::vec3& collisionNormal);
        void solveCollision(std::shared_ptr<RigidBody> other, float& collisionDepth, glm::vec3& collisionNormal);
        void applyAirResistance();
        void applyGroundFriction();
        void applyGroundFriction(std::shared_ptr<RigidBody> other);
};