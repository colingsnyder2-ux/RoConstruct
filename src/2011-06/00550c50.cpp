// from server: 100% by auto
// roc 2011-06 00550c50  unit: seg_00550000  size: 95 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00550c50
//
// 00550c50  56                   push esi
// 00550c51  8b742408             mov esi, dword ptr [esp + 8]
// 00550c55  57                   push edi
// 00550c56  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 00550c5a  6aff                 push -1
// 00550c5c  68ff7f0000           push 0x7fff
// 00550c61  57                   push edi
// 00550c62  56                   push esi
// 00550c63  e838fcffff           call 0x5508a0
// 00550c68  83c410               add esp, 0x10
// 00550c6b  83be2002000000       cmp dword ptr [esi + 0x220], 0
// 00550c72  7424                 je 0x550c98
// 00550c74  8b8624020000         mov eax, dword ptr [esi + 0x224]
// 00550c7a  50                   push eax
// 00550c7b  56                   push esi
// 00550c7c  e81f0a0100           call 0x5616a0
// 00550c81  83c408               add esp, 8
// 00550c84  c7862402000000000000 mov dword ptr [esi + 0x224], 0
// 00550c8e  c7862002000000000000 mov dword ptr [esi + 0x220], 0
// 00550c98  85ff                 test edi, edi
// 00550c9a  7410                 je 0x550cac
// 00550c9c  6820010000           push 0x120
// 00550ca1  6a00                 push 0
// 00550ca3  57                   push edi
// 00550ca4  e83ba62b00           call 0x80b2e4
// 00550ca9  83c40c               add esp, 0xc
// 00550cac  5f                   pop edi
// 00550cad  5e                   pop esi
// 00550cae  c3                   ret 
// library libpng-1.2.16/png.c (function _png_info_destroy)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.16 png.c
