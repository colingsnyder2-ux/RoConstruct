// from server: 100% by Yeetserama
// roc 2010-06 00439dc0  unit: HVCXTPPropertyGridItemEnum::?$XItem  size: 96 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00439dc0
//
// 00439dc0  56                   push esi
// 00439dc1  8bf1                 mov esi, ecx
// 00439dc3  8b8624010000         mov eax, dword ptr [esi + 0x124]
// 00439dc9  85c0                 test eax, eax
// 00439dcb  7409                 je 0x439dd6
// 00439dcd  50                   push eax
// 00439dce  e8c7db3600           call 0x7a799a
// 00439dd3  83c404               add esp, 4
// 00439dd6  8b8618010000         mov eax, dword ptr [esi + 0x118]
// 00439ddc  50                   push eax
// 00439ddd  c7862401000000000000 mov dword ptr [esi + 0x124], 0
// 00439de7  c7862801000000000000 mov dword ptr [esi + 0x128], 0
// 00439df1  c7862c01000000000000 mov dword ptr [esi + 0x12c], 0
// 00439dfb  e89adb3600           call 0x7a799a
// 00439e00  83c404               add esp, 4
// 00439e03  8bce                 mov ecx, esi
// 00439e05  e836523e00           call 0x81f040
// 00439e0a  f644240801           test byte ptr [esp + 8], 1
// 00439e0f  7409                 je 0x439e1a
// 00439e11  56                   push esi
// 00439e12  e883db3600           call 0x7a799a
// 00439e17  83c404               add esp, 4
// 00439e1a  8bc6                 mov eax, esi
// 00439e1c  5e                   pop esi
// 00439e1d  c20400               ret 4
// copied from an identical function in another client (function ?destroy@S@ns_ROCX000001@@QAEPAU12@I@Z)

namespace ns_ROCX000001 {
// from server: 100% by king_originala
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
