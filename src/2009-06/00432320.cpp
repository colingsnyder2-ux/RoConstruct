// from server: 100% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 00438990  unit: IIHAAH::?$CMap  size: 82 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00438990
//
// 00438990  6aff                 push -1
// 00438992  68f8037c00           push 0x7c03f8
// 00438997  64a100000000         mov eax, dword ptr fs:[0]
// 0043899d  50                   push eax
// 0043899e  64892500000000       mov dword ptr fs:[0], esp
// 004389a5  51                   push ecx
// 004389a6  56                   push esi
// 004389a7  8bf1                 mov esi, ecx
// 004389a9  89742404             mov dword ptr [esp + 4], esi
// 004389ad  8d4e20               lea ecx, [esi + 0x20]
// 004389b0  c744241000000000     mov dword ptr [esp + 0x10], 0
// 004389b8  c7018c378100         mov dword ptr [ecx], 0x81378c
// 004389be  e86da72600           call 0x6a3130
// 004389c3  8bce                 mov ecx, esi
// 004389c5  c7442410ffffffff     mov dword ptr [esp + 0x10], 0xffffffff
// 004389cd  e864872600           call 0x6a1136
// 004389d2  8b4c2408             mov ecx, dword ptr [esp + 8]
// 004389d6  5e                   pop esi
// 004389d7  64890d00000000       mov dword ptr fs:[0], ecx
// 004389de  83c410               add esp, 0x10
// 004389e1  c3                   ret 

struct Base
{
    unsigned char storage[32];
    ~Base();
};

struct Member
{
    unsigned long vptr;
    void clear();
};

struct S : Base
{
    Member member;
    ~S();
};

S::~S()
{
    member.vptr = 0x0081378CUL;
    member.clear();
}
