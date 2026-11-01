// from server: 100% by colin
// roc 2007-03 005f57b0  unit: seg_005f0000  size: 179 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005f57b0
//
// 005f57b0  83ec14               sub esp, 0x14
// 005f57b3  8b542418             mov edx, dword ptr [esp + 0x18]
// 005f57b7  8b442420             mov eax, dword ptr [esp + 0x20]
// 005f57bb  d94218               fld dword ptr [edx + 0x18]
// 005f57be  d84808               fmul dword ptr [eax + 8]
// 005f57c1  d9420c               fld dword ptr [edx + 0xc]
// 005f57c4  d84804               fmul dword ptr [eax + 4]
// 005f57c7  dec1                 faddp st(1)
// 005f57c9  d902                 fld dword ptr [edx]
// 005f57cb  d808                 fmul dword ptr [eax]
// 005f57cd  dec1                 faddp st(1)
// 005f57cf  d95c2408             fstp dword ptr [esp + 8]
// 005f57d3  d9421c               fld dword ptr [edx + 0x1c]
// 005f57d6  d84808               fmul dword ptr [eax + 8]
// 005f57d9  d94210               fld dword ptr [edx + 0x10]
// 005f57dc  d84804               fmul dword ptr [eax + 4]
// 005f57df  dec1                 faddp st(1)
// 005f57e1  d94204               fld dword ptr [edx + 4]
// 005f57e4  d808                 fmul dword ptr [eax]
// 005f57e6  dec1                 faddp st(1)
// 005f57e8  d95c240c             fstp dword ptr [esp + 0xc]
// 005f57ec  d94220               fld dword ptr [edx + 0x20]
// 005f57ef  d84808               fmul dword ptr [eax + 8]
// 005f57f2  d94214               fld dword ptr [edx + 0x14]
// 005f57f5  d84804               fmul dword ptr [eax + 4]
// 005f57f8  dec1                 faddp st(1)
// 005f57fa  d94208               fld dword ptr [edx + 8]
// 005f57fd  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 005f5801  d808                 fmul dword ptr [eax]
// 005f5803  52                   push edx
// 005f5804  8d44240c             lea eax, [esp + 0xc]
// 005f5808  50                   push eax
// 005f5809  dec1                 faddp st(1)
// 005f580b  8d442408             lea eax, [esp + 8]
// 005f580f  50                   push eax
// 005f5810  d95c241c             fstp dword ptr [esp + 0x1c]
// 005f5814  e8f7feffff           call 0x5f5710
// 005f5819  d9ee                 fldz 
// 005f581b  d8542404             fcom dword ptr [esp + 4]
// 005f581f  dfe0                 fnstsw ax
// 005f5821  d81c24               fcomp dword ptr [esp]
// 005f5824  f6c405               test ah, 5
// 005f5827  dfe0                 fnstsw ax
// 005f5829  7a1f                 jp 0x5f584a
// 005f582b  f6c405               test ah, 5
// 005f582e  7a0d                 jp 0x5f583d
// 005f5830  8d049500000000       lea eax, [edx*4]
// 005f5837  83c414               add esp, 0x14
// 005f583a  c20c00               ret 0xc
// 005f583d  8d049501000000       lea eax, [edx*4 + 1]
// 005f5844  83c414               add esp, 0x14
// 005f5847  c20c00               ret 0xc
// 005f584a  f6c405               test ah, 5
// 005f584d  8d049503000000       lea eax, [edx*4 + 3]
// 005f5854  7b07                 jnp 0x5f585d
// 005f5856  8d049502000000       lea eax, [edx*4 + 2]
// 005f585d  83c414               add esp, 0x14
// 005f5860  c20c00               ret 0xc
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