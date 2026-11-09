// from server: 100% by auto
// roc 2012-06 00645950  unit: seg_00640000  size: 360 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00645950
//
// 00645950  55                   push ebp
// 00645951  8b6c2408             mov ebp, dword ptr [esp + 8]
// 00645955  85ed                 test ebp, ebp
// 00645957  0f8459010000         je 0x645ab6
// 0064595d  f6456804             test byte ptr [ebp + 0x68], 4
// 00645961  750e                 jne 0x645971
// 00645963  68945eb800           push 0xb85e94
// 00645968  55                   push ebp
// 00645969  e842880000           call 0x64e1b0
// 0064596e  83c408               add esp, 8
// 00645971  56                   push esi
// 00645972  8b742410             mov esi, dword ptr [esp + 0x10]
// 00645976  85f6                 test esi, esi
// 00645978  0f842a010000         je 0x645aa8
// 0064597e  b800020000           mov eax, 0x200
// 00645983  854608               test dword ptr [esi + 8], eax
// 00645986  7412                 je 0x64599a
// 00645988  854568               test dword ptr [ebp + 0x68], eax
// 0064598b  750d                 jne 0x64599a
// 0064598d  8d463c               lea eax, [esi + 0x3c]
// 00645990  50                   push eax
// 00645991  55                   push ebp
// 00645992  e8592d0100           call 0x6586f0
// 00645997  83c408               add esp, 8
// 0064599a  53                   push ebx
// 0064599b  33db                 xor ebx, ebx
// 0064599d  395e30               cmp dword ptr [esi + 0x30], ebx
// 006459a0  57                   push edi
// 006459a1  0f8e88000000         jle 0x645a2f
// 006459a7  33ff                 xor edi, edi
// 006459a9  8da42400000000       lea esp, [esp]
// 006459b0  8b4e38               mov ecx, dword ptr [esi + 0x38]
// 006459b3  8b040f               mov eax, dword ptr [edi + ecx]
// 006459b6  85c0                 test eax, eax
// 006459b8  7e1a                 jle 0x6459d4
// 006459ba  68445eb800           push 0xb85e44
// 006459bf  55                   push ebp
// 006459c0  e89b880000           call 0x64e260
// 006459c5  8b5638               mov edx, dword ptr [esi + 0x38]
// 006459c8  83c408               add esp, 8
// 006459cb  c70417fdffffff       mov dword ptr [edi + edx], 0xfffffffd
// 006459d2  eb52                 jmp 0x645a26
// 006459d4  7c28                 jl 0x6459fe
// 006459d6  8bc1                 mov eax, ecx
// 006459d8  8b0c38               mov ecx, dword ptr [eax + edi]
// 006459db  8b543808             mov edx, dword ptr [eax + edi + 8]
// 006459df  03c7                 add eax, edi
// 006459e1  8b4004               mov eax, dword ptr [eax + 4]
// 006459e4  51                   push ecx
// 006459e5  6a00                 push 0
// 006459e7  52                   push edx
// 006459e8  50                   push eax
// 006459e9  55                   push ebp
// 006459ea  e811100100           call 0x656a00
// 006459ef  8b4e38               mov ecx, dword ptr [esi + 0x38]
// 006459f2  83c414               add esp, 0x14
// 006459f5  c7040ffeffffff       mov dword ptr [edi + ecx], 0xfffffffe
// 006459fc  eb28                 jmp 0x645a26
// 006459fe  83f8ff               cmp eax, -1
// 00645a01  7523                 jne 0x645a26
// 00645a03  8bd1                 mov edx, ecx
// 00645a05  8b4c3a08             mov ecx, dword ptr [edx + edi + 8]
// 00645a09  8d043a               lea eax, [edx + edi]
// 00645a0c  8b5004               mov edx, dword ptr [eax + 4]
// 00645a0f  6a00                 push 0
// 00645a11  51                   push ecx
// 00645a12  52                   push edx
// 00645a13  55                   push ebp
// 00645a14  e8d70e0100           call 0x6568f0
// 00645a19  8b4638               mov eax, dword ptr [esi + 0x38]
// 00645a1c  83c410               add esp, 0x10
// 00645a1f  c70407fdffffff       mov dword ptr [edi + eax], 0xfffffffd
// 00645a26  43                   inc ebx
// 00645a27  83c710               add edi, 0x10
// 00645a2a  3b5e30               cmp ebx, dword ptr [esi + 0x30]
// 00645a2d  7c81                 jl 0x6459b0
// 00645a2f  8b86c0000000         mov eax, dword ptr [esi + 0xc0]
// 00645a35  85c0                 test eax, eax
// 00645a37  746d                 je 0x645aa6
// 00645a39  8bbebc000000         mov edi, dword ptr [esi + 0xbc]
// 00645a3f  8d0c80               lea ecx, [eax + eax*4]
// 00645a42  8d148f               lea edx, [edi + ecx*4]
// 00645a45  3bfa                 cmp edi, edx
// 00645a47  735d                 jae 0x645aa6
// 00645a49  bb00000100           mov ebx, 0x10000
// 00645a4e  8bff                 mov edi, edi
// 00645a50  57                   push edi
// 00645a51  55                   push ebp
// 00645a52  e8a988ffff           call 0x63e300
// 00645a57  83c408               add esp, 8
// 00645a5a  83f801               cmp eax, 1
// 00645a5d  742e                 je 0x645a8d
// 00645a5f  8a4f10               mov cl, byte ptr [edi + 0x10]
// 00645a62  84c9                 test cl, cl
// 00645a64  7427                 je 0x645a8d
// 00645a66  f6c108               test cl, 8
// 00645a69  7422                 je 0x645a8d
// 00645a6b  f6470320             test byte ptr [edi + 3], 0x20
// 00645a6f  750a                 jne 0x645a7b
// 00645a71  83f803               cmp eax, 3
// 00645a74  7405                 je 0x645a7b
// 00645a76  855d6c               test dword ptr [ebp + 0x6c], ebx
// 00645a79  7412                 je 0x645a8d
// 00645a7b  8b470c               mov eax, dword ptr [edi + 0xc]
// 00645a7e  8b4f08               mov ecx, dword ptr [edi + 8]
// 00645a81  50                   push eax
// 00645a82  51                   push ecx
// 00645a83  57                   push edi
// 00645a84  55                   push ebp
// 00645a85  e896170100           call 0x657220
// 00645a8a  83c410               add esp, 0x10
// 00645a8d  8b86c0000000         mov eax, dword ptr [esi + 0xc0]
// 00645a93  8d1480               lea edx, [eax + eax*4]
// 00645a96  8b86bc000000         mov eax, dword ptr [esi + 0xbc]
// 00645a9c  83c714               add edi, 0x14
// 00645a9f  8d0c90               lea ecx, [eax + edx*4]
// 00645aa2  3bf9                 cmp edi, ecx
// 00645aa4  72aa                 jb 0x645a50
// 00645aa6  5f                   pop edi
// 00645aa7  5b                   pop ebx
// 00645aa8  834d6808             or dword ptr [ebp + 0x68], 8
// 00645aac  55                   push ebp
// 00645aad  e86e1d0100           call 0x657820
// 00645ab2  83c404               add esp, 4
// 00645ab5  5e                   pop esi
// 00645ab6  5d                   pop ebp
// 00645ab7  c3                   ret 
// library libpng-1.2.10/pngwrite.c (function _png_write_end)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.10 pngwrite.c
