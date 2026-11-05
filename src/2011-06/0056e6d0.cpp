// from server: 100% by auto
// roc 2011-06 0056e6d0  unit: seg_00560000  size: 42 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0056e6d0
//
// 0056e6d0  56                   push esi
// 0056e6d1  8b742408             mov esi, dword ptr [esp + 8]
// 0056e6d5  85f6                 test esi, esi
// 0056e6d7  741f                 je 0x56e6f8
// 0056e6d9  53                   push ebx
// 0056e6da  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 0056e6de  57                   push edi
// 0056e6df  8b7c2418             mov edi, dword ptr [esp + 0x18]
// 0056e6e3  57                   push edi
// 0056e6e4  53                   push ebx
// 0056e6e5  56                   push esi
// 0056e6e6  e88528ffff           call 0x560f70
// 0056e6eb  57                   push edi
// 0056e6ec  53                   push ebx
// 0056e6ed  56                   push esi
// 0056e6ee  e85d21feff           call 0x550850
// 0056e6f3  83c418               add esp, 0x18
// 0056e6f6  5f                   pop edi
// 0056e6f7  5b                   pop ebx
// 0056e6f8  5e                   pop esi
// 0056e6f9  c3                   ret 
// library libpng-1.2.16/pngrutil.c (function _png_crc_read)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.16 pngrutil.c
