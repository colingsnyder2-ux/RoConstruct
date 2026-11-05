// from server: 100% by auto
// roc 2009-12 005b1090  unit: seg_005b0000  size: 157 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 005b1090
//
// 005b1090  83ec08               sub esp, 8
// 005b1093  53                   push ebx
// 005b1094  56                   push esi
// 005b1095  8bf1                 mov esi, ecx
// 005b1097  8b5e0c               mov ebx, dword ptr [esi + 0xc]
// 005b109a  57                   push edi
// 005b109b  85db                 test ebx, ebx
// 005b109d  7504                 jne 0x5b10a3
// 005b109f  33c9                 xor ecx, ecx
// 005b10a1  eb15                 jmp 0x5b10b8
// 005b10a3  8b4e14               mov ecx, dword ptr [esi + 0x14]
// 005b10a6  2bcb                 sub ecx, ebx
// 005b10a8  b8abaaaa2a           mov eax, 0x2aaaaaab
// 005b10ad  f7e9                 imul ecx
// 005b10af  d1fa                 sar edx, 1
// 005b10b1  8bca                 mov ecx, edx
// 005b10b3  c1e91f               shr ecx, 0x1f
// 005b10b6  03ca                 add ecx, edx
// 005b10b8  8b7e10               mov edi, dword ptr [esi + 0x10]
// 005b10bb  8bd7                 mov edx, edi
// 005b10bd  2bd3                 sub edx, ebx
// 005b10bf  b8abaaaa2a           mov eax, 0x2aaaaaab
// 005b10c4  f7ea                 imul edx
// 005b10c6  d1fa                 sar edx, 1
// 005b10c8  8bc2                 mov eax, edx
// 005b10ca  c1e81f               shr eax, 0x1f
// 005b10cd  03c2                 add eax, edx
// 005b10cf  3bc1                 cmp eax, ecx
// 005b10d1  7332                 jae 0x5b1105
// 005b10d3  8b542418             mov edx, dword ptr [esp + 0x18]
// 005b10d7  c644240c00           mov byte ptr [esp + 0xc], 0
// 005b10dc  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 005b10e0  51                   push ecx
// 005b10e1  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 005b10e5  52                   push edx
// 005b10e6  8d4608               lea eax, [esi + 8]
// 005b10e9  50                   push eax
// 005b10ea  51                   push ecx
// 005b10eb  6a01                 push 1
// 005b10ed  57                   push edi
// 005b10ee  e8edf5ffff           call 0x5b06e0
// 005b10f3  83c418               add esp, 0x18
// 005b10f6  83c70c               add edi, 0xc
// 005b10f9  897e10               mov dword ptr [esi + 0x10], edi
// 005b10fc  5f                   pop edi
// 005b10fd  5e                   pop esi
// 005b10fe  5b                   pop ebx
// 005b10ff  83c408               add esp, 8
// 005b1102  c20400               ret 4
// 005b1105  3bdf                 cmp ebx, edi
// 005b1107  7606                 jbe 0x5b110f
// 005b1109  ff1560b79800         call dword ptr [0x98b760]
// 005b110f  8b542418             mov edx, dword ptr [esp + 0x18]
// 005b1113  8b06                 mov eax, dword ptr [esi]
// 005b1115  52                   push edx
// 005b1116  57                   push edi
// 005b1117  50                   push eax
// 005b1118  8d442418             lea eax, [esp + 0x18]
// 005b111c  50                   push eax
// 005b111d  8bce                 mov ecx, esi
// 005b111f  e80cfeffff           call 0x5b0f30
// 005b1124  5f                   pop edi
// 005b1125  5e                   pop esi
// 005b1126  5b                   pop ebx
// 005b1127  83c408               add esp, 8
// 005b112a  c20400               ret 4
// standard library vector<pod12> (function ?push_back@?$vector@UE@@V?$allocator@UE@@@std@@@std@@QAEXABUE@@@Z)

// stl: vector<pod12>
struct E { int v[3]; };
#include <vector>
template class std::vector<E>;
