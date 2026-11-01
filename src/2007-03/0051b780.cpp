// from server: 100% by auto
// roc 2007-03 0051b780  unit: seg_00510000  size: 701 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0051b780
//
// 0051b780  55                   push ebp
// 0051b781  56                   push esi
// 0051b782  8b74240c             mov esi, dword ptr [esp + 0xc]
// 0051b786  56                   push esi
// 0051b787  c7467800000000       mov dword ptr [esi + 0x78], 0
// 0051b78e  e8ad65ffff           call 0x511d40
// 0051b793  83c404               add esp, 4
// 0051b796  80be2301000000       cmp byte ptr [esi + 0x123], 0
// 0051b79d  0f8495000000         je 0x51b838
// 0051b7a3  f6467002             test byte ptr [esi + 0x70], 2
// 0051b7a7  7522                 jne 0x51b7cb
// 0051b7a9  8b86cc000000         mov eax, dword ptr [esi + 0xcc]
// 0051b7af  2b057c0f7a00         sub eax, dword ptr [0x7a0f7c]
// 0051b7b5  8b0d980f7a00         mov ecx, dword ptr [0x7a0f98]
// 0051b7bb  8d4408ff             lea eax, [eax + ecx - 1]
// 0051b7bf  33d2                 xor edx, edx
// 0051b7c1  f7f1                 div ecx
// 0051b7c3  8986d0000000         mov dword ptr [esi + 0xd0], eax
// 0051b7c9  eb0c                 jmp 0x51b7d7
// 0051b7cb  8b8ecc000000         mov ecx, dword ptr [esi + 0xcc]
// 0051b7d1  898ed0000000         mov dword ptr [esi + 0xd0], ecx
// 0051b7d7  0fb68624010000       movzx eax, byte ptr [esi + 0x124]
// 0051b7de  8baec8000000         mov ebp, dword ptr [esi + 0xc8]
// 0051b7e4  03c0                 add eax, eax
// 0051b7e6  8b8c00600f7a00       mov ecx, dword ptr [eax + eax + 0x7a0f60]
// 0051b7ed  03c0                 add eax, eax
// 0051b7ef  8bd5                 mov edx, ebp
// 0051b7f1  2b90440f7a00         sub edx, dword ptr [eax + 0x7a0f44]
// 0051b7f7  8d440aff             lea eax, [edx + ecx - 1]
// 0051b7fb  33d2                 xor edx, edx
// 0051b7fd  f7f1                 div ecx
// 0051b7ff  8a8e29010000         mov cl, byte ptr [esi + 0x129]
// 0051b805  80f908               cmp cl, 8
// 0051b808  0fb6c9               movzx ecx, cl
// 0051b80b  8986e0000000         mov dword ptr [esi + 0xe0], eax
// 0051b811  7211                 jb 0x51b824
// 0051b813  c1e903               shr ecx, 3
// 0051b816  0fafc8               imul ecx, eax
// 0051b819  8d4101               lea eax, [ecx + 1]
// 0051b81c  8986dc000000         mov dword ptr [esi + 0xdc], eax
// 0051b822  eb3b                 jmp 0x51b85f
// 0051b824  0fafc8               imul ecx, eax
// 0051b827  83c107               add ecx, 7
// 0051b82a  c1e903               shr ecx, 3
// 0051b82d  8d4101               lea eax, [ecx + 1]
// 0051b830  8986dc000000         mov dword ptr [esi + 0xdc], eax
// 0051b836  eb27                 jmp 0x51b85f
// 0051b838  8b8ed8000000         mov ecx, dword ptr [esi + 0xd8]
// 0051b83e  8b86cc000000         mov eax, dword ptr [esi + 0xcc]
// 0051b844  8baec8000000         mov ebp, dword ptr [esi + 0xc8]
// 0051b84a  83c101               add ecx, 1
// 0051b84d  8986d0000000         mov dword ptr [esi + 0xd0], eax
// 0051b853  89aee0000000         mov dword ptr [esi + 0xe0], ebp
// 0051b859  898edc000000         mov dword ptr [esi + 0xdc], ecx
// 0051b85f  0fb68629010000       movzx eax, byte ptr [esi + 0x129]
// 0051b866  53                   push ebx
// 0051b867  8b5e70               mov ebx, dword ptr [esi + 0x70]
// 0051b86a  f6c304               test bl, 4
// 0051b86d  57                   push edi
// 0051b86e  740e                 je 0x51b87e
// 0051b870  80be2701000008       cmp byte ptr [esi + 0x127], 8
// 0051b877  7305                 jae 0x51b87e
// 0051b879  b808000000           mov eax, 8
// 0051b87e  8bfb                 mov edi, ebx
// 0051b880  81e700100000         and edi, 0x1000
// 0051b886  7460                 je 0x51b8e8
// 0051b888  8a8e26010000         mov cl, byte ptr [esi + 0x126]
// 0051b88e  80f903               cmp cl, 3
// 0051b891  7515                 jne 0x51b8a8
// 0051b893  33c0                 xor eax, eax
// 0051b895  6639861a010000       cmp word ptr [esi + 0x11a], ax
// 0051b89c  0f95c0               setne al
// 0051b89f  8d04c518000000       lea eax, [eax*8 + 0x18]
// 0051b8a6  eb40                 jmp 0x51b8e8
// 0051b8a8  84c9                 test cl, cl
// 0051b8aa  7518                 jne 0x51b8c4
// 0051b8ac  83f808               cmp eax, 8
// 0051b8af  7d05                 jge 0x51b8b6
// 0051b8b1  b808000000           mov eax, 8
// 0051b8b6  6683be1a01000000     cmp word ptr [esi + 0x11a], 0
// 0051b8be  7428                 je 0x51b8e8
// 0051b8c0  03c0                 add eax, eax
// 0051b8c2  eb24                 jmp 0x51b8e8
// 0051b8c4  80f902               cmp cl, 2
// 0051b8c7  751f                 jne 0x51b8e8
// 0051b8c9  6683be1a01000000     cmp word ptr [esi + 0x11a], 0
// 0051b8d1  7415                 je 0x51b8e8
// 0051b8d3  8d0c8500000000       lea ecx, [eax*4]
// 0051b8da  b856555555           mov eax, 0x55555556
// 0051b8df  f7e9                 imul ecx
// 0051b8e1  8bc2                 mov eax, edx
// 0051b8e3  c1e81f               shr eax, 0x1f
// 0051b8e6  03c2                 add eax, edx
// 0051b8e8  8bd3                 mov edx, ebx
// 0051b8ea  81e200800000         and edx, 0x8000
// 0051b8f0  7441                 je 0x51b933
// 0051b8f2  8a8e26010000         mov cl, byte ptr [esi + 0x126]
// 0051b8f8  80f903               cmp cl, 3
// 0051b8fb  7507                 jne 0x51b904
// 0051b8fd  b820000000           mov eax, 0x20
// 0051b902  eb2f                 jmp 0x51b933
// 0051b904  84c9                 test cl, cl
// 0051b906  7513                 jne 0x51b91b
// 0051b908  33c9                 xor ecx, ecx
// 0051b90a  83f808               cmp eax, 8
// 0051b90d  0f9fc1               setg cl
// 0051b910  83e901               sub ecx, 1
// 0051b913  83e1f0               and ecx, 0xfffffff0
// 0051b916  83c120               add ecx, 0x20
// 0051b919  eb16                 jmp 0x51b931
// 0051b91b  80f902               cmp cl, 2
// 0051b91e  7513                 jne 0x51b933
// 0051b920  33c9                 xor ecx, ecx
// 0051b922  83f820               cmp eax, 0x20
// 0051b925  0f9fc1               setg cl
// 0051b928  83e901               sub ecx, 1
// 0051b92b  83e1e0               and ecx, 0xffffffe0
// 0051b92e  83c140               add ecx, 0x40
// 0051b931  8bc1                 mov eax, ecx
// 0051b933  f7c300400000         test ebx, 0x4000
// 0051b939  7457                 je 0x51b992
// 0051b93b  6683be1a01000000     cmp word ptr [esi + 0x11a], 0
// 0051b943  7404                 je 0x51b949
// 0051b945  85ff                 test edi, edi
// 0051b947  7536                 jne 0x51b97f
// 0051b949  85d2                 test edx, edx
// 0051b94b  7532                 jne 0x51b97f
// 0051b94d  8a8e26010000         mov cl, byte ptr [esi + 0x126]
// 0051b953  80f904               cmp cl, 4
// 0051b956  7427                 je 0x51b97f
// 0051b958  83f808               cmp eax, 8
// 0051b95b  7f11                 jg 0x51b96e
// 0051b95d  33c0                 xor eax, eax
// 0051b95f  80f906               cmp cl, 6
// 0051b962  0f94c0               sete al
// 0051b965  8d04c518000000       lea eax, [eax*8 + 0x18]
// 0051b96c  eb24                 jmp 0x51b992
// 0051b96e  80e906               sub cl, 6
// 0051b971  f6d9                 neg cl
// 0051b973  1bc9                 sbb ecx, ecx
// 0051b975  83e1f0               and ecx, 0xfffffff0
// 0051b978  83c140               add ecx, 0x40
// 0051b97b  8bc1                 mov eax, ecx
// 0051b97d  eb13                 jmp 0x51b992
// 0051b97f  33d2                 xor edx, edx
// 0051b981  83f810               cmp eax, 0x10
// 0051b984  0f9fc2               setg dl
// 0051b987  83ea01               sub edx, 1
// 0051b98a  83e2e0               and edx, 0xffffffe0
// 0051b98d  83c240               add edx, 0x40
// 0051b990  8bc2                 mov eax, edx
// 0051b992  5f                   pop edi
// 0051b993  f7c300001000         test ebx, 0x100000
// 0051b999  5b                   pop ebx
// 0051b99a  7411                 je 0x51b9ad
// 0051b99c  0fb64e65             movzx ecx, byte ptr [esi + 0x65]
// 0051b9a0  0fb65664             movzx edx, byte ptr [esi + 0x64]
// 0051b9a4  0fafca               imul ecx, edx
// 0051b9a7  3bc8                 cmp ecx, eax
// 0051b9a9  7e02                 jle 0x51b9ad
// 0051b9ab  8bc1                 mov eax, ecx
// 0051b9ad  8d5507               lea edx, [ebp + 7]
// 0051b9b0  83e2f8               and edx, 0xfffffff8
// 0051b9b3  83f808               cmp eax, 8
// 0051b9b6  8bc8                 mov ecx, eax
// 0051b9b8  7c08                 jl 0x51b9c2
// 0051b9ba  c1e903               shr ecx, 3
// 0051b9bd  0fafca               imul ecx, edx
// 0051b9c0  eb09                 jmp 0x51b9cb
// 0051b9c2  0fafca               imul ecx, edx
// 0051b9c5  83c107               add ecx, 7
// 0051b9c8  c1e903               shr ecx, 3
// 0051b9cb  83c007               add eax, 7
// 0051b9ce  c1f803               sar eax, 3
// 0051b9d1  8d440841             lea eax, [eax + ecx + 0x41]
// 0051b9d5  50                   push eax
// 0051b9d6  56                   push esi
// 0051b9d7  e8c4d5ffff           call 0x518fa0
// 0051b9dc  8b8ed8000000         mov ecx, dword ptr [esi + 0xd8]
// 0051b9e2  898650020000         mov dword ptr [esi + 0x250], eax
// 0051b9e8  83c020               add eax, 0x20
// 0051b9eb  83c101               add ecx, 1
// 0051b9ee  83c408               add esp, 8
// 0051b9f1  83f9ff               cmp ecx, -1
// 0051b9f4  8986ec000000         mov dword ptr [esi + 0xec], eax
// 0051b9fa  760e                 jbe 0x51ba0a
// 0051b9fc  6818377a00           push 0x7a3718
// 0051ba01  56                   push esi
// 0051ba02  e819c9ffff           call 0x518320
// 0051ba07  83c408               add esp, 8
// 0051ba0a  8b96d8000000         mov edx, dword ptr [esi + 0xd8]
// 0051ba10  83c201               add edx, 1
// 0051ba13  52                   push edx
// 0051ba14  56                   push esi
// 0051ba15  e886d5ffff           call 0x518fa0
// 0051ba1a  8b8ed8000000         mov ecx, dword ptr [esi + 0xd8]
// 0051ba20  83c101               add ecx, 1
// 0051ba23  51                   push ecx
// 0051ba24  6a00                 push 0
// 0051ba26  50                   push eax
// 0051ba27  56                   push esi
// 0051ba28  8986e8000000         mov dword ptr [esi + 0xe8], eax
// 0051ba2e  e8ddd4ffff           call 0x518f10
// 0051ba33  834e6c40             or dword ptr [esi + 0x6c], 0x40
// 0051ba37  83c418               add esp, 0x18
// 0051ba3a  5e                   pop esi
// 0051ba3b  5d                   pop ebp
// 0051ba3c  c3                   ret 
// library libpng-1.2.7/pngrutil.c (function _png_read_start_row)

// roc-lang: c
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.7 pngrutil.c
