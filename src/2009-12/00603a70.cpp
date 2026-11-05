// from server: 100% by auto
// roc 2009-12 00603a70  unit: seg_00600000  size: 95 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00603a70
//
// 00603a70  56                   push esi
// 00603a71  8b742408             mov esi, dword ptr [esp + 8]
// 00603a75  57                   push edi
// 00603a76  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 00603a7a  6aff                 push -1
// 00603a7c  68ff7f0000           push 0x7fff
// 00603a81  57                   push edi
// 00603a82  56                   push esi
// 00603a83  e838fcffff           call 0x6036c0
// 00603a88  83c410               add esp, 0x10
// 00603a8b  83be2002000000       cmp dword ptr [esi + 0x220], 0
// 00603a92  7424                 je 0x603ab8
// 00603a94  8b8624020000         mov eax, dword ptr [esi + 0x224]
// 00603a9a  50                   push eax
// 00603a9b  56                   push esi
// 00603a9c  e83fd20000           call 0x610ce0
// 00603aa1  83c408               add esp, 8
// 00603aa4  c7862402000000000000 mov dword ptr [esi + 0x224], 0
// 00603aae  c7862002000000000000 mov dword ptr [esi + 0x220], 0
// 00603ab8  85ff                 test edi, edi
// 00603aba  7410                 je 0x603acc
// 00603abc  6820010000           push 0x120
// 00603ac1  6a00                 push 0
// 00603ac3  57                   push edi
// 00603ac4  e8db0f1f00           call 0x7f4aa4
// 00603ac9  83c40c               add esp, 0xc
// 00603acc  5f                   pop edi
// 00603acd  5e                   pop esi
// 00603ace  c3                   ret 
// library libpng-1.2.16/png.c (function _png_info_destroy)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.16 png.c
