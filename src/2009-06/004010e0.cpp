// from server: 100% by EspClaude
// roc 2009-06 004010e0  unit: CAboutRobloxDialog  size: 33 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004010e0
//
// 004010e0  8b442408             mov eax, dword ptr [esp + 8]
// 004010e4  56                   push esi
// 004010e5  8bf1                 mov esi, ecx
// 004010e7  8b4c2408             mov ecx, dword ptr [esp + 8]
// 004010eb  50                   push eax
// 004010ec  51                   push ecx
// 004010ed  8bce                 mov ecx, esi
// 004010ef  e8d27b3100           call 0x718cc6
// 004010f4  6a00                 push 0
// 004010f6  8bce                 mov ecx, esi
// 004010f8  e8c37b3100           call 0x718cc0
// 004010fd  5e                   pop esi
// 004010fe  c20800               ret 8
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
