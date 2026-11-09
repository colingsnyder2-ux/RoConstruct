// roc 2012-06 009fcc70  unit: CXTPControlGallery  size: 36 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009fcc70
//
// 009fcc70  56                   push esi
// 009fcc71  57                   push edi
// 009fcc72  8bf9                 mov edi, ecx
// 009fcc74  e887ffffff           call 0x9fcc00
// 009fcc79  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 009fcc7d  8bf0                 mov esi, eax
// 009fcc7f  8b06                 mov eax, dword ptr [esi]
// 009fcc81  8b90e0000000         mov edx, dword ptr [eax + 0xe0]
// 009fcc87  51                   push ecx
// 009fcc88  57                   push edi
// 009fcc89  8bce                 mov ecx, esi
// 009fcc8b  ffd2                 call edx
// 009fcc8d  5f                   pop edi
// 009fcc8e  8bc6                 mov eax, esi
// 009fcc90  5e                   pop esi
// 009fcc91  c20400               ret 4
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
