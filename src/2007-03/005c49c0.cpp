// from server: 100% by auto
// roc 2007-03 005c49c0  unit: seg_005c0000  size: 147 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005c49c0
//
// 005c49c0  81ec10020000         sub esp, 0x210
// 005c49c6  53                   push ebx
// 005c49c7  56                   push esi
// 005c49c8  8bb4241c020000       mov esi, dword ptr [esp + 0x21c]
// 005c49cf  57                   push edi
// 005c49d0  8d44240c             lea eax, [esp + 0xc]
// 005c49d4  50                   push eax
// 005c49d5  bb01000000           mov ebx, 1
// 005c49da  53                   push ebx
// 005c49db  56                   push esi
// 005c49dc  e8df5bffff           call 0x5ba5c0
// 005c49e1  8d4c241c             lea ecx, [esp + 0x1c]
// 005c49e5  51                   push ecx
// 005c49e6  56                   push esi
// 005c49e7  8bf8                 mov edi, eax
// 005c49e9  e8c255ffff           call 0x5b9fb0
// 005c49ee  83c414               add esp, 0x14
// 005c49f1  837c240c00           cmp dword ptr [esp + 0xc], 0
// 005c49f6  743e                 je 0x5c4a36
// 005c49f8  eb06                 jmp 0x5c4a00
// 005c49fa  8d9b00000000         lea ebx, [ebx]
// 005c4a00  295c240c             sub dword ptr [esp + 0xc], ebx
// 005c4a04  8d94241c020000       lea edx, [esp + 0x21c]
// 005c4a0b  39542410             cmp dword ptr [esp + 0x10], edx
// 005c4a0f  720d                 jb 0x5c4a1e
// 005c4a11  8d442410             lea eax, [esp + 0x10]
// 005c4a15  50                   push eax
// 005c4a16  e82554ffff           call 0x5b9e40
// 005c4a1b  83c404               add esp, 4
// 005c4a1e  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 005c4a22  8a1439               mov dl, byte ptr [ecx + edi]
// 005c4a25  8b442410             mov eax, dword ptr [esp + 0x10]
// 005c4a29  8810                 mov byte ptr [eax], dl
// 005c4a2b  015c2410             add dword ptr [esp + 0x10], ebx
// 005c4a2f  837c240c00           cmp dword ptr [esp + 0xc], 0
// 005c4a34  75ca                 jne 0x5c4a00
// 005c4a36  295c240c             sub dword ptr [esp + 0xc], ebx
// 005c4a3a  8d4c2410             lea ecx, [esp + 0x10]
// 005c4a3e  51                   push ecx
// 005c4a3f  e89c54ffff           call 0x5b9ee0
// 005c4a44  83c404               add esp, 4
// 005c4a47  5f                   pop edi
// 005c4a48  5e                   pop esi
// 005c4a49  8bc3                 mov eax, ebx
// 005c4a4b  5b                   pop ebx
// 005c4a4c  81c410020000         add esp, 0x210
// 005c4a52  c3                   ret 
// library lua-5.1.1/lstrlib.c (function _str_reverse)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lstrlib.c
