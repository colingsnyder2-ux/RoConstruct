// from server: 90% by EspClaude
// roc-flags: /O2 /GS /EHsc /MD /fp:fast
// from server: 55% by colin
// roc 2007-08 005a6c10  unit: RBX::Humanoid  size: 326 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 005a6c10
//
// 005a6c10  83ec18               sub esp, 0x18
// 005a6c13  56                   push esi
// 005a6c14  8bf1                 mov esi, ecx
// 005a6c16  8b8634010000         mov eax, dword ptr [esi + 0x134]
// 005a6c1c  83f803               cmp eax, 3
// 005a6c1f  7525                 jne 0x5a6c46
// 005a6c21  d9864c010000         fld dword ptr [esi + 0x14c]
// 005a6c27  8b442420             mov eax, dword ptr [esp + 0x20]
// 005a6c2b  d918                 fstp dword ptr [eax]
// 005a6c2d  d98650010000         fld dword ptr [esi + 0x150]
// 005a6c33  d95804               fstp dword ptr [eax + 4]
// 005a6c36  d98654010000         fld dword ptr [esi + 0x154]
// 005a6c3c  5e                   pop esi
// 005a6c3d  d95808               fstp dword ptr [eax + 8]
// 005a6c40  83c418               add esp, 0x18
// 005a6c43  c20400               ret 4
// 005a6c46  83f802               cmp eax, 2
// 005a6c49  d9ee                 fldz 
// 005a6c4b  57                   push edi
// 005a6c4c  0f85b5000000         jne 0x5a6d07
// 005a6c52  ddd8                 fstp st(0)
// 005a6c54  e807f0ffff           call 0x5a5c60
// 005a6c59  d9ee                 fldz 
// 005a6c5b  8bf8                 mov edi, eax
// 005a6c5d  85ff                 test edi, edi
// 005a6c5f  d9542408             fst dword ptr [esp + 8]
// 005a6c63  d9542410             fst dword ptr [esp + 0x10]
// 005a6c67  0f849a000000         je 0x5a6d07
// 005a6c6d  8d442408             lea eax, [esp + 8]
// 005a6c71  ddd8                 fstp st(0)
// 005a6c73  50                   push eax
// 005a6c74  8bce                 mov ecx, esi
// 005a6c76  e845deffff           call 0x5a4ac0
// 005a6c7b  84c0                 test al, al
// 005a6c7d  0f8482000000         je 0x5a6d05
// 005a6c83  8bcf                 mov ecx, edi
// 005a6c85  e8f6d2fcff           call 0x573f80
// 005a6c8a  d9442408             fld dword ptr [esp + 8]
// 005a6c8e  d86024               fsub dword ptr [eax + 0x24]
// 005a6c91  83c024               add eax, 0x24
// 005a6c94  d9542414             fst dword ptr [esp + 0x14]
// 005a6c98  d9442410             fld dword ptr [esp + 0x10]
// 005a6c9c  d86008               fsub dword ptr [eax + 8]
// 005a6c9f  d954241c             fst dword ptr [esp + 0x1c]
// 005a6ca3  d9ee                 fldz 
// 005a6ca5  d95c2418             fstp dword ptr [esp + 0x18]
// 005a6ca9  dcc8                 fmul st(0), st(0)
// 005a6cab  d9c1                 fld st(1)
// 005a6cad  deca                 fmulp st(2)
// 005a6caf  dec1                 faddp st(1)
// 005a6cb1  d9fa                 fsqrt 
// 005a6cb3  d81d88797900         fcomp dword ptr [0x797988]
// 005a6cb9  dfe0                 fnstsw ax
// 005a6cbb  f6c405               test ah, 5
// 005a6cbe  7a2d                 jp 0x5a6ced
// 005a6cc0  c7863401000003000000 mov dword ptr [esi + 0x134], 3
// 005a6cca  e851e3ecff           call 0x475020
// 005a6ccf  d900                 fld dword ptr [eax]
// 005a6cd1  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 005a6cd5  d919                 fstp dword ptr [ecx]
// 005a6cd7  5f                   pop edi
// 005a6cd8  d94004               fld dword ptr [eax + 4]
// 005a6cdb  5e                   pop esi
// 005a6cdc  d95904               fstp dword ptr [ecx + 4]
// 005a6cdf  d94008               fld dword ptr [eax + 8]
// 005a6ce2  8bc1                 mov eax, ecx
// 005a6ce4  d95908               fstp dword ptr [ecx + 8]
// 005a6ce7  83c418               add esp, 0x18
// 005a6cea  c20400               ret 4
// 005a6ced  8b742424             mov esi, dword ptr [esp + 0x24]
// 005a6cf1  56                   push esi
// 005a6cf2  8d4c2418             lea ecx, [esp + 0x18]
// 005a6cf6  e8f510f4ff           call 0x4e7df0
// 005a6cfb  5f                   pop edi
// 005a6cfc  8bc6                 mov eax, esi
// 005a6cfe  5e                   pop esi
// 005a6cff  83c418               add esp, 0x18
// 005a6d02  c20400               ret 4
// 005a6d05  d9ee                 fldz 
// 005a6d07  b801000000           mov eax, 1
// 005a6d0c  840538d18b00         test byte ptr [0x8bd138], al
// 005a6d12  751a                 jne 0x5a6d2e
// 005a6d14  090538d18b00         or dword ptr [0x8bd138], eax
// 005a6d1a  d9152cd18b00         fst dword ptr [0x8bd12c]
// 005a6d20  d91530d18b00         fst dword ptr [0x8bd130]
// 005a6d26  d91d34d18b00         fstp dword ptr [0x8bd134]
// 005a6d2c  eb02                 jmp 0x5a6d30
// 005a6d2e  ddd8                 fstp st(0)
// 005a6d30  d9052cd18b00         fld dword ptr [0x8bd12c]
// 005a6d36  8b442424             mov eax, dword ptr [esp + 0x24]
// 005a6d3a  d918                 fstp dword ptr [eax]
// 005a6d3c  5f                   pop edi
// 005a6d3d  d90530d18b00         fld dword ptr [0x8bd130]
// 005a6d43  5e                   pop esi
// 005a6d44  d95804               fstp dword ptr [eax + 4]

#include <math.h>

class Vector3 {
public:
    float x, y, z;
    Vector3() {}
    Vector3(float _x, float _y, float _z) : x(_x), y(_y), z(_z) {}
    Vector3(const Vector3& v) : x(v.x), y(v.y), z(v.z) {}
    float length() const { return (float)sqrt(x * x + y * y + z * z); }
    Vector3 operator-(const Vector3& v) const { return Vector3(x - v.x, y - v.y, z - v.z); }
    Vector3 direction() const;
    static const Vector3& zero();
};

struct CoordinateFrame {
    float rotation[9];
    Vector3 translation;
};

struct PVInstance {
    const CoordinateFrame& getCoordinateFrame() const;
};

extern float g_797988;

struct Humanoid {
    char pad[0x134];
    int state;
    char pad2[0x14c - 0x138];
    Vector3 walkDirection;
    PVInstance* getTorso();
    bool getWalkTarget(Vector3& target);
    Vector3 getWalkDirection();
};

Vector3 Humanoid::getWalkDirection()
{
    if (state == 3)
        return walkDirection;
    if (state == 2) {
        PVInstance* torso = getTorso();
        Vector3 target;
        target.x = 0.0f;
        target.z = 0.0f;
        if (torso) {
            if (getWalkTarget(target)) {
                const Vector3& pos = torso->getCoordinateFrame().translation;
                Vector3 delta = target - pos;
                delta.y = 0.0f;
                if (delta.length() < g_797988) {
                    state = 3;
                    return Vector3::zero();
                }
                return delta.direction();
            }
        }
    }
    static Vector3 none(0.0f, 0.0f, 0.0f);
    return none;
}
