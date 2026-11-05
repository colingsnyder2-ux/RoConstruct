// roc 2012-06 009cb610  unit: CXTPControlColorSelector  size: 36 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009cb610
//
// 009cb610  56                   push esi
// 009cb611  57                   push edi
// 009cb612  8bf9                 mov edi, ecx
// 009cb614  e887ffffff           call 0x9cb5a0
// 009cb619  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 009cb61d  8bf0                 mov esi, eax
// 009cb61f  8b06                 mov eax, dword ptr [esi]
// 009cb621  8b90e0000000         mov edx, dword ptr [eax + 0xe0]
// 009cb627  51                   push ecx
// 009cb628  57                   push edi
// 009cb629  8bce                 mov ecx, esi
// 009cb62b  ffd2                 call edx
// 009cb62d  5f                   pop edi
// 009cb62e  8bc6                 mov eax, esi
// 009cb630  5e                   pop esi
// 009cb631  c20400               ret 4
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
