// from server: 100% by auto
// roc 2007-08 00725b10  unit: boost::thread_resource_error  size: 437 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00725b10
//
// 00725b10  8b442410             mov eax, dword ptr [esp + 0x10]
// 00725b14  53                   push ebx
// 00725b15  56                   push esi
// 00725b16  8bf1                 mov esi, ecx
// 00725b18  8b08                 mov ecx, dword ptr [eax]
// 00725b1a  894c2418             mov dword ptr [esp + 0x18], ecx
// 00725b1e  8b4e04               mov ecx, dword ptr [esi + 4]
// 00725b21  85c9                 test ecx, ecx
// 00725b23  57                   push edi
// 00725b24  7504                 jne 0x725b2a
// 00725b26  33ff                 xor edi, edi
// 00725b28  eb08                 jmp 0x725b32
// 00725b2a  8b7e0c               mov edi, dword ptr [esi + 0xc]
// 00725b2d  2bf9                 sub edi, ecx
// 00725b2f  c1ff02               sar edi, 2
// 00725b32  8b5c2418             mov ebx, dword ptr [esp + 0x18]
// 00725b36  85db                 test ebx, ebx
// 00725b38  0f8481010000         je 0x725cbf
// 00725b3e  85c9                 test ecx, ecx
// 00725b40  7504                 jne 0x725b46
// 00725b42  33c0                 xor eax, eax
// 00725b44  eb08                 jmp 0x725b4e
// 00725b46  8b4608               mov eax, dword ptr [esi + 8]
// 00725b49  2bc1                 sub eax, ecx
// 00725b4b  c1f802               sar eax, 2
// 00725b4e  baffffff3f           mov edx, 0x3fffffff
// 00725b53  2bd0                 sub edx, eax
// 00725b55  3bd3                 cmp edx, ebx
// 00725b57  7305                 jae 0x725b5e
// 00725b59  e8e2fcffff           call 0x725840
// 00725b5e  85c9                 test ecx, ecx
// 00725b60  7504                 jne 0x725b66
// 00725b62  33c0                 xor eax, eax
// 00725b64  eb08                 jmp 0x725b6e
// 00725b66  8b4608               mov eax, dword ptr [esi + 8]
// 00725b69  2bc1                 sub eax, ecx
// 00725b6b  c1f802               sar eax, 2
// 00725b6e  03c3                 add eax, ebx
// 00725b70  3bf8                 cmp edi, eax
// 00725b72  55                   push ebp
// 00725b73  0f83b4000000         jae 0x725c2d
// 00725b79  8bc7                 mov eax, edi
// 00725b7b  d1e8                 shr eax, 1
// 00725b7d  baffffff3f           mov edx, 0x3fffffff
// 00725b82  2bd0                 sub edx, eax
// 00725b84  3bd7                 cmp edx, edi
// 00725b86  7304                 jae 0x725b8c
// 00725b88  33ff                 xor edi, edi
// 00725b8a  eb02                 jmp 0x725b8e
// 00725b8c  03f8                 add edi, eax
// 00725b8e  85c9                 test ecx, ecx
// 00725b90  7504                 jne 0x725b96
// 00725b92  33c0                 xor eax, eax
// 00725b94  eb08                 jmp 0x725b9e
// 00725b96  8b4608               mov eax, dword ptr [esi + 8]
// 00725b99  2bc1                 sub eax, ecx
// 00725b9b  c1f802               sar eax, 2
// 00725b9e  03c3                 add eax, ebx
// 00725ba0  3bf8                 cmp edi, eax
// 00725ba2  7312                 jae 0x725bb6
// 00725ba4  85c9                 test ecx, ecx
// 00725ba6  7504                 jne 0x725bac
// 00725ba8  33ff                 xor edi, edi
// 00725baa  eb08                 jmp 0x725bb4
// 00725bac  8b7e08               mov edi, dword ptr [esi + 8]
// 00725baf  2bf9                 sub edi, ecx
// 00725bb1  c1ff02               sar edi, 2
// 00725bb4  03fb                 add edi, ebx
// 00725bb6  6a00                 push 0
// 00725bb8  57                   push edi
// 00725bb9  e8a2a1e8ff           call 0x5afd60
// 00725bbe  8b4e04               mov ecx, dword ptr [esi + 4]
// 00725bc1  83c408               add esp, 8
// 00725bc4  8be8                 mov ebp, eax
// 00725bc6  8b442418             mov eax, dword ptr [esp + 0x18]
// 00725bca  55                   push ebp
// 00725bcb  50                   push eax
// 00725bcc  51                   push ecx
// 00725bcd  8bce                 mov ecx, esi
// 00725bcf  e8ccd1e8ff           call 0x5b2da0
// 00725bd4  8d542420             lea edx, [esp + 0x20]
// 00725bd8  52                   push edx
// 00725bd9  53                   push ebx
// 00725bda  50                   push eax
// 00725bdb  8bce                 mov ecx, esi
// 00725bdd  e85e0be5ff           call 0x576740
// 00725be2  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 00725be6  50                   push eax
// 00725be7  8b4608               mov eax, dword ptr [esi + 8]
// 00725bea  50                   push eax
// 00725beb  51                   push ecx
// 00725bec  8bce                 mov ecx, esi
// 00725bee  e8add1e8ff           call 0x5b2da0
// 00725bf3  8b4604               mov eax, dword ptr [esi + 4]
// 00725bf6  85c0                 test eax, eax
// 00725bf8  7504                 jne 0x725bfe
// 00725bfa  33c9                 xor ecx, ecx
// 00725bfc  eb08                 jmp 0x725c06
// 00725bfe  8b4e08               mov ecx, dword ptr [esi + 8]
// 00725c01  2bc8                 sub ecx, eax
// 00725c03  c1f902               sar ecx, 2
// 00725c06  03d9                 add ebx, ecx
// 00725c08  85c0                 test eax, eax
// 00725c0a  7409                 je 0x725c15
// 00725c0c  50                   push eax
// 00725c0d  e850a0f0ff           call 0x62fc62
// 00725c12  83c404               add esp, 4
// 00725c15  8d54bd00             lea edx, [ebp + edi*4]
// 00725c19  8d449d00             lea eax, [ebp + ebx*4]
// 00725c1d  896e04               mov dword ptr [esi + 4], ebp
// 00725c20  5d                   pop ebp
// 00725c21  5f                   pop edi
// 00725c22  89560c               mov dword ptr [esi + 0xc], edx
// 00725c25  894608               mov dword ptr [esi + 8], eax
// 00725c28  5e                   pop esi
// 00725c29  5b                   pop ebx
// 00725c2a  c21000               ret 0x10
// 00725c2d  8b6e08               mov ebp, dword ptr [esi + 8]
// 00725c30  8b7c2418             mov edi, dword ptr [esp + 0x18]
// 00725c34  8bcd                 mov ecx, ebp
// 00725c36  2bcf                 sub ecx, edi
// 00725c38  c1f902               sar ecx, 2
// 00725c3b  8d049d00000000       lea eax, [ebx*4]
// 00725c42  3bcb                 cmp ecx, ebx
// 00725c44  8944241c             mov dword ptr [esp + 0x1c], eax
// 00725c48  8bce                 mov ecx, esi
// 00725c4a  7346                 jae 0x725c92
// 00725c4c  03c7                 add eax, edi
// 00725c4e  50                   push eax
// 00725c4f  55                   push ebp
// 00725c50  57                   push edi
// 00725c51  e84ad1e8ff           call 0x5b2da0
// 00725c56  8b4608               mov eax, dword ptr [esi + 8]
// 00725c59  8bc8                 mov ecx, eax
// 00725c5b  2bcf                 sub ecx, edi
// 00725c5d  c1f902               sar ecx, 2
// 00725c60  8d542420             lea edx, [esp + 0x20]
// 00725c64  52                   push edx
// 00725c65  2bd9                 sub ebx, ecx
// 00725c67  53                   push ebx
// 00725c68  50                   push eax
// 00725c69  8bce                 mov ecx, esi
// 00725c6b  e8d00ae5ff           call 0x576740
// 00725c70  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00725c74  014608               add dword ptr [esi + 8], eax
// 00725c77  8b7608               mov esi, dword ptr [esi + 8]
// 00725c7a  8d542420             lea edx, [esp + 0x20]
// 00725c7e  52                   push edx
// 00725c7f  2bf0                 sub esi, eax
// 00725c81  56                   push esi
// 00725c82  57                   push edi
// 00725c83  e86814e6ff           call 0x5870f0
// 00725c88  83c40c               add esp, 0xc
// 00725c8b  5d                   pop ebp
// 00725c8c  5f                   pop edi
// 00725c8d  5e                   pop esi
// 00725c8e  5b                   pop ebx
// 00725c8f  c21000               ret 0x10
// 00725c92  55                   push ebp
// 00725c93  8bdd                 mov ebx, ebp
// 00725c95  2bd8                 sub ebx, eax
// 00725c97  55                   push ebp
// 00725c98  53                   push ebx
// 00725c99  e802d1e8ff           call 0x5b2da0
// 00725c9e  55                   push ebp
// 00725c9f  53                   push ebx
// 00725ca0  57                   push edi
// 00725ca1  894608               mov dword ptr [esi + 8], eax
// 00725ca4  e85794edff           call 0x5ff100
// 00725ca9  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 00725cad  8d44242c             lea eax, [esp + 0x2c]
// 00725cb1  50                   push eax
// 00725cb2  03cf                 add ecx, edi
// 00725cb4  51                   push ecx
// 00725cb5  57                   push edi
// 00725cb6  e83514e6ff           call 0x5870f0
// 00725cbb  83c418               add esp, 0x18
// 00725cbe  5d                   pop ebp
// 00725cbf  5f                   pop edi
// 00725cc0  5e                   pop esi
// 00725cc1  5b                   pop ebx
// 00725cc2  c21000               ret 0x10
// standard library vector<ptr> (function ?_Insert_n@?$vector@PAUT@@V?$allocator@PAUT@@@std@@@std@@IAEXV?$_Vector_iterator@PAUT@@V?$allocator@PAUT@@@std@@@2@IABQAUT@@@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
