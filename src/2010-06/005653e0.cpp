// from server: 100% by auto
// roc 2010-06 005653e0  unit: seg_00560000  size: 95 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 005653e0
//
// 005653e0  56                   push esi
// 005653e1  8b742408             mov esi, dword ptr [esp + 8]
// 005653e5  57                   push edi
// 005653e6  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 005653ea  6aff                 push -1
// 005653ec  68ff7f0000           push 0x7fff
// 005653f1  57                   push edi
// 005653f2  56                   push esi
// 005653f3  e838fcffff           call 0x565030
// 005653f8  83c410               add esp, 0x10
// 005653fb  83be2002000000       cmp dword ptr [esi + 0x220], 0
// 00565402  7424                 je 0x565428
// 00565404  8b8624020000         mov eax, dword ptr [esi + 0x224]
// 0056540a  50                   push eax
// 0056540b  56                   push esi
// 0056540c  e8efd10000           call 0x572600
// 00565411  83c408               add esp, 8
// 00565414  c7862402000000000000 mov dword ptr [esi + 0x224], 0
// 0056541e  c7862002000000000000 mov dword ptr [esi + 0x220], 0
// 00565428  85ff                 test edi, edi
// 0056542a  7410                 je 0x56543c
// 0056542c  6820010000           push 0x120
// 00565431  6a00                 push 0
// 00565433  57                   push edi
// 00565434  e8ab372400           call 0x7a8be4
// 00565439  83c40c               add esp, 0xc
// 0056543c  5f                   pop edi
// 0056543d  5e                   pop esi
// 0056543e  c3                   ret 
// library libpng-1.2.16/png.c (function _png_info_destroy)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.16 png.c
