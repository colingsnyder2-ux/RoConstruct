// from server: 100% by EspClaude
// roc 2009-06 0042cda0  unit: CMemberTreeView  size: 92 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0042cda0
//
// 0042cda0  6aff                 push -1
// 0042cda2  68c8f38400           push 0x84f3c8
// 0042cda7  64a100000000         mov eax, dword ptr fs:[0]
// 0042cdad  50                   push eax
// 0042cdae  64892500000000       mov dword ptr fs:[0], esp
// 0042cdb5  51                   push ecx
// 0042cdb6  56                   push esi
// 0042cdb7  8bf1                 mov esi, ecx
// 0042cdb9  89742404             mov dword ptr [esp + 4], esi
// 0042cdbd  c7063c2f8b00         mov dword ptr [esi], 0x8b2f3c
// 0042cdc3  c74660b42e8b00       mov dword ptr [esi + 0x60], 0x8b2eb4
// 0042cdca  8d8ea0000000         lea ecx, [esi + 0xa0]
// 0042cdd0  c744241000000000     mov dword ptr [esp + 0x10], 0
// 0042cdd8  e8edc32e00           call 0x7191ca
// 0042cddd  8bce                 mov ecx, esi
// 0042cddf  c7442410ffffffff     mov dword ptr [esp + 0x10], 0xffffffff
// 0042cde7  e834d23200           call 0x75a020
// 0042cdec  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0042cdf0  5e                   pop esi
// 0042cdf1  64890d00000000       mov dword ptr fs:[0], ecx
// 0042cdf8  83c410               add esp, 0x10
// 0042cdfb  c3                   ret 
// copied from an identical function in another client (function ??1CClassTreeView@ns_ROCX00002f@@UAE@XZ)

namespace ns_ROCX00002f {
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
