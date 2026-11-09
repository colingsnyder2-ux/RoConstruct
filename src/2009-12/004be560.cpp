// from server: 100% by auto
// roc 2009-12 004be560  unit: Ogre::RbxSpatialHashedSceneNode::?1??_findVisibleObjects::NodeVisiter  size: 342 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 004be560
//
// 004be560  55                   push ebp
// 004be561  8bec                 mov ebp, esp
// 004be563  6aff                 push -1
// 004be565  6880239300           push 0x932380
// 004be56a  64a100000000         mov eax, dword ptr fs:[0]
// 004be570  50                   push eax
// 004be571  64892500000000       mov dword ptr fs:[0], esp
// 004be578  83ec18               sub esp, 0x18
// 004be57b  53                   push ebx
// 004be57c  56                   push esi
// 004be57d  8bf1                 mov esi, ecx
// 004be57f  8b560c               mov edx, dword ptr [esi + 0xc]
// 004be582  57                   push edi
// 004be583  8965f0               mov dword ptr [ebp - 0x10], esp
// 004be586  85d2                 test edx, edx
// 004be588  7504                 jne 0x4be58e
// 004be58a  33c9                 xor ecx, ecx
// 004be58c  eb0a                 jmp 0x4be598
// 004be58e  8b4614               mov eax, dword ptr [esi + 0x14]
// 004be591  2bc2                 sub eax, edx
// 004be593  c1f804               sar eax, 4
// 004be596  8bc8                 mov ecx, eax
// 004be598  8b7d10               mov edi, dword ptr [ebp + 0x10]
// 004be59b  85ff                 test edi, edi
// 004be59d  0f8405020000         je 0x4be7a8
// 004be5a3  8b5e10               mov ebx, dword ptr [esi + 0x10]
// 004be5a6  8bc3                 mov eax, ebx
// 004be5a8  2bc2                 sub eax, edx
// 004be5aa  c1f804               sar eax, 4
// 004be5ad  baffffff0f           mov edx, 0xfffffff
// 004be5b2  2bd0                 sub edx, eax
// 004be5b4  3bd7                 cmp edx, edi
// 004be5b6  7305                 jae 0x4be5bd
// 004be5b8  e8a33bf8ff           call 0x442160
// 004be5bd  8d1438               lea edx, [eax + edi]
// 004be5c0  3bca                 cmp ecx, edx
// 004be5c2  0f8303010000         jae 0x4be6cb
// 004be5c8  8bc1                 mov eax, ecx
// 004be5ca  d1e8                 shr eax, 1
// 004be5cc  bbffffff0f           mov ebx, 0xfffffff
// 004be5d1  2bd8                 sub ebx, eax
// 004be5d3  3bd9                 cmp ebx, ecx
// 004be5d5  730c                 jae 0x4be5e3
// 004be5d7  c745ec00000000       mov dword ptr [ebp - 0x14], 0
// 004be5de  8b4dec               mov ecx, dword ptr [ebp - 0x14]
// 004be5e1  eb05                 jmp 0x4be5e8
// 004be5e3  03c8                 add ecx, eax
// 004be5e5  894dec               mov dword ptr [ebp - 0x14], ecx
// 004be5e8  3bca                 cmp ecx, edx
// 004be5ea  7305                 jae 0x4be5f1
// 004be5ec  8955ec               mov dword ptr [ebp - 0x14], edx
// 004be5ef  8bca                 mov ecx, edx
// 004be5f1  6a00                 push 0
// 004be5f3  51                   push ecx
// 004be5f4  e8e73bf8ff           call 0x4421e0
// 004be5f9  8b5d0c               mov ebx, dword ptr [ebp + 0xc]
// 004be5fc  2b5e0c               sub ebx, dword ptr [esi + 0xc]
// 004be5ff  8b4d14               mov ecx, dword ptr [ebp + 0x14]
// 004be602  83c408               add esp, 8
// 004be605  c1fb04               sar ebx, 4
// 004be608  51                   push ecx
// 004be609  8bd3                 mov edx, ebx
// 004be60b  c1e204               shl edx, 4
// 004be60e  57                   push edi
// 004be60f  03d0                 add edx, eax
// 004be611  52                   push edx
// 004be612  8bce                 mov ecx, esi
// 004be614  894510               mov dword ptr [ebp + 0x10], eax
// 004be617  c745fc00000000       mov dword ptr [ebp - 4], 0
// 004be61e  e8cdfbffff           call 0x4be1f0
// 004be623  8b460c               mov eax, dword ptr [esi + 0xc]
// 004be626  c6451400             mov byte ptr [ebp + 0x14], 0
// 004be62a  8b5514               mov edx, dword ptr [ebp + 0x14]
// 004be62d  52                   push edx
// 004be62e  8b5514               mov edx, dword ptr [ebp + 0x14]
// 004be631  52                   push edx
// 004be632  8b550c               mov edx, dword ptr [ebp + 0xc]
// 004be635  8d4e08               lea ecx, [esi + 8]
// 004be638  51                   push ecx
// 004be639  8b4d10               mov ecx, dword ptr [ebp + 0x10]
// 004be63c  51                   push ecx
// 004be63d  52                   push edx
// 004be63e  50                   push eax
// 004be63f  e83cf7ffff           call 0x4bdd80
// 004be644  8b4e10               mov ecx, dword ptr [esi + 0x10]
// 004be647  83c418               add esp, 0x18
// 004be64a  c6451400             mov byte ptr [ebp + 0x14], 0
// 004be64e  8b5514               mov edx, dword ptr [ebp + 0x14]
// 004be651  52                   push edx
// 004be652  8b5514               mov edx, dword ptr [ebp + 0x14]
// 004be655  52                   push edx
// 004be656  8d043b               lea eax, [ebx + edi]
// 004be659  8b5d10               mov ebx, dword ptr [ebp + 0x10]
// 004be65c  c1e004               shl eax, 4
// 004be65f  8d5608               lea edx, [esi + 8]
// 004be662  52                   push edx
// 004be663  03c3                 add eax, ebx
// 004be665  50                   push eax
// 004be666  8b450c               mov eax, dword ptr [ebp + 0xc]
// 004be669  51                   push ecx
// 004be66a  50                   push eax
// 004be66b  e810f7ffff           call 0x4bdd80
// 004be670  8b460c               mov eax, dword ptr [esi + 0xc]
// 004be673  8b4e10               mov ecx, dword ptr [esi + 0x10]
// 004be676  2bc8                 sub ecx, eax
// 004be678  c1f904               sar ecx, 4
// 004be67b  83c418               add esp, 0x18
// 004be67e  03f9                 add edi, ecx
// 004be680  85c0                 test eax, eax
// 004be682  7409                 je 0x4be68d
// 004be684  50                   push eax
// 004be685  e8d0513300           call 0x7f385a
// 004be68a  83c404               add esp, 4
// 004be68d  8b45ec               mov eax, dword ptr [ebp - 0x14]
// 004be690  c1e004               shl eax, 4
// 004be693  03c3                 add eax, ebx
// 004be695  c1e704               shl edi, 4
// 004be698  03fb                 add edi, ebx
// 004be69a  894614               mov dword ptr [esi + 0x14], eax
// 004be69d  897e10               mov dword ptr [esi + 0x10], edi
// 004be6a0  895e0c               mov dword ptr [esi + 0xc], ebx
// 004be6a3  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 004be6a6  64890d00000000       mov dword ptr fs:[0], ecx
// 004be6ad  5f                   pop edi
// 004be6ae  5e                   pop esi
// 004be6af  5b                   pop ebx
// 004be6b0  8be5                 mov esp, ebp
// 004be6b2  5d                   pop ebp
// 004be6b3  c21000               ret 0x10
// standard library vector<pod16> (function ?_Insert_n@?$vector@UE@@V?$allocator@UE@@@std@@@std@@IAEXV?$_Vector_const_iterator@UE@@V?$allocator@UE@@@std@@@2@IABUE@@@Z)

// stl: vector<pod16>
struct E { int v[4]; };
#include <vector>
template class std::vector<E>;
