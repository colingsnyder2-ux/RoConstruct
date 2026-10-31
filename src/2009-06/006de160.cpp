// from server: 92% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 0060d5a0  unit: RBX::BlockBlockContact  size: 100 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0060d5a0
//
// 0060d5a0  6aff                 push -1
// 0060d5a2  680b8c7d00           push 0x7d8c0b
// 0060d5a7  64a100000000         mov eax, dword ptr fs:[0]
// 0060d5ad  50                   push eax
// 0060d5ae  64892500000000       mov dword ptr fs:[0], esp
// 0060d5b5  51                   push ecx
// 0060d5b6  56                   push esi
// 0060d5b7  8bf1                 mov esi, ecx
// 0060d5b9  57                   push edi
// 0060d5ba  89742408             mov dword ptr [esp + 8], esi
// 0060d5be  8b4640               mov eax, dword ptr [esi + 0x40]
// 0060d5c1  33ff                 xor edi, edi
// 0060d5c3  50                   push eax
// 0060d5c4  897c2418             mov dword ptr [esp + 0x18], edi
// 0060d5c8  e853a7efff           call 0x507d20
// 0060d5cd  897e40               mov dword ptr [esi + 0x40], edi
// 0060d5d0  897e44               mov dword ptr [esi + 0x44], edi
// 0060d5d3  897e48               mov dword ptr [esi + 0x48], edi
// 0060d5d6  8b4e34               mov ecx, dword ptr [esi + 0x34]
// 0060d5d9  51                   push ecx
// 0060d5da  c744241cffffffff     mov dword ptr [esp + 0x1c], 0xffffffff
// 0060d5e2  e839a7efff           call 0x507d20
// 0060d5e7  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0060d5eb  83c408               add esp, 8
// 0060d5ee  897e34               mov dword ptr [esi + 0x34], edi
// 0060d5f1  897e38               mov dword ptr [esi + 0x38], edi
// 0060d5f4  897e3c               mov dword ptr [esi + 0x3c], edi
// 0060d5f7  5f                   pop edi
// 0060d5f8  5e                   pop esi
// 0060d5f9  64890d00000000       mov dword ptr fs:[0], ecx
// 0060d600  83c410               add esp, 0x10
// 0060d603  c3                   ret 

void __cdecl alignedFree(void *);

struct ArrayStorage {
    void *data;
    int size;
    int capacity;
    ~ArrayStorage();
};

inline ArrayStorage::~ArrayStorage()
{
    alignedFree(data);
    data = 0;
    size = 0;
    capacity = 0;
}

struct BlockBlockContact {
    char padding[0x34];
    ArrayStorage first;
    ArrayStorage second;
    ~BlockBlockContact();
};

BlockBlockContact::~BlockBlockContact()
{
}
