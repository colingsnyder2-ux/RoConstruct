// from server: 100% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 00461fd0  unit: Scintilla::CScintillaFindReplaceDlg  size: 105 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00461fd0
//
// 00461fd0  6aff                 push -1
// 00461fd2  6828317c00           push 0x7c3128
// 00461fd7  64a100000000         mov eax, dword ptr fs:[0]
// 00461fdd  50                   push eax
// 00461fde  64892500000000       mov dword ptr fs:[0], esp
// 00461fe5  51                   push ecx
// 00461fe6  56                   push esi
// 00461fe7  8bf1                 mov esi, ecx
// 00461fe9  89742404             mov dword ptr [esp + 4], esi
// 00461fed  8b86b8000000         mov eax, dword ptr [esi + 0xb8]
// 00461ff3  c744241000000000     mov dword ptr [esp + 0x10], 0
// 00461ffb  c786b40000005caa8100 mov dword ptr [esi + 0xb4], 0x81aa5c
// 00462005  85c0                 test eax, eax
// 00462007  7409                 je 0x462012
// 00462009  50                   push eax
// 0046200a  e83be92300           call 0x6a094a
// 0046200f  83c404               add esp, 4
// 00462012  8d4e58               lea ecx, [esi + 0x58]
// 00462015  e8e6dfffff           call 0x460000
// 0046201a  8bce                 mov ecx, esi
// 0046201c  c7442410ffffffff     mov dword ptr [esp + 0x10], 0xffffffff
// 00462024  e86fef2300           call 0x6a0f98
// 00462029  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0046202d  5e                   pop esi
// 0046202e  64890d00000000       mov dword ptr fs:[0], ecx
// 00462035  83c410               add esp, 0x10
// 00462038  c3                   ret 

extern "C" void __cdecl sub_6a094a(void*);

struct Base {
    char data[0x58];
    ~Base();
};

struct Member {
    char data[0x5c];
    ~Member();
};

struct S : Base {
    Member member_58;
    void* field_b4;
    void* field_b8;

    ~S();
};

S::~S()
{
    field_b4 = (void*)0x81aa5c;
    if (field_b8)
        sub_6a094a(field_b8);
}
