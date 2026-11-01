// from server: 100% by auto
// roc 2009-12 00601370  unit: G3D::_internal::DialogTemplate  size: 360 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00601370
//
// 00601370  55                   push ebp
// 00601371  8b6c2408             mov ebp, dword ptr [esp + 8]
// 00601375  85ed                 test ebp, ebp
// 00601377  0f8459010000         je 0x6014d6
// 0060137d  f6456804             test byte ptr [ebp + 0x68], 4
// 00601381  750e                 jne 0x601391
// 00601383  6868319c00           push 0x9c3168
// 00601388  55                   push ebp
// 00601389  e802ee0000           call 0x610190
// 0060138e  83c408               add esp, 8
// 00601391  56                   push esi
// 00601392  8b742410             mov esi, dword ptr [esp + 0x10]
// 00601396  85f6                 test esi, esi
// 00601398  0f842a010000         je 0x6014c8
// 0060139e  b800020000           mov eax, 0x200
// 006013a3  854608               test dword ptr [esi + 8], eax
// 006013a6  7412                 je 0x6013ba
// 006013a8  854568               test dword ptr [ebp + 0x68], eax
// 006013ab  750d                 jne 0x6013ba
// 006013ad  8d463c               lea eax, [esi + 0x3c]
// 006013b0  50                   push eax
// 006013b1  55                   push ebp
// 006013b2  e8b9db0000           call 0x60ef70
// 006013b7  83c408               add esp, 8
// 006013ba  53                   push ebx
// 006013bb  33db                 xor ebx, ebx
// 006013bd  395e30               cmp dword ptr [esi + 0x30], ebx
// 006013c0  57                   push edi
// 006013c1  0f8e88000000         jle 0x60144f
// 006013c7  33ff                 xor edi, edi
// 006013c9  8da42400000000       lea esp, [esp]
// 006013d0  8b4e38               mov ecx, dword ptr [esi + 0x38]
// 006013d3  8b040f               mov eax, dword ptr [edi + ecx]
// 006013d6  85c0                 test eax, eax
// 006013d8  7e1a                 jle 0x6013f4
// 006013da  6818319c00           push 0x9c3118
// 006013df  55                   push ebp
// 006013e0  e85bee0000           call 0x610240
// 006013e5  8b5638               mov edx, dword ptr [esi + 0x38]
// 006013e8  83c408               add esp, 8
// 006013eb  c70417fdffffff       mov dword ptr [edi + edx], 0xfffffffd
// 006013f2  eb52                 jmp 0x601446
// 006013f4  7c28                 jl 0x60141e
// 006013f6  8bc1                 mov eax, ecx
// 006013f8  8b0c38               mov ecx, dword ptr [eax + edi]
// 006013fb  8b543808             mov edx, dword ptr [eax + edi + 8]
// 006013ff  03c7                 add eax, edi
// 00601401  8b4004               mov eax, dword ptr [eax + 4]
// 00601404  51                   push ecx
// 00601405  6a00                 push 0
// 00601407  52                   push edx
// 00601408  50                   push eax
// 00601409  55                   push ebp
// 0060140a  e821be0000           call 0x60d230
// 0060140f  8b4e38               mov ecx, dword ptr [esi + 0x38]
// 00601412  83c414               add esp, 0x14
// 00601415  c7040ffeffffff       mov dword ptr [edi + ecx], 0xfffffffe
// 0060141c  eb28                 jmp 0x601446
// 0060141e  83f8ff               cmp eax, -1
// 00601421  7523                 jne 0x601446
// 00601423  8bd1                 mov edx, ecx
// 00601425  8b4c3a08             mov ecx, dword ptr [edx + edi + 8]
// 00601429  8d043a               lea eax, [edx + edi]
// 0060142c  8b5004               mov edx, dword ptr [eax + 4]
// 0060142f  6a00                 push 0
// 00601431  51                   push ecx
// 00601432  52                   push edx
// 00601433  55                   push ebp
// 00601434  e817bd0000           call 0x60d150
// 00601439  8b4638               mov eax, dword ptr [esi + 0x38]
// 0060143c  83c410               add esp, 0x10
// 0060143f  c70407fdffffff       mov dword ptr [edi + eax], 0xfffffffd
// 00601446  43                   inc ebx
// 00601447  83c710               add edi, 0x10
// 0060144a  3b5e30               cmp ebx, dword ptr [esi + 0x30]
// 0060144d  7c81                 jl 0x6013d0
// 0060144f  8b86c0000000         mov eax, dword ptr [esi + 0xc0]
// 00601455  85c0                 test eax, eax
// 00601457  746d                 je 0x6014c6
// 00601459  8bbebc000000         mov edi, dword ptr [esi + 0xbc]
// 0060145f  8d0c80               lea ecx, [eax + eax*4]
// 00601462  8d148f               lea edx, [edi + ecx*4]
// 00601465  3bfa                 cmp edi, edx
// 00601467  735d                 jae 0x6014c6
// 00601469  bb00000100           mov ebx, 0x10000
// 0060146e  8bff                 mov edi, edi
// 00601470  57                   push edi
// 00601471  55                   push ebp
// 00601472  e869260000           call 0x603ae0
// 00601477  83c408               add esp, 8
// 0060147a  83f801               cmp eax, 1
// 0060147d  742e                 je 0x6014ad
// 0060147f  8a4f10               mov cl, byte ptr [edi + 0x10]
// 00601482  84c9                 test cl, cl
// 00601484  7427                 je 0x6014ad
// 00601486  f6c108               test cl, 8
// 00601489  7422                 je 0x6014ad
// 0060148b  f6470320             test byte ptr [edi + 3], 0x20
// 0060148f  750a                 jne 0x60149b
// 00601491  83f803               cmp eax, 3
// 00601494  7405                 je 0x60149b
// 00601496  855d6c               test dword ptr [ebp + 0x6c], ebx
// 00601499  7412                 je 0x6014ad
// 0060149b  8b470c               mov eax, dword ptr [edi + 0xc]
// 0060149e  8b4f08               mov ecx, dword ptr [edi + 8]
// 006014a1  50                   push eax
// 006014a2  51                   push ecx
// 006014a3  57                   push edi
// 006014a4  55                   push ebp
// 006014a5  e8c6c50000           call 0x60da70
// 006014aa  83c410               add esp, 0x10
// 006014ad  8b86c0000000         mov eax, dword ptr [esi + 0xc0]
// 006014b3  8d1480               lea edx, [eax + eax*4]
// 006014b6  8b86bc000000         mov eax, dword ptr [esi + 0xbc]
// 006014bc  83c714               add edi, 0x14
// 006014bf  8d0c90               lea ecx, [eax + edx*4]
// 006014c2  3bf9                 cmp edi, ecx
// 006014c4  72aa                 jb 0x601470
// 006014c6  5f                   pop edi
// 006014c7  5b                   pop ebx
// 006014c8  834d6808             or dword ptr [ebp + 0x68], 8
// 006014cc  55                   push ebp
// 006014cd  e89ecb0000           call 0x60e070
// 006014d2  83c404               add esp, 4
// 006014d5  5e                   pop esi
// 006014d6  5d                   pop ebp
// 006014d7  c3                   ret 
// library libpng-1.2.10/pngwrite.c (function _png_write_end)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.10 pngwrite.c
