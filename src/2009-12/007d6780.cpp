// from server: 100% by auto
// roc 2009-12 007d6780  unit: seg_007d0000  size: 24 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007d6780
//
// 007d6780  56                   push esi
// 007d6781  8b742408             mov esi, dword ptr [esp + 8]
// 007d6785  8d4628               lea eax, [esi + 0x28]
// 007d6788  50                   push eax
// 007d6789  8bc6                 mov eax, esi
// 007d678b  e8f0f8ffff           call 0x7d6080
// 007d6790  83c404               add esp, 4
// 007d6793  894620               mov dword ptr [esi + 0x20], eax
// 007d6796  5e                   pop esi
// 007d6797  c3                   ret 
// library lua-5.1/llex.c (function _luaX_lookahead)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 llex.c
