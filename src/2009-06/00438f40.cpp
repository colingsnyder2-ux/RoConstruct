// from server: 100% by EspClaude
// roc 2009-06 00438f40  unit: MVCXTPPropertyGridItem::?$XItem  size: 96 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00438f40
//
// 00438f40  56                   push esi
// 00438f41  8bf1                 mov esi, ecx
// 00438f43  8b861c010000         mov eax, dword ptr [esi + 0x11c]
// 00438f49  85c0                 test eax, eax
// 00438f4b  7409                 je 0x438f56
// 00438f4d  50                   push eax
// 00438f4e  e8dffa2d00           call 0x718a32
// 00438f53  83c404               add esp, 4
// 00438f56  8b8610010000         mov eax, dword ptr [esi + 0x110]
// 00438f5c  50                   push eax
// 00438f5d  c7861c01000000000000 mov dword ptr [esi + 0x11c], 0
// 00438f67  c7862001000000000000 mov dword ptr [esi + 0x120], 0
// 00438f71  c7862401000000000000 mov dword ptr [esi + 0x124], 0
// 00438f7b  e8b2fa2d00           call 0x718a32
// 00438f80  83c404               add esp, 4
// 00438f83  8bce                 mov ecx, esi
// 00438f85  e8762e3500           call 0x78be00
// 00438f8a  f644240801           test byte ptr [esp + 8], 1
// 00438f8f  7409                 je 0x438f9a
// 00438f91  56                   push esi
// 00438f92  e89bfa2d00           call 0x718a32
// 00438f97  83c404               add esp, 4
// 00438f9a  8bc6                 mov eax, esi
// 00438f9c  5e                   pop esi
// 00438f9d  c20400               ret 4
// copied from an identical function in another client (function ?destroy@S@ns_ROCX000011@@QAEPAU12@I@Z)

namespace ns_ROCX000011 {
extern "C" void __cdecl deallocate(void*);

struct S
{
    unsigned char padding[0x110];
    void* first;
    unsigned char gap[8];
    void* buffer;
    unsigned int size;
    unsigned int capacity;

    void cleanup();
    S* destroy(unsigned int flags);
};

S* S::destroy(unsigned int flags)
{
    if (buffer)
        deallocate(buffer);

    buffer = 0;
    size = 0;
    capacity = 0;
    deallocate(first);

    cleanup();

    if (flags & 1)
        deallocate(this);

    return this;
}
}
