// roc 2012-06 009caf20  unit: CXTPControlButtonColor  size: 36 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009caf20
//
// 009caf20  56                   push esi
// 009caf21  57                   push edi
// 009caf22  8bf9                 mov edi, ecx
// 009caf24  e887ffffff           call 0x9caeb0
// 009caf29  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 009caf2d  8bf0                 mov esi, eax
// 009caf2f  8b06                 mov eax, dword ptr [esi]
// 009caf31  8b90e0000000         mov edx, dword ptr [eax + 0xe0]
// 009caf37  51                   push ecx
// 009caf38  57                   push edi
// 009caf39  8bce                 mov ecx, esi
// 009caf3b  ffd2                 call edx
// 009caf3d  5f                   pop edi
// 009caf3e  8bc6                 mov eax, esi
// 009caf40  5e                   pop esi
// 009caf41  c20400               ret 4
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
