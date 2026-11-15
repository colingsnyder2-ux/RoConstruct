namespace G3D {
class Vector3 {
public:
    float x, y, z;
    Vector3(float a, float b, float c) : x(a), y(b), z(c) {}
    __declspec(noinline) Vector3 operator-(const Vector3&) const;
};

Vector3 Vector3::operator-(const Vector3& rkVector) const
{
    return Vector3(x - rkVector.x, y - rkVector.y, z - rkVector.z);
}

typedef Vector3 (Vector3::*VectorSubtract)(const Vector3&) const;
VectorSubtract keepVectorSubtract = &Vector3::operator-;
}
