// from server: 100% by Xemicl
// roc 2012-06 00448ed0  unit: CBrowserFrameWnd  size: 89 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00448ed0
//
// 00448ed0  6aff                 push -1
// 00448ed2  68b8e1a900           push 0xa9e1b8
// 00448ed7  64a100000000         mov eax, dword ptr fs:[0]
// 00448edd  50                   push eax
// 00448ede  64892500000000       mov dword ptr fs:[0], esp
// 00448ee5  51                   push ecx
// 00448ee6  56                   push esi
// 00448ee7  8bf1                 mov esi, ecx
// 00448ee9  89742404             mov dword ptr [esp + 4], esi
// 00448eed  c7062c1eb500         mov dword ptr [esi], 0xb51e2c
// 00448ef3  8b8ee8000000         mov ecx, dword ptr [esi + 0xe8]
// 00448ef9  c744241000000000     mov dword ptr [esp + 0x10], 0
// 00448f01  85c9                 test ecx, ecx
// 00448f03  7405                 je 0x448f0a
// 00448f05  e880975300           call 0x98268a
// 00448f0a  8bce                 mov ecx, esi
// 00448f0c  c7442410ffffffff     mov dword ptr [esp + 0x10], 0xffffffff
// 00448f14  e861985300           call 0x98277a
// 00448f19  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00448f1d  5e                   pop esi
// 00448f1e  64890d00000000       mov dword ptr fs:[0], ecx
// 00448f25  83c410               add esp, 0x10
// 00448f28  c3                   ret 
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