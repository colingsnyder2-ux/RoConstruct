// from server: 100% by auto
// roc 2009-12 0060f290  unit: seg_00600000  size: 211 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0060f290
//
// 0060f290  8b442408             mov eax, dword ptr [esp + 8]
// 0060f294  56                   push esi
// 0060f295  8b742408             mov esi, dword ptr [esp + 8]
// 0060f299  8b8e04010000         mov ecx, dword ptr [esi + 0x104]
// 0060f29f  57                   push edi
// 0060f2a0  8d7e74               lea edi, [esi + 0x74]
// 0060f2a3  41                   inc ecx
// 0060f2a4  8907                 mov dword ptr [edi], eax
// 0060f2a6  894e78               mov dword ptr [esi + 0x78], ecx
// 0060f2a9  8da42400000000       lea esp, [esp]
// 0060f2b0  6a00                 push 0
// 0060f2b2  57                   push edi
// 0060f2b3  e8081b0000           call 0x610dc0
// 0060f2b8  83c408               add esp, 8
// 0060f2bb  85c0                 test eax, eax
// 0060f2bd  741b                 je 0x60f2da
// 0060f2bf  8b868c000000         mov eax, dword ptr [esi + 0x8c]
// 0060f2c5  85c0                 test eax, eax
// 0060f2c7  7403                 je 0x60f2cc
// 0060f2c9  50                   push eax
// 0060f2ca  eb05                 jmp 0x60f2d1
// 0060f2cc  68bc319c00           push 0x9c31bc
// 0060f2d1  56                   push esi
// 0060f2d2  e8b90e0000           call 0x610190
// 0060f2d7  83c408               add esp, 8
// 0060f2da  83be8400000000       cmp dword ptr [esi + 0x84], 0
// 0060f2e1  752f                 jne 0x60f312
// 0060f2e3  8b96b0000000         mov edx, dword ptr [esi + 0xb0]
// 0060f2e9  8b86ac000000         mov eax, dword ptr [esi + 0xac]
// 0060f2ef  52                   push edx
// 0060f2f0  50                   push eax
// 0060f2f1  56                   push esi
// 0060f2f2  e849ecffff           call 0x60df40
// 0060f2f7  8b8eac000000         mov ecx, dword ptr [esi + 0xac]
// 0060f2fd  8b96b0000000         mov edx, dword ptr [esi + 0xb0]
// 0060f303  83c40c               add esp, 0xc
// 0060f306  898e80000000         mov dword ptr [esi + 0x80], ecx
// 0060f30c  899684000000         mov dword ptr [esi + 0x84], edx
// 0060f312  837e7800             cmp dword ptr [esi + 0x78], 0
// 0060f316  7598                 jne 0x60f2b0
// 0060f318  8b86e8000000         mov eax, dword ptr [esi + 0xe8]
// 0060f31e  85c0                 test eax, eax
// 0060f320  7412                 je 0x60f334
// 0060f322  8b8eec000000         mov ecx, dword ptr [esi + 0xec]
// 0060f328  898ee8000000         mov dword ptr [esi + 0xe8], ecx
// 0060f32e  8986ec000000         mov dword ptr [esi + 0xec], eax
// 0060f334  56                   push esi
// 0060f335  e8e6fcffff           call 0x60f020
// 0060f33a  ff8654010000         inc dword ptr [esi + 0x154]
// 0060f340  8b8650010000         mov eax, dword ptr [esi + 0x150]
// 0060f346  8b8e54010000         mov ecx, dword ptr [esi + 0x154]
// 0060f34c  83c404               add esp, 4
// 0060f34f  85c0                 test eax, eax
// 0060f351  760d                 jbe 0x60f360
// 0060f353  3bc8                 cmp ecx, eax
// 0060f355  7209                 jb 0x60f360
// 0060f357  56                   push esi
// 0060f358  e8d323ffff           call 0x601730
// 0060f35d  83c404               add esp, 4
// 0060f360  5f                   pop edi
// 0060f361  5e                   pop esi
// 0060f362  c3                   ret 
// library libpng-1.2.6/pngwutil.c (function _png_write_filtered_row)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.6 pngwutil.c
