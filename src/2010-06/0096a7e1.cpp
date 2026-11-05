// from server: 100% by auto
// roc 2010-06 0096a7e1  unit: Ogre::RbxSceneUpdater  size: 313 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0096a7e1
//
// 0096a7e1  6a00                 push 0
// 0096a7e3  6a00                 push 0
// 0096a7e5  e8c8e1e3ff           call 0x7a89b2
// 0096a7ea  8b4d0c               mov ecx, dword ptr [ebp + 0xc]
// 0096a7ed  8bd3                 mov edx, ebx
// 0096a7ef  2bd1                 sub edx, ecx
// 0096a7f1  b8abaaaa2a           mov eax, 0x2aaaaaab
// 0096a7f6  f7ea                 imul edx
// 0096a7f8  c1fa02               sar edx, 2
// 0096a7fb  8bc2                 mov eax, edx
// 0096a7fd  c1e81f               shr eax, 0x1f
// 0096a800  03c2                 add eax, edx
// 0096a802  3bc7                 cmp eax, edi
// 0096a804  8b4514               mov eax, dword ptr [ebp + 0x14]
// 0096a807  0f8399000000         jae 0x96a8a6
// 0096a80d  8b10                 mov edx, dword ptr [eax]
// 0096a80f  8955d4               mov dword ptr [ebp - 0x2c], edx
// 0096a812  8b5004               mov edx, dword ptr [eax + 4]
// 0096a815  8955d8               mov dword ptr [ebp - 0x28], edx
// 0096a818  8b5008               mov edx, dword ptr [eax + 8]
// 0096a81b  8955dc               mov dword ptr [ebp - 0x24], edx
// 0096a81e  8b500c               mov edx, dword ptr [eax + 0xc]
// 0096a821  8955e0               mov dword ptr [ebp - 0x20], edx
// 0096a824  8b5010               mov edx, dword ptr [eax + 0x10]
// 0096a827  8b4014               mov eax, dword ptr [eax + 0x14]
// 0096a82a  8945e8               mov dword ptr [ebp - 0x18], eax
// 0096a82d  8d047f               lea eax, [edi + edi*2]
// 0096a830  03c0                 add eax, eax
// 0096a832  03c0                 add eax, eax
// 0096a834  03c0                 add eax, eax
// 0096a836  894514               mov dword ptr [ebp + 0x14], eax
// 0096a839  03c1                 add eax, ecx
// 0096a83b  50                   push eax
// 0096a83c  53                   push ebx
// 0096a83d  51                   push ecx
// 0096a83e  8bce                 mov ecx, esi
// 0096a840  8955e4               mov dword ptr [ebp - 0x1c], edx
// 0096a843  e8c8fdffff           call 0x96a610
// 0096a848  8b5e10               mov ebx, dword ptr [esi + 0x10]
// 0096a84b  8d4dd4               lea ecx, [ebp - 0x2c]
// 0096a84e  51                   push ecx
// 0096a84f  8bcb                 mov ecx, ebx
// 0096a851  2b4d0c               sub ecx, dword ptr [ebp + 0xc]
// 0096a854  b8abaaaa2a           mov eax, 0x2aaaaaab
// 0096a859  f7e9                 imul ecx
// 0096a85b  c1fa02               sar edx, 2
// 0096a85e  8bc2                 mov eax, edx
// 0096a860  c1e81f               shr eax, 0x1f
// 0096a863  03c2                 add eax, edx
// 0096a865  2bf8                 sub edi, eax
// 0096a867  57                   push edi
// 0096a868  53                   push ebx
// 0096a869  8bce                 mov ecx, esi
// 0096a86b  c745fc02000000       mov dword ptr [ebp - 4], 2
// 0096a872  e859fdffff           call 0x96a5d0
// 0096a877  8b4514               mov eax, dword ptr [ebp + 0x14]
// 0096a87a  014610               add dword ptr [esi + 0x10], eax
// 0096a87d  8b7610               mov esi, dword ptr [esi + 0x10]
// 0096a880  8b550c               mov edx, dword ptr [ebp + 0xc]
// 0096a883  8d4dd4               lea ecx, [ebp - 0x2c]
// 0096a886  51                   push ecx
// 0096a887  2bf0                 sub esi, eax
// 0096a889  56                   push esi
// 0096a88a  52                   push edx
// 0096a88b  e890ddffff           call 0x968620
// 0096a890  83c40c               add esp, 0xc
// 0096a893  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 0096a896  64890d00000000       mov dword ptr fs:[0], ecx
// 0096a89d  5f                   pop edi
// 0096a89e  5e                   pop esi
// 0096a89f  5b                   pop ebx
// 0096a8a0  8be5                 mov esp, ebp
// 0096a8a2  5d                   pop ebp
// 0096a8a3  c21000               ret 0x10
// 0096a8a6  8b08                 mov ecx, dword ptr [eax]
// 0096a8a8  8b5004               mov edx, dword ptr [eax + 4]
// 0096a8ab  894dd4               mov dword ptr [ebp - 0x2c], ecx
// 0096a8ae  8b4808               mov ecx, dword ptr [eax + 8]
// 0096a8b1  8d3c7f               lea edi, [edi + edi*2]
// 0096a8b4  8955d8               mov dword ptr [ebp - 0x28], edx
// 0096a8b7  8b500c               mov edx, dword ptr [eax + 0xc]
// 0096a8ba  03ff                 add edi, edi
// 0096a8bc  894ddc               mov dword ptr [ebp - 0x24], ecx
// 0096a8bf  8b4810               mov ecx, dword ptr [eax + 0x10]
// 0096a8c2  8955e0               mov dword ptr [ebp - 0x20], edx
// 0096a8c5  8b5014               mov edx, dword ptr [eax + 0x14]
// 0096a8c8  03ff                 add edi, edi
// 0096a8ca  53                   push ebx
// 0096a8cb  03ff                 add edi, edi
// 0096a8cd  8bc3                 mov eax, ebx
// 0096a8cf  2bc7                 sub eax, edi
// 0096a8d1  53                   push ebx
// 0096a8d2  894de4               mov dword ptr [ebp - 0x1c], ecx
// 0096a8d5  50                   push eax
// 0096a8d6  8bce                 mov ecx, esi
// 0096a8d8  8955e8               mov dword ptr [ebp - 0x18], edx
// 0096a8db  894514               mov dword ptr [ebp + 0x14], eax
// 0096a8de  e82dfdffff           call 0x96a610
// 0096a8e3  8b4d0c               mov ecx, dword ptr [ebp + 0xc]
// 0096a8e6  894610               mov dword ptr [esi + 0x10], eax
// 0096a8e9  8b4514               mov eax, dword ptr [ebp + 0x14]
// 0096a8ec  53                   push ebx
// 0096a8ed  50                   push eax
// 0096a8ee  51                   push ecx
// 0096a8ef  e8acfcffff           call 0x96a5a0
// 0096a8f4  8b450c               mov eax, dword ptr [ebp + 0xc]
// 0096a8f7  8d55d4               lea edx, [ebp - 0x2c]
// 0096a8fa  52                   push edx
// 0096a8fb  03f8                 add edi, eax
// 0096a8fd  57                   push edi
// 0096a8fe  50                   push eax
// 0096a8ff  e81cddffff           call 0x968620
// 0096a904  83c418               add esp, 0x18
// 0096a907  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 0096a90a  5f                   pop edi
// 0096a90b  5e                   pop esi
// 0096a90c  64890d00000000       mov dword ptr fs:[0], ecx
// 0096a913  5b                   pop ebx
// 0096a914  8be5                 mov esp, ebp
// 0096a916  5d                   pop ebp
// 0096a917  c21000               ret 0x10
// standard library vector<pod24> (function __catch$?_Insert_n@?$vector@UE@@V?$allocator@UE@@@std@@@std@@IAEXV?$_Vector_const_iterator@UE@@V?$allocator@UE@@@std@@@2@IABUE@@@Z$2)

// stl: vector<pod24>
struct E { int v[6]; };
#include <vector>
template class std::vector<E>;
