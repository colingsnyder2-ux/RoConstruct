// roc 2009-12 0058b421  unit: RBX::BeveledBlockBuilder  size: 313 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0058b421
//
// 0058b421  6a00                 push 0
// 0058b423  6a00                 push 0
// 0058b425  e84e942600           call 0x7f4878
// 0058b42a  8b4d0c               mov ecx, dword ptr [ebp + 0xc]
// 0058b42d  8bd3                 mov edx, ebx
// 0058b42f  2bd1                 sub edx, ecx
// 0058b431  b8abaaaa2a           mov eax, 0x2aaaaaab
// 0058b436  f7ea                 imul edx
// 0058b438  c1fa02               sar edx, 2
// 0058b43b  8bc2                 mov eax, edx
// 0058b43d  c1e81f               shr eax, 0x1f
// 0058b440  03c2                 add eax, edx
// 0058b442  3bc7                 cmp eax, edi
// 0058b444  8b4514               mov eax, dword ptr [ebp + 0x14]
// 0058b447  0f8399000000         jae 0x58b4e6
// 0058b44d  8b10                 mov edx, dword ptr [eax]
// 0058b44f  8955d4               mov dword ptr [ebp - 0x2c], edx
// 0058b452  8b5004               mov edx, dword ptr [eax + 4]
// 0058b455  8955d8               mov dword ptr [ebp - 0x28], edx
// 0058b458  8b5008               mov edx, dword ptr [eax + 8]
// 0058b45b  8955dc               mov dword ptr [ebp - 0x24], edx
// 0058b45e  8b500c               mov edx, dword ptr [eax + 0xc]
// 0058b461  8955e0               mov dword ptr [ebp - 0x20], edx
// 0058b464  8b5010               mov edx, dword ptr [eax + 0x10]
// 0058b467  8b4014               mov eax, dword ptr [eax + 0x14]
// 0058b46a  8945e8               mov dword ptr [ebp - 0x18], eax
// 0058b46d  8d047f               lea eax, [edi + edi*2]
// 0058b470  03c0                 add eax, eax
// 0058b472  03c0                 add eax, eax
// 0058b474  03c0                 add eax, eax
// 0058b476  894514               mov dword ptr [ebp + 0x14], eax
// 0058b479  03c1                 add eax, ecx
// 0058b47b  50                   push eax
// 0058b47c  53                   push ebx
// 0058b47d  51                   push ecx
// 0058b47e  8bce                 mov ecx, esi
// 0058b480  8955e4               mov dword ptr [ebp - 0x1c], edx
// 0058b483  e8c8fdffff           call 0x58b250
// 0058b488  8b5e10               mov ebx, dword ptr [esi + 0x10]
// 0058b48b  8d4dd4               lea ecx, [ebp - 0x2c]
// 0058b48e  51                   push ecx
// 0058b48f  8bcb                 mov ecx, ebx
// 0058b491  2b4d0c               sub ecx, dword ptr [ebp + 0xc]
// 0058b494  b8abaaaa2a           mov eax, 0x2aaaaaab
// 0058b499  f7e9                 imul ecx
// 0058b49b  c1fa02               sar edx, 2
// 0058b49e  8bc2                 mov eax, edx
// 0058b4a0  c1e81f               shr eax, 0x1f
// 0058b4a3  03c2                 add eax, edx
// 0058b4a5  2bf8                 sub edi, eax
// 0058b4a7  57                   push edi
// 0058b4a8  53                   push ebx
// 0058b4a9  8bce                 mov ecx, esi
// 0058b4ab  c745fc02000000       mov dword ptr [ebp - 4], 2
// 0058b4b2  e8d9fcffff           call 0x58b190
// 0058b4b7  8b4514               mov eax, dword ptr [ebp + 0x14]
// 0058b4ba  014610               add dword ptr [esi + 0x10], eax
// 0058b4bd  8b7610               mov esi, dword ptr [esi + 0x10]
// 0058b4c0  8b550c               mov edx, dword ptr [ebp + 0xc]
// 0058b4c3  8d4dd4               lea ecx, [ebp - 0x2c]
// 0058b4c6  51                   push ecx
// 0058b4c7  2bf0                 sub esi, eax
// 0058b4c9  56                   push esi
// 0058b4ca  52                   push edx
// 0058b4cb  e8c0dcffff           call 0x589190
// 0058b4d0  83c40c               add esp, 0xc
// 0058b4d3  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 0058b4d6  64890d00000000       mov dword ptr fs:[0], ecx
// 0058b4dd  5f                   pop edi
// 0058b4de  5e                   pop esi
// 0058b4df  5b                   pop ebx
// 0058b4e0  8be5                 mov esp, ebp
// 0058b4e2  5d                   pop ebp
// 0058b4e3  c21000               ret 0x10
// 0058b4e6  8b08                 mov ecx, dword ptr [eax]
// 0058b4e8  8b5004               mov edx, dword ptr [eax + 4]
// 0058b4eb  894dd4               mov dword ptr [ebp - 0x2c], ecx
// 0058b4ee  8b4808               mov ecx, dword ptr [eax + 8]
// 0058b4f1  8d3c7f               lea edi, [edi + edi*2]
// 0058b4f4  8955d8               mov dword ptr [ebp - 0x28], edx
// 0058b4f7  8b500c               mov edx, dword ptr [eax + 0xc]
// 0058b4fa  03ff                 add edi, edi
// 0058b4fc  894ddc               mov dword ptr [ebp - 0x24], ecx
// 0058b4ff  8b4810               mov ecx, dword ptr [eax + 0x10]
// 0058b502  8955e0               mov dword ptr [ebp - 0x20], edx
// 0058b505  8b5014               mov edx, dword ptr [eax + 0x14]
// 0058b508  03ff                 add edi, edi
// 0058b50a  53                   push ebx
// 0058b50b  03ff                 add edi, edi
// 0058b50d  8bc3                 mov eax, ebx
// 0058b50f  2bc7                 sub eax, edi
// 0058b511  53                   push ebx
// 0058b512  894de4               mov dword ptr [ebp - 0x1c], ecx
// 0058b515  50                   push eax
// 0058b516  8bce                 mov ecx, esi
// 0058b518  8955e8               mov dword ptr [ebp - 0x18], edx
// 0058b51b  894514               mov dword ptr [ebp + 0x14], eax
// 0058b51e  e82dfdffff           call 0x58b250
// 0058b523  8b4d0c               mov ecx, dword ptr [ebp + 0xc]
// 0058b526  894610               mov dword ptr [esi + 0x10], eax
// 0058b529  8b4514               mov eax, dword ptr [ebp + 0x14]
// 0058b52c  53                   push ebx
// 0058b52d  50                   push eax
// 0058b52e  51                   push ecx
// 0058b52f  e8dcfbffff           call 0x58b110
// 0058b534  8b450c               mov eax, dword ptr [ebp + 0xc]
// 0058b537  8d55d4               lea edx, [ebp - 0x2c]
// 0058b53a  52                   push edx
// 0058b53b  03f8                 add edi, eax
// 0058b53d  57                   push edi
// 0058b53e  50                   push eax
// 0058b53f  e84cdcffff           call 0x589190
// 0058b544  83c418               add esp, 0x18
// 0058b547  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 0058b54a  5f                   pop edi
// 0058b54b  5e                   pop esi
// 0058b54c  64890d00000000       mov dword ptr fs:[0], ecx
// 0058b553  5b                   pop ebx
// 0058b554  8be5                 mov esp, ebp
// 0058b556  5d                   pop ebp
// 0058b557  c21000               ret 0x10
// standard library vector<pod24> (function __catch$?_Insert_n@?$vector@UE@@V?$allocator@UE@@@std@@@std@@IAEXV?$_Vector_const_iterator@UE@@V?$allocator@UE@@@std@@@2@IABUE@@@Z$2)

// stl: vector<pod24>
struct E { int v[6]; };
#include <vector>
template class std::vector<E>;
