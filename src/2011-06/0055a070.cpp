// from server: 100% by auto
// roc 2011-06 0055a070  unit: seg_00550000  size: 270 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0055a070
//
// 0055a070  57                   push edi
// 0055a071  8b7c2408             mov edi, dword ptr [esp + 8]
// 0055a075  85ff                 test edi, edi
// 0055a077  0f84ff000000         je 0x55a17c
// 0055a07d  56                   push esi
// 0055a07e  8b742410             mov esi, dword ptr [esp + 0x10]
// 0055a082  85f6                 test esi, esi
// 0055a084  0f84f1000000         je 0x55a17b
// 0055a08a  dd056024a800         fld qword ptr [0xa82460]
// 0055a090  8a442414             mov al, byte ptr [esp + 0x14]
// 0055a094  814e0800080000       or dword ptr [esi + 8], 0x800
// 0055a09b  83ec08               sub esp, 8
// 0055a09e  dd1c24               fstp qword ptr [esp]
// 0055a0a1  56                   push esi
// 0055a0a2  57                   push edi
// 0055a0a3  88462c               mov byte ptr [esi + 0x2c], al
// 0055a0a6  e8a5f8ffff           call 0x559950
// 0055a0ab  688fb10000           push 0xb18f
// 0055a0b0  56                   push esi
// 0055a0b1  57                   push edi
// 0055a0b2  e819f9ffff           call 0x5599d0
// 0055a0b7  6870170000           push 0x1770
// 0055a0bc  68983a0000           push 0x3a98
// 0055a0c1  6860ea0000           push 0xea60
// 0055a0c6  6830750000           push 0x7530
// 0055a0cb  68e8800000           push 0x80e8
// 0055a0d0  6800fa0000           push 0xfa00
// 0055a0d5  6884800000           push 0x8084
// 0055a0da  68267a0000           push 0x7a26
// 0055a0df  57                   push edi
// 0055a0e0  e8ab6cffff           call 0x550d90
// 0055a0e5  83c440               add esp, 0x40
// 0055a0e8  85c0                 test eax, eax
// 0055a0ea  0f848b000000         je 0x55a17b
// 0055a0f0  6870170000           push 0x1770
// 0055a0f5  68983a0000           push 0x3a98
// 0055a0fa  6860ea0000           push 0xea60
// 0055a0ff  6830750000           push 0x7530
// 0055a104  68e8800000           push 0x80e8
// 0055a109  6800fa0000           push 0xfa00
// 0055a10e  6884800000           push 0x8084
// 0055a113  68267a0000           push 0x7a26
// 0055a118  56                   push esi
// 0055a119  57                   push edi
// 0055a11a  e821f7ffff           call 0x559840
// 0055a11f  dd055824a800         fld qword ptr [0xa82458]
// 0055a125  dd5c2420             fstp qword ptr [esp + 0x20]
// 0055a129  83ec18               sub esp, 0x18
// 0055a12c  dd055024a800         fld qword ptr [0xa82450]
// 0055a132  dd5c2430             fstp qword ptr [esp + 0x30]
// 0055a136  dd054824a800         fld qword ptr [0xa82448]
// 0055a13c  dd5c2428             fstp qword ptr [esp + 0x28]
// 0055a140  dd054024a800         fld qword ptr [0xa82440]
// 0055a146  dd5c2420             fstp qword ptr [esp + 0x20]
// 0055a14a  dd053824a800         fld qword ptr [0xa82438]
// 0055a150  dd5c2418             fstp qword ptr [esp + 0x18]
// 0055a154  dd053024a800         fld qword ptr [0xa82430]
// 0055a15a  dd5c2410             fstp qword ptr [esp + 0x10]
// 0055a15e  dd052824a800         fld qword ptr [0xa82428]
// 0055a164  dd5c2408             fstp qword ptr [esp + 8]
// 0055a168  dd052024a800         fld qword ptr [0xa82420]
// 0055a16e  dd1c24               fstp qword ptr [esp]
// 0055a171  56                   push esi
// 0055a172  57                   push edi
// 0055a173  e8b8f5ffff           call 0x559730
// 0055a178  83c448               add esp, 0x48
// 0055a17b  5e                   pop esi
// 0055a17c  5f                   pop edi
// 0055a17d  c3                   ret 
// library libpng-1.2.35/pngset.c (function _png_set_sRGB_gAMA_and_cHRM)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.35 pngset.c
