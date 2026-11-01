// from server: 100% by auto
// roc 2007-03 00401810  unit: seg_00400000  size: 62 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00401810
//
// 00401810  56                   push esi
// 00401811  8b742408             mov esi, dword ptr [esp + 8]
// 00401815  85f6                 test esi, esi
// 00401817  742f                 je 0x401848
// 00401819  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0040181d  85c0                 test eax, eax
// 0040181f  7427                 je 0x401848
// 00401821  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00401825  8b542414             mov edx, dword ptr [esp + 0x14]
// 00401829  6a00                 push 0
// 0040182b  6a00                 push 0
// 0040182d  51                   push ecx
// 0040182e  56                   push esi
// 0040182f  6aff                 push -1
// 00401831  50                   push eax
// 00401832  6a00                 push 0
// 00401834  52                   push edx
// 00401835  c60600               mov byte ptr [esi], 0
// 00401838  ff15d4d27700         call dword ptr [0x77d2d4]
// 0040183e  f7d8                 neg eax
// 00401840  1bc0                 sbb eax, eax
// 00401842  23c6                 and eax, esi
// 00401844  5e                   pop esi
// 00401845  c21000               ret 0x10
// 00401848  33c0                 xor eax, eax
// 0040184a  5e                   pop esi
// 0040184b  c21000               ret 0x10
// library mfc-8.0/atlmfc\src\mfc\afxabort.cpp (function ?AtlW2AHelper@@YGPADPADPB_WHI@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/afxabort.cpp
