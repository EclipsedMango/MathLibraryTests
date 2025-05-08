#pragma once

namespace MathClasses
{
    struct Vector4
    {
        float x, y, z, w;

    	Vector4() : x(0.0f), y(0.0f), z(0.0f), w(0.0f) {}
        Vector4(const float x, const float y, const float z, const float w) : x(x), y(y), z(z), w(w) {}

        float Dot(const Vector4& other) const {
            return x * other.x + y * other.y + z * other.z;
        }

        float Magnitude() const { return sqrt(x * x + y * y + z * z); }

        explicit operator float* () { return &x; }
        explicit operator const float* () const { return &x; }

        void Normalise() {
            float mag = this->Magnitude();
            x /= mag;
            y /= mag;
            z /= mag;
        }

        Vector4 Normalised() const {
            float mag = this->Magnitude();
			if (mag == 0.0f) { return {0.0f, 0.0f, 0.0f, w / mag}; }
            return { x / mag, y / mag, z / mag, w / mag};
        }

        Vector4 Cross(const Vector4& other) const {
            return { (y * other.z - z * other.y), (x * other.z - z * other.x), (x * other.y - other.x * y), 0.0f };
        }

        Vector4 operator+(const Vector4& other) const {
            return { x + other.x, y + other.y, z + other.z, w + other.w };
        }

        Vector4 operator-(const Vector4& other) const {
            return { x - other.x, y - other.y, z - other.z, w - other.w };
        }

        Vector4 operator*(const float scale) const {
            return { x * scale, y * scale, z * scale, w * scale };
        }

        Vector4 operator/(float scale) const {
            return { x / scale, y / scale, z / scale, w / scale };
        }

        bool operator==(const Vector4& other) const {
            return (x == other.x && y == other.y && z == other.z && w == other.w);
        }

        bool operator!=(const Vector4& other) const {
            return (x != other.x && y != other.y && z != other.z && w != other.w);
        }

        float& Vector4::operator[](size_t value) {
            return (&x)[value];
    	}

        const float& Vector4::operator[](size_t value) const {
            return (&x)[value];
        }
    };

    Vector4 operator*(float scale, const Vector4& other);

    inline Vector4 operator*(float scale, const Vector4& other) {
        return { scale * other.x, scale * other.y, scale * other.z, scale / other.w};
    }
}