// from server: 100% by auto
// roc 2011-06 00558ad0  unit: seg_00550000  size: 360 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00558ad0
//
// 00558ad0  55                   push ebp
// 00558ad1  8b6c2408             mov ebp, dword ptr [esp + 8]
// 00558ad5  85ed                 test ebp, ebp
// 00558ad7  0f8459010000         je 0x558c36
// 00558add  f6456804             test byte ptr [ebp + 0x68], 4
// 00558ae1  750e                 jne 0x558af1
// 00558ae3  68ec1fa800           push 0xa81fec
// 00558ae8  55                   push ebp
// 00558ae9  e842880000           call 0x561330
// 00558aee  83c408               add esp, 8
// 00558af1  56                   push esi
// 00558af2  8b742410             mov esi, dword ptr [esp + 0x10]
// 00558af6  85f6                 test esi, esi
// 00558af8  0f842a010000         je 0x558c28
// 00558afe  b800020000           mov eax, 0x200
// 00558b03  854608               test dword ptr [esi + 8], eax
// 00558b06  7412                 je 0x558b1a
// 00558b08  854568               test dword ptr [ebp + 0x68], eax
// 00558b0b  750d                 jne 0x558b1a
// 00558b0d  8d463c               lea eax, [esi + 0x3c]
// 00558b10  50                   push eax
// 00558b11  55                   push ebp
// 00558b12  e8c9440100           call 0x56cfe0
// 00558b17  83c408               add esp, 8
// 00558b1a  53                   push ebx
// 00558b1b  33db                 xor ebx, ebx
// 00558b1d  395e30               cmp dword ptr [esi + 0x30], ebx
// 00558b20  57                   push edi
// 00558b21  0f8e88000000         jle 0x558baf
// 00558b27  33ff                 xor edi, edi
// 00558b29  8da42400000000       lea esp, [esp]
// 00558b30  8b4e38               mov ecx, dword ptr [esi + 0x38]
// 00558b33  8b040f               mov eax, dword ptr [edi + ecx]
// 00558b36  85c0                 test eax, eax
// 00558b38  7e1a                 jle 0x558b54
// 00558b3a  689c1fa800           push 0xa81f9c
// 00558b3f  55                   push ebp
// 00558b40  e89b880000           call 0x5613e0
// 00558b45  8b5638               mov edx, dword ptr [esi + 0x38]
// 00558b48  83c408               add esp, 8
// 00558b4b  c70417fdffffff       mov dword ptr [edi + edx], 0xfffffffd
// 00558b52  eb52                 jmp 0x558ba6
// 00558b54  7c28                 jl 0x558b7e
// 00558b56  8bc1                 mov eax, ecx
// 00558b58  8b0c38               mov ecx, dword ptr [eax + edi]
// 00558b5b  8b543808             mov edx, dword ptr [eax + edi + 8]
// 00558b5f  03c7                 add eax, edi
// 00558b61  8b4004               mov eax, dword ptr [eax + 4]
// 00558b64  51                   push ecx
// 00558b65  6a00                 push 0
// 00558b67  52                   push edx
// 00558b68  50                   push eax
// 00558b69  55                   push ebp
// 00558b6a  e881270100           call 0x56b2f0
// 00558b6f  8b4e38               mov ecx, dword ptr [esi + 0x38]
// 00558b72  83c414               add esp, 0x14
// 00558b75  c7040ffeffffff       mov dword ptr [edi + ecx], 0xfffffffe
// 00558b7c  eb28                 jmp 0x558ba6
// 00558b7e  83f8ff               cmp eax, -1
// 00558b81  7523                 jne 0x558ba6
// 00558b83  8bd1                 mov edx, ecx
// 00558b85  8b4c3a08             mov ecx, dword ptr [edx + edi + 8]
// 00558b89  8d043a               lea eax, [edx + edi]
// 00558b8c  8b5004               mov edx, dword ptr [eax + 4]
// 00558b8f  6a00                 push 0
// 00558b91  51                   push ecx
// 00558b92  52                   push edx
// 00558b93  55                   push ebp
// 00558b94  e847260100           call 0x56b1e0
// 00558b99  8b4638               mov eax, dword ptr [esi + 0x38]
// 00558b9c  83c410               add esp, 0x10
// 00558b9f  c70407fdffffff       mov dword ptr [edi + eax], 0xfffffffd
// 00558ba6  43                   inc ebx
// 00558ba7  83c710               add edi, 0x10
// 00558baa  3b5e30               cmp ebx, dword ptr [esi + 0x30]
// 00558bad  7c81                 jl 0x558b30
// 00558baf  8b86c0000000         mov eax, dword ptr [esi + 0xc0]
// 00558bb5  85c0                 test eax, eax
// 00558bb7  746d                 je 0x558c26
// 00558bb9  8bbebc000000         mov edi, dword ptr [esi + 0xbc]
// 00558bbf  8d0c80               lea ecx, [eax + eax*4]
// 00558bc2  8d148f               lea edx, [edi + ecx*4]
// 00558bc5  3bfa                 cmp edi, edx
// 00558bc7  735d                 jae 0x558c26
// 00558bc9  bb00000100           mov ebx, 0x10000
// 00558bce  8bff                 mov edi, edi
// 00558bd0  57                   push edi
// 00558bd1  55                   push ebp
// 00558bd2  e8e980ffff           call 0x550cc0
// 00558bd7  83c408               add esp, 8
// 00558bda  83f801               cmp eax, 1
// 00558bdd  742e                 je 0x558c0d
// 00558bdf  8a4f10               mov cl, byte ptr [edi + 0x10]
// 00558be2  84c9                 test cl, cl
// 00558be4  7427                 je 0x558c0d
// 00558be6  f6c108               test cl, 8
// 00558be9  7422                 je 0x558c0d
// 00558beb  f6470320             test byte ptr [edi + 3], 0x20
// 00558bef  750a                 jne 0x558bfb
// 00558bf1  83f803               cmp eax, 3
// 00558bf4  7405                 je 0x558bfb
// 00558bf6  855d6c               test dword ptr [ebp + 0x6c], ebx
// 00558bf9  7412                 je 0x558c0d
// 00558bfb  8b470c               mov eax, dword ptr [edi + 0xc]
// 00558bfe  8b4f08               mov ecx, dword ptr [edi + 8]
// 00558c01  50                   push eax
// 00558c02  51                   push ecx
// 00558c03  57                   push edi
// 00558c04  55                   push ebp
// 00558c05  e8062f0100           call 0x56bb10
// 00558c0a  83c410               add esp, 0x10
// 00558c0d  8b86c0000000         mov eax, dword ptr [esi + 0xc0]
// 00558c13  8d1480               lea edx, [eax + eax*4]
// 00558c16  8b86bc000000         mov eax, dword ptr [esi + 0xbc]
// 00558c1c  83c714               add edi, 0x14
// 00558c1f  8d0c90               lea ecx, [eax + edx*4]
// 00558c22  3bf9                 cmp edi, ecx
// 00558c24  72aa                 jb 0x558bd0
// 00558c26  5f                   pop edi
// 00558c27  5b                   pop ebx
// 00558c28  834d6808             or dword ptr [ebp + 0x68], 8
// 00558c2c  55                   push ebp
// 00558c2d  e8de340100           call 0x56c110
// 00558c32  83c404               add esp, 4
// 00558c35  5e                   pop esi
// 00558c36  5d                   pop ebp
// 00558c37  c3                   ret 
// library libpng-1.2.10/pngwrite.c (function _png_write_end)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.10 pngwrite.c
