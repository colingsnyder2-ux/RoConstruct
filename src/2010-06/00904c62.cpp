// from server: 100% by auto
// roc 2010-06 00904c62  unit: Ogre::RbxSpatialHashedSceneNode::?3??_findVisibleObjects::NodeVisiter  size: 249 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00904c62
//
// 00904c62  6a00                 push 0
// 00904c64  6a00                 push 0
// 00904c66  e8473deaff           call 0x7a89b2
// 00904c6b  8b4d0c               mov ecx, dword ptr [ebp + 0xc]
// 00904c6e  8bc3                 mov eax, ebx
// 00904c70  2bc1                 sub eax, ecx
// 00904c72  c1f804               sar eax, 4
// 00904c75  3bc7                 cmp eax, edi
// 00904c77  8b4514               mov eax, dword ptr [ebp + 0x14]
// 00904c7a  737b                 jae 0x904cf7
// 00904c7c  8b10                 mov edx, dword ptr [eax]
// 00904c7e  8955dc               mov dword ptr [ebp - 0x24], edx
// 00904c81  8b5004               mov edx, dword ptr [eax + 4]
// 00904c84  8955e0               mov dword ptr [ebp - 0x20], edx
// 00904c87  8b5008               mov edx, dword ptr [eax + 8]
// 00904c8a  8b400c               mov eax, dword ptr [eax + 0xc]
// 00904c8d  8945e8               mov dword ptr [ebp - 0x18], eax
// 00904c90  8bc7                 mov eax, edi
// 00904c92  c1e004               shl eax, 4
// 00904c95  894514               mov dword ptr [ebp + 0x14], eax
// 00904c98  03c1                 add eax, ecx
// 00904c9a  50                   push eax
// 00904c9b  53                   push ebx
// 00904c9c  51                   push ecx
// 00904c9d  8bce                 mov ecx, esi
// 00904c9f  8955e4               mov dword ptr [ebp - 0x1c], edx
// 00904ca2  e889fbffff           call 0x904830
// 00904ca7  8b4610               mov eax, dword ptr [esi + 0x10]
// 00904caa  8bd0                 mov edx, eax
// 00904cac  2b550c               sub edx, dword ptr [ebp + 0xc]
// 00904caf  8d4ddc               lea ecx, [ebp - 0x24]
// 00904cb2  51                   push ecx
// 00904cb3  c1fa04               sar edx, 4
// 00904cb6  2bfa                 sub edi, edx
// 00904cb8  57                   push edi
// 00904cb9  50                   push eax
// 00904cba  8bce                 mov ecx, esi
// 00904cbc  c745fc02000000       mov dword ptr [ebp - 4], 2
// 00904cc3  e838faffff           call 0x904700
// 00904cc8  8b4514               mov eax, dword ptr [ebp + 0x14]
// 00904ccb  014610               add dword ptr [esi + 0x10], eax
// 00904cce  8b7610               mov esi, dword ptr [esi + 0x10]
// 00904cd1  8b550c               mov edx, dword ptr [ebp + 0xc]
// 00904cd4  8d4ddc               lea ecx, [ebp - 0x24]
// 00904cd7  51                   push ecx
// 00904cd8  2bf0                 sub esi, eax
// 00904cda  56                   push esi
// 00904cdb  52                   push edx
// 00904cdc  e88ff8ffff           call 0x904570
// 00904ce1  83c40c               add esp, 0xc
// 00904ce4  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 00904ce7  64890d00000000       mov dword ptr fs:[0], ecx
// 00904cee  5f                   pop edi
// 00904cef  5e                   pop esi
// 00904cf0  5b                   pop ebx
// 00904cf1  8be5                 mov esp, ebp
// 00904cf3  5d                   pop ebp
// 00904cf4  c21000               ret 0x10
// 00904cf7  8b08                 mov ecx, dword ptr [eax]
// 00904cf9  8b5004               mov edx, dword ptr [eax + 4]
// 00904cfc  894ddc               mov dword ptr [ebp - 0x24], ecx
// 00904cff  8b4808               mov ecx, dword ptr [eax + 8]
// 00904d02  c1e704               shl edi, 4
// 00904d05  8955e0               mov dword ptr [ebp - 0x20], edx
// 00904d08  8b500c               mov edx, dword ptr [eax + 0xc]
// 00904d0b  8bc7                 mov eax, edi
// 00904d0d  53                   push ebx
// 00904d0e  8bfb                 mov edi, ebx
// 00904d10  2bf8                 sub edi, eax
// 00904d12  53                   push ebx
// 00904d13  894de4               mov dword ptr [ebp - 0x1c], ecx
// 00904d16  57                   push edi
// 00904d17  8bce                 mov ecx, esi
// 00904d19  8955e8               mov dword ptr [ebp - 0x18], edx
// 00904d1c  894514               mov dword ptr [ebp + 0x14], eax
// 00904d1f  e80cfbffff           call 0x904830
// 00904d24  53                   push ebx
// 00904d25  894610               mov dword ptr [esi + 0x10], eax
// 00904d28  8b450c               mov eax, dword ptr [ebp + 0xc]
// 00904d2b  57                   push edi
// 00904d2c  50                   push eax
// 00904d2d  e83ef9ffff           call 0x904670
// 00904d32  8b450c               mov eax, dword ptr [ebp + 0xc]
// 00904d35  8b5514               mov edx, dword ptr [ebp + 0x14]
// 00904d38  8d4ddc               lea ecx, [ebp - 0x24]
// 00904d3b  51                   push ecx
// 00904d3c  03d0                 add edx, eax
// 00904d3e  52                   push edx
// 00904d3f  50                   push eax
// 00904d40  e82bf8ffff           call 0x904570
// 00904d45  83c418               add esp, 0x18
// 00904d48  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 00904d4b  5f                   pop edi
// 00904d4c  5e                   pop esi
// 00904d4d  64890d00000000       mov dword ptr fs:[0], ecx
// 00904d54  5b                   pop ebx
// 00904d55  8be5                 mov esp, ebp
// 00904d57  5d                   pop ebp
// 00904d58  c21000               ret 0x10
// standard library vector<pod16> (function __catch$?_Insert_n@?$vector@UE@@V?$allocator@UE@@@std@@@std@@IAEXV?$_Vector_const_iterator@UE@@V?$allocator@UE@@@std@@@2@IABUE@@@Z$2)

// stl: vector<pod16>
struct E { int v[4]; };
#include <vector>
template class std::vector<E>;
