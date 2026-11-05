// from server: 100% by auto
// roc 2009-06 00532d00  unit: RBX::BeveledBlockBuilder  size: 159 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00532d00
//
// 00532d00  83ec08               sub esp, 8
// 00532d03  53                   push ebx
// 00532d04  56                   push esi
// 00532d05  8bf1                 mov esi, ecx
// 00532d07  8b5e0c               mov ebx, dword ptr [esi + 0xc]
// 00532d0a  57                   push edi
// 00532d0b  85db                 test ebx, ebx
// 00532d0d  7504                 jne 0x532d13
// 00532d0f  33c9                 xor ecx, ecx
// 00532d11  eb16                 jmp 0x532d29
// 00532d13  8b4e14               mov ecx, dword ptr [esi + 0x14]
// 00532d16  2bcb                 sub ecx, ebx
// 00532d18  b8abaaaa2a           mov eax, 0x2aaaaaab
// 00532d1d  f7e9                 imul ecx
// 00532d1f  c1fa02               sar edx, 2
// 00532d22  8bca                 mov ecx, edx
// 00532d24  c1e91f               shr ecx, 0x1f
// 00532d27  03ca                 add ecx, edx
// 00532d29  8b7e10               mov edi, dword ptr [esi + 0x10]
// 00532d2c  8bd7                 mov edx, edi
// 00532d2e  2bd3                 sub edx, ebx
// 00532d30  b8abaaaa2a           mov eax, 0x2aaaaaab
// 00532d35  f7ea                 imul edx
// 00532d37  c1fa02               sar edx, 2
// 00532d3a  8bc2                 mov eax, edx
// 00532d3c  c1e81f               shr eax, 0x1f
// 00532d3f  03c2                 add eax, edx
// 00532d41  3bc1                 cmp eax, ecx
// 00532d43  7332                 jae 0x532d77
// 00532d45  8b542418             mov edx, dword ptr [esp + 0x18]
// 00532d49  c644240c00           mov byte ptr [esp + 0xc], 0
// 00532d4e  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00532d52  51                   push ecx
// 00532d53  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 00532d57  52                   push edx
// 00532d58  8d4608               lea eax, [esi + 8]
// 00532d5b  50                   push eax
// 00532d5c  51                   push ecx
// 00532d5d  6a01                 push 1
// 00532d5f  57                   push edi
// 00532d60  e87bf9ffff           call 0x5326e0
// 00532d65  83c418               add esp, 0x18
// 00532d68  83c718               add edi, 0x18
// 00532d6b  897e10               mov dword ptr [esi + 0x10], edi
// 00532d6e  5f                   pop edi
// 00532d6f  5e                   pop esi
// 00532d70  5b                   pop ebx
// 00532d71  83c408               add esp, 8
// 00532d74  c20400               ret 4
// 00532d77  3bdf                 cmp ebx, edi
// 00532d79  7606                 jbe 0x532d81
// 00532d7b  ff15ace98900         call dword ptr [0x89e9ac]
// 00532d81  8b542418             mov edx, dword ptr [esp + 0x18]
// 00532d85  8b06                 mov eax, dword ptr [esi]
// 00532d87  52                   push edx
// 00532d88  57                   push edi
// 00532d89  50                   push eax
// 00532d8a  8d442418             lea eax, [esp + 0x18]
// 00532d8e  50                   push eax
// 00532d8f  8bce                 mov ecx, esi
// 00532d91  e8bafeffff           call 0x532c50
// 00532d96  5f                   pop edi
// 00532d97  5e                   pop esi
// 00532d98  5b                   pop ebx
// 00532d99  83c408               add esp, 8
// 00532d9c  c20400               ret 4
// standard library vector<pod24> (function ?push_back@?$vector@UE@@V?$allocator@UE@@@std@@@std@@QAEXABUE@@@Z)

// stl: vector<pod24>
struct E { int v[6]; };
#include <vector>
template class std::vector<E>;
