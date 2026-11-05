// from server: 100% by auto
// roc 2012-06 00656de0  unit: seg_00650000  size: 387 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00656de0
//
// 00656de0  56                   push esi
// 00656de1  8b742408             mov esi, dword ptr [esp + 8]
// 00656de5  0fb68e2b010000       movzx ecx, byte ptr [esi + 0x12b]
// 00656dec  0fb68628010000       movzx eax, byte ptr [esi + 0x128]
// 00656df3  0fafc8               imul ecx, eax
// 00656df6  83f908               cmp ecx, 8
// 00656df9  7c0e                 jl 0x656e09
// 00656dfb  c1e903               shr ecx, 3
// 00656dfe  0faf8ec8000000       imul ecx, dword ptr [esi + 0xc8]
// 00656e05  8bc1                 mov eax, ecx
// 00656e07  eb0f                 jmp 0x656e18
// 00656e09  8b86c8000000         mov eax, dword ptr [esi + 0xc8]
// 00656e0f  0fafc1               imul eax, ecx
// 00656e12  83c007               add eax, 7
// 00656e15  c1e803               shr eax, 3
// 00656e18  57                   push edi
// 00656e19  8d7801               lea edi, [eax + 1]
// 00656e1c  57                   push edi
// 00656e1d  56                   push esi
// 00656e1e  e89d76ffff           call 0x64e4c0
// 00656e23  8986ec000000         mov dword ptr [esi + 0xec], eax
// 00656e29  83c408               add esp, 8
// 00656e2c  c60000               mov byte ptr [eax], 0
// 00656e2f  f6862501000010       test byte ptr [esi + 0x125], 0x10
// 00656e36  741a                 je 0x656e52
// 00656e38  8b8ed8000000         mov ecx, dword ptr [esi + 0xd8]
// 00656e3e  41                   inc ecx
// 00656e3f  51                   push ecx
// 00656e40  56                   push esi
// 00656e41  e87a76ffff           call 0x64e4c0
// 00656e46  8986f0000000         mov dword ptr [esi + 0xf0], eax
// 00656e4c  83c408               add esp, 8
// 00656e4f  c60001               mov byte ptr [eax], 1
// 00656e52  f68625010000e0       test byte ptr [esi + 0x125], 0xe0
// 00656e59  0f8482000000         je 0x656ee1
// 00656e5f  57                   push edi
// 00656e60  56                   push esi
// 00656e61  e85a76ffff           call 0x64e4c0
// 00656e66  57                   push edi
// 00656e67  6a00                 push 0
// 00656e69  50                   push eax
// 00656e6a  8986e8000000         mov dword ptr [esi + 0xe8], eax
// 00656e70  e8ffc43200           call 0x983374
// 00656e75  83c414               add esp, 0x14
// 00656e78  f6862501000020       test byte ptr [esi + 0x125], 0x20
// 00656e7f  741a                 je 0x656e9b
// 00656e81  8b96d8000000         mov edx, dword ptr [esi + 0xd8]
// 00656e87  42                   inc edx
// 00656e88  52                   push edx
// 00656e89  56                   push esi
// 00656e8a  e83176ffff           call 0x64e4c0
// 00656e8f  8986f4000000         mov dword ptr [esi + 0xf4], eax
// 00656e95  83c408               add esp, 8
// 00656e98  c60002               mov byte ptr [eax], 2
// 00656e9b  f6862501000040       test byte ptr [esi + 0x125], 0x40
// 00656ea2  741a                 je 0x656ebe
// 00656ea4  8b86d8000000         mov eax, dword ptr [esi + 0xd8]
// 00656eaa  40                   inc eax
// 00656eab  50                   push eax
// 00656eac  56                   push esi
// 00656ead  e80e76ffff           call 0x64e4c0
// 00656eb2  8986f8000000         mov dword ptr [esi + 0xf8], eax
// 00656eb8  83c408               add esp, 8
// 00656ebb  c60003               mov byte ptr [eax], 3
// 00656ebe  f6862501000080       test byte ptr [esi + 0x125], 0x80
// 00656ec5  741a                 je 0x656ee1
// 00656ec7  8b8ed8000000         mov ecx, dword ptr [esi + 0xd8]
// 00656ecd  41                   inc ecx
// 00656ece  51                   push ecx
// 00656ecf  56                   push esi
// 00656ed0  e8eb75ffff           call 0x64e4c0
// 00656ed5  8986fc000000         mov dword ptr [esi + 0xfc], eax
// 00656edb  83c408               add esp, 8
// 00656ede  c60004               mov byte ptr [eax], 4
// 00656ee1  80be2301000000       cmp byte ptr [esi + 0x123], 0
// 00656ee8  5f                   pop edi
// 00656ee9  7446                 je 0x656f31
// 00656eeb  f6467002             test byte ptr [esi + 0x70], 2
// 00656eef  7526                 jne 0x656f17
// 00656ef1  8b96cc000000         mov edx, dword ptr [esi + 0xcc]
// 00656ef7  8b86c8000000         mov eax, dword ptr [esi + 0xc8]
// 00656efd  83c207               add edx, 7
// 00656f00  c1ea03               shr edx, 3
// 00656f03  83c007               add eax, 7
// 00656f06  c1e803               shr eax, 3
// 00656f09  8996d0000000         mov dword ptr [esi + 0xd0], edx
// 00656f0f  8986d4000000         mov dword ptr [esi + 0xd4], eax
// 00656f15  eb32                 jmp 0x656f49
// 00656f17  8b8ecc000000         mov ecx, dword ptr [esi + 0xcc]
// 00656f1d  8b96c8000000         mov edx, dword ptr [esi + 0xc8]
// 00656f23  898ed0000000         mov dword ptr [esi + 0xd0], ecx
// 00656f29  8996d4000000         mov dword ptr [esi + 0xd4], edx
// 00656f2f  eb18                 jmp 0x656f49
// 00656f31  8b86cc000000         mov eax, dword ptr [esi + 0xcc]
// 00656f37  8b8ec8000000         mov ecx, dword ptr [esi + 0xc8]
// 00656f3d  8986d0000000         mov dword ptr [esi + 0xd0], eax
// 00656f43  898ed4000000         mov dword ptr [esi + 0xd4], ecx
// 00656f49  8b96b0000000         mov edx, dword ptr [esi + 0xb0]
// 00656f4f  8b86ac000000         mov eax, dword ptr [esi + 0xac]
// 00656f55  899684000000         mov dword ptr [esi + 0x84], edx
// 00656f5b  898680000000         mov dword ptr [esi + 0x80], eax
// 00656f61  5e                   pop esi
// 00656f62  c3                   ret 
// library libpng-1.2.22/pngwutil.c (function _png_write_start_row)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.22 pngwutil.c
