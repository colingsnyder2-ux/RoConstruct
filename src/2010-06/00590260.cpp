// from server: 100% by auto
// roc 2010-06 00590260  unit: RBX::Time::W4SampleMethod::?$EnumDesc  size: 152 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00590260
//
// 00590260  55                   push ebp
// 00590261  8bec                 mov ebp, esp
// 00590263  6aff                 push -1
// 00590265  6820199900           push 0x991920
// 0059026a  64a100000000         mov eax, dword ptr fs:[0]
// 00590270  50                   push eax
// 00590271  64892500000000       mov dword ptr fs:[0], esp
// 00590278  83ec08               sub esp, 8
// 0059027b  53                   push ebx
// 0059027c  8b5d08               mov ebx, dword ptr [ebp + 8]
// 0059027f  33c0                 xor eax, eax
// 00590281  56                   push esi
// 00590282  8bf1                 mov esi, ecx
// 00590284  57                   push edi
// 00590285  8965f0               mov dword ptr [ebp - 0x10], esp
// 00590288  8975ec               mov dword ptr [ebp - 0x14], esi
// 0059028b  89460c               mov dword ptr [esi + 0xc], eax
// 0059028e  894610               mov dword ptr [esi + 0x10], eax
// 00590291  894614               mov dword ptr [esi + 0x14], eax
// 00590294  3bd8                 cmp ebx, eax
// 00590296  744d                 je 0x5902e5
// 00590298  81fbffffff1f         cmp ebx, 0x1fffffff
// 0059029e  7605                 jbe 0x5902a5
// 005902a0  e84b3be9ff           call 0x423df0
// 005902a5  50                   push eax
// 005902a6  53                   push ebx
// 005902a7  e804e33600           call 0x8fe5b0
// 005902ac  8bf8                 mov edi, eax
// 005902ae  c6450800             mov byte ptr [ebp + 8], 0
// 005902b2  8b4d08               mov ecx, dword ptr [ebp + 8]
// 005902b5  8b5508               mov edx, dword ptr [ebp + 8]
// 005902b8  51                   push ecx
// 005902b9  8b4d0c               mov ecx, dword ptr [ebp + 0xc]
// 005902bc  8d04df               lea eax, [edi + ebx*8]
// 005902bf  52                   push edx
// 005902c0  894614               mov dword ptr [esi + 0x14], eax
// 005902c3  8d4608               lea eax, [esi + 8]
// 005902c6  50                   push eax
// 005902c7  51                   push ecx
// 005902c8  53                   push ebx
// 005902c9  57                   push edi
// 005902ca  897e0c               mov dword ptr [esi + 0xc], edi
// 005902cd  897e10               mov dword ptr [esi + 0x10], edi
// 005902d0  c745fc00000000       mov dword ptr [ebp - 4], 0
// 005902d7  e87471e9ff           call 0x427450
// 005902dc  8d14df               lea edx, [edi + ebx*8]
// 005902df  83c420               add esp, 0x20
// 005902e2  895610               mov dword ptr [esi + 0x10], edx
// 005902e5  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 005902e8  5f                   pop edi
// 005902e9  5e                   pop esi
// 005902ea  64890d00000000       mov dword ptr fs:[0], ecx
// 005902f1  5b                   pop ebx
// 005902f2  8be5                 mov esp, ebp
// 005902f4  5d                   pop ebp
// 005902f5  c20800               ret 8
// standard library vector<pod8> (function ?_Construct_n@?$vector@UE@@V?$allocator@UE@@@std@@@std@@QAEXIABUE@@@Z)

// stl: vector<pod8>
struct E { int v[2]; };
#include <vector>
template class std::vector<E>;
