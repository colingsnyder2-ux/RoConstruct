// from server: 100% by Xemicl
// roc 2012-06 00449ad0  unit: CClassTreeView  size: 94 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00449ad0
//
// 00449ad0  6aff                 push -1
// 00449ad2  68f8e1a900           push 0xa9e1f8
// 00449ad7  64a100000000         mov eax, dword ptr fs:[0]
// 00449add  50                   push eax
// 00449ade  64892500000000       mov dword ptr fs:[0], esp
// 00449ae5  51                   push ecx
// 00449ae6  56                   push esi
// 00449ae7  8bf1                 mov esi, ecx
// 00449ae9  89742404             mov dword ptr [esp + 4], esi
// 00449aed  e83e925700           call 0x9c2d30
// 00449af2  8d8ea0000000         lea ecx, [esi + 0xa0]
// 00449af8  c744241000000000     mov dword ptr [esp + 0x10], 0
// 00449b00  c7067c26b500         mov dword ptr [esi], 0xb5267c
// 00449b06  c74660f425b500       mov dword ptr [esi + 0x60], 0xb525f4
// 00449b0d  e87c8d5300           call 0x98288e
// 00449b12  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00449b16  c786a800000000000000 mov dword ptr [esi + 0xa8], 0
// 00449b20  8bc6                 mov eax, esi
// 00449b22  5e                   pop esi
// 00449b23  64890d00000000       mov dword ptr fs:[0], ecx
// 00449b2a  83c410               add esp, 0x10
// 00449b2d  c3                   ret 
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