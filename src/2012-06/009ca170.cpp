// roc 2012-06 009ca170  unit: ATL::CRegObject  size: 47 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009ca170
//
// 009ca170  8b442408             mov eax, dword ptr [esp + 8]
// 009ca174  85c0                 test eax, eax
// 009ca176  7512                 jne 0x9ca18a
// 009ca178  56                   push esi
// 009ca179  8b742408             mov esi, dword ptr [esp + 8]
// 009ca17d  50                   push eax
// 009ca17e  56                   push esi
// 009ca17f  e81cffffff           call 0x9ca0a0
// 009ca184  8bc6                 mov eax, esi
// 009ca186  5e                   pop esi
// 009ca187  c20800               ret 8
// 009ca18a  8b4020               mov eax, dword ptr [eax + 0x20]
// 009ca18d  56                   push esi
// 009ca18e  8b742408             mov esi, dword ptr [esp + 8]
// 009ca192  50                   push eax
// 009ca193  56                   push esi
// 009ca194  e807ffffff           call 0x9ca0a0
// 009ca199  8bc6                 mov eax, esi
// 009ca19b  5e                   pop esi
// 009ca19c  c20800               ret 8
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
