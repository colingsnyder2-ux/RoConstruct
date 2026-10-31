// from server: 81% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 0044c360  unit: CRobloxModule  size: 102 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0044c360
//
// 0044c360  6aff                 push -1
// 0044c362  6820127c00           push 0x7c1220
// 0044c367  64a100000000         mov eax, dword ptr fs:[0]
// 0044c36d  50                   push eax
// 0044c36e  64892500000000       mov dword ptr fs:[0], esp
// 0044c375  83ec08               sub esp, 8
// 0044c378  56                   push esi
// 0044c379  8bf1                 mov esi, ecx
// 0044c37b  57                   push edi
// 0044c37c  89742408             mov dword ptr [esp + 8], esi
// 0044c380  8d7e30               lea edi, [esi + 0x30]
// 0044c383  c744241800000000     mov dword ptr [esp + 0x18], 0
// 0044c38b  897c240c             mov dword ptr [esp + 0xc], edi
// 0044c38f  8bcf                 mov ecx, edi
// 0044c391  c644241801           mov byte ptr [esp + 0x18], 1
// 0044c396  e835b4fbff           call 0x4077d0
// 0044c39b  8b3f                 mov edi, dword ptr [edi]
// 0044c39d  57                   push edi
// 0044c39e  e8d7422500           call 0x6a067a
// 0044c3a3  83c404               add esp, 4
// 0044c3a6  8bce                 mov ecx, esi
// 0044c3a8  c7442418ffffffff     mov dword ptr [esp + 0x18], 0xffffffff
// 0044c3b0  e8a74e2500           call 0x6a125c
// 0044c3b5  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0044c3b9  5f                   pop edi
// 0044c3ba  5e                   pop esi
// 0044c3bb  64890d00000000       mov dword ptr fs:[0], ecx
// 0044c3c2  83c414               add esp, 0x14
// 0044c3c5  c3                   ret 

void __cdecl operator delete(void *) throw();

struct Base {
    unsigned char data[48];
    ~Base();
};

struct TreeStorage {
    void *head;
    unsigned char data[16];
    __forceinline ~TreeStorage();
};

struct Tree : TreeStorage {
    void clear();
    __forceinline ~Tree();
};

struct S : Base {
    Tree tree;
    ~S();
};

__forceinline TreeStorage::~TreeStorage()
{
    delete head;
}

__forceinline Tree::~Tree()
{
    clear();
}

S::~S()
{
}
