// from server: 100% by auto
// roc 2009-12 007d1040  unit: seg_007d0000  size: 63 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007d1040
//
// 007d1040  8b4c2408             mov ecx, dword ptr [esp + 8]
// 007d1044  80790600             cmp byte ptr [ecx + 6], 0
// 007d1048  0fb64107             movzx eax, byte ptr [ecx + 7]
// 007d104c  7418                 je 0x7d1066
// 007d104e  c1e004               shl eax, 4
// 007d1051  83c018               add eax, 0x18
// 007d1054  6a00                 push 0
// 007d1056  50                   push eax
// 007d1057  8b44240c             mov eax, dword ptr [esp + 0xc]
// 007d105b  51                   push ecx
// 007d105c  50                   push eax
// 007d105d  e84e070000           call 0x7d17b0
// 007d1062  83c410               add esp, 0x10
// 007d1065  c3                   ret 
// 007d1066  8d048514000000       lea eax, [eax*4 + 0x14]
// 007d106d  6a00                 push 0
// 007d106f  50                   push eax
// 007d1070  8b44240c             mov eax, dword ptr [esp + 0xc]
// 007d1074  51                   push ecx
// 007d1075  50                   push eax
// 007d1076  e835070000           call 0x7d17b0
// 007d107b  83c410               add esp, 0x10
// 007d107e  c3                   ret 
// library lua-5.1/lfunc.c (function _luaF_freeclosure)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lfunc.c
