// from server: 100% by Yeetserama
// roc 2010-06 00438110  unit: G3D::VColor3::?$XItem  size: 96 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00438110
//
// 00438110  56                   push esi
// 00438111  8bf1                 mov esi, ecx
// 00438113  8b8628010000         mov eax, dword ptr [esi + 0x128]
// 00438119  85c0                 test eax, eax
// 0043811b  7409                 je 0x438126
// 0043811d  50                   push eax
// 0043811e  e877f83600           call 0x7a799a
// 00438123  83c404               add esp, 4
// 00438126  8b861c010000         mov eax, dword ptr [esi + 0x11c]
// 0043812c  50                   push eax
// 0043812d  c7862801000000000000 mov dword ptr [esi + 0x128], 0
// 00438137  c7862c01000000000000 mov dword ptr [esi + 0x12c], 0
// 00438141  c7863001000000000000 mov dword ptr [esi + 0x130], 0
// 0043814b  e84af83600           call 0x7a799a
// 00438150  83c404               add esp, 4
// 00438153  8bce                 mov ecx, esi
// 00438155  e8a62d3e00           call 0x81af00
// 0043815a  f644240801           test byte ptr [esp + 8], 1
// 0043815f  7409                 je 0x43816a
// 00438161  56                   push esi
// 00438162  e833f83600           call 0x7a799a
// 00438167  83c404               add esp, 4
// 0043816a  8bc6                 mov eax, esi
// 0043816c  5e                   pop esi
// 0043816d  c20400               ret 4
// copied from an identical function in another client (function ?destroy@S@ns_ROCX000000@@QAEPAU12@I@Z)

namespace ns_ROCX000000 {
// from server: 100% by king_originala
extern "C" void __cdecl release(void*);

struct S {
    char pad000[0x11c];
    void* field11c;
    char pad120[8];
    void* field128;
    unsigned int field12c;
    unsigned int field130;

    void baseDestroy();
    S* destroy(unsigned int flags);
};

S* S::destroy(unsigned int flags) {
    if (field128)
        release(field128);

    field128 = 0;
    field12c = 0;
    field130 = 0;
    release(field11c);

    baseDestroy();

    if (flags & 1)
        release(this);

    return this;
}
}
