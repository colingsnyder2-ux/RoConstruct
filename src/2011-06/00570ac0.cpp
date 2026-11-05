// from server: 100% by auto
// roc 2011-06 00570ac0  unit: seg_00570000  size: 624 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00570ac0
//
// 00570ac0  81ec0c010000         sub esp, 0x10c
// 00570ac6  53                   push ebx
// 00570ac7  8b9c2418010000       mov ebx, dword ptr [esp + 0x118]
// 00570ace  56                   push esi
// 00570acf  8bb42418010000       mov esi, dword ptr [esp + 0x118]
// 00570ad6  8b4668               mov eax, dword ptr [esi + 0x68]
// 00570ad9  a801                 test al, 1
// 00570adb  7548                 jne 0x570b25
// 00570add  68b86aa800           push 0xa86ab8
// 00570ae2  56                   push esi
// 00570ae3  e84808ffff           call 0x561330
// 00570ae8  83c408               add esp, 8
// 00570aeb  8a8626010000         mov al, byte ptr [esi + 0x126]
// 00570af1  57                   push edi
// 00570af2  84c0                 test al, al
// 00570af4  0f85d1000000         jne 0x570bcb
// 00570afa  8bbc2424010000       mov edi, dword ptr [esp + 0x124]
// 00570b01  83ff02               cmp edi, 2
// 00570b04  7477                 je 0x570b7d
// 00570b06  689c6aa800           push 0xa86a9c
// 00570b0b  56                   push esi
// 00570b0c  e8cf08ffff           call 0x5613e0
// 00570b11  57                   push edi
// 00570b12  56                   push esi
// 00570b13  e828edffff           call 0x56f840
// 00570b18  83c410               add esp, 0x10
// 00570b1b  5f                   pop edi
// 00570b1c  5e                   pop esi
// 00570b1d  5b                   pop ebx
// 00570b1e  81c40c010000         add esp, 0x10c
// 00570b24  c3                   ret 
// 00570b25  a804                 test al, 4
// 00570b27  7425                 je 0x570b4e
// 00570b29  68846aa800           push 0xa86a84
// 00570b2e  56                   push esi
// 00570b2f  e8ac08ffff           call 0x5613e0
// 00570b34  8b842428010000       mov eax, dword ptr [esp + 0x128]
// 00570b3b  50                   push eax
// 00570b3c  56                   push esi
// 00570b3d  e8feecffff           call 0x56f840
// 00570b42  83c410               add esp, 0x10
// 00570b45  5e                   pop esi
// 00570b46  5b                   pop ebx
// 00570b47  81c40c010000         add esp, 0x10c
// 00570b4d  c3                   ret 
// 00570b4e  85db                 test ebx, ebx
// 00570b50  7499                 je 0x570aeb
// 00570b52  f6430810             test byte ptr [ebx + 8], 0x10
// 00570b56  7493                 je 0x570aeb
// 00570b58  686c6aa800           push 0xa86a6c
// 00570b5d  56                   push esi
// 00570b5e  e87d08ffff           call 0x5613e0
// 00570b63  8b8c2428010000       mov ecx, dword ptr [esp + 0x128]
// 00570b6a  51                   push ecx
// 00570b6b  56                   push esi
// 00570b6c  e8cfecffff           call 0x56f840
// 00570b71  83c410               add esp, 0x10
// 00570b74  5e                   pop esi
// 00570b75  5b                   pop ebx
// 00570b76  81c40c010000         add esp, 0x10c
// 00570b7c  c3                   ret 
// 00570b7d  6a02                 push 2
// 00570b7f  8d542410             lea edx, [esp + 0x10]
// 00570b83  52                   push edx
// 00570b84  56                   push esi
// 00570b85  e8e603ffff           call 0x560f70
// 00570b8a  6a02                 push 2
// 00570b8c  8d44241c             lea eax, [esp + 0x1c]
// 00570b90  50                   push eax
// 00570b91  56                   push esi
// 00570b92  e8b9fcfdff           call 0x550850
// 00570b97  668b442424           mov ax, word ptr [esp + 0x24]
// 00570b9c  b901000000           mov ecx, 1
// 00570ba1  660fb6d0             movzx dx, al
// 00570ba5  66898e1a010000       mov word ptr [esi + 0x11a], cx
// 00570bac  b900010000           mov ecx, 0x100
// 00570bb1  660fafd1             imul dx, cx
// 00570bb5  660fb6c4             movzx ax, ah
// 00570bb9  83c418               add esp, 0x18
// 00570bbc  6603d0               add dx, ax
// 00570bbf  66899694010000       mov word ptr [esi + 0x194], dx
// 00570bc6  e9f5000000           jmp 0x570cc0
// 00570bcb  3c02                 cmp al, 2
// 00570bcd  757a                 jne 0x570c49
// 00570bcf  8bbc2424010000       mov edi, dword ptr [esp + 0x124]
// 00570bd6  83ff06               cmp edi, 6
// 00570bd9  0f8527ffffff         jne 0x570b06
// 00570bdf  57                   push edi
// 00570be0  8d4c2414             lea ecx, [esp + 0x14]
// 00570be4  51                   push ecx
// 00570be5  56                   push esi
// 00570be6  e8e5daffff           call 0x56e6d0
// 00570beb  0fb644241c           movzx eax, byte ptr [esp + 0x1c]
// 00570bf0  b900010000           mov ecx, 0x100
// 00570bf5  660fafc1             imul ax, cx
// 00570bf9  ba01000000           mov edx, 1
// 00570bfe  6689961a010000       mov word ptr [esi + 0x11a], dx
// 00570c05  0fb654241d           movzx edx, byte ptr [esp + 0x1d]
// 00570c0a  6603c2               add ax, dx
// 00570c0d  0fb654241f           movzx edx, byte ptr [esp + 0x1f]
// 00570c12  6689868e010000       mov word ptr [esi + 0x18e], ax
// 00570c19  0fb644241e           movzx eax, byte ptr [esp + 0x1e]
// 00570c1e  660fafc1             imul ax, cx
// 00570c22  6603c2               add ax, dx
// 00570c25  0fb6542421           movzx edx, byte ptr [esp + 0x21]
// 00570c2a  66898690010000       mov word ptr [esi + 0x190], ax
// 00570c31  0fb6442420           movzx eax, byte ptr [esp + 0x20]
// 00570c36  660fafc1             imul ax, cx
// 00570c3a  83c40c               add esp, 0xc
// 00570c3d  6603c2               add ax, dx
// 00570c40  66898692010000       mov word ptr [esi + 0x192], ax
// 00570c47  eb77                 jmp 0x570cc0
// 00570c49  3c03                 cmp al, 3
// 00570c4b  0f85b9000000         jne 0x570d0a
// 00570c51  f6466802             test byte ptr [esi + 0x68], 2
// 00570c55  750e                 jne 0x570c65
// 00570c57  68506aa800           push 0xa86a50
// 00570c5c  56                   push esi
// 00570c5d  e87e07ffff           call 0x5613e0
// 00570c62  83c408               add esp, 8
// 00570c65  0fb78618010000       movzx eax, word ptr [esi + 0x118]
// 00570c6c  8bbc2424010000       mov edi, dword ptr [esp + 0x124]
// 00570c73  3bf8                 cmp edi, eax
// 00570c75  0f878bfeffff         ja 0x570b06
// 00570c7b  81ff00010000         cmp edi, 0x100
// 00570c81  0f877ffeffff         ja 0x570b06
// 00570c87  85ff                 test edi, edi
// 00570c89  751f                 jne 0x570caa
// 00570c8b  68386aa800           push 0xa86a38
// 00570c90  56                   push esi
// 00570c91  e84a07ffff           call 0x5613e0
// 00570c96  57                   push edi
// 00570c97  56                   push esi
// 00570c98  e8a3ebffff           call 0x56f840
// 00570c9d  83c410               add esp, 0x10
// 00570ca0  5f                   pop edi
// 00570ca1  5e                   pop esi
// 00570ca2  5b                   pop ebx
// 00570ca3  81c40c010000         add esp, 0x10c
// 00570ca9  c3                   ret 
// 00570caa  57                   push edi
// 00570cab  8d4c241c             lea ecx, [esp + 0x1c]
// 00570caf  51                   push ecx
// 00570cb0  56                   push esi
// 00570cb1  e81adaffff           call 0x56e6d0
// 00570cb6  83c40c               add esp, 0xc
// 00570cb9  6689be1a010000       mov word ptr [esi + 0x11a], di
// 00570cc0  6a00                 push 0
// 00570cc2  56                   push esi
// 00570cc3  e878ebffff           call 0x56f840
// 00570cc8  83c408               add esp, 8
// 00570ccb  85c0                 test eax, eax
// 00570ccd  7413                 je 0x570ce2
// 00570ccf  33d2                 xor edx, edx
// 00570cd1  5f                   pop edi
// 00570cd2  6689961a010000       mov word ptr [esi + 0x11a], dx
// 00570cd9  5e                   pop esi
// 00570cda  5b                   pop ebx
// 00570cdb  81c40c010000         add esp, 0x10c
// 00570ce1  c3                   ret 
// 00570ce2  0fb78e1a010000       movzx ecx, word ptr [esi + 0x11a]
// 00570ce9  8d868c010000         lea eax, [esi + 0x18c]
// 00570cef  50                   push eax
// 00570cf0  51                   push ecx
// 00570cf1  8d542420             lea edx, [esp + 0x20]
// 00570cf5  52                   push edx
// 00570cf6  53                   push ebx
// 00570cf7  56                   push esi
// 00570cf8  e87397feff           call 0x55a470
// 00570cfd  83c414               add esp, 0x14
// 00570d00  5f                   pop edi
// 00570d01  5e                   pop esi
// 00570d02  5b                   pop ebx
// 00570d03  81c40c010000         add esp, 0x10c
// 00570d09  c3                   ret 
// 00570d0a  680c6aa800           push 0xa86a0c
// 00570d0f  56                   push esi
// 00570d10  e8cb06ffff           call 0x5613e0
// 00570d15  8b84242c010000       mov eax, dword ptr [esp + 0x12c]
// 00570d1c  50                   push eax
// 00570d1d  56                   push esi
// 00570d1e  e81debffff           call 0x56f840
// 00570d23  83c410               add esp, 0x10
// 00570d26  5f                   pop edi
// 00570d27  5e                   pop esi
// 00570d28  5b                   pop ebx
// 00570d29  81c40c010000         add esp, 0x10c
// 00570d2f  c3                   ret 
// library libpng-1.2.18/pngrutil.c (function _png_handle_tRNS)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.18 pngrutil.c
