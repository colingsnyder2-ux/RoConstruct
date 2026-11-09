// from server: 100% by auto
// roc 2009-06 007b4590  unit: CXTPShortcutManager  size: 104 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007b4590
//
// 007b4590  56                   push esi
// 007b4591  8bf1                 mov esi, ecx
// 007b4593  8b4604               mov eax, dword ptr [esi + 4]
// 007b4596  57                   push edi
// 007b4597  85c0                 test eax, eax
// 007b4599  7410                 je 0x7b45ab
// 007b459b  50                   push eax
// 007b459c  e83d47f6ff           call 0x718cde
// 007b45a1  83c404               add esp, 4
// 007b45a4  c7460400000000       mov dword ptr [esi + 4], 0
// 007b45ab  837c241000           cmp dword ptr [esp + 0x10], 0
// 007b45b0  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 007b45b4  743a                 je 0x7b45f0
// 007b45b6  33c9                 xor ecx, ecx
// 007b45b8  8bc7                 mov eax, edi
// 007b45ba  ba04000000           mov edx, 4
// 007b45bf  f7e2                 mul edx
// 007b45c1  0f90c1               seto cl
// 007b45c4  f7d9                 neg ecx
// 007b45c6  0bc8                 or ecx, eax
// 007b45c8  51                   push ecx
// 007b45c9  e84c47f6ff           call 0x718d1a
// 007b45ce  83c404               add esp, 4
// 007b45d1  894604               mov dword ptr [esi + 4], eax
// 007b45d4  85c0                 test eax, eax
// 007b45d6  7505                 jne 0x7b45dd
// 007b45d8  e80747f6ff           call 0x718ce4
// 007b45dd  8d0cbd00000000       lea ecx, [edi*4]
// 007b45e4  51                   push ecx
// 007b45e5  6a00                 push 0
// 007b45e7  50                   push eax
// 007b45e8  e88756f6ff           call 0x719c74
// 007b45ed  83c40c               add esp, 0xc
// 007b45f0  897e08               mov dword ptr [esi + 8], edi
// 007b45f3  5f                   pop edi
// 007b45f4  5e                   pop esi
// 007b45f5  c20800               ret 8
// library mfc-9.0/atlmfc\src\mfc\afxbasetabctrl.cpp (function ?InitHashTable@?$CMap@PAUHICON__@@PAU1@HH@@QAEXIH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbasetabctrl.cpp
