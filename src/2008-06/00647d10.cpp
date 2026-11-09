// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
namespace G3D {
class Vector2 {
public:
    float x, y;
};
class Matrix3 {
public:
    float elt[3][3];
};
class Vector3 {
public:
    float x, y, z;
    Vector3() {}
    Vector3(float a, float b, float c) : x(a), y(b), z(c) {}
    const float& operator[](int i) const { return ((const float*)this)[i]; }
    float& operator[](int i) { return ((float*)this)[i]; }
};
inline Vector3 operator*(const Vector3& v, const Matrix3& m)
{
    const Vector3& rkPoint = v;
    Vector3 kProd;
    for (int r = 0; r < 3; ++r) {
        kProd[r] = rkPoint[2] * m.elt[2][r] + rkPoint[1] * m.elt[1][r] + rkPoint[0] * m.elt[0][r];
    }
    return kProd;
}
}
namespace RBX {
enum NormalId { NORM_X, NORM_Y, NORM_Z, NORM_X_NEG, NORM_Y_NEG, NORM_Z_NEG };
class Block {
public:
    G3D::Vector2 getProjectedVertex(const G3D::Vector3& v, NormalId id);
    int getClosestEdge(const G3D::Matrix3& rotation, NormalId normalID, G3D::Vector3& crossAxis);
};
G3D::Vector2 Block::getProjectedVertex(const G3D::Vector3& vertex, NormalId normalID)
{
    G3D::Vector2 result;
    switch (normalID)
    {
    case NORM_X: result.x = vertex.y; result.y = vertex.z; break;
    case NORM_Y: result.x = vertex.z; result.y = vertex.x; break;
    case NORM_Z: result.x = vertex.x; result.y = vertex.y; break;
    case NORM_X_NEG: result.x = vertex.z; result.y = vertex.y; break;
    case NORM_Y_NEG: result.x = vertex.x; result.y = vertex.z; break;
    case NORM_Z_NEG: result.x = vertex.y; result.y = vertex.x; break;
    }
    return result;
}

int Block::getClosestEdge(const G3D::Matrix3& rotation, NormalId normalID, G3D::Vector3& crossAxis)
{
    G3D::Vector3 axisInBody = crossAxis * rotation;
    G3D::Vector2 projected = this->getProjectedVertex(axisInBody, normalID);

    if (projected.y > 0.0f)
    {
        if (projected.x > 0.0f)
            return 4 * normalID;
        return 4 * normalID + 1;
    }
    else if (projected.x > 0.0f)
    {
        return 4 * normalID + 3;
    }
    else
    {
        return 4 * normalID + 2;
    }
}
}
