// from server: 100% by auto
// roc 2009-12 00798d50  unit: lua_exception  size: 239 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00798d50
//
// 00798d50  55                   push ebp
// 00798d51  8bec                 mov ebp, esp
// 00798d53  6aff                 push -1
// 00798d55  6888459500           push 0x954588
// 00798d5a  64a100000000         mov eax, dword ptr fs:[0]
// 00798d60  50                   push eax
// 00798d61  64892500000000       mov dword ptr fs:[0], esp
// 00798d68  83ec0c               sub esp, 0xc
// 00798d6b  53                   push ebx
// 00798d6c  56                   push esi
// 00798d6d  57                   push edi
// 00798d6e  8965f0               mov dword ptr [ebp - 0x10], esp
// 00798d71  8bf1                 mov esi, ecx
// 00798d73  6a04                 push 4
// 00798d75  8975e8               mov dword ptr [ebp - 0x18], esi
// 00798d78  e8e3aa0500           call 0x7f3860
// 00798d7d  83c404               add esp, 4
// 00798d80  85c0                 test eax, eax
// 00798d82  7404                 je 0x798d88
// 00798d84  8930                 mov dword ptr [eax], esi
// 00798d86  eb02                 jmp 0x798d8a
// 00798d88  33c0                 xor eax, eax
// 00798d8a  8906                 mov dword ptr [esi], eax
// 00798d8c  8b5d08               mov ebx, dword ptr [ebp + 8]
// 00798d8f  8b4b10               mov ecx, dword ptr [ebx + 0x10]
// 00798d92  2b4b0c               sub ecx, dword ptr [ebx + 0xc]
// 00798d95  b8abaaaa2a           mov eax, 0x2aaaaaab
// 00798d9a  f7e9                 imul ecx
// 00798d9c  c1fa02               sar edx, 2
// 00798d9f  8bfa                 mov edi, edx
// 00798da1  b800000000           mov eax, 0
// 00798da6  c1ef1f               shr edi, 0x1f
// 00798da9  03fa                 add edi, edx
// 00798dab  c745fc00000000       mov dword ptr [ebp - 4], 0
// 00798db2  89460c               mov dword ptr [esi + 0xc], eax
// 00798db5  894610               mov dword ptr [esi + 0x10], eax
// 00798db8  894614               mov dword ptr [esi + 0x14], eax
// 00798dbb  746d                 je 0x798e2a
// 00798dbd  81ffaaaaaa0a         cmp edi, 0xaaaaaaa
// 00798dc3  7605                 jbe 0x798dca
// 00798dc5  e89693caff           call 0x442160
// 00798dca  50                   push eax
// 00798dcb  57                   push edi
// 00798dcc  e8aff0ffff           call 0x797e80
// 00798dd1  8d0c7f               lea ecx, [edi + edi*2]
// 00798dd4  8d14c8               lea edx, [eax + ecx*8]
// 00798dd7  89460c               mov dword ptr [esi + 0xc], eax
// 00798dda  894610               mov dword ptr [esi + 0x10], eax
// 00798ddd  895614               mov dword ptr [esi + 0x14], edx
// 00798de0  8b4310               mov eax, dword ptr [ebx + 0x10]
// 00798de3  83c408               add esp, 8
// 00798de6  c645fc01             mov byte ptr [ebp - 4], 1
// 00798dea  8945ec               mov dword ptr [ebp - 0x14], eax
// 00798ded  39430c               cmp dword ptr [ebx + 0xc], eax
// 00798df0  7606                 jbe 0x798df8
// 00798df2  ff1560b79800         call dword ptr [0x98b760]
// 00798df8  8b7b0c               mov edi, dword ptr [ebx + 0xc]
// 00798dfb  3b7b10               cmp edi, dword ptr [ebx + 0x10]
// 00798dfe  7606                 jbe 0x798e06
// 00798e00  ff1560b79800         call dword ptr [0x98b760]
// 00798e06  8b460c               mov eax, dword ptr [esi + 0xc]
// 00798e09  c6450800             mov byte ptr [ebp + 8], 0
// 00798e0d  8b4d08               mov ecx, dword ptr [ebp + 8]
// 00798e10  8b5508               mov edx, dword ptr [ebp + 8]
// 00798e13  51                   push ecx
// 00798e14  52                   push edx
// 00798e15  8b55ec               mov edx, dword ptr [ebp - 0x14]
// 00798e18  8d4e08               lea ecx, [esi + 8]
// 00798e1b  51                   push ecx
// 00798e1c  50                   push eax
// 00798e1d  52                   push edx
// 00798e1e  57                   push edi
// 00798e1f  e8bcf7ffff           call 0x7985e0
// 00798e24  83c418               add esp, 0x18
// 00798e27  894610               mov dword ptr [esi + 0x10], eax
// 00798e2a  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 00798e2d  5f                   pop edi
// 00798e2e  8bc6                 mov eax, esi
// 00798e30  5e                   pop esi
// 00798e31  64890d00000000       mov dword ptr fs:[0], ecx
// 00798e38  5b                   pop ebx
// 00798e39  8be5                 mov esp, ebp
// 00798e3b  5d                   pop ebp
// 00798e3c  c20400               ret 4
// standard library vector<pod24> (function ??0?$vector@UE@@V?$allocator@UE@@@std@@@std@@QAE@ABV01@@Z)

// stl: vector<pod24>
struct E { int v[6]; };
#include <vector>
template class std::vector<E>;
