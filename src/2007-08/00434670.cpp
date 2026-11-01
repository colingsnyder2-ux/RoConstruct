// from server: 100% by Yeetserama
// roc 2007-08 00434670  unit: CDeclarationView  size: 106 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00434670
//
// 00434670  6aff                 push -1
// 00434672  68d8df7300           push 0x73dfd8
// 00434677  64a100000000         mov eax, dword ptr fs:[0]
// 0043467d  50                   push eax
// 0043467e  51                   push ecx
// 0043467f  56                   push esi
// 00434680  a188518b00           mov eax, dword ptr [0x8b5188]
// 00434685  33c4                 xor eax, esp
// 00434687  50                   push eax
// 00434688  8d44240c             lea eax, [esp + 0xc]
// 0043468c  64a300000000         mov dword ptr fs:[0], eax
// 00434692  8bf1                 mov esi, ecx
// 00434694  89742408             mov dword ptr [esp + 8], esi
// 00434698  e863082300           call 0x664f00
// 0043469d  8d8ea0000000         lea ecx, [esi + 0xa0]
// 004346a3  c744241400000000     mov dword ptr [esp + 0x14], 0
// 004346ab  c7060cc47800         mov dword ptr [esi], 0x78c40c
// 004346b1  c746608cc37800       mov dword ptr [esi + 0x60], 0x78c38c
// 004346b8  e803be1f00           call 0x6304c0
// 004346bd  c786a800000000000000 mov dword ptr [esi + 0xa8], 0
// 004346c7  8bc6                 mov eax, esi
// 004346c9  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 004346cd  64890d00000000       mov dword ptr fs:[0], ecx
// 004346d4  59                   pop ecx
// 004346d5  5e                   pop esi
// 004346d6  83c410               add esp, 0x10
// 004346d9  c3                   ret 
// copied from an identical function in another client (function ??0CDeclarationView@ns_ROCX00000a@@QAE@XZ)

namespace ns_ROCX00000a {
// from server: 100% by king_originala
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
