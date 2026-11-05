// from server: 100% by auto
// roc 2010-06 008e0c7d  unit: Ogre::RbxMaterialAdapter  size: 271 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008e0c7d
//
// 008e0c7d  6a00                 push 0
// 008e0c7f  6a00                 push 0
// 008e0c81  e82c7decff           call 0x7a89b2
// 008e0c86  8b4d0c               mov ecx, dword ptr [ebp + 0xc]
// 008e0c89  8bd3                 mov edx, ebx
// 008e0c8b  2bd1                 sub edx, ecx
// 008e0c8d  b8abaaaa2a           mov eax, 0x2aaaaaab
// 008e0c92  f7ea                 imul edx
// 008e0c94  d1fa                 sar edx, 1
// 008e0c96  8bc2                 mov eax, edx
// 008e0c98  c1e81f               shr eax, 0x1f
// 008e0c9b  03c2                 add eax, edx
// 008e0c9d  3bc7                 cmp eax, edi
// 008e0c9f  8b4514               mov eax, dword ptr [ebp + 0x14]
// 008e0ca2  0f8384000000         jae 0x8e0d2c
// 008e0ca8  8b10                 mov edx, dword ptr [eax]
// 008e0caa  8955e0               mov dword ptr [ebp - 0x20], edx
// 008e0cad  8b5004               mov edx, dword ptr [eax + 4]
// 008e0cb0  8b4008               mov eax, dword ptr [eax + 8]
// 008e0cb3  8945e8               mov dword ptr [ebp - 0x18], eax
// 008e0cb6  8d047f               lea eax, [edi + edi*2]
// 008e0cb9  03c0                 add eax, eax
// 008e0cbb  03c0                 add eax, eax
// 008e0cbd  894514               mov dword ptr [ebp + 0x14], eax
// 008e0cc0  03c1                 add eax, ecx
// 008e0cc2  50                   push eax
// 008e0cc3  53                   push ebx
// 008e0cc4  51                   push ecx
// 008e0cc5  8bce                 mov ecx, esi
// 008e0cc7  8955e4               mov dword ptr [ebp - 0x1c], edx
// 008e0cca  e801ec0800           call 0x96f8d0
// 008e0ccf  8b5e10               mov ebx, dword ptr [esi + 0x10]
// 008e0cd2  8d4de0               lea ecx, [ebp - 0x20]
// 008e0cd5  51                   push ecx
// 008e0cd6  8bcb                 mov ecx, ebx
// 008e0cd8  2b4d0c               sub ecx, dword ptr [ebp + 0xc]
// 008e0cdb  b8abaaaa2a           mov eax, 0x2aaaaaab
// 008e0ce0  f7e9                 imul ecx
// 008e0ce2  d1fa                 sar edx, 1
// 008e0ce4  8bc2                 mov eax, edx
// 008e0ce6  c1e81f               shr eax, 0x1f
// 008e0ce9  03c2                 add eax, edx
// 008e0ceb  2bf8                 sub edi, eax
// 008e0ced  57                   push edi
// 008e0cee  53                   push ebx
// 008e0cef  8bce                 mov ecx, esi
// 008e0cf1  c745fc02000000       mov dword ptr [ebp - 4], 2
// 008e0cf8  e8a3e90800           call 0x96f6a0
// 008e0cfd  8b4514               mov eax, dword ptr [ebp + 0x14]
// 008e0d00  014610               add dword ptr [esi + 0x10], eax
// 008e0d03  8b7610               mov esi, dword ptr [esi + 0x10]
// 008e0d06  8b550c               mov edx, dword ptr [ebp + 0xc]
// 008e0d09  8d4de0               lea ecx, [ebp - 0x20]
// 008e0d0c  51                   push ecx
// 008e0d0d  2bf0                 sub esi, eax
// 008e0d0f  56                   push esi
// 008e0d10  52                   push edx
// 008e0d11  e8ca490700           call 0x9556e0
// 008e0d16  83c40c               add esp, 0xc
// 008e0d19  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 008e0d1c  64890d00000000       mov dword ptr fs:[0], ecx
// 008e0d23  5f                   pop edi
// 008e0d24  5e                   pop esi
// 008e0d25  5b                   pop ebx
// 008e0d26  8be5                 mov esp, ebp
// 008e0d28  5d                   pop ebp
// 008e0d29  c21000               ret 0x10
// 008e0d2c  8b08                 mov ecx, dword ptr [eax]
// 008e0d2e  8b5004               mov edx, dword ptr [eax + 4]
// 008e0d31  8b4008               mov eax, dword ptr [eax + 8]
// 008e0d34  8d3c7f               lea edi, [edi + edi*2]
// 008e0d37  8945e8               mov dword ptr [ebp - 0x18], eax
// 008e0d3a  03ff                 add edi, edi
// 008e0d3c  53                   push ebx
// 008e0d3d  03ff                 add edi, edi
// 008e0d3f  8bc3                 mov eax, ebx
// 008e0d41  2bc7                 sub eax, edi
// 008e0d43  53                   push ebx
// 008e0d44  894de0               mov dword ptr [ebp - 0x20], ecx
// 008e0d47  50                   push eax
// 008e0d48  8bce                 mov ecx, esi
// 008e0d4a  8955e4               mov dword ptr [ebp - 0x1c], edx
// 008e0d4d  894514               mov dword ptr [ebp + 0x14], eax
// 008e0d50  e87beb0800           call 0x96f8d0
// 008e0d55  8b4d14               mov ecx, dword ptr [ebp + 0x14]
// 008e0d58  8b550c               mov edx, dword ptr [ebp + 0xc]
// 008e0d5b  53                   push ebx
// 008e0d5c  51                   push ecx
// 008e0d5d  52                   push edx
// 008e0d5e  894610               mov dword ptr [esi + 0x10], eax
// 008e0d61  e8da490700           call 0x955740
// 008e0d66  8d45e0               lea eax, [ebp - 0x20]
// 008e0d69  50                   push eax
// 008e0d6a  8b450c               mov eax, dword ptr [ebp + 0xc]
// 008e0d6d  03f8                 add edi, eax
// 008e0d6f  57                   push edi
// 008e0d70  50                   push eax
// 008e0d71  e86a490700           call 0x9556e0
// 008e0d76  83c418               add esp, 0x18
// 008e0d79  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 008e0d7c  5f                   pop edi
// 008e0d7d  5e                   pop esi
// 008e0d7e  64890d00000000       mov dword ptr fs:[0], ecx
// 008e0d85  5b                   pop ebx
// 008e0d86  8be5                 mov esp, ebp
// 008e0d88  5d                   pop ebp
// 008e0d89  c21000               ret 0x10
// standard library vector<pod12> (function __catch$?_Insert_n@?$vector@UE@@V?$allocator@UE@@@std@@@std@@IAEXV?$_Vector_const_iterator@UE@@V?$allocator@UE@@@std@@@2@IABUE@@@Z$2)

// stl: vector<pod12>
struct E { int v[3]; };
#include <vector>
template class std::vector<E>;
