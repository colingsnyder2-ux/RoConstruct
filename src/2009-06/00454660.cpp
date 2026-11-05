// from server: 100% by EspClaude
// roc 2009-06 00454660  unit: CRobloxReportDocView  size: 76 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00454660
//
// 00454660  53                   push ebx
// 00454661  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 00454665  55                   push ebp
// 00454666  8b6c2410             mov ebp, dword ptr [esp + 0x10]
// 0045466a  56                   push esi
// 0045466b  57                   push edi
// 0045466c  8b7c2414             mov edi, dword ptr [esp + 0x14]
// 00454670  53                   push ebx
// 00454671  55                   push ebp
// 00454672  57                   push edi
// 00454673  8bf1                 mov esi, ecx
// 00454675  e8ee492c00           call 0x719068
// 0045467a  85ff                 test edi, edi
// 0045467c  7415                 je 0x454693
// 0045467e  8b4654               mov eax, dword ptr [esi + 0x54]
// 00454681  50                   push eax
// 00454682  6a01                 push 1
// 00454684  e827dffaff           call 0x4025b0
// 00454689  83c408               add esp, 8
// 0045468c  5f                   pop edi
// 0045468d  5e                   pop esi
// 0045468e  5d                   pop ebp
// 0045468f  5b                   pop ebx
// 00454690  c20c00               ret 0xc
// 00454693  3beb                 cmp ebp, ebx
// 00454695  740e                 je 0x4546a5
// 00454697  8b4e54               mov ecx, dword ptr [esi + 0x54]
// 0045469a  51                   push ecx
// 0045469b  6a00                 push 0
// 0045469d  e80edffaff           call 0x4025b0
// 004546a2  83c408               add esp, 8
// 004546a5  5f                   pop edi
// 004546a6  5e                   pop esi
// 004546a7  5d                   pop ebp
// 004546a8  5b                   pop ebx
// 004546a9  c20c00               ret 0xc
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
