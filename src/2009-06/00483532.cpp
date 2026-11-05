// from server: 100% by auto
// roc 2009-06 00483532  unit: Ogre::RbxSpatialHashedSceneNode::?1??_findVisibleObjects::NodeVisiter  size: 249 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00483532
//
// 00483532  6a00                 push 0
// 00483534  6a00                 push 0
// 00483536  e80f652900           call 0x719a4a
// 0048353b  8b4d0c               mov ecx, dword ptr [ebp + 0xc]
// 0048353e  8bc3                 mov eax, ebx
// 00483540  2bc1                 sub eax, ecx
// 00483542  c1f804               sar eax, 4
// 00483545  3bc7                 cmp eax, edi
// 00483547  8b4514               mov eax, dword ptr [ebp + 0x14]
// 0048354a  737b                 jae 0x4835c7
// 0048354c  8b10                 mov edx, dword ptr [eax]
// 0048354e  8955dc               mov dword ptr [ebp - 0x24], edx
// 00483551  8b5004               mov edx, dword ptr [eax + 4]
// 00483554  8955e0               mov dword ptr [ebp - 0x20], edx
// 00483557  8b5008               mov edx, dword ptr [eax + 8]
// 0048355a  8b400c               mov eax, dword ptr [eax + 0xc]
// 0048355d  8945e8               mov dword ptr [ebp - 0x18], eax
// 00483560  8bc7                 mov eax, edi
// 00483562  c1e004               shl eax, 4
// 00483565  894514               mov dword ptr [ebp + 0x14], eax
// 00483568  03c1                 add eax, ecx
// 0048356a  50                   push eax
// 0048356b  53                   push ebx
// 0048356c  51                   push ecx
// 0048356d  8bce                 mov ecx, esi
// 0048356f  8955e4               mov dword ptr [ebp - 0x1c], edx
// 00483572  e8b9faffff           call 0x483030
// 00483577  8b4610               mov eax, dword ptr [esi + 0x10]
// 0048357a  8bd0                 mov edx, eax
// 0048357c  2b550c               sub edx, dword ptr [ebp + 0xc]
// 0048357f  8d4ddc               lea ecx, [ebp - 0x24]
// 00483582  51                   push ecx
// 00483583  c1fa04               sar edx, 4
// 00483586  2bfa                 sub edi, edx
// 00483588  57                   push edi
// 00483589  50                   push eax
// 0048358a  8bce                 mov ecx, esi
// 0048358c  c745fc02000000       mov dword ptr [ebp - 4], 2
// 00483593  e8b8f9ffff           call 0x482f50
// 00483598  8b4514               mov eax, dword ptr [ebp + 0x14]
// 0048359b  014610               add dword ptr [esi + 0x10], eax
// 0048359e  8b7610               mov esi, dword ptr [esi + 0x10]
// 004835a1  8b550c               mov edx, dword ptr [ebp + 0xc]
// 004835a4  8d4ddc               lea ecx, [ebp - 0x24]
// 004835a7  51                   push ecx
// 004835a8  2bf0                 sub esi, eax
// 004835aa  56                   push esi
// 004835ab  52                   push edx
// 004835ac  e85f1f0000           call 0x485510
// 004835b1  83c40c               add esp, 0xc
// 004835b4  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 004835b7  64890d00000000       mov dword ptr fs:[0], ecx
// 004835be  5f                   pop edi
// 004835bf  5e                   pop esi
// 004835c0  5b                   pop ebx
// 004835c1  8be5                 mov esp, ebp
// 004835c3  5d                   pop ebp
// 004835c4  c21000               ret 0x10
// 004835c7  8b08                 mov ecx, dword ptr [eax]
// 004835c9  8b5004               mov edx, dword ptr [eax + 4]
// 004835cc  894ddc               mov dword ptr [ebp - 0x24], ecx
// 004835cf  8b4808               mov ecx, dword ptr [eax + 8]
// 004835d2  c1e704               shl edi, 4
// 004835d5  8955e0               mov dword ptr [ebp - 0x20], edx
// 004835d8  8b500c               mov edx, dword ptr [eax + 0xc]
// 004835db  8bc7                 mov eax, edi
// 004835dd  53                   push ebx
// 004835de  8bfb                 mov edi, ebx
// 004835e0  2bf8                 sub edi, eax
// 004835e2  53                   push ebx
// 004835e3  894de4               mov dword ptr [ebp - 0x1c], ecx
// 004835e6  57                   push edi
// 004835e7  8bce                 mov ecx, esi
// 004835e9  8955e8               mov dword ptr [ebp - 0x18], edx
// 004835ec  894514               mov dword ptr [ebp + 0x14], eax
// 004835ef  e83cfaffff           call 0x483030
// 004835f4  53                   push ebx
// 004835f5  894610               mov dword ptr [esi + 0x10], eax
// 004835f8  8b450c               mov eax, dword ptr [ebp + 0xc]
// 004835fb  57                   push edi
// 004835fc  50                   push eax
// 004835fd  e87e1f0000           call 0x485580
// 00483602  8b450c               mov eax, dword ptr [ebp + 0xc]
// 00483605  8b5514               mov edx, dword ptr [ebp + 0x14]
// 00483608  8d4ddc               lea ecx, [ebp - 0x24]
// 0048360b  51                   push ecx
// 0048360c  03d0                 add edx, eax
// 0048360e  52                   push edx
// 0048360f  50                   push eax
// 00483610  e8fb1e0000           call 0x485510
// 00483615  83c418               add esp, 0x18
// 00483618  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 0048361b  5f                   pop edi
// 0048361c  5e                   pop esi
// 0048361d  64890d00000000       mov dword ptr fs:[0], ecx
// 00483624  5b                   pop ebx
// 00483625  8be5                 mov esp, ebp
// 00483627  5d                   pop ebp
// 00483628  c21000               ret 0x10
// standard library vector<pod16> (function __catch$?_Insert_n@?$vector@UE@@V?$allocator@UE@@@std@@@std@@IAEXV?$_Vector_const_iterator@UE@@V?$allocator@UE@@@std@@@2@IABUE@@@Z$2)

// stl: vector<pod16>
struct E { int v[4]; };
#include <vector>
template class std::vector<E>;
