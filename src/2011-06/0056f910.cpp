// from server: 100% by auto
// roc 2011-06 0056f910  unit: seg_00560000  size: 444 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0056f910
//
// 0056f910  83ec10               sub esp, 0x10
// 0056f913  53                   push ebx
// 0056f914  55                   push ebp
// 0056f915  56                   push esi
// 0056f916  8b742420             mov esi, dword ptr [esp + 0x20]
// 0056f91a  f6466801             test byte ptr [esi + 0x68], 1
// 0056f91e  57                   push edi
// 0056f91f  740e                 je 0x56f92f
// 0056f921  683464a800           push 0xa86434
// 0056f926  56                   push esi
// 0056f927  e8041affff           call 0x561330
// 0056f92c  83c408               add esp, 8
// 0056f92f  837c242c0d           cmp dword ptr [esp + 0x2c], 0xd
// 0056f934  740e                 je 0x56f944
// 0056f936  682064a800           push 0xa86420
// 0056f93b  56                   push esi
// 0056f93c  e8ef19ffff           call 0x561330
// 0056f941  83c408               add esp, 8
// 0056f944  834e6801             or dword ptr [esi + 0x68], 1
// 0056f948  6a0d                 push 0xd
// 0056f94a  8d442414             lea eax, [esp + 0x14]
// 0056f94e  50                   push eax
// 0056f94f  56                   push esi
// 0056f950  e81b16ffff           call 0x560f70
// 0056f955  6a0d                 push 0xd
// 0056f957  8d4c2420             lea ecx, [esp + 0x20]
// 0056f95b  51                   push ecx
// 0056f95c  56                   push esi
// 0056f95d  e8ee0efeff           call 0x550850
// 0056f962  6a00                 push 0
// 0056f964  56                   push esi
// 0056f965  e8d6feffff           call 0x56f840
// 0056f96a  0fb67c2430           movzx edi, byte ptr [esp + 0x30]
// 0056f96f  0fb6542431           movzx edx, byte ptr [esp + 0x31]
// 0056f974  0fb6442432           movzx eax, byte ptr [esp + 0x32]
// 0056f979  0fb64c2433           movzx ecx, byte ptr [esp + 0x33]
// 0056f97e  c1e708               shl edi, 8
// 0056f981  03fa                 add edi, edx
// 0056f983  c1e708               shl edi, 8
// 0056f986  03f8                 add edi, eax
// 0056f988  c1e708               shl edi, 8
// 0056f98b  03f9                 add edi, ecx
// 0056f98d  83c420               add esp, 0x20
// 0056f990  81ffffffff7f         cmp edi, 0x7fffffff
// 0056f996  760e                 jbe 0x56f9a6
// 0056f998  683c62a800           push 0xa8623c
// 0056f99d  56                   push esi
// 0056f99e  e88d19ffff           call 0x561330
// 0056f9a3  83c408               add esp, 8
// 0056f9a6  0fb66c2414           movzx ebp, byte ptr [esp + 0x14]
// 0056f9ab  0fb6542415           movzx edx, byte ptr [esp + 0x15]
// 0056f9b0  0fb6442416           movzx eax, byte ptr [esp + 0x16]
// 0056f9b5  0fb64c2417           movzx ecx, byte ptr [esp + 0x17]
// 0056f9ba  c1e508               shl ebp, 8
// 0056f9bd  03ea                 add ebp, edx
// 0056f9bf  c1e508               shl ebp, 8
// 0056f9c2  03e8                 add ebp, eax
// 0056f9c4  c1e508               shl ebp, 8
// 0056f9c7  03e9                 add ebp, ecx
// 0056f9c9  81fdffffff7f         cmp ebp, 0x7fffffff
// 0056f9cf  760e                 jbe 0x56f9df
// 0056f9d1  683c62a800           push 0xa8623c
// 0056f9d6  56                   push esi
// 0056f9d7  e85419ffff           call 0x561330
// 0056f9dc  83c408               add esp, 8
// 0056f9df  0fb644241b           movzx eax, byte ptr [esp + 0x1b]
// 0056f9e4  0fb64c2419           movzx ecx, byte ptr [esp + 0x19]
// 0056f9e9  0fb6542418           movzx edx, byte ptr [esp + 0x18]
// 0056f9ee  0fb65c241a           movzx ebx, byte ptr [esp + 0x1a]
// 0056f9f3  89442424             mov dword ptr [esp + 0x24], eax
// 0056f9f7  0fb644241c           movzx eax, byte ptr [esp + 0x1c]
// 0056f9fc  8944242c             mov dword ptr [esp + 0x2c], eax
// 0056fa00  888623010000         mov byte ptr [esi + 0x123], al
// 0056fa06  8a442424             mov al, byte ptr [esp + 0x24]
// 0056fa0a  888638020000         mov byte ptr [esi + 0x238], al
// 0056fa10  0fb6c1               movzx eax, cl
// 0056fa13  89bec8000000         mov dword ptr [esi + 0xc8], edi
// 0056fa19  89aecc000000         mov dword ptr [esi + 0xcc], ebp
// 0056fa1f  889627010000         mov byte ptr [esi + 0x127], dl
// 0056fa25  888e26010000         mov byte ptr [esi + 0x126], cl
// 0056fa2b  889e60020000         mov byte ptr [esi + 0x260], bl
// 0056fa31  83f806               cmp eax, 6
// 0056fa34  7729                 ja 0x56fa5f
// 0056fa36  ff2485b0fa5600       jmp dword ptr [eax*4 + 0x56fab0]
// 0056fa3d  c6862a01000001       mov byte ptr [esi + 0x12a], 1
// 0056fa44  eb19                 jmp 0x56fa5f
// 0056fa46  c6862a01000003       mov byte ptr [esi + 0x12a], 3
// 0056fa4d  eb10                 jmp 0x56fa5f
// 0056fa4f  c6862a01000002       mov byte ptr [esi + 0x12a], 2
// 0056fa56  eb07                 jmp 0x56fa5f
// 0056fa58  c6862a01000004       mov byte ptr [esi + 0x12a], 4
// 0056fa5f  8a862a010000         mov al, byte ptr [esi + 0x12a]
// 0056fa65  f6ea                 imul dl
// 0056fa67  888629010000         mov byte ptr [esi + 0x129], al
// 0056fa6d  3c08                 cmp al, 8
// 0056fa6f  0fb6c0               movzx eax, al
// 0056fa72  7208                 jb 0x56fa7c
// 0056fa74  c1e803               shr eax, 3
// 0056fa77  0fafc7               imul eax, edi
// 0056fa7a  eb09                 jmp 0x56fa85
// 0056fa7c  0fafc7               imul eax, edi
// 0056fa7f  83c007               add eax, 7
// 0056fa82  c1e803               shr eax, 3
// 0056fa85  8986d8000000         mov dword ptr [esi + 0xd8], eax
// 0056fa8b  8b442424             mov eax, dword ptr [esp + 0x24]
// 0056fa8f  50                   push eax
// 0056fa90  8b442430             mov eax, dword ptr [esp + 0x30]
// 0056fa94  53                   push ebx
// 0056fa95  50                   push eax
// 0056fa96  51                   push ecx
// 0056fa97  8b4c2438             mov ecx, dword ptr [esp + 0x38]
// 0056fa9b  52                   push edx
// 0056fa9c  55                   push ebp
// 0056fa9d  57                   push edi
// 0056fa9e  51                   push ecx
// 0056fa9f  56                   push esi
// 0056faa0  e86ba0feff           call 0x559b10
// 0056faa5  83c424               add esp, 0x24
// 0056faa8  5f                   pop edi
// 0056faa9  5e                   pop esi
// 0056faaa  5d                   pop ebp
// 0056faab  5b                   pop ebx
// 0056faac  83c410               add esp, 0x10
// 0056faaf  c3                   ret 
// 0056fab0  3dfa56005f           cmp eax, 0x5f0056fa
// 0056fab5  fa                   cli 
// 0056fab6  56                   push esi
// 0056fab7  0046fa               add byte ptr [esi - 6], al
// 0056faba  56                   push esi
// 0056fabb  003dfa56004f         add byte ptr [0x4f0056fa], bh
// 0056fac1  fa                   cli 
// 0056fac2  56                   push esi
// 0056fac3  005ffa               add byte ptr [edi - 6], bl
// 0056fac6  56                   push esi
// 0056fac7  0058fa               add byte ptr [eax - 6], bl
// 0056faca  56                   push esi
// library libpng-1.2.10/pngrutil.c (function _png_handle_IHDR)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.10 pngrutil.c
