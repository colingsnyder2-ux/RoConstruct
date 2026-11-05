// roc 2009-12 005b1abd  unit: RBX::BrickBuilder  size: 271 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 005b1abd
//
// 005b1abd  6a00                 push 0
// 005b1abf  6a00                 push 0
// 005b1ac1  e8b22d2400           call 0x7f4878
// 005b1ac6  8b4d0c               mov ecx, dword ptr [ebp + 0xc]
// 005b1ac9  8bd3                 mov edx, ebx
// 005b1acb  2bd1                 sub edx, ecx
// 005b1acd  b8abaaaa2a           mov eax, 0x2aaaaaab
// 005b1ad2  f7ea                 imul edx
// 005b1ad4  d1fa                 sar edx, 1
// 005b1ad6  8bc2                 mov eax, edx
// 005b1ad8  c1e81f               shr eax, 0x1f
// 005b1adb  03c2                 add eax, edx
// 005b1add  3bc7                 cmp eax, edi
// 005b1adf  8b4514               mov eax, dword ptr [ebp + 0x14]
// 005b1ae2  0f8384000000         jae 0x5b1b6c
// 005b1ae8  8b10                 mov edx, dword ptr [eax]
// 005b1aea  8955e0               mov dword ptr [ebp - 0x20], edx
// 005b1aed  8b5004               mov edx, dword ptr [eax + 4]
// 005b1af0  8b4008               mov eax, dword ptr [eax + 8]
// 005b1af3  8945e8               mov dword ptr [ebp - 0x18], eax
// 005b1af6  8d047f               lea eax, [edi + edi*2]
// 005b1af9  03c0                 add eax, eax
// 005b1afb  03c0                 add eax, eax
// 005b1afd  894514               mov dword ptr [ebp + 0x14], eax
// 005b1b00  03c1                 add eax, ecx
// 005b1b02  50                   push eax
// 005b1b03  53                   push ebx
// 005b1b04  51                   push ecx
// 005b1b05  8bce                 mov ecx, esi
// 005b1b07  8955e4               mov dword ptr [ebp - 0x1c], edx
// 005b1b0a  e801fdffff           call 0x5b1810
// 005b1b0f  8b5e10               mov ebx, dword ptr [esi + 0x10]
// 005b1b12  8d4de0               lea ecx, [ebp - 0x20]
// 005b1b15  51                   push ecx
// 005b1b16  8bcb                 mov ecx, ebx
// 005b1b18  2b4d0c               sub ecx, dword ptr [ebp + 0xc]
// 005b1b1b  b8abaaaa2a           mov eax, 0x2aaaaaab
// 005b1b20  f7e9                 imul ecx
// 005b1b22  d1fa                 sar edx, 1
// 005b1b24  8bc2                 mov eax, edx
// 005b1b26  c1e81f               shr eax, 0x1f
// 005b1b29  03c2                 add eax, edx
// 005b1b2b  2bf8                 sub edi, eax
// 005b1b2d  57                   push edi
// 005b1b2e  53                   push ebx
// 005b1b2f  8bce                 mov ecx, esi
// 005b1b31  c745fc02000000       mov dword ptr [ebp - 4], 2
// 005b1b38  e87302eeff           call 0x491db0
// 005b1b3d  8b4514               mov eax, dword ptr [ebp + 0x14]
// 005b1b40  014610               add dword ptr [esi + 0x10], eax
// 005b1b43  8b7610               mov esi, dword ptr [esi + 0x10]
// 005b1b46  8b550c               mov edx, dword ptr [ebp + 0xc]
// 005b1b49  8d4de0               lea ecx, [ebp - 0x20]
// 005b1b4c  51                   push ecx
// 005b1b4d  2bf0                 sub esi, eax
// 005b1b4f  56                   push esi
// 005b1b50  52                   push edx
// 005b1b51  e83afaffff           call 0x5b1590
// 005b1b56  83c40c               add esp, 0xc
// 005b1b59  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 005b1b5c  64890d00000000       mov dword ptr fs:[0], ecx
// 005b1b63  5f                   pop edi
// 005b1b64  5e                   pop esi
// 005b1b65  5b                   pop ebx
// 005b1b66  8be5                 mov esp, ebp
// 005b1b68  5d                   pop ebp
// 005b1b69  c21000               ret 0x10
// 005b1b6c  8b08                 mov ecx, dword ptr [eax]
// 005b1b6e  8b5004               mov edx, dword ptr [eax + 4]
// 005b1b71  8b4008               mov eax, dword ptr [eax + 8]
// 005b1b74  8d3c7f               lea edi, [edi + edi*2]
// 005b1b77  8945e8               mov dword ptr [ebp - 0x18], eax
// 005b1b7a  03ff                 add edi, edi
// 005b1b7c  53                   push ebx
// 005b1b7d  03ff                 add edi, edi
// 005b1b7f  8bc3                 mov eax, ebx
// 005b1b81  2bc7                 sub eax, edi
// 005b1b83  53                   push ebx
// 005b1b84  894de0               mov dword ptr [ebp - 0x20], ecx
// 005b1b87  50                   push eax
// 005b1b88  8bce                 mov ecx, esi
// 005b1b8a  8955e4               mov dword ptr [ebp - 0x1c], edx
// 005b1b8d  894514               mov dword ptr [ebp + 0x14], eax
// 005b1b90  e87bfcffff           call 0x5b1810
// 005b1b95  8b4d14               mov ecx, dword ptr [ebp + 0x14]
// 005b1b98  8b550c               mov edx, dword ptr [ebp + 0xc]
// 005b1b9b  53                   push ebx
// 005b1b9c  51                   push ecx
// 005b1b9d  52                   push edx
// 005b1b9e  894610               mov dword ptr [esi + 0x10], eax
// 005b1ba1  e84afaffff           call 0x5b15f0
// 005b1ba6  8d45e0               lea eax, [ebp - 0x20]
// 005b1ba9  50                   push eax
// 005b1baa  8b450c               mov eax, dword ptr [ebp + 0xc]
// 005b1bad  03f8                 add edi, eax
// 005b1baf  57                   push edi
// 005b1bb0  50                   push eax
// 005b1bb1  e8daf9ffff           call 0x5b1590
// 005b1bb6  83c418               add esp, 0x18
// 005b1bb9  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 005b1bbc  5f                   pop edi
// 005b1bbd  5e                   pop esi
// 005b1bbe  64890d00000000       mov dword ptr fs:[0], ecx
// 005b1bc5  5b                   pop ebx
// 005b1bc6  8be5                 mov esp, ebp
// 005b1bc8  5d                   pop ebp
// 005b1bc9  c21000               ret 0x10
// standard library vector<pod12> (function __catch$?_Insert_n@?$vector@UE@@V?$allocator@UE@@@std@@@std@@IAEXV?$_Vector_const_iterator@UE@@V?$allocator@UE@@@std@@@2@IABUE@@@Z$2)

// stl: vector<pod12>
struct E { int v[3]; };
#include <vector>
template class std::vector<E>;
