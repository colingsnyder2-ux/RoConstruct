// from server: 100% by Yeetserama
// roc 2007-08 00434110  unit: CClassTreeView  size: 104 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00434110
//
// 00434110  6aff                 push -1
// 00434112  68d8df7300           push 0x73dfd8
// 00434117  64a100000000         mov eax, dword ptr fs:[0]
// 0043411d  50                   push eax
// 0043411e  51                   push ecx
// 0043411f  56                   push esi
// 00434120  a188518b00           mov eax, dword ptr [0x8b5188]
// 00434125  33c4                 xor eax, esp
// 00434127  50                   push eax
// 00434128  8d44240c             lea eax, [esp + 0xc]
// 0043412c  64a300000000         mov dword ptr fs:[0], eax
// 00434132  8bf1                 mov esi, ecx
// 00434134  89742408             mov dword ptr [esp + 8], esi
// 00434138  c7060cc47800         mov dword ptr [esi], 0x78c40c
// 0043413e  c746608cc37800       mov dword ptr [esi + 0x60], 0x78c38c
// 00434145  8d8ea0000000         lea ecx, [esi + 0xa0]
// 0043414b  c744241400000000     mov dword ptr [esp + 0x14], 0
// 00434153  e862c31f00           call 0x6304ba
// 00434158  8bce                 mov ecx, esi
// 0043415a  c7442414ffffffff     mov dword ptr [esp + 0x14], 0xffffffff
// 00434162  e8c90d2300           call 0x664f30
// 00434167  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0043416b  64890d00000000       mov dword ptr fs:[0], ecx
// 00434172  59                   pop ecx
// 00434173  5e                   pop esi
// 00434174  83c410               add esp, 0x10
// 00434177  c3                   ret 
// copied from an identical function in another client (function ??1CClassTreeView@ns_ROCX00001f@@UAE@XZ)

namespace ns_ROCX00001f {
// from server: 100% by king_originala
struct Primary
{
    virtual ~Primary();
    char padding[0x5c];
};

struct Secondary
{
    virtual ~Secondary();
    char padding[0x3c];
};

struct Base : Primary, Secondary
{
    virtual ~Base();
};

struct Member
{
    ~Member();
};

struct CClassTreeView : Base
{
    Member member;
    virtual ~CClassTreeView();
};

CClassTreeView::~CClassTreeView()
{
}
}
