// from server: 100% by auto
// roc 2007-03 0050c810  unit: seg_00500000  size: 66 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0050c810
//
// 0050c810  56                   push esi
// 0050c811  8b742408             mov esi, dword ptr [esp + 8]
// 0050c815  f6466c40             test byte ptr [esi + 0x6c], 0x40
// 0050c819  7519                 jne 0x50c834
// 0050c81b  56                   push esi
// 0050c81c  e85fef0000           call 0x51b780
// 0050c821  8b442410             mov eax, dword ptr [esp + 0x10]
// 0050c825  83c404               add esp, 4
// 0050c828  50                   push eax
// 0050c829  56                   push esi
// 0050c82a  e8511e0000           call 0x50e680
// 0050c82f  83c408               add esp, 8
// 0050c832  5e                   pop esi
// 0050c833  c3                   ret 
// 0050c834  68a0257a00           push 0x7a25a0
// 0050c839  56                   push esi
// 0050c83a  e891bb0000           call 0x5183d0
// 0050c83f  8b442414             mov eax, dword ptr [esp + 0x14]
// 0050c843  83c408               add esp, 8
// 0050c846  50                   push eax
// 0050c847  56                   push esi
// 0050c848  e8331e0000           call 0x50e680
// 0050c84d  83c408               add esp, 8
// 0050c850  5e                   pop esi
// 0050c851  c3                   ret 
// library libpng-1.2.7/pngread.c (function _png_read_update_info)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.7 pngread.c
