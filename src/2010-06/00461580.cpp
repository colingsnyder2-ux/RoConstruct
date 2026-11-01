// from server: 100% by Yeetserama
// roc 2010-06 00461580  unit: CRobloxReportDocView  size: 76 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00461580
//
// 00461580  53                   push ebx
// 00461581  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 00461585  55                   push ebp
// 00461586  8b6c2410             mov ebp, dword ptr [esp + 0x10]
// 0046158a  56                   push esi
// 0046158b  57                   push edi
// 0046158c  8b7c2414             mov edi, dword ptr [esp + 0x14]
// 00461590  53                   push ebx
// 00461591  55                   push ebp
// 00461592  57                   push edi
// 00461593  8bf1                 mov esi, ecx
// 00461595  e8366a3400           call 0x7a7fd0
// 0046159a  85ff                 test edi, edi
// 0046159c  7415                 je 0x4615b3
// 0046159e  8b4654               mov eax, dword ptr [esi + 0x54]
// 004615a1  50                   push eax
// 004615a2  6a01                 push 1
// 004615a4  e8b70cfaff           call 0x402260
// 004615a9  83c408               add esp, 8
// 004615ac  5f                   pop edi
// 004615ad  5e                   pop esi
// 004615ae  5d                   pop ebp
// 004615af  5b                   pop ebx
// 004615b0  c20c00               ret 0xc
// 004615b3  3beb                 cmp ebp, ebx
// 004615b5  740e                 je 0x4615c5
// 004615b7  8b4e54               mov ecx, dword ptr [esi + 0x54]
// 004615ba  51                   push ecx
// 004615bb  6a00                 push 0
// 004615bd  e89e0cfaff           call 0x402260
// 004615c2  83c408               add esp, 8
// 004615c5  5f                   pop edi
// 004615c6  5e                   pop esi
// 004615c7  5d                   pop ebp
// 004615c8  5b                   pop ebx
// 004615c9  c20c00               ret 0xc
// copied from an identical function in another client (function ?fn_ROCX000011_00456310@S@ns_ROCX000011@@QAEXHHH@Z)

namespace ns_ROCX000011 {
// from server: 100% by king_originala
extern void __cdecl G1_func_00405aa0(int, int);

struct S
{
    char padding[0x54];
    int field54;

    void G1_func_006a0cc8(int, int, int);
    void fn_ROCX000011_00456310(int, int, int);
};

void S::fn_ROCX000011_00456310(int a, int b, int c)
{
    G1_func_006a0cc8(a, b, c);
    if (a)
        G1_func_00405aa0(1, field54);
    else if (b != c)
        G1_func_00405aa0(0, field54);
}
}
