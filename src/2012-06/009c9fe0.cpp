// roc 2012-06 009c9fe0  unit: ATL::CRegObject  size: 47 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009c9fe0
//
// 009c9fe0  8b442408             mov eax, dword ptr [esp + 8]
// 009c9fe4  85c0                 test eax, eax
// 009c9fe6  7512                 jne 0x9c9ffa
// 009c9fe8  56                   push esi
// 009c9fe9  8b742408             mov esi, dword ptr [esp + 8]
// 009c9fed  50                   push eax
// 009c9fee  56                   push esi
// 009c9fef  e8acffffff           call 0x9c9fa0
// 009c9ff4  8bc6                 mov eax, esi
// 009c9ff6  5e                   pop esi
// 009c9ff7  c20800               ret 8
// 009c9ffa  8b4020               mov eax, dword ptr [eax + 0x20]
// 009c9ffd  56                   push esi
// 009c9ffe  8b742408             mov esi, dword ptr [esp + 8]
// 009ca002  50                   push eax
// 009ca003  56                   push esi
// 009ca004  e897ffffff           call 0x9c9fa0
// 009ca009  8bc6                 mov eax, esi
// 009ca00b  5e                   pop esi
// 009ca00c  c20800               ret 8
// copied from an identical function in another client (function ?fn_ROCX000017@ns_ROCX000017@@YGPAXPAXPAUCPropertyGridItemBrickColor@1@@Z)

namespace ns_ROCX000017 {
struct CPropertyGridItemBrickColor
{
    char pad[0x20];
    void* field_20;
};

void __stdcall fn_ROCX000017(void* dst, void* src);

void* __stdcall fn_ROCX000017(void* dst, CPropertyGridItemBrickColor* src)
{
    void* value;
    if (src == 0)
        value = 0;
    else
        value = src->field_20;
    fn_ROCX000017(dst, value);
    return dst;
}
}
