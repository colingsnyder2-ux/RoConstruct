// from server: 100% by auto
// roc 2012-06 00657820  unit: seg_00650000  size: 112 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00657820
//
// 00657820  83ec08               sub esp, 8
// 00657823  56                   push esi
// 00657824  8b742410             mov esi, dword ptr [esp + 0x10]
// 00657828  c644240449           mov byte ptr [esp + 4], 0x49
// 0065782d  c644240545           mov byte ptr [esp + 5], 0x45
// 00657832  c64424064e           mov byte ptr [esp + 6], 0x4e
// 00657837  c644240744           mov byte ptr [esp + 7], 0x44
// 0065783c  c644240800           mov byte ptr [esp + 8], 0
// 00657841  85f6                 test esi, esi
// 00657843  7442                 je 0x657887
// 00657845  6a00                 push 0
// 00657847  8d442408             lea eax, [esp + 8]
// 0065784b  50                   push eax
// 0065784c  56                   push esi
// 0065784d  e86ee8ffff           call 0x6560c0
// 00657852  8b8610010000         mov eax, dword ptr [esi + 0x110]
// 00657858  8bd0                 mov edx, eax
// 0065785a  8bc8                 mov ecx, eax
// 0065785c  c1e918               shr ecx, 0x18
// 0065785f  c1ea10               shr edx, 0x10
// 00657862  884c241c             mov byte ptr [esp + 0x1c], cl
// 00657866  8854241d             mov byte ptr [esp + 0x1d], dl
// 0065786a  6a04                 push 4
// 0065786c  8d542420             lea edx, [esp + 0x20]
// 00657870  8bc8                 mov ecx, eax
// 00657872  52                   push edx
// 00657873  c1e908               shr ecx, 8
// 00657876  56                   push esi
// 00657877  884c242a             mov byte ptr [esp + 0x2a], cl
// 0065787b  8844242b             mov byte ptr [esp + 0x2b], al
// 0065787f  e83cfefeff           call 0x6476c0
// 00657884  83c418               add esp, 0x18
// 00657887  834e6810             or dword ptr [esi + 0x68], 0x10
// 0065788b  5e                   pop esi
// 0065788c  83c408               add esp, 8
// 0065788f  c3                   ret 
// library libpng-1.2.22/pngwutil.c (function _png_write_IEND)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.22 pngwutil.c
