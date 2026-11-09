// roc 2012-06 00a77840  unit: CXTPRibbonControlSystemRecentFileList  size: 36 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00a77840
//
// 00a77840  56                   push esi
// 00a77841  57                   push edi
// 00a77842  8bf9                 mov edi, ecx
// 00a77844  e887ffffff           call 0xa777d0
// 00a77849  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00a7784d  8bf0                 mov esi, eax
// 00a7784f  8b06                 mov eax, dword ptr [esi]
// 00a77851  8b90e0000000         mov edx, dword ptr [eax + 0xe0]
// 00a77857  51                   push ecx
// 00a77858  57                   push edi
// 00a77859  8bce                 mov ecx, esi
// 00a7785b  ffd2                 call edx
// 00a7785d  5f                   pop edi
// 00a7785e  8bc6                 mov eax, esi
// 00a77860  5e                   pop esi
// 00a77861  c20400               ret 4
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
