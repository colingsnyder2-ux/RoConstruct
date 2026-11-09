// from server: 100% by auto
// roc 2010-06 00482760  unit: RBX::LDraw2Lua::LDraw2RobloxPartMap  size: 128 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00482760
//
// 00482760  83ec08               sub esp, 8
// 00482763  56                   push esi
// 00482764  8bf1                 mov esi, ecx
// 00482766  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 00482769  57                   push edi
// 0048276a  85c9                 test ecx, ecx
// 0048276c  7504                 jne 0x482772
// 0048276e  33c0                 xor eax, eax
// 00482770  eb08                 jmp 0x48277a
// 00482772  8b4614               mov eax, dword ptr [esi + 0x14]
// 00482775  2bc1                 sub eax, ecx
// 00482777  c1f806               sar eax, 6
// 0048277a  8b7e10               mov edi, dword ptr [esi + 0x10]
// 0048277d  8bd7                 mov edx, edi
// 0048277f  2bd1                 sub edx, ecx
// 00482781  c1fa06               sar edx, 6
// 00482784  3bd0                 cmp edx, eax
// 00482786  7331                 jae 0x4827b9
// 00482788  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0048278c  c644240800           mov byte ptr [esp + 8], 0
// 00482791  8b442408             mov eax, dword ptr [esp + 8]
// 00482795  50                   push eax
// 00482796  8b442418             mov eax, dword ptr [esp + 0x18]
// 0048279a  51                   push ecx
// 0048279b  8d5608               lea edx, [esi + 8]
// 0048279e  52                   push edx
// 0048279f  50                   push eax
// 004827a0  6a01                 push 1
// 004827a2  57                   push edi
// 004827a3  e808f8ffff           call 0x481fb0
// 004827a8  83c418               add esp, 0x18
// 004827ab  83c740               add edi, 0x40
// 004827ae  897e10               mov dword ptr [esi + 0x10], edi
// 004827b1  5f                   pop edi
// 004827b2  5e                   pop esi
// 004827b3  83c408               add esp, 8
// 004827b6  c20400               ret 4
// 004827b9  3bcf                 cmp ecx, edi
// 004827bb  7606                 jbe 0x4827c3
// 004827bd  ff150ca99e00         call dword ptr [0x9ea90c]
// 004827c3  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 004827c7  8b06                 mov eax, dword ptr [esi]
// 004827c9  51                   push ecx
// 004827ca  57                   push edi
// 004827cb  50                   push eax
// 004827cc  8d542414             lea edx, [esp + 0x14]
// 004827d0  52                   push edx
// 004827d1  8bce                 mov ecx, esi
// 004827d3  e8a8feffff           call 0x482680
// 004827d8  5f                   pop edi
// 004827d9  5e                   pop esi
// 004827da  83c408               add esp, 8
// 004827dd  c20400               ret 4
// standard library vector<pod64> (function ?push_back@?$vector@UE@@V?$allocator@UE@@@std@@@std@@QAEXABUE@@@Z)

// stl: vector<pod64>
struct E { int v[16]; };
#include <vector>
template class std::vector<E>;
