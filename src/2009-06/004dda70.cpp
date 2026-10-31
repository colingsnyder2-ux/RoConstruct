// from server: 100% by EspClaude
// roc 2009-06 004dda70  unit: RBX::Network::ConcurrentRakPeer::PacketJob  size: 195 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004dda70
//
// 004dda70  83ec40               sub esp, 0x40
// 004dda73  56                   push esi
// 004dda74  8b74244c             mov esi, dword ptr [esp + 0x4c]
// 004dda78  56                   push esi
// 004dda79  8d4c2418             lea ecx, [esp + 0x18]
// 004dda7d  e8fec4fbff           call 0x499f80
// 004dda82  d94624               fld dword ptr [esi + 0x24]
// 004dda85  d95c2438             fstp dword ptr [esp + 0x38]
// 004dda89  8d442414             lea eax, [esp + 0x14]
// 004dda8d  d94628               fld dword ptr [esi + 0x28]
// 004dda90  50                   push eax
// 004dda91  d95c2440             fstp dword ptr [esp + 0x40]
// 004dda95  d9462c               fld dword ptr [esi + 0x2c]
// 004dda98  d95c2444             fstp dword ptr [esp + 0x44]
// 004dda9c  e81fffffff           call 0x4dd9c0
// 004ddaa1  8b74244c             mov esi, dword ptr [esp + 0x4c]
// 004ddaa5  8d4c243c             lea ecx, [esp + 0x3c]
// 004ddaa9  51                   push ecx
// 004ddaaa  56                   push esi
// 004ddaab  e840fcffff           call 0x4dd6f0
// 004ddab0  8d542420             lea edx, [esp + 0x20]
// 004ddab4  52                   push edx
// 004ddab5  e8a6f11800           call 0x66cc60
// 004ddaba  83c410               add esp, 0x10
// 004ddabd  8bce                 mov ecx, esi
// 004ddabf  84c0                 test al, al
// 004ddac1  742d                 je 0x4ddaf0
// 004ddac3  e8d8c0ffff           call 0x4d9ba0
// 004ddac8  8d442414             lea eax, [esp + 0x14]
// 004ddacc  50                   push eax
// 004ddacd  e8fef11800           call 0x66ccd0
// 004ddad2  83c404               add esp, 4
// 004ddad5  6a01                 push 1
// 004ddad7  6a06                 push 6
// 004ddad9  8d4c2454             lea ecx, [esp + 0x54]
// 004ddadd  51                   push ecx
// 004ddade  8bce                 mov ecx, esi
// 004ddae0  89442458             mov dword ptr [esp + 0x58], eax
// 004ddae4  e857c1ffff           call 0x4d9c40
// 004ddae9  8bc6                 mov eax, esi
// 004ddaeb  5e                   pop esi
// 004ddaec  83c440               add esp, 0x40
// 004ddaef  c3                   ret 
// 004ddaf0  e88bc0ffff           call 0x4d9b80
// 004ddaf5  8d542414             lea edx, [esp + 0x14]
// 004ddaf9  52                   push edx
// 004ddafa  8d4c2408             lea ecx, [esp + 8]
// 004ddafe  e8fda21900           call 0x677e00
// 004ddb03  d944240c             fld dword ptr [esp + 0xc]
// 004ddb07  83ec10               sub esp, 0x10
// 004ddb0a  d95c240c             fstp dword ptr [esp + 0xc]
// 004ddb0e  8bce                 mov ecx, esi
// 004ddb10  d9442418             fld dword ptr [esp + 0x18]
// 004ddb14  d95c2408             fstp dword ptr [esp + 8]
// 004ddb18  d9442414             fld dword ptr [esp + 0x14]
// 004ddb1c  d95c2404             fstp dword ptr [esp + 4]
// 004ddb20  d9442420             fld dword ptr [esp + 0x20]
// 004ddb24  d91c24               fstp dword ptr [esp]
// 004ddb27  e854f1ffff           call 0x4dcc80
// 004ddb2c  8bc6                 mov eax, esi
// 004ddb2e  5e                   pop esi
// 004ddb2f  83c440               add esp, 0x40
// 004ddb32  c3                   ret 
// copied from an identical function in another client (function ?convert@ns_ROCX000065@@YAPAUS@1@PAU21@PBUTransform@1@@Z)

namespace ns_ROCX000065 {
struct Matrix {
    float elements[9];
    Matrix(const Matrix&);
};

struct Transform {
    Matrix rotation;
    float position[3];
};

struct Quaternion {
    float x, y, z, w;
    Quaternion(const Matrix&);
};

struct S {
    void clear();
    void prepare();
    void assign(const unsigned int*, int, int);
    void setRotation(float, float, float, float);
};

extern void __cdecl normalize(Matrix*);
extern void __cdecl setPosition(S*, const float*);
extern bool __cdecl isIdentity(const Matrix*);
extern unsigned int __cdecl encodeRotation(const Matrix*);

S* __cdecl convert(S* destination, const Transform* source)
{
    Transform value = {
        source->rotation,
        { source->position[0], source->position[1], source->position[2] }
    };

    normalize(&value.rotation);
    setPosition(destination, value.position);

    if (isIdentity(&value.rotation)) {
        destination->prepare();
        unsigned int encoded = encodeRotation(&value.rotation);
        destination->assign(&encoded, 6, 1);
    } else {
        destination->clear();
        Quaternion rotation(value.rotation);
        destination->setRotation(rotation.w, rotation.x, rotation.y, rotation.z);
    }

    return destination;
}
}
