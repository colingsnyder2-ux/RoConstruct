// roc 2012-06 009d3e00  unit: CXTPControlSelector  size: 36 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009d3e00
//
// 009d3e00  56                   push esi
// 009d3e01  57                   push edi
// 009d3e02  8bf9                 mov edi, ecx
// 009d3e04  e887ffffff           call 0x9d3d90
// 009d3e09  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 009d3e0d  8bf0                 mov esi, eax
// 009d3e0f  8b06                 mov eax, dword ptr [esi]
// 009d3e11  8b90e0000000         mov edx, dword ptr [eax + 0xe0]
// 009d3e17  51                   push ecx
// 009d3e18  57                   push edi
// 009d3e19  8bce                 mov ecx, esi
// 009d3e1b  ffd2                 call edx
// 009d3e1d  5f                   pop edi
// 009d3e1e  8bc6                 mov eax, esi
// 009d3e20  5e                   pop esi
// 009d3e21  c20400               ret 4
// copied from an identical function in another client (function ?sub_44cbb0@CRobloxControlColorSelector@ns_ROCX000024@@QAEPAXPAX@Z)

namespace ns_ROCX000024 {
struct CRobloxControlColorSelector {
    void* sub_44cb40();
    void* sub_44cbb0(void* arg);
};

void* CRobloxControlColorSelector::sub_44cbb0(void* arg)
{
    void* p = sub_44cb40();
    void** vtbl = *(void***)p;
    void (__thiscall *fn)(void*, void*, void*) = (void (__thiscall *)(void*, void*, void*))vtbl[0x38];
    fn(p, this, arg);
    return p;
}
}
