// from server: 39% by colin
// roc 2007-08 00427c10  unit: MainLogManager  size: 36 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00427c10
//
// 00427c10  e8098e2000           call 0x630a1e
// 00427c15  8be5                 mov esp, ebp
// 00427c17  5d                   pop ebp
// 00427c18  c24001               ret 0x140
// 00427c1b  8b8c2454010000       mov ecx, dword ptr [esp + 0x154]
// 00427c22  5f                   pop edi
// 00427c23  5e                   pop esi
// 00427c24  5b                   pop ebx
// 00427c25  33cc                 xor ecx, esp
// 00427c27  32c0                 xor al, al
// 00427c29  e8f08d2000           call 0x630a1e
// 00427c2e  8be5                 mov esp, ebp
// 00427c30  5d                   pop ebp
// 00427c31  c24001               ret 0x140

extern "C" void __stdcall sub_630A1E();

struct MainLogManager {
    void f();
};

void MainLogManager::f()
{
    sub_630A1E();
    sub_630A1E();
}
