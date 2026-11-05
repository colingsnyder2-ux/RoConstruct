// from server: 100% by auto
// roc 2010-06 00446ae0  unit: RBX::Reflection::M::?$TypedPropertyDescriptor  size: 231 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00446ae0
//
// 00446ae0  56                   push esi
// 00446ae1  57                   push edi
// 00446ae2  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 00446ae6  8bf1                 mov esi, ecx
// 00446ae8  3bf7                 cmp esi, edi
// 00446aea  0f84d0000000         je 0x446bc0
// 00446af0  53                   push ebx
// 00446af1  8b5f10               mov ebx, dword ptr [edi + 0x10]
// 00446af4  55                   push ebp
// 00446af5  8b6f0c               mov ebp, dword ptr [edi + 0xc]
// 00446af8  8bc3                 mov eax, ebx
// 00446afa  2bc5                 sub eax, ebp
// 00446afc  c1f802               sar eax, 2
// 00446aff  85c0                 test eax, eax
// 00446b01  750e                 jne 0x446b11
// 00446b03  e8a8faffff           call 0x4465b0
// 00446b08  5d                   pop ebp
// 00446b09  5b                   pop ebx
// 00446b0a  5f                   pop edi
// 00446b0b  8bc6                 mov eax, esi
// 00446b0d  5e                   pop esi
// 00446b0e  c20400               ret 4
// 00446b11  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 00446b14  8b5610               mov edx, dword ptr [esi + 0x10]
// 00446b17  2bd1                 sub edx, ecx
// 00446b19  c1fa02               sar edx, 2
// 00446b1c  3bc2                 cmp eax, edx
// 00446b1e  7726                 ja 0x446b46
// 00446b20  51                   push ecx
// 00446b21  53                   push ebx
// 00446b22  55                   push ebp
// 00446b23  e868efffff           call 0x445a90
// 00446b28  8b4710               mov eax, dword ptr [edi + 0x10]
// 00446b2b  2b470c               sub eax, dword ptr [edi + 0xc]
// 00446b2e  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 00446b31  83c40c               add esp, 0xc
// 00446b34  5d                   pop ebp
// 00446b35  c1f802               sar eax, 2
// 00446b38  5b                   pop ebx
// 00446b39  8d1481               lea edx, [ecx + eax*4]
// 00446b3c  5f                   pop edi
// 00446b3d  895610               mov dword ptr [esi + 0x10], edx
// 00446b40  8bc6                 mov eax, esi
// 00446b42  5e                   pop esi
// 00446b43  c20400               ret 4
// 00446b46  85c9                 test ecx, ecx
// 00446b48  7504                 jne 0x446b4e
// 00446b4a  33db                 xor ebx, ebx
// 00446b4c  eb08                 jmp 0x446b56
// 00446b4e  8b5e14               mov ebx, dword ptr [esi + 0x14]
// 00446b51  2bd9                 sub ebx, ecx
// 00446b53  c1fb02               sar ebx, 2
// 00446b56  3bc3                 cmp eax, ebx
// 00446b58  772c                 ja 0x446b86
// 00446b5a  8bc5                 mov eax, ebp
// 00446b5c  51                   push ecx
// 00446b5d  8d1c90               lea ebx, [eax + edx*4]
// 00446b60  53                   push ebx
// 00446b61  50                   push eax
// 00446b62  e829efffff           call 0x445a90
// 00446b67  8b4610               mov eax, dword ptr [esi + 0x10]
// 00446b6a  8b4f10               mov ecx, dword ptr [edi + 0x10]
// 00446b6d  83c40c               add esp, 0xc
// 00446b70  50                   push eax
// 00446b71  51                   push ecx
// 00446b72  53                   push ebx
// 00446b73  8bce                 mov ecx, esi
// 00446b75  e8762d2c00           call 0x7098f0
// 00446b7a  5d                   pop ebp
// 00446b7b  5b                   pop ebx
// 00446b7c  894610               mov dword ptr [esi + 0x10], eax
// 00446b7f  5f                   pop edi
// 00446b80  8bc6                 mov eax, esi
// 00446b82  5e                   pop esi
// 00446b83  c20400               ret 4
// 00446b86  85c9                 test ecx, ecx
// 00446b88  7409                 je 0x446b93
// 00446b8a  51                   push ecx
// 00446b8b  e80a0e3600           call 0x7a799a
// 00446b90  83c404               add esp, 4
// 00446b93  8b4710               mov eax, dword ptr [edi + 0x10]
// 00446b96  2b470c               sub eax, dword ptr [edi + 0xc]
// 00446b99  8bce                 mov ecx, esi
// 00446b9b  c1f802               sar eax, 2
// 00446b9e  50                   push eax
// 00446b9f  e8ec092100           call 0x657590
// 00446ba4  84c0                 test al, al
// 00446ba6  7416                 je 0x446bbe
// 00446ba8  8b560c               mov edx, dword ptr [esi + 0xc]
// 00446bab  8b4710               mov eax, dword ptr [edi + 0x10]
// 00446bae  8b4f0c               mov ecx, dword ptr [edi + 0xc]
// 00446bb1  52                   push edx
// 00446bb2  50                   push eax
// 00446bb3  51                   push ecx
// 00446bb4  8bce                 mov ecx, esi
// 00446bb6  e8352d2c00           call 0x7098f0
// 00446bbb  894610               mov dword ptr [esi + 0x10], eax
// 00446bbe  5d                   pop ebp
// 00446bbf  5b                   pop ebx
// 00446bc0  5f                   pop edi
// 00446bc1  8bc6                 mov eax, esi
// 00446bc3  5e                   pop esi
// 00446bc4  c20400               ret 4
// standard library vector<ptr> (function ??4?$vector@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAEAAV01@ABV01@@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
