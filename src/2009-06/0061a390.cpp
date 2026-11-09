// from server: 100% by auto
// roc 2009-06 0061a390  unit: RBX::VChangeHistoryService::?$FactoryProduct  size: 152 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0061a390
//
// 0061a390  55                   push ebp
// 0061a391  8bec                 mov ebp, esp
// 0061a393  6aff                 push -1
// 0061a395  68e0828600           push 0x8682e0
// 0061a39a  64a100000000         mov eax, dword ptr fs:[0]
// 0061a3a0  50                   push eax
// 0061a3a1  64892500000000       mov dword ptr fs:[0], esp
// 0061a3a8  83ec08               sub esp, 8
// 0061a3ab  53                   push ebx
// 0061a3ac  8b5d08               mov ebx, dword ptr [ebp + 8]
// 0061a3af  33c0                 xor eax, eax
// 0061a3b1  56                   push esi
// 0061a3b2  8bf1                 mov esi, ecx
// 0061a3b4  57                   push edi
// 0061a3b5  8965f0               mov dword ptr [ebp - 0x10], esp
// 0061a3b8  8975ec               mov dword ptr [ebp - 0x14], esi
// 0061a3bb  89460c               mov dword ptr [esi + 0xc], eax
// 0061a3be  894610               mov dword ptr [esi + 0x10], eax
// 0061a3c1  894614               mov dword ptr [esi + 0x14], eax
// 0061a3c4  3bd8                 cmp ebx, eax
// 0061a3c6  744d                 je 0x61a415
// 0061a3c8  81fbffffff1f         cmp ebx, 0x1fffffff
// 0061a3ce  7605                 jbe 0x61a3d5
// 0061a3d0  e88b5fe7ff           call 0x490360
// 0061a3d5  50                   push eax
// 0061a3d6  53                   push ebx
// 0061a3d7  e814abe6ff           call 0x484ef0
// 0061a3dc  8bf8                 mov edi, eax
// 0061a3de  c6450800             mov byte ptr [ebp + 8], 0
// 0061a3e2  8b4d08               mov ecx, dword ptr [ebp + 8]
// 0061a3e5  8b5508               mov edx, dword ptr [ebp + 8]
// 0061a3e8  51                   push ecx
// 0061a3e9  8b4d0c               mov ecx, dword ptr [ebp + 0xc]
// 0061a3ec  8d04df               lea eax, [edi + ebx*8]
// 0061a3ef  52                   push edx
// 0061a3f0  894614               mov dword ptr [esi + 0x14], eax
// 0061a3f3  8d4608               lea eax, [esi + 8]
// 0061a3f6  50                   push eax
// 0061a3f7  51                   push ecx
// 0061a3f8  53                   push ebx
// 0061a3f9  57                   push edi
// 0061a3fa  897e0c               mov dword ptr [esi + 0xc], edi
// 0061a3fd  897e10               mov dword ptr [esi + 0x10], edi
// 0061a400  c745fc00000000       mov dword ptr [ebp - 4], 0
// 0061a407  e8c4bfe0ff           call 0x4263d0
// 0061a40c  8d14df               lea edx, [edi + ebx*8]
// 0061a40f  83c420               add esp, 0x20
// 0061a412  895610               mov dword ptr [esi + 0x10], edx
// 0061a415  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 0061a418  5f                   pop edi
// 0061a419  5e                   pop esi
// 0061a41a  64890d00000000       mov dword ptr fs:[0], ecx
// 0061a421  5b                   pop ebx
// 0061a422  8be5                 mov esp, ebp
// 0061a424  5d                   pop ebp
// 0061a425  c20800               ret 8
// standard library vector<pod8> (function ?_Construct_n@?$vector@UE@@V?$allocator@UE@@@std@@@std@@QAEXIABUE@@@Z)

// stl: vector<pod8>
struct E { int v[2]; };
#include <vector>
template class std::vector<E>;
