// from server: 100% by auto
// roc 2007-08 0046af60  unit: RBX::LDraw2Lua::LDraw2RobloxPartMap  size: 131 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0046af60
//
// 0046af60  83ec08               sub esp, 8
// 0046af63  56                   push esi
// 0046af64  8bf1                 mov esi, ecx
// 0046af66  8b5604               mov edx, dword ptr [esi + 4]
// 0046af69  85d2                 test edx, edx
// 0046af6b  57                   push edi
// 0046af6c  7504                 jne 0x46af72
// 0046af6e  33c9                 xor ecx, ecx
// 0046af70  eb08                 jmp 0x46af7a
// 0046af72  8b4e08               mov ecx, dword ptr [esi + 8]
// 0046af75  2bca                 sub ecx, edx
// 0046af77  c1f906               sar ecx, 6
// 0046af7a  85d2                 test edx, edx
// 0046af7c  743d                 je 0x46afbb
// 0046af7e  8b460c               mov eax, dword ptr [esi + 0xc]
// 0046af81  2bc2                 sub eax, edx
// 0046af83  c1f806               sar eax, 6
// 0046af86  3bc8                 cmp ecx, eax
// 0046af88  7331                 jae 0x46afbb
// 0046af8a  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0046af8e  8b542414             mov edx, dword ptr [esp + 0x14]
// 0046af92  8b7e08               mov edi, dword ptr [esi + 8]
// 0046af95  c644240800           mov byte ptr [esp + 8], 0
// 0046af9a  8b442408             mov eax, dword ptr [esp + 8]
// 0046af9e  50                   push eax
// 0046af9f  51                   push ecx
// 0046afa0  56                   push esi
// 0046afa1  52                   push edx
// 0046afa2  6a01                 push 1
// 0046afa4  57                   push edi
// 0046afa5  e8b6f8ffff           call 0x46a860
// 0046afaa  83c418               add esp, 0x18
// 0046afad  83c740               add edi, 0x40
// 0046afb0  897e08               mov dword ptr [esi + 8], edi
// 0046afb3  5f                   pop edi
// 0046afb4  5e                   pop esi
// 0046afb5  83c408               add esp, 8
// 0046afb8  c20400               ret 4
// 0046afbb  8b7e08               mov edi, dword ptr [esi + 8]
// 0046afbe  3bd7                 cmp edx, edi
// 0046afc0  7606                 jbe 0x46afc8
// 0046afc2  ff15d8e67700         call dword ptr [0x77e6d8]
// 0046afc8  8b442414             mov eax, dword ptr [esp + 0x14]
// 0046afcc  50                   push eax
// 0046afcd  57                   push edi
// 0046afce  56                   push esi
// 0046afcf  8d4c2414             lea ecx, [esp + 0x14]
// 0046afd3  51                   push ecx
// 0046afd4  8bce                 mov ecx, esi
// 0046afd6  e8d5feffff           call 0x46aeb0
// 0046afdb  5f                   pop edi
// 0046afdc  5e                   pop esi
// 0046afdd  83c408               add esp, 8
// 0046afe0  c20400               ret 4
// standard library vector<pod64> (function ?push_back@?$vector@UE@@V?$allocator@UE@@@std@@@std@@QAEXABUE@@@Z)

// stl: vector<pod64>
struct E { int v[16]; };
#include <vector>
template class std::vector<E>;
