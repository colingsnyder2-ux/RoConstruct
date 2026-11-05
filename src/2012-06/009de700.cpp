// roc 2012-06 009de700  unit: CXTPControlTabWorkspace  size: 36 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009de700
//
// 009de700  56                   push esi
// 009de701  57                   push edi
// 009de702  8bf9                 mov edi, ecx
// 009de704  e887ffffff           call 0x9de690
// 009de709  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 009de70d  8bf0                 mov esi, eax
// 009de70f  8b06                 mov eax, dword ptr [esi]
// 009de711  8b90e0000000         mov edx, dword ptr [eax + 0xe0]
// 009de717  51                   push ecx
// 009de718  57                   push edi
// 009de719  8bce                 mov ecx, esi
// 009de71b  ffd2                 call edx
// 009de71d  5f                   pop edi
// 009de71e  8bc6                 mov eax, esi
// 009de720  5e                   pop esi
// 009de721  c20400               ret 4
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
