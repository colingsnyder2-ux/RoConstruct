// from server: 100% by auto
// roc 2007-03 0050a740  unit: seg_00500000  size: 53 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0050a740
//
// 0050a740  817c240820010000     cmp dword ptr [esp + 8], 0x120
// 0050a748  56                   push esi
// 0050a749  8b742408             mov esi, dword ptr [esp + 8]
// 0050a74d  8b06                 mov eax, dword ptr [esi]
// 0050a74f  7312                 jae 0x50a763
// 0050a751  50                   push eax
// 0050a752  e829e80000           call 0x518f80
// 0050a757  6a02                 push 2
// 0050a759  e802e80000           call 0x518f60
// 0050a75e  83c408               add esp, 8
// 0050a761  8906                 mov dword ptr [esi], eax
// 0050a763  6820010000           push 0x120
// 0050a768  6a00                 push 0
// 0050a76a  50                   push eax
// 0050a76b  e8ac481100           call 0x61f01c
// 0050a770  83c40c               add esp, 0xc
// 0050a773  5e                   pop esi
// 0050a774  c3                   ret 
// library libpng-1.2.7/png.c (function _png_info_init_3)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.7 png.c
