// roc 2012-06 009d2c10  unit: CXTPControlToolbars  size: 36 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009d2c10
//
// 009d2c10  56                   push esi
// 009d2c11  57                   push edi
// 009d2c12  8bf9                 mov edi, ecx
// 009d2c14  e887ffffff           call 0x9d2ba0
// 009d2c19  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 009d2c1d  8bf0                 mov esi, eax
// 009d2c1f  8b06                 mov eax, dword ptr [esi]
// 009d2c21  8b90e0000000         mov edx, dword ptr [eax + 0xe0]
// 009d2c27  51                   push ecx
// 009d2c28  57                   push edi
// 009d2c29  8bce                 mov ecx, esi
// 009d2c2b  ffd2                 call edx
// 009d2c2d  5f                   pop edi
// 009d2c2e  8bc6                 mov eax, esi
// 009d2c30  5e                   pop esi
// 009d2c31  c20400               ret 4
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
