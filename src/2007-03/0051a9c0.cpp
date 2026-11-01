// from server: 100% by auto
// roc 2007-03 0051a9c0  unit: seg_00510000  size: 38 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0051a9c0
//
// 0051a9c0  53                   push ebx
// 0051a9c1  8b5c2408             mov ebx, dword ptr [esp + 8]
// 0051a9c5  56                   push esi
// 0051a9c6  8b742414             mov esi, dword ptr [esp + 0x14]
// 0051a9ca  57                   push edi
// 0051a9cb  8b7c2414             mov edi, dword ptr [esp + 0x14]
// 0051a9cf  56                   push esi
// 0051a9d0  57                   push edi
// 0051a9d1  53                   push ebx
// 0051a9d2  e8c985ffff           call 0x512fa0
// 0051a9d7  56                   push esi
// 0051a9d8  57                   push edi
// 0051a9d9  53                   push ebx
// 0051a9da  e811fdfeff           call 0x50a6f0
// 0051a9df  83c418               add esp, 0x18
// 0051a9e2  5f                   pop edi
// 0051a9e3  5e                   pop esi
// 0051a9e4  5b                   pop ebx
// 0051a9e5  c3                   ret 
// library libpng-1.2.7/pngrutil.c (function _png_crc_read)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.7 pngrutil.c
