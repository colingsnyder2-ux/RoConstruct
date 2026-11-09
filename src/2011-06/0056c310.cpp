// from server: 100% by auto
// roc 2011-06 0056c310  unit: seg_00560000  size: 356 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0056c310
//
// 0056c310  83ec20               sub esp, 0x20
// 0056c313  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 0056c317  53                   push ebx
// 0056c318  56                   push esi
// 0056c319  8b74242c             mov esi, dword ptr [esp + 0x2c]
// 0056c31d  b043                 mov al, 0x43
// 0056c31f  57                   push edi
// 0056c320  88442411             mov byte ptr [esp + 0x11], al
// 0056c324  88442412             mov byte ptr [esp + 0x12], al
// 0056c328  8d44240c             lea eax, [esp + 0xc]
// 0056c32c  50                   push eax
// 0056c32d  33ff                 xor edi, edi
// 0056c32f  51                   push ecx
// 0056c330  56                   push esi
// 0056c331  c644241c69           mov byte ptr [esp + 0x1c], 0x69
// 0056c336  c644241f50           mov byte ptr [esp + 0x1f], 0x50
// 0056c33b  c644242000           mov byte ptr [esp + 0x20], 0
// 0056c340  897c242c             mov dword ptr [esp + 0x2c], edi
// 0056c344  897c2430             mov dword ptr [esp + 0x30], edi
// 0056c348  897c2434             mov dword ptr [esp + 0x34], edi
// 0056c34c  897c2424             mov dword ptr [esp + 0x24], edi
// 0056c350  897c2428             mov dword ptr [esp + 0x28], edi
// 0056c354  e8a7ecffff           call 0x56b000
// 0056c359  8bd8                 mov ebx, eax
// 0056c35b  83c40c               add esp, 0xc
// 0056c35e  3bdf                 cmp ebx, edi
// 0056c360  0f8407010000         je 0x56c46d
// 0056c366  397c2438             cmp dword ptr [esp + 0x38], edi
// 0056c36a  740e                 je 0x56c37a
// 0056c36c  68d85fa800           push 0xa85fd8
// 0056c371  56                   push esi
// 0056c372  e86950ffff           call 0x5613e0
// 0056c377  83c408               add esp, 8
// 0056c37a  8b44243c             mov eax, dword ptr [esp + 0x3c]
// 0056c37e  55                   push ebp
// 0056c37f  3bc7                 cmp eax, edi
// 0056c381  7507                 jne 0x56c38a
// 0056c383  33ed                 xor ebp, ebp
// 0056c385  e99e000000           jmp 0x56c428
// 0056c38a  8b6c2444             mov ebp, dword ptr [esp + 0x44]
// 0056c38e  83fd03               cmp ebp, 3
// 0056c391  7e41                 jle 0x56c3d4
// 0056c393  0fb638               movzx edi, byte ptr [eax]
// 0056c396  0fb65001             movzx edx, byte ptr [eax + 1]
// 0056c39a  0fb64802             movzx ecx, byte ptr [eax + 2]
// 0056c39e  c1e708               shl edi, 8
// 0056c3a1  0bfa                 or edi, edx
// 0056c3a3  0fb65003             movzx edx, byte ptr [eax + 3]
// 0056c3a7  c1e708               shl edi, 8
// 0056c3aa  0bf9                 or edi, ecx
// 0056c3ac  c1e708               shl edi, 8
// 0056c3af  0bfa                 or edi, edx
// 0056c3b1  7d21                 jge 0x56c3d4
// 0056c3b3  68a45fa800           push 0xa85fa4
// 0056c3b8  56                   push esi
// 0056c3b9  e82250ffff           call 0x5613e0
// 0056c3be  8b442418             mov eax, dword ptr [esp + 0x18]
// 0056c3c2  50                   push eax
// 0056c3c3  56                   push esi
// 0056c3c4  e8d752ffff           call 0x5616a0
// 0056c3c9  83c410               add esp, 0x10
// 0056c3cc  5d                   pop ebp
// 0056c3cd  5f                   pop edi
// 0056c3ce  5e                   pop esi
// 0056c3cf  5b                   pop ebx
// 0056c3d0  83c420               add esp, 0x20
// 0056c3d3  c3                   ret 
// 0056c3d4  3bef                 cmp ebp, edi
// 0056c3d6  7d21                 jge 0x56c3f9
// 0056c3d8  68745fa800           push 0xa85f74
// 0056c3dd  56                   push esi
// 0056c3de  e8fd4fffff           call 0x5613e0
// 0056c3e3  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0056c3e7  51                   push ecx
// 0056c3e8  56                   push esi
// 0056c3e9  e8b252ffff           call 0x5616a0
// 0056c3ee  83c410               add esp, 0x10
// 0056c3f1  5d                   pop ebp
// 0056c3f2  5f                   pop edi
// 0056c3f3  5e                   pop esi
// 0056c3f4  5b                   pop ebx
// 0056c3f5  83c420               add esp, 0x20
// 0056c3f8  c3                   ret 
// 0056c3f9  7e14                 jle 0x56c40f
// 0056c3fb  68405fa800           push 0xa85f40
// 0056c400  56                   push esi
// 0056c401  e8da4fffff           call 0x5613e0
// 0056c406  8b442448             mov eax, dword ptr [esp + 0x48]
// 0056c40a  83c408               add esp, 8
// 0056c40d  8bef                 mov ebp, edi
// 0056c40f  85ed                 test ebp, ebp
// 0056c411  7415                 je 0x56c428
// 0056c413  50                   push eax
// 0056c414  8d7c2420             lea edi, [esp + 0x20]
// 0056c418  33c0                 xor eax, eax
// 0056c41a  8bcd                 mov ecx, ebp
// 0056c41c  8bd6                 mov edx, esi
// 0056c41e  e87de6ffff           call 0x56aaa0
// 0056c423  83c404               add esp, 4
// 0056c426  8be8                 mov ebp, eax
// 0056c428  8d542b02             lea edx, [ebx + ebp + 2]
// 0056c42c  52                   push edx
// 0056c42d  8d442418             lea eax, [esp + 0x18]
// 0056c431  50                   push eax
// 0056c432  56                   push esi
// 0056c433  e878e5ffff           call 0x56a9b0
// 0056c438  8b7c241c             mov edi, dword ptr [esp + 0x1c]
// 0056c43c  c6441f0100           mov byte ptr [edi + ebx + 1], 0
// 0056c441  83c302               add ebx, 2
// 0056c444  53                   push ebx
// 0056c445  57                   push edi
// 0056c446  56                   push esi
// 0056c447  e8d4e5ffff           call 0x56aa20
// 0056c44c  83c418               add esp, 0x18
// 0056c44f  85ed                 test ebp, ebp
// 0056c451  7409                 je 0x56c45c
// 0056c453  8d44241c             lea eax, [esp + 0x1c]
// 0056c457  e8c4e8ffff           call 0x56ad20
// 0056c45c  56                   push esi
// 0056c45d  e8fee5ffff           call 0x56aa60
// 0056c462  57                   push edi
// 0056c463  56                   push esi
// 0056c464  e83752ffff           call 0x5616a0
// 0056c469  83c40c               add esp, 0xc
// 0056c46c  5d                   pop ebp
// 0056c46d  5f                   pop edi
// 0056c46e  5e                   pop esi
// 0056c46f  5b                   pop ebx
// 0056c470  83c420               add esp, 0x20
// 0056c473  c3                   ret 
// library libpng-1.2.40/pngwutil.c (function _png_write_iCCP)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.40 pngwutil.c
