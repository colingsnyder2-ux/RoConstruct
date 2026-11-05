// from server: 100% by auto
// roc 2010-06 00579a20  unit: seg_00570000  size: 541 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00579a20
//
// 00579a20  83ec08               sub esp, 8
// 00579a23  55                   push ebp
// 00579a24  8b6c2414             mov ebp, dword ptr [esp + 0x14]
// 00579a28  56                   push esi
// 00579a29  8b742414             mov esi, dword ptr [esp + 0x14]
// 00579a2d  8b4668               mov eax, dword ptr [esi + 0x68]
// 00579a30  a801                 test al, 1
// 00579a32  7527                 jne 0x579a5b
// 00579a34  68e074a200           push 0xa274e0
// 00579a39  56                   push esi
// 00579a3a  e87180ffff           call 0x571ab0
// 00579a3f  83c408               add esp, 8
// 00579a42  8a8626010000         mov al, byte ptr [esi + 0x126]
// 00579a48  57                   push edi
// 00579a49  3c03                 cmp al, 3
// 00579a4b  0f8582000000         jne 0x579ad3
// 00579a51  bf01000000           mov edi, 1
// 00579a56  e983000000           jmp 0x579ade
// 00579a5b  a804                 test al, 4
// 00579a5d  741f                 je 0x579a7e
// 00579a5f  68c874a200           push 0xa274c8
// 00579a64  56                   push esi
// 00579a65  e8f680ffff           call 0x571b60
// 00579a6a  8b442424             mov eax, dword ptr [esp + 0x24]
// 00579a6e  50                   push eax
// 00579a6f  56                   push esi
// 00579a70  e89beaffff           call 0x578510
// 00579a75  83c410               add esp, 0x10
// 00579a78  5e                   pop esi
// 00579a79  5d                   pop ebp
// 00579a7a  83c408               add esp, 8
// 00579a7d  c3                   ret 
// 00579a7e  80be2601000003       cmp byte ptr [esi + 0x126], 3
// 00579a85  7523                 jne 0x579aaa
// 00579a87  a802                 test al, 2
// 00579a89  751f                 jne 0x579aaa
// 00579a8b  68ac74a200           push 0xa274ac
// 00579a90  56                   push esi
// 00579a91  e8ca80ffff           call 0x571b60
// 00579a96  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 00579a9a  51                   push ecx
// 00579a9b  56                   push esi
// 00579a9c  e86feaffff           call 0x578510
// 00579aa1  83c410               add esp, 0x10
// 00579aa4  5e                   pop esi
// 00579aa5  5d                   pop ebp
// 00579aa6  83c408               add esp, 8
// 00579aa9  c3                   ret 
// 00579aaa  85ed                 test ebp, ebp
// 00579aac  7494                 je 0x579a42
// 00579aae  f6450820             test byte ptr [ebp + 8], 0x20
// 00579ab2  748e                 je 0x579a42
// 00579ab4  689474a200           push 0xa27494
// 00579ab9  56                   push esi
// 00579aba  e8a180ffff           call 0x571b60
// 00579abf  8b542424             mov edx, dword ptr [esp + 0x24]
// 00579ac3  52                   push edx
// 00579ac4  56                   push esi
// 00579ac5  e846eaffff           call 0x578510
// 00579aca  83c410               add esp, 0x10
// 00579acd  5e                   pop esi
// 00579ace  5d                   pop ebp
// 00579acf  83c408               add esp, 8
// 00579ad2  c3                   ret 
// 00579ad3  0fb6f8               movzx edi, al
// 00579ad6  83e702               and edi, 2
// 00579ad9  83cf01               or edi, 1
// 00579adc  03ff                 add edi, edi
// 00579ade  53                   push ebx
// 00579adf  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 00579ae3  3bdf                 cmp ebx, edi
// 00579ae5  741d                 je 0x579b04
// 00579ae7  687874a200           push 0xa27478
// 00579aec  56                   push esi
// 00579aed  e86e80ffff           call 0x571b60
// 00579af2  53                   push ebx
// 00579af3  56                   push esi
// 00579af4  e817eaffff           call 0x578510
// 00579af9  83c410               add esp, 0x10
// 00579afc  5b                   pop ebx
// 00579afd  5f                   pop edi
// 00579afe  5e                   pop esi
// 00579aff  5d                   pop ebp
// 00579b00  83c408               add esp, 8
// 00579b03  c3                   ret 
// 00579b04  57                   push edi
// 00579b05  8d442414             lea eax, [esp + 0x14]
// 00579b09  50                   push eax
// 00579b0a  56                   push esi
// 00579b0b  e80029ffff           call 0x56c410
// 00579b10  57                   push edi
// 00579b11  8d4c2420             lea ecx, [esp + 0x20]
// 00579b15  51                   push ecx
// 00579b16  56                   push esi
// 00579b17  e8c4b4feff           call 0x564fe0
// 00579b1c  6a00                 push 0
// 00579b1e  56                   push esi
// 00579b1f  e8ece9ffff           call 0x578510
// 00579b24  83c420               add esp, 0x20
// 00579b27  85c0                 test eax, eax
// 00579b29  0f8506010000         jne 0x579c35
// 00579b2f  8a8626010000         mov al, byte ptr [esi + 0x126]
// 00579b35  3c03                 cmp al, 3
// 00579b37  7570                 jne 0x579ba9
// 00579b39  8a442410             mov al, byte ptr [esp + 0x10]
// 00579b3d  888638010000         mov byte ptr [esi + 0x138], al
// 00579b43  85ed                 test ebp, ebp
// 00579b45  0f84d9000000         je 0x579c24
// 00579b4b  0fb74d14             movzx ecx, word ptr [ebp + 0x14]
// 00579b4f  6685c9               test cx, cx
// 00579b52  0f84cc000000         je 0x579c24
// 00579b58  660fb6d0             movzx dx, al
// 00579b5c  663bd1               cmp dx, cx
// 00579b5f  7616                 jbe 0x579b77
// 00579b61  685474a200           push 0xa27454
// 00579b66  56                   push esi
// 00579b67  e8f47fffff           call 0x571b60
// 00579b6c  83c408               add esp, 8
// 00579b6f  5b                   pop ebx
// 00579b70  5f                   pop edi
// 00579b71  5e                   pop esi
// 00579b72  5d                   pop ebp
// 00579b73  83c408               add esp, 8
// 00579b76  c3                   ret 
// 00579b77  8b8e14010000         mov ecx, dword ptr [esi + 0x114]
// 00579b7d  0fb6c0               movzx eax, al
// 00579b80  8d0440               lea eax, [eax + eax*2]
// 00579b83  0fb61408             movzx edx, byte ptr [eax + ecx]
// 00579b87  03c1                 add eax, ecx
// 00579b89  6689963a010000       mov word ptr [esi + 0x13a], dx
// 00579b90  660fb64801           movzx cx, byte ptr [eax + 1]
// 00579b95  66898e3c010000       mov word ptr [esi + 0x13c], cx
// 00579b9c  0fb65002             movzx edx, byte ptr [eax + 2]
// 00579ba0  6689963e010000       mov word ptr [esi + 0x13e], dx
// 00579ba7  eb7b                 jmp 0x579c24
// 00579ba9  b900010000           mov ecx, 0x100
// 00579bae  a802                 test al, 2
// 00579bb0  752a                 jne 0x579bdc
// 00579bb2  660fb6442410         movzx ax, byte ptr [esp + 0x10]
// 00579bb8  660fb6542411         movzx dx, byte ptr [esp + 0x11]
// 00579bbe  660fafc1             imul ax, cx
// 00579bc2  6603c2               add ax, dx
// 00579bc5  66898640010000       mov word ptr [esi + 0x140], ax
// 00579bcc  6689863c010000       mov word ptr [esi + 0x13c], ax
// 00579bd3  6689863a010000       mov word ptr [esi + 0x13a], ax
// 00579bda  eb41                 jmp 0x579c1d
// 00579bdc  0fb6442410           movzx eax, byte ptr [esp + 0x10]
// 00579be1  0fb6542411           movzx edx, byte ptr [esp + 0x11]
// 00579be6  660fafc1             imul ax, cx
// 00579bea  6603c2               add ax, dx
// 00579bed  0fb6542413           movzx edx, byte ptr [esp + 0x13]
// 00579bf2  6689863a010000       mov word ptr [esi + 0x13a], ax
// 00579bf9  0fb6442412           movzx eax, byte ptr [esp + 0x12]
// 00579bfe  660fafc1             imul ax, cx
// 00579c02  6603c2               add ax, dx
// 00579c05  0fb6542415           movzx edx, byte ptr [esp + 0x15]
// 00579c0a  6689863c010000       mov word ptr [esi + 0x13c], ax
// 00579c11  0fb6442414           movzx eax, byte ptr [esp + 0x14]
// 00579c16  660fafc1             imul ax, cx
// 00579c1a  6603c2               add ax, dx
// 00579c1d  6689863e010000       mov word ptr [esi + 0x13e], ax
// 00579c24  8d8638010000         lea eax, [esi + 0x138]
// 00579c2a  50                   push eax
// 00579c2b  55                   push ebp
// 00579c2c  56                   push esi
// 00579c2d  e8de9cfeff           call 0x563910
// 00579c32  83c40c               add esp, 0xc
// 00579c35  5b                   pop ebx
// 00579c36  5f                   pop edi
// 00579c37  5e                   pop esi
// 00579c38  5d                   pop ebp
// 00579c39  83c408               add esp, 8
// 00579c3c  c3                   ret 
// library libpng-1.2.29/pngrutil.c (function _png_handle_bKGD)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.29 pngrutil.c
