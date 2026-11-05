// from server: 100% by Yeetserama
// roc 2007-08 004343e0  unit: CMemberTreeView  size: 113 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004343e0
//
// 004343e0  6aff                 push -1
// 004343e2  68d8df7300           push 0x73dfd8
// 004343e7  64a100000000         mov eax, dword ptr fs:[0]
// 004343ed  50                   push eax
// 004343ee  51                   push ecx
// 004343ef  56                   push esi
// 004343f0  a188518b00           mov eax, dword ptr [0x8b5188]
// 004343f5  33c4                 xor eax, esp
// 004343f7  50                   push eax
// 004343f8  8d44240c             lea eax, [esp + 0xc]
// 004343fc  64a300000000         mov dword ptr fs:[0], eax
// 00434402  8bf1                 mov esi, ecx
// 00434404  89742408             mov dword ptr [esp + 8], esi
// 00434408  e8f30a2300           call 0x664f00
// 0043440d  8d8ea0000000         lea ecx, [esi + 0xa0]
// 00434413  c744241400000000     mov dword ptr [esp + 0x14], 0
// 0043441b  c706bcc77800         mov dword ptr [esi], 0x78c7bc
// 00434421  c746603cc77800       mov dword ptr [esi + 0x60], 0x78c73c
// 00434428  e893c01f00           call 0x6304c0
// 0043442d  c686a800000001       mov byte ptr [esi + 0xa8], 1
// 00434434  c786ac00000000000000 mov dword ptr [esi + 0xac], 0
// 0043443e  8bc6                 mov eax, esi
// 00434440  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00434444  64890d00000000       mov dword ptr fs:[0], ecx
// 0043444b  59                   pop ecx
// 0043444c  5e                   pop esi
// 0043444d  83c410               add esp, 0x10
// 00434450  c3                   ret 
// copied from an identical function in another client (function ??0CMemberTreeView@ns_ROCX000006@@QAE@XZ)

namespace ns_ROCX000006 {
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
