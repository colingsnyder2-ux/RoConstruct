// from server: 100% by EspClaude
// from server: 50% by tester
// roc 2007-08 005ec3a0  unit: RBX::BodyVelocity  size: 235 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 005ec3a0
//
// 005ec3a0  83ec18               sub esp, 0x18
// 005ec3a3  53                   push ebx
// 005ec3a4  56                   push esi
// 005ec3a5  57                   push edi
// 005ec3a6  8bf9                 mov edi, ecx
// 005ec3a8  8b4710               mov eax, dword ptr [edi + 0x10]
// 005ec3ab  8b88d8010000         mov ecx, dword ptr [eax + 0x1d8]
// 005ec3b1  8b5964               mov ebx, dword ptr [ecx + 0x64]
// 005ec3b4  8bcb                 mov ecx, ebx
// 005ec3b6  e8453df4ff           call 0x530100
// 005ec3bb  d94724               fld dword ptr [edi + 0x24]
// 005ec3be  d8a3b4000000         fsub dword ptr [ebx + 0xb4]
// 005ec3c4  8b4304               mov eax, dword ptr [ebx + 4]
// 005ec3c7  d94728               fld dword ptr [edi + 0x28]
// 005ec3ca  8b481c               mov ecx, dword ptr [eax + 0x1c]
// 005ec3cd  85c9                 test ecx, ecx
// 005ec3cf  d8a3b8000000         fsub dword ptr [ebx + 0xb8]
// 005ec3d5  d9472c               fld dword ptr [edi + 0x2c]
// 005ec3d8  d8a3bc000000         fsub dword ptr [ebx + 0xbc]
// 005ec3de  d94714               fld dword ptr [edi + 0x14]
// 005ec3e1  dccb                 fmul st(3), st(0)
// 005ec3e3  d9cb                 fxch st(3)
// 005ec3e5  d95c240c             fstp dword ptr [esp + 0xc]
// 005ec3e9  d9c9                 fxch st(1)
// 005ec3eb  d8ca                 fmul st(2)
// 005ec3ed  d95c2410             fstp dword ptr [esp + 0x10]
// 005ec3f1  dec9                 fmulp st(1)
// 005ec3f3  d95c2414             fstp dword ptr [esp + 0x14]
// 005ec3f7  7407                 je 0x5ec400
// 005ec3f9  e882890300           call 0x624d80
// 005ec3fe  eb03                 jmp 0x5ec403
// 005ec400  d9407c               fld dword ptr [eax + 0x7c]
// 005ec403  d944240c             fld dword ptr [esp + 0xc]
// 005ec407  8d7730               lea esi, [edi + 0x30]
// 005ec40a  d8c9                 fmul st(1)
// 005ec40c  8d4718               lea eax, [edi + 0x18]
// 005ec40f  d9442410             fld dword ptr [esp + 0x10]
// 005ec413  50                   push eax
// 005ec414  d8ca                 fmul st(2)
// 005ec416  8d542410             lea edx, [esp + 0x10]
// 005ec41a  d9442418             fld dword ptr [esp + 0x18]
// 005ec41e  52                   push edx
// 005ec41f  decb                 fmulp st(3)
// 005ec421  8bce                 mov ecx, esi
// 005ec423  d9c9                 fxch st(1)
// 005ec425  d91e                 fstp dword ptr [esi]
// 005ec427  d95e04               fstp dword ptr [esi + 4]
// 005ec42a  d95e08               fstp dword ptr [esi + 8]
// 005ec42d  d900                 fld dword ptr [eax]
// 005ec42f  d9e0                 fchs 
// 005ec431  d95c2414             fstp dword ptr [esp + 0x14]
// 005ec435  d94004               fld dword ptr [eax + 4]
// 005ec438  d9e0                 fchs 
// 005ec43a  d95c2418             fstp dword ptr [esp + 0x18]
// 005ec43e  d94008               fld dword ptr [eax + 8]
// 005ec441  8d442420             lea eax, [esp + 0x20]
// 005ec445  d9e0                 fchs 
// 005ec447  50                   push eax
// 005ec448  d95c2420             fstp dword ptr [esp + 0x20]
// 005ec44c  e84f40ebff           call 0x4a04a0
// 005ec451  d900                 fld dword ptr [eax]
// 005ec453  d91e                 fstp dword ptr [esi]
// 005ec455  d94004               fld dword ptr [eax + 4]
// 005ec458  d95e04               fstp dword ptr [esi + 4]
// 005ec45b  d94008               fld dword ptr [eax + 8]
// 005ec45e  d95e08               fstp dword ptr [esi + 8]
// 005ec461  8b5b04               mov ebx, dword ptr [ebx + 4]
// 005ec464  8bcb                 mov ecx, ebx
// 005ec466  e8953cf4ff           call 0x530100
// 005ec46b  8b4b04               mov ecx, dword ptr [ebx + 4]
// 005ec46e  8b4920               mov ecx, dword ptr [ecx + 0x20]
// 005ec471  85c9                 test ecx, ecx
// 005ec473  740d                 je 0x5ec482
// 005ec475  81c3a8000000         add ebx, 0xa8
// 005ec47b  53                   push ebx
// 005ec47c  56                   push esi
// 005ec47d  e8ae2bfeff           call 0x5cf030
// 005ec482  5f                   pop edi
// 005ec483  5e                   pop esi
// 005ec484  5b                   pop ebx
// 005ec485  83c418               add esp, 0x18
// 005ec488  c20800               ret 8

// roc-flags: /O2 /GS /EHsc /MD /fp:fast
// Codegen analog rewritten from the target: offsets are the ones the target bytes use.
class Vector3 {
public:
    float x, y, z;
    Vector3() {}
    Vector3(float _x, float _y, float _z) : x(_x), y(_y), z(_z) {}
    Vector3& operator=(const Vector3& v) { x = v.x; y = v.y; z = v.z; return *this; }
    Vector3 operator-(const Vector3& v) const { return Vector3(x - v.x, y - v.y, z - v.z); }
    Vector3 operator*(float s) const { return Vector3(x * s, y * s, z * s); }
    Vector3 operator-() const { return Vector3(-x, -y, -z); }
    Vector3 clamp(const Vector3& low, const Vector3& high) const;   // 0x4a04a0
};

class MassOwner {
public:
    float getMass() const;                                         // 0x624d80
};

class Kernel {
public:
    void accumulateForce(const Vector3& force, const Vector3& at); // 0x5cf030
};

class Body {
public:
    char pad0[4];
    Body* parent;            // +0x04
    char pad8[0x1c - 0x8];
    MassOwner* massOwner;    // +0x1c
    Kernel* kernel;          // +0x20
    char pad24[0x7c - 0x24];
    float mass;              // +0x7c
    char pad80[0xa8 - 0x80];
    Vector3 position;        // +0xa8
    Vector3 velocity;        // +0xb4

    void updatePV();                                               // 0x530100
    float getMass() const { return massOwner ? massOwner->getMass() : mass; }
};

struct Assembly {
    char pad0[0x64];
    Body* body;              // +0x64
};

struct Primitive {
    char pad0[0x1d8];
    Assembly* assembly;      // +0x1d8
};

namespace RBX {

class BodyVelocity {
public:
    char pad0[0x10];
    Primitive* part;         // +0x10
    float p;                 // +0x14
    Vector3 maxForce;        // +0x18
    Vector3 velocity;        // +0x24
    Vector3 force;           // +0x30

    void computeForce(int a, int b);
};

void BodyVelocity::computeForce(int, int)
{
    Body* body = part->assembly->body;
    body->updatePV();
    Vector3 delta = (velocity - body->velocity) * p;
    force = delta * body->parent->getMass();
    force = force.clamp(-maxForce, maxForce);

    Body* root = body->parent;
    root->updatePV();
    if (root->parent->kernel)
        root->parent->kernel->accumulateForce(force, root->position);
}

}
