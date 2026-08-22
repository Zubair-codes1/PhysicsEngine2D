#ifndef VECTOR2D

#define VECTOR2D

#include <cmath>

/**
 * Namespace physics with Vector2D struct
 * 
 * @author Zubair Abdul Matin
 */
namespace physics {

    struct Vector2D {

        float xPos;
        float yPos;

        // constructors
        Vector2D() {};
        Vector2D(float newXPos, float newYPos) {
            this->xPos = newXPos;
            this->yPos = newYPos;
        }
        Vector2D(const Vector2D& vector) {
            this->xPos = vector.xPos;
            this->yPos = vector.yPos;
        }

        // negates a supplied vector
        [[nodiscard]] Vector2D negate(const Vector2D& vector) const {
            return Vector2D{-vector.xPos, -vector.yPos};
        }

        // negate the this vector
        [[nodiscard]] Vector2D negateThis() const {
            return negate(*this);
        }

        // set new value
        [[nodiscard]] Vector2D setNewValue(const Vector2D& vector) {
            this->xPos = vector.xPos;
            this->yPos = vector.yPos;

            return *this;
        }

        // overriding the + operator
        [[nodiscard]] Vector2D operator+(const Vector2D& addedVector) {
            this->xPos += addedVector.xPos;
            this->yPos += addedVector.yPos;

            return *this;
        }

        // scalar adding
        [[nodiscard]] Vector2D add_scalar (const float scalar) {
            this->xPos += scalar;
            this->yPos += scalar;

            return *this;
        }

        // overriding - operator
        [[nodiscard]] Vector2D operator-(const Vector2D& subtratedVector) {
            this->xPos -= subtratedVector.xPos;
            this->yPos -= subtratedVector.yPos;

            return *this;
        }

        // subtracting a scalar
        [[nodiscard]] Vector2D subtract_scalar (const float scalar) {
            this->xPos -= scalar;
            this->yPos -= scalar;

            return *this;
        }

        // overriding * operator
        [[nodiscard]] Vector2D operator*(const Vector2D& multipliedVector) {
            this->xPos *= multipliedVector.xPos;
            this->yPos *= multipliedVector.yPos;

            return *this;
        }

        // multiplying by a scalar
        [[nodiscard]] Vector2D multiply_scalar(const float scalar) {
            this->xPos *= scalar;
            this->yPos *= scalar;

            return *this;
        }

        // divide operator
        [[nodiscard]] Vector2D operator_divide(const Vector2D divideVector) {
            this->xPos /= divideVector.xPos;
            this->yPos /= divideVector.yPos;

            return *this;
        }

        // scalar division
        [[nodiscard]] Vector2D divide_scalar(const float scalar) {
            this->xPos /= scalar;
            this->yPos /= scalar;

            return *this;
        }

        // length squared of this vector
        [[nodiscard]] float length_squared() const {
            return pow(this->xPos, 2) + pow(this->yPos, 2);
        }

        // finds the scalar magnitude of this vector
        [[nodiscard]] float vector_length() const {
            return sqrt(length_squared());
        }

        /**
         * Rotating the vector by certain radians
         * [                        ]
         * |  cos(x)     - sin(x)   |
         * |  sin(x)     cos(x)     |
         * [                        ]
         */
        void rotate(float radians) {
            float c = cos(radians);
            float s = sin(radians);

            float x = this->xPos * c - this->yPos * s;
            float y = this->xPos * s + this->yPos * s;

            this->xPos = x;
            this->yPos = y;
        }

        // dot product
        [[nodiscard]] float dot_product(const Vector2D dotVector) const {
            return (this->xPos * dotVector.xPos + this->yPos * dotVector.yPos);
        }

        // cross product
        [[nodiscard]] float cross_product(const Vector2D crossVector) const {
            return (this->xPos * crossVector.yPos - this->yPos * crossVector.xPos);
        }

    };

}

#endif
