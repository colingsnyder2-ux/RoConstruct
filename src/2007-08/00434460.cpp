// from server: 100% by Yeetserama
// roc 2007-08 00434460  unit: CMemberTreeView  size: 104 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00434460
//
// 00434460  6aff                 push -1
// 00434462  68d8df7300           push 0x73dfd8
// 00434467  64a100000000         mov eax, dword ptr fs:[0]
// 0043446d  50                   push eax
// 0043446e  51                   push ecx
// 0043446f  56                   push esi
// 00434470  a188518b00           mov eax, dword ptr [0x8b5188]
// 00434475  33c4                 xor eax, esp
// 00434477  50                   push eax
// 00434478  8d44240c             lea eax, [esp + 0xc]
// 0043447c  64a300000000         mov dword ptr fs:[0], eax
// 00434482  8bf1                 mov esi, ecx
// 00434484  89742408             mov dword ptr [esp + 8], esi
// 00434488  c706bcc77800         mov dword ptr [esi], 0x78c7bc
// 0043448e  c746603cc77800       mov dword ptr [esi + 0x60], 0x78c73c
// 00434495  8d8ea0000000         lea ecx, [esi + 0xa0]
// 0043449b  c744241400000000     mov dword ptr [esp + 0x14], 0
// 004344a3  e812c01f00           call 0x6304ba
// 004344a8  8bce                 mov ecx, esi
// 004344aa  c7442414ffffffff     mov dword ptr [esp + 0x14], 0xffffffff
// 004344b2  e8790a2300           call 0x664f30
// 004344b7  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 004344bb  64890d00000000       mov dword ptr fs:[0], ecx
// 004344c2  59                   pop ecx
// 004344c3  5e                   pop esi
// 004344c4  83c410               add esp, 0x10
// 004344c7  c3                   ret 
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
