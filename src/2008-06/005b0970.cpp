// from server: 100% by colin
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD /fp:fast
extern const float attachmentScale;

struct Vector3
{
    float x, y, z;

    Vector3();
    Vector3(const Vector3& v);
    Vector3 operator*(float scale) const;
};

inline Vector3::Vector3() {}

inline Vector3::Vector3(const Vector3& v)
    : x(v.x), y(v.y), z(v.z)
{
}

__forceinline Vector3 Vector3::operator*(float scale) const
{
    Vector3 result;
    result.x = x * scale;
    result.y = y * scale;
    result.z = z * scale;
    return result;
}

struct Matrix3
{
    float elt[3][3];
    Vector3 column(int index) const;
};

struct Accoutrement
{
    char gap[0x158];
    Matrix3 rotation;

    Vector3 getAttachmentLook() const;
};

Vector3 Accoutrement::getAttachmentLook() const
{
    const float scale = attachmentScale;
    return rotation.column(2) * scale;
}
