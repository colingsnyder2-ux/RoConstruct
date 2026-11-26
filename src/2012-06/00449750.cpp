// from server: 100% by Xemicl
// roc 2012-06 00449750  unit: CMemberTreeView  size: 101 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00449750
//
// 00449750  6aff                 push -1
// 00449752  68f8e1a900           push 0xa9e1f8
// 00449757  64a100000000         mov eax, dword ptr fs:[0]
// 0044975d  50                   push eax
// 0044975e  64892500000000       mov dword ptr fs:[0], esp
// 00449765  51                   push ecx
// 00449766  56                   push esi
// 00449767  8bf1                 mov esi, ecx
// 00449769  89742404             mov dword ptr [esp + 4], esi
// 0044976d  e8be955700           call 0x9c2d30
// 00449772  8d8ea0000000         lea ecx, [esi + 0xa0]
// 00449778  c744241000000000     mov dword ptr [esp + 0x10], 0
// 00449780  c706542ab500         mov dword ptr [esi], 0xb52a54
// 00449786  c74660cc29b500       mov dword ptr [esi + 0x60], 0xb529cc
// 0044978d  e8fc905300           call 0x98288e
// 00449792  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00449796  c686a800000001       mov byte ptr [esi + 0xa8], 1
// 0044979d  c786ac00000000000000 mov dword ptr [esi + 0xac], 0
// 004497a7  8bc6                 mov eax, esi
// 004497a9  5e                   pop esi
// 004497aa  64890d00000000       mov dword ptr fs:[0], ecx
// 004497b1  83c410               add esp, 0x10
// 004497b4  c3                   ret 
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