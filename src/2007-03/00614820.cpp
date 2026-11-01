// from server: 100% by auto
// roc 2007-03 00614820  unit: seg_00610000  size: 42 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00614820
//
// 00614820  83ec10               sub esp, 0x10
// 00614823  8b442418             mov eax, dword ptr [esp + 0x18]
// 00614827  53                   push ebx
// 00614828  8b5c2418             mov ebx, dword ptr [esp + 0x18]
// 0061482c  8d4c2404             lea ecx, [esp + 4]
// 00614830  51                   push ecx
// 00614831  89442408             mov dword ptr [esp + 8], eax
// 00614835  c744241004000000     mov dword ptr [esp + 0x10], 4
// 0061483d  e8fefeffff           call 0x614740
// 00614842  83c404               add esp, 4
// 00614845  5b                   pop ebx
// 00614846  83c410               add esp, 0x10
// 00614849  c3                   ret 
// library lua-5.1.1/lcode.c (function _luaK_stringK)

// roc-lang: c
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lcode.c
