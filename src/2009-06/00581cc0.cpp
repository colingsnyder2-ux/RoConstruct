// from server: 100% by auto
// roc 2009-06 00581cc0  unit: seg_00580000  size: 95 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00581cc0
//
// 00581cc0  56                   push esi
// 00581cc1  8b742408             mov esi, dword ptr [esp + 8]
// 00581cc5  57                   push edi
// 00581cc6  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 00581cca  6aff                 push -1
// 00581ccc  68ff7f0000           push 0x7fff
// 00581cd1  57                   push edi
// 00581cd2  56                   push esi
// 00581cd3  e838fcffff           call 0x581910
// 00581cd8  83c410               add esp, 0x10
// 00581cdb  83be2002000000       cmp dword ptr [esi + 0x220], 0
// 00581ce2  7424                 je 0x581d08
// 00581ce4  8b8624020000         mov eax, dword ptr [esi + 0x224]
// 00581cea  50                   push eax
// 00581ceb  56                   push esi
// 00581cec  e8bfcf0000           call 0x58ecb0
// 00581cf1  83c408               add esp, 8
// 00581cf4  c7862402000000000000 mov dword ptr [esi + 0x224], 0
// 00581cfe  c7862002000000000000 mov dword ptr [esi + 0x220], 0
// 00581d08  85ff                 test edi, edi
// 00581d0a  7410                 je 0x581d1c
// 00581d0c  6820010000           push 0x120
// 00581d11  6a00                 push 0
// 00581d13  57                   push edi
// 00581d14  e85b7f1900           call 0x719c74
// 00581d19  83c40c               add esp, 0xc
// 00581d1c  5f                   pop edi
// 00581d1d  5e                   pop esi
// 00581d1e  c3                   ret 
// library libpng-1.2.16/png.c (function _png_info_destroy)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.16 png.c
