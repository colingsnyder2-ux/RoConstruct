// from server: 71% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 005dc0c0  unit: RBX::VPartInstance::?$FilteredSelection  size: 136 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005dc0c0
//
// 005dc0c0  56                   push esi
// 005dc0c1  8bf1                 mov esi, ecx
// 005dc0c3  8b4c2408             mov ecx, dword ptr [esp + 8]
// 005dc0c7  d901                 fld dword ptr [ecx]
// 005dc0c9  d89ec4010000         fcomp dword ptr [esi + 0x1c4]
// 005dc0cf  dfe0                 fnstsw ax
// 005dc0d1  f6c444               test ah, 0x44
// 005dc0d4  7a20                 jp 0x5dc0f6
// 005dc0d6  d94104               fld dword ptr [ecx + 4]
// 005dc0d9  d89ec8010000         fcomp dword ptr [esi + 0x1c8]
// 005dc0df  dfe0                 fnstsw ax
// 005dc0e1  f6c444               test ah, 0x44
// 005dc0e4  7a10                 jp 0x5dc0f6
// 005dc0e6  d94108               fld dword ptr [ecx + 8]
// 005dc0e9  d89ecc010000         fcomp dword ptr [esi + 0x1cc]
// 005dc0ef  dfe0                 fnstsw ax
// 005dc0f1  f6c444               test ah, 0x44
// 005dc0f4  7b26                 jnp 0x5dc11c
// 005dc0f6  d901                 fld dword ptr [ecx]
// 005dc0f8  68cca49700           push 0x97a4cc
// 005dc0fd  d99ec4010000         fstp dword ptr [esi + 0x1c4]
// 005dc103  d94104               fld dword ptr [ecx + 4]
// 005dc106  d99ec8010000         fstp dword ptr [esi + 0x1c8]
// 005dc10c  d94108               fld dword ptr [ecx + 8]
// 005dc10f  8bce                 mov ecx, esi
// 005dc111  d99ecc010000         fstp dword ptr [esi + 0x1cc]
// 005dc117  e8e419e3ff           call 0x40db00
// 005dc11c  8b86b8010000         mov eax, dword ptr [esi + 0x1b8]
// 005dc122  f7d8                 neg eax
// 005dc124  1bc0                 sbb eax, eax
// 005dc126  83c002               add eax, 2
// 005dc129  33c9                 xor ecx, ecx
// 005dc12b  83f802               cmp eax, 2
// 005dc12e  0f95c1               setne cl
// 005dc131  8986b8010000         mov dword ptr [esi + 0x1b8], eax
// 005dc137  49                   dec ecx
// 005dc138  81e1f0000000         and ecx, 0xf0
// 005dc13e  898eb4010000         mov dword ptr [esi + 0x1b4], ecx
// 005dc144  5e                   pop esi
// 005dc145  c20400               ret 4

#pragma float_control(precise, off)

struct Vector3
{
    float x, y, z;
};

extern char property;

struct S
{
    unsigned char padding[0x1b4];
    int mask;
    int state;
    unsigned char gap[8];
    float x, y, z;

    void notify(const void*);
    void f(const Vector3&);
};

void S::f(const Vector3& value)
{
    if (x != value.x || y != value.y || z != value.z)
    {
        x = value.x;
        y = value.y;
        z = value.z;
        notify(&property);
    }

    state = state ? 1 : 2;
    mask = state == 2 ? 0xf0 : 0;
}
