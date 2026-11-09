// from server: 100% by EspClaude
// roc 2009-06 00435580  unit: G3D::VColor3::?$XItem  size: 96 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00435580
//
// 00435580  56                   push esi
// 00435581  8bf1                 mov esi, ecx
// 00435583  8b8628010000         mov eax, dword ptr [esi + 0x128]
// 00435589  85c0                 test eax, eax
// 0043558b  7409                 je 0x435596
// 0043558d  50                   push eax
// 0043558e  e89f342e00           call 0x718a32
// 00435593  83c404               add esp, 4
// 00435596  8b861c010000         mov eax, dword ptr [esi + 0x11c]
// 0043559c  50                   push eax
// 0043559d  c7862801000000000000 mov dword ptr [esi + 0x128], 0
// 004355a7  c7862c01000000000000 mov dword ptr [esi + 0x12c], 0
// 004355b1  c7863001000000000000 mov dword ptr [esi + 0x130], 0
// 004355bb  e872342e00           call 0x718a32
// 004355c0  83c404               add esp, 4
// 004355c3  8bce                 mov ecx, esi
// 004355c5  e876693500           call 0x78bf40
// 004355ca  f644240801           test byte ptr [esp + 8], 1
// 004355cf  7409                 je 0x4355da
// 004355d1  56                   push esi
// 004355d2  e85b342e00           call 0x718a32
// 004355d7  83c404               add esp, 4
// 004355da  8bc6                 mov eax, esi
// 004355dc  5e                   pop esi
// 004355dd  c20400               ret 4
// copied from an identical function in another client (function ?destroy@S@ns_ROCX000007@@QAEPAU12@I@Z)

namespace ns_ROCX000007 {
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
