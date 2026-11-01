// from server: 100% by auto
// roc 2011-06 00820b00  unit: CXTPImageManagerResource::CBitmapDC  size: 322 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00820b00
//
// 00820b00  83ec2c               sub esp, 0x2c
// 00820b03  56                   push esi
// 00820b04  8b742438             mov esi, dword ptr [esp + 0x38]
// 00820b08  85f6                 test esi, esi
// 00820b0a  7507                 jne 0x820b13
// 00820b0c  33c0                 xor eax, eax
// 00820b0e  5e                   pop esi
// 00820b0f  83c42c               add esp, 0x2c
// 00820b12  c3                   ret 
// 00820b13  53                   push ebx
// 00820b14  6a2c                 push 0x2c
// 00820b16  8d44240c             lea eax, [esp + 0xc]
// 00820b1a  6a00                 push 0
// 00820b1c  50                   push eax
// 00820b1d  e8c2a7feff           call 0x80b2e4
// 00820b22  8b5c2444             mov ebx, dword ptr [esp + 0x44]
// 00820b26  83c40c               add esp, 0xc
// 00820b29  c744240828000000     mov dword ptr [esp + 8], 0x28
// 00820b31  85db                 test ebx, ebx
// 00820b33  7504                 jne 0x820b39
// 00820b35  33c0                 xor eax, eax
// 00820b37  eb03                 jmp 0x820b3c
// 00820b39  8b4304               mov eax, dword ptr [ebx + 4]
// 00820b3c  55                   push ebp
// 00820b3d  8b2d9401a400         mov ebp, dword ptr [0xa40194]
// 00820b43  6a00                 push 0
// 00820b45  8d4c2410             lea ecx, [esp + 0x10]
// 00820b49  51                   push ecx
// 00820b4a  6a00                 push 0
// 00820b4c  6a00                 push 0
// 00820b4e  6a00                 push 0
// 00820b50  56                   push esi
// 00820b51  50                   push eax
// 00820b52  ffd5                 call ebp
// 00820b54  85c0                 test eax, eax
// 00820b56  7408                 je 0x820b60
// 00820b58  66837c241a20         cmp word ptr [esp + 0x1a], 0x20
// 00820b5e  7409                 je 0x820b69
// 00820b60  5d                   pop ebp
// 00820b61  5b                   pop ebx
// 00820b62  33c0                 xor eax, eax
// 00820b64  5e                   pop esi
// 00820b65  83c42c               add esp, 0x2c
// 00820b68  c3                   ret 
// 00820b69  8b442410             mov eax, dword ptr [esp + 0x10]
// 00820b6d  0faf442414           imul eax, dword ptr [esp + 0x14]
// 00820b72  8b54244c             mov edx, dword ptr [esp + 0x4c]
// 00820b76  03c0                 add eax, eax
// 00820b78  03c0                 add eax, eax
// 00820b7a  57                   push edi
// 00820b7b  8b3d400aa400         mov edi, dword ptr [0xa40a40]
// 00820b81  50                   push eax
// 00820b82  8902                 mov dword ptr [edx], eax
// 00820b84  ffd7                 call edi
// 00820b86  8b742450             mov esi, dword ptr [esp + 0x50]
// 00820b8a  83c404               add esp, 4
// 00820b8d  8906                 mov dword ptr [esi], eax
// 00820b8f  85c0                 test eax, eax
// 00820b91  0f8494000000         je 0x820c2b
// 00820b97  6a34                 push 0x34
// 00820b99  ffd7                 call edi
// 00820b9b  8b7c244c             mov edi, dword ptr [esp + 0x4c]
// 00820b9f  83c404               add esp, 4
// 00820ba2  8907                 mov dword ptr [edi], eax
// 00820ba4  85c0                 test eax, eax
// 00820ba6  7520                 jne 0x820bc8
// 00820ba8  8b06                 mov eax, dword ptr [esi]
// 00820baa  85c0                 test eax, eax
// 00820bac  7410                 je 0x820bbe
// 00820bae  50                   push eax
// 00820baf  ff15740aa400         call dword ptr [0xa40a74]
// 00820bb5  83c404               add esp, 4
// 00820bb8  c70600000000         mov dword ptr [esi], 0
// 00820bbe  5f                   pop edi
// 00820bbf  5d                   pop ebp
// 00820bc0  5b                   pop ebx
// 00820bc1  33c0                 xor eax, eax
// 00820bc3  5e                   pop esi
// 00820bc4  83c42c               add esp, 0x2c
// 00820bc7  c3                   ret 
// 00820bc8  6a28                 push 0x28
// 00820bca  8d4c2414             lea ecx, [esp + 0x14]
// 00820bce  51                   push ecx
// 00820bcf  6a28                 push 0x28
// 00820bd1  50                   push eax
// 00820bd2  ff153c0aa400         call dword ptr [0xa40a3c]
// 00820bd8  83c410               add esp, 0x10
// 00820bdb  85db                 test ebx, ebx
// 00820bdd  7504                 jne 0x820be3
// 00820bdf  33c0                 xor eax, eax
// 00820be1  eb03                 jmp 0x820be6
// 00820be3  8b4304               mov eax, dword ptr [ebx + 4]
// 00820be6  8b17                 mov edx, dword ptr [edi]
// 00820be8  8b0e                 mov ecx, dword ptr [esi]
// 00820bea  6a00                 push 0
// 00820bec  52                   push edx
// 00820bed  8b542420             mov edx, dword ptr [esp + 0x20]
// 00820bf1  51                   push ecx
// 00820bf2  8b4c2450             mov ecx, dword ptr [esp + 0x50]
// 00820bf6  52                   push edx
// 00820bf7  6a00                 push 0
// 00820bf9  51                   push ecx
// 00820bfa  50                   push eax
// 00820bfb  ffd5                 call ebp
// 00820bfd  85c0                 test eax, eax
// 00820bff  7534                 jne 0x820c35
// 00820c01  8b06                 mov eax, dword ptr [esi]
// 00820c03  8b1d740aa400         mov ebx, dword ptr [0xa40a74]
// 00820c09  85c0                 test eax, eax
// 00820c0b  740c                 je 0x820c19
// 00820c0d  50                   push eax
// 00820c0e  ffd3                 call ebx
// 00820c10  83c404               add esp, 4
// 00820c13  c70600000000         mov dword ptr [esi], 0
// 00820c19  8b07                 mov eax, dword ptr [edi]
// 00820c1b  85c0                 test eax, eax
// 00820c1d  740c                 je 0x820c2b
// 00820c1f  50                   push eax
// 00820c20  ffd3                 call ebx
// 00820c22  83c404               add esp, 4
// 00820c25  c70700000000         mov dword ptr [edi], 0
// 00820c2b  5f                   pop edi
// 00820c2c  5d                   pop ebp
// 00820c2d  5b                   pop ebx
// 00820c2e  33c0                 xor eax, eax
// 00820c30  5e                   pop esi
// 00820c31  83c42c               add esp, 0x2c
// 00820c34  c3                   ret 
// 00820c35  5f                   pop edi
// 00820c36  5d                   pop ebp
// 00820c37  5b                   pop ebx
// 00820c38  b801000000           mov eax, 1
// 00820c3d  5e                   pop esi
// 00820c3e  83c42c               add esp, 0x2c
// 00820c41  c3                   ret 
// library xtp-15.2.1-shared-mfc/Source\Common\XTPImageManager.cpp (function ?GetBitmapBits@CXTPImageManagerIcon@@SAHAAVCDC@@PAUHBITMAP__@@AAPAUtagBITMAPINFO@@AAPAXAAI@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1-shared-mfc Source/Common/XTPImageManager.cpp
