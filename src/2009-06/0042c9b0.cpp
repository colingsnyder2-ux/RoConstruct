// from server: 100% by EspClaude
// roc 2009-06 0042c9b0  unit: CClassTreeView  size: 92 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0042c9b0
//
// 0042c9b0  6aff                 push -1
// 0042c9b2  68c8f38400           push 0x84f3c8
// 0042c9b7  64a100000000         mov eax, dword ptr fs:[0]
// 0042c9bd  50                   push eax
// 0042c9be  64892500000000       mov dword ptr fs:[0], esp
// 0042c9c5  51                   push ecx
// 0042c9c6  56                   push esi
// 0042c9c7  8bf1                 mov esi, ecx
// 0042c9c9  89742404             mov dword ptr [esp + 4], esi
// 0042c9cd  c706742b8b00         mov dword ptr [esi], 0x8b2b74
// 0042c9d3  c74660ec2a8b00       mov dword ptr [esi + 0x60], 0x8b2aec
// 0042c9da  8d8ea0000000         lea ecx, [esi + 0xa0]
// 0042c9e0  c744241000000000     mov dword ptr [esp + 0x10], 0
// 0042c9e8  e8ddc72e00           call 0x7191ca
// 0042c9ed  8bce                 mov ecx, esi
// 0042c9ef  c7442410ffffffff     mov dword ptr [esp + 0x10], 0xffffffff
// 0042c9f7  e824d63200           call 0x75a020
// 0042c9fc  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0042ca00  5e                   pop esi
// 0042ca01  64890d00000000       mov dword ptr fs:[0], ecx
// 0042ca08  83c410               add esp, 0x10
// 0042ca0b  c3                   ret 
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
