// from server: 96% by EspClaude
// roc 2007-08 005da080  unit: RBX::VVelocityMotor::?$FactoryProduct  size: 628 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 005da080
// 005da080  83ec5c               sub esp, 0x5c
// 005da083  56                   push esi
// 005da084  6a00                 push 0
// 005da086  68284a8800           push 0x884a28
// 005da08b  8bf1                 mov esi, ecx
// 005da08d  8b86bc000000         mov eax, dword ptr [esi + 0xbc]
// 005da093  684c1f8800           push 0x881f4c
// 005da098  6a00                 push 0
// 005da09a  50                   push eax
// 005da09b  e8966c0500           call 0x630d36
// 005da0a0  83c414               add esp, 0x14
// 005da0a3  85c0                 test eax, eax
// 005da0a5  7514                 jne 0x5da0bb
// 005da0a7  8b742464             mov esi, dword ptr [esp + 0x64]
// 005da0ab  8bce                 mov ecx, esi
// 005da0ad  e89eafe9ff           call 0x475050
// 005da0b2  8bc6                 mov eax, esi
// 005da0b4  5e                   pop esi
// 005da0b5  83c45c               add esp, 0x5c
// 005da0b8  c20400               ret 4
// 005da0bb  8b80d8010000         mov eax, dword ptr [eax + 0x1d8]
// 005da0c1  8b4060               mov eax, dword ptr [eax + 0x60]
// 005da0c4  d94004               fld dword ptr [eax + 4]
// 005da0c7  83c004               add eax, 4
// 005da0ca  d9059c7e7900         fld dword ptr [0x797e9c]
// 005da0d0  8b8ef8000000         mov ecx, dword ptr [esi + 0xf8]
// 005da0d6  dcc9                 fmul st(1), st(0)
// 005da0d8  51                   push ecx
// 005da0d9  d94004               fld dword ptr [eax + 4]
// 005da0dc  8d542428             lea edx, [esp + 0x28]
// 005da0e0  52                   push edx
// 005da0e1  d8c9                 fmul st(1)
// 005da0e3  d94008               fld dword ptr [eax + 8]
// 005da0e6  8d442420             lea eax, [esp + 0x20]
// 005da0ea  deca                 fmulp st(2)
// 005da0ec  50                   push eax
// 005da0ed  d9c2                 fld st(2)
// 005da0ef  d9e0                 fchs 
// 005da0f1  d9c1                 fld st(1)
// 005da0f3  d9e0                 fchs 
// 005da0f5  d9c3                 fld st(3)
// 005da0f7  d9e0                 fchs 
// 005da0f9  d9ca                 fxch st(2)
// 005da0fb  d95c2454             fstp dword ptr [esp + 0x54]
// 005da0ff  d95c2458             fstp dword ptr [esp + 0x58]
// 005da103  d95c245c             fstp dword ptr [esp + 0x5c]
// 005da107  d9ca                 fxch st(2)
// 005da109  d9542460             fst dword ptr [esp + 0x60]
// 005da10d  d95c2430             fstp dword ptr [esp + 0x30]
// 005da111  d9c9                 fxch st(1)
// 005da113  d9542464             fst dword ptr [esp + 0x64]
// 005da117  d95c2434             fstp dword ptr [esp + 0x34]
// 005da11b  d9542468             fst dword ptr [esp + 0x68]
// 005da11f  d95c2438             fstp dword ptr [esp + 0x38]
// 005da123  e818fbfdff           call 0x5b9c40
// 005da128  50                   push eax
// 005da129  8d4c241c             lea ecx, [esp + 0x1c]
// 005da12d  51                   push ecx
// 005da12e  e84d16fdff           call 0x5ab780
// 005da133  d9ee                 fldz 
// 005da135  8b8600010000         mov eax, dword ptr [esi + 0x100]
// 005da13b  d9542428             fst dword ptr [esp + 0x28]
// 005da13f  83c414               add esp, 0x14
// 005da142  83e800               sub eax, 0
// 005da145  740d                 je 0x5da154
// 005da147  83e801               sub eax, 1
// 005da14a  7514                 jne 0x5da160
// 005da14c  d9c0                 fld st(0)
// 005da14e  d954240c             fst dword ptr [esp + 0xc]
// 005da152  eb10                 jmp 0x5da164
// 005da154  d944240c             fld dword ptr [esp + 0xc]
// 005da158  d9e0                 fchs 
// 005da15a  d954240c             fst dword ptr [esp + 0xc]
// 005da15e  eb04                 jmp 0x5da164
// 005da160  d944240c             fld dword ptr [esp + 0xc]
// 005da164  8b86fc000000         mov eax, dword ptr [esi + 0xfc]
// 005da16a  83e801               sub eax, 1
// 005da16d  740d                 je 0x5da17c
// 005da16f  83e801               sub eax, 1
// 005da172  d9442410             fld dword ptr [esp + 0x10]
// 005da176  750a                 jne 0x5da182
// 005da178  d9e0                 fchs 
// 005da17a  eb02                 jmp 0x5da17e
// 005da17c  d9c1                 fld st(1)
// 005da17e  d9542410             fst dword ptr [esp + 0x10]
// 005da182  8b8604010000         mov eax, dword ptr [esi + 0x104]
// 005da188  83e801               sub eax, 1
// 005da18b  741a                 je 0x5da1a7
// 005da18d  83e801               sub eax, 1
// 005da190  ddd9                 fstp st(1)
// 005da192  ddd8                 fstp st(0)
// 005da194  0f85af000000         jne 0x5da249
// 005da19a  d954240c             fst dword ptr [esp + 0xc]
// 005da19e  d95c2410             fstp dword ptr [esp + 0x10]
// 005da1a2  e9a4000000           jmp 0x5da24b
// 005da1a7  d9c1                 fld st(1)
// 005da1a9  d9e1                 fabs 
// 005da1ab  d9e8                 fld1 
// 005da1ad  dce9                 fsub st(1), st(0)
// 005da1af  d9c9                 fxch st(1)
// 005da1b1  d9542404             fst dword ptr [esp + 4]
// 005da1b5  d9cc                 fxch st(4)
// 005da1b7  d9542408             fst dword ptr [esp + 8]
// 005da1bb  d8d3                 fcom st(3)
// 005da1bd  dfe0                 fnstsw ax
// 005da1bf  d9056c647900         fld dword ptr [0x79646c]
// 005da1c5  f6c405               test ah, 5
// 005da1c8  7a06                 jp 0x5da1d0
// 005da1ca  dddc                 fstp st(4)
// 005da1cc  d9c1                 fld st(1)
// 005da1ce  eb11                 jmp 0x5da1e1
// 005da1d0  d9cc                 fxch st(4)
// 005da1d2  d8d9                 fcomp st(1)
// 005da1d4  dfe0                 fnstsw ax
// 005da1d6  f6c405               test ah, 5
// 005da1d9  7a04                 jp 0x5da1df
// 005da1db  d9c3                 fld st(3)
// 005da1dd  eb02                 jmp 0x5da1e1
// 005da1df  d9c0                 fld st(0)
// 005da1e1  d9cd                 fxch st(5)
// 005da1e3  d8d9                 fcomp st(1)
// 005da1e5  dfe0                 fnstsw ax
// 005da1e7  f6c441               test ah, 0x41
// 005da1ea  8d442404             lea eax, [esp + 4]
// 005da1ee  7404                 je 0x5da1f4
// 005da1f0  8d442408             lea eax, [esp + 8]
// 005da1f4  d9cc                 fxch st(4)
// 005da1f6  d808                 fmul dword ptr [eax]
// 005da1f8  d95c240c             fstp dword ptr [esp + 0xc]
// 005da1fc  d9c1                 fld st(1)
// 005da1fe  d9e1                 fabs 
// 005da200  d8e1                 fsub st(1)
// 005da202  d9542404             fst dword ptr [esp + 4]
// 005da206  d9cc                 fxch st(4)
// 005da208  d9542408             fst dword ptr [esp + 8]
// 005da20c  d8d2                 fcom st(2)
// 005da20e  dfe0                 fnstsw ax
// 005da210  f6c405               test ah, 5
// 005da213  7a06                 jp 0x5da21b
// 005da215  ddda                 fstp st(2)
// 005da217  ddda                 fstp st(2)
// 005da219  eb13                 jmp 0x5da22e
// 005da21b  ddd9                 fstp st(1)
// 005da21d  d8d1                 fcom st(1)
// 005da21f  dfe0                 fnstsw ax
// 005da221  ddd9                 fstp st(1)
// 005da223  f6c441               test ah, 0x41
// 005da226  7406                 je 0x5da22e
// 005da228  ddd9                 fstp st(1)
// 005da22a  d9c0                 fld st(0)
// 005da22c  d9c9                 fxch st(1)
// 005da22e  d8da                 fcomp st(2)
// 005da230  dfe0                 fnstsw ax
// 005da232  ddd9                 fstp st(1)
// 005da234  f6c405               test ah, 5
// 005da237  8d442404             lea eax, [esp + 4]
// 005da23b  7b04                 jnp 0x5da241
// 005da23d  8d442408             lea eax, [esp + 8]
// 005da241  d808                 fmul dword ptr [eax]
// 005da243  d95c2410             fstp dword ptr [esp + 0x10]
// 005da247  eb02                 jmp 0x5da24b
// 005da249  ddd8                 fstp st(0)
// 005da24b  8b96f8000000         mov edx, dword ptr [esi + 0xf8]
// 005da251  52                   push edx
// 005da252  8d442410             lea eax, [esp + 0x10]
// 005da256  50                   push eax
// 005da257  8d4c2438             lea ecx, [esp + 0x38]
// 005da25b  51                   push ecx
// 005da25c  e8bff8fdff           call 0x5b9b20
// 005da261  8b96f8000000         mov edx, dword ptr [esi + 0xf8]
// 005da267  83c40c               add esp, 0xc
// 005da26a  52                   push edx
// 005da26b  8d442440             lea eax, [esp + 0x40]
// 005da26f  50                   push eax
// 005da270  8d4c2450             lea ecx, [esp + 0x50]
// 005da274  e8e727feff           call 0x5bca60
// 005da279  d900                 fld dword ptr [eax]
// 005da27b  d8442430             fadd dword ptr [esp + 0x30]
// 005da27f  8b16                 mov edx, dword ptr [esi]
// 005da281  8bce                 mov ecx, esi
// 005da283  d95c2418             fstp dword ptr [esp + 0x18]
// 005da287  d94004               fld dword ptr [eax + 4]
// 005da28a  d8442434             fadd dword ptr [esp + 0x34]
// 005da28e  d95c241c             fstp dword ptr [esp + 0x1c]
// 005da292  d94008               fld dword ptr [eax + 8]
// 005da295  8b4244               mov eax, dword ptr [edx + 0x44]
// 005da298  d8442438             fadd dword ptr [esp + 0x38]
// 005da29c  d95c2420             fstp dword ptr [esp + 0x20]
// 005da2a0  ffd0                 call eax
// 005da2a2  83f801               cmp eax, 1
// 005da2a5  8b86f8000000         mov eax, dword ptr [esi + 0xf8]
// 005da2ab  7414                 je 0x5da2c1
// 005da2ad  83c003               add eax, 3
// 005da2b0  99                   cdq 
// 005da2b1  b906000000           mov ecx, 6
// 005da2b6  f7f9                 idiv ecx
// 005da2b8  52                   push edx
// 005da2b9  e882f6fdff           call 0x5b9940
// 005da2be  83c404               add esp, 4
// 005da2c1  50                   push eax
// 005da2c2  e829fdfdff           call 0x5b9ff0
// 005da2c7  8b742468             mov esi, dword ptr [esp + 0x68]
// 005da2cb  83c404               add esp, 4
// 005da2ce  50                   push eax
// 005da2cf  8bce                 mov ecx, esi
// 005da2d1  e8faf2f2ff           call 0x5095d0
// 005da2d6  d9442418             fld dword ptr [esp + 0x18]
// 005da2da  d95e24               fstp dword ptr [esi + 0x24]
// 005da2dd  8bc6                 mov eax, esi
// 005da2df  d944241c             fld dword ptr [esp + 0x1c]
// 005da2e3  d95e28               fstp dword ptr [esi + 0x28]
// 005da2e6  d9442420             fld dword ptr [esp + 0x20]
// 005da2ea  d95e2c               fstp dword ptr [esi + 0x2c]
// 005da2ed  5e                   pop esi
// 005da2ee  83c45c               add esp, 0x5c
// 005da2f1  c20400               ret 4
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast
// RBX::Feature::computeLocalCoordinateFrame() const (rbxgs v8datamodel/Feature.cpp)
// with the 2007-08 layout read off the bytes: parent at Instance+0xbc,
// faceId/topBottom/leftRight/inOut at 0xf8/0xfc/0x100/0x104,
// PartInstance primitive at 0x1d8, Primitive geometry at 0x60, Geometry
// gridSize at +4, getCoordOrientation at vtable +0x44, Primitive::getExtentsLocal inline.
#include <algorithm>
#include <cmath>

namespace G3D {
class Vector3 {
public:
    float x, y, z;
    Vector3() : x(0.0f), y(0.0f), z(0.0f) {}
    Vector3(float fX, float fY, float fZ) : x(fX), y(fY), z(fZ) {}
    Vector3(const Vector3& V) : x(V.x), y(V.y), z(V.z) {}
    Vector3& operator=(const Vector3& v) { x = v.x; y = v.y; z = v.z; return *this; }
    Vector3 operator+(const Vector3& v) const { return Vector3(x + v.x, y + v.y, z + v.z); }
    Vector3 operator*(float f) const { return Vector3(x * f, y * f, z * f); }
    Vector3 operator-() const { return Vector3(-x, -y, -z); }
};
class Matrix3 {
public:
    Matrix3(const Matrix3& rkMatrix);
    float elt[3][3];
};
class CoordinateFrame {
public:
    Matrix3 rotation;
    Vector3 translation;
    CoordinateFrame();
    CoordinateFrame(const Matrix3& rotation, const Vector3& translation)
        : rotation(rotation), translation(translation) {}
};
}

namespace RBX {
enum NormalId { NORM_X = 0, NORM_Y, NORM_Z, NORM_X_NEG, NORM_Y_NEG, NORM_Z_NEG, NORM_UNDEFINED };

G3D::Vector3 objectToUvw(const G3D::Vector3& object, NormalId faceId);
G3D::Vector3 uvwToObject(const G3D::Vector3& uvw, NormalId faceId);
const G3D::Matrix3& normalIdToMatrix3(NormalId normalId);
NormalId intToNormalId(int i);

class Math {
public:
    static float sign(float fValue)
    {
        if (fValue > 0.0f) {
            return 1.0f;
        }
        if (fValue < 0.0f) {
            return -1.0f;
        }
        return 0.0f;
    }
    static G3D::Vector3 vector3Abs(const G3D::Vector3& v);
};

class Extents {
    G3D::Vector3 low;
    G3D::Vector3 high;
public:
    Extents(const G3D::Vector3& low, const G3D::Vector3& high) : low(low), high(high) {}
    const G3D::Vector3& min() const { return this->low; }
    const G3D::Vector3& max() const { return this->high; }
    G3D::Vector3 faceCenter(NormalId faceId) const;
};

class Geometry {
protected:
    G3D::Vector3 gridSize;
    virtual void onSetSize() {}
public:
    const G3D::Vector3& getGridSize() const { return gridSize; }
};

class Primitive {
    char pad0[0x60];
    Geometry* geometry;
public:
    Extents getExtentsLocal() const
    {
        G3D::Vector3 hVec = geometry->getGridSize() * 0.5f;
        return Extents(-hVec, hVec);
    }
};

class Instance {
public:
    virtual ~Instance();
    virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04();
    virtual void v05(); virtual void v06(); virtual void v07(); virtual void v08();
    virtual void v09(); virtual void v10(); virtual void v11(); virtual void v12();
    virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16();
    Instance* getParent() const { return parent; }
private:
    char pad0[0xb8];
    Instance* parent;
};

class PartInstance : public Instance {
    char pad1[0x1d8 - 0xc0];
    Primitive* primitive;
public:
    Primitive* getPrimitive() const { return primitive; }
};

class Feature : public Instance {
public:
    enum TopBottom { TOP = 0, CENTER_TB = 1, BOTTOM = 2 };
    enum LeftRight { LEFT = 0, CENTER_LR = 1, RIGHT = 2 };
    enum InOut { EDGE = 0, INSET = 1, CENTER_IO = 2 };
    enum InOutZ { Z_IN = 0, Z_OUT = 1 };
private:
    char pad1[0xf8 - 0xc0];
public:
    NormalId faceId;
    TopBottom topBottom;
    LeftRight leftRight;
    InOut inOut;
protected:
    virtual Feature::InOutZ getCoordOrientation() const;
public:
    G3D::CoordinateFrame computeLocalCoordinateFrame() const;
};

G3D::CoordinateFrame Feature::computeLocalCoordinateFrame() const
{
    PartInstance* part = dynamic_cast<PartInstance*>(getParent());

    if (!part)
        return G3D::CoordinateFrame();

    Extents extents = part->getPrimitive()->getExtentsLocal();

    G3D::Vector3 corner = extents.max();
    G3D::Vector3 uv = Math::vector3Abs(RBX::objectToUvw(corner, faceId));

    uv.z = 0.0f;

    switch (leftRight)
    {
        case LEFT:
            uv.x = -uv.x;
            break;

        case CENTER_LR:
            uv.x = 0.0f;
            break;
    }

    switch (topBottom)
    {
        case CENTER_TB:
            uv.y = 0.0f;
            break;

        case BOTTOM:
            uv.y = -uv.y;
            break;
    }

    switch (inOut)
    {
    case INSET:
        uv.x = RBX::Math::sign(uv.x) * std::max(0.0f, std::abs(uv.x) - 1.0f);
        uv.y = RBX::Math::sign(uv.y) * std::max(0.0f, std::abs(uv.y) - 1.0f);
        break;

    case CENTER_IO:
        uv.x = 0.0f;
        uv.y = 0.0f;
        break;
    }

    G3D::Vector3 uvInObject = RBX::uvwToObject(uv, faceId);
    G3D::Vector3 ptInObject = extents.faceCenter(faceId) + uvInObject;

    RBX::NormalId face = getCoordOrientation() == Z_OUT
                             ? faceId
                             : RBX::intToNormalId((faceId + NORM_X_NEG) % NORM_UNDEFINED);

    return G3D::CoordinateFrame(RBX::normalIdToMatrix3(face), ptInObject);
}
}
