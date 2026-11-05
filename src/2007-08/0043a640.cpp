// from server: 100% by auto
// roc 2007-08 0043a640  unit: IIHAAH::?$CMap  size: 293 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0043a640
//
// 0043a640  56                   push esi
// 0043a641  57                   push edi
// 0043a642  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 0043a646  8bf1                 mov esi, ecx
// 0043a648  3bf7                 cmp esi, edi
// 0043a64a  0f840e010000         je 0x43a75e
// 0043a650  53                   push ebx
// 0043a651  8b5f04               mov ebx, dword ptr [edi + 4]
// 0043a654  85db                 test ebx, ebx
// 0043a656  55                   push ebp
// 0043a657  740c                 je 0x43a665
// 0043a659  8b6f08               mov ebp, dword ptr [edi + 8]
// 0043a65c  8bd5                 mov edx, ebp
// 0043a65e  2bd3                 sub edx, ebx
// 0043a660  c1fa02               sar edx, 2
// 0043a663  750e                 jne 0x43a673
// 0043a665  e816f7ffff           call 0x439d80
// 0043a66a  5d                   pop ebp
// 0043a66b  5b                   pop ebx
// 0043a66c  5f                   pop edi
// 0043a66d  8bc6                 mov eax, esi
// 0043a66f  5e                   pop esi
// 0043a670  c20400               ret 4
// 0043a673  8b4604               mov eax, dword ptr [esi + 4]
// 0043a676  85c0                 test eax, eax
// 0043a678  7504                 jne 0x43a67e
// 0043a67a  33c9                 xor ecx, ecx
// 0043a67c  eb08                 jmp 0x43a686
// 0043a67e  8b4e08               mov ecx, dword ptr [esi + 8]
// 0043a681  2bc8                 sub ecx, eax
// 0043a683  c1f902               sar ecx, 2
// 0043a686  3bd1                 cmp edx, ecx
// 0043a688  7740                 ja 0x43a6ca
// 0043a68a  50                   push eax
// 0043a68b  55                   push ebp
// 0043a68c  53                   push ebx
// 0043a68d  e81ef2ffff           call 0x4398b0
// 0043a692  8b4704               mov eax, dword ptr [edi + 4]
// 0043a695  83c40c               add esp, 0xc
// 0043a698  85c0                 test eax, eax
// 0043a69a  7514                 jne 0x43a6b0
// 0043a69c  8b4604               mov eax, dword ptr [esi + 4]
// 0043a69f  5d                   pop ebp
// 0043a6a0  33ff                 xor edi, edi
// 0043a6a2  8d0cb8               lea ecx, [eax + edi*4]
// 0043a6a5  5b                   pop ebx
// 0043a6a6  5f                   pop edi
// 0043a6a7  894e08               mov dword ptr [esi + 8], ecx
// 0043a6aa  8bc6                 mov eax, esi
// 0043a6ac  5e                   pop esi
// 0043a6ad  c20400               ret 4
// 0043a6b0  8b7f08               mov edi, dword ptr [edi + 8]
// 0043a6b3  2bf8                 sub edi, eax
// 0043a6b5  8b4604               mov eax, dword ptr [esi + 4]
// 0043a6b8  5d                   pop ebp
// 0043a6b9  c1ff02               sar edi, 2
// 0043a6bc  8d0cb8               lea ecx, [eax + edi*4]
// 0043a6bf  5b                   pop ebx
// 0043a6c0  5f                   pop edi
// 0043a6c1  894e08               mov dword ptr [esi + 8], ecx
// 0043a6c4  8bc6                 mov eax, esi
// 0043a6c6  5e                   pop esi
// 0043a6c7  c20400               ret 4
// 0043a6ca  85c0                 test eax, eax
// 0043a6cc  7504                 jne 0x43a6d2
// 0043a6ce  33c9                 xor ecx, ecx
// 0043a6d0  eb08                 jmp 0x43a6da
// 0043a6d2  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 0043a6d5  2bc8                 sub ecx, eax
// 0043a6d7  c1f902               sar ecx, 2
// 0043a6da  3bd1                 cmp edx, ecx
// 0043a6dc  773c                 ja 0x43a71a
// 0043a6de  85c0                 test eax, eax
// 0043a6e0  7504                 jne 0x43a6e6
// 0043a6e2  33c9                 xor ecx, ecx
// 0043a6e4  eb08                 jmp 0x43a6ee
// 0043a6e6  8b4e08               mov ecx, dword ptr [esi + 8]
// 0043a6e9  2bc8                 sub ecx, eax
// 0043a6eb  c1f902               sar ecx, 2
// 0043a6ee  8bd3                 mov edx, ebx
// 0043a6f0  50                   push eax
// 0043a6f1  8d1c8a               lea ebx, [edx + ecx*4]
// 0043a6f4  53                   push ebx
// 0043a6f5  52                   push edx
// 0043a6f6  e8b5f1ffff           call 0x4398b0
// 0043a6fb  8b5608               mov edx, dword ptr [esi + 8]
// 0043a6fe  8b4708               mov eax, dword ptr [edi + 8]
// 0043a701  83c40c               add esp, 0xc
// 0043a704  52                   push edx
// 0043a705  50                   push eax
// 0043a706  53                   push ebx
// 0043a707  8bce                 mov ecx, esi
// 0043a709  e892861700           call 0x5b2da0
// 0043a70e  5d                   pop ebp
// 0043a70f  5b                   pop ebx
// 0043a710  894608               mov dword ptr [esi + 8], eax
// 0043a713  5f                   pop edi
// 0043a714  8bc6                 mov eax, esi
// 0043a716  5e                   pop esi
// 0043a717  c20400               ret 4
// 0043a71a  85c0                 test eax, eax
// 0043a71c  7409                 je 0x43a727
// 0043a71e  50                   push eax
// 0043a71f  e83e551f00           call 0x62fc62
// 0043a724  83c404               add esp, 4
// 0043a727  8b4f04               mov ecx, dword ptr [edi + 4]
// 0043a72a  85c9                 test ecx, ecx
// 0043a72c  7504                 jne 0x43a732
// 0043a72e  33c0                 xor eax, eax
// 0043a730  eb08                 jmp 0x43a73a
// 0043a732  8b4708               mov eax, dword ptr [edi + 8]
// 0043a735  2bc1                 sub eax, ecx
// 0043a737  c1f802               sar eax, 2
// 0043a73a  50                   push eax
// 0043a73b  8bce                 mov ecx, esi
// 0043a73d  e85ef2ffff           call 0x4399a0
// 0043a742  84c0                 test al, al
// 0043a744  7416                 je 0x43a75c
// 0043a746  8b4e04               mov ecx, dword ptr [esi + 4]
// 0043a749  8b5708               mov edx, dword ptr [edi + 8]
// 0043a74c  8b4704               mov eax, dword ptr [edi + 4]
// 0043a74f  51                   push ecx
// 0043a750  52                   push edx
// 0043a751  50                   push eax
// 0043a752  8bce                 mov ecx, esi
// 0043a754  e847861700           call 0x5b2da0
// 0043a759  894608               mov dword ptr [esi + 8], eax
// 0043a75c  5d                   pop ebp
// 0043a75d  5b                   pop ebx
// 0043a75e  5f                   pop edi
// 0043a75f  8bc6                 mov eax, esi
// 0043a761  5e                   pop esi
// 0043a762  c20400               ret 4
// standard library vector<ptr> (function ??4?$vector@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAEAAV01@ABV01@@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
