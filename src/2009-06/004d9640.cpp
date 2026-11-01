// from server: 100% by EspClaude
// from server: 100% by tester
// roc 2008-06 004a50c0  unit: RBX::VHint::?$FactoryProduct::Creator  size: 87 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004a50c0
//
// 004a50c0  56                   push esi
// 004a50c1  57                   push edi
// 004a50c2  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 004a50c6  81ff00010000         cmp edi, 0x100
// 004a50cc  8bf1                 mov esi, ecx
// 004a50ce  c70600000000         mov dword ptr [esi], 0
// 004a50d4  c7460800000000       mov dword ptr [esi + 8], 0
// 004a50db  7f18                 jg 0x4a50f5
// 004a50dd  8d4611               lea eax, [esi + 0x11]
// 004a50e0  89460c               mov dword ptr [esi + 0xc], eax
// 004a50e3  5f                   pop edi
// 004a50e4  c7460400080000       mov dword ptr [esi + 4], 0x800
// 004a50eb  8bc6                 mov eax, esi
// 004a50ed  c6461001             mov byte ptr [esi + 0x10], 1
// 004a50f1  5e                   pop esi
// 004a50f2  c20400               ret 4
// 004a50f5  57                   push edi
// 004a50f6  ff15b0288000         call dword ptr [0x8028b0]
// 004a50fc  83c404               add esp, 4
// 004a50ff  8d0cfd00000000       lea ecx, [edi*8]
// 004a5106  89460c               mov dword ptr [esi + 0xc], eax
// 004a5109  5f                   pop edi
// 004a510a  894e04               mov dword ptr [esi + 4], ecx
// 004a510d  8bc6                 mov eax, esi
// 004a510f  c6461001             mov byte ptr [esi + 0x10], 1
// 004a5113  5e                   pop esi
// 004a5114  c20400               ret 4

extern "C" void* (__cdecl *malloc)(unsigned int size);

struct BoundFuncDesc {
    void* field0;
    unsigned int field4;
    void* field8;
    void* fieldC;
    unsigned char field10;
    char field11;
    void* construct(unsigned int size);
};

void* BoundFuncDesc::construct(unsigned int size) {
    field0 = 0;
    field8 = 0;
    if (size <= 0x400) {
        fieldC = (char*)this + 0x11;
        field4 = 0x2000;
    } else {
        fieldC = malloc(size);
        field4 = size * 8;
    }
    field10 = 1;
    return this;
}
