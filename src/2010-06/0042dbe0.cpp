// from server: 100% by Yeetserama
// roc 2010-06 0042dbe0  unit: CBrowserFrameWnd  size: 89 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0042dbe0
//
// 0042dbe0  6aff                 push -1
// 0042dbe2  6818039800           push 0x980318
// 0042dbe7  64a100000000         mov eax, dword ptr fs:[0]
// 0042dbed  50                   push eax
// 0042dbee  64892500000000       mov dword ptr fs:[0], esp
// 0042dbf5  51                   push ecx
// 0042dbf6  56                   push esi
// 0042dbf7  8bf1                 mov esi, ecx
// 0042dbf9  89742404             mov dword ptr [esp + 4], esi
// 0042dbfd  c706445fa000         mov dword ptr [esi], 0xa05f44
// 0042dc03  8b8ee8000000         mov ecx, dword ptr [esi + 0xe8]
// 0042dc09  c744241000000000     mov dword ptr [esp + 0x10], 0
// 0042dc11  85c9                 test ecx, ecx
// 0042dc13  7405                 je 0x42dc1a
// 0042dc15  e802a33700           call 0x7a7f1c
// 0042dc1a  8bce                 mov ecx, esi
// 0042dc1c  c7442410ffffffff     mov dword ptr [esp + 0x10], 0xffffffff
// 0042dc24  e813a43700           call 0x7a803c
// 0042dc29  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0042dc2d  5e                   pop esi
// 0042dc2e  64890d00000000       mov dword ptr fs:[0], ecx
// 0042dc35  83c410               add esp, 0x10
// 0042dc38  c3                   ret 
// copied from an identical function in another client (function ??1CBrowserFrameWnd@ns_ROCX000003@@UAE@XZ)

namespace ns_ROCX000003 {
// from server: 100% by king_originala
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
