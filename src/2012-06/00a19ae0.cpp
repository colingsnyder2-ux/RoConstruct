// roc 2012-06 00a19ae0  unit: CXTPToolBar::CControlButtonHide  size: 36 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00a19ae0
//
// 00a19ae0  56                   push esi
// 00a19ae1  57                   push edi
// 00a19ae2  8bf9                 mov edi, ecx
// 00a19ae4  e887ffffff           call 0xa19a70
// 00a19ae9  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00a19aed  8bf0                 mov esi, eax
// 00a19aef  8b06                 mov eax, dword ptr [esi]
// 00a19af1  8b90e0000000         mov edx, dword ptr [eax + 0xe0]
// 00a19af7  51                   push ecx
// 00a19af8  57                   push edi
// 00a19af9  8bce                 mov ecx, esi
// 00a19afb  ffd2                 call edx
// 00a19afd  5f                   pop edi
// 00a19afe  8bc6                 mov eax, esi
// 00a19b00  5e                   pop esi
// 00a19b01  c20400               ret 4
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
