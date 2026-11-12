// from server: 71% by EspClaude
// from server: 43% by colin
// roc 2007-08 006262d0  unit: RBX::Running  size: 834 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 006262d0
//
// 006262d0  6aff                 push -1
// 006262d2  64a100000000         mov eax, dword ptr fs:[0]
// 006262d8  68d8c57500           push 0x75c5d8
// 006262dd  50                   push eax
// 006262de  64892500000000       mov dword ptr fs:[0], esp
// 006262e5  83ec78               sub esp, 0x78
// 006262e8  53                   push ebx
// 006262e9  55                   push ebp
// 006262ea  56                   push esi
// 006262eb  57                   push edi
// 006262ec  8bf9                 mov edi, ecx
// 006262ee  8b4f04               mov ecx, dword ptr [edi + 4]
// 006262f1  e85afff7ff           call 0x5a6250
// 006262f6  85c0                 test eax, eax
// 006262f8  0f84f7020000         je 0x6265f5
// 006262fe  8b4f04               mov ecx, dword ptr [edi + 4]
// 00626301  e8eafef7ff           call 0x5a61f0
// 00626306  8b7064               mov esi, dword ptr [eax + 0x64]
// 00626309  8bce                 mov ecx, esi
// 0062630b  e8f09df0ff           call 0x530100
// 00626310  8b4f04               mov ecx, dword ptr [edi + 4]
// 00626313  81c684000000         add esi, 0x84
// 00626319  e8d2fef7ff           call 0x5a61f0
// 0062631e  8b4060               mov eax, dword ptr [eax + 0x60]
// 00626321  d94004               fld dword ptr [eax + 4]
// 00626324  83c004               add eax, 4
// 00626327  80bc249800000000     cmp byte ptr [esp + 0x98], 0
// 0062632f  d9059c7e7900         fld dword ptr [0x797e9c]
// 00626335  dcc9                 fmul st(1), st(0)
// 00626337  d9c9                 fxch st(1)
// 00626339  d95c241c             fstp dword ptr [esp + 0x1c]
// 0062633d  d94004               fld dword ptr [eax + 4]
// 00626340  d8c9                 fmul st(1)
// 00626342  d95c2418             fstp dword ptr [esp + 0x18]
// 00626346  d84808               fmul dword ptr [eax + 8]
// 00626349  d95c2420             fstp dword ptr [esp + 0x20]
// 0062634d  d9e8                 fld1 
// 0062634f  d95c2410             fstp dword ptr [esp + 0x10]
// 00626353  7408                 je 0x62635d
// 00626355  d905347b7900         fld dword ptr [0x797b34]
// 0062635b  eb06                 jmp 0x626363
// 0062635d  d905504a7c00         fld dword ptr [0x7c4a50]
// 00626363  8b4f04               mov ecx, dword ptr [edi + 4]
// 00626366  d95c2414             fstp dword ptr [esp + 0x14]
// 0062636a  e8a1fef7ff           call 0x5a6210
// 0062636f  85c0                 test eax, eax
// 00626371  8b4f04               mov ecx, dword ptr [edi + 4]
// 00626374  740d                 je 0x626383
// 00626376  e895fef7ff           call 0x5a6210
// 0062637b  8b4060               mov eax, dword ptr [eax + 0x60]
// 0062637e  d94008               fld dword ptr [eax + 8]
// 00626381  eb17                 jmp 0x62639a
// 00626383  e8a8fef7ff           call 0x5a6230
// 00626388  85c0                 test eax, eax
// 0062638a  741c                 je 0x6263a8
// 0062638c  8b4f04               mov ecx, dword ptr [edi + 4]
// 0062638f  e89cfef7ff           call 0x5a6230
// 00626394  8b4860               mov ecx, dword ptr [eax + 0x60]
// 00626397  d94108               fld dword ptr [ecx + 8]
// 0062639a  d84c2414             fmul dword ptr [esp + 0x14]
// 0062639e  d80560377900         fadd dword ptr [0x793760]
// 006263a4  d95c2410             fstp dword ptr [esp + 0x10]
// 006263a8  d9442418             fld dword ptr [esp + 0x18]
// 006263ac  8d542438             lea edx, [esp + 0x38]
// 006263b0  d9e0                 fchs 
// 006263b2  52                   push edx
// 006263b3  d9542418             fst dword ptr [esp + 0x18]
// 006263b7  8d442430             lea eax, [esp + 0x30]
// 006263bb  d9ee                 fldz 
// 006263bd  50                   push eax
// 006263be  d9542440             fst dword ptr [esp + 0x40]
// 006263c2  8bce                 mov ecx, esi
// 006263c4  d95c2448             fstp dword ptr [esp + 0x48]
// 006263c8  d95c2444             fstp dword ptr [esp + 0x44]
// 006263cc  e8cfcde4ff           call 0x4731a0
// 006263d1  f605f4fb8b0001       test byte ptr [0x8bfbf4], 1
// 006263d8  751d                 jne 0x6263f7
// 006263da  d9ee                 fldz 
// 006263dc  830df4fb8b0001       or dword ptr [0x8bfbf4], 1
// 006263e3  d915e8fb8b00         fst dword ptr [0x8bfbe8]
// 006263e9  d9e8                 fld1 
// 006263eb  d91decfb8b00         fstp dword ptr [0x8bfbec]
// 006263f1  d91df0fb8b00         fstp dword ptr [0x8bfbf0]
// 006263f7  d905e8fb8b00         fld dword ptr [0x8bfbe8]
// 006263fd  8d4c2438             lea ecx, [esp + 0x38]
// 00626401  d9e0                 fchs 
// 00626403  51                   push ecx
// 00626404  d905ecfb8b00         fld dword ptr [0x8bfbec]
// 0062640a  8d542430             lea edx, [esp + 0x30]
// 0062640e  d9e0                 fchs 
// 00626410  52                   push edx
// 00626411  d905f0fb8b00         fld dword ptr [0x8bfbf0]
// 00626417  8d442458             lea eax, [esp + 0x58]
// 0062641b  d9e0                 fchs 
// 0062641d  50                   push eax
// 0062641e  d9ca                 fxch st(2)
// 00626420  d95c2444             fstp dword ptr [esp + 0x44]
// 00626424  d95c2448             fstp dword ptr [esp + 0x48]
// 00626428  d95c244c             fstp dword ptr [esp + 0x4c]
// 0062642c  e85f74efff           call 0x51d890
// 00626431  d944241c             fld dword ptr [esp + 0x1c]
// 00626435  83c408               add esp, 8
// 00626438  8d4c2454             lea ecx, [esp + 0x54]
// 0062643c  d91c24               fstp dword ptr [esp]
// 0062643f  51                   push ecx
// 00626440  8bcf                 mov ecx, edi
// 00626442  c784249800000000000000 mov dword ptr [esp + 0x98], 0
// 0062644d  e89efaffff           call 0x625ef0
// 00626452  85c0                 test eax, eax
// 00626454  0f859d010000         jne 0x6265f7
// 0062645a  d9442414             fld dword ptr [esp + 0x14]
// 0062645e  c7442418ffffffff     mov dword ptr [esp + 0x18], 0xffffffff
// 00626466  d954243c             fst dword ptr [esp + 0x3c]
// 0062646a  8d5f08               lea ebx, [edi + 8]
// 0062646d  8d6f1c               lea ebp, [edi + 0x1c]
// 00626470  eb12                 jmp 0x626484
// 00626472  eb0c                 jmp 0x626480
// 00626474  8da42400000000       lea esp, [esp]
// 0062647b  eb03                 jmp 0x626480
// 0062647d  8d4900               lea ecx, [ecx]
// 00626480  d944243c             fld dword ptr [esp + 0x3c]
// 00626484  db442418             fild dword ptr [esp + 0x18]
// 00626488  c7442414ffffffff     mov dword ptr [esp + 0x14], 0xffffffff
// 00626490  d84c241c             fmul dword ptr [esp + 0x1c]
// 00626494  d9542438             fst dword ptr [esp + 0x38]
// 00626498  eb0e                 jmp 0x6264a8
// 0062649a  8d9b00000000         lea ebx, [ebx]
// 006264a0  d944243c             fld dword ptr [esp + 0x3c]
// 006264a4  d9442438             fld dword ptr [esp + 0x38]
// 006264a8  f605f4fb8b0001       test byte ptr [0x8bfbf4], 1
// 006264af  db442414             fild dword ptr [esp + 0x14]
// 006264b3  d84c2420             fmul dword ptr [esp + 0x20]
// 006264b7  d906                 fld dword ptr [esi]
// 006264b9  d8ca                 fmul st(2)
// 006264bb  d9c1                 fld st(1)
// 006264bd  d84e08               fmul dword ptr [esi + 8]
// 006264c0  dec1                 faddp st(1)
// 006264c2  d9c3                 fld st(3)
// 006264c4  d84e04               fmul dword ptr [esi + 4]
// 006264c7  dec1                 faddp st(1)
// 006264c9  d84624               fadd dword ptr [esi + 0x24]
// 006264cc  d9460c               fld dword ptr [esi + 0xc]
// 006264cf  d8cb                 fmul st(3)
// 006264d1  d94614               fld dword ptr [esi + 0x14]
// 006264d4  d8cb                 fmul st(3)
// 006264d6  dec1                 faddp st(1)
// 006264d8  d94610               fld dword ptr [esi + 0x10]
// 006264db  d8cd                 fmul st(5)
// 006264dd  dec1                 faddp st(1)
// 006264df  d84628               fadd dword ptr [esi + 0x28]
// 006264e2  d94620               fld dword ptr [esi + 0x20]
// 006264e5  decb                 fmulp st(3)
// 006264e7  d9461c               fld dword ptr [esi + 0x1c]
// 006264ea  decd                 fmulp st(5)
// 006264ec  d9ca                 fxch st(2)
// 006264ee  dec4                 faddp st(4)
// 006264f0  d9ca                 fxch st(2)
// 006264f2  d84e18               fmul dword ptr [esi + 0x18]
// 006264f5  dec3                 faddp st(3)
// 006264f7  d9ca                 fxch st(2)
// 006264f9  d8462c               fadd dword ptr [esi + 0x2c]
// 006264fc  d9c9                 fxch st(1)
// 006264fe  d95c242c             fstp dword ptr [esp + 0x2c]
// 00626502  d9c9                 fxch st(1)
// 00626504  d95c2430             fstp dword ptr [esp + 0x30]
// 00626508  d95c2434             fstp dword ptr [esp + 0x34]
// 0062650c  751d                 jne 0x62652b
// 0062650e  d9ee                 fldz 
// 00626510  830df4fb8b0001       or dword ptr [0x8bfbf4], 1
// 00626517  d915e8fb8b00         fst dword ptr [0x8bfbe8]
// 0062651d  d9e8                 fld1 
// 0062651f  d91decfb8b00         fstp dword ptr [0x8bfbec]
// 00626525  d91df0fb8b00         fstp dword ptr [0x8bfbf0]
// 0062652b  d905e8fb8b00         fld dword ptr [0x8bfbe8]
// 00626531  8d542444             lea edx, [esp + 0x44]
// 00626535  d9e0                 fchs 
// 00626537  52                   push edx
// 00626538  d95c2448             fstp dword ptr [esp + 0x48]
// 0062653c  8d442430             lea eax, [esp + 0x30]
// 00626540  d905ecfb8b00         fld dword ptr [0x8bfbec]
// 00626546  50                   push eax
// 00626547  d9e0                 fchs 
// 00626549  8d4c2474             lea ecx, [esp + 0x74]
// 0062654d  d95c2450             fstp dword ptr [esp + 0x50]
// 00626551  51                   push ecx
// 00626552  d905f0fb8b00         fld dword ptr [0x8bfbf0]
// 00626558  d9e0                 fchs 
// 0062655a  d95c2458             fstp dword ptr [esp + 0x58]
// 0062655e  e82d73efff           call 0x51d890
// 00626563  d94004               fld dword ptr [eax + 4]
// 00626566  8b5704               mov edx, dword ptr [edi + 4]
// 00626569  d95c2460             fstp dword ptr [esp + 0x60]
// 0062656d  83c40c               add esp, 0xc
// 00626570  d94008               fld dword ptr [eax + 8]
// 00626573  d95c2458             fstp dword ptr [esp + 0x58]
// 00626577  d9400c               fld dword ptr [eax + 0xc]
// 0062657a  d95c245c             fstp dword ptr [esp + 0x5c]
// 0062657e  d94010               fld dword ptr [eax + 0x10]
// 00626581  d95c2460             fstp dword ptr [esp + 0x60]
// 00626585  d94014               fld dword ptr [eax + 0x14]
// 00626588  d95c2464             fstp dword ptr [esp + 0x64]
// 0062658c  d94018               fld dword ptr [eax + 0x18]
// 0062658f  d95c2468             fstp dword ptr [esp + 0x68]
// 00626593  d9442410             fld dword ptr [esp + 0x10]
// 00626597  d95c2424             fstp dword ptr [esp + 0x24]
// 0062659b  8b8298010000         mov eax, dword ptr [edx + 0x198]
// 006265a1  8b4830               mov ecx, dword ptr [eax + 0x30]
// 006265a4  8d542424             lea edx, [esp + 0x24]
// 006265a8  52                   push edx
// 006265a9  8d44242c             lea eax, [esp + 0x2c]
// 006265ad  50                   push eax
// 006265ae  55                   push ebp
// 006265af  53                   push ebx
// 006265b0  6a00                 push 0
// 006265b2  8d542464             lea edx, [esp + 0x64]
// 006265b6  52                   push edx
// 006265b7  e87497fdff           call 0x5ffd30
// 006265bc  85c0                 test eax, eax
// 006265be  740d                 je 0x6265cd
// 006265c0  50                   push eax
// 006265c1  e87ad7f4ff           call 0x573d40
// 006265c6  83c404               add esp, 4
// 006265c9  85c0                 test eax, eax
// 006265cb  752a                 jne 0x6265f7
// 006265cd  8b442414             mov eax, dword ptr [esp + 0x14]
// 006265d1  83c002               add eax, 2
// 006265d4  83f801               cmp eax, 1
// 006265d7  89442414             mov dword ptr [esp + 0x14], eax
// 006265db  0f8ebffeffff         jle 0x6264a0
// 006265e1  8b442418             mov eax, dword ptr [esp + 0x18]
// 006265e5  83c002               add eax, 2
// 006265e8  83f801               cmp eax, 1
// 006265eb  89442418             mov dword ptr [esp + 0x18], eax
// 006265ef  0f8e8bfeffff         jle 0x626480
// 006265f5  33c0                 xor eax, eax
// 006265f7  8b8c2488000000       mov ecx, dword ptr [esp + 0x88]
// 006265fe  5f                   pop edi
// 006265ff  5e                   pop esi
// 00626600  5d                   pop ebp
// 00626601  5b                   pop ebx
// 00626602  64890d00000000       mov dword ptr fs:[0], ecx
// 00626609  81c484000000         add esp, 0x84
// 0062660f  c20400               ret 4
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast

namespace RBX {

class Vector3 {
public:
    float x, y, z;
    Vector3() {}
    Vector3(float _x, float _y, float _z) : x(_x), y(_y), z(_z) {}
    Vector3(const Vector3& v) { x = v.x; y = v.y; z = v.z; }
    Vector3& operator=(const Vector3& v) { x = v.x; y = v.y; z = v.z; return *this; }
    Vector3 operator-() const { return Vector3(-x, -y, -z); }
    Vector3 operator+(const Vector3& v) const { return Vector3(x + v.x, y + v.y, z + v.z); }
    Vector3 operator*(float s) const { return Vector3(x * s, y * s, z * s); }
    static const Vector3& unitY() { static Vector3 v(0.0f, 1.0f, 0.0f); return v; }
};

class Matrix3 {
public:
    float elt[3][3];
    Vector3 operator*(const Vector3& v) const {
        return Vector3(elt[0][0] * v.x + elt[0][1] * v.y + elt[0][2] * v.z,
                       elt[1][0] * v.x + elt[1][1] * v.y + elt[1][2] * v.z,
                       elt[2][0] * v.x + elt[2][1] * v.y + elt[2][2] * v.z);
    }
};

class CoordinateFrame {
public:
    Matrix3 rotation;        // +0
    Vector3 translation;     // +0x24
    Vector3 pointToWorldSpace(const Vector3& v) const;
    Vector3 toWorld(const Vector3& v) const {
        return Vector3(
            rotation.elt[0][0] * v.x + rotation.elt[0][1] * v.y + rotation.elt[0][2] * v.z + translation.x,
            rotation.elt[1][0] * v.x + rotation.elt[1][1] * v.y + rotation.elt[1][2] * v.z + translation.y,
            rotation.elt[2][0] * v.x + rotation.elt[2][1] * v.y + rotation.elt[2][2] * v.z + translation.z);
    }
};

class Ray {
public:
    Vector3 origin;          // +4
    Vector3 direction;       // +0x10
    virtual ~Ray() {}
    static Ray fromOriginAndDirection(const Vector3& origin, const Vector3& direction);
};

struct Geometry {
    int pad0;
    Vector3 size;            // +4
};

struct Body {
    char pad0[0x84];
    CoordinateFrame position;   // +0x84
    void updatePV();
};

struct Primitive {
    char pad0[0x60];
    Geometry* geometry;      // +0x60
    Body* body;              // +0x64
};

class PartInstance {
public:
    static PartInstance* fromPrimitive(Primitive* p);
};

class HitTestFilter {
public:
    virtual int filterResult(const Primitive* p) const;
};

struct ContactManager {
    Primitive* getHit(const Ray& ray, void* ignore, const HitTestFilter* filter,
                      Vector3& hitPoint, int& stopped, float& maxDistance);
};

struct World {
    char pad0[0x30];
    ContactManager* contactManager;  // +0x30
};

struct Humanoid {
    char pad0[0x198];
    World* world;            // +0x198
    Primitive* getHeadSlow();
    Primitive* getTorsoSlow();
    Primitive* getRightLegSlow();
    Primitive* getLeftLegSlow();
};

struct HumanoidStateBase {
    virtual ~HumanoidStateBase();
    Humanoid* humanoid;      // +4
};

struct RunningBase : HumanoidStateBase, HitTestFilter {   // HitTestFilter at +8
    char padc[0x10];
    Vector3 floorPoint;      // +0x1c
    PartInstance* findFloorAlongRay(const Ray& ray, float radius);
    PartInstance* findFloor(bool jumping);
};

PartInstance* RunningBase::findFloor(bool jumping)
{
    if (humanoid->getHeadSlow()) {
        Body* body = humanoid->getTorsoSlow()->body;
        body->updatePV();
        const CoordinateFrame& cf = body->position;

        const Vector3& size = humanoid->getTorsoSlow()->geometry->size;
        float halfX = size.x * 0.5f;
        float halfY = size.y * 0.5f;
        float halfZ = size.z * 0.5f;

        float legLength = 1.0f;
        float legScale = jumping ? 1.5f : 1.1f;
        if (humanoid->getRightLegSlow())
            legLength = humanoid->getRightLegSlow()->geometry->size.y * legScale + 1.0f;
        else if (humanoid->getLeftLegSlow())
            legLength = humanoid->getLeftLegSlow()->geometry->size.y * legScale + 1.0f;

        Vector3 origin = cf.pointToWorldSpace(Vector3(0.0f, -halfY, 0.0f));
        Ray ray = Ray::fromOriginAndDirection(origin, -Vector3::unitY());

        if (PartInstance* part = findFloorAlongRay(ray, halfX))
            return part;

        for (int i = -1; i <= 1; i += 2) {
            for (int j = -1; j <= 1; j += 2) {
                origin = cf.toWorld(Vector3(i * halfX, -halfY, j * halfZ));
                ray = Ray::fromOriginAndDirection(origin, -Vector3::unitY());
                float maxDistance = legLength;
                int stopped;
                Primitive* hit = humanoid->world->contactManager->getHit(ray, 0, this, floorPoint, stopped, maxDistance);
                if (hit) {
                    if (PartInstance* part = PartInstance::fromPrimitive(hit))
                        return part;
                }
            }
        }
    }
    return 0;
}

}
