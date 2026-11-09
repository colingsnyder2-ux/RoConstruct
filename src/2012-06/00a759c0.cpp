// roc 2012-06 00a759c0  unit: CXTPRibbonControlTab  size: 36 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00a759c0
//
// 00a759c0  56                   push esi
// 00a759c1  57                   push edi
// 00a759c2  8bf9                 mov edi, ecx
// 00a759c4  e887ffffff           call 0xa75950
// 00a759c9  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00a759cd  8bf0                 mov esi, eax
// 00a759cf  8b06                 mov eax, dword ptr [esi]
// 00a759d1  8b90e0000000         mov edx, dword ptr [eax + 0xe0]
// 00a759d7  51                   push ecx
// 00a759d8  57                   push edi
// 00a759d9  8bce                 mov ecx, esi
// 00a759db  ffd2                 call edx
// 00a759dd  5f                   pop edi
// 00a759de  8bc6                 mov eax, esi
// 00a759e0  5e                   pop esi
// 00a759e1  c20400               ret 4
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
