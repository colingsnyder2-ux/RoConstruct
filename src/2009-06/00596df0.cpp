// from server: 100% by auto
// roc 2009-06 00596df0  unit: seg_00590000  size: 436 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00596df0
//
// 00596df0  53                   push ebx
// 00596df1  55                   push ebp
// 00596df2  56                   push esi
// 00596df3  8b742410             mov esi, dword ptr [esp + 0x10]
// 00596df7  f6466801             test byte ptr [esi + 0x68], 1
// 00596dfb  57                   push edi
// 00596dfc  750e                 jne 0x596e0c
// 00596dfe  68a42d8d00           push 0x8d2da4
// 00596e03  56                   push esi
// 00596e04  e85773ffff           call 0x58e160
// 00596e09  83c408               add esp, 8
// 00596e0c  8b4668               mov eax, dword ptr [esi + 0x68]
// 00596e0f  a804                 test al, 4
// 00596e11  7406                 je 0x596e19
// 00596e13  83c808               or eax, 8
// 00596e16  894668               mov dword ptr [esi + 0x68], eax
// 00596e19  8b8688020000         mov eax, dword ptr [esi + 0x288]
// 00596e1f  50                   push eax
// 00596e20  56                   push esi
// 00596e21  e88a7effff           call 0x58ecb0
// 00596e26  8b6c2424             mov ebp, dword ptr [esp + 0x24]
// 00596e2a  8d4d01               lea ecx, [ebp + 1]
// 00596e2d  51                   push ecx
// 00596e2e  56                   push esi
// 00596e2f  e8ac7effff           call 0x58ece0
// 00596e34  8bf8                 mov edi, eax
// 00596e36  33db                 xor ebx, ebx
// 00596e38  83c410               add esp, 0x10
// 00596e3b  89be88020000         mov dword ptr [esi + 0x288], edi
// 00596e41  3bfb                 cmp edi, ebx
// 00596e43  7513                 jne 0x596e58
// 00596e45  687c2d8d00           push 0x8d2d7c
// 00596e4a  56                   push esi
// 00596e4b  e8c073ffff           call 0x58e210
// 00596e50  83c408               add esp, 8
// 00596e53  5f                   pop edi
// 00596e54  5e                   pop esi
// 00596e55  5d                   pop ebp
// 00596e56  5b                   pop ebx
// 00596e57  c3                   ret 
// 00596e58  55                   push ebp
// 00596e59  57                   push edi
// 00596e5a  56                   push esi
// 00596e5b  e8a01effff           call 0x588d00
// 00596e60  55                   push ebp
// 00596e61  57                   push edi
// 00596e62  56                   push esi
// 00596e63  e858aafeff           call 0x5818c0
// 00596e68  53                   push ebx
// 00596e69  56                   push esi
// 00596e6a  e871ddffff           call 0x594be0
// 00596e6f  83c420               add esp, 0x20
// 00596e72  85c0                 test eax, eax
// 00596e74  741b                 je 0x596e91
// 00596e76  8b9688020000         mov edx, dword ptr [esi + 0x288]
// 00596e7c  52                   push edx
// 00596e7d  56                   push esi
// 00596e7e  e82d7effff           call 0x58ecb0
// 00596e83  83c408               add esp, 8
// 00596e86  5f                   pop edi
// 00596e87  899e88020000         mov dword ptr [esi + 0x288], ebx
// 00596e8d  5e                   pop esi
// 00596e8e  5d                   pop ebp
// 00596e8f  5b                   pop ebx
// 00596e90  c3                   ret 
// 00596e91  8b8688020000         mov eax, dword ptr [esi + 0x288]
// 00596e97  881c28               mov byte ptr [eax + ebp], bl
// 00596e9a  8b8688020000         mov eax, dword ptr [esi + 0x288]
// 00596ea0  8bf8                 mov edi, eax
// 00596ea2  381f                 cmp byte ptr [edi], bl
// 00596ea4  7405                 je 0x596eab
// 00596ea6  47                   inc edi
// 00596ea7  381f                 cmp byte ptr [edi], bl
// 00596ea9  75fb                 jne 0x596ea6
// 00596eab  8d4c28fe             lea ecx, [eax + ebp - 2]
// 00596eaf  3bf9                 cmp edi, ecx
// 00596eb1  7226                 jb 0x596ed9
// 00596eb3  68642d8d00           push 0x8d2d64
// 00596eb8  56                   push esi
// 00596eb9  e85273ffff           call 0x58e210
// 00596ebe  8b9688020000         mov edx, dword ptr [esi + 0x288]
// 00596ec4  52                   push edx
// 00596ec5  56                   push esi
// 00596ec6  e8e57dffff           call 0x58ecb0
// 00596ecb  83c410               add esp, 0x10
// 00596ece  5f                   pop edi
// 00596ecf  899e88020000         mov dword ptr [esi + 0x288], ebx
// 00596ed5  5e                   pop esi
// 00596ed6  5d                   pop ebp
// 00596ed7  5b                   pop ebx
// 00596ed8  c3                   ret 
// 00596ed9  0fbe5f01             movsx ebx, byte ptr [edi + 1]
// 00596edd  47                   inc edi
// 00596ede  85db                 test ebx, ebx
// 00596ee0  7410                 je 0x596ef2
// 00596ee2  683c2d8d00           push 0x8d2d3c
// 00596ee7  56                   push esi
// 00596ee8  e82373ffff           call 0x58e210
// 00596eed  83c408               add esp, 8
// 00596ef0  33db                 xor ebx, ebx
// 00596ef2  2bbe88020000         sub edi, dword ptr [esi + 0x288]
// 00596ef8  8d442414             lea eax, [esp + 0x14]
// 00596efc  50                   push eax
// 00596efd  47                   inc edi
// 00596efe  57                   push edi
// 00596eff  55                   push ebp
// 00596f00  53                   push ebx
// 00596f01  56                   push esi
// 00596f02  e829ccffff           call 0x593b30
// 00596f07  6a10                 push 0x10
// 00596f09  56                   push esi
// 00596f0a  e8d17dffff           call 0x58ece0
// 00596f0f  8be8                 mov ebp, eax
// 00596f11  83c41c               add esp, 0x1c
// 00596f14  85ed                 test ebp, ebp
// 00596f16  7526                 jne 0x596f3e
// 00596f18  68102d8d00           push 0x8d2d10
// 00596f1d  56                   push esi
// 00596f1e  e8ed72ffff           call 0x58e210
// 00596f23  8b8e88020000         mov ecx, dword ptr [esi + 0x288]
// 00596f29  51                   push ecx
// 00596f2a  56                   push esi
// 00596f2b  e8807dffff           call 0x58ecb0
// 00596f30  83c410               add esp, 0x10
// 00596f33  5f                   pop edi
// 00596f34  89ae88020000         mov dword ptr [esi + 0x288], ebp
// 00596f3a  5e                   pop esi
// 00596f3b  5d                   pop ebp
// 00596f3c  5b                   pop ebx
// 00596f3d  c3                   ret 
// 00596f3e  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 00596f42  895d00               mov dword ptr [ebp], ebx
// 00596f45  8b9688020000         mov edx, dword ptr [esi + 0x288]
// 00596f4b  6a01                 push 1
// 00596f4d  895504               mov dword ptr [ebp + 4], edx
// 00596f50  8b8688020000         mov eax, dword ptr [esi + 0x288]
// 00596f56  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 00596f5a  55                   push ebp
// 00596f5b  52                   push edx
// 00596f5c  03c7                 add eax, edi
// 00596f5e  56                   push esi
// 00596f5f  894508               mov dword ptr [ebp + 8], eax
// 00596f62  894d0c               mov dword ptr [ebp + 0xc], ecx
// 00596f65  e8a6a0feff           call 0x581010
// 00596f6a  55                   push ebp
// 00596f6b  56                   push esi
// 00596f6c  8bf8                 mov edi, eax
// 00596f6e  e83d7dffff           call 0x58ecb0
// 00596f73  8b8688020000         mov eax, dword ptr [esi + 0x288]
// 00596f79  50                   push eax
// 00596f7a  56                   push esi
// 00596f7b  e8307dffff           call 0x58ecb0
// 00596f80  83c420               add esp, 0x20
// 00596f83  c7868802000000000000 mov dword ptr [esi + 0x288], 0
// 00596f8d  85ff                 test edi, edi
// 00596f8f  740e                 je 0x596f9f
// 00596f91  68e42c8d00           push 0x8d2ce4
// 00596f96  56                   push esi
// 00596f97  e8c471ffff           call 0x58e160
// 00596f9c  83c408               add esp, 8
// 00596f9f  5f                   pop edi
// 00596fa0  5e                   pop esi
// 00596fa1  5d                   pop ebp
// 00596fa2  5b                   pop ebx
// 00596fa3  c3                   ret 
// library libpng-1.2.32/pngrutil.c (function _png_handle_zTXt)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.32 pngrutil.c
