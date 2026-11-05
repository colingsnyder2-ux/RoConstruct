// from server: 100% by auto
// roc 2010-06 0096fa9d  unit: seg_00960000  size: 271 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0096fa9d
//
// 0096fa9d  6a00                 push 0
// 0096fa9f  6a00                 push 0
// 0096faa1  e80c8fe3ff           call 0x7a89b2
// 0096faa6  8b4d0c               mov ecx, dword ptr [ebp + 0xc]
// 0096faa9  8bd3                 mov edx, ebx
// 0096faab  2bd1                 sub edx, ecx
// 0096faad  b8abaaaa2a           mov eax, 0x2aaaaaab
// 0096fab2  f7ea                 imul edx
// 0096fab4  d1fa                 sar edx, 1
// 0096fab6  8bc2                 mov eax, edx
// 0096fab8  c1e81f               shr eax, 0x1f
// 0096fabb  03c2                 add eax, edx
// 0096fabd  3bc7                 cmp eax, edi
// 0096fabf  8b4514               mov eax, dword ptr [ebp + 0x14]
// 0096fac2  0f8384000000         jae 0x96fb4c
// 0096fac8  8b10                 mov edx, dword ptr [eax]
// 0096faca  8955e0               mov dword ptr [ebp - 0x20], edx
// 0096facd  8b5004               mov edx, dword ptr [eax + 4]
// 0096fad0  8b4008               mov eax, dword ptr [eax + 8]
// 0096fad3  8945e8               mov dword ptr [ebp - 0x18], eax
// 0096fad6  8d047f               lea eax, [edi + edi*2]
// 0096fad9  03c0                 add eax, eax
// 0096fadb  03c0                 add eax, eax
// 0096fadd  894514               mov dword ptr [ebp + 0x14], eax
// 0096fae0  03c1                 add eax, ecx
// 0096fae2  50                   push eax
// 0096fae3  53                   push ebx
// 0096fae4  51                   push ecx
// 0096fae5  8bce                 mov ecx, esi
// 0096fae7  8955e4               mov dword ptr [ebp - 0x1c], edx
// 0096faea  e8e1fdffff           call 0x96f8d0
// 0096faef  8b5e10               mov ebx, dword ptr [esi + 0x10]
// 0096faf2  8d4de0               lea ecx, [ebp - 0x20]
// 0096faf5  51                   push ecx
// 0096faf6  8bcb                 mov ecx, ebx
// 0096faf8  2b4d0c               sub ecx, dword ptr [ebp + 0xc]
// 0096fafb  b8abaaaa2a           mov eax, 0x2aaaaaab
// 0096fb00  f7e9                 imul ecx
// 0096fb02  d1fa                 sar edx, 1
// 0096fb04  8bc2                 mov eax, edx
// 0096fb06  c1e81f               shr eax, 0x1f
// 0096fb09  03c2                 add eax, edx
// 0096fb0b  2bf8                 sub edi, eax
// 0096fb0d  57                   push edi
// 0096fb0e  53                   push ebx
// 0096fb0f  8bce                 mov ecx, esi
// 0096fb11  c745fc02000000       mov dword ptr [ebp - 4], 2
// 0096fb18  e883fbffff           call 0x96f6a0
// 0096fb1d  8b4514               mov eax, dword ptr [ebp + 0x14]
// 0096fb20  014610               add dword ptr [esi + 0x10], eax
// 0096fb23  8b7610               mov esi, dword ptr [esi + 0x10]
// 0096fb26  8b550c               mov edx, dword ptr [ebp + 0xc]
// 0096fb29  8d4de0               lea ecx, [ebp - 0x20]
// 0096fb2c  51                   push ecx
// 0096fb2d  2bf0                 sub esi, eax
// 0096fb2f  56                   push esi
// 0096fb30  52                   push edx
// 0096fb31  e80afbffff           call 0x96f640
// 0096fb36  83c40c               add esp, 0xc
// 0096fb39  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 0096fb3c  64890d00000000       mov dword ptr fs:[0], ecx
// 0096fb43  5f                   pop edi
// 0096fb44  5e                   pop esi
// 0096fb45  5b                   pop ebx
// 0096fb46  8be5                 mov esp, ebp
// 0096fb48  5d                   pop ebp
// 0096fb49  c21000               ret 0x10
// 0096fb4c  8b08                 mov ecx, dword ptr [eax]
// 0096fb4e  8b5004               mov edx, dword ptr [eax + 4]
// 0096fb51  8b4008               mov eax, dword ptr [eax + 8]
// 0096fb54  8d3c7f               lea edi, [edi + edi*2]
// 0096fb57  8945e8               mov dword ptr [ebp - 0x18], eax
// 0096fb5a  03ff                 add edi, edi
// 0096fb5c  53                   push ebx
// 0096fb5d  03ff                 add edi, edi
// 0096fb5f  8bc3                 mov eax, ebx
// 0096fb61  2bc7                 sub eax, edi
// 0096fb63  53                   push ebx
// 0096fb64  894de0               mov dword ptr [ebp - 0x20], ecx
// 0096fb67  50                   push eax
// 0096fb68  8bce                 mov ecx, esi
// 0096fb6a  8955e4               mov dword ptr [ebp - 0x1c], edx
// 0096fb6d  894514               mov dword ptr [ebp + 0x14], eax
// 0096fb70  e85bfdffff           call 0x96f8d0
// 0096fb75  8b4d14               mov ecx, dword ptr [ebp + 0x14]
// 0096fb78  8b550c               mov edx, dword ptr [ebp + 0xc]
// 0096fb7b  53                   push ebx
// 0096fb7c  51                   push ecx
// 0096fb7d  52                   push edx
// 0096fb7e  894610               mov dword ptr [esi + 0x10], eax
// 0096fb81  e8eafaffff           call 0x96f670
// 0096fb86  8d45e0               lea eax, [ebp - 0x20]
// 0096fb89  50                   push eax
// 0096fb8a  8b450c               mov eax, dword ptr [ebp + 0xc]
// 0096fb8d  03f8                 add edi, eax
// 0096fb8f  57                   push edi
// 0096fb90  50                   push eax
// 0096fb91  e8aafaffff           call 0x96f640
// 0096fb96  83c418               add esp, 0x18
// 0096fb99  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 0096fb9c  5f                   pop edi
// 0096fb9d  5e                   pop esi
// 0096fb9e  64890d00000000       mov dword ptr fs:[0], ecx
// 0096fba5  5b                   pop ebx
// 0096fba6  8be5                 mov esp, ebp
// 0096fba8  5d                   pop ebp
// 0096fba9  c21000               ret 0x10
// standard library vector<pod12> (function __catch$?_Insert_n@?$vector@UE@@V?$allocator@UE@@@std@@@std@@IAEXV?$_Vector_const_iterator@UE@@V?$allocator@UE@@@std@@@2@IABUE@@@Z$2)

// stl: vector<pod12>
struct E { int v[3]; };
#include <vector>
template class std::vector<E>;
