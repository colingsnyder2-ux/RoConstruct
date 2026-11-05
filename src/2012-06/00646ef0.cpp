// from server: 100% by auto
// roc 2012-06 00646ef0  unit: seg_00640000  size: 270 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00646ef0
//
// 00646ef0  57                   push edi
// 00646ef1  8b7c2408             mov edi, dword ptr [esp + 8]
// 00646ef5  85ff                 test edi, edi
// 00646ef7  0f84ff000000         je 0x646ffc
// 00646efd  56                   push esi
// 00646efe  8b742410             mov esi, dword ptr [esp + 0x10]
// 00646f02  85f6                 test esi, esi
// 00646f04  0f84f1000000         je 0x646ffb
// 00646f0a  dd051063b800         fld qword ptr [0xb86310]
// 00646f10  8a442414             mov al, byte ptr [esp + 0x14]
// 00646f14  814e0800080000       or dword ptr [esi + 8], 0x800
// 00646f1b  83ec08               sub esp, 8
// 00646f1e  dd1c24               fstp qword ptr [esp]
// 00646f21  56                   push esi
// 00646f22  57                   push edi
// 00646f23  88462c               mov byte ptr [esi + 0x2c], al
// 00646f26  e8a5f8ffff           call 0x6467d0
// 00646f2b  688fb10000           push 0xb18f
// 00646f30  56                   push esi
// 00646f31  57                   push edi
// 00646f32  e819f9ffff           call 0x646850
// 00646f37  6870170000           push 0x1770
// 00646f3c  68983a0000           push 0x3a98
// 00646f41  6860ea0000           push 0xea60
// 00646f46  6830750000           push 0x7530
// 00646f4b  68e8800000           push 0x80e8
// 00646f50  6800fa0000           push 0xfa00
// 00646f55  6884800000           push 0x8084
// 00646f5a  68267a0000           push 0x7a26
// 00646f5f  57                   push edi
// 00646f60  e86b74ffff           call 0x63e3d0
// 00646f65  83c440               add esp, 0x40
// 00646f68  85c0                 test eax, eax
// 00646f6a  0f848b000000         je 0x646ffb
// 00646f70  6870170000           push 0x1770
// 00646f75  68983a0000           push 0x3a98
// 00646f7a  6860ea0000           push 0xea60
// 00646f7f  6830750000           push 0x7530
// 00646f84  68e8800000           push 0x80e8
// 00646f89  6800fa0000           push 0xfa00
// 00646f8e  6884800000           push 0x8084
// 00646f93  68267a0000           push 0x7a26
// 00646f98  56                   push esi
// 00646f99  57                   push edi
// 00646f9a  e821f7ffff           call 0x6466c0
// 00646f9f  dd050863b800         fld qword ptr [0xb86308]
// 00646fa5  dd5c2420             fstp qword ptr [esp + 0x20]
// 00646fa9  83ec18               sub esp, 0x18
// 00646fac  dd050063b800         fld qword ptr [0xb86300]
// 00646fb2  dd5c2430             fstp qword ptr [esp + 0x30]
// 00646fb6  dd05f862b800         fld qword ptr [0xb862f8]
// 00646fbc  dd5c2428             fstp qword ptr [esp + 0x28]
// 00646fc0  dd05f062b800         fld qword ptr [0xb862f0]
// 00646fc6  dd5c2420             fstp qword ptr [esp + 0x20]
// 00646fca  dd05e862b800         fld qword ptr [0xb862e8]
// 00646fd0  dd5c2418             fstp qword ptr [esp + 0x18]
// 00646fd4  dd05e062b800         fld qword ptr [0xb862e0]
// 00646fda  dd5c2410             fstp qword ptr [esp + 0x10]
// 00646fde  dd05d862b800         fld qword ptr [0xb862d8]
// 00646fe4  dd5c2408             fstp qword ptr [esp + 8]
// 00646fe8  dd05d062b800         fld qword ptr [0xb862d0]
// 00646fee  dd1c24               fstp qword ptr [esp]
// 00646ff1  56                   push esi
// 00646ff2  57                   push edi
// 00646ff3  e8b8f5ffff           call 0x6465b0
// 00646ff8  83c448               add esp, 0x48
// 00646ffb  5e                   pop esi
// 00646ffc  5f                   pop edi
// 00646ffd  c3                   ret 
// library libpng-1.2.35/pngset.c (function _png_set_sRGB_gAMA_and_cHRM)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.35 pngset.c
