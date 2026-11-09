// roc 2009-12 0083e190  unit: CXTPCustomizeSheet  size: 73 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0083e190
//
// 0083e190  56                   push esi
// 0083e191  8b742408             mov esi, dword ptr [esp + 8]
// 0083e195  8b06                 mov eax, dword ptr [esi]
// 0083e197  8b5004               mov edx, dword ptr [eax + 4]
// 0083e19a  57                   push edi
// 0083e19b  8bf9                 mov edi, ecx
// 0083e19d  6a00                 push 0
// 0083e19f  8bce                 mov ecx, esi
// 0083e1a1  ffd2                 call edx
// 0083e1a3  8b87b8000000         mov eax, dword ptr [edi + 0xb8]
// 0083e1a9  8b7858               mov edi, dword ptr [eax + 0x58]
// 0083e1ac  85ff                 test edi, edi
// 0083e1ae  7424                 je 0x83e1d4
// 0083e1b0  8b16                 mov edx, dword ptr [esi]
// 0083e1b2  8b8798000000         mov eax, dword ptr [edi + 0x98]
// 0083e1b8  8b5204               mov edx, dword ptr [edx + 4]
// 0083e1bb  50                   push eax
// 0083e1bc  8bce                 mov ecx, esi
// 0083e1be  ffd2                 call edx
// 0083e1c0  8b06                 mov eax, dword ptr [esi]
// 0083e1c2  8b10                 mov edx, dword ptr [eax]
// 0083e1c4  33c9                 xor ecx, ecx
// 0083e1c6  398f80000000         cmp dword ptr [edi + 0x80], ecx
// 0083e1cc  0f95c1               setne cl
// 0083e1cf  51                   push ecx
// 0083e1d0  8bce                 mov ecx, esi
// 0083e1d2  ffd2                 call edx
// 0083e1d4  5f                   pop edi
// 0083e1d5  5e                   pop esi
// 0083e1d6  c20400               ret 4
// copied from an identical function in another client (function ?func@CXTPCustomizeSheet@ns_ROCX000006@ns_ROCX00001a@@QAEXPAX@Z)

namespace ns_ROCX000006 {
struct S_func_007611b0 {

    unsigned int f(int a1, int a2, int a3, int a4, int a5, int a6);
};
unsigned int S_func_007611b0::f(int a1, int a2, int a3, int a4, int a5, int a6)
{
    return 0x80004001u;
}
}
