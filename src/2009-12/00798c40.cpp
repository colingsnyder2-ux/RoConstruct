// from server: 100% by auto
// roc 2009-12 00798c40  unit: lua_exception  size: 239 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00798c40
//
// 00798c40  55                   push ebp
// 00798c41  8bec                 mov ebp, esp
// 00798c43  6aff                 push -1
// 00798c45  6868459500           push 0x954568
// 00798c4a  64a100000000         mov eax, dword ptr fs:[0]
// 00798c50  50                   push eax
// 00798c51  64892500000000       mov dword ptr fs:[0], esp
// 00798c58  83ec0c               sub esp, 0xc
// 00798c5b  53                   push ebx
// 00798c5c  56                   push esi
// 00798c5d  57                   push edi
// 00798c5e  8965f0               mov dword ptr [ebp - 0x10], esp
// 00798c61  8bf1                 mov esi, ecx
// 00798c63  6a04                 push 4
// 00798c65  8975e8               mov dword ptr [ebp - 0x18], esi
// 00798c68  e8f3ab0500           call 0x7f3860
// 00798c6d  83c404               add esp, 4
// 00798c70  85c0                 test eax, eax
// 00798c72  7404                 je 0x798c78
// 00798c74  8930                 mov dword ptr [eax], esi
// 00798c76  eb02                 jmp 0x798c7a
// 00798c78  33c0                 xor eax, eax
// 00798c7a  8906                 mov dword ptr [esi], eax
// 00798c7c  8b5d08               mov ebx, dword ptr [ebp + 8]
// 00798c7f  8b4b10               mov ecx, dword ptr [ebx + 0x10]
// 00798c82  2b4b0c               sub ecx, dword ptr [ebx + 0xc]
// 00798c85  b8abaaaa2a           mov eax, 0x2aaaaaab
// 00798c8a  f7e9                 imul ecx
// 00798c8c  c1fa02               sar edx, 2
// 00798c8f  8bfa                 mov edi, edx
// 00798c91  b800000000           mov eax, 0
// 00798c96  c1ef1f               shr edi, 0x1f
// 00798c99  03fa                 add edi, edx
// 00798c9b  c745fc00000000       mov dword ptr [ebp - 4], 0
// 00798ca2  89460c               mov dword ptr [esi + 0xc], eax
// 00798ca5  894610               mov dword ptr [esi + 0x10], eax
// 00798ca8  894614               mov dword ptr [esi + 0x14], eax
// 00798cab  746d                 je 0x798d1a
// 00798cad  81ffaaaaaa0a         cmp edi, 0xaaaaaaa
// 00798cb3  7605                 jbe 0x798cba
// 00798cb5  e8a694caff           call 0x442160
// 00798cba  50                   push eax
// 00798cbb  57                   push edi
// 00798cbc  e8bff1ffff           call 0x797e80
// 00798cc1  8d0c7f               lea ecx, [edi + edi*2]
// 00798cc4  8d14c8               lea edx, [eax + ecx*8]
// 00798cc7  89460c               mov dword ptr [esi + 0xc], eax
// 00798cca  894610               mov dword ptr [esi + 0x10], eax
// 00798ccd  895614               mov dword ptr [esi + 0x14], edx
// 00798cd0  8b4310               mov eax, dword ptr [ebx + 0x10]
// 00798cd3  83c408               add esp, 8
// 00798cd6  c645fc01             mov byte ptr [ebp - 4], 1
// 00798cda  8945ec               mov dword ptr [ebp - 0x14], eax
// 00798cdd  39430c               cmp dword ptr [ebx + 0xc], eax
// 00798ce0  7606                 jbe 0x798ce8
// 00798ce2  ff1560b79800         call dword ptr [0x98b760]
// 00798ce8  8b7b0c               mov edi, dword ptr [ebx + 0xc]
// 00798ceb  3b7b10               cmp edi, dword ptr [ebx + 0x10]
// 00798cee  7606                 jbe 0x798cf6
// 00798cf0  ff1560b79800         call dword ptr [0x98b760]
// 00798cf6  8b460c               mov eax, dword ptr [esi + 0xc]
// 00798cf9  c6450800             mov byte ptr [ebp + 8], 0
// 00798cfd  8b4d08               mov ecx, dword ptr [ebp + 8]
// 00798d00  8b5508               mov edx, dword ptr [ebp + 8]
// 00798d03  51                   push ecx
// 00798d04  52                   push edx
// 00798d05  8b55ec               mov edx, dword ptr [ebp - 0x14]
// 00798d08  8d4e08               lea ecx, [esi + 8]
// 00798d0b  51                   push ecx
// 00798d0c  50                   push eax
// 00798d0d  52                   push edx
// 00798d0e  57                   push edi
// 00798d0f  e87cf8ffff           call 0x798590
// 00798d14  83c418               add esp, 0x18
// 00798d17  894610               mov dword ptr [esi + 0x10], eax
// 00798d1a  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 00798d1d  5f                   pop edi
// 00798d1e  8bc6                 mov eax, esi
// 00798d20  5e                   pop esi
// 00798d21  64890d00000000       mov dword ptr fs:[0], ecx
// 00798d28  5b                   pop ebx
// 00798d29  8be5                 mov esp, ebp
// 00798d2b  5d                   pop ebp
// 00798d2c  c20400               ret 4
// standard library vector<pod24> (function ??0?$vector@UE@@V?$allocator@UE@@@std@@@std@@QAE@ABV01@@Z)

// stl: vector<pod24>
struct E { int v[6]; };
#include <vector>
template class std::vector<E>;
