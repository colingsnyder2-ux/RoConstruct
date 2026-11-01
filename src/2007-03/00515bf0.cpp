// from server: 100% by auto
// roc 2007-03 00515bf0  unit: seg_00510000  size: 423 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00515bf0
//
// 00515bf0  56                   push esi
// 00515bf1  8b742408             mov esi, dword ptr [esp + 8]
// 00515bf5  0fb68e2b010000       movzx ecx, byte ptr [esi + 0x12b]
// 00515bfc  0fb68628010000       movzx eax, byte ptr [esi + 0x128]
// 00515c03  0fafc8               imul ecx, eax
// 00515c06  83f908               cmp ecx, 8
// 00515c09  7c0e                 jl 0x515c19
// 00515c0b  c1e903               shr ecx, 3
// 00515c0e  0faf8ec8000000       imul ecx, dword ptr [esi + 0xc8]
// 00515c15  8bc1                 mov eax, ecx
// 00515c17  eb0f                 jmp 0x515c28
// 00515c19  8b86c8000000         mov eax, dword ptr [esi + 0xc8]
// 00515c1f  0fafc1               imul eax, ecx
// 00515c22  83c007               add eax, 7
// 00515c25  c1e803               shr eax, 3
// 00515c28  57                   push edi
// 00515c29  8d7801               lea edi, [eax + 1]
// 00515c2c  57                   push edi
// 00515c2d  56                   push esi
// 00515c2e  e86d330000           call 0x518fa0
// 00515c33  8986ec000000         mov dword ptr [esi + 0xec], eax
// 00515c39  83c408               add esp, 8
// 00515c3c  c60000               mov byte ptr [eax], 0
// 00515c3f  f6862501000010       test byte ptr [esi + 0x125], 0x10
// 00515c46  741c                 je 0x515c64
// 00515c48  8b8ed8000000         mov ecx, dword ptr [esi + 0xd8]
// 00515c4e  83c101               add ecx, 1
// 00515c51  51                   push ecx
// 00515c52  56                   push esi
// 00515c53  e848330000           call 0x518fa0
// 00515c58  8986f0000000         mov dword ptr [esi + 0xf0], eax
// 00515c5e  83c408               add esp, 8
// 00515c61  c60001               mov byte ptr [eax], 1
// 00515c64  f68625010000e0       test byte ptr [esi + 0x125], 0xe0
// 00515c6b  0f8488000000         je 0x515cf9
// 00515c71  57                   push edi
// 00515c72  56                   push esi
// 00515c73  e828330000           call 0x518fa0
// 00515c78  57                   push edi
// 00515c79  6a00                 push 0
// 00515c7b  50                   push eax
// 00515c7c  8986e8000000         mov dword ptr [esi + 0xe8], eax
// 00515c82  e895931000           call 0x61f01c
// 00515c87  83c414               add esp, 0x14
// 00515c8a  f6862501000020       test byte ptr [esi + 0x125], 0x20
// 00515c91  741c                 je 0x515caf
// 00515c93  8b96d8000000         mov edx, dword ptr [esi + 0xd8]
// 00515c99  83c201               add edx, 1
// 00515c9c  52                   push edx
// 00515c9d  56                   push esi
// 00515c9e  e8fd320000           call 0x518fa0
// 00515ca3  8986f4000000         mov dword ptr [esi + 0xf4], eax
// 00515ca9  83c408               add esp, 8
// 00515cac  c60002               mov byte ptr [eax], 2
// 00515caf  f6862501000040       test byte ptr [esi + 0x125], 0x40
// 00515cb6  741c                 je 0x515cd4
// 00515cb8  8b86d8000000         mov eax, dword ptr [esi + 0xd8]
// 00515cbe  83c001               add eax, 1
// 00515cc1  50                   push eax
// 00515cc2  56                   push esi
// 00515cc3  e8d8320000           call 0x518fa0
// 00515cc8  8986f8000000         mov dword ptr [esi + 0xf8], eax
// 00515cce  83c408               add esp, 8
// 00515cd1  c60003               mov byte ptr [eax], 3
// 00515cd4  f6862501000080       test byte ptr [esi + 0x125], 0x80
// 00515cdb  741c                 je 0x515cf9
// 00515cdd  8b8ed8000000         mov ecx, dword ptr [esi + 0xd8]
// 00515ce3  83c101               add ecx, 1
// 00515ce6  51                   push ecx
// 00515ce7  56                   push esi
// 00515ce8  e8b3320000           call 0x518fa0
// 00515ced  8986fc000000         mov dword ptr [esi + 0xfc], eax
// 00515cf3  83c408               add esp, 8
// 00515cf6  c60004               mov byte ptr [eax], 4
// 00515cf9  80be2301000000       cmp byte ptr [esi + 0x123], 0
// 00515d00  5f                   pop edi
// 00515d01  7462                 je 0x515d65
// 00515d03  f6467002             test byte ptr [esi + 0x70], 2
// 00515d07  7542                 jne 0x515d4b
// 00515d09  8b0d980f7a00         mov ecx, dword ptr [0x7a0f98]
// 00515d0f  8b96cc000000         mov edx, dword ptr [esi + 0xcc]
// 00515d15  2b157c0f7a00         sub edx, dword ptr [0x7a0f7c]
// 00515d1b  8d440aff             lea eax, [edx + ecx - 1]
// 00515d1f  33d2                 xor edx, edx
// 00515d21  f7f1                 div ecx
// 00515d23  33d2                 xor edx, edx
// 00515d25  8986d0000000         mov dword ptr [esi + 0xd0], eax
// 00515d2b  8b86c8000000         mov eax, dword ptr [esi + 0xc8]
// 00515d31  2b05440f7a00         sub eax, dword ptr [0x7a0f44]
// 00515d37  8b0d600f7a00         mov ecx, dword ptr [0x7a0f60]
// 00515d3d  8d4408ff             lea eax, [eax + ecx - 1]
// 00515d41  f7f1                 div ecx
// 00515d43  8986d4000000         mov dword ptr [esi + 0xd4], eax
// 00515d49  eb32                 jmp 0x515d7d
// 00515d4b  8b8ecc000000         mov ecx, dword ptr [esi + 0xcc]
// 00515d51  8b96c8000000         mov edx, dword ptr [esi + 0xc8]
// 00515d57  898ed0000000         mov dword ptr [esi + 0xd0], ecx
// 00515d5d  8996d4000000         mov dword ptr [esi + 0xd4], edx
// 00515d63  eb18                 jmp 0x515d7d
// 00515d65  8b86cc000000         mov eax, dword ptr [esi + 0xcc]
// 00515d6b  8b8ec8000000         mov ecx, dword ptr [esi + 0xc8]
// 00515d71  8986d0000000         mov dword ptr [esi + 0xd0], eax
// 00515d77  898ed4000000         mov dword ptr [esi + 0xd4], ecx
// 00515d7d  8b96b0000000         mov edx, dword ptr [esi + 0xb0]
// 00515d83  8b86ac000000         mov eax, dword ptr [esi + 0xac]
// 00515d89  899684000000         mov dword ptr [esi + 0x84], edx
// 00515d8f  898680000000         mov dword ptr [esi + 0x80], eax
// 00515d95  5e                   pop esi
// 00515d96  c3                   ret 
// library libpng-1.2.7/pngwutil.c (function _png_write_start_row)

// roc-lang: c
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.7 pngwutil.c
