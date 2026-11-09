// roc 2012-06 009ed4d0  unit: CXTPToolTipContextToolTip  size: 35 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009ed4d0
//
// 009ed4d0  8b442404             mov eax, dword ptr [esp + 4]
// 009ed4d4  56                   push esi
// 009ed4d5  6a3c                 push 0x3c
// 009ed4d7  50                   push eax
// 009ed4d8  8bf1                 mov esi, ecx
// 009ed4da  6a3c                 push 0x3c
// 009ed4dc  56                   push esi
// 009ed4dd  c7463c00000000       mov dword ptr [esi + 0x3c], 0
// 009ed4e4  ff15fc29b200         call dword ptr [0xb229fc]
// 009ed4ea  83c410               add esp, 0x10
// 009ed4ed  8bc6                 mov eax, esi
// 009ed4ef  5e                   pop esi
// 009ed4f0  c20400               ret 4
// copied from an identical function in another client (function ?construct@CXTPToolTipContext_CRichEditToolTip@ns_ROCX000002@@QAEPAXPAX@Z)

namespace ns_ROCX000002 {
extern "C" int (__cdecl *memcpy_s)(void*, unsigned int, const void*, unsigned int);

struct CXTPToolTipContext_CRichEditToolTip
{
    char pad[0x3c];
    int field_3c;
    void* construct(void* src);
};

void* CXTPToolTipContext_CRichEditToolTip::construct(void* src)
{
    field_3c = 0;
    memcpy_s(this, 0x3c, src, 0x3c);
    return this;
}
}
