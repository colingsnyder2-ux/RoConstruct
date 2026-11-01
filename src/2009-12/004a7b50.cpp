// from server: 100% by auto
// roc 2009-12 004a7b50  unit: Ogre::UTVertexPositionNormalStudsTex::?$SpecializedMeshGen  size: 159 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 004a7b50
//
// 004a7b50  83ec08               sub esp, 8
// 004a7b53  53                   push ebx
// 004a7b54  56                   push esi
// 004a7b55  8bf1                 mov esi, ecx
// 004a7b57  8b5e0c               mov ebx, dword ptr [esi + 0xc]
// 004a7b5a  57                   push edi
// 004a7b5b  85db                 test ebx, ebx
// 004a7b5d  7504                 jne 0x4a7b63
// 004a7b5f  33c9                 xor ecx, ecx
// 004a7b61  eb16                 jmp 0x4a7b79
// 004a7b63  8b4e14               mov ecx, dword ptr [esi + 0x14]
// 004a7b66  2bcb                 sub ecx, ebx
// 004a7b68  b8abaaaa2a           mov eax, 0x2aaaaaab
// 004a7b6d  f7e9                 imul ecx
// 004a7b6f  c1fa03               sar edx, 3
// 004a7b72  8bca                 mov ecx, edx
// 004a7b74  c1e91f               shr ecx, 0x1f
// 004a7b77  03ca                 add ecx, edx
// 004a7b79  8b7e10               mov edi, dword ptr [esi + 0x10]
// 004a7b7c  8bd7                 mov edx, edi
// 004a7b7e  2bd3                 sub edx, ebx
// 004a7b80  b8abaaaa2a           mov eax, 0x2aaaaaab
// 004a7b85  f7ea                 imul edx
// 004a7b87  c1fa03               sar edx, 3
// 004a7b8a  8bc2                 mov eax, edx
// 004a7b8c  c1e81f               shr eax, 0x1f
// 004a7b8f  03c2                 add eax, edx
// 004a7b91  3bc1                 cmp eax, ecx
// 004a7b93  7332                 jae 0x4a7bc7
// 004a7b95  8b542418             mov edx, dword ptr [esp + 0x18]
// 004a7b99  c644240c00           mov byte ptr [esp + 0xc], 0
// 004a7b9e  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 004a7ba2  51                   push ecx
// 004a7ba3  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 004a7ba7  52                   push edx
// 004a7ba8  8d4608               lea eax, [esi + 8]
// 004a7bab  50                   push eax
// 004a7bac  51                   push ecx
// 004a7bad  6a01                 push 1
// 004a7baf  57                   push edi
// 004a7bb0  e8cb84ffff           call 0x4a0080
// 004a7bb5  83c418               add esp, 0x18
// 004a7bb8  83c730               add edi, 0x30
// 004a7bbb  897e10               mov dword ptr [esi + 0x10], edi
// 004a7bbe  5f                   pop edi
// 004a7bbf  5e                   pop esi
// 004a7bc0  5b                   pop ebx
// 004a7bc1  83c408               add esp, 8
// 004a7bc4  c20400               ret 4
// 004a7bc7  3bdf                 cmp ebx, edi
// 004a7bc9  7606                 jbe 0x4a7bd1
// 004a7bcb  ff1560b79800         call dword ptr [0x98b760]
// 004a7bd1  8b542418             mov edx, dword ptr [esp + 0x18]
// 004a7bd5  8b06                 mov eax, dword ptr [esi]
// 004a7bd7  52                   push edx
// 004a7bd8  57                   push edi
// 004a7bd9  50                   push eax
// 004a7bda  8d442418             lea eax, [esp + 0x18]
// 004a7bde  50                   push eax
// 004a7bdf  8bce                 mov ecx, esi
// 004a7be1  e8baf7ffff           call 0x4a73a0
// 004a7be6  5f                   pop edi
// 004a7be7  5e                   pop esi
// 004a7be8  5b                   pop ebx
// 004a7be9  83c408               add esp, 8
// 004a7bec  c20400               ret 4
// standard library vector<pod48> (function ?push_back@?$vector@UE@@V?$allocator@UE@@@std@@@std@@QAEXABUE@@@Z)

// stl: vector<pod48>
struct E { int v[12]; };
#include <vector>
template class std::vector<E>;
