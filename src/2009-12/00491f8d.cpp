// roc 2009-12 00491f8d  unit: Ogre::RbxEntity  size: 271 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00491f8d
//
// 00491f8d  6a00                 push 0
// 00491f8f  6a00                 push 0
// 00491f91  e8e2283600           call 0x7f4878
// 00491f96  8b4d0c               mov ecx, dword ptr [ebp + 0xc]
// 00491f99  8bd3                 mov edx, ebx
// 00491f9b  2bd1                 sub edx, ecx
// 00491f9d  b8abaaaa2a           mov eax, 0x2aaaaaab
// 00491fa2  f7ea                 imul edx
// 00491fa4  d1fa                 sar edx, 1
// 00491fa6  8bc2                 mov eax, edx
// 00491fa8  c1e81f               shr eax, 0x1f
// 00491fab  03c2                 add eax, edx
// 00491fad  3bc7                 cmp eax, edi
// 00491faf  8b4514               mov eax, dword ptr [ebp + 0x14]
// 00491fb2  0f8384000000         jae 0x49203c
// 00491fb8  8b10                 mov edx, dword ptr [eax]
// 00491fba  8955e0               mov dword ptr [ebp - 0x20], edx
// 00491fbd  8b5004               mov edx, dword ptr [eax + 4]
// 00491fc0  8b4008               mov eax, dword ptr [eax + 8]
// 00491fc3  8945e8               mov dword ptr [ebp - 0x18], eax
// 00491fc6  8d047f               lea eax, [edi + edi*2]
// 00491fc9  03c0                 add eax, eax
// 00491fcb  03c0                 add eax, eax
// 00491fcd  894514               mov dword ptr [ebp + 0x14], eax
// 00491fd0  03c1                 add eax, ecx
// 00491fd2  50                   push eax
// 00491fd3  53                   push ebx
// 00491fd4  51                   push ecx
// 00491fd5  8bce                 mov ecx, esi
// 00491fd7  8955e4               mov dword ptr [ebp - 0x1c], edx
// 00491fda  e831f81100           call 0x5b1810
// 00491fdf  8b5e10               mov ebx, dword ptr [esi + 0x10]
// 00491fe2  8d4de0               lea ecx, [ebp - 0x20]
// 00491fe5  51                   push ecx
// 00491fe6  8bcb                 mov ecx, ebx
// 00491fe8  2b4d0c               sub ecx, dword ptr [ebp + 0xc]
// 00491feb  b8abaaaa2a           mov eax, 0x2aaaaaab
// 00491ff0  f7e9                 imul ecx
// 00491ff2  d1fa                 sar edx, 1
// 00491ff4  8bc2                 mov eax, edx
// 00491ff6  c1e81f               shr eax, 0x1f
// 00491ff9  03c2                 add eax, edx
// 00491ffb  2bf8                 sub edi, eax
// 00491ffd  57                   push edi
// 00491ffe  53                   push ebx
// 00491fff  8bce                 mov ecx, esi
// 00492001  c745fc02000000       mov dword ptr [ebp - 4], 2
// 00492008  e8a3fdffff           call 0x491db0
// 0049200d  8b4514               mov eax, dword ptr [ebp + 0x14]
// 00492010  014610               add dword ptr [esi + 0x10], eax
// 00492013  8b7610               mov esi, dword ptr [esi + 0x10]
// 00492016  8b550c               mov edx, dword ptr [ebp + 0xc]
// 00492019  8d4de0               lea ecx, [ebp - 0x20]
// 0049201c  51                   push ecx
// 0049201d  2bf0                 sub esi, eax
// 0049201f  56                   push esi
// 00492020  52                   push edx
// 00492021  e88ae61100           call 0x5b06b0
// 00492026  83c40c               add esp, 0xc
// 00492029  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 0049202c  64890d00000000       mov dword ptr fs:[0], ecx
// 00492033  5f                   pop edi
// 00492034  5e                   pop esi
// 00492035  5b                   pop ebx
// 00492036  8be5                 mov esp, ebp
// 00492038  5d                   pop ebp
// 00492039  c21000               ret 0x10
// 0049203c  8b08                 mov ecx, dword ptr [eax]
// 0049203e  8b5004               mov edx, dword ptr [eax + 4]
// 00492041  8b4008               mov eax, dword ptr [eax + 8]
// 00492044  8d3c7f               lea edi, [edi + edi*2]
// 00492047  8945e8               mov dword ptr [ebp - 0x18], eax
// 0049204a  03ff                 add edi, edi
// 0049204c  53                   push ebx
// 0049204d  03ff                 add edi, edi
// 0049204f  8bc3                 mov eax, ebx
// 00492051  2bc7                 sub eax, edi
// 00492053  53                   push ebx
// 00492054  894de0               mov dword ptr [ebp - 0x20], ecx
// 00492057  50                   push eax
// 00492058  8bce                 mov ecx, esi
// 0049205a  8955e4               mov dword ptr [ebp - 0x1c], edx
// 0049205d  894514               mov dword ptr [ebp + 0x14], eax
// 00492060  e8abf71100           call 0x5b1810
// 00492065  8b4d14               mov ecx, dword ptr [ebp + 0x14]
// 00492068  8b550c               mov edx, dword ptr [ebp + 0xc]
// 0049206b  53                   push ebx
// 0049206c  51                   push ecx
// 0049206d  52                   push edx
// 0049206e  894610               mov dword ptr [esi + 0x10], eax
// 00492071  e80afdffff           call 0x491d80
// 00492076  8d45e0               lea eax, [ebp - 0x20]
// 00492079  50                   push eax
// 0049207a  8b450c               mov eax, dword ptr [ebp + 0xc]
// 0049207d  03f8                 add edi, eax
// 0049207f  57                   push edi
// 00492080  50                   push eax
// 00492081  e82ae61100           call 0x5b06b0
// 00492086  83c418               add esp, 0x18
// 00492089  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 0049208c  5f                   pop edi
// 0049208d  5e                   pop esi
// 0049208e  64890d00000000       mov dword ptr fs:[0], ecx
// 00492095  5b                   pop ebx
// 00492096  8be5                 mov esp, ebp
// 00492098  5d                   pop ebp
// 00492099  c21000               ret 0x10
// standard library vector<pod12> (function __catch$?_Insert_n@?$vector@UE@@V?$allocator@UE@@@std@@@std@@IAEXV?$_Vector_const_iterator@UE@@V?$allocator@UE@@@std@@@2@IABUE@@@Z$2)

// stl: vector<pod12>
struct E { int v[3]; };
#include <vector>
template class std::vector<E>;
