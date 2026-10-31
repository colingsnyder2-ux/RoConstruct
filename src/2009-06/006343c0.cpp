// from server: 100% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 005a9580  unit: RBX::VScriptContext::?$FactoryProduct  size: 121 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005a9580
//
// 005a9580  a1c8b19500           mov eax, dword ptr [0x95b1c8]
// 005a9585  56                   push esi
// 005a9586  57                   push edi
// 005a9587  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 005a958b  50                   push eax
// 005a958c  6a02                 push 2
// 005a958e  57                   push edi
// 005a958f  e81c800600           call 0x6115b0
// 005a9594  8b0dc8b19500         mov ecx, dword ptr [0x95b1c8]
// 005a959a  51                   push ecx
// 005a959b  6a01                 push 1
// 005a959d  57                   push edi
// 005a959e  8bf0                 mov esi, eax
// 005a95a0  e80b800600           call 0x6115b0
// 005a95a5  d94624               fld dword ptr [esi + 0x24]
// 005a95a8  8bc8                 mov ecx, eax
// 005a95aa  d85924               fcomp dword ptr [ecx + 0x24]
// 005a95ad  83c418               add esp, 0x18
// 005a95b0  dfe0                 fnstsw ax
// 005a95b2  f6c444               test ah, 0x44
// 005a95b5  7a2b                 jp 0x5a95e2
// 005a95b7  d94628               fld dword ptr [esi + 0x28]
// 005a95ba  d85928               fcomp dword ptr [ecx + 0x28]
// 005a95bd  dfe0                 fnstsw ax
// 005a95bf  f6c444               test ah, 0x44
// 005a95c2  7a1e                 jp 0x5a95e2
// 005a95c4  d9462c               fld dword ptr [esi + 0x2c]
// 005a95c7  d8592c               fcomp dword ptr [ecx + 0x2c]
// 005a95ca  dfe0                 fnstsw ax
// 005a95cc  f6c444               test ah, 0x44
// 005a95cf  7a11                 jp 0x5a95e2
// 005a95d1  56                   push esi
// 005a95d2  e8a99cf6ff           call 0x513280
// 005a95d7  84c0                 test al, al
// 005a95d9  7407                 je 0x5a95e2
// 005a95db  b801000000           mov eax, 1
// 005a95e0  eb02                 jmp 0x5a95e4
// 005a95e2  33c0                 xor eax, eax
// 005a95e4  0fb6d0               movzx edx, al
// 005a95e7  52                   push edx
// 005a95e8  57                   push edi
// 005a95e9  e8028e0600           call 0x6123f0
// 005a95ee  83c408               add esp, 8
// 005a95f1  5f                   pop edi
// 005a95f2  b801000000           mov eax, 1
// 005a95f7  5e                   pop esi
// 005a95f8  c3                   ret 

#pragma float_control(precise, off)

struct Matrix {
    float elements[9];
    bool equal(const Matrix& other) const;
};

struct Transform {
    Matrix rotation;
    float x, y, z;
};

extern void* typeDescriptor;

extern "C" Transform* __cdecl getTransform(void* state, int index, void* type);
extern "C" void __cdecl pushBoolean(void* state, int value);

int __cdecl compareTransforms(void* state)
{
    Transform* a = getTransform(state, 2, typeDescriptor);
    Transform* b = getTransform(state, 1, typeDescriptor);

    int result = b->x == a->x &&
                 b->y == a->y &&
                 b->z == a->z &&
                 b->rotation.equal(a->rotation);

    pushBoolean(state, static_cast<unsigned char>(result));
    return 1;
}
