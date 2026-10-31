// from server: 100% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 00407ef0  unit: VCApp::?$CComObject  size: 87 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00407ef0
//
// 00407ef0  56                   push esi
// 00407ef1  8bf1                 mov esi, ecx
// 00407ef3  c7068cb58000         mov dword ptr [esi], 0x80b58c
// 00407ef9  c7460474b58000       mov dword ptr [esi + 4], 0x80b574
// 00407f00  c7460c58b58000       mov dword ptr [esi + 0xc], 0x80b558
// 00407f07  c746140cb58000       mov dword ptr [esi + 0x14], 0x80b50c
// 00407f0e  c74618010000c0       mov dword ptr [esi + 0x18], 0xc0000001
// 00407f15  8b0d68c29600         mov ecx, dword ptr [0x96c268]
// 00407f1b  8b01                 mov eax, dword ptr [ecx]
// 00407f1d  8b5008               mov edx, dword ptr [eax + 8]
// 00407f20  ffd2                 call edx
// 00407f22  8b4610               mov eax, dword ptr [esi + 0x10]
// 00407f25  85c0                 test eax, eax
// 00407f27  7408                 je 0x407f31
// 00407f29  8b08                 mov ecx, dword ptr [eax]
// 00407f2b  8b5108               mov edx, dword ptr [ecx + 8]
// 00407f2e  50                   push eax
// 00407f2f  ffd2                 call edx
// 00407f31  f644240801           test byte ptr [esp + 8], 1
// 00407f36  7409                 je 0x407f41
// 00407f38  56                   push esi
// 00407f39  e83c872900           call 0x6a067a
// 00407f3e  83c404               add esp, 4
// 00407f41  8bc6                 mov eax, esi
// 00407f43  5e                   pop esi
// 00407f44  c20400               ret 4

struct Manager {
    virtual void slot0() = 0;
    virtual void slot1() = 0;
    virtual void release() = 0;
};

struct Interface {
    virtual void __stdcall slot0() = 0;
    virtual void __stdcall slot1() = 0;
    virtual unsigned long __stdcall release() = 0;
};

void __cdecl operator delete(void *);

struct S {
    unsigned long table0;
    unsigned long table4;
    unsigned long field8;
    unsigned long table12;
    Interface *field16;
    unsigned long table20;
    unsigned long field24;

    S *destroy(unsigned int flags);
};

S *S::destroy(unsigned int flags)
{
    table0 = 0x0080B58C;
    table4 = 0x0080B574;
    table12 = 0x0080B558;
    table20 = 0x0080B50C;
    field24 = 0xC0000001;

    (*(Manager **)0x0096C268)->release();

    if (field16)
        field16->release();

    if (flags & 1)
        operator delete(this);

    return this;
}
