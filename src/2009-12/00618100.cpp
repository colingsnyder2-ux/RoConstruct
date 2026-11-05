// from server: 100% by auto
// roc 2009-12 00618100  unit: seg_00610000  size: 541 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00618100
//
// 00618100  83ec08               sub esp, 8
// 00618103  55                   push ebp
// 00618104  8b6c2414             mov ebp, dword ptr [esp + 0x14]
// 00618108  56                   push esi
// 00618109  8b742414             mov esi, dword ptr [esp + 0x14]
// 0061810d  8b4668               mov eax, dword ptr [esi + 0x68]
// 00618110  a801                 test al, 1
// 00618112  7527                 jne 0x61813b
// 00618114  6868979c00           push 0x9c9768
// 00618119  56                   push esi
// 0061811a  e87180ffff           call 0x610190
// 0061811f  83c408               add esp, 8
// 00618122  8a8626010000         mov al, byte ptr [esi + 0x126]
// 00618128  57                   push edi
// 00618129  3c03                 cmp al, 3
// 0061812b  0f8582000000         jne 0x6181b3
// 00618131  bf01000000           mov edi, 1
// 00618136  e983000000           jmp 0x6181be
// 0061813b  a804                 test al, 4
// 0061813d  741f                 je 0x61815e
// 0061813f  6850979c00           push 0x9c9750
// 00618144  56                   push esi
// 00618145  e8f680ffff           call 0x610240
// 0061814a  8b442424             mov eax, dword ptr [esp + 0x24]
// 0061814e  50                   push eax
// 0061814f  56                   push esi
// 00618150  e89beaffff           call 0x616bf0
// 00618155  83c410               add esp, 0x10
// 00618158  5e                   pop esi
// 00618159  5d                   pop ebp
// 0061815a  83c408               add esp, 8
// 0061815d  c3                   ret 
// 0061815e  80be2601000003       cmp byte ptr [esi + 0x126], 3
// 00618165  7523                 jne 0x61818a
// 00618167  a802                 test al, 2
// 00618169  751f                 jne 0x61818a
// 0061816b  6834979c00           push 0x9c9734
// 00618170  56                   push esi
// 00618171  e8ca80ffff           call 0x610240
// 00618176  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 0061817a  51                   push ecx
// 0061817b  56                   push esi
// 0061817c  e86feaffff           call 0x616bf0
// 00618181  83c410               add esp, 0x10
// 00618184  5e                   pop esi
// 00618185  5d                   pop ebp
// 00618186  83c408               add esp, 8
// 00618189  c3                   ret 
// 0061818a  85ed                 test ebp, ebp
// 0061818c  7494                 je 0x618122
// 0061818e  f6450820             test byte ptr [ebp + 8], 0x20
// 00618192  748e                 je 0x618122
// 00618194  681c979c00           push 0x9c971c
// 00618199  56                   push esi
// 0061819a  e8a180ffff           call 0x610240
// 0061819f  8b542424             mov edx, dword ptr [esp + 0x24]
// 006181a3  52                   push edx
// 006181a4  56                   push esi
// 006181a5  e846eaffff           call 0x616bf0
// 006181aa  83c410               add esp, 0x10
// 006181ad  5e                   pop esi
// 006181ae  5d                   pop ebp
// 006181af  83c408               add esp, 8
// 006181b2  c3                   ret 
// 006181b3  0fb6f8               movzx edi, al
// 006181b6  83e702               and edi, 2
// 006181b9  83cf01               or edi, 1
// 006181bc  03ff                 add edi, edi
// 006181be  53                   push ebx
// 006181bf  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 006181c3  3bdf                 cmp ebx, edi
// 006181c5  741d                 je 0x6181e4
// 006181c7  6800979c00           push 0x9c9700
// 006181cc  56                   push esi
// 006181cd  e86e80ffff           call 0x610240
// 006181d2  53                   push ebx
// 006181d3  56                   push esi
// 006181d4  e817eaffff           call 0x616bf0
// 006181d9  83c410               add esp, 0x10
// 006181dc  5b                   pop ebx
// 006181dd  5f                   pop edi
// 006181de  5e                   pop esi
// 006181df  5d                   pop ebp
// 006181e0  83c408               add esp, 8
// 006181e3  c3                   ret 
// 006181e4  57                   push edi
// 006181e5  8d442414             lea eax, [esp + 0x14]
// 006181e9  50                   push eax
// 006181ea  56                   push esi
// 006181eb  e8a028ffff           call 0x60aa90
// 006181f0  57                   push edi
// 006181f1  8d4c2420             lea ecx, [esp + 0x20]
// 006181f5  51                   push ecx
// 006181f6  56                   push esi
// 006181f7  e874b4feff           call 0x603670
// 006181fc  6a00                 push 0
// 006181fe  56                   push esi
// 006181ff  e8ece9ffff           call 0x616bf0
// 00618204  83c420               add esp, 0x20
// 00618207  85c0                 test eax, eax
// 00618209  0f8506010000         jne 0x618315
// 0061820f  8a8626010000         mov al, byte ptr [esi + 0x126]
// 00618215  3c03                 cmp al, 3
// 00618217  7570                 jne 0x618289
// 00618219  8a442410             mov al, byte ptr [esp + 0x10]
// 0061821d  888638010000         mov byte ptr [esi + 0x138], al
// 00618223  85ed                 test ebp, ebp
// 00618225  0f84d9000000         je 0x618304
// 0061822b  0fb74d14             movzx ecx, word ptr [ebp + 0x14]
// 0061822f  6685c9               test cx, cx
// 00618232  0f84cc000000         je 0x618304
// 00618238  660fb6d0             movzx dx, al
// 0061823c  663bd1               cmp dx, cx
// 0061823f  7616                 jbe 0x618257
// 00618241  68dc969c00           push 0x9c96dc
// 00618246  56                   push esi
// 00618247  e8f47fffff           call 0x610240
// 0061824c  83c408               add esp, 8
// 0061824f  5b                   pop ebx
// 00618250  5f                   pop edi
// 00618251  5e                   pop esi
// 00618252  5d                   pop ebp
// 00618253  83c408               add esp, 8
// 00618256  c3                   ret 
// 00618257  8b8e14010000         mov ecx, dword ptr [esi + 0x114]
// 0061825d  0fb6c0               movzx eax, al
// 00618260  8d0440               lea eax, [eax + eax*2]
// 00618263  0fb61408             movzx edx, byte ptr [eax + ecx]
// 00618267  03c1                 add eax, ecx
// 00618269  6689963a010000       mov word ptr [esi + 0x13a], dx
// 00618270  660fb64801           movzx cx, byte ptr [eax + 1]
// 00618275  66898e3c010000       mov word ptr [esi + 0x13c], cx
// 0061827c  0fb65002             movzx edx, byte ptr [eax + 2]
// 00618280  6689963e010000       mov word ptr [esi + 0x13e], dx
// 00618287  eb7b                 jmp 0x618304
// 00618289  b900010000           mov ecx, 0x100
// 0061828e  a802                 test al, 2
// 00618290  752a                 jne 0x6182bc
// 00618292  660fb6442410         movzx ax, byte ptr [esp + 0x10]
// 00618298  660fb6542411         movzx dx, byte ptr [esp + 0x11]
// 0061829e  660fafc1             imul ax, cx
// 006182a2  6603c2               add ax, dx
// 006182a5  66898640010000       mov word ptr [esi + 0x140], ax
// 006182ac  6689863c010000       mov word ptr [esi + 0x13c], ax
// 006182b3  6689863a010000       mov word ptr [esi + 0x13a], ax
// 006182ba  eb41                 jmp 0x6182fd
// 006182bc  0fb6442410           movzx eax, byte ptr [esp + 0x10]
// 006182c1  0fb6542411           movzx edx, byte ptr [esp + 0x11]
// 006182c6  660fafc1             imul ax, cx
// 006182ca  6603c2               add ax, dx
// 006182cd  0fb6542413           movzx edx, byte ptr [esp + 0x13]
// 006182d2  6689863a010000       mov word ptr [esi + 0x13a], ax
// 006182d9  0fb6442412           movzx eax, byte ptr [esp + 0x12]
// 006182de  660fafc1             imul ax, cx
// 006182e2  6603c2               add ax, dx
// 006182e5  0fb6542415           movzx edx, byte ptr [esp + 0x15]
// 006182ea  6689863c010000       mov word ptr [esi + 0x13c], ax
// 006182f1  0fb6442414           movzx eax, byte ptr [esp + 0x14]
// 006182f6  660fafc1             imul ax, cx
// 006182fa  6603c2               add ax, dx
// 006182fd  6689863e010000       mov word ptr [esi + 0x13e], ax
// 00618304  8d8638010000         lea eax, [esi + 0x138]
// 0061830a  50                   push eax
// 0061830b  55                   push ebp
// 0061830c  56                   push esi
// 0061830d  e88e9cfeff           call 0x601fa0
// 00618312  83c40c               add esp, 0xc
// 00618315  5b                   pop ebx
// 00618316  5f                   pop edi
// 00618317  5e                   pop esi
// 00618318  5d                   pop ebp
// 00618319  83c408               add esp, 8
// 0061831c  c3                   ret 
// library libpng-1.2.29/pngrutil.c (function _png_handle_bKGD)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.29 pngrutil.c
