// roc 2012-06 009d32c0  unit: CXTPControlRecentFileList  size: 36 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009d32c0
//
// 009d32c0  56                   push esi
// 009d32c1  57                   push edi
// 009d32c2  8bf9                 mov edi, ecx
// 009d32c4  e887ffffff           call 0x9d3250
// 009d32c9  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 009d32cd  8bf0                 mov esi, eax
// 009d32cf  8b06                 mov eax, dword ptr [esi]
// 009d32d1  8b90e0000000         mov edx, dword ptr [eax + 0xe0]
// 009d32d7  51                   push ecx
// 009d32d8  57                   push edi
// 009d32d9  8bce                 mov ecx, esi
// 009d32db  ffd2                 call edx
// 009d32dd  5f                   pop edi
// 009d32de  8bc6                 mov eax, esi
// 009d32e0  5e                   pop esi
// 009d32e1  c20400               ret 4
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
