#ifndef VECTOR2D

#define VECTOR2D

namespace physics {

    struct Vector2D {

        float xPos;
        float yPos;

        Vector2D() {};
        Vector2D(float newXPos, float newYPos) {
            this->xPos = newXPos;
            this->yPos = newYPos;
        }


        [[nodiscard]] Vector2D operator+=(const Vector2D& addedVector) {
            this->xPos += addedVector.xPos;
            this->yPos += addedVector.yPos;

            return *this;
        }

        [[nodiscard]] Vector2D operator-(const Vector2D& subtratedVector) {
            this->xPos -= subtratedVector.xPos;
            this->yPos -= subtratedVector.yPos;

            return *this;
        }

        [[nodiscard]] Vector2D operator*(const Vector2D& multipliedVector) {
            this->xPos *= multipliedVector.xPos;
            this->yPos *= multipliedVector.yPos;

            return *this;
        }

        [[nodiscard]] Vector2D multiply_scalar(const float scalar) {
            this->xPos *= scalar;
            this->yPos *= scalar;

            return *this;
        }

        [[nodiscard]] Vector2D operator_divide(const Vector2D divideVector) {
            this->xPos /= divideVector.xPos;
            this->yPos /= divideVector.yPos;

            return *this;
        }

        [[nodiscard]] float dot_product(const Vector2D dotVector) const {
            return (this->xPos * dotVector.xPos + this->yPos * dotVector.yPos);
        }

        [[nodiscard]] float cross_product(const Vector2D crossVector) const {
            return (this->xPos * crossVector.yPos - this->yPos * crossVector.xPos);
        }

    };

}

#endif
