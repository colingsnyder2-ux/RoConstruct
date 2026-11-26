// from server: 100% by Xemicl
// roc 2012-06 0063de90  unit: seg_00630000  size: 70 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0063de90
//
// 0063de90  56                   push esi
// 0063de91  8b742408             mov esi, dword ptr [esp + 8]
// 0063de95  f6861c01000020       test byte ptr [esi + 0x11c], 0x20
// 0063de9c  7411                 je 0x63deaf
// 0063de9e  8b466c               mov eax, dword ptr [esi + 0x6c]
// 0063dea1  2500030000           and eax, 0x300
// 0063dea6  3d00030000           cmp eax, 0x300
// 0063deab  750b                 jne 0x63deb8
// 0063dead  5e                   pop esi
// 0063deae  c3                   ret 
// 0063deaf  f7466c00080000       test dword ptr [esi + 0x6c], 0x800
// 0063deb6  751c                 jne 0x63ded4
// 0063deb8  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0063debc  8b54240c             mov edx, dword ptr [esp + 0xc]
// 0063dec0  8b8610010000         mov eax, dword ptr [esi + 0x110]
// 0063dec6  51                   push ecx
// 0063dec7  52                   push edx
// 0063dec8  50                   push eax
// 0063dec9  e892090100           call 0x64e860
// 0063dece  898610010000         mov dword ptr [esi + 0x110], eax
// 0063ded4  5e                   pop esi
// 0063ded5  c3                   ret 
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