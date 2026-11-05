// from server: 100% by auto
// roc 2011-06 00570d30  unit: seg_00570000  size: 541 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00570d30
//
// 00570d30  83ec08               sub esp, 8
// 00570d33  55                   push ebp
// 00570d34  8b6c2414             mov ebp, dword ptr [esp + 0x14]
// 00570d38  56                   push esi
// 00570d39  8b742414             mov esi, dword ptr [esp + 0x14]
// 00570d3d  8b4668               mov eax, dword ptr [esi + 0x68]
// 00570d40  a801                 test al, 1
// 00570d42  7527                 jne 0x570d6b
// 00570d44  68606ba800           push 0xa86b60
// 00570d49  56                   push esi
// 00570d4a  e8e105ffff           call 0x561330
// 00570d4f  83c408               add esp, 8
// 00570d52  8a8626010000         mov al, byte ptr [esi + 0x126]
// 00570d58  57                   push edi
// 00570d59  3c03                 cmp al, 3
// 00570d5b  0f8582000000         jne 0x570de3
// 00570d61  bf01000000           mov edi, 1
// 00570d66  e983000000           jmp 0x570dee
// 00570d6b  a804                 test al, 4
// 00570d6d  741f                 je 0x570d8e
// 00570d6f  68486ba800           push 0xa86b48
// 00570d74  56                   push esi
// 00570d75  e86606ffff           call 0x5613e0
// 00570d7a  8b442424             mov eax, dword ptr [esp + 0x24]
// 00570d7e  50                   push eax
// 00570d7f  56                   push esi
// 00570d80  e8bbeaffff           call 0x56f840
// 00570d85  83c410               add esp, 0x10
// 00570d88  5e                   pop esi
// 00570d89  5d                   pop ebp
// 00570d8a  83c408               add esp, 8
// 00570d8d  c3                   ret 
// 00570d8e  80be2601000003       cmp byte ptr [esi + 0x126], 3
// 00570d95  7523                 jne 0x570dba
// 00570d97  a802                 test al, 2
// 00570d99  751f                 jne 0x570dba
// 00570d9b  682c6ba800           push 0xa86b2c
// 00570da0  56                   push esi
// 00570da1  e83a06ffff           call 0x5613e0
// 00570da6  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 00570daa  51                   push ecx
// 00570dab  56                   push esi
// 00570dac  e88feaffff           call 0x56f840
// 00570db1  83c410               add esp, 0x10
// 00570db4  5e                   pop esi
// 00570db5  5d                   pop ebp
// 00570db6  83c408               add esp, 8
// 00570db9  c3                   ret 
// 00570dba  85ed                 test ebp, ebp
// 00570dbc  7494                 je 0x570d52
// 00570dbe  f6450820             test byte ptr [ebp + 8], 0x20
// 00570dc2  748e                 je 0x570d52
// 00570dc4  68146ba800           push 0xa86b14
// 00570dc9  56                   push esi
// 00570dca  e81106ffff           call 0x5613e0
// 00570dcf  8b542424             mov edx, dword ptr [esp + 0x24]
// 00570dd3  52                   push edx
// 00570dd4  56                   push esi
// 00570dd5  e866eaffff           call 0x56f840
// 00570dda  83c410               add esp, 0x10
// 00570ddd  5e                   pop esi
// 00570dde  5d                   pop ebp
// 00570ddf  83c408               add esp, 8
// 00570de2  c3                   ret 
// 00570de3  0fb6f8               movzx edi, al
// 00570de6  83e702               and edi, 2
// 00570de9  83cf01               or edi, 1
// 00570dec  03ff                 add edi, edi
// 00570dee  53                   push ebx
// 00570def  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 00570df3  3bdf                 cmp ebx, edi
// 00570df5  741d                 je 0x570e14
// 00570df7  68f86aa800           push 0xa86af8
// 00570dfc  56                   push esi
// 00570dfd  e8de05ffff           call 0x5613e0
// 00570e02  53                   push ebx
// 00570e03  56                   push esi
// 00570e04  e837eaffff           call 0x56f840
// 00570e09  83c410               add esp, 0x10
// 00570e0c  5b                   pop ebx
// 00570e0d  5f                   pop edi
// 00570e0e  5e                   pop esi
// 00570e0f  5d                   pop ebp
// 00570e10  83c408               add esp, 8
// 00570e13  c3                   ret 
// 00570e14  57                   push edi
// 00570e15  8d442414             lea eax, [esp + 0x14]
// 00570e19  50                   push eax
// 00570e1a  56                   push esi
// 00570e1b  e85001ffff           call 0x560f70
// 00570e20  57                   push edi
// 00570e21  8d4c2420             lea ecx, [esp + 0x20]
// 00570e25  51                   push ecx
// 00570e26  56                   push esi
// 00570e27  e824fafdff           call 0x550850
// 00570e2c  6a00                 push 0
// 00570e2e  56                   push esi
// 00570e2f  e80ceaffff           call 0x56f840
// 00570e34  83c420               add esp, 0x20
// 00570e37  85c0                 test eax, eax
// 00570e39  0f8506010000         jne 0x570f45
// 00570e3f  8a8626010000         mov al, byte ptr [esi + 0x126]
// 00570e45  3c03                 cmp al, 3
// 00570e47  7570                 jne 0x570eb9
// 00570e49  8a442410             mov al, byte ptr [esp + 0x10]
// 00570e4d  888638010000         mov byte ptr [esi + 0x138], al
// 00570e53  85ed                 test ebp, ebp
// 00570e55  0f84d9000000         je 0x570f34
// 00570e5b  0fb74d14             movzx ecx, word ptr [ebp + 0x14]
// 00570e5f  6685c9               test cx, cx
// 00570e62  0f84cc000000         je 0x570f34
// 00570e68  660fb6d0             movzx dx, al
// 00570e6c  663bd1               cmp dx, cx
// 00570e6f  7216                 jb 0x570e87
// 00570e71  68d46aa800           push 0xa86ad4
// 00570e76  56                   push esi
// 00570e77  e86405ffff           call 0x5613e0
// 00570e7c  83c408               add esp, 8
// 00570e7f  5b                   pop ebx
// 00570e80  5f                   pop edi
// 00570e81  5e                   pop esi
// 00570e82  5d                   pop ebp
// 00570e83  83c408               add esp, 8
// 00570e86  c3                   ret 
// 00570e87  8b8e14010000         mov ecx, dword ptr [esi + 0x114]
// 00570e8d  0fb6c0               movzx eax, al
// 00570e90  8d0440               lea eax, [eax + eax*2]
// 00570e93  0fb61408             movzx edx, byte ptr [eax + ecx]
// 00570e97  03c1                 add eax, ecx
// 00570e99  6689963a010000       mov word ptr [esi + 0x13a], dx
// 00570ea0  660fb64801           movzx cx, byte ptr [eax + 1]
// 00570ea5  66898e3c010000       mov word ptr [esi + 0x13c], cx
// 00570eac  0fb65002             movzx edx, byte ptr [eax + 2]
// 00570eb0  6689963e010000       mov word ptr [esi + 0x13e], dx
// 00570eb7  eb7b                 jmp 0x570f34
// 00570eb9  b900010000           mov ecx, 0x100
// 00570ebe  a802                 test al, 2
// 00570ec0  752a                 jne 0x570eec
// 00570ec2  660fb6442410         movzx ax, byte ptr [esp + 0x10]
// 00570ec8  660fb6542411         movzx dx, byte ptr [esp + 0x11]
// 00570ece  660fafc1             imul ax, cx
// 00570ed2  6603c2               add ax, dx
// 00570ed5  66898640010000       mov word ptr [esi + 0x140], ax
// 00570edc  6689863c010000       mov word ptr [esi + 0x13c], ax
// 00570ee3  6689863a010000       mov word ptr [esi + 0x13a], ax
// 00570eea  eb41                 jmp 0x570f2d
// 00570eec  0fb6442410           movzx eax, byte ptr [esp + 0x10]
// 00570ef1  0fb6542411           movzx edx, byte ptr [esp + 0x11]
// 00570ef6  660fafc1             imul ax, cx
// 00570efa  6603c2               add ax, dx
// 00570efd  0fb6542413           movzx edx, byte ptr [esp + 0x13]
// 00570f02  6689863a010000       mov word ptr [esi + 0x13a], ax
// 00570f09  0fb6442412           movzx eax, byte ptr [esp + 0x12]
// 00570f0e  660fafc1             imul ax, cx
// 00570f12  6603c2               add ax, dx
// 00570f15  0fb6542415           movzx edx, byte ptr [esp + 0x15]
// 00570f1a  6689863c010000       mov word ptr [esi + 0x13c], ax
// 00570f21  0fb6442414           movzx eax, byte ptr [esp + 0x14]
// 00570f26  660fafc1             imul ax, cx
// 00570f2a  6603c2               add ax, dx
// 00570f2d  6689863e010000       mov word ptr [esi + 0x13e], ax
// 00570f34  8d8638010000         lea eax, [esi + 0x138]
// 00570f3a  50                   push eax
// 00570f3b  55                   push ebp
// 00570f3c  56                   push esi
// 00570f3d  e8be87feff           call 0x559700
// 00570f42  83c40c               add esp, 0xc
// 00570f45  5b                   pop ebx
// 00570f46  5f                   pop edi
// 00570f47  5e                   pop esi
// 00570f48  5d                   pop ebp
// 00570f49  83c408               add esp, 8
// 00570f4c  c3                   ret 
// library libpng-1.2.35/pngrutil.c (function _png_handle_bKGD)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.35 pngrutil.c
