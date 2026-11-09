// roc 2012-06 007205c0  unit: RBX::VMouseCommand::?$sp_counted_impl_p  size: 17 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 007205c0
//
// 007205c0  8b490c               mov ecx, dword ptr [ecx + 0xc]
// 007205c3  85c9                 test ecx, ecx
// 007205c5  7409                 je 0x7205d0
// 007205c7  8b01                 mov eax, dword ptr [ecx]
// 007205c9  8b5040               mov edx, dword ptr [eax + 0x40]
// 007205cc  6a01                 push 1
// 007205ce  ffd2                 call edx
// 007205d0  c3                   ret 
// copied from an identical function in another client (function ?f@S@ns_ROCX000011@@QAEXXZ)

namespace ns_ROCX000011 {
struct S
{
    char pad[12];
    void* field;
    void f();
};

void S::f()
{
    void* p = field;
    if (p)
    {
        typedef void (__thiscall *Fn)(void*, int);
        Fn fn = *(Fn *)((char *)*(void **)p + 0x40);
        fn(p, 1);
    }
}
}
