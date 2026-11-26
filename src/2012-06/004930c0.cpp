// from server: 100% by Xemicl
// roc 2012-06 004930c0  unit: CRobloxView  size: 76 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 004930c0
//
// 004930c0  53                   push ebx
// 004930c1  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 004930c5  55                   push ebp
// 004930c6  8b6c2410             mov ebp, dword ptr [esp + 0x10]
// 004930ca  56                   push esi
// 004930cb  57                   push edi
// 004930cc  8b7c2414             mov edi, dword ptr [esp + 0x14]
// 004930d0  53                   push ebx
// 004930d1  55                   push ebp
// 004930d2  57                   push edi
// 004930d3  8bf1                 mov esi, ecx
// 004930d5  e864f64e00           call 0x98273e
// 004930da  85ff                 test edi, edi
// 004930dc  7415                 je 0x4930f3
// 004930de  8b4654               mov eax, dword ptr [esi + 0x54]
// 004930e1  50                   push eax
// 004930e2  6a01                 push 1
// 004930e4  e807f9f6ff           call 0x4029f0
// 004930e9  83c408               add esp, 8
// 004930ec  5f                   pop edi
// 004930ed  5e                   pop esi
// 004930ee  5d                   pop ebp
// 004930ef  5b                   pop ebx
// 004930f0  c20c00               ret 0xc
// 004930f3  3beb                 cmp ebp, ebx
// 004930f5  740e                 je 0x493105
// 004930f7  8b4e54               mov ecx, dword ptr [esi + 0x54]
// 004930fa  51                   push ecx
// 004930fb  6a00                 push 0
// 004930fd  e8eef8f6ff           call 0x4029f0
// 00493102  83c408               add esp, 8
// 00493105  5f                   pop edi
// 00493106  5e                   pop esi
// 00493107  5d                   pop ebp
// 00493108  5b                   pop ebx
// 00493109  c20c00               ret 0xc
// copied from an identical function in another client (function ?fn_ROCX000038_00456310@S@ns_ROCX000038@@QAEXHHH@Z)

namespace ns_ROCX000038 {
extern void __cdecl G1_func_00405aa0(int, int);

struct S
{
    char padding[0x54];
    int field54;

    void G1_func_006a0cc8(int, int, int);
    void fn_ROCX000038_00456310(int, int, int);
};

void S::fn_ROCX000038_00456310(int a, int b, int c)
{
    G1_func_006a0cc8(a, b, c);
    if (a)
        G1_func_00405aa0(1, field54);
    else if (b != c)
        G1_func_00405aa0(0, field54);
}
}