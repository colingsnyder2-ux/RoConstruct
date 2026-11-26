// from server: 100% by Xemicl
// roc 2012-06 00437630  unit: VCMDIFrameWnd::?$CXTPFrameWndBase  size: 89 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00437630
//
// 00437630  6aff                 push -1
// 00437632  6868d3a900           push 0xa9d368
// 00437637  64a100000000         mov eax, dword ptr fs:[0]
// 0043763d  50                   push eax
// 0043763e  64892500000000       mov dword ptr fs:[0], esp
// 00437645  51                   push ecx
// 00437646  56                   push esi
// 00437647  8bf1                 mov esi, ecx
// 00437649  89742404             mov dword ptr [esp + 4], esi
// 0043764d  c70694feb400         mov dword ptr [esi], 0xb4fe94
// 00437653  8b8eec000000         mov ecx, dword ptr [esi + 0xec]
// 00437659  c744241000000000     mov dword ptr [esp + 0x10], 0
// 00437661  85c9                 test ecx, ecx
// 00437663  7405                 je 0x43766a
// 00437665  e820b05400           call 0x98268a
// 0043766a  8bce                 mov ecx, esi
// 0043766c  c7442410ffffffff     mov dword ptr [esp + 0x10], 0xffffffff
// 00437674  e801b15400           call 0x98277a
// 00437679  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0043767d  5e                   pop esi
// 0043767e  64890d00000000       mov dword ptr fs:[0], ecx
// 00437685  83c410               add esp, 0x10
// 00437688  c3                   ret 
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