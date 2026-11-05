// from server: 100% by auto
// roc 2007-08 00539320  unit: RBX::VScriptContext::?$FactoryProduct  size: 149 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00539320
//
// 00539320  55                   push ebp
// 00539321  8bec                 mov ebp, esp
// 00539323  6aff                 push -1
// 00539325  68e00b7500           push 0x750be0
// 0053932a  64a100000000         mov eax, dword ptr fs:[0]
// 00539330  50                   push eax
// 00539331  64892500000000       mov dword ptr fs:[0], esp
// 00539338  83ec08               sub esp, 8
// 0053933b  53                   push ebx
// 0053933c  8b5d08               mov ebx, dword ptr [ebp + 8]
// 0053933f  33c0                 xor eax, eax
// 00539341  3bd8                 cmp ebx, eax
// 00539343  56                   push esi
// 00539344  8bf1                 mov esi, ecx
// 00539346  57                   push edi
// 00539347  8965f0               mov dword ptr [ebp - 0x10], esp
// 0053934a  8975ec               mov dword ptr [ebp - 0x14], esi
// 0053934d  894604               mov dword ptr [esi + 4], eax
// 00539350  894608               mov dword ptr [esi + 8], eax
// 00539353  89460c               mov dword ptr [esi + 0xc], eax
// 00539356  744a                 je 0x5393a2
// 00539358  81fbffffff1f         cmp ebx, 0x1fffffff
// 0053935e  7605                 jbe 0x539365
// 00539360  e89be4edff           call 0x417800
// 00539365  50                   push eax
// 00539366  53                   push ebx
// 00539367  e854e70200           call 0x567ac0
// 0053936c  8bf8                 mov edi, eax
// 0053936e  c6450800             mov byte ptr [ebp + 8], 0
// 00539372  8b4d08               mov ecx, dword ptr [ebp + 8]
// 00539375  8b5508               mov edx, dword ptr [ebp + 8]
// 00539378  51                   push ecx
// 00539379  52                   push edx
// 0053937a  8d04df               lea eax, [edi + ebx*8]
// 0053937d  89460c               mov dword ptr [esi + 0xc], eax
// 00539380  8b450c               mov eax, dword ptr [ebp + 0xc]
// 00539383  56                   push esi
// 00539384  50                   push eax
// 00539385  53                   push ebx
// 00539386  57                   push edi
// 00539387  897e04               mov dword ptr [esi + 4], edi
// 0053938a  897e08               mov dword ptr [esi + 8], edi
// 0053938d  c745fc00000000       mov dword ptr [ebp - 4], 0
// 00539394  e89746efff           call 0x42da30
// 00539399  8d0cdf               lea ecx, [edi + ebx*8]
// 0053939c  83c420               add esp, 0x20
// 0053939f  894e08               mov dword ptr [esi + 8], ecx
// 005393a2  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 005393a5  5f                   pop edi
// 005393a6  5e                   pop esi
// 005393a7  64890d00000000       mov dword ptr fs:[0], ecx
// 005393ae  5b                   pop ebx
// 005393af  8be5                 mov esp, ebp
// 005393b1  5d                   pop ebp
// 005393b2  c20800               ret 8
// standard library vector<pod8> (function ?_Construct_n@?$vector@UE@@V?$allocator@UE@@@std@@@std@@QAEXIABUE@@@Z)

// stl: vector<pod8>
struct E { int v[2]; };
#include <vector>
template class std::vector<E>;
