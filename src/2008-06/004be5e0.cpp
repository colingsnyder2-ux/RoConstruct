// from server: 100% by auto
// roc 2008-06 004be5e0  unit: ProfiledRakPeer  size: 269 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004be5e0
//
// 004be5e0  55                   push ebp
// 004be5e1  8bec                 mov ebp, esp
// 004be5e3  81ec94000000         sub esp, 0x94
// 004be5e9  8b4508               mov eax, dword ptr [ebp + 8]
// 004be5ec  53                   push ebx
// 004be5ed  56                   push esi
// 004be5ee  57                   push edi
// 004be5ef  8bf0                 mov esi, eax
// 004be5f1  6a40                 push 0x40
// 004be5f3  b910000000           mov ecx, 0x10
// 004be5f8  8dbd6cffffff         lea edi, [ebp - 0x94]
// 004be5fe  f3a5                 rep movsd dword ptr es:[edi], dword ptr [esi]
// 004be600  8bf0                 mov esi, eax
// 004be602  6a00                 push 0
// 004be604  b910000000           mov ecx, 0x10
// 004be609  8d7dac               lea edi, [ebp - 0x54]
// 004be60c  50                   push eax
// 004be60d  f3a5                 rep movsd dword ptr es:[edi], dword ptr [esi]
// 004be60f  e8f0301e00           call 0x6a1704
// 004be614  33c0                 xor eax, eax
// 004be616  83c40c               add esp, 0xc
// 004be619  33c9                 xor ecx, ecx
// 004be61b  8945fc               mov dword ptr [ebp - 4], eax
// 004be61e  894df4               mov dword ptr [ebp - 0xc], ecx
// 004be621  eb0d                 jmp 0x4be630
// 004be623  8da42400000000       lea esp, [esp]
// 004be62a  8d9b00000000         lea ebx, [ebx]
// 004be630  8b9c8d6cffffff       mov ebx, dword ptr [ebp + ecx*4 - 0x94]
// 004be637  c745f820000000       mov dword ptr [ebp - 8], 0x20
// 004be63e  85db                 test ebx, ebx
// 004be640  0f848a000000         je 0x4be6d0
// 004be646  f6c301               test bl, 1
// 004be649  746d                 je 0x4be6b8
// 004be64b  85c0                 test eax, eax
// 004be64d  7414                 je 0x4be663
// 004be64f  50                   push eax
// 004be650  8d45ac               lea eax, [ebp - 0x54]
// 004be653  50                   push eax
// 004be654  e847e3ffff           call 0x4bc9a0
// 004be659  83c408               add esp, 8
// 004be65c  c745fc00000000       mov dword ptr [ebp - 4], 0
// 004be663  8d4dac               lea ecx, [ebp - 0x54]
// 004be666  894dec               mov dword ptr [ebp - 0x14], ecx
// 004be669  c745f003000000       mov dword ptr [ebp - 0x10], 3
// 004be670  8b75ec               mov esi, dword ptr [ebp - 0x14]
// 004be673  8b7d08               mov edi, dword ptr [ebp + 8]
// 004be676  8b4df0               mov ecx, dword ptr [ebp - 0x10]
// 004be679  8b06                 mov eax, dword ptr [esi]
// 004be67b  33d2                 xor edx, edx
// 004be67d  0107                 add dword ptr [edi], eax
// 004be67f  8b4604               mov eax, dword ptr [esi + 4]
// 004be682  114704               adc dword ptr [edi + 4], eax
// 004be685  8b4608               mov eax, dword ptr [esi + 8]
// 004be688  114708               adc dword ptr [edi + 8], eax
// 004be68b  8b460c               mov eax, dword ptr [esi + 0xc]
// 004be68e  11470c               adc dword ptr [edi + 0xc], eax
// 004be691  e322                 jecxz 0x4be6b5
// 004be693  42                   inc edx
// 004be694  42                   inc edx
// 004be695  8b04d6               mov eax, dword ptr [esi + edx*8]
// 004be698  1104d7               adc dword ptr [edi + edx*8], eax
// 004be69b  8b44d604             mov eax, dword ptr [esi + edx*8 + 4]
// 004be69f  1144d704             adc dword ptr [edi + edx*8 + 4], eax
// 004be6a3  8b44d608             mov eax, dword ptr [esi + edx*8 + 8]
// 004be6a7  1144d708             adc dword ptr [edi + edx*8 + 8], eax
// 004be6ab  8b44d60c             mov eax, dword ptr [esi + edx*8 + 0xc]
// 004be6af  1144d70c             adc dword ptr [edi + edx*8 + 0xc], eax
// 004be6b3  e2de                 loop 0x4be693
// 004be6b5  8b45fc               mov eax, dword ptr [ebp - 4]
// 004be6b8  8145f8ffff0000       add dword ptr [ebp - 8], 0xffff
// 004be6bf  d1eb                 shr ebx, 1
// 004be6c1  40                   inc eax
// 004be6c2  8945fc               mov dword ptr [ebp - 4], eax
// 004be6c5  85db                 test ebx, ebx
// 004be6c7  0f8579ffffff         jne 0x4be646
// 004be6cd  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 004be6d0  0fb755f8             movzx edx, word ptr [ebp - 8]
// 004be6d4  41                   inc ecx
// 004be6d5  03c2                 add eax, edx
// 004be6d7  8945fc               mov dword ptr [ebp - 4], eax
// 004be6da  894df4               mov dword ptr [ebp - 0xc], ecx
// 004be6dd  83f910               cmp ecx, 0x10
// 004be6e0  0f824affffff         jb 0x4be630
// 004be6e6  5f                   pop edi
// 004be6e7  5e                   pop esi
// 004be6e8  5b                   pop ebx
// 004be6e9  8be5                 mov esp, ebp
// 004be6eb  5d                   pop ebp
// 004be6ec  c3                   ret 
// library openrbx-raknet/RakPeer.cpp (function ??$usquare@$$BY0BA@I@big@@YAXAAY0BA@I@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /EHsc /MD
// roc-lib: openrbx-raknet RakPeer.cpp
