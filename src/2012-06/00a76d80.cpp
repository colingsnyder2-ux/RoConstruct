// roc 2012-06 00a76d80  unit: CXTPRibbonControlSystemButton  size: 36 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00a76d80
//
// 00a76d80  56                   push esi
// 00a76d81  57                   push edi
// 00a76d82  8bf9                 mov edi, ecx
// 00a76d84  e887ffffff           call 0xa76d10
// 00a76d89  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00a76d8d  8bf0                 mov esi, eax
// 00a76d8f  8b06                 mov eax, dword ptr [esi]
// 00a76d91  8b90e0000000         mov edx, dword ptr [eax + 0xe0]
// 00a76d97  51                   push ecx
// 00a76d98  57                   push edi
// 00a76d99  8bce                 mov ecx, esi
// 00a76d9b  ffd2                 call edx
// 00a76d9d  5f                   pop edi
// 00a76d9e  8bc6                 mov eax, esi
// 00a76da0  5e                   pop esi
// 00a76da1  c20400               ret 4
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
