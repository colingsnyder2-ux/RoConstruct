// from server: 100% by EspClaude
// roc 2009-06 0042cd30  unit: CMemberTreeView  size: 101 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0042cd30
//
// 0042cd30  6aff                 push -1
// 0042cd32  68c8f38400           push 0x84f3c8
// 0042cd37  64a100000000         mov eax, dword ptr fs:[0]
// 0042cd3d  50                   push eax
// 0042cd3e  64892500000000       mov dword ptr fs:[0], esp
// 0042cd45  51                   push ecx
// 0042cd46  56                   push esi
// 0042cd47  8bf1                 mov esi, ecx
// 0042cd49  89742404             mov dword ptr [esp + 4], esi
// 0042cd4d  e89ed23200           call 0x759ff0
// 0042cd52  8d8ea0000000         lea ecx, [esi + 0xa0]
// 0042cd58  c744241000000000     mov dword ptr [esp + 0x10], 0
// 0042cd60  c7063c2f8b00         mov dword ptr [esi], 0x8b2f3c
// 0042cd66  c74660b42e8b00       mov dword ptr [esi + 0x60], 0x8b2eb4
// 0042cd6d  e876c42e00           call 0x7191e8
// 0042cd72  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0042cd76  c686a800000001       mov byte ptr [esi + 0xa8], 1
// 0042cd7d  c786ac00000000000000 mov dword ptr [esi + 0xac], 0
// 0042cd87  8bc6                 mov eax, esi
// 0042cd89  5e                   pop esi
// 0042cd8a  64890d00000000       mov dword ptr fs:[0], ecx
// 0042cd91  83c410               add esp, 0x10
// 0042cd94  c3                   ret 
// copied from an identical function in another client (function ??0CMemberTreeView@ns_ROCX000036@@QAE@XZ)

namespace ns_ROCX000036 {
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

struct CXTTreeCtrlBase : Primary, Secondary
{
    CXTTreeCtrlBase();
    virtual ~CXTTreeCtrlBase();
};

struct Member
{
    Member();
    ~Member();
    char storage[8];
};

struct CMemberTreeView : CXTTreeCtrlBase
{
    CMemberTreeView();
    virtual ~CMemberTreeView();

    Member member;
    bool enabled;
    int value;
};

CMemberTreeView::CMemberTreeView()
{
    enabled = true;
    value = 0;
}
}
