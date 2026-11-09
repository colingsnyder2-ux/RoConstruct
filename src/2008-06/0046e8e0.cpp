// from server: 100% by auto
// roc 2008-06 0046e8e0  unit: RBX::LDraw2Lua::LDraw2RobloxPartMap  size: 128 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0046e8e0
//
// 0046e8e0  83ec08               sub esp, 8
// 0046e8e3  56                   push esi
// 0046e8e4  8bf1                 mov esi, ecx
// 0046e8e6  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 0046e8e9  57                   push edi
// 0046e8ea  85c9                 test ecx, ecx
// 0046e8ec  7504                 jne 0x46e8f2
// 0046e8ee  33c0                 xor eax, eax
// 0046e8f0  eb08                 jmp 0x46e8fa
// 0046e8f2  8b4614               mov eax, dword ptr [esi + 0x14]
// 0046e8f5  2bc1                 sub eax, ecx
// 0046e8f7  c1f806               sar eax, 6
// 0046e8fa  8b7e10               mov edi, dword ptr [esi + 0x10]
// 0046e8fd  8bd7                 mov edx, edi
// 0046e8ff  2bd1                 sub edx, ecx
// 0046e901  c1fa06               sar edx, 6
// 0046e904  3bd0                 cmp edx, eax
// 0046e906  7331                 jae 0x46e939
// 0046e908  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0046e90c  c644240800           mov byte ptr [esp + 8], 0
// 0046e911  8b442408             mov eax, dword ptr [esp + 8]
// 0046e915  50                   push eax
// 0046e916  8b442418             mov eax, dword ptr [esp + 0x18]
// 0046e91a  51                   push ecx
// 0046e91b  8d5608               lea edx, [esi + 8]
// 0046e91e  52                   push edx
// 0046e91f  50                   push eax
// 0046e920  6a01                 push 1
// 0046e922  57                   push edi
// 0046e923  e858f8ffff           call 0x46e180
// 0046e928  83c418               add esp, 0x18
// 0046e92b  83c740               add edi, 0x40
// 0046e92e  897e10               mov dword ptr [esi + 0x10], edi
// 0046e931  5f                   pop edi
// 0046e932  5e                   pop esi
// 0046e933  83c408               add esp, 8
// 0046e936  c20400               ret 4
// 0046e939  3bcf                 cmp ecx, edi
// 0046e93b  7606                 jbe 0x46e943
// 0046e93d  ff1590288000         call dword ptr [0x802890]
// 0046e943  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0046e947  8b06                 mov eax, dword ptr [esi]
// 0046e949  51                   push ecx
// 0046e94a  57                   push edi
// 0046e94b  50                   push eax
// 0046e94c  8d542414             lea edx, [esp + 0x14]
// 0046e950  52                   push edx
// 0046e951  8bce                 mov ecx, esi
// 0046e953  e8a8feffff           call 0x46e800
// 0046e958  5f                   pop edi
// 0046e959  5e                   pop esi
// 0046e95a  83c408               add esp, 8
// 0046e95d  c20400               ret 4
// standard library vector<pod64> (function ?push_back@?$vector@UE@@V?$allocator@UE@@@std@@@std@@QAEXABUE@@@Z)

// stl: vector<pod64>
struct E { int v[16]; };
#include <vector>
template class std::vector<E>;
