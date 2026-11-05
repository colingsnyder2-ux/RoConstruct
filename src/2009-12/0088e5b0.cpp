// from server: 100% by auto
// roc 2009-12 0088e5b0  unit: CXTPShortcutManager  size: 104 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0088e5b0
//
// 0088e5b0  56                   push esi
// 0088e5b1  8bf1                 mov esi, ecx
// 0088e5b3  8b4604               mov eax, dword ptr [esi + 4]
// 0088e5b6  57                   push edi
// 0088e5b7  85c0                 test eax, eax
// 0088e5b9  7410                 je 0x88e5cb
// 0088e5bb  50                   push eax
// 0088e5bc  e84555f6ff           call 0x7f3b06
// 0088e5c1  83c404               add esp, 4
// 0088e5c4  c7460400000000       mov dword ptr [esi + 4], 0
// 0088e5cb  837c241000           cmp dword ptr [esp + 0x10], 0
// 0088e5d0  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 0088e5d4  743a                 je 0x88e610
// 0088e5d6  33c9                 xor ecx, ecx
// 0088e5d8  8bc7                 mov eax, edi
// 0088e5da  ba04000000           mov edx, 4
// 0088e5df  f7e2                 mul edx
// 0088e5e1  0f90c1               seto cl
// 0088e5e4  f7d9                 neg ecx
// 0088e5e6  0bc8                 or ecx, eax
// 0088e5e8  51                   push ecx
// 0088e5e9  e85455f6ff           call 0x7f3b42
// 0088e5ee  83c404               add esp, 4
// 0088e5f1  894604               mov dword ptr [esi + 4], eax
// 0088e5f4  85c0                 test eax, eax
// 0088e5f6  7505                 jne 0x88e5fd
// 0088e5f8  e80f55f6ff           call 0x7f3b0c
// 0088e5fd  8d0cbd00000000       lea ecx, [edi*4]
// 0088e604  51                   push ecx
// 0088e605  6a00                 push 0
// 0088e607  50                   push eax
// 0088e608  e89764f6ff           call 0x7f4aa4
// 0088e60d  83c40c               add esp, 0xc
// 0088e610  897e08               mov dword ptr [esi + 8], edi
// 0088e613  5f                   pop edi
// 0088e614  5e                   pop esi
// 0088e615  c20800               ret 8
// library mfc-9.0/atlmfc\src\mfc\afxbasetabctrl.cpp (function ?InitHashTable@?$CMap@PAUHICON__@@PAU1@HH@@QAEXIH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbasetabctrl.cpp
