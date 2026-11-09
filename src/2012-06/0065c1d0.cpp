// from server: 100% by auto
// roc 2012-06 0065c1d0  unit: seg_00650000  size: 624 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0065c1d0
//
// 0065c1d0  81ec0c010000         sub esp, 0x10c
// 0065c1d6  53                   push ebx
// 0065c1d7  8b9c2418010000       mov ebx, dword ptr [esp + 0x118]
// 0065c1de  56                   push esi
// 0065c1df  8bb42418010000       mov esi, dword ptr [esp + 0x118]
// 0065c1e6  8b4668               mov eax, dword ptr [esi + 0x68]
// 0065c1e9  a801                 test al, 1
// 0065c1eb  7548                 jne 0x65c235
// 0065c1ed  6808a9b800           push 0xb8a908
// 0065c1f2  56                   push esi
// 0065c1f3  e8b81fffff           call 0x64e1b0
// 0065c1f8  83c408               add esp, 8
// 0065c1fb  8a8626010000         mov al, byte ptr [esi + 0x126]
// 0065c201  57                   push edi
// 0065c202  84c0                 test al, al
// 0065c204  0f85d1000000         jne 0x65c2db
// 0065c20a  8bbc2424010000       mov edi, dword ptr [esp + 0x124]
// 0065c211  83ff02               cmp edi, 2
// 0065c214  7477                 je 0x65c28d
// 0065c216  68eca8b800           push 0xb8a8ec
// 0065c21b  56                   push esi
// 0065c21c  e83f20ffff           call 0x64e260
// 0065c221  57                   push edi
// 0065c222  56                   push esi
// 0065c223  e828edffff           call 0x65af50
// 0065c228  83c410               add esp, 0x10
// 0065c22b  5f                   pop edi
// 0065c22c  5e                   pop esi
// 0065c22d  5b                   pop ebx
// 0065c22e  81c40c010000         add esp, 0x10c
// 0065c234  c3                   ret 
// 0065c235  a804                 test al, 4
// 0065c237  7425                 je 0x65c25e
// 0065c239  68d4a8b800           push 0xb8a8d4
// 0065c23e  56                   push esi
// 0065c23f  e81c20ffff           call 0x64e260
// 0065c244  8b842428010000       mov eax, dword ptr [esp + 0x128]
// 0065c24b  50                   push eax
// 0065c24c  56                   push esi
// 0065c24d  e8feecffff           call 0x65af50
// 0065c252  83c410               add esp, 0x10
// 0065c255  5e                   pop esi
// 0065c256  5b                   pop ebx
// 0065c257  81c40c010000         add esp, 0x10c
// 0065c25d  c3                   ret 
// 0065c25e  85db                 test ebx, ebx
// 0065c260  7499                 je 0x65c1fb
// 0065c262  f6430810             test byte ptr [ebx + 8], 0x10
// 0065c266  7493                 je 0x65c1fb
// 0065c268  68bca8b800           push 0xb8a8bc
// 0065c26d  56                   push esi
// 0065c26e  e8ed1fffff           call 0x64e260
// 0065c273  8b8c2428010000       mov ecx, dword ptr [esp + 0x128]
// 0065c27a  51                   push ecx
// 0065c27b  56                   push esi
// 0065c27c  e8cfecffff           call 0x65af50
// 0065c281  83c410               add esp, 0x10
// 0065c284  5e                   pop esi
// 0065c285  5b                   pop ebx
// 0065c286  81c40c010000         add esp, 0x10c
// 0065c28c  c3                   ret 
// 0065c28d  6a02                 push 2
// 0065c28f  8d542410             lea edx, [esp + 0x10]
// 0065c293  52                   push edx
// 0065c294  56                   push esi
// 0065c295  e8561bffff           call 0x64ddf0
// 0065c29a  6a02                 push 2
// 0065c29c  8d44241c             lea eax, [esp + 0x1c]
// 0065c2a0  50                   push eax
// 0065c2a1  56                   push esi
// 0065c2a2  e8e91bfeff           call 0x63de90
// 0065c2a7  668b442424           mov ax, word ptr [esp + 0x24]
// 0065c2ac  b901000000           mov ecx, 1
// 0065c2b1  660fb6d0             movzx dx, al
// 0065c2b5  66898e1a010000       mov word ptr [esi + 0x11a], cx
// 0065c2bc  b900010000           mov ecx, 0x100
// 0065c2c1  660fafd1             imul dx, cx
// 0065c2c5  660fb6c4             movzx ax, ah
// 0065c2c9  83c418               add esp, 0x18
// 0065c2cc  6603d0               add dx, ax
// 0065c2cf  66899694010000       mov word ptr [esi + 0x194], dx
// 0065c2d6  e9f5000000           jmp 0x65c3d0
// 0065c2db  3c02                 cmp al, 2
// 0065c2dd  757a                 jne 0x65c359
// 0065c2df  8bbc2424010000       mov edi, dword ptr [esp + 0x124]
// 0065c2e6  83ff06               cmp edi, 6
// 0065c2e9  0f8527ffffff         jne 0x65c216
// 0065c2ef  57                   push edi
// 0065c2f0  8d4c2414             lea ecx, [esp + 0x14]
// 0065c2f4  51                   push ecx
// 0065c2f5  56                   push esi
// 0065c2f6  e8e5daffff           call 0x659de0
// 0065c2fb  0fb644241c           movzx eax, byte ptr [esp + 0x1c]
// 0065c300  b900010000           mov ecx, 0x100
// 0065c305  660fafc1             imul ax, cx
// 0065c309  ba01000000           mov edx, 1
// 0065c30e  6689961a010000       mov word ptr [esi + 0x11a], dx
// 0065c315  0fb654241d           movzx edx, byte ptr [esp + 0x1d]
// 0065c31a  6603c2               add ax, dx
// 0065c31d  0fb654241f           movzx edx, byte ptr [esp + 0x1f]
// 0065c322  6689868e010000       mov word ptr [esi + 0x18e], ax
// 0065c329  0fb644241e           movzx eax, byte ptr [esp + 0x1e]
// 0065c32e  660fafc1             imul ax, cx
// 0065c332  6603c2               add ax, dx
// 0065c335  0fb6542421           movzx edx, byte ptr [esp + 0x21]
// 0065c33a  66898690010000       mov word ptr [esi + 0x190], ax
// 0065c341  0fb6442420           movzx eax, byte ptr [esp + 0x20]
// 0065c346  660fafc1             imul ax, cx
// 0065c34a  83c40c               add esp, 0xc
// 0065c34d  6603c2               add ax, dx
// 0065c350  66898692010000       mov word ptr [esi + 0x192], ax
// 0065c357  eb77                 jmp 0x65c3d0
// 0065c359  3c03                 cmp al, 3
// 0065c35b  0f85b9000000         jne 0x65c41a
// 0065c361  f6466802             test byte ptr [esi + 0x68], 2
// 0065c365  750e                 jne 0x65c375
// 0065c367  68a0a8b800           push 0xb8a8a0
// 0065c36c  56                   push esi
// 0065c36d  e8ee1effff           call 0x64e260
// 0065c372  83c408               add esp, 8
// 0065c375  0fb78618010000       movzx eax, word ptr [esi + 0x118]
// 0065c37c  8bbc2424010000       mov edi, dword ptr [esp + 0x124]
// 0065c383  3bf8                 cmp edi, eax
// 0065c385  0f878bfeffff         ja 0x65c216
// 0065c38b  81ff00010000         cmp edi, 0x100
// 0065c391  0f877ffeffff         ja 0x65c216
// 0065c397  85ff                 test edi, edi
// 0065c399  751f                 jne 0x65c3ba
// 0065c39b  6888a8b800           push 0xb8a888
// 0065c3a0  56                   push esi
// 0065c3a1  e8ba1effff           call 0x64e260
// 0065c3a6  57                   push edi
// 0065c3a7  56                   push esi
// 0065c3a8  e8a3ebffff           call 0x65af50
// 0065c3ad  83c410               add esp, 0x10
// 0065c3b0  5f                   pop edi
// 0065c3b1  5e                   pop esi
// 0065c3b2  5b                   pop ebx
// 0065c3b3  81c40c010000         add esp, 0x10c
// 0065c3b9  c3                   ret 
// 0065c3ba  57                   push edi
// 0065c3bb  8d4c241c             lea ecx, [esp + 0x1c]
// 0065c3bf  51                   push ecx
// 0065c3c0  56                   push esi
// 0065c3c1  e81adaffff           call 0x659de0
// 0065c3c6  83c40c               add esp, 0xc
// 0065c3c9  6689be1a010000       mov word ptr [esi + 0x11a], di
// 0065c3d0  6a00                 push 0
// 0065c3d2  56                   push esi
// 0065c3d3  e878ebffff           call 0x65af50
// 0065c3d8  83c408               add esp, 8
// 0065c3db  85c0                 test eax, eax
// 0065c3dd  7413                 je 0x65c3f2
// 0065c3df  33d2                 xor edx, edx
// 0065c3e1  5f                   pop edi
// 0065c3e2  6689961a010000       mov word ptr [esi + 0x11a], dx
// 0065c3e9  5e                   pop esi
// 0065c3ea  5b                   pop ebx
// 0065c3eb  81c40c010000         add esp, 0x10c
// 0065c3f1  c3                   ret 
// 0065c3f2  0fb78e1a010000       movzx ecx, word ptr [esi + 0x11a]
// 0065c3f9  8d868c010000         lea eax, [esi + 0x18c]
// 0065c3ff  50                   push eax
// 0065c400  51                   push ecx
// 0065c401  8d542420             lea edx, [esp + 0x20]
// 0065c405  52                   push edx
// 0065c406  53                   push ebx
// 0065c407  56                   push esi
// 0065c408  e8e3aefeff           call 0x6472f0
// 0065c40d  83c414               add esp, 0x14
// 0065c410  5f                   pop edi
// 0065c411  5e                   pop esi
// 0065c412  5b                   pop ebx
// 0065c413  81c40c010000         add esp, 0x10c
// 0065c419  c3                   ret 
// 0065c41a  685ca8b800           push 0xb8a85c
// 0065c41f  56                   push esi
// 0065c420  e83b1effff           call 0x64e260
// 0065c425  8b84242c010000       mov eax, dword ptr [esp + 0x12c]
// 0065c42c  50                   push eax
// 0065c42d  56                   push esi
// 0065c42e  e81debffff           call 0x65af50
// 0065c433  83c410               add esp, 0x10
// 0065c436  5f                   pop edi
// 0065c437  5e                   pop esi
// 0065c438  5b                   pop ebx
// 0065c439  81c40c010000         add esp, 0x10c
// 0065c43f  c3                   ret 
// library libpng-1.2.18/pngrutil.c (function _png_handle_tRNS)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.18 pngrutil.c
