// from server: 100% by EspClaude
// from server: 100% by tester
// roc 2008-06 00458d10  unit: CRobloxReportPaneView  size: 79 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00458d10
//
// 00458d10  6aff                 push -1
// 00458d12  6888277c00           push 0x7c2788
// 00458d17  64a100000000         mov eax, dword ptr fs:[0]
// 00458d1d  50                   push eax
// 00458d1e  64892500000000       mov dword ptr fs:[0], esp
// 00458d25  51                   push ecx
// 00458d26  56                   push esi
// 00458d27  8bf1                 mov esi, ecx
// 00458d29  89742404             mov dword ptr [esp + 4], esi
// 00458d2d  8d8ed4030000         lea ecx, [esi + 0x3c4]
// 00458d33  c744241000000000     mov dword ptr [esp + 0x10], 0
// 00458d3b  e840d0faff           call 0x405d80
// 00458d40  8bce                 mov ecx, esi
// 00458d42  c7442410ffffffff     mov dword ptr [esp + 0x10], 0xffffffff
// 00458d4a  e821feffff           call 0x458b70
// 00458d4f  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00458d53  5e                   pop esi
// 00458d54  64890d00000000       mov dword ptr fs:[0], ecx
// 00458d5b  83c410               add esp, 0x10
// 00458d5e  c3                   ret 

struct Base {
    char data[0x3c4];
    ~Base();
};

struct Member {
    ~Member();
};

struct ImageKeyButton : Base {
    Member member;
    ~ImageKeyButton();
};

ImageKeyButton::~ImageKeyButton()
{
}
