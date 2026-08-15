#ifndef VECTOR2D

#define VECTOR2D

namespace physics {

    struct Vector2D {

        float xPos;
        float yPos;

        Vector2D();
        Vector2D(float newXPos, float newYPos) {
            this->xPos = newXPos;
            this->yPos = newYPos;
        }


        [[nodiscard]] Vector2D operator+(const Vector2D addedVector) {
            this->xPos += addedVector.xPos;
            this->yPos += addedVector.yPos;

            return *this;
        }

        [[nodiscard]] Vector2D operator-(const Vector2D subtratedVector) {
            this->xPos -= subtratedVector.xPos;
            this->yPos -= subtratedVector.yPos;

            return *this;
        }

        [[nodiscard]] Vector2D operator*(const Vector2D multipliedVector) {
            this->xPos *= multipliedVector.xPos;
            this->yPos *= multipliedVector.yPos;

            return *this;
        }

        [[nodiscard]] Vector2D operator_divide(const Vector2D divideVector) {
            this->xPos /= divideVector.xPos;
            this->yPos /= divideVector.yPos;

            return *this;
        }

    }

}


#endif
