// from server: 100% by EspClaude
// roc 2009-06 005e05c0  unit: std::D::DU?$char_traits::?$basic_istringstream  size: 34 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 005e05c0
//
// 005e05c0  56                   push esi
// 005e05c1  8d71b0               lea esi, [ecx - 0x50]
// 005e05c4  8bce                 mov ecx, esi
// 005e05c6  ff15a0e48900         call dword ptr [0x89e4a0]
// 005e05cc  f644240801           test byte ptr [esp + 8], 1
// 005e05d1  7409                 je 0x5e05dc
// 005e05d3  56                   push esi
// 005e05d4  e859841300           call 0x718a32
// 005e05d9  83c404               add esp, 4
// 005e05dc  8bc6                 mov eax, esi
// 005e05de  5e                   pop esi
// 005e05df  c20400               ret 4
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
    void *base = reinterpret_cast<char *>(this) - 0x50;
    destroyStream(base);
    if (flags & 1)
        deallocate(base);
    return base;
}
}
