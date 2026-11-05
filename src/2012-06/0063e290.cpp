// from server: 100% by auto
// roc 2012-06 0063e290  unit: seg_00630000  size: 95 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0063e290
//
// 0063e290  56                   push esi
// 0063e291  8b742408             mov esi, dword ptr [esp + 8]
// 0063e295  57                   push edi
// 0063e296  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 0063e29a  6aff                 push -1
// 0063e29c  68ff7f0000           push 0x7fff
// 0063e2a1  57                   push edi
// 0063e2a2  56                   push esi
// 0063e2a3  e838fcffff           call 0x63dee0
// 0063e2a8  83c410               add esp, 0x10
// 0063e2ab  83be2002000000       cmp dword ptr [esi + 0x220], 0
// 0063e2b2  7424                 je 0x63e2d8
// 0063e2b4  8b8624020000         mov eax, dword ptr [esi + 0x224]
// 0063e2ba  50                   push eax
// 0063e2bb  56                   push esi
// 0063e2bc  e85f020100           call 0x64e520
// 0063e2c1  83c408               add esp, 8
// 0063e2c4  c7862402000000000000 mov dword ptr [esi + 0x224], 0
// 0063e2ce  c7862002000000000000 mov dword ptr [esi + 0x220], 0
// 0063e2d8  85ff                 test edi, edi
// 0063e2da  7410                 je 0x63e2ec
// 0063e2dc  6820010000           push 0x120
// 0063e2e1  6a00                 push 0
// 0063e2e3  57                   push edi
// 0063e2e4  e88b503400           call 0x983374
// 0063e2e9  83c40c               add esp, 0xc
// 0063e2ec  5f                   pop edi
// 0063e2ed  5e                   pop esi
// 0063e2ee  c3                   ret 
// library libpng-1.2.16/png.c (function _png_info_destroy)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.16 png.c
