#ifndef RIGIDBODY

#define RIGIDBODY

#include "Vector2D.hpp"

namespace physics {
    class RigidBody {
        public:

            RigidBody() {
                this->mass = 1.f;
                this->velocity = {0.f, 0.f};
                this->force = {0.f, 0.f};
            };

            RigidBody(float newMass, Vector2D newVelocity, Vector2D acceleration) {
                this->mass = newMass;
                this->velocity = newVelocity;
                this->force = acceleration.multiply_scalar(mass);
            };

            void setMass(float newMass) {
                this->mass = newMass;
            }

            void setVelocity(Vector2D newVelocity) {
                this->velocity = newVelocity;
            }

            void setForce(Vector2D newForce) {
                this->force = newForce;
            }

            float getMass() const {
                return this->mass;
            }

            Vector2D getVelocity() const {
                return this->velocity;
            }

            Vector2D getForce() const {
                return this->force;
            }

            void update_velocity_from_force() {
                this->velocity = {velocity.xPos + force.xPos, velocity.yPos + force.yPos};
            }
        

        private:
            float mass;
            Vector2D velocity{0.0f, 0.f};
            Vector2D force;
    };
}

#endif