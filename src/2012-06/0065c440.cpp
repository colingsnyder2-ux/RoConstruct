// from server: 100% by auto
// roc 2012-06 0065c440  unit: seg_00650000  size: 541 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0065c440
//
// 0065c440  83ec08               sub esp, 8
// 0065c443  55                   push ebp
// 0065c444  8b6c2414             mov ebp, dword ptr [esp + 0x14]
// 0065c448  56                   push esi
// 0065c449  8b742414             mov esi, dword ptr [esp + 0x14]
// 0065c44d  8b4668               mov eax, dword ptr [esi + 0x68]
// 0065c450  a801                 test al, 1
// 0065c452  7527                 jne 0x65c47b
// 0065c454  68b0a9b800           push 0xb8a9b0
// 0065c459  56                   push esi
// 0065c45a  e8511dffff           call 0x64e1b0
// 0065c45f  83c408               add esp, 8
// 0065c462  8a8626010000         mov al, byte ptr [esi + 0x126]
// 0065c468  57                   push edi
// 0065c469  3c03                 cmp al, 3
// 0065c46b  0f8582000000         jne 0x65c4f3
// 0065c471  bf01000000           mov edi, 1
// 0065c476  e983000000           jmp 0x65c4fe
// 0065c47b  a804                 test al, 4
// 0065c47d  741f                 je 0x65c49e
// 0065c47f  6898a9b800           push 0xb8a998
// 0065c484  56                   push esi
// 0065c485  e8d61dffff           call 0x64e260
// 0065c48a  8b442424             mov eax, dword ptr [esp + 0x24]
// 0065c48e  50                   push eax
// 0065c48f  56                   push esi
// 0065c490  e8bbeaffff           call 0x65af50
// 0065c495  83c410               add esp, 0x10
// 0065c498  5e                   pop esi
// 0065c499  5d                   pop ebp
// 0065c49a  83c408               add esp, 8
// 0065c49d  c3                   ret 
// 0065c49e  80be2601000003       cmp byte ptr [esi + 0x126], 3
// 0065c4a5  7523                 jne 0x65c4ca
// 0065c4a7  a802                 test al, 2
// 0065c4a9  751f                 jne 0x65c4ca
// 0065c4ab  687ca9b800           push 0xb8a97c
// 0065c4b0  56                   push esi
// 0065c4b1  e8aa1dffff           call 0x64e260
// 0065c4b6  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 0065c4ba  51                   push ecx
// 0065c4bb  56                   push esi
// 0065c4bc  e88feaffff           call 0x65af50
// 0065c4c1  83c410               add esp, 0x10
// 0065c4c4  5e                   pop esi
// 0065c4c5  5d                   pop ebp
// 0065c4c6  83c408               add esp, 8
// 0065c4c9  c3                   ret 
// 0065c4ca  85ed                 test ebp, ebp
// 0065c4cc  7494                 je 0x65c462
// 0065c4ce  f6450820             test byte ptr [ebp + 8], 0x20
// 0065c4d2  748e                 je 0x65c462
// 0065c4d4  6864a9b800           push 0xb8a964
// 0065c4d9  56                   push esi
// 0065c4da  e8811dffff           call 0x64e260
// 0065c4df  8b542424             mov edx, dword ptr [esp + 0x24]
// 0065c4e3  52                   push edx
// 0065c4e4  56                   push esi
// 0065c4e5  e866eaffff           call 0x65af50
// 0065c4ea  83c410               add esp, 0x10
// 0065c4ed  5e                   pop esi
// 0065c4ee  5d                   pop ebp
// 0065c4ef  83c408               add esp, 8
// 0065c4f2  c3                   ret 
// 0065c4f3  0fb6f8               movzx edi, al
// 0065c4f6  83e702               and edi, 2
// 0065c4f9  83cf01               or edi, 1
// 0065c4fc  03ff                 add edi, edi
// 0065c4fe  53                   push ebx
// 0065c4ff  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 0065c503  3bdf                 cmp ebx, edi
// 0065c505  741d                 je 0x65c524
// 0065c507  6848a9b800           push 0xb8a948
// 0065c50c  56                   push esi
// 0065c50d  e84e1dffff           call 0x64e260
// 0065c512  53                   push ebx
// 0065c513  56                   push esi
// 0065c514  e837eaffff           call 0x65af50
// 0065c519  83c410               add esp, 0x10
// 0065c51c  5b                   pop ebx
// 0065c51d  5f                   pop edi
// 0065c51e  5e                   pop esi
// 0065c51f  5d                   pop ebp
// 0065c520  83c408               add esp, 8
// 0065c523  c3                   ret 
// 0065c524  57                   push edi
// 0065c525  8d442414             lea eax, [esp + 0x14]
// 0065c529  50                   push eax
// 0065c52a  56                   push esi
// 0065c52b  e8c018ffff           call 0x64ddf0
// 0065c530  57                   push edi
// 0065c531  8d4c2420             lea ecx, [esp + 0x20]
// 0065c535  51                   push ecx
// 0065c536  56                   push esi
// 0065c537  e85419feff           call 0x63de90
// 0065c53c  6a00                 push 0
// 0065c53e  56                   push esi
// 0065c53f  e80ceaffff           call 0x65af50
// 0065c544  83c420               add esp, 0x20
// 0065c547  85c0                 test eax, eax
// 0065c549  0f8506010000         jne 0x65c655
// 0065c54f  8a8626010000         mov al, byte ptr [esi + 0x126]
// 0065c555  3c03                 cmp al, 3
// 0065c557  7570                 jne 0x65c5c9
// 0065c559  8a442410             mov al, byte ptr [esp + 0x10]
// 0065c55d  888638010000         mov byte ptr [esi + 0x138], al
// 0065c563  85ed                 test ebp, ebp
// 0065c565  0f84d9000000         je 0x65c644
// 0065c56b  0fb74d14             movzx ecx, word ptr [ebp + 0x14]
// 0065c56f  6685c9               test cx, cx
// 0065c572  0f84cc000000         je 0x65c644
// 0065c578  660fb6d0             movzx dx, al
// 0065c57c  663bd1               cmp dx, cx
// 0065c57f  7216                 jb 0x65c597
// 0065c581  6824a9b800           push 0xb8a924
// 0065c586  56                   push esi
// 0065c587  e8d41cffff           call 0x64e260
// 0065c58c  83c408               add esp, 8
// 0065c58f  5b                   pop ebx
// 0065c590  5f                   pop edi
// 0065c591  5e                   pop esi
// 0065c592  5d                   pop ebp
// 0065c593  83c408               add esp, 8
// 0065c596  c3                   ret 
// 0065c597  8b8e14010000         mov ecx, dword ptr [esi + 0x114]
// 0065c59d  0fb6c0               movzx eax, al
// 0065c5a0  8d0440               lea eax, [eax + eax*2]
// 0065c5a3  0fb61408             movzx edx, byte ptr [eax + ecx]
// 0065c5a7  03c1                 add eax, ecx
// 0065c5a9  6689963a010000       mov word ptr [esi + 0x13a], dx
// 0065c5b0  660fb64801           movzx cx, byte ptr [eax + 1]
// 0065c5b5  66898e3c010000       mov word ptr [esi + 0x13c], cx
// 0065c5bc  0fb65002             movzx edx, byte ptr [eax + 2]
// 0065c5c0  6689963e010000       mov word ptr [esi + 0x13e], dx
// 0065c5c7  eb7b                 jmp 0x65c644
// 0065c5c9  b900010000           mov ecx, 0x100
// 0065c5ce  a802                 test al, 2
// 0065c5d0  752a                 jne 0x65c5fc
// 0065c5d2  660fb6442410         movzx ax, byte ptr [esp + 0x10]
// 0065c5d8  660fb6542411         movzx dx, byte ptr [esp + 0x11]
// 0065c5de  660fafc1             imul ax, cx
// 0065c5e2  6603c2               add ax, dx
// 0065c5e5  66898640010000       mov word ptr [esi + 0x140], ax
// 0065c5ec  6689863c010000       mov word ptr [esi + 0x13c], ax
// 0065c5f3  6689863a010000       mov word ptr [esi + 0x13a], ax
// 0065c5fa  eb41                 jmp 0x65c63d
// 0065c5fc  0fb6442410           movzx eax, byte ptr [esp + 0x10]
// 0065c601  0fb6542411           movzx edx, byte ptr [esp + 0x11]
// 0065c606  660fafc1             imul ax, cx
// 0065c60a  6603c2               add ax, dx
// 0065c60d  0fb6542413           movzx edx, byte ptr [esp + 0x13]
// 0065c612  6689863a010000       mov word ptr [esi + 0x13a], ax
// 0065c619  0fb6442412           movzx eax, byte ptr [esp + 0x12]
// 0065c61e  660fafc1             imul ax, cx
// 0065c622  6603c2               add ax, dx
// 0065c625  0fb6542415           movzx edx, byte ptr [esp + 0x15]
// 0065c62a  6689863c010000       mov word ptr [esi + 0x13c], ax
// 0065c631  0fb6442414           movzx eax, byte ptr [esp + 0x14]
// 0065c636  660fafc1             imul ax, cx
// 0065c63a  6603c2               add ax, dx
// 0065c63d  6689863e010000       mov word ptr [esi + 0x13e], ax
// 0065c644  8d8638010000         lea eax, [esi + 0x138]
// 0065c64a  50                   push eax
// 0065c64b  55                   push ebp
// 0065c64c  56                   push esi
// 0065c64d  e82e9ffeff           call 0x646580
// 0065c652  83c40c               add esp, 0xc
// 0065c655  5b                   pop ebx
// 0065c656  5f                   pop edi
// 0065c657  5e                   pop esi
// 0065c658  5d                   pop ebp
// 0065c659  83c408               add esp, 8
// 0065c65c  c3                   ret 
// library libpng-1.2.35/pngrutil.c (function _png_handle_bKGD)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.35 pngrutil.c
