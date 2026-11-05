// roc 2012-06 009d2840  unit: CXTPControlWindowList  size: 36 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009d2840
//
// 009d2840  56                   push esi
// 009d2841  57                   push edi
// 009d2842  8bf9                 mov edi, ecx
// 009d2844  e887ffffff           call 0x9d27d0
// 009d2849  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 009d284d  8bf0                 mov esi, eax
// 009d284f  8b06                 mov eax, dword ptr [esi]
// 009d2851  8b90e0000000         mov edx, dword ptr [eax + 0xe0]
// 009d2857  51                   push ecx
// 009d2858  57                   push edi
// 009d2859  8bce                 mov ecx, esi
// 009d285b  ffd2                 call edx
// 009d285d  5f                   pop edi
// 009d285e  8bc6                 mov eax, esi
// 009d2860  5e                   pop esi
// 009d2861  c20400               ret 4
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
