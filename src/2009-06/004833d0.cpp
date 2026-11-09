// from server: 100% by auto
// roc 2009-06 004833d0  unit: Ogre::RbxSpatialHashedSceneNode::?1??_findVisibleObjects::NodeVisiter  size: 342 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004833d0
//
// 004833d0  55                   push ebp
// 004833d1  8bec                 mov ebp, esp
// 004833d3  6aff                 push -1
// 004833d5  6890518500           push 0x855190
// 004833da  64a100000000         mov eax, dword ptr fs:[0]
// 004833e0  50                   push eax
// 004833e1  64892500000000       mov dword ptr fs:[0], esp
// 004833e8  83ec18               sub esp, 0x18
// 004833eb  53                   push ebx
// 004833ec  56                   push esi
// 004833ed  8bf1                 mov esi, ecx
// 004833ef  8b560c               mov edx, dword ptr [esi + 0xc]
// 004833f2  57                   push edi
// 004833f3  8965f0               mov dword ptr [ebp - 0x10], esp
// 004833f6  85d2                 test edx, edx
// 004833f8  7504                 jne 0x4833fe
// 004833fa  33c9                 xor ecx, ecx
// 004833fc  eb0a                 jmp 0x483408
// 004833fe  8b4614               mov eax, dword ptr [esi + 0x14]
// 00483401  2bc2                 sub eax, edx
// 00483403  c1f804               sar eax, 4
// 00483406  8bc8                 mov ecx, eax
// 00483408  8b7d10               mov edi, dword ptr [ebp + 0x10]
// 0048340b  85ff                 test edi, edi
// 0048340d  0f8405020000         je 0x483618
// 00483413  8b5e10               mov ebx, dword ptr [esi + 0x10]
// 00483416  8bc3                 mov eax, ebx
// 00483418  2bc2                 sub eax, edx
// 0048341a  c1f804               sar eax, 4
// 0048341d  baffffff0f           mov edx, 0xfffffff
// 00483422  2bd0                 sub edx, eax
// 00483424  3bd7                 cmp edx, edi
// 00483426  7305                 jae 0x48342d
// 00483428  e833cf0000           call 0x490360
// 0048342d  8d1438               lea edx, [eax + edi]
// 00483430  3bca                 cmp ecx, edx
// 00483432  0f8303010000         jae 0x48353b
// 00483438  8bc1                 mov eax, ecx
// 0048343a  d1e8                 shr eax, 1
// 0048343c  bbffffff0f           mov ebx, 0xfffffff
// 00483441  2bd8                 sub ebx, eax
// 00483443  3bd9                 cmp ebx, ecx
// 00483445  730c                 jae 0x483453
// 00483447  c745ec00000000       mov dword ptr [ebp - 0x14], 0
// 0048344e  8b4dec               mov ecx, dword ptr [ebp - 0x14]
// 00483451  eb05                 jmp 0x483458
// 00483453  03c8                 add ecx, eax
// 00483455  894dec               mov dword ptr [ebp - 0x14], ecx
// 00483458  3bca                 cmp ecx, edx
// 0048345a  7305                 jae 0x483461
// 0048345c  8955ec               mov dword ptr [ebp - 0x14], edx
// 0048345f  8bca                 mov ecx, edx
// 00483461  6a00                 push 0
// 00483463  51                   push ecx
// 00483464  e8e7f0ffff           call 0x482550
// 00483469  8b5d0c               mov ebx, dword ptr [ebp + 0xc]
// 0048346c  2b5e0c               sub ebx, dword ptr [esi + 0xc]
// 0048346f  8b4d14               mov ecx, dword ptr [ebp + 0x14]
// 00483472  83c408               add esp, 8
// 00483475  c1fb04               sar ebx, 4
// 00483478  51                   push ecx
// 00483479  8bd3                 mov edx, ebx
// 0048347b  c1e204               shl edx, 4
// 0048347e  57                   push edi
// 0048347f  03d0                 add edx, eax
// 00483481  52                   push edx
// 00483482  8bce                 mov ecx, esi
// 00483484  894510               mov dword ptr [ebp + 0x10], eax
// 00483487  c745fc00000000       mov dword ptr [ebp - 4], 0
// 0048348e  e8bdfaffff           call 0x482f50
// 00483493  8b460c               mov eax, dword ptr [esi + 0xc]
// 00483496  c6451400             mov byte ptr [ebp + 0x14], 0
// 0048349a  8b5514               mov edx, dword ptr [ebp + 0x14]
// 0048349d  52                   push edx
// 0048349e  8b5514               mov edx, dword ptr [ebp + 0x14]
// 004834a1  52                   push edx
// 004834a2  8b550c               mov edx, dword ptr [ebp + 0xc]
// 004834a5  8d4e08               lea ecx, [esi + 8]
// 004834a8  51                   push ecx
// 004834a9  8b4d10               mov ecx, dword ptr [ebp + 0x10]
// 004834ac  51                   push ecx
// 004834ad  52                   push edx
// 004834ae  50                   push eax
// 004834af  e8dcf7ffff           call 0x482c90
// 004834b4  8b4e10               mov ecx, dword ptr [esi + 0x10]
// 004834b7  83c418               add esp, 0x18
// 004834ba  c6451400             mov byte ptr [ebp + 0x14], 0
// 004834be  8b5514               mov edx, dword ptr [ebp + 0x14]
// 004834c1  52                   push edx
// 004834c2  8b5514               mov edx, dword ptr [ebp + 0x14]
// 004834c5  52                   push edx
// 004834c6  8d043b               lea eax, [ebx + edi]
// 004834c9  8b5d10               mov ebx, dword ptr [ebp + 0x10]
// 004834cc  c1e004               shl eax, 4
// 004834cf  8d5608               lea edx, [esi + 8]
// 004834d2  52                   push edx
// 004834d3  03c3                 add eax, ebx
// 004834d5  50                   push eax
// 004834d6  8b450c               mov eax, dword ptr [ebp + 0xc]
// 004834d9  51                   push ecx
// 004834da  50                   push eax
// 004834db  e8b0f7ffff           call 0x482c90
// 004834e0  8b460c               mov eax, dword ptr [esi + 0xc]
// 004834e3  8b4e10               mov ecx, dword ptr [esi + 0x10]
// 004834e6  2bc8                 sub ecx, eax
// 004834e8  c1f904               sar ecx, 4
// 004834eb  83c418               add esp, 0x18
// 004834ee  03f9                 add edi, ecx
// 004834f0  85c0                 test eax, eax
// 004834f2  7409                 je 0x4834fd
// 004834f4  50                   push eax
// 004834f5  e838552900           call 0x718a32
// 004834fa  83c404               add esp, 4
// 004834fd  8b45ec               mov eax, dword ptr [ebp - 0x14]
// 00483500  c1e004               shl eax, 4
// 00483503  03c3                 add eax, ebx
// 00483505  c1e704               shl edi, 4
// 00483508  03fb                 add edi, ebx
// 0048350a  894614               mov dword ptr [esi + 0x14], eax
// 0048350d  897e10               mov dword ptr [esi + 0x10], edi
// 00483510  895e0c               mov dword ptr [esi + 0xc], ebx
// 00483513  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 00483516  64890d00000000       mov dword ptr fs:[0], ecx
// 0048351d  5f                   pop edi
// 0048351e  5e                   pop esi
// 0048351f  5b                   pop ebx
// 00483520  8be5                 mov esp, ebp
// 00483522  5d                   pop ebp
// 00483523  c21000               ret 0x10
// standard library vector<pod16> (function ?_Insert_n@?$vector@UE@@V?$allocator@UE@@@std@@@std@@IAEXV?$_Vector_const_iterator@UE@@V?$allocator@UE@@@std@@@2@IABUE@@@Z)

// stl: vector<pod16>
struct E { int v[4]; };
#include <vector>
template class std::vector<E>;
