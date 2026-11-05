// roc 2012-06 009c9070  unit: CXTPToolBar::CControlButtonExpand  size: 36 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009c9070
//
// 009c9070  56                   push esi
// 009c9071  57                   push edi
// 009c9072  8bf9                 mov edi, ecx
// 009c9074  e887ffffff           call 0x9c9000
// 009c9079  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 009c907d  8bf0                 mov esi, eax
// 009c907f  8b06                 mov eax, dword ptr [esi]
// 009c9081  8b90e0000000         mov edx, dword ptr [eax + 0xe0]
// 009c9087  51                   push ecx
// 009c9088  57                   push edi
// 009c9089  8bce                 mov ecx, esi
// 009c908b  ffd2                 call edx
// 009c908d  5f                   pop edi
// 009c908e  8bc6                 mov eax, esi
// 009c9090  5e                   pop esi
// 009c9091  c20400               ret 4
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
