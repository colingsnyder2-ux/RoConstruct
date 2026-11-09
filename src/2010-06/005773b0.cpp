// from server: 100% by auto
// roc 2010-06 005773b0  unit: seg_00570000  size: 42 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 005773b0
//
// 005773b0  56                   push esi
// 005773b1  8b742408             mov esi, dword ptr [esp + 8]
// 005773b5  85f6                 test esi, esi
// 005773b7  741f                 je 0x5773d8
// 005773b9  53                   push ebx
// 005773ba  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 005773be  57                   push edi
// 005773bf  8b7c2418             mov edi, dword ptr [esp + 0x18]
// 005773c3  57                   push edi
// 005773c4  53                   push ebx
// 005773c5  56                   push esi
// 005773c6  e84550ffff           call 0x56c410
// 005773cb  57                   push edi
// 005773cc  53                   push ebx
// 005773cd  56                   push esi
// 005773ce  e80ddcfeff           call 0x564fe0
// 005773d3  83c418               add esp, 0x18
// 005773d6  5f                   pop edi
// 005773d7  5b                   pop ebx
// 005773d8  5e                   pop esi
// 005773d9  c3                   ret 
// library libpng-1.2.16/pngrutil.c (function _png_crc_read)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.16 pngrutil.c
