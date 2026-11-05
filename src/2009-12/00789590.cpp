// from server: 100% by auto
// roc 2009-12 00789590  unit: RBX::UniversalTool  size: 64 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00789590
//
// 00789590  83ec14               sub esp, 0x14
// 00789593  56                   push esi
// 00789594  57                   push edi
// 00789595  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 00789599  85ff                 test edi, edi
// 0078959b  7505                 jne 0x7895a2
// 0078959d  bfd0d99b00           mov edi, 0x9bd9d0
// 007895a2  8b442428             mov eax, dword ptr [esp + 0x28]
// 007895a6  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 007895aa  8b742420             mov esi, dword ptr [esp + 0x20]
// 007895ae  50                   push eax
// 007895af  51                   push ecx
// 007895b0  8d542410             lea edx, [esp + 0x10]
// 007895b4  52                   push edx
// 007895b5  56                   push esi
// 007895b6  e8b57b0400           call 0x7d1170
// 007895bb  57                   push edi
// 007895bc  8d44241c             lea eax, [esp + 0x1c]
// 007895c0  50                   push eax
// 007895c1  56                   push esi
// 007895c2  e8e9e70000           call 0x797db0
// 007895c7  83c41c               add esp, 0x1c
// 007895ca  5f                   pop edi
// 007895cb  5e                   pop esi
// 007895cc  83c414               add esp, 0x14
// 007895cf  c3                   ret 
// library lua-5.1/lapi.c (function _lua_load)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
