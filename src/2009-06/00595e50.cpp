// from server: 100% by auto
// roc 2009-06 00595e50  unit: seg_00590000  size: 624 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00595e50
//
// 00595e50  81ec0c010000         sub esp, 0x10c
// 00595e56  53                   push ebx
// 00595e57  8b9c2418010000       mov ebx, dword ptr [esp + 0x118]
// 00595e5e  56                   push esi
// 00595e5f  8bb42418010000       mov esi, dword ptr [esp + 0x118]
// 00595e66  8b4668               mov eax, dword ptr [esi + 0x68]
// 00595e69  a801                 test al, 1
// 00595e6b  7548                 jne 0x595eb5
// 00595e6d  6830288d00           push 0x8d2830
// 00595e72  56                   push esi
// 00595e73  e8e882ffff           call 0x58e160
// 00595e78  83c408               add esp, 8
// 00595e7b  8a8626010000         mov al, byte ptr [esi + 0x126]
// 00595e81  57                   push edi
// 00595e82  84c0                 test al, al
// 00595e84  0f85d1000000         jne 0x595f5b
// 00595e8a  8bbc2424010000       mov edi, dword ptr [esp + 0x124]
// 00595e91  83ff02               cmp edi, 2
// 00595e94  7477                 je 0x595f0d
// 00595e96  6814288d00           push 0x8d2814
// 00595e9b  56                   push esi
// 00595e9c  e86f83ffff           call 0x58e210
// 00595ea1  57                   push edi
// 00595ea2  56                   push esi
// 00595ea3  e838edffff           call 0x594be0
// 00595ea8  83c410               add esp, 0x10
// 00595eab  5f                   pop edi
// 00595eac  5e                   pop esi
// 00595ead  5b                   pop ebx
// 00595eae  81c40c010000         add esp, 0x10c
// 00595eb4  c3                   ret 
// 00595eb5  a804                 test al, 4
// 00595eb7  7425                 je 0x595ede
// 00595eb9  68fc278d00           push 0x8d27fc
// 00595ebe  56                   push esi
// 00595ebf  e84c83ffff           call 0x58e210
// 00595ec4  8b842428010000       mov eax, dword ptr [esp + 0x128]
// 00595ecb  50                   push eax
// 00595ecc  56                   push esi
// 00595ecd  e80eedffff           call 0x594be0
// 00595ed2  83c410               add esp, 0x10
// 00595ed5  5e                   pop esi
// 00595ed6  5b                   pop ebx
// 00595ed7  81c40c010000         add esp, 0x10c
// 00595edd  c3                   ret 
// 00595ede  85db                 test ebx, ebx
// 00595ee0  7499                 je 0x595e7b
// 00595ee2  f6430810             test byte ptr [ebx + 8], 0x10
// 00595ee6  7493                 je 0x595e7b
// 00595ee8  68e4278d00           push 0x8d27e4
// 00595eed  56                   push esi
// 00595eee  e81d83ffff           call 0x58e210
// 00595ef3  8b8c2428010000       mov ecx, dword ptr [esp + 0x128]
// 00595efa  51                   push ecx
// 00595efb  56                   push esi
// 00595efc  e8dfecffff           call 0x594be0
// 00595f01  83c410               add esp, 0x10
// 00595f04  5e                   pop esi
// 00595f05  5b                   pop ebx
// 00595f06  81c40c010000         add esp, 0x10c
// 00595f0c  c3                   ret 
// 00595f0d  6a02                 push 2
// 00595f0f  8d542410             lea edx, [esp + 0x10]
// 00595f13  52                   push edx
// 00595f14  56                   push esi
// 00595f15  e8e62dffff           call 0x588d00
// 00595f1a  6a02                 push 2
// 00595f1c  8d44241c             lea eax, [esp + 0x1c]
// 00595f20  50                   push eax
// 00595f21  56                   push esi
// 00595f22  e899b9feff           call 0x5818c0
// 00595f27  668b442424           mov ax, word ptr [esp + 0x24]
// 00595f2c  b901000000           mov ecx, 1
// 00595f31  660fb6d0             movzx dx, al
// 00595f35  66898e1a010000       mov word ptr [esi + 0x11a], cx
// 00595f3c  b900010000           mov ecx, 0x100
// 00595f41  660fafd1             imul dx, cx
// 00595f45  660fb6c4             movzx ax, ah
// 00595f49  83c418               add esp, 0x18
// 00595f4c  6603d0               add dx, ax
// 00595f4f  66899694010000       mov word ptr [esi + 0x194], dx
// 00595f56  e9f5000000           jmp 0x596050
// 00595f5b  3c02                 cmp al, 2
// 00595f5d  757a                 jne 0x595fd9
// 00595f5f  8bbc2424010000       mov edi, dword ptr [esp + 0x124]
// 00595f66  83ff06               cmp edi, 6
// 00595f69  0f8527ffffff         jne 0x595e96
// 00595f6f  57                   push edi
// 00595f70  8d4c2414             lea ecx, [esp + 0x14]
// 00595f74  51                   push ecx
// 00595f75  56                   push esi
// 00595f76  e805dbffff           call 0x593a80
// 00595f7b  0fb644241c           movzx eax, byte ptr [esp + 0x1c]
// 00595f80  b900010000           mov ecx, 0x100
// 00595f85  660fafc1             imul ax, cx
// 00595f89  ba01000000           mov edx, 1
// 00595f8e  6689961a010000       mov word ptr [esi + 0x11a], dx
// 00595f95  0fb654241d           movzx edx, byte ptr [esp + 0x1d]
// 00595f9a  6603c2               add ax, dx
// 00595f9d  0fb654241f           movzx edx, byte ptr [esp + 0x1f]
// 00595fa2  6689868e010000       mov word ptr [esi + 0x18e], ax
// 00595fa9  0fb644241e           movzx eax, byte ptr [esp + 0x1e]
// 00595fae  660fafc1             imul ax, cx
// 00595fb2  6603c2               add ax, dx
// 00595fb5  0fb6542421           movzx edx, byte ptr [esp + 0x21]
// 00595fba  66898690010000       mov word ptr [esi + 0x190], ax
// 00595fc1  0fb6442420           movzx eax, byte ptr [esp + 0x20]
// 00595fc6  660fafc1             imul ax, cx
// 00595fca  83c40c               add esp, 0xc
// 00595fcd  6603c2               add ax, dx
// 00595fd0  66898692010000       mov word ptr [esi + 0x192], ax
// 00595fd7  eb77                 jmp 0x596050
// 00595fd9  3c03                 cmp al, 3
// 00595fdb  0f85b9000000         jne 0x59609a
// 00595fe1  f6466802             test byte ptr [esi + 0x68], 2
// 00595fe5  750e                 jne 0x595ff5
// 00595fe7  68c8278d00           push 0x8d27c8
// 00595fec  56                   push esi
// 00595fed  e81e82ffff           call 0x58e210
// 00595ff2  83c408               add esp, 8
// 00595ff5  0fb78618010000       movzx eax, word ptr [esi + 0x118]
// 00595ffc  8bbc2424010000       mov edi, dword ptr [esp + 0x124]
// 00596003  3bf8                 cmp edi, eax
// 00596005  0f878bfeffff         ja 0x595e96
// 0059600b  81ff00010000         cmp edi, 0x100
// 00596011  0f877ffeffff         ja 0x595e96
// 00596017  85ff                 test edi, edi
// 00596019  751f                 jne 0x59603a
// 0059601b  68b0278d00           push 0x8d27b0
// 00596020  56                   push esi
// 00596021  e8ea81ffff           call 0x58e210
// 00596026  57                   push edi
// 00596027  56                   push esi
// 00596028  e8b3ebffff           call 0x594be0
// 0059602d  83c410               add esp, 0x10
// 00596030  5f                   pop edi
// 00596031  5e                   pop esi
// 00596032  5b                   pop ebx
// 00596033  81c40c010000         add esp, 0x10c
// 00596039  c3                   ret 
// 0059603a  57                   push edi
// 0059603b  8d4c241c             lea ecx, [esp + 0x1c]
// 0059603f  51                   push ecx
// 00596040  56                   push esi
// 00596041  e83adaffff           call 0x593a80
// 00596046  83c40c               add esp, 0xc
// 00596049  6689be1a010000       mov word ptr [esi + 0x11a], di
// 00596050  6a00                 push 0
// 00596052  56                   push esi
// 00596053  e888ebffff           call 0x594be0
// 00596058  83c408               add esp, 8
// 0059605b  85c0                 test eax, eax
// 0059605d  7413                 je 0x596072
// 0059605f  33d2                 xor edx, edx
// 00596061  5f                   pop edi
// 00596062  6689961a010000       mov word ptr [esi + 0x11a], dx
// 00596069  5e                   pop esi
// 0059606a  5b                   pop ebx
// 0059606b  81c40c010000         add esp, 0x10c
// 00596071  c3                   ret 
// 00596072  0fb78e1a010000       movzx ecx, word ptr [esi + 0x11a]
// 00596079  8d868c010000         lea eax, [esi + 0x18c]
// 0059607f  50                   push eax
// 00596080  51                   push ecx
// 00596081  8d542420             lea edx, [esp + 0x20]
// 00596085  52                   push edx
// 00596086  53                   push ebx
// 00596087  56                   push esi
// 00596088  e883b1feff           call 0x581210
// 0059608d  83c414               add esp, 0x14
// 00596090  5f                   pop edi
// 00596091  5e                   pop esi
// 00596092  5b                   pop ebx
// 00596093  81c40c010000         add esp, 0x10c
// 00596099  c3                   ret 
// 0059609a  6884278d00           push 0x8d2784
// 0059609f  56                   push esi
// 005960a0  e86b81ffff           call 0x58e210
// 005960a5  8b84242c010000       mov eax, dword ptr [esp + 0x12c]
// 005960ac  50                   push eax
// 005960ad  56                   push esi
// 005960ae  e82debffff           call 0x594be0
// 005960b3  83c410               add esp, 0x10
// 005960b6  5f                   pop edi
// 005960b7  5e                   pop esi
// 005960b8  5b                   pop ebx
// 005960b9  81c40c010000         add esp, 0x10c
// 005960bf  c3                   ret 
// library libpng-1.2.18/pngrutil.c (function _png_handle_tRNS)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.18 pngrutil.c
