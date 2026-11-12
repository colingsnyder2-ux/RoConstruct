// from server: 91% by EspClaude
// from server: 40% by colin
// roc 2007-08 00601f10  unit: RBX::Running  size: 952 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00601f10
//
// 00601f10  d9442404             fld dword ptr [esp + 4]
// 00601f14  83ec38               sub esp, 0x38
// 00601f17  55                   push ebp
// 00601f18  57                   push edi
// 00601f19  51                   push ecx
// 00601f1a  d91c24               fstp dword ptr [esp]
// 00601f1d  8bf9                 mov edi, ecx
// 00601f1f  e86c470200           call 0x626690
// 00601f24  d9ee                 fldz 
// 00601f26  d85f38               fcomp dword ptr [edi + 0x38]
// 00601f29  dfe0                 fnstsw ax
// 00601f2b  f6c441               test ah, 0x41
// 00601f2e  750a                 jne 0x601f3a
// 00601f30  d9442444             fld dword ptr [esp + 0x44]
// 00601f34  d84738               fadd dword ptr [edi + 0x38]
// 00601f37  d95f38               fstp dword ptr [edi + 0x38]
// 00601f3a  8b4f04               mov ecx, dword ptr [edi + 4]
// 00601f3d  e80e43faff           call 0x5a6250
// 00601f42  8be8                 mov ebp, eax
// 00601f44  85ed                 test ebp, ebp
// 00601f46  0f8474030000         je 0x6022c0
// 00601f4c  56                   push esi
// 00601f4d  8b7504               mov esi, dword ptr [ebp + 4]
// 00601f50  85f6                 test esi, esi
// 00601f52  0f8467030000         je 0x6022bf
// 00601f58  8bce                 mov ecx, esi
// 00601f5a  e8a1e1f2ff           call 0x530100
// 00601f5f  8d442438             lea eax, [esp + 0x38]
// 00601f63  50                   push eax
// 00601f64  8bce                 mov ecx, esi
// 00601f66  e83593feff           call 0x5eb2a0
// 00601f6b  d94748               fld dword ptr [edi + 0x48]
// 00601f6e  d84734               fadd dword ptr [edi + 0x34]
// 00601f71  8bce                 mov ecx, esi
// 00601f73  d8a6c4000000         fsub dword ptr [esi + 0xc4]
// 00601f79  d84804               fmul dword ptr [eax + 4]
// 00601f7c  d80d382b7c00         fmul dword ptr [0x7c2b38]
// 00601f82  d95c2448             fstp dword ptr [esp + 0x48]
// 00601f86  e85595feff           call 0x5eb4e0
// 00601f8b  d9442448             fld dword ptr [esp + 0x48]
// 00601f8f  8d4c2438             lea ecx, [esp + 0x38]
// 00601f93  d86004               fsub dword ptr [eax + 4]
// 00601f96  51                   push ecx
// 00601f97  8bce                 mov ecx, esi
// 00601f99  d95c244c             fstp dword ptr [esp + 0x4c]
// 00601f9d  e8fe92feff           call 0x5eb2a0
// 00601fa2  d94004               fld dword ptr [eax + 4]
// 00601fa5  d80dfc438b00         fmul dword ptr [0x8b43fc]
// 00601fab  d9c0                 fld st(0)
// 00601fad  d9e0                 fchs 
// 00601faf  d9442448             fld dword ptr [esp + 0x48]
// 00601fb3  d8d1                 fcom st(1)
// 00601fb5  dfe0                 fnstsw ax
// 00601fb7  f6c441               test ah, 0x41
// 00601fba  7a45                 jp 0x602001
// 00601fbc  ddd8                 fstp st(0)
// 00601fbe  ddd9                 fstp st(1)
// 00601fc0  d9ee                 fldz 
// 00601fc2  53                   push ebx
// 00601fc3  d9542418             fst dword ptr [esp + 0x18]
// 00601fc7  8d542418             lea edx, [esp + 0x18]
// 00601fcb  d95c2420             fstp dword ptr [esp + 0x20]
// 00601fcf  52                   push edx
// 00601fd0  8bce                 mov ecx, esi
// 00601fd2  d95c2420             fstp dword ptr [esp + 0x20]
// 00601fd6  e8c559feff           call 0x5e79a0
// 00601fdb  8b4714               mov eax, dword ptr [edi + 0x14]
// 00601fde  85c0                 test eax, eax
// 00601fe0  742e                 je 0x602010
// 00601fe2  8b98d8010000         mov ebx, dword ptr [eax + 0x1d8]
// 00601fe8  85db                 test ebx, ebx
// 00601fea  7534                 jne 0x602020
// 00601fec  8b4e1c               mov ecx, dword ptr [esi + 0x1c]
// 00601fef  85c9                 test ecx, ecx
// 00601ff1  7421                 je 0x602014
// 00601ff3  e8882d0200           call 0x624d80
// 00601ff8  d95c244c             fstp dword ptr [esp + 0x4c]
// 00601ffc  e94c010000           jmp 0x60214d
// 00602001  ddd9                 fstp st(1)
// 00602003  d8d1                 fcom st(1)
// 00602005  dfe0                 fnstsw ax
// 00602007  f6c401               test ah, 1
// 0060200a  75b2                 jne 0x601fbe
// 0060200c  ddd8                 fstp st(0)
// 0060200e  ebb0                 jmp 0x601fc0
// 00602010  33db                 xor ebx, ebx
// 00602012  ebd8                 jmp 0x601fec
// 00602014  d9467c               fld dword ptr [esi + 0x7c]
// 00602017  d95c244c             fstp dword ptr [esp + 0x4c]
// 0060201b  e92d010000           jmp 0x60214d
// 00602020  8b4364               mov eax, dword ptr [ebx + 0x64]
// 00602023  8b4004               mov eax, dword ptr [eax + 4]
// 00602026  8b481c               mov ecx, dword ptr [eax + 0x1c]
// 00602029  85c9                 test ecx, ecx
// 0060202b  7407                 je 0x602034
// 0060202d  e84e2d0200           call 0x624d80
// 00602032  eb03                 jmp 0x602037
// 00602034  d9407c               fld dword ptr [eax + 0x7c]
// 00602037  8b4e1c               mov ecx, dword ptr [esi + 0x1c]
// 0060203a  d95c244c             fstp dword ptr [esp + 0x4c]
// 0060203e  85c9                 test ecx, ecx
// 00602040  7407                 je 0x602049
// 00602042  e8392d0200           call 0x624d80
// 00602047  eb03                 jmp 0x60204c
// 00602049  d9467c               fld dword ptr [esi + 0x7c]
// 0060204c  d9542410             fst dword ptr [esp + 0x10]
// 00602050  d85c244c             fcomp dword ptr [esp + 0x4c]
// 00602054  dfe0                 fnstsw ax
// 00602056  f6c441               test ah, 0x41
// 00602059  8d44244c             lea eax, [esp + 0x4c]
// 0060205d  7404                 je 0x602063
// 0060205f  8d442410             lea eax, [esp + 0x10]
// 00602063  d900                 fld dword ptr [eax]
// 00602065  d95c244c             fstp dword ptr [esp + 0x4c]
// 00602069  d9ee                 fldz 
// 0060206b  d85f4c               fcomp dword ptr [edi + 0x4c]
// 0060206e  dfe0                 fnstsw ax
// 00602070  f6c444               test ah, 0x44
// 00602073  0f8bd4000000         jnp 0x60214d
// 00602079  8bcd                 mov ecx, ebp
// 0060207b  e880e0f2ff           call 0x530100
// 00602080  8bce                 mov ecx, esi
// 00602082  e879e0f2ff           call 0x530100
// 00602087  d9474c               fld dword ptr [edi + 0x4c]
// 0060208a  d8a5ac000000         fsub dword ptr [ebp + 0xac]
// 00602090  d80d402b7c00         fmul dword ptr [0x7c2b40]
// 00602096  d986b8000000         fld dword ptr [esi + 0xb8]
// 0060209c  d80d442b7c00         fmul dword ptr [0x7c2b44]
// 006020a2  dee9                 fsubp st(1)
// 006020a4  d9542410             fst dword ptr [esp + 0x10]
// 006020a8  d9ee                 fldz 
// 006020aa  ded9                 fcompp 
// 006020ac  dfe0                 fnstsw ax
// 006020ae  f6c405               test ah, 5
// 006020b1  0f8a96000000         jp 0x60214d
// 006020b7  8bce                 mov ecx, esi
// 006020b9  e8e293feff           call 0x5eb4a0
// 006020be  8bce                 mov ecx, esi
// 006020c0  8d6804               lea ebp, [eax + 4]
// 006020c3  e808fcfdff           call 0x5e1cd0
// 006020c8  d87d00               fdivr dword ptr [ebp]
// 006020cb  d9442410             fld dword ptr [esp + 0x10]
// 006020cf  d8d1                 fcom st(1)
// 006020d1  dfe0                 fnstsw ax
// 006020d3  f6c441               test ah, 0x41
// 006020d6  7571                 jne 0x602149
// 006020d8  dee1                 fsubrp st(1)
// 006020da  d9542410             fst dword ptr [esp + 0x10]
// 006020de  d81d04448b00         fcomp dword ptr [0x8b4404]
// 006020e4  dfe0                 fnstsw ax
// 006020e6  f6c441               test ah, 0x41
// 006020e9  b804448b00           mov eax, 0x8b4404
// 006020ee  7404                 je 0x6020f4
// 006020f0  8d442410             lea eax, [esp + 0x10]
// 006020f4  d944244c             fld dword ptr [esp + 0x4c]
// 006020f8  8d4c2418             lea ecx, [esp + 0x18]
// 006020fc  d808                 fmul dword ptr [eax]
// 006020fe  51                   push ecx
// 006020ff  8bce                 mov ecx, esi
// 00602101  d9542414             fst dword ptr [esp + 0x14]
// 00602105  d9ee                 fldz 
// 00602107  d954241c             fst dword ptr [esp + 0x1c]
// 0060210b  d95c2424             fstp dword ptr [esp + 0x24]
// 0060210f  d95c2420             fstp dword ptr [esp + 0x20]
// 00602113  e8c891feff           call 0x5eb2e0
// 00602118  d9ee                 fldz 
// 0060211a  8b5364               mov edx, dword ptr [ebx + 0x64]
// 0060211d  8b4204               mov eax, dword ptr [edx + 4]
// 00602120  d9542418             fst dword ptr [esp + 0x18]
// 00602124  d9442410             fld dword ptr [esp + 0x10]
// 00602128  8b4820               mov ecx, dword ptr [eax + 0x20]
// 0060212b  85c9                 test ecx, ecx
// 0060212d  d9e0                 fchs 
// 0060212f  d95c241c             fstp dword ptr [esp + 0x1c]
// 00602133  d95c2420             fstp dword ptr [esp + 0x20]
// 00602137  7414                 je 0x60214d
// 00602139  8d571c               lea edx, [edi + 0x1c]
// 0060213c  52                   push edx
// 0060213d  8d44241c             lea eax, [esp + 0x1c]
// 00602141  50                   push eax
// 00602142  e8e9cefcff           call 0x5cf030
// 00602147  eb04                 jmp 0x60214d
// 00602149  ddd9                 fstp st(1)
// 0060214b  ddd8                 fstp st(0)
// 0060214d  d9473c               fld dword ptr [edi + 0x3c]
// 00602150  8bce                 mov ecx, esi
// 00602152  d84728               fadd dword ptr [edi + 0x28]
// 00602155  d95c2410             fstp dword ptr [esp + 0x10]
// 00602159  d94744               fld dword ptr [edi + 0x44]
// 0060215c  d84730               fadd dword ptr [edi + 0x30]
// 0060215f  d95c2414             fstp dword ptr [esp + 0x14]
// 00602163  e898dff2ff           call 0x530100
// 00602168  8b4e1c               mov ecx, dword ptr [esi + 0x1c]
// 0060216b  85c9                 test ecx, ecx
// 0060216d  7407                 je 0x602176
// 0060216f  e80c2c0200           call 0x624d80
// 00602174  eb03                 jmp 0x602179
// 00602176  d9467c               fld dword ptr [esi + 0x7c]
// 00602179  51                   push ecx
// 0060217a  8d4c2428             lea ecx, [esp + 0x28]
// 0060217e  d91c24               fstp dword ptr [esp]
// 00602181  51                   push ecx
// 00602182  8bce                 mov ecx, esi
// 00602184  e81793feff           call 0x5eb4a0
// 00602189  8bc8                 mov ecx, eax
// 0060218b  e8a0d4f0ff           call 0x50f630
// 00602190  d9442410             fld dword ptr [esp + 0x10]
// 00602194  d8a6b4000000         fsub dword ptr [esi + 0xb4]
// 0060219a  d905442b7c00         fld dword ptr [0x7c2b44]
// 006021a0  dcc9                 fmul st(1), st(0)
// 006021a2  d9ee                 fldz 
// 006021a4  d85740               fcom dword ptr [edi + 0x40]
// 006021a7  dfe0                 fnstsw ax
// 006021a9  d9442428             fld dword ptr [esp + 0x28]
// 006021ad  f6c405               test ah, 5
// 006021b0  7a0d                 jp 0x6021bf
// 006021b2  d94740               fld dword ptr [edi + 0x40]
// 006021b5  d8a6b8000000         fsub dword ptr [esi + 0xb8]
// 006021bb  d8cb                 fmul st(3)
// 006021bd  eb02                 jmp 0x6021c1
// 006021bf  d9c0                 fld st(0)
// 006021c1  d9442414             fld dword ptr [esp + 0x14]
// 006021c5  6800448b00           push 0x8b4400
// 006021ca  d8a6bc000000         fsub dword ptr [esi + 0xbc]
// 006021d0  8d54241c             lea edx, [esp + 0x1c]
// 006021d4  52                   push edx
// 006021d5  8d442444             lea eax, [esp + 0x44]
// 006021d9  decc                 fmulp st(4)
// 006021db  50                   push eax
// 006021dc  d90500448b00         fld dword ptr [0x8b4400]
// 006021e2  8d4c243c             lea ecx, [esp + 0x3c]
// 006021e6  d9e0                 fchs 
// 006021e8  d95c2424             fstp dword ptr [esp + 0x24]
// 006021ec  d9ca                 fxch st(2)
// 006021ee  d95c2428             fstp dword ptr [esp + 0x28]
// 006021f2  d90508448b00         fld dword ptr [0x8b4408]
// 006021f8  d9e0                 fchs 
// 006021fa  d95c242c             fstp dword ptr [esp + 0x2c]
// 006021fe  d9cb                 fxch st(3)
// 00602200  d8642430             fsub dword ptr [esp + 0x30]
// 00602204  d95c243c             fstp dword ptr [esp + 0x3c]
// 00602208  dee2                 fsubrp st(2)
// 0060220a  d9c9                 fxch st(1)
// 0060220c  d95c2440             fstp dword ptr [esp + 0x40]
// 00602210  d8642438             fsub dword ptr [esp + 0x38]
// 00602214  d95c2444             fstp dword ptr [esp + 0x44]
// 00602218  e883e2e9ff           call 0x4a04a0
// 0060221d  85db                 test ebx, ebx
// 0060221f  d944243c             fld dword ptr [esp + 0x3c]
// 00602223  d944244c             fld dword ptr [esp + 0x4c]
// 00602227  dcc9                 fmul st(1), st(0)
// 00602229  d9c9                 fxch st(1)
// 0060222b  d9542418             fst dword ptr [esp + 0x18]
// 0060222f  d9442440             fld dword ptr [esp + 0x40]
// 00602233  d8ca                 fmul st(2)
// 00602235  d95c241c             fstp dword ptr [esp + 0x1c]
// 00602239  d9442444             fld dword ptr [esp + 0x44]
// 0060223d  deca                 fmulp st(2)
// 0060223f  d9c9                 fxch st(1)
// 00602241  d9542420             fst dword ptr [esp + 0x20]
// 00602245  7424                 je 0x60226b
// 00602247  d94374               fld dword ptr [ebx + 0x74]
// 0060224a  d90558f77900         fld dword ptr [0x79f758]
// 00602250  d8d9                 fcomp st(1)
// 00602252  dfe0                 fnstsw ax
// 00602254  f6c441               test ah, 0x41
// 00602257  7516                 jne 0x60226f
// 00602259  dcc8                 fmul st(0), st(0)
// 0060225b  dcca                 fmul st(2), st(0)
// 0060225d  d9ca                 fxch st(2)
// 0060225f  d95c2418             fstp dword ptr [esp + 0x18]
// 00602263  dec9                 fmulp st(1)
// 00602265  d95c2420             fstp dword ptr [esp + 0x20]
// 00602269  eb0a                 jmp 0x602275
// 0060226b  ddd8                 fstp st(0)
// 0060226d  eb04                 jmp 0x602273
// 0060226f  ddd9                 fstp st(1)
// 00602271  ddd9                 fstp st(1)
// 00602273  ddd8                 fstp st(0)
// 00602275  8d4c2418             lea ecx, [esp + 0x18]
// 00602279  51                   push ecx
// 0060227a  8bce                 mov ecx, esi
// 0060227c  e85f90feff           call 0x5eb2e0
// 00602281  85db                 test ebx, ebx
// 00602283  7439                 je 0x6022be
// 00602285  d9442418             fld dword ptr [esp + 0x18]
// 00602289  8b5364               mov edx, dword ptr [ebx + 0x64]
// 0060228c  8b4204               mov eax, dword ptr [edx + 4]
// 0060228f  d9e0                 fchs 
// 00602291  8b4820               mov ecx, dword ptr [eax + 0x20]
// 00602294  d95c243c             fstp dword ptr [esp + 0x3c]
// 00602298  85c9                 test ecx, ecx
// 0060229a  d944241c             fld dword ptr [esp + 0x1c]
// 0060229e  d9e0                 fchs 
// 006022a0  d95c2440             fstp dword ptr [esp + 0x40]
// 006022a4  d9442420             fld dword ptr [esp + 0x20]
// 006022a8  d9e0                 fchs 
// 006022aa  d95c2444             fstp dword ptr [esp + 0x44]
// 006022ae  740e                 je 0x6022be
// 006022b0  83c71c               add edi, 0x1c
// 006022b3  57                   push edi
// 006022b4  8d542440             lea edx, [esp + 0x40]
// 006022b8  52                   push edx
// 006022b9  e872cdfcff           call 0x5cf030
// 006022be  5b                   pop ebx
// 006022bf  5e                   pop esi
// 006022c0  5f                   pop edi
// 006022c1  5d                   pop ebp
// 006022c2  83c438               add esp, 0x38
// 006022c5  c20400               ret 4

// roc-flags: /O2 /GS /EHsc /MD /fp:fast
#include <algorithm>

namespace RBX {

inline float clamp(float val, float low, float hi) {
    if (val <= low) {
        return low;
    } else if (val >= hi) {
        return hi;
    } else {
        return val;
    }
}

struct Vector3 {
    float x, y, z;
    Vector3() {}
    Vector3(float _x, float _y, float _z) : x(_x), y(_y), z(_z) {}
    Vector3 operator*(float s) const { return Vector3(x * s, y * s, z * s); }
    Vector3 operator-(const Vector3& v) const { return Vector3(x - v.x, y - v.y, z - v.z); }
    Vector3 operator-() const { return Vector3(-x, -y, -z); }
    Vector3 clamp(const Vector3& low, const Vector3& high) const;   // 004a04a0
};

struct Velocity {                       // returned by reference from 005eb4a0 (+4 read as float)
    Vector3 linear;
    Vector3 extrapolate(float mass) const;                           // 0050f630 (thiscall, hidden return)
};

struct Simulator {
    void applyForceAtPoint(const Vector3& force, const Vector3& point);  // 005cf030
};

struct RootBody {
    float getMass() const;              // 00624d80
};

struct Node {
    void updatePV();                    // 00530100
};

struct Body : Node {
    char pad0[0x1c];
    RootBody* root;                     // +0x1c
    Simulator* sim;                     // +0x20
    char pad24[0x7c - 0x24];
    float mass;                         // +0x7c
    char pad80[0xb4 - 0x80];
    Vector3 linearVelocity;             // +0xb4
    char padc0[4];
    float yRotation;                    // +0xc4

    Vector3 getVelocity() const;        // 005eb2a0
    const Vector3& getPosition() const; // 005eb4e0
    const Velocity& getPV() const;      // 005eb4a0
    float getMoment() const;            // 005e1cd0
    void setVelocity(const Vector3& v); // 005e79a0
    void accumulateForce(const Vector3& f); // 005eb2e0

    float getMass() const { return root ? root->getMass() : mass; }
    void applyForceAtPoint(const Vector3& f, const Vector3& p) { if (sim) sim->applyForceAtPoint(f, p); }
};

struct Primitive : Node {
    char pad0[4];
    Body* body;                         // +4
    char pad8[0xac - 8];
    float altitude;                     // +0xac
};

struct FloorPart {
    char pad0[0x64];
    struct { int pad; Body* body; }* primitive;   // +0x64 -> +4 body
    char pad68[0x74 - 0x68];
    float friction;                     // +0x74
};

struct Floor {
    char pad0[0x1d8];
    FloorPart* part;                    // +0x1d8
};

struct Humanoid {
    Primitive* getTorsoPrimitive();     // 005a6250
};

extern const float kAltitudeP;        // 007c2b38 (7500.0f)
extern const float kLiftP;            // 007c2b40 (10000.0f)
extern const float kVelocityP;        // 007c2b44 (1250.0f)
extern float verticalForceGain;         // 008b43fc
extern Vector3 maxForce;                // 008b4400

struct Balancing {
    void* vtable;
    Humanoid* humanoid;                 // +4
    char pad8[0x14 - 8];
    Floor* floor;                       // +0x14
    char pad18[4];
    Vector3 floorContact;               // +0x1c
    void onComputeForce(float dt);      // 00626690
};

struct Running : Balancing {
    Vector3 floorVelocity;              // +0x28
    float floorAltitude;                // +0x34
    float jumpWarmup;                   // +0x38
    Vector3 desiredVelocity;            // +0x3c
    float desiredAltitude;              // +0x48
    float desiredLift;                  // +0x4c
    void onComputeForce(float dt);
};

void Running::onComputeForce(float dt)
{
    Balancing::onComputeForce(dt);

    if (jumpWarmup < 0.0f)
        jumpWarmup += dt;

    Primitive* torso = humanoid->getTorsoPrimitive();
    if (!torso)
        return;
    Body* body = torso->body;
    if (!body)
        return;

    body->updatePV();
    float lift = (desiredAltitude + floorAltitude - body->yRotation) * body->getVelocity().y * kAltitudeP - body->getPosition().y;
    float maxLift = body->getVelocity().y * verticalForceGain;
    body->setVelocity(Vector3(0.0f, clamp(lift, -maxLift, maxLift), 0.0f));

    FloorPart* floorPart = floor ? floor->part : 0;
    float mass;
    if (!floorPart) {
        mass = body->getMass();
    } else {
        mass = std::min(body->getMass(), floorPart->primitive->body->getMass());
        if (desiredLift != 0.0f) {
            torso->updatePV();
            body->updatePV();
            float up = (desiredLift - torso->altitude) * kLiftP - body->linearVelocity.y * kVelocityP;
            if (up > 0.0f) {
                float limit = body->getPV().linear.y / body->getMoment();
                if (up > limit) {
                    up = std::min(up - limit, maxForce.y);
                    float f = mass * up;
                    body->accumulateForce(Vector3(0.0f, f, 0.0f));
                    floorPart->primitive->body->applyForceAtPoint(Vector3(0.0f, -f, 0.0f), floorContact);
                }
            }
        }
    }

    float x = desiredVelocity.x + floorVelocity.x;
    float z = desiredVelocity.z + floorVelocity.z;
    body->updatePV();
    Vector3 current = body->getPV().extrapolate(body->getMass());
    float dx = (x - body->linearVelocity.x) * kVelocityP;
    float dy = desiredVelocity.y > 0.0f ? (desiredVelocity.y - body->linearVelocity.y) * kVelocityP : current.y;
    float dz = (z - body->linearVelocity.z) * kVelocityP;
    Vector3 error(dx, dy, dz);
    Vector3 clamped = (error - current).clamp(Vector3(-maxForce.x, 0.0f, -maxForce.z), maxForce);
    Vector3 force = clamped * mass;
    if (floorPart) {
        float s = floorPart->friction;
        if (s < 0.3f) {
            float s2 = s * s;
            force.x *= s2;
            force.z *= s2;
        }
    }
    body->accumulateForce(force);
    if (floorPart)
        floorPart->primitive->body->applyForceAtPoint(-force, floorContact);
}

}
