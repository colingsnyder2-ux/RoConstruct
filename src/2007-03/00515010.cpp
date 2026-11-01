// from server: 100% by auto
// roc 2007-03 00515010  unit: seg_00510000  size: 46 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00515010
//
// 00515010  57                   push edi
// 00515011  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 00515015  85ff                 test edi, edi
// 00515017  7423                 je 0x51503c
// 00515019  56                   push esi
// 0051501a  8b742414             mov esi, dword ptr [esp + 0x14]
// 0051501e  85f6                 test esi, esi
// 00515020  7619                 jbe 0x51503b
// 00515022  53                   push ebx
// 00515023  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 00515027  56                   push esi
// 00515028  57                   push edi
// 00515029  53                   push ebx
// 0051502a  e8c156ffff           call 0x50a6f0
// 0051502f  56                   push esi
// 00515030  57                   push edi
// 00515031  53                   push ebx
// 00515032  e8a953ffff           call 0x50a3e0
// 00515037  83c418               add esp, 0x18
// 0051503a  5b                   pop ebx
// 0051503b  5e                   pop esi
// 0051503c  5f                   pop edi
// 0051503d  c3                   ret 
// library libpng-1.2.7/pngwutil.c (function _png_write_chunk_data)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.7 pngwutil.c
