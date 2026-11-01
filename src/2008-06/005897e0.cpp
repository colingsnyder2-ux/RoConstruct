// from server: 100% by auto
// from server: 100% by auto
// roc 2008-06 005897e0  unit: RBX::VChangeHistoryService::?$FactoryProduct  size: 152 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005897e0
//
// 005897e0  55                   push ebp
// 005897e1  8bec                 mov ebp, esp
// 005897e3  6aff                 push -1
// 005897e5  6800157d00           push 0x7d1500
// 005897ea  64a100000000         mov eax, dword ptr fs:[0]
// 005897f0  50                   push eax
// 005897f1  64892500000000       mov dword ptr fs:[0], esp
// 005897f8  83ec08               sub esp, 8
// 005897fb  53                   push ebx
// 005897fc  8b5d08               mov ebx, dword ptr [ebp + 8]
// 005897ff  33c0                 xor eax, eax
// 00589801  56                   push esi
// 00589802  8bf1                 mov esi, ecx
// 00589804  57                   push edi
// 00589805  8965f0               mov dword ptr [ebp - 0x10], esp
// 00589808  8975ec               mov dword ptr [ebp - 0x14], esi
// 0058980b  89460c               mov dword ptr [esi + 0xc], eax
// 0058980e  894610               mov dword ptr [esi + 0x10], eax
// 00589811  894614               mov dword ptr [esi + 0x14], eax
// 00589814  3bd8                 cmp ebx, eax
// 00589816  744d                 je 0x589865
// 00589818  81fbffffff1f         cmp ebx, 0x1fffffff
// 0058981e  7605                 jbe 0x589825
// 00589820  e81bd5f3ff           call 0x4c6d40
// 00589825  50                   push eax
// 00589826  53                   push ebx
// 00589827  e814650e00           call 0x66fd40
// 0058982c  8bf8                 mov edi, eax
// 0058982e  c6450800             mov byte ptr [ebp + 8], 0
// 00589832  8b4d08               mov ecx, dword ptr [ebp + 8]
// 00589835  8b5508               mov edx, dword ptr [ebp + 8]
// 00589838  51                   push ecx
// 00589839  8b4d0c               mov ecx, dword ptr [ebp + 0xc]
// 0058983c  8d04df               lea eax, [edi + ebx*8]
// 0058983f  52                   push edx
// 00589840  894614               mov dword ptr [esi + 0x14], eax
// 00589843  8d4608               lea eax, [esi + 8]
// 00589846  50                   push eax
// 00589847  51                   push ecx
// 00589848  53                   push ebx
// 00589849  57                   push edi
// 0058984a  897e0c               mov dword ptr [esi + 0xc], edi
// 0058984d  897e10               mov dword ptr [esi + 0x10], edi
// 00589850  c745fc00000000       mov dword ptr [ebp - 4], 0
// 00589857  e8143ceaff           call 0x42d470
// 0058985c  8d14df               lea edx, [edi + ebx*8]
// 0058985f  83c420               add esp, 0x20
// 00589862  895610               mov dword ptr [esi + 0x10], edx
// 00589865  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 00589868  5f                   pop edi
// 00589869  5e                   pop esi
// 0058986a  64890d00000000       mov dword ptr fs:[0], ecx
// 00589871  5b                   pop ebx
// 00589872  8be5                 mov esp, ebp
// 00589874  5d                   pop ebp
// 00589875  c20800               ret 8
// standard library vector<pod8> (function ?_Construct_n@?$vector@UE@@V?$allocator@UE@@@std@@@std@@QAEXIABUE@@@Z)

// stl: vector<pod8>
struct E { int v[2]; };
#include <vector>
template class std::vector<E>;
