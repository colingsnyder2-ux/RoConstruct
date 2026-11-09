// roc 2012-06 00991220  unit: CXTPControlComboBox  size: 36 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00991220
//
// 00991220  56                   push esi
// 00991221  57                   push edi
// 00991222  8bf9                 mov edi, ecx
// 00991224  e887ffffff           call 0x9911b0
// 00991229  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0099122d  8bf0                 mov esi, eax
// 0099122f  8b06                 mov eax, dword ptr [esi]
// 00991231  8b90e0000000         mov edx, dword ptr [eax + 0xe0]
// 00991237  51                   push ecx
// 00991238  57                   push edi
// 00991239  8bce                 mov ecx, esi
// 0099123b  ffd2                 call edx
// 0099123d  5f                   pop edi
// 0099123e  8bc6                 mov eax, esi
// 00991240  5e                   pop esi
// 00991241  c20400               ret 4
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
