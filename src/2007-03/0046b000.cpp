// from server: 100% by auto
// roc 2007-03 0046b000  unit: seg_00460000  size: 131 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0046b000
//
// 0046b000  83ec08               sub esp, 8
// 0046b003  56                   push esi
// 0046b004  8bf1                 mov esi, ecx
// 0046b006  8b5604               mov edx, dword ptr [esi + 4]
// 0046b009  85d2                 test edx, edx
// 0046b00b  57                   push edi
// 0046b00c  7504                 jne 0x46b012
// 0046b00e  33c9                 xor ecx, ecx
// 0046b010  eb08                 jmp 0x46b01a
// 0046b012  8b4e08               mov ecx, dword ptr [esi + 8]
// 0046b015  2bca                 sub ecx, edx
// 0046b017  c1f906               sar ecx, 6
// 0046b01a  85d2                 test edx, edx
// 0046b01c  743d                 je 0x46b05b
// 0046b01e  8b460c               mov eax, dword ptr [esi + 0xc]
// 0046b021  2bc2                 sub eax, edx
// 0046b023  c1f806               sar eax, 6
// 0046b026  3bc8                 cmp ecx, eax
// 0046b028  7331                 jae 0x46b05b
// 0046b02a  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0046b02e  8b542414             mov edx, dword ptr [esp + 0x14]
// 0046b032  8b7e08               mov edi, dword ptr [esi + 8]
// 0046b035  c644240800           mov byte ptr [esp + 8], 0
// 0046b03a  8b442408             mov eax, dword ptr [esp + 8]
// 0046b03e  50                   push eax
// 0046b03f  51                   push ecx
// 0046b040  56                   push esi
// 0046b041  52                   push edx
// 0046b042  6a01                 push 1
// 0046b044  57                   push edi
// 0046b045  e8b6f8ffff           call 0x46a900
// 0046b04a  83c418               add esp, 0x18
// 0046b04d  83c740               add edi, 0x40
// 0046b050  897e08               mov dword ptr [esi + 8], edi
// 0046b053  5f                   pop edi
// 0046b054  5e                   pop esi
// 0046b055  83c408               add esp, 8
// 0046b058  c20400               ret 4
// 0046b05b  8b7e08               mov edi, dword ptr [esi + 8]
// 0046b05e  3bd7                 cmp edx, edi
// 0046b060  7606                 jbe 0x46b068
// 0046b062  ff1544e97700         call dword ptr [0x77e944]
// 0046b068  8b442414             mov eax, dword ptr [esp + 0x14]
// 0046b06c  50                   push eax
// 0046b06d  57                   push edi
// 0046b06e  56                   push esi
// 0046b06f  8d4c2414             lea ecx, [esp + 0x14]
// 0046b073  51                   push ecx
// 0046b074  8bce                 mov ecx, esi
// 0046b076  e8d5feffff           call 0x46af50
// 0046b07b  5f                   pop edi
// 0046b07c  5e                   pop esi
// 0046b07d  83c408               add esp, 8
// 0046b080  c20400               ret 4
// standard library vector<pod64> (function ?push_back@?$vector@UE@@V?$allocator@UE@@@std@@@std@@QAEXABUE@@@Z)

// stl: vector<pod64>
struct E { int v[16]; };
#include <vector>
template class std::vector<E>;
