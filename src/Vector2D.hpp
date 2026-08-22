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
        Vector2D(float newXPos, float newYPos) : xPos(newXPos), yPos(newYPos) {}
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
        [[nodiscard]] Vector2D setNewValue(const Vector2D& vector) const {
            return Vector2D{vector.xPos, vector.yPos};
        }

        // overriding the + operator
        [[nodiscard]] Vector2D operator+(const Vector2D& addedVector) const {
            return Vector2D{this->xPos + addedVector.xPos, this->yPos + addedVector.yPos};
        }

        // scalar adding
        [[nodiscard]] Vector2D add_scalar (const float scalar) {
            return Vector2D{this->xPos + scalar, this->yPos + scalar};
        }

        // overriding - operator
        [[nodiscard]] Vector2D operator-(const Vector2D& subtractedVector) {
            return Vector2D{this->xPos - subtractedVector.xPos, this->yPos - subtractedVector.yPos};
        }

        // subtracting a scalar
        [[nodiscard]] Vector2D subtract_scalar (const float scalar) {
            return Vector2D{this->xPos - scalar, this->yPos - scalar};
        }

        // overriding * operator
        [[nodiscard]] Vector2D operator*(const Vector2D& multipliedVector) {
            return Vector2D{this->xPos * multipliedVector.xPos, this->yPos * multipliedVector.yPos};
        }

        // multiplying by a scalar
        [[nodiscard]] Vector2D multiply_scalar(const float scalar) {
            return Vector2D{this->xPos * scalar, this->yPos * scalar};
        }

        // divide operator
        [[nodiscard]] Vector2D operator_divide(const Vector2D divideVector) {
            return Vector2D{this->xPos / divideVector.xPos, this->yPos / divideVector.yPos};
        }

        // scalar division
        [[nodiscard]] Vector2D divide_scalar(const float scalar) {
            return Vector2D{this->xPos / scalar, this->yPos / scalar};
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
            float y = this->xPos * s + this->yPos * c;

            this->xPos = x;
            this->yPos = y;
        }

        /**
         * normalising a vector (making its length/magnitude exactly 1)
         */
        void normalise() {
            float squared_sum = length_squared();

            if (squared_sum > 0) {
                float length = sqrt(squared_sum);
                this->xPos /= length;
                this->yPos /= length;
            }
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
