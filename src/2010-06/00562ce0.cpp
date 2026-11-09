// from server: 100% by auto
// roc 2010-06 00562ce0  unit: G3D::_internal::DialogTemplate  size: 360 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00562ce0
//
// 00562ce0  55                   push ebp
// 00562ce1  8b6c2408             mov ebp, dword ptr [esp + 8]
// 00562ce5  85ed                 test ebp, ebp
// 00562ce7  0f8459010000         je 0x562e46
// 00562ced  f6456804             test byte ptr [ebp + 0x68], 4
// 00562cf1  750e                 jne 0x562d01
// 00562cf3  68c00ea200           push 0xa20ec0
// 00562cf8  55                   push ebp
// 00562cf9  e8b2ed0000           call 0x571ab0
// 00562cfe  83c408               add esp, 8
// 00562d01  56                   push esi
// 00562d02  8b742410             mov esi, dword ptr [esp + 0x10]
// 00562d06  85f6                 test esi, esi
// 00562d08  0f842a010000         je 0x562e38
// 00562d0e  b800020000           mov eax, 0x200
// 00562d13  854608               test dword ptr [esi + 8], eax
// 00562d16  7412                 je 0x562d2a
// 00562d18  854568               test dword ptr [ebp + 0x68], eax
// 00562d1b  750d                 jne 0x562d2a
// 00562d1d  8d463c               lea eax, [esi + 0x3c]
// 00562d20  50                   push eax
// 00562d21  55                   push ebp
// 00562d22  e869db0000           call 0x570890
// 00562d27  83c408               add esp, 8
// 00562d2a  53                   push ebx
// 00562d2b  33db                 xor ebx, ebx
// 00562d2d  395e30               cmp dword ptr [esi + 0x30], ebx
// 00562d30  57                   push edi
// 00562d31  0f8e88000000         jle 0x562dbf
// 00562d37  33ff                 xor edi, edi
// 00562d39  8da42400000000       lea esp, [esp]
// 00562d40  8b4e38               mov ecx, dword ptr [esi + 0x38]
// 00562d43  8b040f               mov eax, dword ptr [edi + ecx]
// 00562d46  85c0                 test eax, eax
// 00562d48  7e1a                 jle 0x562d64
// 00562d4a  68700ea200           push 0xa20e70
// 00562d4f  55                   push ebp
// 00562d50  e80bee0000           call 0x571b60
// 00562d55  8b5638               mov edx, dword ptr [esi + 0x38]
// 00562d58  83c408               add esp, 8
// 00562d5b  c70417fdffffff       mov dword ptr [edi + edx], 0xfffffffd
// 00562d62  eb52                 jmp 0x562db6
// 00562d64  7c28                 jl 0x562d8e
// 00562d66  8bc1                 mov eax, ecx
// 00562d68  8b0c38               mov ecx, dword ptr [eax + edi]
// 00562d6b  8b543808             mov edx, dword ptr [eax + edi + 8]
// 00562d6f  03c7                 add eax, edi
// 00562d71  8b4004               mov eax, dword ptr [eax + 4]
// 00562d74  51                   push ecx
// 00562d75  6a00                 push 0
// 00562d77  52                   push edx
// 00562d78  50                   push eax
// 00562d79  55                   push ebp
// 00562d7a  e8d1bd0000           call 0x56eb50
// 00562d7f  8b4e38               mov ecx, dword ptr [esi + 0x38]
// 00562d82  83c414               add esp, 0x14
// 00562d85  c7040ffeffffff       mov dword ptr [edi + ecx], 0xfffffffe
// 00562d8c  eb28                 jmp 0x562db6
// 00562d8e  83f8ff               cmp eax, -1
// 00562d91  7523                 jne 0x562db6
// 00562d93  8bd1                 mov edx, ecx
// 00562d95  8b4c3a08             mov ecx, dword ptr [edx + edi + 8]
// 00562d99  8d043a               lea eax, [edx + edi]
// 00562d9c  8b5004               mov edx, dword ptr [eax + 4]
// 00562d9f  6a00                 push 0
// 00562da1  51                   push ecx
// 00562da2  52                   push edx
// 00562da3  55                   push ebp
// 00562da4  e8c7bc0000           call 0x56ea70
// 00562da9  8b4638               mov eax, dword ptr [esi + 0x38]
// 00562dac  83c410               add esp, 0x10
// 00562daf  c70407fdffffff       mov dword ptr [edi + eax], 0xfffffffd
// 00562db6  43                   inc ebx
// 00562db7  83c710               add edi, 0x10
// 00562dba  3b5e30               cmp ebx, dword ptr [esi + 0x30]
// 00562dbd  7c81                 jl 0x562d40
// 00562dbf  8b86c0000000         mov eax, dword ptr [esi + 0xc0]
// 00562dc5  85c0                 test eax, eax
// 00562dc7  746d                 je 0x562e36
// 00562dc9  8bbebc000000         mov edi, dword ptr [esi + 0xbc]
// 00562dcf  8d0c80               lea ecx, [eax + eax*4]
// 00562dd2  8d148f               lea edx, [edi + ecx*4]
// 00562dd5  3bfa                 cmp edi, edx
// 00562dd7  735d                 jae 0x562e36
// 00562dd9  bb00000100           mov ebx, 0x10000
// 00562dde  8bff                 mov edi, edi
// 00562de0  57                   push edi
// 00562de1  55                   push ebp
// 00562de2  e869260000           call 0x565450
// 00562de7  83c408               add esp, 8
// 00562dea  83f801               cmp eax, 1
// 00562ded  742e                 je 0x562e1d
// 00562def  8a4f10               mov cl, byte ptr [edi + 0x10]
// 00562df2  84c9                 test cl, cl
// 00562df4  7427                 je 0x562e1d
// 00562df6  f6c108               test cl, 8
// 00562df9  7422                 je 0x562e1d
// 00562dfb  f6470320             test byte ptr [edi + 3], 0x20
// 00562dff  750a                 jne 0x562e0b
// 00562e01  83f803               cmp eax, 3
// 00562e04  7405                 je 0x562e0b
// 00562e06  855d6c               test dword ptr [ebp + 0x6c], ebx
// 00562e09  7412                 je 0x562e1d
// 00562e0b  8b470c               mov eax, dword ptr [edi + 0xc]
// 00562e0e  8b4f08               mov ecx, dword ptr [edi + 8]
// 00562e11  50                   push eax
// 00562e12  51                   push ecx
// 00562e13  57                   push edi
// 00562e14  55                   push ebp
// 00562e15  e876c50000           call 0x56f390
// 00562e1a  83c410               add esp, 0x10
// 00562e1d  8b86c0000000         mov eax, dword ptr [esi + 0xc0]
// 00562e23  8d1480               lea edx, [eax + eax*4]
// 00562e26  8b86bc000000         mov eax, dword ptr [esi + 0xbc]
// 00562e2c  83c714               add edi, 0x14
// 00562e2f  8d0c90               lea ecx, [eax + edx*4]
// 00562e32  3bf9                 cmp edi, ecx
// 00562e34  72aa                 jb 0x562de0
// 00562e36  5f                   pop edi
// 00562e37  5b                   pop ebx
// 00562e38  834d6808             or dword ptr [ebp + 0x68], 8
// 00562e3c  55                   push ebp
// 00562e3d  e84ecb0000           call 0x56f990
// 00562e42  83c404               add esp, 4
// 00562e45  5e                   pop esi
// 00562e46  5d                   pop ebp
// 00562e47  c3                   ret 
// library libpng-1.2.10/pngwrite.c (function _png_write_end)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.10 pngwrite.c
