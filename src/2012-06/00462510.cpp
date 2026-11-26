// from server: 100% by Xemicl
// roc 2012-06 00462510  unit: RBXImage  size: 78 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00462510
//
// 00462510  56                   push esi
// 00462511  8bf1                 mov esi, ecx
// 00462513  8b4e04               mov ecx, dword ptr [esi + 4]
// 00462516  33c0                 xor eax, eax
// 00462518  c7064c75b500         mov dword ptr [esi], 0xb5754c
// 0046251e  3bc8                 cmp ecx, eax
// 00462520  7426                 je 0x462548
// 00462522  51                   push ecx
// 00462523  894604               mov dword ptr [esi + 4], eax
// 00462526  894608               mov dword ptr [esi + 8], eax
// 00462529  89460c               mov dword ptr [esi + 0xc], eax
// 0046252c  894610               mov dword ptr [esi + 0x10], eax
// 0046252f  894618               mov dword ptr [esi + 0x18], eax
// 00462532  894614               mov dword ptr [esi + 0x14], eax
// 00462535  c74620ffffffff       mov dword ptr [esi + 0x20], 0xffffffff
// 0046253c  88461d               mov byte ptr [esi + 0x1d], al
// 0046253f  88461c               mov byte ptr [esi + 0x1c], al
// 00462542  ff157021b200         call dword ptr [0xb22170]
// 00462548  f644240801           test byte ptr [esp + 8], 1
// 0046254d  7409                 je 0x462558
// 0046254f  56                   push esi
// 00462550  e8bffb5100           call 0x982114
// 00462555  83c404               add esp, 4
// 00462558  8bc6                 mov eax, esi
// 0046255a  5e                   pop esi
// 0046255b  c20400               ret 4
// copied from an identical function in another client (function ?destroy@RBXImage@ns_ROCX00000a@@QAEPAXI@Z)

namespace ns_ROCX00000a {
struct RBXImage {
    void* vtable;
    void* field4;
    int field8;
    int fieldC;
    int field10;
    int field14;
    int field18;
    unsigned char field1C;
    unsigned char field1D;
    int field20;
    void* destroy(unsigned int flags);
};

extern void* image_vtable[];
extern "C" int (__stdcall *DeleteObject)(void*);
extern "C" void __cdecl operator_delete(void*);

void* RBXImage::destroy(unsigned int flags) {
    void* p = this->field4;
    this->vtable = image_vtable;
    if (p != 0) {
        this->field4 = 0;
        this->field8 = 0;
        this->fieldC = 0;
        this->field10 = 0;
        this->field18 = 0;
        this->field14 = 0;
        this->field20 = -1;
        this->field1D = 0;
        this->field1C = 0;
        DeleteObject(p);
    }
    if (flags & 1) {
        operator_delete(this);
    }
    return this;
}
}