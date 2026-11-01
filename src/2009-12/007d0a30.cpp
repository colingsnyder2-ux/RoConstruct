// from server: 100% by auto
// roc 2009-12 007d0a30  unit: RBX::PartDropTool  size: 189 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007d0a30
//
// 007d0a30  51                   push ecx
// 007d0a31  57                   push edi
// 007d0a32  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 007d0a36  8b4710               mov eax, dword ptr [edi + 0x10]
// 007d0a39  80781502             cmp byte ptr [eax + 0x15], 2
// 007d0a3d  0f84a7000000         je 0x7d0aea
// 007d0a43  53                   push ebx
// 007d0a44  55                   push ebp
// 007d0a45  8b6c2418             mov ebp, dword ptr [esp + 0x18]
// 007d0a49  8d4d01               lea ecx, [ebp + 1]
// 007d0a4c  56                   push esi
// 007d0a4d  81f9ffffff3f         cmp ecx, 0x3fffffff
// 007d0a53  7717                 ja 0x7d0a6c
// 007d0a55  8d14ad00000000       lea edx, [ebp*4]
// 007d0a5c  52                   push edx
// 007d0a5d  6a00                 push 0
// 007d0a5f  6a00                 push 0
// 007d0a61  57                   push edi
// 007d0a62  e8490d0000           call 0x7d17b0
// 007d0a67  83c410               add esp, 0x10
// 007d0a6a  eb09                 jmp 0x7d0a75
// 007d0a6c  57                   push edi
// 007d0a6d  e81e0d0000           call 0x7d1790
// 007d0a72  83c404               add esp, 4
// 007d0a75  8b5f10               mov ebx, dword ptr [edi + 0x10]
// 007d0a78  8bf0                 mov esi, eax
// 007d0a7a  85ed                 test ebp, ebp
// 007d0a7c  7e0c                 jle 0x7d0a8a
// 007d0a7e  8bcd                 mov ecx, ebp
// 007d0a80  33c0                 xor eax, eax
// 007d0a82  8bfe                 mov edi, esi
// 007d0a84  f3ab                 rep stosd dword ptr es:[edi], eax
// 007d0a86  8b7c2418             mov edi, dword ptr [esp + 0x18]
// 007d0a8a  33c9                 xor ecx, ecx
// 007d0a8c  394b08               cmp dword ptr [ebx + 8], ecx
// 007d0a8f  894c2410             mov dword ptr [esp + 0x10], ecx
// 007d0a93  7e37                 jle 0x7d0acc
// 007d0a95  8b03                 mov eax, dword ptr [ebx]
// 007d0a97  8b0488               mov eax, dword ptr [eax + ecx*4]
// 007d0a9a  85c0                 test eax, eax
// 007d0a9c  7424                 je 0x7d0ac2
// 007d0a9e  8d7dff               lea edi, [ebp - 1]
// 007d0aa1  8b4808               mov ecx, dword ptr [eax + 8]
// 007d0aa4  8b10                 mov edx, dword ptr [eax]
// 007d0aa6  23cf                 and ecx, edi
// 007d0aa8  8b2c8e               mov ebp, dword ptr [esi + ecx*4]
// 007d0aab  8928                 mov dword ptr [eax], ebp
// 007d0aad  89048e               mov dword ptr [esi + ecx*4], eax
// 007d0ab0  8bc2                 mov eax, edx
// 007d0ab2  85d2                 test edx, edx
// 007d0ab4  75eb                 jne 0x7d0aa1
// 007d0ab6  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 007d0aba  8b6c241c             mov ebp, dword ptr [esp + 0x1c]
// 007d0abe  8b7c2418             mov edi, dword ptr [esp + 0x18]
// 007d0ac2  41                   inc ecx
// 007d0ac3  3b4b08               cmp ecx, dword ptr [ebx + 8]
// 007d0ac6  894c2410             mov dword ptr [esp + 0x10], ecx
// 007d0aca  7cc9                 jl 0x7d0a95
// 007d0acc  8b4b08               mov ecx, dword ptr [ebx + 8]
// 007d0acf  8b13                 mov edx, dword ptr [ebx]
// 007d0ad1  03c9                 add ecx, ecx
// 007d0ad3  6a00                 push 0
// 007d0ad5  03c9                 add ecx, ecx
// 007d0ad7  51                   push ecx
// 007d0ad8  52                   push edx
// 007d0ad9  57                   push edi
// 007d0ada  e8d10c0000           call 0x7d17b0
// 007d0adf  83c410               add esp, 0x10
// 007d0ae2  8933                 mov dword ptr [ebx], esi
// 007d0ae4  5e                   pop esi
// 007d0ae5  896b08               mov dword ptr [ebx + 8], ebp
// 007d0ae8  5d                   pop ebp
// 007d0ae9  5b                   pop ebx
// 007d0aea  5f                   pop edi
// 007d0aeb  59                   pop ecx
// 007d0aec  c3                   ret 
// library lua-5.1/lstring.c (function _luaS_resize)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lstring.c
