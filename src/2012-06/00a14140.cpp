// roc 2012-06 00a14140  unit: CXTPControlEdit  size: 36 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00a14140
//
// 00a14140  56                   push esi
// 00a14141  57                   push edi
// 00a14142  8bf9                 mov edi, ecx
// 00a14144  e887ffffff           call 0xa140d0
// 00a14149  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00a1414d  8bf0                 mov esi, eax
// 00a1414f  8b06                 mov eax, dword ptr [esi]
// 00a14151  8b90e0000000         mov edx, dword ptr [eax + 0xe0]
// 00a14157  51                   push ecx
// 00a14158  57                   push edi
// 00a14159  8bce                 mov ecx, esi
// 00a1415b  ffd2                 call edx
// 00a1415d  5f                   pop edi
// 00a1415e  8bc6                 mov eax, esi
// 00a14160  5e                   pop esi
// 00a14161  c20400               ret 4
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
