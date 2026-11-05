// from server: 100% by auto
// roc 2012-06 0063b290  unit: G3D::_internal::DialogTemplate  size: 215 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0063b290
//
// 0063b290  56                   push esi
// 0063b291  8bf1                 mov esi, ecx
// 0063b293  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0063b297  57                   push edi
// 0063b298  8b7e04               mov edi, dword ptr [esi + 4]
// 0063b29b  3bf9                 cmp edi, ecx
// 0063b29d  0f84bf000000         je 0x63b362
// 0063b2a3  8b5608               mov edx, dword ptr [esi + 8]
// 0063b2a6  53                   push ebx
// 0063b2a7  33db                 xor ebx, ebx
// 0063b2a9  3bca                 cmp ecx, edx
// 0063b2ab  894e04               mov dword ptr [esi + 4], ecx
// 0063b2ae  7e65                 jle 0x63b315
// 0063b2b0  3bd3                 cmp edx, ebx
// 0063b2b2  7506                 jne 0x63b2ba
// 0063b2b4  894e08               mov dword ptr [esi + 8], ecx
// 0063b2b7  57                   push edi
// 0063b2b8  eb7f                 jmp 0x63b339
// 0063b2ba  ba0a000000           mov edx, 0xa
// 0063b2bf  3bca                 cmp ecx, edx
// 0063b2c1  7c4c                 jl 0x63b30f
// 0063b2c3  8b4608               mov eax, dword ptr [esi + 8]
// 0063b2c6  f30f1005dc48b600     movss xmm0, dword ptr [0xb648dc]
// 0063b2ce  03c0                 add eax, eax
// 0063b2d0  03c0                 add eax, eax
// 0063b2d2  3d801a0600           cmp eax, 0x61a80
// 0063b2d7  7e0a                 jle 0x63b2e3
// 0063b2d9  f30f1005d848b600     movss xmm0, dword ptr [0xb648d8]
// 0063b2e1  eb0f                 jmp 0x63b2f2
// 0063b2e3  3d00fa0000           cmp eax, 0xfa00
// 0063b2e8  7e08                 jle 0x63b2f2
// 0063b2ea  f30f10056832b600     movss xmm0, dword ptr [0xb63268]
// 0063b2f2  8b4608               mov eax, dword ptr [esi + 8]
// 0063b2f5  55                   push ebp
// 0063b2f6  f30f2ac8             cvtsi2ss xmm1, eax
// 0063b2fa  f30f59c8             mulss xmm1, xmm0
// 0063b2fe  f30f2ce9             cvttss2si ebp, xmm1
// 0063b302  2be8                 sub ebp, eax
// 0063b304  8d0429               lea eax, [ecx + ebp]
// 0063b307  3bc2                 cmp eax, edx
// 0063b309  894608               mov dword ptr [esi + 8], eax
// 0063b30c  5d                   pop ebp
// 0063b30d  7d03                 jge 0x63b312
// 0063b30f  895608               mov dword ptr [esi + 8], edx
// 0063b312  57                   push edi
// 0063b313  eb24                 jmp 0x63b339
// 0063b315  b856555555           mov eax, 0x55555556
// 0063b31a  f7ea                 imul edx
// 0063b31c  8bc2                 mov eax, edx
// 0063b31e  c1e81f               shr eax, 0x1f
// 0063b321  03c2                 add eax, edx
// 0063b323  3bc8                 cmp ecx, eax
// 0063b325  7f19                 jg 0x63b340
// 0063b327  385c2414             cmp byte ptr [esp + 0x14], bl
// 0063b32b  7413                 je 0x63b340
// 0063b32d  83f90a               cmp ecx, 0xa
// 0063b330  7e0e                 jle 0x63b340
// 0063b332  3bcf                 cmp ecx, edi
// 0063b334  7c02                 jl 0x63b338
// 0063b336  8bcf                 mov ecx, edi
// 0063b338  51                   push ecx
// 0063b339  8bce                 mov ecx, esi
// 0063b33b  e830feffff           call 0x63b170
// 0063b340  3b7e04               cmp edi, dword ptr [esi + 4]
// 0063b343  8bcf                 mov ecx, edi
// 0063b345  7d1a                 jge 0x63b361
// 0063b347  8b16                 mov edx, dword ptr [esi]
// 0063b349  8d048a               lea eax, [edx + ecx*4]
// 0063b34c  3bc3                 cmp eax, ebx
// 0063b34e  740b                 je 0x63b35b
// 0063b350  8818                 mov byte ptr [eax], bl
// 0063b352  885801               mov byte ptr [eax + 1], bl
// 0063b355  885802               mov byte ptr [eax + 2], bl
// 0063b358  885803               mov byte ptr [eax + 3], bl
// 0063b35b  41                   inc ecx
// 0063b35c  3b4e04               cmp ecx, dword ptr [esi + 4]
// 0063b35f  7ce6                 jl 0x63b347
// 0063b361  5b                   pop ebx
// 0063b362  5f                   pop edi
// 0063b363  5e                   pop esi
// 0063b364  c20800               ret 8
// library rbx2016-g3d/GImage_bmp.cpp (function ?resize@?$Array@VColor4uint8@G3D@@$09$0CA@@G3D@@QAEXH_N@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /arch:SSE2 /fp:fast
// roc-lib: rbx2016-g3d GImage_bmp.cpp
