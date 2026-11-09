// roc 2009-12 004be6c2  unit: Ogre::RbxSpatialHashedSceneNode::?1??_findVisibleObjects::NodeVisiter  size: 249 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 004be6c2
//
// 004be6c2  6a00                 push 0
// 004be6c4  6a00                 push 0
// 004be6c6  e8ad613300           call 0x7f4878
// 004be6cb  8b4d0c               mov ecx, dword ptr [ebp + 0xc]
// 004be6ce  8bc3                 mov eax, ebx
// 004be6d0  2bc1                 sub eax, ecx
// 004be6d2  c1f804               sar eax, 4
// 004be6d5  3bc7                 cmp eax, edi
// 004be6d7  8b4514               mov eax, dword ptr [ebp + 0x14]
// 004be6da  737b                 jae 0x4be757
// 004be6dc  8b10                 mov edx, dword ptr [eax]
// 004be6de  8955dc               mov dword ptr [ebp - 0x24], edx
// 004be6e1  8b5004               mov edx, dword ptr [eax + 4]
// 004be6e4  8955e0               mov dword ptr [ebp - 0x20], edx
// 004be6e7  8b5008               mov edx, dword ptr [eax + 8]
// 004be6ea  8b400c               mov eax, dword ptr [eax + 0xc]
// 004be6ed  8945e8               mov dword ptr [ebp - 0x18], eax
// 004be6f0  8bc7                 mov eax, edi
// 004be6f2  c1e004               shl eax, 4
// 004be6f5  894514               mov dword ptr [ebp + 0x14], eax
// 004be6f8  03c1                 add eax, ecx
// 004be6fa  50                   push eax
// 004be6fb  53                   push ebx
// 004be6fc  51                   push ecx
// 004be6fd  8bce                 mov ecx, esi
// 004be6ff  8955e4               mov dword ptr [ebp - 0x1c], edx
// 004be702  e889fbffff           call 0x4be290
// 004be707  8b4610               mov eax, dword ptr [esi + 0x10]
// 004be70a  8bd0                 mov edx, eax
// 004be70c  2b550c               sub edx, dword ptr [ebp + 0xc]
// 004be70f  8d4ddc               lea ecx, [ebp - 0x24]
// 004be712  51                   push ecx
// 004be713  c1fa04               sar edx, 4
// 004be716  2bfa                 sub edi, edx
// 004be718  57                   push edi
// 004be719  50                   push eax
// 004be71a  8bce                 mov ecx, esi
// 004be71c  c745fc02000000       mov dword ptr [ebp - 4], 2
// 004be723  e8c8faffff           call 0x4be1f0
// 004be728  8b4514               mov eax, dword ptr [ebp + 0x14]
// 004be72b  014610               add dword ptr [esi + 0x10], eax
// 004be72e  8b7610               mov esi, dword ptr [esi + 0x10]
// 004be731  8b550c               mov edx, dword ptr [ebp + 0xc]
// 004be734  8d4ddc               lea ecx, [ebp - 0x24]
// 004be737  51                   push ecx
// 004be738  2bf0                 sub esi, eax
// 004be73a  56                   push esi
// 004be73b  52                   push edx
// 004be73c  e8dff7ffff           call 0x4bdf20
// 004be741  83c40c               add esp, 0xc
// 004be744  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 004be747  64890d00000000       mov dword ptr fs:[0], ecx
// 004be74e  5f                   pop edi
// 004be74f  5e                   pop esi
// 004be750  5b                   pop ebx
// 004be751  8be5                 mov esp, ebp
// 004be753  5d                   pop ebp
// 004be754  c21000               ret 0x10
// 004be757  8b08                 mov ecx, dword ptr [eax]
// 004be759  8b5004               mov edx, dword ptr [eax + 4]
// 004be75c  894ddc               mov dword ptr [ebp - 0x24], ecx
// 004be75f  8b4808               mov ecx, dword ptr [eax + 8]
// 004be762  c1e704               shl edi, 4
// 004be765  8955e0               mov dword ptr [ebp - 0x20], edx
// 004be768  8b500c               mov edx, dword ptr [eax + 0xc]
// 004be76b  8bc7                 mov eax, edi
// 004be76d  53                   push ebx
// 004be76e  8bfb                 mov edi, ebx
// 004be770  2bf8                 sub edi, eax
// 004be772  53                   push ebx
// 004be773  894de4               mov dword ptr [ebp - 0x1c], ecx
// 004be776  57                   push edi
// 004be777  8bce                 mov ecx, esi
// 004be779  8955e8               mov dword ptr [ebp - 0x18], edx
// 004be77c  894514               mov dword ptr [ebp + 0x14], eax
// 004be77f  e80cfbffff           call 0x4be290
// 004be784  53                   push ebx
// 004be785  894610               mov dword ptr [esi + 0x10], eax
// 004be788  8b450c               mov eax, dword ptr [ebp + 0xc]
// 004be78b  57                   push edi
// 004be78c  50                   push eax
// 004be78d  e8bef9ffff           call 0x4be150
// 004be792  8b450c               mov eax, dword ptr [ebp + 0xc]
// 004be795  8b5514               mov edx, dword ptr [ebp + 0x14]
// 004be798  8d4ddc               lea ecx, [ebp - 0x24]
// 004be79b  51                   push ecx
// 004be79c  03d0                 add edx, eax
// 004be79e  52                   push edx
// 004be79f  50                   push eax
// 004be7a0  e87bf7ffff           call 0x4bdf20
// 004be7a5  83c418               add esp, 0x18
// 004be7a8  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 004be7ab  5f                   pop edi
// 004be7ac  5e                   pop esi
// 004be7ad  64890d00000000       mov dword ptr fs:[0], ecx
// 004be7b4  5b                   pop ebx
// 004be7b5  8be5                 mov esp, ebp
// 004be7b7  5d                   pop ebp
// 004be7b8  c21000               ret 0x10
// standard library vector<pod16> (function __catch$?_Insert_n@?$vector@UE@@V?$allocator@UE@@@std@@@std@@IAEXV?$_Vector_const_iterator@UE@@V?$allocator@UE@@@std@@@2@IABUE@@@Z$2)

// stl: vector<pod16>
struct E { int v[4]; };
#include <vector>
template class std::vector<E>;
