// from server: 100% by auto
// roc 2009-06 00486880  unit: Ogre::RbxMeshPartAdapter  size: 249 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00486880
//
// 00486880  55                   push ebp
// 00486881  8bec                 mov ebp, esp
// 00486883  6aff                 push -1
// 00486885  6880548500           push 0x855480
// 0048688a  64a100000000         mov eax, dword ptr fs:[0]
// 00486890  50                   push eax
// 00486891  64892500000000       mov dword ptr fs:[0], esp
// 00486898  83ec0c               sub esp, 0xc
// 0048689b  53                   push ebx
// 0048689c  56                   push esi
// 0048689d  57                   push edi
// 0048689e  8b7d08               mov edi, dword ptr [ebp + 8]
// 004868a1  8965f0               mov dword ptr [ebp - 0x10], esp
// 004868a4  8bf1                 mov esi, ecx
// 004868a6  81ff55555515         cmp edi, 0x15555555
// 004868ac  7605                 jbe 0x4868b3
// 004868ae  e8ad9a0000           call 0x490360
// 004868b3  8b460c               mov eax, dword ptr [esi + 0xc]
// 004868b6  85c0                 test eax, eax
// 004868b8  7415                 je 0x4868cf
// 004868ba  8b4e14               mov ecx, dword ptr [esi + 0x14]
// 004868bd  2bc8                 sub ecx, eax
// 004868bf  b8abaaaa2a           mov eax, 0x2aaaaaab
// 004868c4  f7e9                 imul ecx
// 004868c6  d1fa                 sar edx, 1
// 004868c8  8bc2                 mov eax, edx
// 004868ca  c1e81f               shr eax, 0x1f
// 004868cd  03c2                 add eax, edx
// 004868cf  3bc7                 cmp eax, edi
// 004868d1  0f838f000000         jae 0x486966
// 004868d7  6a00                 push 0
// 004868d9  57                   push edi
// 004868da  e87146ffff           call 0x47af50
// 004868df  8b5e10               mov ebx, dword ptr [esi + 0x10]
// 004868e2  83c408               add esp, 8
// 004868e5  8945ec               mov dword ptr [ebp - 0x14], eax
// 004868e8  c745fc00000000       mov dword ptr [ebp - 4], 0
// 004868ef  395e0c               cmp dword ptr [esi + 0xc], ebx
// 004868f2  7606                 jbe 0x4868fa
// 004868f4  ff15ace98900         call dword ptr [0x89e9ac]
// 004868fa  8b7e0c               mov edi, dword ptr [esi + 0xc]
// 004868fd  3b7e10               cmp edi, dword ptr [esi + 0x10]
// 00486900  7606                 jbe 0x486908
// 00486902  ff15ace98900         call dword ptr [0x89e9ac]
// 00486908  8b4d08               mov ecx, dword ptr [ebp + 8]
// 0048690b  c645e800             mov byte ptr [ebp - 0x18], 0
// 0048690f  8b45e8               mov eax, dword ptr [ebp - 0x18]
// 00486912  50                   push eax
// 00486913  8b45ec               mov eax, dword ptr [ebp - 0x14]
// 00486916  51                   push ecx
// 00486917  8d5608               lea edx, [esi + 8]
// 0048691a  52                   push edx
// 0048691b  50                   push eax
// 0048691c  53                   push ebx
// 0048691d  57                   push edi
// 0048691e  e8ed46ffff           call 0x47b010
// 00486923  8b5e0c               mov ebx, dword ptr [esi + 0xc]
// 00486926  8b4e10               mov ecx, dword ptr [esi + 0x10]
// 00486929  2bcb                 sub ecx, ebx
// 0048692b  b8abaaaa2a           mov eax, 0x2aaaaaab
// 00486930  f7e9                 imul ecx
// 00486932  d1fa                 sar edx, 1
// 00486934  8bfa                 mov edi, edx
// 00486936  c1ef1f               shr edi, 0x1f
// 00486939  83c418               add esp, 0x18
// 0048693c  03fa                 add edi, edx
// 0048693e  85db                 test ebx, ebx
// 00486940  7409                 je 0x48694b
// 00486942  53                   push ebx
// 00486943  e8ea202900           call 0x718a32
// 00486948  83c404               add esp, 4
// 0048694b  8b4508               mov eax, dword ptr [ebp + 8]
// 0048694e  8d0c40               lea ecx, [eax + eax*2]
// 00486951  8b45ec               mov eax, dword ptr [ebp - 0x14]
// 00486954  8d1488               lea edx, [eax + ecx*4]
// 00486957  8d0c7f               lea ecx, [edi + edi*2]
// 0048695a  895614               mov dword ptr [esi + 0x14], edx
// 0048695d  8d1488               lea edx, [eax + ecx*4]
// 00486960  895610               mov dword ptr [esi + 0x10], edx
// 00486963  89460c               mov dword ptr [esi + 0xc], eax
// 00486966  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 00486969  5f                   pop edi
// 0048696a  5e                   pop esi
// 0048696b  64890d00000000       mov dword ptr fs:[0], ecx
// 00486972  5b                   pop ebx
// 00486973  8be5                 mov esp, ebp
// 00486975  5d                   pop ebp
// 00486976  c20400               ret 4
// standard library vector<pod12> (function ?reserve@?$vector@UE@@V?$allocator@UE@@@std@@@std@@QAEXI@Z)

// stl: vector<pod12>
struct E { int v[3]; };
#include <vector>
template class std::vector<E>;
