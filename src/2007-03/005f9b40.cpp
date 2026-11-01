// from server: 100% by auto
// roc 2007-03 005f9b40  unit: seg_005f0000  size: 134 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005f9b40
//
// 005f9b40  53                   push ebx
// 005f9b41  8a5e36               mov bl, byte ptr [esi + 0x36]
// 005f9b44  80fb04               cmp bl, 4
// 005f9b47  55                   push ebp
// 005f9b48  8b6c240c             mov ebp, dword ptr [esp + 0xc]
// 005f9b4c  57                   push edi
// 005f9b4d  8b7e18               mov edi, dword ptr [esi + 0x18]
// 005f9b50  896e18               mov dword ptr [esi + 0x18], ebp
// 005f9b53  7619                 jbe 0x5f9b6e
// 005f9b55  837e3c00             cmp dword ptr [esi + 0x3c], 0
// 005f9b59  7513                 jne 0x5f9b6e
// 005f9b5b  8b4638               mov eax, dword ptr [esi + 0x38]
// 005f9b5e  6aff                 push -1
// 005f9b60  6a03                 push 3
// 005f9b62  56                   push esi
// 005f9b63  89463c               mov dword ptr [esi + 0x3c], eax
// 005f9b66  e8b561fcff           call 0x5bfd20
// 005f9b6b  83c40c               add esp, 0xc
// 005f9b6e  f6c304               test bl, 4
// 005f9b71  744f                 je 0x5f9bc2
// 005f9b73  8b4e14               mov ecx, dword ptr [esi + 0x14]
// 005f9b76  8b5104               mov edx, dword ptr [ecx + 4]
// 005f9b79  8b02                 mov eax, dword ptr [edx]
// 005f9b7b  8b4810               mov ecx, dword ptr [eax + 0x10]
// 005f9b7e  8b510c               mov edx, dword ptr [ecx + 0xc]
// 005f9b81  8b4914               mov ecx, dword ptr [ecx + 0x14]
// 005f9b84  8bc5                 mov eax, ebp
// 005f9b86  2bc2                 sub eax, edx
// 005f9b88  c1f802               sar eax, 2
// 005f9b8b  83e801               sub eax, 1
// 005f9b8e  85c9                 test ecx, ecx
// 005f9b90  7405                 je 0x5f9b97
// 005f9b92  8b1c81               mov ebx, dword ptr [ecx + eax*4]
// 005f9b95  eb02                 jmp 0x5f9b99
// 005f9b97  33db                 xor ebx, ebx
// 005f9b99  85c0                 test eax, eax
// 005f9b9b  7419                 je 0x5f9bb6
// 005f9b9d  3bef                 cmp ebp, edi
// 005f9b9f  7615                 jbe 0x5f9bb6
// 005f9ba1  85c9                 test ecx, ecx
// 005f9ba3  740b                 je 0x5f9bb0
// 005f9ba5  2bfa                 sub edi, edx
// 005f9ba7  c1ff02               sar edi, 2
// 005f9baa  8b4cb9fc             mov ecx, dword ptr [ecx + edi*4 - 4]
// 005f9bae  eb02                 jmp 0x5f9bb2
// 005f9bb0  33c9                 xor ecx, ecx
// 005f9bb2  3bd9                 cmp ebx, ecx
// 005f9bb4  740c                 je 0x5f9bc2
// 005f9bb6  53                   push ebx
// 005f9bb7  6a02                 push 2
// 005f9bb9  56                   push esi
// 005f9bba  e86161fcff           call 0x5bfd20
// 005f9bbf  83c40c               add esp, 0xc
// 005f9bc2  5f                   pop edi
// 005f9bc3  5d                   pop ebp
// 005f9bc4  5b                   pop ebx
// 005f9bc5  c3                   ret 
// library lua-5.1.1/lvm.c (function _traceexec)

// roc-lang: c
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lvm.c
