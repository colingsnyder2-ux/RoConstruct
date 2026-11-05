// from server: 100% by auto
// roc 2009-06 004832e8  unit: Ogre::RbxSpatialHashedSceneNode::?1??_findVisibleObjects::NodeVisiter  size: 232 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004832e8
//
// 004832e8  6a00                 push 0
// 004832ea  6a00                 push 0
// 004832ec  e859672900           call 0x719a4a
// 004832f1  8b450c               mov eax, dword ptr [ebp + 0xc]
// 004832f4  8bcb                 mov ecx, ebx
// 004832f6  2bc8                 sub ecx, eax
// 004832f8  c1f903               sar ecx, 3
// 004832fb  3bcf                 cmp ecx, edi
// 004832fd  7374                 jae 0x483373
// 004832ff  8b4d14               mov ecx, dword ptr [ebp + 0x14]
// 00483302  8b11                 mov edx, dword ptr [ecx]
// 00483304  8b4904               mov ecx, dword ptr [ecx + 4]
// 00483307  894dec               mov dword ptr [ebp - 0x14], ecx
// 0048330a  8d0cfd00000000       lea ecx, [edi*8]
// 00483311  894d14               mov dword ptr [ebp + 0x14], ecx
// 00483314  03c8                 add ecx, eax
// 00483316  51                   push ecx
// 00483317  53                   push ebx
// 00483318  50                   push eax
// 00483319  8bce                 mov ecx, esi
// 0048331b  8955e8               mov dword ptr [ebp - 0x18], edx
// 0048331e  e81db22700           call 0x6fe540
// 00483323  8b4610               mov eax, dword ptr [esi + 0x10]
// 00483326  8bc8                 mov ecx, eax
// 00483328  2b4d0c               sub ecx, dword ptr [ebp + 0xc]
// 0048332b  8d55e8               lea edx, [ebp - 0x18]
// 0048332e  c1f903               sar ecx, 3
// 00483331  52                   push edx
// 00483332  2bf9                 sub edi, ecx
// 00483334  57                   push edi
// 00483335  50                   push eax
// 00483336  8bce                 mov ecx, esi
// 00483338  c745fc02000000       mov dword ptr [ebp - 4], 2
// 0048333f  e8fc350100           call 0x496940
// 00483344  8b4514               mov eax, dword ptr [ebp + 0x14]
// 00483347  014610               add dword ptr [esi + 0x10], eax
// 0048334a  8b7610               mov esi, dword ptr [esi + 0x10]
// 0048334d  8d55e8               lea edx, [ebp - 0x18]
// 00483350  52                   push edx
// 00483351  2bf0                 sub esi, eax
// 00483353  8b450c               mov eax, dword ptr [ebp + 0xc]
// 00483356  56                   push esi
// 00483357  50                   push eax
// 00483358  e8e3683b00           call 0x839c40
// 0048335d  83c40c               add esp, 0xc
// 00483360  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 00483363  64890d00000000       mov dword ptr fs:[0], ecx
// 0048336a  5f                   pop edi
// 0048336b  5e                   pop esi
// 0048336c  5b                   pop ebx
// 0048336d  8be5                 mov esp, ebp
// 0048336f  5d                   pop ebp
// 00483370  c21000               ret 0x10
// 00483373  8b4514               mov eax, dword ptr [ebp + 0x14]
// 00483376  8b08                 mov ecx, dword ptr [eax]
// 00483378  8b5004               mov edx, dword ptr [eax + 4]
// 0048337b  8d04fd00000000       lea eax, [edi*8]
// 00483382  53                   push ebx
// 00483383  8bfb                 mov edi, ebx
// 00483385  2bf8                 sub edi, eax
// 00483387  53                   push ebx
// 00483388  894de8               mov dword ptr [ebp - 0x18], ecx
// 0048338b  57                   push edi
// 0048338c  8bce                 mov ecx, esi
// 0048338e  8955ec               mov dword ptr [ebp - 0x14], edx
// 00483391  894514               mov dword ptr [ebp + 0x14], eax
// 00483394  e8a7b12700           call 0x6fe540
// 00483399  53                   push ebx
// 0048339a  894610               mov dword ptr [esi + 0x10], eax
// 0048339d  8b450c               mov eax, dword ptr [ebp + 0xc]
// 004833a0  57                   push edi
// 004833a1  50                   push eax
// 004833a2  e809fbffff           call 0x482eb0
// 004833a7  8b450c               mov eax, dword ptr [ebp + 0xc]
// 004833aa  8b5514               mov edx, dword ptr [ebp + 0x14]
// 004833ad  8d4de8               lea ecx, [ebp - 0x18]
// 004833b0  51                   push ecx
// 004833b1  03d0                 add edx, eax
// 004833b3  52                   push edx
// 004833b4  50                   push eax
// 004833b5  e886683b00           call 0x839c40
// 004833ba  83c418               add esp, 0x18
// 004833bd  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 004833c0  5f                   pop edi
// 004833c1  5e                   pop esi
// 004833c2  64890d00000000       mov dword ptr fs:[0], ecx
// 004833c9  5b                   pop ebx
// 004833ca  8be5                 mov esp, ebp
// 004833cc  5d                   pop ebp
// 004833cd  c21000               ret 0x10
// standard library vector<pod8> (function __catch$?_Insert_n@?$vector@UE@@V?$allocator@UE@@@std@@@std@@IAEXV?$_Vector_const_iterator@UE@@V?$allocator@UE@@@std@@@2@IABUE@@@Z$2)

// stl: vector<pod8>
struct E { int v[2]; };
#include <vector>
template class std::vector<E>;
