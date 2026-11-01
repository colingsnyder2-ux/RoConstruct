// from server: 100% by auto
// roc 2007-03 005f8e80  unit: seg_005f0000  size: 231 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005f8e80
//
// 005f8e80  837f5004             cmp dword ptr [edi + 0x50], 4
// 005f8e84  7c17                 jl 0x5f8e9d
// 005f8e86  8b4748               mov eax, dword ptr [edi + 0x48]
// 005f8e89  f6400503             test byte ptr [eax + 5], 3
// 005f8e8d  740e                 je 0x5f8e9d
// 005f8e8f  50                   push eax
// 005f8e90  8b442408             mov eax, dword ptr [esp + 8]
// 005f8e94  50                   push eax
// 005f8e95  e826fbffff           call 0x5f89c0
// 005f8e9a  83c408               add esp, 8
// 005f8e9d  8b4728               mov eax, dword ptr [edi + 0x28]
// 005f8ea0  8b5714               mov edx, dword ptr [edi + 0x14]
// 005f8ea3  3bc2                 cmp eax, edx
// 005f8ea5  53                   push ebx
// 005f8ea6  8b5f08               mov ebx, dword ptr [edi + 8]
// 005f8ea9  55                   push ebp
// 005f8eaa  56                   push esi
// 005f8eab  8beb                 mov ebp, ebx
// 005f8ead  7711                 ja 0x5f8ec0
// 005f8eaf  90                   nop 
// 005f8eb0  8b4808               mov ecx, dword ptr [eax + 8]
// 005f8eb3  3be9                 cmp ebp, ecx
// 005f8eb5  7302                 jae 0x5f8eb9
// 005f8eb7  8be9                 mov ebp, ecx
// 005f8eb9  83c018               add eax, 0x18
// 005f8ebc  3bc2                 cmp eax, edx
// 005f8ebe  76f0                 jbe 0x5f8eb0
// 005f8ec0  8b7720               mov esi, dword ptr [edi + 0x20]
// 005f8ec3  3bf3                 cmp esi, ebx
// 005f8ec5  7324                 jae 0x5f8eeb
// 005f8ec7  837e0804             cmp dword ptr [esi + 8], 4
// 005f8ecb  7c16                 jl 0x5f8ee3
// 005f8ecd  8b06                 mov eax, dword ptr [esi]
// 005f8ecf  f6400503             test byte ptr [eax + 5], 3
// 005f8ed3  740e                 je 0x5f8ee3
// 005f8ed5  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 005f8ed9  50                   push eax
// 005f8eda  51                   push ecx
// 005f8edb  e8e0faffff           call 0x5f89c0
// 005f8ee0  83c408               add esp, 8
// 005f8ee3  83c610               add esi, 0x10
// 005f8ee6  3b7708               cmp esi, dword ptr [edi + 8]
// 005f8ee9  72dc                 jb 0x5f8ec7
// 005f8eeb  3bf5                 cmp esi, ebp
// 005f8eed  770c                 ja 0x5f8efb
// 005f8eef  33c0                 xor eax, eax
// 005f8ef1  894608               mov dword ptr [esi + 8], eax
// 005f8ef4  83c610               add esi, 0x10
// 005f8ef7  3bf5                 cmp esi, ebp
// 005f8ef9  76f6                 jbe 0x5f8ef1
// 005f8efb  2b6f20               sub ebp, dword ptr [edi + 0x20]
// 005f8efe  8b7730               mov esi, dword ptr [edi + 0x30]
// 005f8f01  c1fd04               sar ebp, 4
// 005f8f04  81fe204e0000         cmp esi, 0x4e20
// 005f8f0a  7f57                 jg 0x5f8f63
// 005f8f0c  8b4f14               mov ecx, dword ptr [edi + 0x14]
// 005f8f0f  2b4f28               sub ecx, dword ptr [edi + 0x28]
// 005f8f12  b8abaaaa2a           mov eax, 0x2aaaaaab
// 005f8f17  f7e9                 imul ecx
// 005f8f19  c1fa02               sar edx, 2
// 005f8f1c  8bc2                 mov eax, edx
// 005f8f1e  c1e81f               shr eax, 0x1f
// 005f8f21  03c2                 add eax, edx
// 005f8f23  03c0                 add eax, eax
// 005f8f25  03c0                 add eax, eax
// 005f8f27  3bc6                 cmp eax, esi
// 005f8f29  7d16                 jge 0x5f8f41
// 005f8f2b  83fe10               cmp esi, 0x10
// 005f8f2e  7e11                 jle 0x5f8f41
// 005f8f30  8bc6                 mov eax, esi
// 005f8f32  99                   cdq 
// 005f8f33  2bc2                 sub eax, edx
// 005f8f35  d1f8                 sar eax, 1
// 005f8f37  50                   push eax
// 005f8f38  57                   push edi
// 005f8f39  e8326dfcff           call 0x5bfc70
// 005f8f3e  83c408               add esp, 8
// 005f8f41  8b472c               mov eax, dword ptr [edi + 0x2c]
// 005f8f44  8d0cad00000000       lea ecx, [ebp*4]
// 005f8f4b  3bc8                 cmp ecx, eax
// 005f8f4d  7d14                 jge 0x5f8f63
// 005f8f4f  83f85a               cmp eax, 0x5a
// 005f8f52  7e0f                 jle 0x5f8f63
// 005f8f54  99                   cdq 
// 005f8f55  2bc2                 sub eax, edx
// 005f8f57  d1f8                 sar eax, 1
// 005f8f59  50                   push eax
// 005f8f5a  57                   push edi
// 005f8f5b  e8b06cfcff           call 0x5bfc10
// 005f8f60  83c408               add esp, 8
// 005f8f63  5e                   pop esi
// 005f8f64  5d                   pop ebp
// 005f8f65  5b                   pop ebx
// 005f8f66  c3                   ret 
// library lua-5.1.1/lgc.c (function _traversestack)

// roc-lang: c
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lgc.c
