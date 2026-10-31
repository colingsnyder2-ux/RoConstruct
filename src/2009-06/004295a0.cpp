// from server: 100% by EspClaude
// roc 2009-06 004295a0  unit: VCMDIFrameWnd::?$CXTPFrameWndBase  size: 89 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004295a0
//
// 004295a0  6aff                 push -1
// 004295a2  68c8ef8400           push 0x84efc8
// 004295a7  64a100000000         mov eax, dword ptr fs:[0]
// 004295ad  50                   push eax
// 004295ae  64892500000000       mov dword ptr fs:[0], esp
// 004295b5  51                   push ecx
// 004295b6  56                   push esi
// 004295b7  8bf1                 mov esi, ecx
// 004295b9  89742404             mov dword ptr [esp + 4], esi
// 004295bd  c7064c148b00         mov dword ptr [esi], 0x8b144c
// 004295c3  8b8eec000000         mov ecx, dword ptr [esi + 0xec]
// 004295c9  c744241000000000     mov dword ptr [esp + 0x10], 0
// 004295d1  85c9                 test ecx, ecx
// 004295d3  7405                 je 0x4295da
// 004295d5  e8cef92e00           call 0x718fa8
// 004295da  8bce                 mov ecx, esi
// 004295dc  c7442410ffffffff     mov dword ptr [esp + 0x10], 0xffffffff
// 004295e4  e8ebfa2e00           call 0x7190d4
// 004295e9  8b4c2408             mov ecx, dword ptr [esp + 8]
// 004295ed  5e                   pop esi
// 004295ee  64890d00000000       mov dword ptr fs:[0], ecx
// 004295f5  83c410               add esp, 0x10
// 004295f8  c3                   ret 
// copied from an identical function in another client (function ??1Frame@ns_ROCX000001@@UAE@XZ)

namespace ns_ROCX000001 {
struct Resource {
    void release();
};

struct Base {
    virtual ~Base();
    char padding[232];
};

struct Frame : Base {
    Resource* resource;
    virtual ~Frame();
};

Frame::~Frame()
{
    if (resource)
        resource->release();
}
}
