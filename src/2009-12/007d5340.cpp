// from server: 100% by auto
// roc 2009-12 007d5340  unit: seg_007d0000  size: 23 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007d5340
//
// 007d5340  8b442404             mov eax, dword ptr [esp + 4]
// 007d5344  8b4810               mov ecx, dword ptr [eax + 0x10]
// 007d5347  8b542408             mov edx, dword ptr [esp + 8]
// 007d534b  51                   push ecx
// 007d534c  52                   push edx
// 007d534d  50                   push eax
// 007d534e  e84dffffff           call 0x7d52a0
// 007d5353  83c40c               add esp, 0xc
// 007d5356  c3                   ret 
// library lua-5.1/llex.c (function _luaX_syntaxerror)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 llex.c
