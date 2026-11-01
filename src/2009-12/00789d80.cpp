// from server: 100% by auto
// roc 2009-12 00789d80  unit: RBX::UniversalTool  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00789d80
//
// 00789d80  8b442408             mov eax, dword ptr [esp + 8]
// 00789d84  56                   push esi
// 00789d85  8b742408             mov esi, dword ptr [esp + 8]
// 00789d89  50                   push eax
// 00789d8a  56                   push esi
// 00789d8b  e810e9ffff           call 0x7886a0
// 00789d90  83c408               add esp, 8
// 00789d93  85c0                 test eax, eax
// 00789d95  7513                 jne 0x789daa
// 00789d97  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00789d9b  51                   push ecx
// 00789d9c  68009d9e00           push 0x9e9d00
// 00789da1  56                   push esi
// 00789da2  e849ffffff           call 0x789cf0
// 00789da7  83c40c               add esp, 0xc
// 00789daa  5e                   pop esi
// 00789dab  c3                   ret 
// library lua-5.1/lauxlib.c (function _luaL_checkstack)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lauxlib.c
