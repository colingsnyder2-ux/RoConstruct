// roc 2009-12 00616cc0  unit: seg_00610000  size: 444 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00616cc0
//
// 00616cc0  83ec10               sub esp, 0x10
// 00616cc3  53                   push ebx
// 00616cc4  55                   push ebp
// 00616cc5  56                   push esi
// 00616cc6  8b742420             mov esi, dword ptr [esp + 0x20]
// 00616cca  f6466801             test byte ptr [esi + 0x68], 1
// 00616cce  57                   push edi
// 00616ccf  740e                 je 0x616cdf
// 00616cd1  68d08f9c00           push 0x9c8fd0
// 00616cd6  56                   push esi
// 00616cd7  e8b494ffff           call 0x610190
// 00616cdc  83c408               add esp, 8
// 00616cdf  837c242c0d           cmp dword ptr [esp + 0x2c], 0xd
// 00616ce4  740e                 je 0x616cf4
// 00616ce6  68bc8f9c00           push 0x9c8fbc
// 00616ceb  56                   push esi
// 00616cec  e89f94ffff           call 0x610190
// 00616cf1  83c408               add esp, 8
// 00616cf4  834e6801             or dword ptr [esi + 0x68], 1
// 00616cf8  6a0d                 push 0xd
// 00616cfa  8d442414             lea eax, [esp + 0x14]
// 00616cfe  50                   push eax
// 00616cff  56                   push esi
// 00616d00  e88b3dffff           call 0x60aa90
// 00616d05  6a0d                 push 0xd
// 00616d07  8d4c2420             lea ecx, [esp + 0x20]
// 00616d0b  51                   push ecx
// 00616d0c  56                   push esi
// 00616d0d  e85ec9feff           call 0x603670
// 00616d12  6a00                 push 0
// 00616d14  56                   push esi
// 00616d15  e8d6feffff           call 0x616bf0
// 00616d1a  0fb67c2430           movzx edi, byte ptr [esp + 0x30]
// 00616d1f  0fb6542431           movzx edx, byte ptr [esp + 0x31]
// 00616d24  0fb6442432           movzx eax, byte ptr [esp + 0x32]
// 00616d29  0fb64c2433           movzx ecx, byte ptr [esp + 0x33]
// 00616d2e  c1e708               shl edi, 8
// 00616d31  03fa                 add edi, edx
// 00616d33  c1e708               shl edi, 8
// 00616d36  03f8                 add edi, eax
// 00616d38  c1e708               shl edi, 8
// 00616d3b  03f9                 add edi, ecx
// 00616d3d  83c420               add esp, 0x20
// 00616d40  81ffffffff7f         cmp edi, 0x7fffffff
// 00616d46  760e                 jbe 0x616d56
// 00616d48  68d88d9c00           push 0x9c8dd8
// 00616d4d  56                   push esi
// 00616d4e  e83d94ffff           call 0x610190
// 00616d53  83c408               add esp, 8
// 00616d56  0fb66c2414           movzx ebp, byte ptr [esp + 0x14]
// 00616d5b  0fb6542415           movzx edx, byte ptr [esp + 0x15]
// 00616d60  0fb6442416           movzx eax, byte ptr [esp + 0x16]
// 00616d65  0fb64c2417           movzx ecx, byte ptr [esp + 0x17]
// 00616d6a  c1e508               shl ebp, 8
// 00616d6d  03ea                 add ebp, edx
// 00616d6f  c1e508               shl ebp, 8
// 00616d72  03e8                 add ebp, eax
// 00616d74  c1e508               shl ebp, 8
// 00616d77  03e9                 add ebp, ecx
// 00616d79  81fdffffff7f         cmp ebp, 0x7fffffff
// 00616d7f  760e                 jbe 0x616d8f
// 00616d81  68d88d9c00           push 0x9c8dd8
// 00616d86  56                   push esi
// 00616d87  e80494ffff           call 0x610190
// 00616d8c  83c408               add esp, 8
// 00616d8f  0fb644241b           movzx eax, byte ptr [esp + 0x1b]
// 00616d94  0fb64c2419           movzx ecx, byte ptr [esp + 0x19]
// 00616d99  0fb6542418           movzx edx, byte ptr [esp + 0x18]
// 00616d9e  0fb65c241a           movzx ebx, byte ptr [esp + 0x1a]
// 00616da3  89442424             mov dword ptr [esp + 0x24], eax
// 00616da7  0fb644241c           movzx eax, byte ptr [esp + 0x1c]
// 00616dac  8944242c             mov dword ptr [esp + 0x2c], eax
// 00616db0  888623010000         mov byte ptr [esi + 0x123], al
// 00616db6  8a442424             mov al, byte ptr [esp + 0x24]
// 00616dba  888638020000         mov byte ptr [esi + 0x238], al
// 00616dc0  0fb6c1               movzx eax, cl
// 00616dc3  89bec8000000         mov dword ptr [esi + 0xc8], edi
// 00616dc9  89aecc000000         mov dword ptr [esi + 0xcc], ebp
// 00616dcf  889627010000         mov byte ptr [esi + 0x127], dl
// 00616dd5  888e26010000         mov byte ptr [esi + 0x126], cl
// 00616ddb  889e60020000         mov byte ptr [esi + 0x260], bl
// 00616de1  83f806               cmp eax, 6
// 00616de4  7729                 ja 0x616e0f
// 00616de6  ff2485606e6100       jmp dword ptr [eax*4 + 0x616e60]
// 00616ded  c6862a01000001       mov byte ptr [esi + 0x12a], 1
// 00616df4  eb19                 jmp 0x616e0f
// 00616df6  c6862a01000003       mov byte ptr [esi + 0x12a], 3
// 00616dfd  eb10                 jmp 0x616e0f
// 00616dff  c6862a01000002       mov byte ptr [esi + 0x12a], 2
// 00616e06  eb07                 jmp 0x616e0f
// 00616e08  c6862a01000004       mov byte ptr [esi + 0x12a], 4
// 00616e0f  8a862a010000         mov al, byte ptr [esi + 0x12a]
// 00616e15  f6ea                 imul dl
// 00616e17  888629010000         mov byte ptr [esi + 0x129], al
// 00616e1d  3c08                 cmp al, 8
// 00616e1f  0fb6c0               movzx eax, al
// 00616e22  7208                 jb 0x616e2c
// 00616e24  c1e803               shr eax, 3
// 00616e27  0fafc7               imul eax, edi
// 00616e2a  eb09                 jmp 0x616e35
// 00616e2c  0fafc7               imul eax, edi
// 00616e2f  83c007               add eax, 7
// 00616e32  c1e803               shr eax, 3
// 00616e35  8986d8000000         mov dword ptr [esi + 0xd8], eax
// 00616e3b  8b442424             mov eax, dword ptr [esp + 0x24]
// 00616e3f  50                   push eax
// 00616e40  8b442430             mov eax, dword ptr [esp + 0x30]
// 00616e44  53                   push ebx
// 00616e45  50                   push eax
// 00616e46  51                   push ecx
// 00616e47  8b4c2438             mov ecx, dword ptr [esp + 0x38]
// 00616e4b  52                   push edx
// 00616e4c  55                   push ebp
// 00616e4d  57                   push edi
// 00616e4e  51                   push ecx
// 00616e4f  56                   push esi
// 00616e50  e83bb8feff           call 0x602690
// 00616e55  83c424               add esp, 0x24
// 00616e58  5f                   pop edi
// 00616e59  5e                   pop esi
// 00616e5a  5d                   pop ebp
// 00616e5b  5b                   pop ebx
// 00616e5c  83c410               add esp, 0x10
// 00616e5f  c3                   ret 
// 00616e60  ed                   in eax, dx
// 00616e61  6d                   insd dword ptr es:[edi], dx
// 00616e62  61                   popal 
// 00616e63  000f                 add byte ptr [edi], cl
// 00616e65  6e                   outsb dx, byte ptr [esi]
// 00616e66  61                   popal 
// 00616e67  00f6                 add dh, dh
// 00616e69  6d                   insd dword ptr es:[edi], dx
// 00616e6a  61                   popal 
// 00616e6b  00ed                 add ch, ch
// 00616e6d  6d                   insd dword ptr es:[edi], dx
// 00616e6e  61                   popal 
// 00616e6f  00ff                 add bh, bh
// 00616e71  6d                   insd dword ptr es:[edi], dx
// 00616e72  61                   popal 
// 00616e73  000f                 add byte ptr [edi], cl
// 00616e75  6e                   outsb dx, byte ptr [esi]
// 00616e76  61                   popal 
// 00616e77  0008                 add byte ptr [eax], cl
// 00616e79  6e                   outsb dx, byte ptr [esi]
// 00616e7a  61                   popal 
// library libpng-1.2.10/pngrutil.c (function _png_handle_IHDR)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.10 pngrutil.c
