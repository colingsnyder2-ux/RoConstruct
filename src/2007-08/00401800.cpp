// from server: 100% by auto
// roc 2007-08 00401800  unit: CAboutRobloxDialog  size: 62 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00401800
//
// 00401800  56                   push esi
// 00401801  8b742408             mov esi, dword ptr [esp + 8]
// 00401805  85f6                 test esi, esi
// 00401807  742f                 je 0x401838
// 00401809  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0040180d  85c0                 test eax, eax
// 0040180f  7427                 je 0x401838
// 00401811  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00401815  8b542414             mov edx, dword ptr [esp + 0x14]
// 00401819  6a00                 push 0
// 0040181b  6a00                 push 0
// 0040181d  51                   push ecx
// 0040181e  56                   push esi
// 0040181f  6aff                 push -1
// 00401821  50                   push eax
// 00401822  6a00                 push 0
// 00401824  52                   push edx
// 00401825  c60600               mov byte ptr [esi], 0
// 00401828  ff1514d37700         call dword ptr [0x77d314]
// 0040182e  f7d8                 neg eax
// 00401830  1bc0                 sbb eax, eax
// 00401832  23c6                 and eax, esi
// 00401834  5e                   pop esi
// 00401835  c21000               ret 0x10
// 00401838  33c0                 xor eax, eax
// 0040183a  5e                   pop esi
// 0040183b  c21000               ret 0x10
// library mfc-8.0/atlmfc\src\mfc\afxabort.cpp (function ?AtlW2AHelper@@YGPADPADPB_WHI@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/afxabort.cpp
