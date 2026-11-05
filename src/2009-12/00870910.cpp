// roc 2009-12 00870910  unit: CXTPHookManager::CHookSink  size: 46 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00870910
//
// 00870910  53                   push ebx
// 00870911  8b5c2408             mov ebx, dword ptr [esp + 8]
// 00870915  56                   push esi
// 00870916  57                   push edi
// 00870917  53                   push ebx
// 00870918  8bf9                 mov edi, ecx
// 0087091a  e8a1ffffff           call 0x8708c0
// 0087091f  8bf0                 mov esi, eax
// 00870921  85f6                 test esi, esi
// 00870923  7413                 je 0x870938
// 00870925  53                   push ebx
// 00870926  8bcf                 mov ecx, edi
// 00870928  e8a3bf0300           call 0x8ac8d0
// 0087092d  8b06                 mov eax, dword ptr [esi]
// 0087092f  8b5004               mov edx, dword ptr [eax + 4]
// 00870932  6a01                 push 1
// 00870934  8bce                 mov ecx, esi
// 00870936  ffd2                 call edx
// 00870938  5f                   pop edi
// 00870939  5e                   pop esi
// 0087093a  5b                   pop ebx
// 0087093b  c20400               ret 4
// copied from an identical function in another client (function ?DoRemove@CHookSink@ns_ROCX000025@ns_ROCX0000ee@@QAEXH@Z)

namespace ns_ROCX000025 {
extern char G;

extern char G;
struct S_func_00765d60
{
    void* p0;
    int z0;
    int z1;
    int z2;
    int z3;
    S_func_00765d60();
};
S_func_00765d60::S_func_00765d60()
{
    p0 = (void*)&G;
    z0 = 0;
    z1 = z2 = z3 = 0;
}
}
