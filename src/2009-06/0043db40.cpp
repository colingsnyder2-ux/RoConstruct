// from server: 100% by EspClaude
// roc 2009-06 0043db40  unit: RBXImage  size: 78 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0043db40
//
// 0043db40  56                   push esi
// 0043db41  8bf1                 mov esi, ecx
// 0043db43  8b4e04               mov ecx, dword ptr [esi + 4]
// 0043db46  33c0                 xor eax, eax
// 0043db48  c706ec5d8b00         mov dword ptr [esi], 0x8b5dec
// 0043db4e  3bc8                 cmp ecx, eax
// 0043db50  7426                 je 0x43db78
// 0043db52  51                   push ecx
// 0043db53  894604               mov dword ptr [esi + 4], eax
// 0043db56  894608               mov dword ptr [esi + 8], eax
// 0043db59  89460c               mov dword ptr [esi + 0xc], eax
// 0043db5c  894610               mov dword ptr [esi + 0x10], eax
// 0043db5f  894618               mov dword ptr [esi + 0x18], eax
// 0043db62  894614               mov dword ptr [esi + 0x14], eax
// 0043db65  c74620ffffffff       mov dword ptr [esi + 0x20], 0xffffffff
// 0043db6c  88461d               mov byte ptr [esi + 0x1d], al
// 0043db6f  88461c               mov byte ptr [esi + 0x1c], al
// 0043db72  ff1560e18900         call dword ptr [0x89e160]
// 0043db78  f644240801           test byte ptr [esp + 8], 1
// 0043db7d  7409                 je 0x43db88
// 0043db7f  56                   push esi
// 0043db80  e8adae2d00           call 0x718a32
// 0043db85  83c404               add esp, 4
// 0043db88  8bc6                 mov eax, esi
// 0043db8a  5e                   pop esi
// 0043db8b  c20400               ret 4
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
