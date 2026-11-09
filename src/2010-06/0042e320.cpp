// from server: 100% by Yeetserama
// roc 2010-06 0042e320  unit: CMemberTreeView  size: 101 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0042e320
//
// 0042e320  6aff                 push -1
// 0042e322  6838039800           push 0x980338
// 0042e327  64a100000000         mov eax, dword ptr fs:[0]
// 0042e32d  50                   push eax
// 0042e32e  64892500000000       mov dword ptr fs:[0], esp
// 0042e335  51                   push ecx
// 0042e336  56                   push esi
// 0042e337  8bf1                 mov esi, ecx
// 0042e339  89742404             mov dword ptr [esp + 4], esi
// 0042e33d  e8eeac3b00           call 0x7e9030
// 0042e342  8d8ea0000000         lea ecx, [esi + 0xa0]
// 0042e348  c744241000000000     mov dword ptr [esp + 0x10], 0
// 0042e350  c706346aa000         mov dword ptr [esi], 0xa06a34
// 0042e356  c74660ac69a000       mov dword ptr [esi + 0x60], 0xa069ac
// 0042e35d  e8ee9d3700           call 0x7a8150
// 0042e362  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0042e366  c686a800000001       mov byte ptr [esi + 0xa8], 1
// 0042e36d  c786ac00000000000000 mov dword ptr [esi + 0xac], 0
// 0042e377  8bc6                 mov eax, esi
// 0042e379  5e                   pop esi
// 0042e37a  64890d00000000       mov dword ptr fs:[0], ecx
// 0042e381  83c410               add esp, 0x10
// 0042e384  c3                   ret 
// copied from an identical function in another client (function ??0CMemberTreeView@ns_ROCX000013@@QAE@XZ)

namespace ns_ROCX000013 {
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
