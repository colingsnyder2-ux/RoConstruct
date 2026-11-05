// from server: 100% by auto
// roc 2012-06 00659de0  unit: seg_00650000  size: 42 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00659de0
//
// 00659de0  56                   push esi
// 00659de1  8b742408             mov esi, dword ptr [esp + 8]
// 00659de5  85f6                 test esi, esi
// 00659de7  741f                 je 0x659e08
// 00659de9  53                   push ebx
// 00659dea  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 00659dee  57                   push edi
// 00659def  8b7c2418             mov edi, dword ptr [esp + 0x18]
// 00659df3  57                   push edi
// 00659df4  53                   push ebx
// 00659df5  56                   push esi
// 00659df6  e8f53fffff           call 0x64ddf0
// 00659dfb  57                   push edi
// 00659dfc  53                   push ebx
// 00659dfd  56                   push esi
// 00659dfe  e88d40feff           call 0x63de90
// 00659e03  83c418               add esp, 0x18
// 00659e06  5f                   pop edi
// 00659e07  5b                   pop ebx
// 00659e08  5e                   pop esi
// 00659e09  c3                   ret 
// library libpng-1.2.16/pngrutil.c (function _png_crc_read)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.16 pngrutil.c
