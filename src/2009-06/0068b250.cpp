// from server: 100% by EspClaude
// roc 2009-06 0068b250  unit: G3D::VCoordinateFrame::V?$Value::?$BoundPropGetSet  size: 141 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0068b250
//
// 0068b250  64a100000000         mov eax, dword ptr fs:[0]
// 0068b256  6aff                 push -1
// 0068b258  6848c38500           push 0x85c348
// 0068b25d  50                   push eax
// 0068b25e  64892500000000       mov dword ptr fs:[0], esp
// 0068b265  83ec2c               sub esp, 0x2c
// 0068b268  56                   push esi
// 0068b269  57                   push edi
// 0068b26a  8bf9                 mov edi, ecx
// 0068b26c  833f00               cmp dword ptr [edi], 0
// 0068b26f  7517                 jne 0x68b288
// 0068b271  8d4c240c             lea ecx, [esp + 0xc]
// 0068b275  e866e2d7ff           call 0x4094e0
// 0068b27a  50                   push eax
// 0068b27b  c744244000000000     mov dword ptr [esp + 0x40], 0
// 0068b283  e8d8efd7ff           call 0x40a260
// 0068b288  83ec30               sub esp, 0x30
// 0068b28b  8bf4                 mov esi, esp
// 0068b28d  8d442474             lea eax, [esp + 0x74]
// 0068b291  89642438             mov dword ptr [esp + 0x38], esp
// 0068b295  50                   push eax
// 0068b296  8bce                 mov ecx, esi
// 0068b298  e8e3ece0ff           call 0x499f80
// 0068b29d  d9842498000000       fld dword ptr [esp + 0x98]
// 0068b2a4  d95e24               fstp dword ptr [esi + 0x24]
// 0068b2a7  83c708               add edi, 8
// 0068b2aa  d984249c000000       fld dword ptr [esp + 0x9c]
// 0068b2b1  57                   push edi
// 0068b2b2  d95e28               fstp dword ptr [esi + 0x28]
// 0068b2b5  d98424a4000000       fld dword ptr [esp + 0xa4]
// 0068b2bc  d95e2c               fstp dword ptr [esi + 0x2c]
// 0068b2bf  8b4ff8               mov ecx, dword ptr [edi - 8]
// 0068b2c2  8b5104               mov edx, dword ptr [ecx + 4]
// 0068b2c5  ffd2                 call edx
// 0068b2c7  8b4c2468             mov ecx, dword ptr [esp + 0x68]
// 0068b2cb  83c434               add esp, 0x34
// 0068b2ce  5f                   pop edi
// 0068b2cf  64890d00000000       mov dword ptr fs:[0], ecx
// 0068b2d6  5e                   pop esi
// 0068b2d7  83c438               add esp, 0x38
// 0068b2da  c23000               ret 0x30
// copied from an identical function in another client (function ?f@S@ns_ROCX000016@@QAEXUValue@2@@Z)

namespace ns_ROCX000016 {
struct Error
{
    char data[40];
    Error();
    ~Error();
};

extern __declspec(noreturn) void throw_error(const Error&);

struct Matrix
{
    float data[9];
    Matrix(const Matrix&);
};

struct Value
{
    Matrix rotation;
    float x;
    float y;
    float z;
};

struct FunctionTable
{
    void (__cdecl *first)();
    void (__cdecl *invoke)(void*, Value);
};

struct S
{
    FunctionTable* table;
    unsigned int reserved;
    char storage[1];

    void f(Value value);
};

void S::f(Value value)
{
    if (table == 0)
        throw_error(Error());

    table->invoke(storage, value);
}
}
