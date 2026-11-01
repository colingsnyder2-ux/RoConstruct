// from server: 100% by auto
// roc 2007-03 005fcc10  unit: seg_005f0000  size: 63 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005fcc10
//
// 005fcc10  8b4c2408             mov ecx, dword ptr [esp + 8]
// 005fcc14  80790600             cmp byte ptr [ecx + 6], 0
// 005fcc18  0fb64107             movzx eax, byte ptr [ecx + 7]
// 005fcc1c  7418                 je 0x5fcc36
// 005fcc1e  c1e004               shl eax, 4
// 005fcc21  83c018               add eax, 0x18
// 005fcc24  6a00                 push 0
// 005fcc26  50                   push eax
// 005fcc27  8b44240c             mov eax, dword ptr [esp + 0xc]
// 005fcc2b  51                   push ecx
// 005fcc2c  50                   push eax
// 005fcc2d  e86e070000           call 0x5fd3a0
// 005fcc32  83c410               add esp, 0x10
// 005fcc35  c3                   ret 
// 005fcc36  8d048514000000       lea eax, [eax*4 + 0x14]
// 005fcc3d  6a00                 push 0
// 005fcc3f  50                   push eax
// 005fcc40  8b44240c             mov eax, dword ptr [esp + 0xc]
// 005fcc44  51                   push ecx
// 005fcc45  50                   push eax
// 005fcc46  e855070000           call 0x5fd3a0
// 005fcc4b  83c410               add esp, 0x10
// 005fcc4e  c3                   ret 
// library lua-5.1.1/lfunc.c (function _luaF_freeclosure)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lfunc.c
