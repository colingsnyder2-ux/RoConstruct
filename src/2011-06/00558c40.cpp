// from server: 100% by auto
// roc 2011-06 00558c40  unit: seg_00550000  size: 588 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00558c40
//
// 00558c40  56                   push esi
// 00558c41  8b742408             mov esi, dword ptr [esp + 8]
// 00558c45  85f6                 test esi, esi
// 00558c47  0f841f020000         je 0x558e6c
// 00558c4d  83bee400000000       cmp dword ptr [esi + 0xe4], 0
// 00558c54  7529                 jne 0x558c7f
// 00558c56  80be2401000000       cmp byte ptr [esi + 0x124], 0
// 00558c5d  7520                 jne 0x558c7f
// 00558c5f  f7466800040000       test dword ptr [esi + 0x68], 0x400
// 00558c66  750e                 jne 0x558c76
// 00558c68  680820a800           push 0xa82008
// 00558c6d  56                   push esi
// 00558c6e  e8bd860000           call 0x561330
// 00558c73  83c408               add esp, 8
// 00558c76  56                   push esi
// 00558c77  e8542a0100           call 0x56b6d0
// 00558c7c  83c404               add esp, 4
// 00558c7f  80be2301000000       cmp byte ptr [esi + 0x123], 0
// 00558c86  0f84d4000000         je 0x558d60
// 00558c8c  f6467002             test byte ptr [esi + 0x70], 2
// 00558c90  0f84ca000000         je 0x558d60
// 00558c96  0fb68624010000       movzx eax, byte ptr [esi + 0x124]
// 00558c9d  83f806               cmp eax, 6
// 00558ca0  0f87ba000000         ja 0x558d60
// 00558ca6  ff2485708e5500       jmp dword ptr [eax*4 + 0x558e70]
// 00558cad  f686e400000007       test byte ptr [esi + 0xe4], 7
// 00558cb4  0f84a6000000         je 0x558d60
// 00558cba  56                   push esi
// 00558cbb  e8d0430100           call 0x56d090
// 00558cc0  83c404               add esp, 4
// 00558cc3  5e                   pop esi
// 00558cc4  c3                   ret 
// 00558cc5  f686e400000007       test byte ptr [esi + 0xe4], 7
// 00558ccc  750d                 jne 0x558cdb
// 00558cce  83bec800000005       cmp dword ptr [esi + 0xc8], 5
// 00558cd5  0f8385000000         jae 0x558d60
// 00558cdb  56                   push esi
// 00558cdc  e8af430100           call 0x56d090
// 00558ce1  83c404               add esp, 4
// 00558ce4  5e                   pop esi
// 00558ce5  c3                   ret 
// 00558ce6  8b86e4000000         mov eax, dword ptr [esi + 0xe4]
// 00558cec  2407                 and al, 7
// 00558cee  3c04                 cmp al, 4
// 00558cf0  746e                 je 0x558d60
// 00558cf2  56                   push esi
// 00558cf3  e898430100           call 0x56d090
// 00558cf8  83c404               add esp, 4
// 00558cfb  5e                   pop esi
// 00558cfc  c3                   ret 
// 00558cfd  b803000000           mov eax, 3
// 00558d02  8486e4000000         test byte ptr [esi + 0xe4], al
// 00558d08  7508                 jne 0x558d12
// 00558d0a  3986c8000000         cmp dword ptr [esi + 0xc8], eax
// 00558d10  734e                 jae 0x558d60
// 00558d12  56                   push esi
// 00558d13  e878430100           call 0x56d090
// 00558d18  83c404               add esp, 4
// 00558d1b  5e                   pop esi
// 00558d1c  c3                   ret 
// 00558d1d  8b8ee4000000         mov ecx, dword ptr [esi + 0xe4]
// 00558d23  80e103               and cl, 3
// 00558d26  80f902               cmp cl, 2
// 00558d29  7435                 je 0x558d60
// 00558d2b  56                   push esi
// 00558d2c  e85f430100           call 0x56d090
// 00558d31  83c404               add esp, 4
// 00558d34  5e                   pop esi
// 00558d35  c3                   ret 
// 00558d36  f686e400000001       test byte ptr [esi + 0xe4], 1
// 00558d3d  7509                 jne 0x558d48
// 00558d3f  83bec800000002       cmp dword ptr [esi + 0xc8], 2
// 00558d46  7318                 jae 0x558d60
// 00558d48  56                   push esi
// 00558d49  e842430100           call 0x56d090
// 00558d4e  83c404               add esp, 4
// 00558d51  5e                   pop esi
// 00558d52  c3                   ret 
// 00558d53  f686e400000001       test byte ptr [esi + 0xe4], 1
// 00558d5a  0f845affffff         je 0x558cba
// 00558d60  0fb69626010000       movzx edx, byte ptr [esi + 0x126]
// 00558d67  8a8628010000         mov al, byte ptr [esi + 0x128]
// 00558d6d  8b8ed4000000         mov ecx, dword ptr [esi + 0xd4]
// 00558d73  889608010000         mov byte ptr [esi + 0x108], dl
// 00558d79  8a962b010000         mov dl, byte ptr [esi + 0x12b]
// 00558d7f  888609010000         mov byte ptr [esi + 0x109], al
// 00558d85  f6ea                 imul dl
// 00558d87  57                   push edi
// 00558d88  8dbe00010000         lea edi, [esi + 0x100]
// 00558d8e  88860b010000         mov byte ptr [esi + 0x10b], al
// 00558d94  3c08                 cmp al, 8
// 00558d96  890f                 mov dword ptr [edi], ecx
// 00558d98  88960a010000         mov byte ptr [esi + 0x10a], dl
// 00558d9e  0fb6c0               movzx eax, al
// 00558da1  7208                 jb 0x558dab
// 00558da3  c1e803               shr eax, 3
// 00558da6  0fafc1               imul eax, ecx
// 00558da9  eb09                 jmp 0x558db4
// 00558dab  0fafc1               imul eax, ecx
// 00558dae  83c007               add eax, 7
// 00558db1  c1e803               shr eax, 3
// 00558db4  8b8eec000000         mov ecx, dword ptr [esi + 0xec]
// 00558dba  50                   push eax
// 00558dbb  898604010000         mov dword ptr [esi + 0x104], eax
// 00558dc1  8b442414             mov eax, dword ptr [esp + 0x14]
// 00558dc5  50                   push eax
// 00558dc6  41                   inc ecx
// 00558dc7  51                   push ecx
// 00558dc8  56                   push esi
// 00558dc9  e8e2870000           call 0x5615b0
// 00558dce  83c410               add esp, 0x10
// 00558dd1  80be2301000000       cmp byte ptr [esi + 0x123], 0
// 00558dd8  7436                 je 0x558e10
// 00558dda  8a8624010000         mov al, byte ptr [esi + 0x124]
// 00558de0  3c06                 cmp al, 6
// 00558de2  732c                 jae 0x558e10
// 00558de4  f6467002             test byte ptr [esi + 0x70], 2
// 00558de8  7426                 je 0x558e10
// 00558dea  0fb6d0               movzx edx, al
// 00558ded  8b86ec000000         mov eax, dword ptr [esi + 0xec]
// 00558df3  52                   push edx
// 00558df4  40                   inc eax
// 00558df5  50                   push eax
// 00558df6  57                   push edi
// 00558df7  e8642a0100           call 0x56b860
// 00558dfc  83c40c               add esp, 0xc
// 00558dff  833f00               cmp dword ptr [edi], 0
// 00558e02  750c                 jne 0x558e10
// 00558e04  56                   push esi
// 00558e05  e886420100           call 0x56d090
// 00558e0a  83c404               add esp, 4
// 00558e0d  5f                   pop edi
// 00558e0e  5e                   pop esi
// 00558e0f  c3                   ret 
// 00558e10  837e7000             cmp dword ptr [esi + 0x70], 0
// 00558e14  7409                 je 0x558e1f
// 00558e16  56                   push esi
// 00558e17  e854570100           call 0x56e570
// 00558e1c  83c404               add esp, 4
// 00558e1f  f6863002000004       test byte ptr [esi + 0x230], 4
// 00558e26  741a                 je 0x558e42
// 00558e28  80be3802000040       cmp byte ptr [esi + 0x238], 0x40
// 00558e2f  7511                 jne 0x558e42
// 00558e31  8b8eec000000         mov ecx, dword ptr [esi + 0xec]
// 00558e37  41                   inc ecx
// 00558e38  51                   push ecx
// 00558e39  57                   push edi
// 00558e3a  e851560100           call 0x56e490
// 00558e3f  83c408               add esp, 8
// 00558e42  57                   push edi
// 00558e43  56                   push esi
// 00558e44  e877450100           call 0x56d3c0
// 00558e49  8b869c010000         mov eax, dword ptr [esi + 0x19c]
// 00558e4f  83c408               add esp, 8
// 00558e52  85c0                 test eax, eax
// 00558e54  7415                 je 0x558e6b
// 00558e56  0fb69624010000       movzx edx, byte ptr [esi + 0x124]
// 00558e5d  8b8ee4000000         mov ecx, dword ptr [esi + 0xe4]
// 00558e63  52                   push edx
// 00558e64  51                   push ecx
// 00558e65  56                   push esi
// 00558e66  ffd0                 call eax
// 00558e68  83c40c               add esp, 0xc
// 00558e6b  5f                   pop edi
// 00558e6c  5e                   pop esi
// 00558e6d  c3                   ret 
// 00558e6e  8bff                 mov edi, edi
// 00558e70  ad                   lodsd eax, dword ptr [esi]
// 00558e71  8c5500               mov word ptr [ebp], ss
// 00558e74  c58c5500e68c55       lds ecx, ptr [ebp + edx*2 + 0x558ce600]
// 00558e7b  00fd                 add ch, bh
// 00558e7d  8c5500               mov word ptr [ebp], ss
// 00558e80  1d8d550036           sbb eax, 0x3600558d
// 00558e85  8d5500               lea edx, [ebp]
// 00558e88  53                   push ebx
// 00558e89  8d5500               lea edx, [ebp]
// library libpng-1.2.10/pngwrite.c (function _png_write_row)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.10 pngwrite.c
