// from server: 100% by auto
// roc 2008-06 004017a0  unit: CAboutRobloxDialog  size: 62 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004017a0
//
// 004017a0  56                   push esi
// 004017a1  8b742408             mov esi, dword ptr [esp + 8]
// 004017a5  85f6                 test esi, esi
// 004017a7  742f                 je 0x4017d8
// 004017a9  8b44240c             mov eax, dword ptr [esp + 0xc]
// 004017ad  85c0                 test eax, eax
// 004017af  7427                 je 0x4017d8
// 004017b1  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 004017b5  8b542414             mov edx, dword ptr [esp + 0x14]
// 004017b9  6a00                 push 0
// 004017bb  6a00                 push 0
// 004017bd  51                   push ecx
// 004017be  56                   push esi
// 004017bf  6aff                 push -1
// 004017c1  50                   push eax
// 004017c2  6a00                 push 0
// 004017c4  52                   push edx
// 004017c5  c60600               mov byte ptr [esi], 0
// 004017c8  ff15ec228000         call dword ptr [0x8022ec]
// 004017ce  f7d8                 neg eax
// 004017d0  1bc0                 sbb eax, eax
// 004017d2  23c6                 and eax, esi
// 004017d4  5e                   pop esi
// 004017d5  c21000               ret 0x10
// 004017d8  33c0                 xor eax, eax
// 004017da  5e                   pop esi
// 004017db  c21000               ret 0x10
// library mfc-9.0/atlmfc\src\mfc\olemisc.cpp (function ?AtlW2AHelper@@YGPADPADPB_WHI@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/olemisc.cpp
