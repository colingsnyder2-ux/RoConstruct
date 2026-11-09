// roc 2012-06 00987540  unit: CXTPControl  size: 36 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00987540
//
// 00987540  56                   push esi
// 00987541  57                   push edi
// 00987542  8bf9                 mov edi, ecx
// 00987544  e887ffffff           call 0x9874d0
// 00987549  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0098754d  8bf0                 mov esi, eax
// 0098754f  8b06                 mov eax, dword ptr [esi]
// 00987551  8b90e0000000         mov edx, dword ptr [eax + 0xe0]
// 00987557  51                   push ecx
// 00987558  57                   push edi
// 00987559  8bce                 mov ecx, esi
// 0098755b  ffd2                 call edx
// 0098755d  5f                   pop edi
// 0098755e  8bc6                 mov eax, esi
// 00987560  5e                   pop esi
// 00987561  c20400               ret 4
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
