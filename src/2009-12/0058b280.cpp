// from server: 100% by auto
// roc 2009-12 0058b280  unit: RBX::BeveledBlockBuilder  size: 405 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0058b280
//
// 0058b280  55                   push ebp
// 0058b281  8bec                 mov ebp, esp
// 0058b283  6aff                 push -1
// 0058b285  68c0c99300           push 0x93c9c0
// 0058b28a  64a100000000         mov eax, dword ptr fs:[0]
// 0058b290  50                   push eax
// 0058b291  64892500000000       mov dword ptr fs:[0], esp
// 0058b298  83ec20               sub esp, 0x20
// 0058b29b  53                   push ebx
// 0058b29c  56                   push esi
// 0058b29d  8bf1                 mov esi, ecx
// 0058b29f  8b460c               mov eax, dword ptr [esi + 0xc]
// 0058b2a2  57                   push edi
// 0058b2a3  8965f0               mov dword ptr [ebp - 0x10], esp
// 0058b2a6  85c0                 test eax, eax
// 0058b2a8  7504                 jne 0x58b2ae
// 0058b2aa  33c9                 xor ecx, ecx
// 0058b2ac  eb18                 jmp 0x58b2c6
// 0058b2ae  8b5614               mov edx, dword ptr [esi + 0x14]
// 0058b2b1  2bd0                 sub edx, eax
// 0058b2b3  b8abaaaa2a           mov eax, 0x2aaaaaab
// 0058b2b8  f7ea                 imul edx
// 0058b2ba  c1fa02               sar edx, 2
// 0058b2bd  8bc2                 mov eax, edx
// 0058b2bf  c1e81f               shr eax, 0x1f
// 0058b2c2  03c2                 add eax, edx
// 0058b2c4  8bc8                 mov ecx, eax
// 0058b2c6  8b7d10               mov edi, dword ptr [ebp + 0x10]
// 0058b2c9  85ff                 test edi, edi
// 0058b2cb  0f8476020000         je 0x58b547
// 0058b2d1  8b5e10               mov ebx, dword ptr [esi + 0x10]
// 0058b2d4  8bd3                 mov edx, ebx
// 0058b2d6  2b560c               sub edx, dword ptr [esi + 0xc]
// 0058b2d9  b8abaaaa2a           mov eax, 0x2aaaaaab
// 0058b2de  f7ea                 imul edx
// 0058b2e0  c1fa02               sar edx, 2
// 0058b2e3  8bc2                 mov eax, edx
// 0058b2e5  c1e81f               shr eax, 0x1f
// 0058b2e8  03c2                 add eax, edx
// 0058b2ea  baaaaaaa0a           mov edx, 0xaaaaaaa
// 0058b2ef  2bd0                 sub edx, eax
// 0058b2f1  3bd7                 cmp edx, edi
// 0058b2f3  7305                 jae 0x58b2fa
// 0058b2f5  e8666eebff           call 0x442160
// 0058b2fa  8d1438               lea edx, [eax + edi]
// 0058b2fd  3bca                 cmp ecx, edx
// 0058b2ff  0f8325010000         jae 0x58b42a
// 0058b305  8bc1                 mov eax, ecx
// 0058b307  d1e8                 shr eax, 1
// 0058b309  bbaaaaaa0a           mov ebx, 0xaaaaaaa
// 0058b30e  2bd8                 sub ebx, eax
// 0058b310  3bd9                 cmp ebx, ecx
// 0058b312  730c                 jae 0x58b320
// 0058b314  c745ec00000000       mov dword ptr [ebp - 0x14], 0
// 0058b31b  8b4dec               mov ecx, dword ptr [ebp - 0x14]
// 0058b31e  eb05                 jmp 0x58b325
// 0058b320  03c8                 add ecx, eax
// 0058b322  894dec               mov dword ptr [ebp - 0x14], ecx
// 0058b325  3bca                 cmp ecx, edx
// 0058b327  7305                 jae 0x58b32e
// 0058b329  8955ec               mov dword ptr [ebp - 0x14], edx
// 0058b32c  8bca                 mov ecx, edx
// 0058b32e  6a00                 push 0
// 0058b330  51                   push ecx
// 0058b331  e84acb2000           call 0x797e80
// 0058b336  8b550c               mov edx, dword ptr [ebp + 0xc]
// 0058b339  2b560c               sub edx, dword ptr [esi + 0xc]
// 0058b33c  8bc8                 mov ecx, eax
// 0058b33e  b8abaaaa2a           mov eax, 0x2aaaaaab
// 0058b343  f7ea                 imul edx
// 0058b345  8b4514               mov eax, dword ptr [ebp + 0x14]
// 0058b348  c1fa02               sar edx, 2
// 0058b34b  8bda                 mov ebx, edx
// 0058b34d  83c408               add esp, 8
// 0058b350  c1eb1f               shr ebx, 0x1f
// 0058b353  03da                 add ebx, edx
// 0058b355  50                   push eax
// 0058b356  8d145b               lea edx, [ebx + ebx*2]
// 0058b359  8d04d1               lea eax, [ecx + edx*8]
// 0058b35c  57                   push edi
// 0058b35d  894d10               mov dword ptr [ebp + 0x10], ecx
// 0058b360  50                   push eax
// 0058b361  8bce                 mov ecx, esi
// 0058b363  c745fc00000000       mov dword ptr [ebp - 4], 0
// 0058b36a  e821feffff           call 0x58b190
// 0058b36f  8b460c               mov eax, dword ptr [esi + 0xc]
// 0058b372  c6451400             mov byte ptr [ebp + 0x14], 0
// 0058b376  8b5514               mov edx, dword ptr [ebp + 0x14]
// 0058b379  52                   push edx
// 0058b37a  8b5514               mov edx, dword ptr [ebp + 0x14]
// 0058b37d  52                   push edx
// 0058b37e  8b550c               mov edx, dword ptr [ebp + 0xc]
// 0058b381  8d4e08               lea ecx, [esi + 8]
// 0058b384  51                   push ecx
// 0058b385  8b4d10               mov ecx, dword ptr [ebp + 0x10]
// 0058b388  51                   push ecx
// 0058b389  52                   push edx
// 0058b38a  50                   push eax
// 0058b38b  e880fcffff           call 0x58b010
// 0058b390  8b5510               mov edx, dword ptr [ebp + 0x10]
// 0058b393  8b4610               mov eax, dword ptr [esi + 0x10]
// 0058b396  83c418               add esp, 0x18
// 0058b399  03df                 add ebx, edi
// 0058b39b  8d0c5b               lea ecx, [ebx + ebx*2]
// 0058b39e  8d0cca               lea ecx, [edx + ecx*8]
// 0058b3a1  c6451400             mov byte ptr [ebp + 0x14], 0
// 0058b3a5  8b5514               mov edx, dword ptr [ebp + 0x14]
// 0058b3a8  52                   push edx
// 0058b3a9  8b5514               mov edx, dword ptr [ebp + 0x14]
// 0058b3ac  52                   push edx
// 0058b3ad  8d5608               lea edx, [esi + 8]
// 0058b3b0  52                   push edx
// 0058b3b1  51                   push ecx
// 0058b3b2  50                   push eax
// 0058b3b3  8b450c               mov eax, dword ptr [ebp + 0xc]
// 0058b3b6  50                   push eax
// 0058b3b7  e854fcffff           call 0x58b010
// 0058b3bc  8b5e0c               mov ebx, dword ptr [esi + 0xc]
// 0058b3bf  8b4e10               mov ecx, dword ptr [esi + 0x10]
// 0058b3c2  2bcb                 sub ecx, ebx
// 0058b3c4  b8abaaaa2a           mov eax, 0x2aaaaaab
// 0058b3c9  f7e9                 imul ecx
// 0058b3cb  c1fa02               sar edx, 2
// 0058b3ce  8bca                 mov ecx, edx
// 0058b3d0  c1e91f               shr ecx, 0x1f
// 0058b3d3  03ca                 add ecx, edx
// 0058b3d5  83c418               add esp, 0x18
// 0058b3d8  03f9                 add edi, ecx
// 0058b3da  85db                 test ebx, ebx
// 0058b3dc  7409                 je 0x58b3e7
// 0058b3de  53                   push ebx
// 0058b3df  e876842600           call 0x7f385a
// 0058b3e4  83c404               add esp, 4
// 0058b3e7  8b45ec               mov eax, dword ptr [ebp - 0x14]
// 0058b3ea  8d1440               lea edx, [eax + eax*2]
// 0058b3ed  8b4510               mov eax, dword ptr [ebp + 0x10]
// 0058b3f0  8d0cd0               lea ecx, [eax + edx*8]
// 0058b3f3  8d147f               lea edx, [edi + edi*2]
// 0058b3f6  894e14               mov dword ptr [esi + 0x14], ecx
// 0058b3f9  8d0cd0               lea ecx, [eax + edx*8]
// 0058b3fc  894e10               mov dword ptr [esi + 0x10], ecx
// 0058b3ff  89460c               mov dword ptr [esi + 0xc], eax
// 0058b402  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 0058b405  64890d00000000       mov dword ptr fs:[0], ecx
// 0058b40c  5f                   pop edi
// 0058b40d  5e                   pop esi
// 0058b40e  5b                   pop ebx
// 0058b40f  8be5                 mov esp, ebp
// 0058b411  5d                   pop ebp
// 0058b412  c21000               ret 0x10
// standard library vector<pod24> (function ?_Insert_n@?$vector@UE@@V?$allocator@UE@@@std@@@std@@IAEXV?$_Vector_const_iterator@UE@@V?$allocator@UE@@@std@@@2@IABUE@@@Z)

// stl: vector<pod24>
struct E { int v[6]; };
#include <vector>
template class std::vector<E>;
