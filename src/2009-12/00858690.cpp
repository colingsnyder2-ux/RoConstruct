// roc 2009-12 00858690  unit: CXTPTabClientWnd  size: 61 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00858690
//
// 00858690  53                   push ebx
// 00858691  56                   push esi
// 00858692  57                   push edi
// 00858693  8bf9                 mov edi, ecx
// 00858695  33f6                 xor esi, esi
// 00858697  e8b4dfffff           call 0x856650
// 0085869c  85c0                 test eax, eax
// 0085869e  7e1c                 jle 0x8586bc
// 008586a0  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 008586a4  56                   push esi
// 008586a5  8bcf                 mov ecx, edi
// 008586a7  e894eeffff           call 0x857540
// 008586ac  3bc3                 cmp eax, ebx
// 008586ae  7415                 je 0x8586c5
// 008586b0  8bcf                 mov ecx, edi
// 008586b2  46                   inc esi
// 008586b3  e898dfffff           call 0x856650
// 008586b8  3bf0                 cmp esi, eax
// 008586ba  7ce8                 jl 0x8586a4
// 008586bc  5f                   pop edi
// 008586bd  5e                   pop esi
// 008586be  83c8ff               or eax, 0xffffffff
// 008586c1  5b                   pop ebx
// 008586c2  c20400               ret 4
// 008586c5  5f                   pop edi
// 008586c6  8bc6                 mov eax, esi
// 008586c8  5e                   pop esi
// 008586c9  5b                   pop ebx
// 008586ca  c20400               ret 4
// copied from an identical function in another client (function ?FindTabIndex@CXTPTabClientWnd@ns_ROCX000007@ns_ROCX000078@@QAEHH@Z)

namespace ns_ROCX000007 {
struct S_func_007611c0 {

    unsigned int f(int a1, int a2, int a3);
};
unsigned int S_func_007611c0::f(int a1, int a2, int a3)
{
    return 0x80004001u;
}
}
