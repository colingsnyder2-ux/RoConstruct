// from server: 100% by EspClaude
// roc 2009-06 0042c5c0  unit: CBrowserFrameWnd  size: 89 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0042c5c0
//
// 0042c5c0  6aff                 push -1
// 0042c5c2  6868f38400           push 0x84f368
// 0042c5c7  64a100000000         mov eax, dword ptr fs:[0]
// 0042c5cd  50                   push eax
// 0042c5ce  64892500000000       mov dword ptr fs:[0], esp
// 0042c5d5  51                   push ecx
// 0042c5d6  56                   push esi
// 0042c5d7  8bf1                 mov esi, ecx
// 0042c5d9  89742404             mov dword ptr [esp + 4], esi
// 0042c5dd  c7064c248b00         mov dword ptr [esi], 0x8b244c
// 0042c5e3  8b8ee8000000         mov ecx, dword ptr [esi + 0xe8]
// 0042c5e9  c744241000000000     mov dword ptr [esp + 0x10], 0
// 0042c5f1  85c9                 test ecx, ecx
// 0042c5f3  7405                 je 0x42c5fa
// 0042c5f5  e8aec92e00           call 0x718fa8
// 0042c5fa  8bce                 mov ecx, esi
// 0042c5fc  c7442410ffffffff     mov dword ptr [esp + 0x10], 0xffffffff
// 0042c604  e8cbca2e00           call 0x7190d4
// 0042c609  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0042c60d  5e                   pop esi
// 0042c60e  64890d00000000       mov dword ptr fs:[0], ecx
// 0042c615  83c410               add esp, 0x10
// 0042c618  c3                   ret 
// copied from an identical function in another client (function ??1CBrowserFrameWnd@ns_ROCX000026@@UAE@XZ)

namespace ns_ROCX000026 {
struct Object
{
    void release();
};

struct Base
{
    virtual ~Base();
    char padding[0xe4];
};

struct CBrowserFrameWnd : Base
{
    Object* object;
    ~CBrowserFrameWnd();
};

CBrowserFrameWnd::~CBrowserFrameWnd()
{
    if (object)
        object->release();
}
}
