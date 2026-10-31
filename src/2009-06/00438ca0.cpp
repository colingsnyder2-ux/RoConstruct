// from server: 100% by EspClaude
// roc 2009-06 00438ca0  unit: HVCXTPPropertyGridItemEnum::?$XItem  size: 96 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00438ca0
//
// 00438ca0  56                   push esi
// 00438ca1  8bf1                 mov esi, ecx
// 00438ca3  8b8624010000         mov eax, dword ptr [esi + 0x124]
// 00438ca9  85c0                 test eax, eax
// 00438cab  7409                 je 0x438cb6
// 00438cad  50                   push eax
// 00438cae  e87ffd2d00           call 0x718a32
// 00438cb3  83c404               add esp, 4
// 00438cb6  8b8618010000         mov eax, dword ptr [esi + 0x118]
// 00438cbc  50                   push eax
// 00438cbd  c7862401000000000000 mov dword ptr [esi + 0x124], 0
// 00438cc7  c7862801000000000000 mov dword ptr [esi + 0x128], 0
// 00438cd1  c7862c01000000000000 mov dword ptr [esi + 0x12c], 0
// 00438cdb  e852fd2d00           call 0x718a32
// 00438ce0  83c404               add esp, 4
// 00438ce3  8bce                 mov ecx, esi
// 00438ce5  e856733500           call 0x790040
// 00438cea  f644240801           test byte ptr [esp + 8], 1
// 00438cef  7409                 je 0x438cfa
// 00438cf1  56                   push esi
// 00438cf2  e83bfd2d00           call 0x718a32
// 00438cf7  83c404               add esp, 4
// 00438cfa  8bc6                 mov eax, esi
// 00438cfc  5e                   pop esi
// 00438cfd  c20400               ret 4
// copied from an identical function in another client (function ?destroy@S@ns_ROCX000004@@QAEPAU12@I@Z)

namespace ns_ROCX000004 {
extern "C" void __cdecl release(void *);

struct S {
    unsigned char padding0[0x118];
    void *buffer;
    unsigned char padding1[8];
    void *first;
    void *last;
    void *limit;

    void cleanup();
    S *destroy(unsigned int flags);
};

S *S::destroy(unsigned int flags)
{
    if (first)
        release(first);

    first = 0;
    last = 0;
    limit = 0;

    release(buffer);
    cleanup();

    if (flags & 1)
        release(this);

    return this;
}
}
