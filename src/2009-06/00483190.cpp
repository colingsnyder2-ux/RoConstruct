// from server: 100% by auto
// roc 2009-06 00483190  unit: Ogre::RbxSpatialHashedSceneNode::?1??_findVisibleObjects::NodeVisiter  size: 332 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00483190
//
// 00483190  55                   push ebp
// 00483191  8bec                 mov ebp, esp
// 00483193  6aff                 push -1
// 00483195  6880518500           push 0x855180
// 0048319a  64a100000000         mov eax, dword ptr fs:[0]
// 004831a0  50                   push eax
// 004831a1  64892500000000       mov dword ptr fs:[0], esp
// 004831a8  83ec0c               sub esp, 0xc
// 004831ab  53                   push ebx
// 004831ac  56                   push esi
// 004831ad  8bf1                 mov esi, ecx
// 004831af  8b560c               mov edx, dword ptr [esi + 0xc]
// 004831b2  57                   push edi
// 004831b3  8965f0               mov dword ptr [ebp - 0x10], esp
// 004831b6  85d2                 test edx, edx
// 004831b8  7504                 jne 0x4831be
// 004831ba  33c9                 xor ecx, ecx
// 004831bc  eb0a                 jmp 0x4831c8
// 004831be  8b4614               mov eax, dword ptr [esi + 0x14]
// 004831c1  2bc2                 sub eax, edx
// 004831c3  c1f803               sar eax, 3
// 004831c6  8bc8                 mov ecx, eax
// 004831c8  8b7d10               mov edi, dword ptr [ebp + 0x10]
// 004831cb  85ff                 test edi, edi
// 004831cd  0f84ea010000         je 0x4833bd
// 004831d3  8b5e10               mov ebx, dword ptr [esi + 0x10]
// 004831d6  8bc3                 mov eax, ebx
// 004831d8  2bc2                 sub eax, edx
// 004831da  c1f803               sar eax, 3
// 004831dd  baffffff1f           mov edx, 0x1fffffff
// 004831e2  2bd0                 sub edx, eax
// 004831e4  3bd7                 cmp edx, edi
// 004831e6  7305                 jae 0x4831ed
// 004831e8  e873d10000           call 0x490360
// 004831ed  8d1438               lea edx, [eax + edi]
// 004831f0  3bca                 cmp ecx, edx
// 004831f2  0f83f9000000         jae 0x4832f1
// 004831f8  8bc1                 mov eax, ecx
// 004831fa  d1e8                 shr eax, 1
// 004831fc  bbffffff1f           mov ebx, 0x1fffffff
// 00483201  2bd8                 sub ebx, eax
// 00483203  3bd9                 cmp ebx, ecx
// 00483205  730c                 jae 0x483213
// 00483207  c745ec00000000       mov dword ptr [ebp - 0x14], 0
// 0048320e  8b4dec               mov ecx, dword ptr [ebp - 0x14]
// 00483211  eb05                 jmp 0x483218
// 00483213  03c8                 add ecx, eax
// 00483215  894dec               mov dword ptr [ebp - 0x14], ecx
// 00483218  3bca                 cmp ecx, edx
// 0048321a  7305                 jae 0x483221
// 0048321c  8955ec               mov dword ptr [ebp - 0x14], edx
// 0048321f  8bca                 mov ecx, edx
// 00483221  6a00                 push 0
// 00483223  51                   push ecx
// 00483224  e8c71c0000           call 0x484ef0
// 00483229  8b5d0c               mov ebx, dword ptr [ebp + 0xc]
// 0048322c  2b5e0c               sub ebx, dword ptr [esi + 0xc]
// 0048322f  8b4d14               mov ecx, dword ptr [ebp + 0x14]
// 00483232  83c408               add esp, 8
// 00483235  51                   push ecx
// 00483236  c1fb03               sar ebx, 3
// 00483239  57                   push edi
// 0048323a  8d14d8               lea edx, [eax + ebx*8]
// 0048323d  52                   push edx
// 0048323e  8bce                 mov ecx, esi
// 00483240  894510               mov dword ptr [ebp + 0x10], eax
// 00483243  c745fc00000000       mov dword ptr [ebp - 4], 0
// 0048324a  e8f1360100           call 0x496940
// 0048324f  8b460c               mov eax, dword ptr [esi + 0xc]
// 00483252  c6451400             mov byte ptr [ebp + 0x14], 0
// 00483256  8b5514               mov edx, dword ptr [ebp + 0x14]
// 00483259  52                   push edx
// 0048325a  8b5514               mov edx, dword ptr [ebp + 0x14]
// 0048325d  52                   push edx
// 0048325e  8b550c               mov edx, dword ptr [ebp + 0xc]
// 00483261  8d4e08               lea ecx, [esi + 8]
// 00483264  51                   push ecx
// 00483265  8b4d10               mov ecx, dword ptr [ebp + 0x10]
// 00483268  51                   push ecx
// 00483269  52                   push edx
// 0048326a  50                   push eax
// 0048326b  e8a02c0000           call 0x485f10
// 00483270  8b4610               mov eax, dword ptr [esi + 0x10]
// 00483273  83c418               add esp, 0x18
// 00483276  c6451400             mov byte ptr [ebp + 0x14], 0
// 0048327a  8b5514               mov edx, dword ptr [ebp + 0x14]
// 0048327d  52                   push edx
// 0048327e  8b5514               mov edx, dword ptr [ebp + 0x14]
// 00483281  52                   push edx
// 00483282  8d0c3b               lea ecx, [ebx + edi]
// 00483285  8b5d10               mov ebx, dword ptr [ebp + 0x10]
// 00483288  8d5608               lea edx, [esi + 8]
// 0048328b  52                   push edx
// 0048328c  8d0ccb               lea ecx, [ebx + ecx*8]
// 0048328f  51                   push ecx
// 00483290  50                   push eax
// 00483291  8b450c               mov eax, dword ptr [ebp + 0xc]
// 00483294  50                   push eax
// 00483295  e8762c0000           call 0x485f10
// 0048329a  8b460c               mov eax, dword ptr [esi + 0xc]
// 0048329d  8b4e10               mov ecx, dword ptr [esi + 0x10]
// 004832a0  2bc8                 sub ecx, eax
// 004832a2  c1f903               sar ecx, 3
// 004832a5  83c418               add esp, 0x18
// 004832a8  03f9                 add edi, ecx
// 004832aa  85c0                 test eax, eax
// 004832ac  7409                 je 0x4832b7
// 004832ae  50                   push eax
// 004832af  e87e572900           call 0x718a32
// 004832b4  83c404               add esp, 4
// 004832b7  8b55ec               mov edx, dword ptr [ebp - 0x14]
// 004832ba  8d04d3               lea eax, [ebx + edx*8]
// 004832bd  8d0cfb               lea ecx, [ebx + edi*8]
// 004832c0  894614               mov dword ptr [esi + 0x14], eax
// 004832c3  894e10               mov dword ptr [esi + 0x10], ecx
// 004832c6  895e0c               mov dword ptr [esi + 0xc], ebx
// 004832c9  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 004832cc  64890d00000000       mov dword ptr fs:[0], ecx
// 004832d3  5f                   pop edi
// 004832d4  5e                   pop esi
// 004832d5  5b                   pop ebx
// 004832d6  8be5                 mov esp, ebp
// 004832d8  5d                   pop ebp
// 004832d9  c21000               ret 0x10
// standard library vector<pod8> (function ?_Insert_n@?$vector@UE@@V?$allocator@UE@@@std@@@std@@IAEXV?$_Vector_const_iterator@UE@@V?$allocator@UE@@@std@@@2@IABUE@@@Z)

// stl: vector<pod8>
struct E { int v[2]; };
#include <vector>
template class std::vector<E>;
