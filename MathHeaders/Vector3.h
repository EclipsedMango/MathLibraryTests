#pragma once

#define TOLERENCE 0.000005

namespace MathClasses
{
    struct Vector3
    {
        float x, y, z;

        Vector3() : x(0.0f), y(0.0f), z(0.0f) {}
        Vector3(const float x, const float y, const float z) : x(x), y(y), z(z) {}

        std::string ToString() const {
            std::string str;
            for (int i = 0; i < 3; ++i) {
                str += std::to_string((*this)[i]) + ", ";
            }
            return str;
        }

        float Dot(const Vector3& other) const {
            return x * other.x + y * other.y + z * other.z;
        }

        float Magnitude() const { return sqrt(x * x + y * y + z * z); }

		explicit operator float* () { return &x; }
        explicit operator const float* () const { return &x; }

        void Normalise() {
            const float mag = this->Magnitude();
            if (mag == 0.0f) { return; }
            x /= mag;
            y /= mag;
            z /= mag;
        }

        Vector3 Normalised() const {
            float mag = this->Magnitude();
            if (mag == 0.0f) { return {0.0f, 0.0f, 0.0f}; }
            return { x / mag, y / mag, z / mag };
        }

        Vector3 Cross(const Vector3& other) const {
            return { (y * other.z - z * other.y), (z * other.x - x * other.z), (x * other.y - other.x * y) };
        }

    	Vector3 operator+(const Vector3& other) const { return { x + other.x, y + other.y, z + other.z }; }

        Vector3 operator-(const Vector3& other) const { return { x - other.x, y - other.y, z - other.z }; }

        Vector3 operator*(const float scale) const { return { x * scale, y * scale, z * scale }; }

        Vector3 operator/(const float scale) const { return { x / scale, y / scale, z / scale }; }

        bool operator==(const Vector3& other) const {
	        return (abs(x - other.x) < TOLERENCE && abs(y - other.y) < TOLERENCE && abs(z - other.z) < TOLERENCE);
        }

        bool operator!=(const Vector3& other) const {
            return !(*this == other);
        }

        float& operator[](const size_t value) {
            return (&x)[value];
        }

        const float& operator[](const size_t value) const {
            return (&x)[value];
        }
	};

    Vector3 operator*(float scale, const Vector3& other);

    inline Vector3 operator*(const float scale, const Vector3& other) {
        return { scale * other.x, scale * other.y, scale * other.z };
    }
}