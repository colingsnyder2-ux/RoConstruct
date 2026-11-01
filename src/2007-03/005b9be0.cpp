// from server: 100% by auto
// roc 2007-03 005b9be0  unit: seg_005b0000  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005b9be0
//
// 005b9be0  8b442408             mov eax, dword ptr [esp + 8]
// 005b9be4  56                   push esi
// 005b9be5  8b742408             mov esi, dword ptr [esp + 8]
// 005b9be9  50                   push eax
// 005b9bea  56                   push esi
// 005b9beb  e840edffff           call 0x5b8930
// 005b9bf0  83c408               add esp, 8
// 005b9bf3  85c0                 test eax, eax
// 005b9bf5  7513                 jne 0x5b9c0a
// 005b9bf7  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 005b9bfb  51                   push ecx
// 005b9bfc  6834917b00           push 0x7b9134
// 005b9c01  56                   push esi
// 005b9c02  e849ffffff           call 0x5b9b50
// 005b9c07  83c40c               add esp, 0xc
// 005b9c0a  5e                   pop esi
// 005b9c0b  c3                   ret 
// library lua-5.1.1/lauxlib.c (function _luaL_checkstack)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lauxlib.c
