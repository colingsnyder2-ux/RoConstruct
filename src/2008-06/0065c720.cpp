// from server: 100% by auto
// roc 2008-06 0065c720  unit: RBX::BallBallContact  size: 132 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0065c720
//
// 0065c720  53                   push ebx
// 0065c721  8a5e36               mov bl, byte ptr [esi + 0x36]
// 0065c724  55                   push ebp
// 0065c725  8b6c240c             mov ebp, dword ptr [esp + 0xc]
// 0065c729  57                   push edi
// 0065c72a  8b7e18               mov edi, dword ptr [esi + 0x18]
// 0065c72d  896e18               mov dword ptr [esi + 0x18], ebp
// 0065c730  80fb04               cmp bl, 4
// 0065c733  7619                 jbe 0x65c74e
// 0065c735  837e3c00             cmp dword ptr [esi + 0x3c], 0
// 0065c739  7513                 jne 0x65c74e
// 0065c73b  8b4638               mov eax, dword ptr [esi + 0x38]
// 0065c73e  6aff                 push -1
// 0065c740  6a03                 push 3
// 0065c742  56                   push esi
// 0065c743  89463c               mov dword ptr [esi + 0x3c], eax
// 0065c746  e83554fcff           call 0x621b80
// 0065c74b  83c40c               add esp, 0xc
// 0065c74e  f6c304               test bl, 4
// 0065c751  744d                 je 0x65c7a0
// 0065c753  8b4e14               mov ecx, dword ptr [esi + 0x14]
// 0065c756  8b5104               mov edx, dword ptr [ecx + 4]
// 0065c759  8b02                 mov eax, dword ptr [edx]
// 0065c75b  8b4810               mov ecx, dword ptr [eax + 0x10]
// 0065c75e  8b510c               mov edx, dword ptr [ecx + 0xc]
// 0065c761  8b4914               mov ecx, dword ptr [ecx + 0x14]
// 0065c764  8bc5                 mov eax, ebp
// 0065c766  2bc2                 sub eax, edx
// 0065c768  c1f802               sar eax, 2
// 0065c76b  48                   dec eax
// 0065c76c  85c9                 test ecx, ecx
// 0065c76e  7405                 je 0x65c775
// 0065c770  8b1c81               mov ebx, dword ptr [ecx + eax*4]
// 0065c773  eb02                 jmp 0x65c777
// 0065c775  33db                 xor ebx, ebx
// 0065c777  85c0                 test eax, eax
// 0065c779  7419                 je 0x65c794
// 0065c77b  3bef                 cmp ebp, edi
// 0065c77d  7615                 jbe 0x65c794
// 0065c77f  85c9                 test ecx, ecx
// 0065c781  740b                 je 0x65c78e
// 0065c783  2bfa                 sub edi, edx
// 0065c785  c1ff02               sar edi, 2
// 0065c788  8b4cb9fc             mov ecx, dword ptr [ecx + edi*4 - 4]
// 0065c78c  eb02                 jmp 0x65c790
// 0065c78e  33c9                 xor ecx, ecx
// 0065c790  3bd9                 cmp ebx, ecx
// 0065c792  740c                 je 0x65c7a0
// 0065c794  53                   push ebx
// 0065c795  6a02                 push 2
// 0065c797  56                   push esi
// 0065c798  e8e353fcff           call 0x621b80
// 0065c79d  83c40c               add esp, 0xc
// 0065c7a0  5f                   pop edi
// 0065c7a1  5d                   pop ebp
// 0065c7a2  5b                   pop ebx
// 0065c7a3  c3                   ret 
// library lua-5.1.2/lvm.c (function _traceexec)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.2 lvm.c
