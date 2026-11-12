// from server: 100% by EspClaude
// roc-flags: /O2 /GS- /EHsc /MD
// from server: 67% by tajop
// roc 2007-08 005f1770  unit: RBX::Reflection::Metadata::VClass::?$BoundPropGetSet  size: 138 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 005f1770
//
// 005f1770  64a100000000         mov eax, dword ptr fs:[0]
// 005f1776  6aff                 push -1
// 005f1778  68c80a7500           push 0x750ac8
// 005f177d  50                   push eax
// 005f177e  64892500000000       mov dword ptr fs:[0], esp
// 005f1785  83ec2c               sub esp, 0x2c
// 005f1788  56                   push esi
// 005f1789  57                   push edi
// 005f178a  8bf9                 mov edi, ecx
// 005f178c  833f00               cmp dword ptr [edi], 0
// 005f178f  7517                 jne 0x5f17a8
// 005f1791  8d4c240c             lea ecx, [esp + 0xc]
// 005f1795  e86624e2ff           call 0x413c00
// 005f179a  50                   push eax
// 005f179b  c744244000000000     mov dword ptr [esp + 0x40], 0
// 005f17a3  e8c829e2ff           call 0x414170
// 005f17a8  83ec30               sub esp, 0x30
// 005f17ab  8bf4                 mov esi, esp
// 005f17ad  8d442474             lea eax, [esp + 0x74]
// 005f17b1  89642438             mov dword ptr [esp + 0x38], esp
// 005f17b5  50                   push eax
// 005f17b6  8bce                 mov ecx, esi
// 005f17b8  e8137ef1ff           call 0x5095d0
// 005f17bd  d9842498000000       fld dword ptr [esp + 0x98]
// 005f17c4  d95e24               fstp dword ptr [esi + 0x24]
// 005f17c7  d984249c000000       fld dword ptr [esp + 0x9c]
// 005f17ce  d95e28               fstp dword ptr [esi + 0x28]
// 005f17d1  d98424a0000000       fld dword ptr [esp + 0xa0]
// 005f17d8  d95e2c               fstp dword ptr [esi + 0x2c]
// 005f17db  8b4f04               mov ecx, dword ptr [edi + 4]
// 005f17de  8b5708               mov edx, dword ptr [edi + 8]
// 005f17e1  51                   push ecx
// 005f17e2  ffd2                 call edx
// 005f17e4  8b4c2468             mov ecx, dword ptr [esp + 0x68]
// 005f17e8  83c434               add esp, 0x34
// 005f17eb  5f                   pop edi
// 005f17ec  64890d00000000       mov dword ptr fs:[0], ecx
// 005f17f3  5e                   pop esi
// 005f17f4  83c438               add esp, 0x38
// 005f17f7  c23000               ret 0x30

struct Matrix3 {
    float elt[9];
    Matrix3(const Matrix3& m);
};

struct Vector3 {
    float x, y, z;
    Vector3(const Vector3& v) : x(v.x), y(v.y), z(v.z) {}
};

struct CoordinateFrame {
    Matrix3 rotation;
    Vector3 translation;
};

struct bad_function_call {
    int data[10];
    bad_function_call();
    ~bad_function_call();
};

__declspec(noreturn) void throw_exception(const bad_function_call& e);

struct Function1 {
    void* manager;
    void* functor;
    void (*invoker)(void*, CoordinateFrame);
    void operator()(CoordinateFrame a0) const;
};

void Function1::operator()(CoordinateFrame a0) const
{
    if (manager == 0)
        throw_exception(bad_function_call());
    invoker(functor, a0);
}
