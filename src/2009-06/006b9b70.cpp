// from server: 100% by auto
// roc 2009-06 006b9b70  unit: RBX::UniversalTool  size: 64 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006b9b70
//
// 006b9b70  83ec14               sub esp, 0x14
// 006b9b73  56                   push esi
// 006b9b74  57                   push edi
// 006b9b75  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 006b9b79  85ff                 test edi, edi
// 006b9b7b  7505                 jne 0x6b9b82
// 006b9b7d  bf00758c00           mov edi, 0x8c7500
// 006b9b82  8b442428             mov eax, dword ptr [esp + 0x28]
// 006b9b86  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 006b9b8a  8b742420             mov esi, dword ptr [esp + 0x20]
// 006b9b8e  50                   push eax
// 006b9b8f  51                   push ecx
// 006b9b90  8d542410             lea edx, [esp + 0x10]
// 006b9b94  52                   push edx
// 006b9b95  56                   push esi
// 006b9b96  e885350300           call 0x6ed120
// 006b9b9b  57                   push edi
// 006b9b9c  8d44241c             lea eax, [esp + 0x1c]
// 006b9ba0  50                   push eax
// 006b9ba1  56                   push esi
// 006b9ba2  e8999c0000           call 0x6c3840
// 006b9ba7  83c41c               add esp, 0x1c
// 006b9baa  5f                   pop edi
// 006b9bab  5e                   pop esi
// 006b9bac  83c414               add esp, 0x14
// 006b9baf  c3                   ret 
// library lua-5.1/lapi.c (function _lua_load)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
