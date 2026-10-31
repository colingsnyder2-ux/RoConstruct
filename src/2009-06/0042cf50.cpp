// from server: 100% by EspClaude
// roc 2009-06 0042cf50  unit: CDeclarationView  size: 94 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0042cf50
//
// 0042cf50  6aff                 push -1
// 0042cf52  68c8f38400           push 0x84f3c8
// 0042cf57  64a100000000         mov eax, dword ptr fs:[0]
// 0042cf5d  50                   push eax
// 0042cf5e  64892500000000       mov dword ptr fs:[0], esp
// 0042cf65  51                   push ecx
// 0042cf66  56                   push esi
// 0042cf67  8bf1                 mov esi, ecx
// 0042cf69  89742404             mov dword ptr [esp + 4], esi
// 0042cf6d  e87ed03200           call 0x759ff0
// 0042cf72  8d8ea0000000         lea ecx, [esi + 0xa0]
// 0042cf78  c744241000000000     mov dword ptr [esp + 0x10], 0
// 0042cf80  c706742b8b00         mov dword ptr [esi], 0x8b2b74
// 0042cf86  c74660ec2a8b00       mov dword ptr [esi + 0x60], 0x8b2aec
// 0042cf8d  e856c22e00           call 0x7191e8
// 0042cf92  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0042cf96  c786a800000000000000 mov dword ptr [esi + 0xa8], 0
// 0042cfa0  8bc6                 mov eax, esi
// 0042cfa2  5e                   pop esi
// 0042cfa3  64890d00000000       mov dword ptr fs:[0], ecx
// 0042cfaa  83c410               add esp, 0x10
// 0042cfad  c3                   ret 
// copied from an identical function in another client (function ??0CDeclarationView@ns_ROCX00003a@@QAE@XZ)

namespace ns_ROCX00003a {
struct Primary {
    virtual ~Primary();
    char padding[0x5c];
};

struct Secondary {
    virtual ~Secondary();
    char padding[0x3c];
};

struct Base : Primary, Secondary {
    Base();
    virtual ~Base();
};

struct Member {
    Member();
    ~Member();
    char storage[8];
};

struct CDeclarationView : Base {
    Member member;
    int value;

    CDeclarationView();
    virtual ~CDeclarationView();
};

CDeclarationView::CDeclarationView()
    : Base(), member(), value(0)
{
}
}
