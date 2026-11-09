// from server: 100% by auto
// roc 2009-12 00615a90  unit: seg_00610000  size: 42 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00615a90
//
// 00615a90  56                   push esi
// 00615a91  8b742408             mov esi, dword ptr [esp + 8]
// 00615a95  85f6                 test esi, esi
// 00615a97  741f                 je 0x615ab8
// 00615a99  53                   push ebx
// 00615a9a  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 00615a9e  57                   push edi
// 00615a9f  8b7c2418             mov edi, dword ptr [esp + 0x18]
// 00615aa3  57                   push edi
// 00615aa4  53                   push ebx
// 00615aa5  56                   push esi
// 00615aa6  e8e54fffff           call 0x60aa90
// 00615aab  57                   push edi
// 00615aac  53                   push ebx
// 00615aad  56                   push esi
// 00615aae  e8bddbfeff           call 0x603670
// 00615ab3  83c418               add esp, 0x18
// 00615ab6  5f                   pop edi
// 00615ab7  5b                   pop ebx
// 00615ab8  5e                   pop esi
// 00615ab9  c3                   ret 
// library libpng-1.2.16/pngrutil.c (function _png_crc_read)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.16 pngrutil.c
