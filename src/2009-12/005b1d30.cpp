// from server: 100% by auto
// roc 2009-12 005b1d30  unit: RBX::BrickBuilder  size: 157 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 005b1d30
//
// 005b1d30  83ec08               sub esp, 8
// 005b1d33  53                   push ebx
// 005b1d34  56                   push esi
// 005b1d35  8bf1                 mov esi, ecx
// 005b1d37  8b5e0c               mov ebx, dword ptr [esi + 0xc]
// 005b1d3a  57                   push edi
// 005b1d3b  85db                 test ebx, ebx
// 005b1d3d  7504                 jne 0x5b1d43
// 005b1d3f  33c9                 xor ecx, ecx
// 005b1d41  eb15                 jmp 0x5b1d58
// 005b1d43  8b4e14               mov ecx, dword ptr [esi + 0x14]
// 005b1d46  2bcb                 sub ecx, ebx
// 005b1d48  b8abaaaa2a           mov eax, 0x2aaaaaab
// 005b1d4d  f7e9                 imul ecx
// 005b1d4f  d1fa                 sar edx, 1
// 005b1d51  8bca                 mov ecx, edx
// 005b1d53  c1e91f               shr ecx, 0x1f
// 005b1d56  03ca                 add ecx, edx
// 005b1d58  8b7e10               mov edi, dword ptr [esi + 0x10]
// 005b1d5b  8bd7                 mov edx, edi
// 005b1d5d  2bd3                 sub edx, ebx
// 005b1d5f  b8abaaaa2a           mov eax, 0x2aaaaaab
// 005b1d64  f7ea                 imul edx
// 005b1d66  d1fa                 sar edx, 1
// 005b1d68  8bc2                 mov eax, edx
// 005b1d6a  c1e81f               shr eax, 0x1f
// 005b1d6d  03c2                 add eax, edx
// 005b1d6f  3bc1                 cmp eax, ecx
// 005b1d71  7332                 jae 0x5b1da5
// 005b1d73  8b542418             mov edx, dword ptr [esp + 0x18]
// 005b1d77  c644240c00           mov byte ptr [esp + 0xc], 0
// 005b1d7c  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 005b1d80  51                   push ecx
// 005b1d81  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 005b1d85  52                   push edx
// 005b1d86  8d4608               lea eax, [esi + 8]
// 005b1d89  50                   push eax
// 005b1d8a  51                   push ecx
// 005b1d8b  6a01                 push 1
// 005b1d8d  57                   push edi
// 005b1d8e  e82df8ffff           call 0x5b15c0
// 005b1d93  83c418               add esp, 0x18
// 005b1d96  83c70c               add edi, 0xc
// 005b1d99  897e10               mov dword ptr [esi + 0x10], edi
// 005b1d9c  5f                   pop edi
// 005b1d9d  5e                   pop esi
// 005b1d9e  5b                   pop ebx
// 005b1d9f  83c408               add esp, 8
// 005b1da2  c20400               ret 4
// 005b1da5  3bdf                 cmp ebx, edi
// 005b1da7  7606                 jbe 0x5b1daf
// 005b1da9  ff1560b79800         call dword ptr [0x98b760]
// 005b1daf  8b542418             mov edx, dword ptr [esp + 0x18]
// 005b1db3  8b06                 mov eax, dword ptr [esi]
// 005b1db5  52                   push edx
// 005b1db6  57                   push edi
// 005b1db7  50                   push eax
// 005b1db8  8d442418             lea eax, [esp + 0x18]
// 005b1dbc  50                   push eax
// 005b1dbd  8bce                 mov ecx, esi
// 005b1dbf  e89cfeffff           call 0x5b1c60
// 005b1dc4  5f                   pop edi
// 005b1dc5  5e                   pop esi
// 005b1dc6  5b                   pop ebx
// 005b1dc7  83c408               add esp, 8
// 005b1dca  c20400               ret 4
// standard library vector<pod12> (function ?push_back@?$vector@UE@@V?$allocator@UE@@@std@@@std@@QAEXABUE@@@Z)

// stl: vector<pod12>
struct E { int v[3]; };
#include <vector>
template class std::vector<E>;
