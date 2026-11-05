// roc 2012-06 00a4b250  unit: CXTPControlCustom  size: 36 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00a4b250
//
// 00a4b250  56                   push esi
// 00a4b251  57                   push edi
// 00a4b252  8bf9                 mov edi, ecx
// 00a4b254  e887ffffff           call 0xa4b1e0
// 00a4b259  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00a4b25d  8bf0                 mov esi, eax
// 00a4b25f  8b06                 mov eax, dword ptr [esi]
// 00a4b261  8b90e0000000         mov edx, dword ptr [eax + 0xe0]
// 00a4b267  51                   push ecx
// 00a4b268  57                   push edi
// 00a4b269  8bce                 mov ecx, esi
// 00a4b26b  ffd2                 call edx
// 00a4b26d  5f                   pop edi
// 00a4b26e  8bc6                 mov eax, esi
// 00a4b270  5e                   pop esi
// 00a4b271  c20400               ret 4
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
