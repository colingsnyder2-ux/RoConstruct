// from server: 100% by Xemicl
// from server: 100% by Xemicl
// roc 2012-06 006a1e30  unit: std::D::DU?$char_traits::?$basic_istringstream  size: 34 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 006a1e30
//
// 006a1e30  56                   push esi
// 006a1e31  8d71b0               lea esi, [ecx - 0x50]
// 006a1e34  8bce                 mov ecx, esi
// 006a1e36  ff157026b200         call dword ptr [0xb22670]
// 006a1e3c  f644240801           test byte ptr [esp + 8], 1
// 006a1e41  7409                 je 0x6a1e4c
// 006a1e43  56                   push esi
// 006a1e44  e8cb022e00           call 0x982114
// 006a1e49  83c404               add esp, 4
// 006a1e4c  8bc6                 mov eax, esi
// 006a1e4e  5e                   pop esi
// 006a1e4f  c20400               ret 4
// copied from an identical function in another client (function ?destroy@S@ns_ROCX000010@@QAEPAXI@Z)

namespace ns_ROCX000010 {
typedef void (__thiscall *DestroyFn)(void *);
extern DestroyFn destroyStream;
extern "C" void __cdecl deallocate(void *);

struct S {
    void *destroy(unsigned int flags);
};

void *S::destroy(unsigned int flags)
{
    void *base = reinterpret_cast<char *>(this) - 0x54;
    destroyStream(base);
    if (flags & 1)
        deallocate(base);
    return base;
}
}