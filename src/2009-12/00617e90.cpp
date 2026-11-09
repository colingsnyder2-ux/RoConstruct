// from server: 100% by auto
// roc 2009-12 00617e90  unit: seg_00610000  size: 624 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00617e90
//
// 00617e90  81ec0c010000         sub esp, 0x10c
// 00617e96  53                   push ebx
// 00617e97  8b9c2418010000       mov ebx, dword ptr [esp + 0x118]
// 00617e9e  56                   push esi
// 00617e9f  8bb42418010000       mov esi, dword ptr [esp + 0x118]
// 00617ea6  8b4668               mov eax, dword ptr [esi + 0x68]
// 00617ea9  a801                 test al, 1
// 00617eab  7548                 jne 0x617ef5
// 00617ead  68c0969c00           push 0x9c96c0
// 00617eb2  56                   push esi
// 00617eb3  e8d882ffff           call 0x610190
// 00617eb8  83c408               add esp, 8
// 00617ebb  8a8626010000         mov al, byte ptr [esi + 0x126]
// 00617ec1  57                   push edi
// 00617ec2  84c0                 test al, al
// 00617ec4  0f85d1000000         jne 0x617f9b
// 00617eca  8bbc2424010000       mov edi, dword ptr [esp + 0x124]
// 00617ed1  83ff02               cmp edi, 2
// 00617ed4  7477                 je 0x617f4d
// 00617ed6  68a4969c00           push 0x9c96a4
// 00617edb  56                   push esi
// 00617edc  e85f83ffff           call 0x610240
// 00617ee1  57                   push edi
// 00617ee2  56                   push esi
// 00617ee3  e808edffff           call 0x616bf0
// 00617ee8  83c410               add esp, 0x10
// 00617eeb  5f                   pop edi
// 00617eec  5e                   pop esi
// 00617eed  5b                   pop ebx
// 00617eee  81c40c010000         add esp, 0x10c
// 00617ef4  c3                   ret 
// 00617ef5  a804                 test al, 4
// 00617ef7  7425                 je 0x617f1e
// 00617ef9  688c969c00           push 0x9c968c
// 00617efe  56                   push esi
// 00617eff  e83c83ffff           call 0x610240
// 00617f04  8b842428010000       mov eax, dword ptr [esp + 0x128]
// 00617f0b  50                   push eax
// 00617f0c  56                   push esi
// 00617f0d  e8deecffff           call 0x616bf0
// 00617f12  83c410               add esp, 0x10
// 00617f15  5e                   pop esi
// 00617f16  5b                   pop ebx
// 00617f17  81c40c010000         add esp, 0x10c
// 00617f1d  c3                   ret 
// 00617f1e  85db                 test ebx, ebx
// 00617f20  7499                 je 0x617ebb
// 00617f22  f6430810             test byte ptr [ebx + 8], 0x10
// 00617f26  7493                 je 0x617ebb
// 00617f28  6874969c00           push 0x9c9674
// 00617f2d  56                   push esi
// 00617f2e  e80d83ffff           call 0x610240
// 00617f33  8b8c2428010000       mov ecx, dword ptr [esp + 0x128]
// 00617f3a  51                   push ecx
// 00617f3b  56                   push esi
// 00617f3c  e8afecffff           call 0x616bf0
// 00617f41  83c410               add esp, 0x10
// 00617f44  5e                   pop esi
// 00617f45  5b                   pop ebx
// 00617f46  81c40c010000         add esp, 0x10c
// 00617f4c  c3                   ret 
// 00617f4d  6a02                 push 2
// 00617f4f  8d542410             lea edx, [esp + 0x10]
// 00617f53  52                   push edx
// 00617f54  56                   push esi
// 00617f55  e8362bffff           call 0x60aa90
// 00617f5a  6a02                 push 2
// 00617f5c  8d44241c             lea eax, [esp + 0x1c]
// 00617f60  50                   push eax
// 00617f61  56                   push esi
// 00617f62  e809b7feff           call 0x603670
// 00617f67  668b442424           mov ax, word ptr [esp + 0x24]
// 00617f6c  b901000000           mov ecx, 1
// 00617f71  660fb6d0             movzx dx, al
// 00617f75  66898e1a010000       mov word ptr [esi + 0x11a], cx
// 00617f7c  b900010000           mov ecx, 0x100
// 00617f81  660fafd1             imul dx, cx
// 00617f85  660fb6c4             movzx ax, ah
// 00617f89  83c418               add esp, 0x18
// 00617f8c  6603d0               add dx, ax
// 00617f8f  66899694010000       mov word ptr [esi + 0x194], dx
// 00617f96  e9f5000000           jmp 0x618090
// 00617f9b  3c02                 cmp al, 2
// 00617f9d  757a                 jne 0x618019
// 00617f9f  8bbc2424010000       mov edi, dword ptr [esp + 0x124]
// 00617fa6  83ff06               cmp edi, 6
// 00617fa9  0f8527ffffff         jne 0x617ed6
// 00617faf  57                   push edi
// 00617fb0  8d4c2414             lea ecx, [esp + 0x14]
// 00617fb4  51                   push ecx
// 00617fb5  56                   push esi
// 00617fb6  e8d5daffff           call 0x615a90
// 00617fbb  0fb644241c           movzx eax, byte ptr [esp + 0x1c]
// 00617fc0  b900010000           mov ecx, 0x100
// 00617fc5  660fafc1             imul ax, cx
// 00617fc9  ba01000000           mov edx, 1
// 00617fce  6689961a010000       mov word ptr [esi + 0x11a], dx
// 00617fd5  0fb654241d           movzx edx, byte ptr [esp + 0x1d]
// 00617fda  6603c2               add ax, dx
// 00617fdd  0fb654241f           movzx edx, byte ptr [esp + 0x1f]
// 00617fe2  6689868e010000       mov word ptr [esi + 0x18e], ax
// 00617fe9  0fb644241e           movzx eax, byte ptr [esp + 0x1e]
// 00617fee  660fafc1             imul ax, cx
// 00617ff2  6603c2               add ax, dx
// 00617ff5  0fb6542421           movzx edx, byte ptr [esp + 0x21]
// 00617ffa  66898690010000       mov word ptr [esi + 0x190], ax
// 00618001  0fb6442420           movzx eax, byte ptr [esp + 0x20]
// 00618006  660fafc1             imul ax, cx
// 0061800a  83c40c               add esp, 0xc
// 0061800d  6603c2               add ax, dx
// 00618010  66898692010000       mov word ptr [esi + 0x192], ax
// 00618017  eb77                 jmp 0x618090
// 00618019  3c03                 cmp al, 3
// 0061801b  0f85b9000000         jne 0x6180da
// 00618021  f6466802             test byte ptr [esi + 0x68], 2
// 00618025  750e                 jne 0x618035
// 00618027  6858969c00           push 0x9c9658
// 0061802c  56                   push esi
// 0061802d  e80e82ffff           call 0x610240
// 00618032  83c408               add esp, 8
// 00618035  0fb78618010000       movzx eax, word ptr [esi + 0x118]
// 0061803c  8bbc2424010000       mov edi, dword ptr [esp + 0x124]
// 00618043  3bf8                 cmp edi, eax
// 00618045  0f878bfeffff         ja 0x617ed6
// 0061804b  81ff00010000         cmp edi, 0x100
// 00618051  0f877ffeffff         ja 0x617ed6
// 00618057  85ff                 test edi, edi
// 00618059  751f                 jne 0x61807a
// 0061805b  6840969c00           push 0x9c9640
// 00618060  56                   push esi
// 00618061  e8da81ffff           call 0x610240
// 00618066  57                   push edi
// 00618067  56                   push esi
// 00618068  e883ebffff           call 0x616bf0
// 0061806d  83c410               add esp, 0x10
// 00618070  5f                   pop edi
// 00618071  5e                   pop esi
// 00618072  5b                   pop ebx
// 00618073  81c40c010000         add esp, 0x10c
// 00618079  c3                   ret 
// 0061807a  57                   push edi
// 0061807b  8d4c241c             lea ecx, [esp + 0x1c]
// 0061807f  51                   push ecx
// 00618080  56                   push esi
// 00618081  e80adaffff           call 0x615a90
// 00618086  83c40c               add esp, 0xc
// 00618089  6689be1a010000       mov word ptr [esi + 0x11a], di
// 00618090  6a00                 push 0
// 00618092  56                   push esi
// 00618093  e858ebffff           call 0x616bf0
// 00618098  83c408               add esp, 8
// 0061809b  85c0                 test eax, eax
// 0061809d  7413                 je 0x6180b2
// 0061809f  33d2                 xor edx, edx
// 006180a1  5f                   pop edi
// 006180a2  6689961a010000       mov word ptr [esi + 0x11a], dx
// 006180a9  5e                   pop esi
// 006180aa  5b                   pop ebx
// 006180ab  81c40c010000         add esp, 0x10c
// 006180b1  c3                   ret 
// 006180b2  0fb78e1a010000       movzx ecx, word ptr [esi + 0x11a]
// 006180b9  8d868c010000         lea eax, [esi + 0x18c]
// 006180bf  50                   push eax
// 006180c0  51                   push ecx
// 006180c1  8d542420             lea edx, [esp + 0x20]
// 006180c5  52                   push edx
// 006180c6  53                   push ebx
// 006180c7  56                   push esi
// 006180c8  e8f3aefeff           call 0x602fc0
// 006180cd  83c414               add esp, 0x14
// 006180d0  5f                   pop edi
// 006180d1  5e                   pop esi
// 006180d2  5b                   pop ebx
// 006180d3  81c40c010000         add esp, 0x10c
// 006180d9  c3                   ret 
// 006180da  6814969c00           push 0x9c9614
// 006180df  56                   push esi
// 006180e0  e85b81ffff           call 0x610240
// 006180e5  8b84242c010000       mov eax, dword ptr [esp + 0x12c]
// 006180ec  50                   push eax
// 006180ed  56                   push esi
// 006180ee  e8fdeaffff           call 0x616bf0
// 006180f3  83c410               add esp, 0x10
// 006180f6  5f                   pop edi
// 006180f7  5e                   pop esi
// 006180f8  5b                   pop ebx
// 006180f9  81c40c010000         add esp, 0x10c
// 006180ff  c3                   ret 
// library libpng-1.2.18/pngrutil.c (function _png_handle_tRNS)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.18 pngrutil.c
