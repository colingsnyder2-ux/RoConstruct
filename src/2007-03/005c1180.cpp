// from server: 100% by auto
// roc 2007-03 005c1180  unit: seg_005c0000  size: 131 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005c1180
//
// 005c1180  83ec08               sub esp, 8
// 005c1183  56                   push esi
// 005c1184  8bf1                 mov esi, ecx
// 005c1186  8b5604               mov edx, dword ptr [esi + 4]
// 005c1189  85d2                 test edx, edx
// 005c118b  57                   push edi
// 005c118c  7504                 jne 0x5c1192
// 005c118e  33c9                 xor ecx, ecx
// 005c1190  eb08                 jmp 0x5c119a
// 005c1192  8b4e08               mov ecx, dword ptr [esi + 8]
// 005c1195  2bca                 sub ecx, edx
// 005c1197  c1f904               sar ecx, 4
// 005c119a  85d2                 test edx, edx
// 005c119c  743d                 je 0x5c11db
// 005c119e  8b460c               mov eax, dword ptr [esi + 0xc]
// 005c11a1  2bc2                 sub eax, edx
// 005c11a3  c1f804               sar eax, 4
// 005c11a6  3bc8                 cmp ecx, eax
// 005c11a8  7331                 jae 0x5c11db
// 005c11aa  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 005c11ae  8b542414             mov edx, dword ptr [esp + 0x14]
// 005c11b2  8b7e08               mov edi, dword ptr [esi + 8]
// 005c11b5  c644240800           mov byte ptr [esp + 8], 0
// 005c11ba  8b442408             mov eax, dword ptr [esp + 8]
// 005c11be  50                   push eax
// 005c11bf  51                   push ecx
// 005c11c0  56                   push esi
// 005c11c1  52                   push edx
// 005c11c2  6a01                 push 1
// 005c11c4  57                   push edi
// 005c11c5  e8d6f9ffff           call 0x5c0ba0
// 005c11ca  83c418               add esp, 0x18
// 005c11cd  83c710               add edi, 0x10
// 005c11d0  897e08               mov dword ptr [esi + 8], edi
// 005c11d3  5f                   pop edi
// 005c11d4  5e                   pop esi
// 005c11d5  83c408               add esp, 8
// 005c11d8  c20400               ret 4
// 005c11db  8b7e08               mov edi, dword ptr [esi + 8]
// 005c11de  3bd7                 cmp edx, edi
// 005c11e0  7606                 jbe 0x5c11e8
// 005c11e2  ff1544e97700         call dword ptr [0x77e944]
// 005c11e8  8b442414             mov eax, dword ptr [esp + 0x14]
// 005c11ec  50                   push eax
// 005c11ed  57                   push edi
// 005c11ee  56                   push esi
// 005c11ef  8d4c2414             lea ecx, [esp + 0x14]
// 005c11f3  51                   push ecx
// 005c11f4  8bce                 mov ecx, esi
// 005c11f6  e8f5feffff           call 0x5c10f0
// 005c11fb  5f                   pop edi
// 005c11fc  5e                   pop esi
// 005c11fd  83c408               add esp, 8
// 005c1200  c20400               ret 4
// standard library vector<pod16> (function ?push_back@?$vector@UE@@V?$allocator@UE@@@std@@@std@@QAEXABUE@@@Z)

// stl: vector<pod16>
struct E { int v[4]; };
#include <vector>
template class std::vector<E>;
