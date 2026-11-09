// from server: 100% by auto
// roc 2008-06 0065b5d0  unit: RBX::BallBallContact  size: 212 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0065b5d0
//
// 0065b5d0  56                   push esi
// 0065b5d1  8b74240c             mov esi, dword ptr [esp + 0xc]
// 0065b5d5  0fb64604             movzx eax, byte ptr [esi + 4]
// 0065b5d9  806605fc             and byte ptr [esi + 5], 0xfc
// 0065b5dd  83e804               sub eax, 4
// 0065b5e0  83f806               cmp eax, 6
// 0065b5e3  0f879d000000         ja 0x65b686
// 0065b5e9  57                   push edi
// 0065b5ea  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 0065b5ee  8bff                 mov edi, edi
// 0065b5f0  ff248588b66500       jmp dword ptr [eax*4 + 0x65b688]
// 0065b5f7  8b4608               mov eax, dword ptr [esi + 8]
// 0065b5fa  804e0504             or byte ptr [esi + 5], 4
// 0065b5fe  85c0                 test eax, eax
// 0065b600  7410                 je 0x65b612
// 0065b602  f6400503             test byte ptr [eax + 5], 3
// 0065b606  740a                 je 0x65b612
// 0065b608  50                   push eax
// 0065b609  57                   push edi
// 0065b60a  e8c1ffffff           call 0x65b5d0
// 0065b60f  83c408               add esp, 8
// 0065b612  8b760c               mov esi, dword ptr [esi + 0xc]
// 0065b615  f6460503             test byte ptr [esi + 5], 3
// 0065b619  746a                 je 0x65b685
// 0065b61b  806605fc             and byte ptr [esi + 5], 0xfc
// 0065b61f  0fb64604             movzx eax, byte ptr [esi + 4]
// 0065b623  83e804               sub eax, 4
// 0065b626  83f806               cmp eax, 6
// 0065b629  76c5                 jbe 0x65b5f0
// 0065b62b  5f                   pop edi
// 0065b62c  5e                   pop esi
// 0065b62d  c3                   ret 
// 0065b62e  8b4608               mov eax, dword ptr [esi + 8]
// 0065b631  83780804             cmp dword ptr [eax + 8], 4
// 0065b635  7c12                 jl 0x65b649
// 0065b637  8b00                 mov eax, dword ptr [eax]
// 0065b639  f6400503             test byte ptr [eax + 5], 3
// 0065b63d  740a                 je 0x65b649
// 0065b63f  50                   push eax
// 0065b640  57                   push edi
// 0065b641  e88affffff           call 0x65b5d0
// 0065b646  83c408               add esp, 8
// 0065b649  8d4610               lea eax, [esi + 0x10]
// 0065b64c  394608               cmp dword ptr [esi + 8], eax
// 0065b64f  7534                 jne 0x65b685
// 0065b651  804e0504             or byte ptr [esi + 5], 4
// 0065b655  5f                   pop edi
// 0065b656  5e                   pop esi
// 0065b657  c3                   ret 
// 0065b658  8b4f24               mov ecx, dword ptr [edi + 0x24]
// 0065b65b  894e08               mov dword ptr [esi + 8], ecx
// 0065b65e  897724               mov dword ptr [edi + 0x24], esi
// 0065b661  5f                   pop edi
// 0065b662  5e                   pop esi
// 0065b663  c3                   ret 
// 0065b664  8b5724               mov edx, dword ptr [edi + 0x24]
// 0065b667  895618               mov dword ptr [esi + 0x18], edx
// 0065b66a  897724               mov dword ptr [edi + 0x24], esi
// 0065b66d  5f                   pop edi
// 0065b66e  5e                   pop esi
// 0065b66f  c3                   ret 
// 0065b670  8b4724               mov eax, dword ptr [edi + 0x24]
// 0065b673  89466c               mov dword ptr [esi + 0x6c], eax
// 0065b676  897724               mov dword ptr [edi + 0x24], esi
// 0065b679  5f                   pop edi
// 0065b67a  5e                   pop esi
// 0065b67b  c3                   ret 
// 0065b67c  8b4f24               mov ecx, dword ptr [edi + 0x24]
// 0065b67f  894e44               mov dword ptr [esi + 0x44], ecx
// 0065b682  897724               mov dword ptr [edi + 0x24], esi
// 0065b685  5f                   pop edi
// 0065b686  5e                   pop esi
// 0065b687  c3                   ret 
// 0065b688  85b6650064b6         test dword ptr [esi - 0x499bff9b], esi
// 0065b68e  650058b6             add byte ptr gs:[eax - 0x4a], bl
// 0065b692  6500f7               add bh, dh
// 0065b695  b565                 mov ch, 0x65
// 0065b697  0070b6               add byte ptr [eax - 0x4a], dh
// 0065b69a  65007cb665           add byte ptr gs:[esi + esi*4 + 0x65], bh
// 0065b69f  002e                 add byte ptr [esi], ch
// 0065b6a1  b665                 mov dh, 0x65
// library lua-5.1/lgc.c (function _reallymarkobject)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lgc.c
