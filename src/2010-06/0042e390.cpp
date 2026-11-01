// from server: 100% by Yeetserama
// roc 2010-06 0042e390  unit: CMemberTreeView  size: 92 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0042e390
//
// 0042e390  6aff                 push -1
// 0042e392  6838039800           push 0x980338
// 0042e397  64a100000000         mov eax, dword ptr fs:[0]
// 0042e39d  50                   push eax
// 0042e39e  64892500000000       mov dword ptr fs:[0], esp
// 0042e3a5  51                   push ecx
// 0042e3a6  56                   push esi
// 0042e3a7  8bf1                 mov esi, ecx
// 0042e3a9  89742404             mov dword ptr [esp + 4], esi
// 0042e3ad  c706346aa000         mov dword ptr [esi], 0xa06a34
// 0042e3b3  c74660ac69a000       mov dword ptr [esi + 0x60], 0xa069ac
// 0042e3ba  8d8ea0000000         lea ecx, [esi + 0xa0]
// 0042e3c0  c744241000000000     mov dword ptr [esp + 0x10], 0
// 0042e3c8  e8659d3700           call 0x7a8132
// 0042e3cd  8bce                 mov ecx, esi
// 0042e3cf  c7442410ffffffff     mov dword ptr [esp + 0x10], 0xffffffff
// 0042e3d7  e884ac3b00           call 0x7e9060
// 0042e3dc  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0042e3e0  5e                   pop esi
// 0042e3e1  64890d00000000       mov dword ptr fs:[0], ecx
// 0042e3e8  83c410               add esp, 0x10
// 0042e3eb  c3                   ret 
// copied from an identical function in another client (function ??1CClassTreeView@ns_ROCX00000c@@UAE@XZ)

namespace ns_ROCX00000c {
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
