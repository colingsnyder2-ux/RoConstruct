// from server: 100% by Yeetserama
// roc 2010-06 00443670  unit: RBXImage  size: 78 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00443670
//
// 00443670  56                   push esi
// 00443671  8bf1                 mov esi, ecx
// 00443673  8b4e04               mov ecx, dword ptr [esi + 4]
// 00443676  33c0                 xor eax, eax
// 00443678  c70684aba000         mov dword ptr [esi], 0xa0ab84
// 0044367e  3bc8                 cmp ecx, eax
// 00443680  7426                 je 0x4436a8
// 00443682  51                   push ecx
// 00443683  894604               mov dword ptr [esi + 4], eax
// 00443686  894608               mov dword ptr [esi + 8], eax
// 00443689  89460c               mov dword ptr [esi + 0xc], eax
// 0044368c  894610               mov dword ptr [esi + 0x10], eax
// 0044368f  894618               mov dword ptr [esi + 0x18], eax
// 00443692  894614               mov dword ptr [esi + 0x14], eax
// 00443695  c74620ffffffff       mov dword ptr [esi + 0x20], 0xffffffff
// 0044369c  88461d               mov byte ptr [esi + 0x1d], al
// 0044369f  88461c               mov byte ptr [esi + 0x1c], al
// 004436a2  ff15d4a09e00         call dword ptr [0x9ea0d4]
// 004436a8  f644240801           test byte ptr [esp + 8], 1
// 004436ad  7409                 je 0x4436b8
// 004436af  56                   push esi
// 004436b0  e8e5423600           call 0x7a799a
// 004436b5  83c404               add esp, 4
// 004436b8  8bc6                 mov eax, esi
// 004436ba  5e                   pop esi
// 004436bb  c20400               ret 4
// copied from an identical function in another client (function ?destroy@RBXImage@ns_ROCX000003@@QAEPAXI@Z)

namespace ns_ROCX000003 {
// from server: 100% by king_originala
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
