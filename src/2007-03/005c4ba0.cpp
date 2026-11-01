// from server: 100% by auto
// roc 2007-03 005c4ba0  unit: seg_005c0000  size: 118 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005c4ba0
//
// 005c4ba0  81ec10020000         sub esp, 0x210
// 005c4ba6  53                   push ebx
// 005c4ba7  56                   push esi
// 005c4ba8  57                   push edi
// 005c4ba9  8bbc2420020000       mov edi, dword ptr [esp + 0x220]
// 005c4bb0  8d44240c             lea eax, [esp + 0xc]
// 005c4bb4  50                   push eax
// 005c4bb5  6a01                 push 1
// 005c4bb7  57                   push edi
// 005c4bb8  e8035affff           call 0x5ba5c0
// 005c4bbd  6a02                 push 2
// 005c4bbf  57                   push edi
// 005c4bc0  8bd8                 mov ebx, eax
// 005c4bc2  e8395bffff           call 0x5ba700
// 005c4bc7  8d4c2424             lea ecx, [esp + 0x24]
// 005c4bcb  51                   push ecx
// 005c4bcc  57                   push edi
// 005c4bcd  8bf0                 mov esi, eax
// 005c4bcf  e8dc53ffff           call 0x5b9fb0
// 005c4bd4  83c41c               add esp, 0x1c
// 005c4bd7  85f6                 test esi, esi
// 005c4bd9  7e1f                 jle 0x5c4bfa
// 005c4bdb  eb03                 jmp 0x5c4be0
// 005c4bdd  8d4900               lea ecx, [ecx]
// 005c4be0  8b54240c             mov edx, dword ptr [esp + 0xc]
// 005c4be4  52                   push edx
// 005c4be5  8d442414             lea eax, [esp + 0x14]
// 005c4be9  53                   push ebx
// 005c4bea  50                   push eax
// 005c4beb  83ee01               sub esi, 1
// 005c4bee  e88d52ffff           call 0x5b9e80
// 005c4bf3  83c40c               add esp, 0xc
// 005c4bf6  85f6                 test esi, esi
// 005c4bf8  7fe6                 jg 0x5c4be0
// 005c4bfa  8d4c2410             lea ecx, [esp + 0x10]
// 005c4bfe  51                   push ecx
// 005c4bff  e8dc52ffff           call 0x5b9ee0
// 005c4c04  83c404               add esp, 4
// 005c4c07  5f                   pop edi
// 005c4c08  5e                   pop esi
// 005c4c09  b801000000           mov eax, 1
// 005c4c0e  5b                   pop ebx
// 005c4c0f  81c410020000         add esp, 0x210
// 005c4c15  c3                   ret 
// library lua-5.1.1/lstrlib.c (function _str_rep)

// roc-lang: c
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lstrlib.c
