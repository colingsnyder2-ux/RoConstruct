// from server: 100% by auto
// roc 2007-03 005f9df0  unit: seg_005f0000  size: 289 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005f9df0
//
// 005f9df0  83ec08               sub esp, 8
// 005f9df3  53                   push ebx
// 005f9df4  55                   push ebp
// 005f9df5  8b6c2418             mov ebp, dword ptr [esp + 0x18]
// 005f9df9  56                   push esi
// 005f9dfa  8b742418             mov esi, dword ptr [esp + 0x18]
// 005f9dfe  57                   push edi
// 005f9dff  c744241000000000     mov dword ptr [esp + 0x10], 0
// 005f9e07  eb07                 jmp 0x5f9e10
// 005f9e09  8da42400000000       lea esp, [esp]
// 005f9e10  837d0805             cmp dword ptr [ebp + 8], 5
// 005f9e14  0f8587000000         jne 0x5f9ea1
// 005f9e1a  8b442424             mov eax, dword ptr [esp + 0x24]
// 005f9e1e  8b5d00               mov ebx, dword ptr [ebp]
// 005f9e21  50                   push eax
// 005f9e22  53                   push ebx
// 005f9e23  56                   push esi
// 005f9e24  e847210000           call 0x5fbf70
// 005f9e29  8bc8                 mov ecx, eax
// 005f9e2b  83c40c               add esp, 0xc
// 005f9e2e  83790800             cmp dword ptr [ecx + 8], 0
// 005f9e32  894c2414             mov dword ptr [esp + 0x14], ecx
// 005f9e36  752c                 jne 0x5f9e64
// 005f9e38  8b4308               mov eax, dword ptr [ebx + 8]
// 005f9e3b  85c0                 test eax, eax
// 005f9e3d  7425                 je 0x5f9e64
// 005f9e3f  f6400602             test byte ptr [eax + 6], 2
// 005f9e43  751f                 jne 0x5f9e64
// 005f9e45  8b4e10               mov ecx, dword ptr [esi + 0x10]
// 005f9e48  8b91c0000000         mov edx, dword ptr [ecx + 0xc0]
// 005f9e4e  52                   push edx
// 005f9e4f  6a01                 push 1
// 005f9e51  50                   push eax
// 005f9e52  e899fbffff           call 0x5f99f0
// 005f9e57  8bf8                 mov edi, eax
// 005f9e59  83c40c               add esp, 0xc
// 005f9e5c  85ff                 test edi, edi
// 005f9e5e  7564                 jne 0x5f9ec4
// 005f9e60  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 005f9e64  8b442428             mov eax, dword ptr [esp + 0x28]
// 005f9e68  8b10                 mov edx, dword ptr [eax]
// 005f9e6a  8911                 mov dword ptr [ecx], edx
// 005f9e6c  8b5004               mov edx, dword ptr [eax + 4]
// 005f9e6f  895104               mov dword ptr [ecx + 4], edx
// 005f9e72  8b5008               mov edx, dword ptr [eax + 8]
// 005f9e75  895108               mov dword ptr [ecx + 8], edx
// 005f9e78  b904000000           mov ecx, 4
// 005f9e7d  394808               cmp dword ptr [eax + 8], ecx
// 005f9e80  7c6c                 jl 0x5f9eee
// 005f9e82  8b00                 mov eax, dword ptr [eax]
// 005f9e84  f6400503             test byte ptr [eax + 5], 3
// 005f9e88  7464                 je 0x5f9eee
// 005f9e8a  844b05               test byte ptr [ebx + 5], cl
// 005f9e8d  745f                 je 0x5f9eee
// 005f9e8f  53                   push ebx
// 005f9e90  56                   push esi
// 005f9e91  e84afaffff           call 0x5f98e0
// 005f9e96  83c408               add esp, 8
// 005f9e99  5f                   pop edi
// 005f9e9a  5e                   pop esi
// 005f9e9b  5d                   pop ebp
// 005f9e9c  5b                   pop ebx
// 005f9e9d  83c408               add esp, 8
// 005f9ea0  c3                   ret 
// 005f9ea1  6a01                 push 1
// 005f9ea3  55                   push ebp
// 005f9ea4  56                   push esi
// 005f9ea5  e876fbffff           call 0x5f9a20
// 005f9eaa  8bf8                 mov edi, eax
// 005f9eac  83c40c               add esp, 0xc
// 005f9eaf  837f0800             cmp dword ptr [edi + 8], 0
// 005f9eb3  750f                 jne 0x5f9ec4
// 005f9eb5  68c4027c00           push 0x7c02c4
// 005f9eba  55                   push ebp
// 005f9ebb  56                   push esi
// 005f9ebc  e81f94fcff           call 0x5c32e0
// 005f9ec1  83c40c               add esp, 0xc
// 005f9ec4  837f0806             cmp dword ptr [edi + 8], 6
// 005f9ec8  742c                 je 0x5f9ef6
// 005f9eca  8b442410             mov eax, dword ptr [esp + 0x10]
// 005f9ece  83c001               add eax, 1
// 005f9ed1  83f864               cmp eax, 0x64
// 005f9ed4  8bef                 mov ebp, edi
// 005f9ed6  89442410             mov dword ptr [esp + 0x10], eax
// 005f9eda  0f8c30ffffff         jl 0x5f9e10
// 005f9ee0  68cc027c00           push 0x7c02cc
// 005f9ee5  56                   push esi
// 005f9ee6  e8c591fcff           call 0x5c30b0
// 005f9eeb  83c408               add esp, 8
// 005f9eee  5f                   pop edi
// 005f9eef  5e                   pop esi
// 005f9ef0  5d                   pop ebp
// 005f9ef1  5b                   pop ebx
// 005f9ef2  83c408               add esp, 8
// 005f9ef5  c3                   ret 
// 005f9ef6  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 005f9efa  8b542424             mov edx, dword ptr [esp + 0x24]
// 005f9efe  57                   push edi
// 005f9eff  8bc5                 mov eax, ebp
// 005f9f01  e86afdffff           call 0x5f9c70
// 005f9f06  83c404               add esp, 4
// 005f9f09  5f                   pop edi
// 005f9f0a  5e                   pop esi
// 005f9f0b  5d                   pop ebp
// 005f9f0c  5b                   pop ebx
// 005f9f0d  83c408               add esp, 8
// 005f9f10  c3                   ret 
// library lua-5.1.1/lvm.c (function _luaV_settable)

// roc-lang: c
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lvm.c
