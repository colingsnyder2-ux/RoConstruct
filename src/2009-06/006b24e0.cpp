// from server: 100% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 0060e100  unit: RBX::BlockBlockContact  size: 124 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0060e100
//
// 0060e100  6aff                 push -1
// 0060e102  68a88d7d00           push 0x7d8da8
// 0060e107  64a100000000         mov eax, dword ptr fs:[0]
// 0060e10d  50                   push eax
// 0060e10e  64892500000000       mov dword ptr fs:[0], esp
// 0060e115  83ec0c               sub esp, 0xc
// 0060e118  33c0                 xor eax, eax
// 0060e11a  56                   push esi
// 0060e11b  8bf1                 mov esi, ecx
// 0060e11d  89442408             mov dword ptr [esp + 8], eax
// 0060e121  8944240c             mov dword ptr [esp + 0xc], eax
// 0060e125  89442404             mov dword ptr [esp + 4], eax
// 0060e129  89442418             mov dword ptr [esp + 0x18], eax
// 0060e12d  8d442404             lea eax, [esp + 4]
// 0060e131  50                   push eax
// 0060e132  8d4e08               lea ecx, [esi + 8]
// 0060e135  51                   push ecx
// 0060e136  e8f5090000           call 0x60eb30
// 0060e13b  8b5628               mov edx, dword ptr [esi + 0x28]
// 0060e13e  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 0060e142  8b742428             mov esi, dword ptr [esp + 0x28]
// 0060e146  52                   push edx
// 0060e147  50                   push eax
// 0060e148  8d4c2414             lea ecx, [esp + 0x14]
// 0060e14c  51                   push ecx
// 0060e14d  56                   push esi
// 0060e14e  e8dd260000           call 0x610830
// 0060e153  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 0060e157  52                   push edx
// 0060e158  c7442434ffffffff     mov dword ptr [esp + 0x34], 0xffffffff
// 0060e160  e8bb9befff           call 0x507d20
// 0060e165  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 0060e169  83c41c               add esp, 0x1c
// 0060e16c  8bc6                 mov eax, esi
// 0060e16e  5e                   pop esi
// 0060e16f  64890d00000000       mov dword ptr fs:[0], ecx
// 0060e176  83c418               add esp, 0x18
// 0060e179  c20800               ret 8

void __cdecl alignedFree(void*);

struct Array
{
    void* data;
    int capacity;
    int size;

    __forceinline Array();
    __forceinline ~Array();
};

__forceinline Array::Array()
{
    capacity = 0;
    size = 0;
    data = 0;
}

__forceinline Array::~Array()
{
    alignedFree(data);
}

struct Vector
{
    float x, y, z;
    Vector(const Vector&);
};

void __cdecl collect(void*, Array*);
Vector __cdecl calculate(const Array*, int, int);

struct Contact
{
    char prefix[8];
    char source[36];
    int value;

    Vector f(int);
};

Vector Contact::f(int index)
{
    Array temporary;
    collect(source, &temporary);
    return calculate(&temporary, index, value);
}
