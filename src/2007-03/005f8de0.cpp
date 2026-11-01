// from server: 100% by auto
// roc 2007-03 005f8de0  unit: seg_005f0000  size: 148 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005f8de0
//
// 005f8de0  8b460c               mov eax, dword ptr [esi + 0xc]
// 005f8de3  f6400503             test byte ptr [eax + 5], 3
// 005f8de7  740a                 je 0x5f8df3
// 005f8de9  50                   push eax
// 005f8dea  53                   push ebx
// 005f8deb  e8d0fbffff           call 0x5f89c0
// 005f8df0  83c408               add esp, 8
// 005f8df3  807e0600             cmp byte ptr [esi + 6], 0
// 005f8df7  55                   push ebp
// 005f8df8  57                   push edi
// 005f8df9  7434                 je 0x5f8e2f
// 005f8dfb  33ed                 xor ebp, ebp
// 005f8dfd  807e0700             cmp byte ptr [esi + 7], 0
// 005f8e01  766e                 jbe 0x5f8e71
// 005f8e03  8d7e18               lea edi, [esi + 0x18]
// 005f8e06  837f0804             cmp dword ptr [edi + 8], 4
// 005f8e0a  7c12                 jl 0x5f8e1e
// 005f8e0c  8b07                 mov eax, dword ptr [edi]
// 005f8e0e  f6400503             test byte ptr [eax + 5], 3
// 005f8e12  740a                 je 0x5f8e1e
// 005f8e14  50                   push eax
// 005f8e15  53                   push ebx
// 005f8e16  e8a5fbffff           call 0x5f89c0
// 005f8e1b  83c408               add esp, 8
// 005f8e1e  0fb64607             movzx eax, byte ptr [esi + 7]
// 005f8e22  83c501               add ebp, 1
// 005f8e25  83c710               add edi, 0x10
// 005f8e28  3be8                 cmp ebp, eax
// 005f8e2a  7cda                 jl 0x5f8e06
// 005f8e2c  5f                   pop edi
// 005f8e2d  5d                   pop ebp
// 005f8e2e  c3                   ret 
// 005f8e2f  8b4610               mov eax, dword ptr [esi + 0x10]
// 005f8e32  f6400503             test byte ptr [eax + 5], 3
// 005f8e36  740a                 je 0x5f8e42
// 005f8e38  50                   push eax
// 005f8e39  53                   push ebx
// 005f8e3a  e881fbffff           call 0x5f89c0
// 005f8e3f  83c408               add esp, 8
// 005f8e42  33ff                 xor edi, edi
// 005f8e44  807e0700             cmp byte ptr [esi + 7], 0
// 005f8e48  7627                 jbe 0x5f8e71
// 005f8e4a  8d6e14               lea ebp, [esi + 0x14]
// 005f8e4d  8d4900               lea ecx, [ecx]
// 005f8e50  8b4500               mov eax, dword ptr [ebp]
// 005f8e53  f6400503             test byte ptr [eax + 5], 3
// 005f8e57  740a                 je 0x5f8e63
// 005f8e59  50                   push eax
// 005f8e5a  53                   push ebx
// 005f8e5b  e860fbffff           call 0x5f89c0
// 005f8e60  83c408               add esp, 8
// 005f8e63  0fb64e07             movzx ecx, byte ptr [esi + 7]
// 005f8e67  83c701               add edi, 1
// 005f8e6a  83c504               add ebp, 4
// 005f8e6d  3bf9                 cmp edi, ecx
// 005f8e6f  7cdf                 jl 0x5f8e50
// 005f8e71  5f                   pop edi
// 005f8e72  5d                   pop ebp
// 005f8e73  c3                   ret 
// library lua-5.1.1/lgc.c (function _traverseclosure)

// roc-lang: c
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lgc.c
