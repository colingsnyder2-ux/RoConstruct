// from server: 100% by Xemicl
// roc 2012-06 004010f0  unit: CAboutRobloxDialog  size: 33 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 004010f0
//
// 004010f0  8b442408             mov eax, dword ptr [esp + 8]
// 004010f4  56                   push esi
// 004010f5  8bf1                 mov esi, ecx
// 004010f7  8b4c2408             mov ecx, dword ptr [esp + 8]
// 004010fb  50                   push eax
// 004010fc  51                   push ecx
// 004010fd  8bce                 mov ecx, esi
// 004010ff  e89e125800           call 0x9823a2
// 00401104  6a00                 push 0
// 00401106  8bce                 mov ecx, esi
// 00401108  e88f125800           call 0x98239c
// 0040110d  5e                   pop esi
// 0040110e  c20800               ret 8
// copied from an identical function in another client (function ?f@CAboutRobloxDialog@ns_ROCX000004@@QAEXHH@Z)

namespace ns_ROCX000004 {
struct CAboutRobloxDialog
{
    void f(int a, int b);
    void first(int a, int b);
    void second(int value);
};

void CAboutRobloxDialog::f(int a, int b)
{
    first(a, b);
    second(0);
}
}