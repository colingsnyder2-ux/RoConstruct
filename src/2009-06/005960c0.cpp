// from server: 100% by auto
// roc 2009-06 005960c0  unit: seg_00590000  size: 541 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 005960c0
//
// 005960c0  83ec08               sub esp, 8
// 005960c3  55                   push ebp
// 005960c4  8b6c2414             mov ebp, dword ptr [esp + 0x14]
// 005960c8  56                   push esi
// 005960c9  8b742414             mov esi, dword ptr [esp + 0x14]
// 005960cd  8b4668               mov eax, dword ptr [esi + 0x68]
// 005960d0  a801                 test al, 1
// 005960d2  7527                 jne 0x5960fb
// 005960d4  68d8288d00           push 0x8d28d8
// 005960d9  56                   push esi
// 005960da  e88180ffff           call 0x58e160
// 005960df  83c408               add esp, 8
// 005960e2  8a8626010000         mov al, byte ptr [esi + 0x126]
// 005960e8  57                   push edi
// 005960e9  3c03                 cmp al, 3
// 005960eb  0f8582000000         jne 0x596173
// 005960f1  bf01000000           mov edi, 1
// 005960f6  e983000000           jmp 0x59617e
// 005960fb  a804                 test al, 4
// 005960fd  741f                 je 0x59611e
// 005960ff  68c0288d00           push 0x8d28c0
// 00596104  56                   push esi
// 00596105  e80681ffff           call 0x58e210
// 0059610a  8b442424             mov eax, dword ptr [esp + 0x24]
// 0059610e  50                   push eax
// 0059610f  56                   push esi
// 00596110  e8cbeaffff           call 0x594be0
// 00596115  83c410               add esp, 0x10
// 00596118  5e                   pop esi
// 00596119  5d                   pop ebp
// 0059611a  83c408               add esp, 8
// 0059611d  c3                   ret 
// 0059611e  80be2601000003       cmp byte ptr [esi + 0x126], 3
// 00596125  7523                 jne 0x59614a
// 00596127  a802                 test al, 2
// 00596129  751f                 jne 0x59614a
// 0059612b  68a4288d00           push 0x8d28a4
// 00596130  56                   push esi
// 00596131  e8da80ffff           call 0x58e210
// 00596136  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 0059613a  51                   push ecx
// 0059613b  56                   push esi
// 0059613c  e89feaffff           call 0x594be0
// 00596141  83c410               add esp, 0x10
// 00596144  5e                   pop esi
// 00596145  5d                   pop ebp
// 00596146  83c408               add esp, 8
// 00596149  c3                   ret 
// 0059614a  85ed                 test ebp, ebp
// 0059614c  7494                 je 0x5960e2
// 0059614e  f6450820             test byte ptr [ebp + 8], 0x20
// 00596152  748e                 je 0x5960e2
// 00596154  688c288d00           push 0x8d288c
// 00596159  56                   push esi
// 0059615a  e8b180ffff           call 0x58e210
// 0059615f  8b542424             mov edx, dword ptr [esp + 0x24]
// 00596163  52                   push edx
// 00596164  56                   push esi
// 00596165  e876eaffff           call 0x594be0
// 0059616a  83c410               add esp, 0x10
// 0059616d  5e                   pop esi
// 0059616e  5d                   pop ebp
// 0059616f  83c408               add esp, 8
// 00596172  c3                   ret 
// 00596173  0fb6f8               movzx edi, al
// 00596176  83e702               and edi, 2
// 00596179  83cf01               or edi, 1
// 0059617c  03ff                 add edi, edi
// 0059617e  53                   push ebx
// 0059617f  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 00596183  3bdf                 cmp ebx, edi
// 00596185  741d                 je 0x5961a4
// 00596187  6870288d00           push 0x8d2870
// 0059618c  56                   push esi
// 0059618d  e87e80ffff           call 0x58e210
// 00596192  53                   push ebx
// 00596193  56                   push esi
// 00596194  e847eaffff           call 0x594be0
// 00596199  83c410               add esp, 0x10
// 0059619c  5b                   pop ebx
// 0059619d  5f                   pop edi
// 0059619e  5e                   pop esi
// 0059619f  5d                   pop ebp
// 005961a0  83c408               add esp, 8
// 005961a3  c3                   ret 
// 005961a4  57                   push edi
// 005961a5  8d442414             lea eax, [esp + 0x14]
// 005961a9  50                   push eax
// 005961aa  56                   push esi
// 005961ab  e8502bffff           call 0x588d00
// 005961b0  57                   push edi
// 005961b1  8d4c2420             lea ecx, [esp + 0x20]
// 005961b5  51                   push ecx
// 005961b6  56                   push esi
// 005961b7  e804b7feff           call 0x5818c0
// 005961bc  6a00                 push 0
// 005961be  56                   push esi
// 005961bf  e81ceaffff           call 0x594be0
// 005961c4  83c420               add esp, 0x20
// 005961c7  85c0                 test eax, eax
// 005961c9  0f8506010000         jne 0x5962d5
// 005961cf  8a8626010000         mov al, byte ptr [esi + 0x126]
// 005961d5  3c03                 cmp al, 3
// 005961d7  7570                 jne 0x596249
// 005961d9  8a442410             mov al, byte ptr [esp + 0x10]
// 005961dd  888638010000         mov byte ptr [esi + 0x138], al
// 005961e3  85ed                 test ebp, ebp
// 005961e5  0f84d9000000         je 0x5962c4
// 005961eb  0fb74d14             movzx ecx, word ptr [ebp + 0x14]
// 005961ef  6685c9               test cx, cx
// 005961f2  0f84cc000000         je 0x5962c4
// 005961f8  660fb6d0             movzx dx, al
// 005961fc  663bd1               cmp dx, cx
// 005961ff  7616                 jbe 0x596217
// 00596201  684c288d00           push 0x8d284c
// 00596206  56                   push esi
// 00596207  e80480ffff           call 0x58e210
// 0059620c  83c408               add esp, 8
// 0059620f  5b                   pop ebx
// 00596210  5f                   pop edi
// 00596211  5e                   pop esi
// 00596212  5d                   pop ebp
// 00596213  83c408               add esp, 8
// 00596216  c3                   ret 
// 00596217  8b8e14010000         mov ecx, dword ptr [esi + 0x114]
// 0059621d  0fb6c0               movzx eax, al
// 00596220  8d0440               lea eax, [eax + eax*2]
// 00596223  0fb61408             movzx edx, byte ptr [eax + ecx]
// 00596227  03c1                 add eax, ecx
// 00596229  6689963a010000       mov word ptr [esi + 0x13a], dx
// 00596230  660fb64801           movzx cx, byte ptr [eax + 1]
// 00596235  66898e3c010000       mov word ptr [esi + 0x13c], cx
// 0059623c  0fb65002             movzx edx, byte ptr [eax + 2]
// 00596240  6689963e010000       mov word ptr [esi + 0x13e], dx
// 00596247  eb7b                 jmp 0x5962c4
// 00596249  b900010000           mov ecx, 0x100
// 0059624e  a802                 test al, 2
// 00596250  752a                 jne 0x59627c
// 00596252  660fb6442410         movzx ax, byte ptr [esp + 0x10]
// 00596258  660fb6542411         movzx dx, byte ptr [esp + 0x11]
// 0059625e  660fafc1             imul ax, cx
// 00596262  6603c2               add ax, dx
// 00596265  66898640010000       mov word ptr [esi + 0x140], ax
// 0059626c  6689863c010000       mov word ptr [esi + 0x13c], ax
// 00596273  6689863a010000       mov word ptr [esi + 0x13a], ax
// 0059627a  eb41                 jmp 0x5962bd
// 0059627c  0fb6442410           movzx eax, byte ptr [esp + 0x10]
// 00596281  0fb6542411           movzx edx, byte ptr [esp + 0x11]
// 00596286  660fafc1             imul ax, cx
// 0059628a  6603c2               add ax, dx
// 0059628d  0fb6542413           movzx edx, byte ptr [esp + 0x13]
// 00596292  6689863a010000       mov word ptr [esi + 0x13a], ax
// 00596299  0fb6442412           movzx eax, byte ptr [esp + 0x12]
// 0059629e  660fafc1             imul ax, cx
// 005962a2  6603c2               add ax, dx
// 005962a5  0fb6542415           movzx edx, byte ptr [esp + 0x15]
// 005962aa  6689863c010000       mov word ptr [esi + 0x13c], ax
// 005962b1  0fb6442414           movzx eax, byte ptr [esp + 0x14]
// 005962b6  660fafc1             imul ax, cx
// 005962ba  6603c2               add ax, dx
// 005962bd  6689863e010000       mov word ptr [esi + 0x13e], ax
// 005962c4  8d8638010000         lea eax, [esi + 0x138]
// 005962ca  50                   push eax
// 005962cb  55                   push ebp
// 005962cc  56                   push esi
// 005962cd  e8fe9efeff           call 0x5801d0
// 005962d2  83c40c               add esp, 0xc
// 005962d5  5b                   pop ebx
// 005962d6  5f                   pop edi
// 005962d7  5e                   pop esi
// 005962d8  5d                   pop ebp
// 005962d9  83c408               add esp, 8
// 005962dc  c3                   ret 
// library libpng-1.2.29/pngrutil.c (function _png_handle_bKGD)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.29 pngrutil.c
