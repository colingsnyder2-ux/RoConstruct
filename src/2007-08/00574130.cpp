// from server: 100% by EspClaude
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast
// roc 2007-08 00574130  unit: RBX::PartInstance  size: 377 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00574130
//
// 00574130  6aff                 push -1
// 00574132  6868527500           push 0x755268
// 00574137  64a100000000         mov eax, dword ptr fs:[0]
// 0057413d  50                   push eax
// 0057413e  64892500000000       mov dword ptr fs:[0], esp
// 00574145  83ec58               sub esp, 0x58
// 00574148  56                   push esi
// 00574149  57                   push edi
// 0057414a  8bf9                 mov edi, ecx
// 0057414c  8b87d8010000         mov eax, dword ptr [edi + 0x1d8]
// 00574152  8b7064               mov esi, dword ptr [eax + 0x64]
// 00574155  8bce                 mov ecx, esi
// 00574157  e8a4bffbff           call 0x530100
// 0057415c  8b442470             mov eax, dword ptr [esp + 0x70]
// 00574160  50                   push eax
// 00574161  8d542448             lea edx, [esp + 0x48]
// 00574165  8d8e84000000         lea ecx, [esi + 0x84]
// 0057416b  52                   push edx
// 0057416c  e85f98faff           call 0x51d9d0
// 00574171  8b87d8010000         mov eax, dword ptr [edi + 0x1d8]
// 00574177  8b4060               mov eax, dword ptr [eax + 0x60]
// 0057417a  d94004               fld dword ptr [eax + 4]
// 0057417d  83c004               add eax, 4
// 00574180  d9059c7e7900         fld dword ptr [0x797e9c]
// 00574186  68cc9b8c00           push 0x8c9bcc
// 0057418b  dcc9                 fmul st(1), st(0)
// 0057418d  68c89b8c00           push 0x8c9bc8
// 00574192  d94004               fld dword ptr [eax + 4]
// 00574195  8d4c2410             lea ecx, [esp + 0x10]
// 00574199  51                   push ecx
// 0057419a  d8c9                 fmul st(1)
// 0057419c  8d542438             lea edx, [esp + 0x38]
// 005741a0  d94008               fld dword ptr [eax + 8]
// 005741a3  52                   push edx
// 005741a4  deca                 fmulp st(2)
// 005741a6  8d442464             lea eax, [esp + 0x64]
// 005741aa  50                   push eax
// 005741ab  8d4c245c             lea ecx, [esp + 0x5c]
// 005741af  d9c2                 fld st(2)
// 005741b1  51                   push ecx
// 005741b2  d9e0                 fchs 
// 005741b4  c784248000000000000000 mov dword ptr [esp + 0x80], 0
// 005741bf  d9c1                 fld st(1)
// 005741c1  d9e0                 fchs 
// 005741c3  d9c3                 fld st(3)
// 005741c5  d9e0                 fchs 
// 005741c7  d9ca                 fxch st(2)
// 005741c9  d954242c             fst dword ptr [esp + 0x2c]
// 005741cd  d9c9                 fxch st(1)
// 005741cf  d9542430             fst dword ptr [esp + 0x30]
// 005741d3  d9ca                 fxch st(2)
// 005741d5  d9542434             fst dword ptr [esp + 0x34]
// 005741d9  d9cd                 fxch st(5)
// 005741db  d9542438             fst dword ptr [esp + 0x38]
// 005741df  d9cb                 fxch st(3)
// 005741e1  d954243c             fst dword ptr [esp + 0x3c]
// 005741e5  d9cc                 fxch st(4)
// 005741e7  d9542440             fst dword ptr [esp + 0x40]
// 005741eb  d9ee                 fldz 
// 005741ed  d9542420             fst dword ptr [esp + 0x20]
// 005741f1  d9542424             fst dword ptr [esp + 0x24]
// 005741f5  d95c2428             fstp dword ptr [esp + 0x28]
// 005741f9  d9c9                 fxch st(1)
// 005741fb  d95c2444             fstp dword ptr [esp + 0x44]
// 005741ff  d9c9                 fxch st(1)
// 00574201  d95c2448             fstp dword ptr [esp + 0x48]
// 00574205  d9cb                 fxch st(3)
// 00574207  d95c244c             fstp dword ptr [esp + 0x4c]
// 0057420b  d95c2450             fstp dword ptr [esp + 0x50]
// 0057420f  d95c2454             fstp dword ptr [esp + 0x54]
// 00574213  d95c2458             fstp dword ptr [esp + 0x58]
// 00574217  e804381c00           call 0x737a20
// 0057421c  83c418               add esp, 0x18
// 0057421f  33c9                 xor ecx, ecx
// 00574221  d9448c20             fld dword ptr [esp + ecx*4 + 0x20]
// 00574225  d85c8c08             fcomp dword ptr [esp + ecx*4 + 8]
// 00574229  dfe0                 fnstsw ax
// 0057422b  f6c444               test ah, 0x44
// 0057422e  7b2c                 jnp 0x57425c
// 00574230  d9448c14             fld dword ptr [esp + ecx*4 + 0x14]
// 00574234  d85c8c08             fcomp dword ptr [esp + ecx*4 + 8]
// 00574238  dfe0                 fnstsw ax
// 0057423a  f6c444               test ah, 0x44
// 0057423d  7b42                 jnp 0x574281
// 0057423f  83c101               add ecx, 1
// 00574242  83f903               cmp ecx, 3
// 00574245  7cda                 jl 0x574221
// 00574247  5f                   pop edi
// 00574248  33c0                 xor eax, eax
// 0057424a  5e                   pop esi
// 0057424b  8b4c2458             mov ecx, dword ptr [esp + 0x58]
// 0057424f  64890d00000000       mov dword ptr fs:[0], ecx
// 00574256  83c464               add esp, 0x64
// 00574259  c20800               ret 8
// 0057425c  8b542474             mov edx, dword ptr [esp + 0x74]
// 00574260  890a                 mov dword ptr [edx], ecx
// 00574262  51                   push ecx
// 00574263  8d8fa4010000         lea ecx, [edi + 0x1a4]
// 00574269  e8422a0400           call 0x5b6cb0
// 0057426e  5f                   pop edi
// 0057426f  5e                   pop esi
// 00574270  8b4c2458             mov ecx, dword ptr [esp + 0x58]
// 00574274  64890d00000000       mov dword ptr fs:[0], ecx
// 0057427b  83c464               add esp, 0x64
// 0057427e  c20800               ret 8
// 00574281  8d4103               lea eax, [ecx + 3]
// 00574284  8b4c2474             mov ecx, dword ptr [esp + 0x74]
// 00574288  8901                 mov dword ptr [ecx], eax
// 0057428a  50                   push eax
// 0057428b  8d8fa4010000         lea ecx, [edi + 0x1a4]
// 00574291  e81a2a0400           call 0x5b6cb0
// 00574296  8b4c2460             mov ecx, dword ptr [esp + 0x60]
// 0057429a  5f                   pop edi
// 0057429b  5e                   pop esi
// 0057429c  64890d00000000       mov dword ptr fs:[0], ecx
// 005742a3  83c464               add esp, 0x64
// 005742a6  c20800               ret 8

namespace G3D {
    class Vector3 {
    public:
        float x, y, z;
        Vector3() {}
        Vector3(float _x, float _y, float _z) : x(_x), y(_y), z(_z) {}
        Vector3(const Vector3& v) : x(v.x), y(v.y), z(v.z) {}
        const float& operator[](int i) const { return ((const float*)this)[i]; }
    };
    class Matrix3 {
    public:
        float elt[3][3];
    };
    // origin at +4 in the target frame: G3D 6 Ray has a virtual destructor
    class Ray {
    public:
        Vector3 origin;
        Vector3 direction;
        virtual ~Ray() {}
    };
    class CoordinateFrame {
    public:
        Matrix3 rotation;
        Vector3 translation;
        Ray toObjectSpace(const Ray& r) const;
    };
    class AABox {
    private:
        Vector3 lo;
        Vector3 hi;
    public:
        AABox(const Vector3& low, const Vector3& high) : lo(low), hi(high) {}
    };
    class CollisionDetection {
    public:
        static Vector3 ignore;
        static bool ignoreBool;
        static bool collisionLocationForMovingPointFixedAABox(
            const Vector3& point, const Vector3& velocity, const AABox& box,
            Vector3& outLocation, bool& inside = ignoreBool, Vector3& normal = ignore);
    };
}

namespace RBX {
    enum NormalId { NORM_X = 0, NORM_Y, NORM_Z, NORM_X_NEG, NORM_Y_NEG, NORM_Z_NEG };

    class Extents {
    private:
        G3D::Vector3 low;
        G3D::Vector3 high;
    public:
        Extents(const G3D::Vector3& low, const G3D::Vector3& high) : low(low), high(high) {}
        const G3D::Vector3& min() const { return low; }
        const G3D::Vector3& max() const { return high; }
    };

    class Geometry {
    public:
        virtual ~Geometry();
        G3D::Vector3 gridSize;          // +0x04
        const G3D::Vector3& getGridSize() const { return gridSize; }
    };

    class Body {
    public:
        void updatePV();                 // 0x530100, thiscall, no args
        const G3D::CoordinateFrame& getCoordinateFrame()
        {
            updatePV();
            return cframe;
        }
    private:
        char pad[0x84];
        G3D::CoordinateFrame cframe;     // +0x84
    };

    class Primitive {
    private:
        char pad[0x60];
        Geometry* geometry;              // +0x60
        Body* body;                      // +0x64
    public:
        const G3D::CoordinateFrame& getCoordinateFrame() const { return body->getCoordinateFrame(); }
        const G3D::Vector3& getGridSize() const { return geometry->getGridSize(); }
    };

    class Surface;
    class Surfaces {
    public:
        Surface& operator[](NormalId id);
    };

    class PartInstance {
    public:
        Surface* getSurface(const G3D::Ray& source, int& faceIndex);
    private:
        char pad[0x1a4];
        Surfaces surfaces;               // +0x1a4
        char pad2[0x1d8 - 0x1a8];
        Primitive* primitive;            // +0x1d8
    };

    Surface* PartInstance::getSurface(const G3D::Ray& source, int& faceIndex)
    {
        const G3D::CoordinateFrame& frame = primitive->getCoordinateFrame();
        G3D::Ray ray = frame.toObjectSpace(source);
        const G3D::Vector3& size = primitive->getGridSize();
        float x = size.x * 0.5f;
        float y = size.y * 0.5f;
        float z = size.z * 0.5f;
        Extents bounds(G3D::Vector3(-x, -y, -z), G3D::Vector3(x, y, z));
        const G3D::Vector3& low = bounds.min();
        const G3D::Vector3& high = bounds.max();
        G3D::Vector3 point(0.0f, 0.0f, 0.0f);
        G3D::CollisionDetection::collisionLocationForMovingPointFixedAABox(
            ray.origin, ray.direction, G3D::AABox(low, high), point);
        for (int i = 0; i < 3; ++i) {
            if (point[i] == high[i]) {
                faceIndex = i;
                return &surfaces[(NormalId)i];
            }
            if (point[i] == low[i]) {
                faceIndex = i + 3;
                return &surfaces[(NormalId)(i + 3)];
            }
        }
        return 0;
    }
}
