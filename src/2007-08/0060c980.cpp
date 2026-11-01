// from server: 100% by colin
// roc 2007-08 0060c980  unit: RBX::Block  size: 179 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0060c980
//
// 0060c980  83ec14               sub esp, 0x14
// 0060c983  8b542418             mov edx, dword ptr [esp + 0x18]
// 0060c987  8b442420             mov eax, dword ptr [esp + 0x20]
// 0060c98b  d94218               fld dword ptr [edx + 0x18]
// 0060c98e  d84808               fmul dword ptr [eax + 8]
// 0060c991  d9420c               fld dword ptr [edx + 0xc]
// 0060c994  d84804               fmul dword ptr [eax + 4]
// 0060c997  dec1                 faddp st(1)
// 0060c999  d902                 fld dword ptr [edx]
// 0060c99b  d808                 fmul dword ptr [eax]
// 0060c99d  dec1                 faddp st(1)
// 0060c99f  d95c2408             fstp dword ptr [esp + 8]
// 0060c9a3  d9421c               fld dword ptr [edx + 0x1c]
// 0060c9a6  d84808               fmul dword ptr [eax + 8]
// 0060c9a9  d94210               fld dword ptr [edx + 0x10]
// 0060c9ac  d84804               fmul dword ptr [eax + 4]
// 0060c9af  dec1                 faddp st(1)
// 0060c9b1  d94204               fld dword ptr [edx + 4]
// 0060c9b4  d808                 fmul dword ptr [eax]
// 0060c9b6  dec1                 faddp st(1)
// 0060c9b8  d95c240c             fstp dword ptr [esp + 0xc]
// 0060c9bc  d94220               fld dword ptr [edx + 0x20]
// 0060c9bf  d84808               fmul dword ptr [eax + 8]
// 0060c9c2  d94214               fld dword ptr [edx + 0x14]
// 0060c9c5  d84804               fmul dword ptr [eax + 4]
// 0060c9c8  dec1                 faddp st(1)
// 0060c9ca  d94208               fld dword ptr [edx + 8]
// 0060c9cd  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 0060c9d1  d808                 fmul dword ptr [eax]
// 0060c9d3  52                   push edx
// 0060c9d4  8d44240c             lea eax, [esp + 0xc]
// 0060c9d8  50                   push eax
// 0060c9d9  dec1                 faddp st(1)
// 0060c9db  8d442408             lea eax, [esp + 8]
// 0060c9df  50                   push eax
// 0060c9e0  d95c241c             fstp dword ptr [esp + 0x1c]
// 0060c9e4  e8f7feffff           call 0x60c8e0
// 0060c9e9  d9ee                 fldz 
// 0060c9eb  d8542404             fcom dword ptr [esp + 4]
// 0060c9ef  dfe0                 fnstsw ax
// 0060c9f1  d81c24               fcomp dword ptr [esp]
// 0060c9f4  f6c405               test ah, 5
// 0060c9f7  dfe0                 fnstsw ax
// 0060c9f9  7a1f                 jp 0x60ca1a
// 0060c9fb  f6c405               test ah, 5
// 0060c9fe  7a0d                 jp 0x60ca0d
// 0060ca00  8d049500000000       lea eax, [edx*4]
// 0060ca07  83c414               add esp, 0x14
// 0060ca0a  c20c00               ret 0xc
// 0060ca0d  8d049501000000       lea eax, [edx*4 + 1]
// 0060ca14  83c414               add esp, 0x14
// 0060ca17  c20c00               ret 0xc
// 0060ca1a  f6c405               test ah, 5
// 0060ca1d  8d049503000000       lea eax, [edx*4 + 3]
// 0060ca24  7b07                 jnp 0x60ca2d
// 0060ca26  8d049502000000       lea eax, [edx*4 + 2]
// 0060ca2d  83c414               add esp, 0x14
// 0060ca30  c20c00               ret 0xc
// copied from an identical function in another client (function ?getClosestEdge@Block@RBX@@QAEHABVMatrix3@G3D@@W4NormalId@2@AAVVector3@4@@Z)

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