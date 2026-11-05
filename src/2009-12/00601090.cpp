// from server: 100% by auto
// roc 2009-12 00601090  unit: G3D::_internal::DialogTemplate  size: 736 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00601090
//
// 00601090  55                   push ebp
// 00601091  8b6c2408             mov ebp, dword ptr [esp + 8]
// 00601095  85ed                 test ebp, ebp
// 00601097  0f84d1020000         je 0x60136e
// 0060109d  56                   push esi
// 0060109e  8b742410             mov esi, dword ptr [esp + 0x10]
// 006010a2  85f6                 test esi, esi
// 006010a4  0f84c3020000         je 0x60136d
// 006010aa  56                   push esi
// 006010ab  55                   push ebp
// 006010ac  e8effdffff           call 0x600ea0
// 006010b1  83c408               add esp, 8
// 006010b4  f6460808             test byte ptr [esi + 8], 8
// 006010b8  7414                 je 0x6010ce
// 006010ba  0fb74614             movzx eax, word ptr [esi + 0x14]
// 006010be  8b4e10               mov ecx, dword ptr [esi + 0x10]
// 006010c1  50                   push eax
// 006010c2  51                   push ecx
// 006010c3  55                   push ebp
// 006010c4  e8b7bc0000           call 0x60cd80
// 006010c9  83c40c               add esp, 0xc
// 006010cc  eb14                 jmp 0x6010e2
// 006010ce  807e1903             cmp byte ptr [esi + 0x19], 3
// 006010d2  750e                 jne 0x6010e2
// 006010d4  683c319c00           push 0x9c313c
// 006010d9  55                   push ebp
// 006010da  e8b1f00000           call 0x610190
// 006010df  83c408               add esp, 8
// 006010e2  f6460810             test byte ptr [esi + 8], 0x10
// 006010e6  7449                 je 0x601131
// 006010e8  f7457000000800       test dword ptr [ebp + 0x70], 0x80000
// 006010ef  7425                 je 0x601116
// 006010f1  807e1903             cmp byte ptr [esi + 0x19], 3
// 006010f5  751f                 jne 0x601116
// 006010f7  33d2                 xor edx, edx
// 006010f9  33c0                 xor eax, eax
// 006010fb  663b5616             cmp dx, word ptr [esi + 0x16]
// 006010ff  7315                 jae 0x601116
// 00601101  8b4e4c               mov ecx, dword ptr [esi + 0x4c]
// 00601104  03c8                 add ecx, eax
// 00601106  80caff               or dl, 0xff
// 00601109  2a11                 sub dl, byte ptr [ecx]
// 0060110b  40                   inc eax
// 0060110c  8811                 mov byte ptr [ecx], dl
// 0060110e  0fb74e16             movzx ecx, word ptr [esi + 0x16]
// 00601112  3bc1                 cmp eax, ecx
// 00601114  7ceb                 jl 0x601101
// 00601116  0fb65619             movzx edx, byte ptr [esi + 0x19]
// 0060111a  0fb74616             movzx eax, word ptr [esi + 0x16]
// 0060111e  52                   push edx
// 0060111f  8b564c               mov edx, dword ptr [esi + 0x4c]
// 00601122  50                   push eax
// 00601123  8d4e50               lea ecx, [esi + 0x50]
// 00601126  51                   push ecx
// 00601127  52                   push edx
// 00601128  55                   push ebp
// 00601129  e8f2d80000           call 0x60ea20
// 0060112e  83c414               add esp, 0x14
// 00601131  f6460820             test byte ptr [esi + 8], 0x20
// 00601135  7412                 je 0x601149
// 00601137  0fb64619             movzx eax, byte ptr [esi + 0x19]
// 0060113b  50                   push eax
// 0060113c  8d4e5a               lea ecx, [esi + 0x5a]
// 0060113f  51                   push ecx
// 00601140  55                   push ebp
// 00601141  e83ada0000           call 0x60eb80
// 00601146  83c40c               add esp, 0xc
// 00601149  f6460840             test byte ptr [esi + 8], 0x40
// 0060114d  7412                 je 0x601161
// 0060114f  0fb75614             movzx edx, word ptr [esi + 0x14]
// 00601153  8b467c               mov eax, dword ptr [esi + 0x7c]
// 00601156  52                   push edx
// 00601157  50                   push eax
// 00601158  55                   push ebp
// 00601159  e832bd0000           call 0x60ce90
// 0060115e  83c40c               add esp, 0xc
// 00601161  f7460800010000       test dword ptr [esi + 8], 0x100
// 00601168  7416                 je 0x601180
// 0060116a  0fb64e6c             movzx ecx, byte ptr [esi + 0x6c]
// 0060116e  8b5668               mov edx, dword ptr [esi + 0x68]
// 00601171  8b4664               mov eax, dword ptr [esi + 0x64]
// 00601174  51                   push ecx
// 00601175  52                   push edx
// 00601176  50                   push eax
// 00601177  55                   push ebp
// 00601178  e863db0000           call 0x60ece0
// 0060117d  83c410               add esp, 0x10
// 00601180  f7460800040000       test dword ptr [esi + 8], 0x400
// 00601187  743c                 je 0x6011c5
// 00601189  8b8eb0000000         mov ecx, dword ptr [esi + 0xb0]
// 0060118f  8b96ac000000         mov edx, dword ptr [esi + 0xac]
// 00601195  0fb686b5000000       movzx eax, byte ptr [esi + 0xb5]
// 0060119c  51                   push ecx
// 0060119d  0fb68eb4000000       movzx ecx, byte ptr [esi + 0xb4]
// 006011a4  52                   push edx
// 006011a5  8b96a8000000         mov edx, dword ptr [esi + 0xa8]
// 006011ab  50                   push eax
// 006011ac  8b86a4000000         mov eax, dword ptr [esi + 0xa4]
// 006011b2  51                   push ecx
// 006011b3  8b8ea0000000         mov ecx, dword ptr [esi + 0xa0]
// 006011b9  52                   push edx
// 006011ba  50                   push eax
// 006011bb  51                   push ecx
// 006011bc  55                   push ebp
// 006011bd  e8bec10000           call 0x60d380
// 006011c2  83c420               add esp, 0x20
// 006011c5  f7460800400000       test dword ptr [esi + 8], 0x4000
// 006011cc  7427                 je 0x6011f5
// 006011ce  dd86e8000000         fld qword ptr [esi + 0xe8]
// 006011d4  0fb696dc000000       movzx edx, byte ptr [esi + 0xdc]
// 006011db  83ec10               sub esp, 0x10
// 006011de  dd5c2408             fstp qword ptr [esp + 8]
// 006011e2  dd86e0000000         fld qword ptr [esi + 0xe0]
// 006011e8  dd1c24               fstp qword ptr [esp]
// 006011eb  52                   push edx
// 006011ec  55                   push ebp
// 006011ed  e8dedb0000           call 0x60edd0
// 006011f2  83c418               add esp, 0x18
// 006011f5  f6460880             test byte ptr [esi + 8], 0x80
// 006011f9  7416                 je 0x601211
// 006011fb  0fb64678             movzx eax, byte ptr [esi + 0x78]
// 006011ff  8b4e74               mov ecx, dword ptr [esi + 0x74]
// 00601202  8b5670               mov edx, dword ptr [esi + 0x70]
// 00601205  50                   push eax
// 00601206  51                   push ecx
// 00601207  52                   push edx
// 00601208  55                   push ebp
// 00601209  e872dc0000           call 0x60ee80
// 0060120e  83c410               add esp, 0x10
// 00601211  57                   push edi
// 00601212  bf00020000           mov edi, 0x200
// 00601217  857e08               test dword ptr [esi + 8], edi
// 0060121a  7410                 je 0x60122c
// 0060121c  8d463c               lea eax, [esi + 0x3c]
// 0060121f  50                   push eax
// 00601220  55                   push ebp
// 00601221  e84add0000           call 0x60ef70
// 00601226  83c408               add esp, 8
// 00601229  097d68               or dword ptr [ebp + 0x68], edi
// 0060122c  f7460800200000       test dword ptr [esi + 8], 0x2000
// 00601233  53                   push ebx
// 00601234  742a                 je 0x601260
// 00601236  33ff                 xor edi, edi
// 00601238  39bed8000000         cmp dword ptr [esi + 0xd8], edi
// 0060123e  7e20                 jle 0x601260
// 00601240  33db                 xor ebx, ebx
// 00601242  8b8ed4000000         mov ecx, dword ptr [esi + 0xd4]
// 00601248  03cb                 add ecx, ebx
// 0060124a  51                   push ecx
// 0060124b  55                   push ebp
// 0060124c  e86fd10000           call 0x60e3c0
// 00601251  47                   inc edi
// 00601252  83c408               add esp, 8
// 00601255  83c310               add ebx, 0x10
// 00601258  3bbed8000000         cmp edi, dword ptr [esi + 0xd8]
// 0060125e  7ce2                 jl 0x601242
// 00601260  33db                 xor ebx, ebx
// 00601262  395e30               cmp dword ptr [esi + 0x30], ebx
// 00601265  0f8e84000000         jle 0x6012ef
// 0060126b  33ff                 xor edi, edi
// 0060126d  8d4900               lea ecx, [ecx]
// 00601270  8b5638               mov edx, dword ptr [esi + 0x38]
// 00601273  8b0417               mov eax, dword ptr [edi + edx]
// 00601276  85c0                 test eax, eax
// 00601278  7e1a                 jle 0x601294
// 0060127a  6818319c00           push 0x9c3118
// 0060127f  55                   push ebp
// 00601280  e8bbef0000           call 0x610240
// 00601285  8b4638               mov eax, dword ptr [esi + 0x38]
// 00601288  83c408               add esp, 8
// 0060128b  c70407fdffffff       mov dword ptr [edi + eax], 0xfffffffd
// 00601292  eb52                 jmp 0x6012e6
// 00601294  7528                 jne 0x6012be
// 00601296  8bca                 mov ecx, edx
// 00601298  8b140f               mov edx, dword ptr [edi + ecx]
// 0060129b  8d040f               lea eax, [edi + ecx]
// 0060129e  8b4808               mov ecx, dword ptr [eax + 8]
// 006012a1  52                   push edx
// 006012a2  8b5004               mov edx, dword ptr [eax + 4]
// 006012a5  6a00                 push 0
// 006012a7  51                   push ecx
// 006012a8  52                   push edx
// 006012a9  55                   push ebp
// 006012aa  e881bf0000           call 0x60d230
// 006012af  8b4638               mov eax, dword ptr [esi + 0x38]
// 006012b2  83c414               add esp, 0x14
// 006012b5  c70407feffffff       mov dword ptr [edi + eax], 0xfffffffe
// 006012bc  eb28                 jmp 0x6012e6
// 006012be  83f8ff               cmp eax, -1
// 006012c1  7523                 jne 0x6012e6
// 006012c3  8bca                 mov ecx, edx
// 006012c5  8b540f08             mov edx, dword ptr [edi + ecx + 8]
// 006012c9  8d040f               lea eax, [edi + ecx]
// 006012cc  8b4004               mov eax, dword ptr [eax + 4]
// 006012cf  6a00                 push 0
// 006012d1  52                   push edx
// 006012d2  50                   push eax
// 006012d3  55                   push ebp
// 006012d4  e877be0000           call 0x60d150
// 006012d9  8b4e38               mov ecx, dword ptr [esi + 0x38]
// 006012dc  83c410               add esp, 0x10
// 006012df  c7040ffdffffff       mov dword ptr [edi + ecx], 0xfffffffd
// 006012e6  43                   inc ebx
// 006012e7  83c710               add edi, 0x10
// 006012ea  3b5e30               cmp ebx, dword ptr [esi + 0x30]
// 006012ed  7c81                 jl 0x601270
// 006012ef  8b86c0000000         mov eax, dword ptr [esi + 0xc0]
// 006012f5  85c0                 test eax, eax
// 006012f7  7472                 je 0x60136b
// 006012f9  8bbebc000000         mov edi, dword ptr [esi + 0xbc]
// 006012ff  8d1480               lea edx, [eax + eax*4]
// 00601302  8d0497               lea eax, [edi + edx*4]
// 00601305  3bf8                 cmp edi, eax
// 00601307  7362                 jae 0x60136b
// 00601309  bb00000100           mov ebx, 0x10000
// 0060130e  8bff                 mov edi, edi
// 00601310  57                   push edi
// 00601311  55                   push ebp
// 00601312  e8c9270000           call 0x603ae0
// 00601317  83c408               add esp, 8
// 0060131a  83f801               cmp eax, 1
// 0060131d  7433                 je 0x601352
// 0060131f  8a4f10               mov cl, byte ptr [edi + 0x10]
// 00601322  84c9                 test cl, cl
// 00601324  742c                 je 0x601352
// 00601326  f6c102               test cl, 2
// 00601329  7427                 je 0x601352
// 0060132b  f6c104               test cl, 4
// 0060132e  7522                 jne 0x601352
// 00601330  f6470320             test byte ptr [edi + 3], 0x20
// 00601334  750a                 jne 0x601340
// 00601336  83f803               cmp eax, 3
// 00601339  7405                 je 0x601340
// 0060133b  855d6c               test dword ptr [ebp + 0x6c], ebx
// 0060133e  7412                 je 0x601352
// 00601340  8b4f0c               mov ecx, dword ptr [edi + 0xc]
// 00601343  8b5708               mov edx, dword ptr [edi + 8]
// 00601346  51                   push ecx
// 00601347  52                   push edx
// 00601348  57                   push edi
// 00601349  55                   push ebp
// 0060134a  e821c70000           call 0x60da70
// 0060134f  83c410               add esp, 0x10
// 00601352  8b86c0000000         mov eax, dword ptr [esi + 0xc0]
// 00601358  8b8ebc000000         mov ecx, dword ptr [esi + 0xbc]
// 0060135e  8d0480               lea eax, [eax + eax*4]
// 00601361  83c714               add edi, 0x14
// 00601364  8d1481               lea edx, [ecx + eax*4]
// 00601367  3bfa                 cmp edi, edx
// 00601369  72a5                 jb 0x601310
// 0060136b  5b                   pop ebx
// 0060136c  5f                   pop edi
// 0060136d  5e                   pop esi
// 0060136e  5d                   pop ebp
// 0060136f  c3                   ret 
// library libpng-1.2.10/pngwrite.c (function _png_write_info)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.10 pngwrite.c
