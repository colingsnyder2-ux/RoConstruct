// from server: 100% by auto
// roc 2010-06 00564a20  unit: seg_00560000  size: 389 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00564a20
//
// 00564a20  51                   push ecx
// 00564a21  55                   push ebp
// 00564a22  8b6c240c             mov ebp, dword ptr [esp + 0xc]
// 00564a26  85ed                 test ebp, ebp
// 00564a28  0f8474010000         je 0x564ba2
// 00564a2e  56                   push esi
// 00564a2f  8b742414             mov esi, dword ptr [esp + 0x14]
// 00564a33  85f6                 test esi, esi
// 00564a35  0f8466010000         je 0x564ba1
// 00564a3b  8b86d8000000         mov eax, dword ptr [esi + 0xd8]
// 00564a41  53                   push ebx
// 00564a42  57                   push edi
// 00564a43  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 00564a47  03c7                 add eax, edi
// 00564a49  c1e004               shl eax, 4
// 00564a4c  50                   push eax
// 00564a4d  55                   push ebp
// 00564a4e  e8dddb0000           call 0x572630
// 00564a53  8bd8                 mov ebx, eax
// 00564a55  83c408               add esp, 8
// 00564a58  895c2410             mov dword ptr [esp + 0x10], ebx
// 00564a5c  85db                 test ebx, ebx
// 00564a5e  7514                 jne 0x564a74
// 00564a60  68c814a200           push 0xa214c8
// 00564a65  55                   push ebp
// 00564a66  e8f5d00000           call 0x571b60
// 00564a6b  83c408               add esp, 8
// 00564a6e  5f                   pop edi
// 00564a6f  5b                   pop ebx
// 00564a70  5e                   pop esi
// 00564a71  5d                   pop ebp
// 00564a72  59                   pop ecx
// 00564a73  c3                   ret 
// 00564a74  8b8ed8000000         mov ecx, dword ptr [esi + 0xd8]
// 00564a7a  8b96d4000000         mov edx, dword ptr [esi + 0xd4]
// 00564a80  c1e104               shl ecx, 4
// 00564a83  51                   push ecx
// 00564a84  52                   push edx
// 00564a85  53                   push ebx
// 00564a86  e89b432400           call 0x7a8e26
// 00564a8b  8b86d4000000         mov eax, dword ptr [esi + 0xd4]
// 00564a91  50                   push eax
// 00564a92  55                   push ebp
// 00564a93  e868db0000           call 0x572600
// 00564a98  33c0                 xor eax, eax
// 00564a9a  83c414               add esp, 0x14
// 00564a9d  3bf8                 cmp edi, eax
// 00564a9f  8986d4000000         mov dword ptr [esi + 0xd4], eax
// 00564aa5  89442418             mov dword ptr [esp + 0x18], eax
// 00564aa9  0f8ed6000000         jle 0x564b85
// 00564aaf  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00564ab3  83c70c               add edi, 0xc
// 00564ab6  eb08                 jmp 0x564ac0
// 00564ab8  8da42400000000       lea esp, [esp]
// 00564abf  90                   nop 
// 00564ac0  8bb6d8000000         mov esi, dword ptr [esi + 0xd8]
// 00564ac6  03742418             add esi, dword ptr [esp + 0x18]
// 00564aca  8b47f4               mov eax, dword ptr [edi - 0xc]
// 00564acd  c1e604               shl esi, 4
// 00564ad0  03f3                 add esi, ebx
// 00564ad2  8d5001               lea edx, [eax + 1]
// 00564ad5  8a08                 mov cl, byte ptr [eax]
// 00564ad7  40                   inc eax
// 00564ad8  84c9                 test cl, cl
// 00564ada  75f9                 jne 0x564ad5
// 00564adc  2bc2                 sub eax, edx
// 00564ade  8d5801               lea ebx, [eax + 1]
// 00564ae1  53                   push ebx
// 00564ae2  55                   push ebp
// 00564ae3  e848db0000           call 0x572630
// 00564ae8  83c408               add esp, 8
// 00564aeb  8906                 mov dword ptr [esi], eax
// 00564aed  85c0                 test eax, eax
// 00564aef  7510                 jne 0x564b01
// 00564af1  689c14a200           push 0xa2149c
// 00564af6  55                   push ebp
// 00564af7  e864d00000           call 0x571b60
// 00564afc  83c408               add esp, 8
// 00564aff  eb62                 jmp 0x564b63
// 00564b01  8b4ff4               mov ecx, dword ptr [edi - 0xc]
// 00564b04  53                   push ebx
// 00564b05  51                   push ecx
// 00564b06  50                   push eax
// 00564b07  e81a432400           call 0x7a8e26
// 00564b0c  8b07                 mov eax, dword ptr [edi]
// 00564b0e  8d1480               lea edx, [eax + eax*4]
// 00564b11  03d2                 add edx, edx
// 00564b13  52                   push edx
// 00564b14  55                   push ebp
// 00564b15  e816db0000           call 0x572630
// 00564b1a  83c414               add esp, 0x14
// 00564b1d  894608               mov dword ptr [esi + 8], eax
// 00564b20  85c0                 test eax, eax
// 00564b22  751f                 jne 0x564b43
// 00564b24  689c14a200           push 0xa2149c
// 00564b29  55                   push ebp
// 00564b2a  e831d00000           call 0x571b60
// 00564b2f  8b06                 mov eax, dword ptr [esi]
// 00564b31  50                   push eax
// 00564b32  55                   push ebp
// 00564b33  e8c8da0000           call 0x572600
// 00564b38  83c410               add esp, 0x10
// 00564b3b  c70600000000         mov dword ptr [esi], 0
// 00564b41  eb20                 jmp 0x564b63
// 00564b43  8b0f                 mov ecx, dword ptr [edi]
// 00564b45  8b57fc               mov edx, dword ptr [edi - 4]
// 00564b48  8d0c89               lea ecx, [ecx + ecx*4]
// 00564b4b  03c9                 add ecx, ecx
// 00564b4d  51                   push ecx
// 00564b4e  52                   push edx
// 00564b4f  50                   push eax
// 00564b50  e8d1422400           call 0x7a8e26
// 00564b55  8b07                 mov eax, dword ptr [edi]
// 00564b57  89460c               mov dword ptr [esi + 0xc], eax
// 00564b5a  8a4ff8               mov cl, byte ptr [edi - 8]
// 00564b5d  83c40c               add esp, 0xc
// 00564b60  884e04               mov byte ptr [esi + 4], cl
// 00564b63  8b442418             mov eax, dword ptr [esp + 0x18]
// 00564b67  8b74241c             mov esi, dword ptr [esp + 0x1c]
// 00564b6b  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 00564b6f  40                   inc eax
// 00564b70  83c710               add edi, 0x10
// 00564b73  3b442424             cmp eax, dword ptr [esp + 0x24]
// 00564b77  89442418             mov dword ptr [esp + 0x18], eax
// 00564b7b  0f8c3fffffff         jl 0x564ac0
// 00564b81  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 00564b85  01bed8000000         add dword ptr [esi + 0xd8], edi
// 00564b8b  814e0800200000       or dword ptr [esi + 8], 0x2000
// 00564b92  838eb800000020       or dword ptr [esi + 0xb8], 0x20
// 00564b99  5f                   pop edi
// 00564b9a  899ed4000000         mov dword ptr [esi + 0xd4], ebx
// 00564ba0  5b                   pop ebx
// 00564ba1  5e                   pop esi
// 00564ba2  5d                   pop ebp
// 00564ba3  59                   pop ecx
// 00564ba4  c3                   ret 
// library libpng-1.2.29/pngset.c (function _png_set_sPLT)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.29 pngset.c
