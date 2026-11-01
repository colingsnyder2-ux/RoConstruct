// from server: 100% by auto
// roc 2007-03 005f9d00  unit: seg_005f0000  size: 227 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005f9d00
//
// 005f9d00  51                   push ecx
// 005f9d01  53                   push ebx
// 005f9d02  8b5c240c             mov ebx, dword ptr [esp + 0xc]
// 005f9d06  55                   push ebp
// 005f9d07  56                   push esi
// 005f9d08  57                   push edi
// 005f9d09  8b7c241c             mov edi, dword ptr [esp + 0x1c]
// 005f9d0d  c744241000000000     mov dword ptr [esp + 0x10], 0
// 005f9d15  837f0805             cmp dword ptr [edi + 8], 5
// 005f9d19  755b                 jne 0x5f9d76
// 005f9d1b  8b442420             mov eax, dword ptr [esp + 0x20]
// 005f9d1f  8b37                 mov esi, dword ptr [edi]
// 005f9d21  50                   push eax
// 005f9d22  56                   push esi
// 005f9d23  e898210000           call 0x5fbec0
// 005f9d28  8be8                 mov ebp, eax
// 005f9d2a  83c408               add esp, 8
// 005f9d2d  837d0800             cmp dword ptr [ebp + 8], 0
// 005f9d31  7528                 jne 0x5f9d5b
// 005f9d33  8b7608               mov esi, dword ptr [esi + 8]
// 005f9d36  85f6                 test esi, esi
// 005f9d38  7421                 je 0x5f9d5b
// 005f9d3a  f6460601             test byte ptr [esi + 6], 1
// 005f9d3e  751b                 jne 0x5f9d5b
// 005f9d40  8b4b10               mov ecx, dword ptr [ebx + 0x10]
// 005f9d43  8b91bc000000         mov edx, dword ptr [ecx + 0xbc]
// 005f9d49  52                   push edx
// 005f9d4a  6a00                 push 0
// 005f9d4c  56                   push esi
// 005f9d4d  e89efcffff           call 0x5f99f0
// 005f9d52  8bf0                 mov esi, eax
// 005f9d54  83c40c               add esp, 0xc
// 005f9d57  85f6                 test esi, esi
// 005f9d59  753e                 jne 0x5f9d99
// 005f9d5b  8b4d00               mov ecx, dword ptr [ebp]
// 005f9d5e  8b442424             mov eax, dword ptr [esp + 0x24]
// 005f9d62  8908                 mov dword ptr [eax], ecx
// 005f9d64  8b5504               mov edx, dword ptr [ebp + 4]
// 005f9d67  5f                   pop edi
// 005f9d68  5e                   pop esi
// 005f9d69  895004               mov dword ptr [eax + 4], edx
// 005f9d6c  8b4d08               mov ecx, dword ptr [ebp + 8]
// 005f9d6f  5d                   pop ebp
// 005f9d70  894808               mov dword ptr [eax + 8], ecx
// 005f9d73  5b                   pop ebx
// 005f9d74  59                   pop ecx
// 005f9d75  c3                   ret 
// 005f9d76  6a00                 push 0
// 005f9d78  57                   push edi
// 005f9d79  53                   push ebx
// 005f9d7a  e8a1fcffff           call 0x5f9a20
// 005f9d7f  8bf0                 mov esi, eax
// 005f9d81  83c40c               add esp, 0xc
// 005f9d84  837e0800             cmp dword ptr [esi + 8], 0
// 005f9d88  750f                 jne 0x5f9d99
// 005f9d8a  68c4027c00           push 0x7c02c4
// 005f9d8f  57                   push edi
// 005f9d90  53                   push ebx
// 005f9d91  e84a95fcff           call 0x5c32e0
// 005f9d96  83c40c               add esp, 0xc
// 005f9d99  837e0806             cmp dword ptr [esi + 8], 6
// 005f9d9d  742a                 je 0x5f9dc9
// 005f9d9f  8b442410             mov eax, dword ptr [esp + 0x10]
// 005f9da3  83c001               add eax, 1
// 005f9da6  83f864               cmp eax, 0x64
// 005f9da9  8bfe                 mov edi, esi
// 005f9dab  89442410             mov dword ptr [esp + 0x10], eax
// 005f9daf  0f8c60ffffff         jl 0x5f9d15
// 005f9db5  68b0027c00           push 0x7c02b0
// 005f9dba  53                   push ebx
// 005f9dbb  e8f092fcff           call 0x5c30b0
// 005f9dc0  83c408               add esp, 8
// 005f9dc3  5f                   pop edi
// 005f9dc4  5e                   pop esi
// 005f9dc5  5d                   pop ebp
// 005f9dc6  5b                   pop ebx
// 005f9dc7  59                   pop ecx
// 005f9dc8  c3                   ret 
// 005f9dc9  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 005f9dcd  8b442424             mov eax, dword ptr [esp + 0x24]
// 005f9dd1  56                   push esi
// 005f9dd2  53                   push ebx
// 005f9dd3  8bd7                 mov edx, edi
// 005f9dd5  e8f6fdffff           call 0x5f9bd0
// 005f9dda  83c408               add esp, 8
// 005f9ddd  5f                   pop edi
// 005f9dde  5e                   pop esi
// 005f9ddf  5d                   pop ebp
// 005f9de0  5b                   pop ebx
// 005f9de1  59                   pop ecx
// 005f9de2  c3                   ret 
// library lua-5.1.1/lvm.c (function _luaV_gettable)

// roc-lang: c
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lvm.c
