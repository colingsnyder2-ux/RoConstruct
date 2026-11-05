// from server: 100% by auto
// roc 2009-06 00593a80  unit: seg_00590000  size: 42 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00593a80
//
// 00593a80  56                   push esi
// 00593a81  8b742408             mov esi, dword ptr [esp + 8]
// 00593a85  85f6                 test esi, esi
// 00593a87  741f                 je 0x593aa8
// 00593a89  53                   push ebx
// 00593a8a  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 00593a8e  57                   push edi
// 00593a8f  8b7c2418             mov edi, dword ptr [esp + 0x18]
// 00593a93  57                   push edi
// 00593a94  53                   push ebx
// 00593a95  56                   push esi
// 00593a96  e86552ffff           call 0x588d00
// 00593a9b  57                   push edi
// 00593a9c  53                   push ebx
// 00593a9d  56                   push esi
// 00593a9e  e81ddefeff           call 0x5818c0
// 00593aa3  83c418               add esp, 0x18
// 00593aa6  5f                   pop edi
// 00593aa7  5b                   pop ebx
// 00593aa8  5e                   pop esi
// 00593aa9  c3                   ret 
// library libpng-1.2.16/pngrutil.c (function _png_crc_read)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.16 pngrutil.c
