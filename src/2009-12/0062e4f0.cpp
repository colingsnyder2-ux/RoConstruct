// from server: 100% by auto
// roc 2009-12 0062e4f0  unit: RBX::Time::W4SampleMethod::?$EnumDesc  size: 152 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0062e4f0
//
// 0062e4f0  55                   push ebp
// 0062e4f1  8bec                 mov ebp, esp
// 0062e4f3  6aff                 push -1
// 0062e4f5  6890fc9300           push 0x93fc90
// 0062e4fa  64a100000000         mov eax, dword ptr fs:[0]
// 0062e500  50                   push eax
// 0062e501  64892500000000       mov dword ptr fs:[0], esp
// 0062e508  83ec08               sub esp, 8
// 0062e50b  53                   push ebx
// 0062e50c  8b5d08               mov ebx, dword ptr [ebp + 8]
// 0062e50f  33c0                 xor eax, eax
// 0062e511  56                   push esi
// 0062e512  8bf1                 mov esi, ecx
// 0062e514  57                   push edi
// 0062e515  8965f0               mov dword ptr [ebp - 0x10], esp
// 0062e518  8975ec               mov dword ptr [ebp - 0x14], esi
// 0062e51b  89460c               mov dword ptr [esi + 0xc], eax
// 0062e51e  894610               mov dword ptr [esi + 0x10], eax
// 0062e521  894614               mov dword ptr [esi + 0x14], eax
// 0062e524  3bd8                 cmp ebx, eax
// 0062e526  744d                 je 0x62e575
// 0062e528  81fbffffff1f         cmp ebx, 0x1fffffff
// 0062e52e  7605                 jbe 0x62e535
// 0062e530  e82b3ce1ff           call 0x442160
// 0062e535  50                   push eax
// 0062e536  53                   push ebx
// 0062e537  e894d5f4ff           call 0x57bad0
// 0062e53c  8bf8                 mov edi, eax
// 0062e53e  c6450800             mov byte ptr [ebp + 8], 0
// 0062e542  8b4d08               mov ecx, dword ptr [ebp + 8]
// 0062e545  8b5508               mov edx, dword ptr [ebp + 8]
// 0062e548  51                   push ecx
// 0062e549  8b4d0c               mov ecx, dword ptr [ebp + 0xc]
// 0062e54c  8d04df               lea eax, [edi + ebx*8]
// 0062e54f  52                   push edx
// 0062e550  894614               mov dword ptr [esi + 0x14], eax
// 0062e553  8d4608               lea eax, [esi + 8]
// 0062e556  50                   push eax
// 0062e557  51                   push ecx
// 0062e558  53                   push ebx
// 0062e559  57                   push edi
// 0062e55a  897e0c               mov dword ptr [esi + 0xc], edi
// 0062e55d  897e10               mov dword ptr [esi + 0x10], edi
// 0062e560  c745fc00000000       mov dword ptr [ebp - 4], 0
// 0062e567  e8848adfff           call 0x426ff0
// 0062e56c  8d14df               lea edx, [edi + ebx*8]
// 0062e56f  83c420               add esp, 0x20
// 0062e572  895610               mov dword ptr [esi + 0x10], edx
// 0062e575  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 0062e578  5f                   pop edi
// 0062e579  5e                   pop esi
// 0062e57a  64890d00000000       mov dword ptr fs:[0], ecx
// 0062e581  5b                   pop ebx
// 0062e582  8be5                 mov esp, ebp
// 0062e584  5d                   pop ebp
// 0062e585  c20800               ret 8
// standard library vector<pod8> (function ?_Construct_n@?$vector@UE@@V?$allocator@UE@@@std@@@std@@QAEXIABUE@@@Z)

// stl: vector<pod8>
struct E { int v[2]; };
#include <vector>
template class std::vector<E>;
