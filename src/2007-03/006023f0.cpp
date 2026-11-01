// from server: 100% by auto
// roc 2007-03 006023f0  unit: seg_00600000  size: 24 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 006023f0
//
// 006023f0  56                   push esi
// 006023f1  8b742408             mov esi, dword ptr [esp + 8]
// 006023f5  8d4628               lea eax, [esi + 0x28]
// 006023f8  50                   push eax
// 006023f9  8bc6                 mov eax, esi
// 006023fb  e8e0f8ffff           call 0x601ce0
// 00602400  83c404               add esp, 4
// 00602403  894620               mov dword ptr [esi + 0x20], eax
// 00602406  5e                   pop esi
// 00602407  c3                   ret 
// library lua-5.1.1/llex.c (function _luaX_lookahead)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 llex.c
