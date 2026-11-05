// roc 2012-06 004c3170  unit: RBX::VRbxTextureProxy::?$sp_counted_impl_p  size: 17 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 004c3170
//
// 004c3170  8b490c               mov ecx, dword ptr [ecx + 0xc]
// 004c3173  85c9                 test ecx, ecx
// 004c3175  7409                 je 0x4c3180
// 004c3177  8b01                 mov eax, dword ptr [ecx]
// 004c3179  8b5010               mov edx, dword ptr [eax + 0x10]
// 004c317c  6a01                 push 1
// 004c317e  ffd2                 call edx
// 004c3180  c3                   ret 
// copied from an identical function in another client (function ?f@S@ns_ROCX00000e@@QAEXXZ)

namespace ns_ROCX00000e {
struct S
{
    void f();
};

void S::f()
{
    struct VTable
    {
        void *unused[4];
        void (__thiscall *release)(void *, int);
    };

    void *p = *(void **)((char *)this + 0x0c);
    if (p != 0)
        ((VTable *)*(void **)p)->release(p, 1);
}
}
