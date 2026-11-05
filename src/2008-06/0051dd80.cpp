// from server: 100% by tester
// roc 2008-06 0051dd80  unit: seg_00510000  size: 70 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0051dd80
//
// 0051dd80  56                   push esi
// 0051dd81  8b742408             mov esi, dword ptr [esp + 8]
// 0051dd85  f6861c01000020       test byte ptr [esi + 0x11c], 0x20
// 0051dd8c  7411                 je 0x51dd9f
// 0051dd8e  8b466c               mov eax, dword ptr [esi + 0x6c]
// 0051dd91  2500030000           and eax, 0x300
// 0051dd96  3d00030000           cmp eax, 0x300
// 0051dd9b  750b                 jne 0x51dda8
// 0051dd9d  5e                   pop esi
// 0051dd9e  c3                   ret 
// 0051dd9f  f7466c00080000       test dword ptr [esi + 0x6c], 0x800
// 0051dda6  751c                 jne 0x51ddc4
// 0051dda8  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0051ddac  8b54240c             mov edx, dword ptr [esp + 0xc]
// 0051ddb0  8b8610010000         mov eax, dword ptr [esi + 0x110]
// 0051ddb6  51                   push ecx
// 0051ddb7  52                   push edx
// 0051ddb8  50                   push eax
// 0051ddb9  e852a32800           call 0x7a8110
// 0051ddbe  898610010000         mov dword ptr [esi + 0x110], eax
// 0051ddc4  5e                   pop esi
// 0051ddc5  c3                   ret 
// copied from an identical function in another client (function ?G3D_DialogTemplate_method@ns_ROCX000003@@YAXPAUG3D_DialogTemplate@1@PAX11@Z)

namespace ns_ROCX000003 {
struct G3D_DialogTemplate {
    char pad[0x6c];
    unsigned int flags;
    char pad2[0x110 - 0x70];
    void* field_110;
    char pad3[0x11c - 0x114];
    unsigned char byte_11c;
};

extern "C" void* __stdcall sub_0072d160(void*, void*, void*);

void G3D_DialogTemplate_method(G3D_DialogTemplate* self, void* a, void* b, void* c)
{
    if ((self->byte_11c & 0x20) != 0) {
        unsigned int v = self->flags & 0x300;
        if (v != 0x300)
            goto do_call;
        return;
    } else {
        if ((self->flags & 0x800) != 0)
            return;
    }
do_call:
    self->field_110 = sub_0072d160(self->field_110, a, b);
}
}
