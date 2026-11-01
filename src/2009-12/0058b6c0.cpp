// from server: 100% by auto
// roc 2009-12 0058b6c0  unit: RBX::BeveledBlockBuilder  size: 174 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0058b6c0
//
// 0058b6c0  83ec08               sub esp, 8
// 0058b6c3  53                   push ebx
// 0058b6c4  55                   push ebp
// 0058b6c5  8b2d60b79800         mov ebp, dword ptr [0x98b760]
// 0058b6cb  56                   push esi
// 0058b6cc  8bf1                 mov esi, ecx
// 0058b6ce  8b5e10               mov ebx, dword ptr [esi + 0x10]
// 0058b6d1  57                   push edi
// 0058b6d2  8b7e0c               mov edi, dword ptr [esi + 0xc]
// 0058b6d5  8bcb                 mov ecx, ebx
// 0058b6d7  2bcf                 sub ecx, edi
// 0058b6d9  b8abaaaa2a           mov eax, 0x2aaaaaab
// 0058b6de  f7e9                 imul ecx
// 0058b6e0  c1fa02               sar edx, 2
// 0058b6e3  8bc2                 mov eax, edx
// 0058b6e5  c1e81f               shr eax, 0x1f
// 0058b6e8  03c2                 add eax, edx
// 0058b6ea  7504                 jne 0x58b6f0
// 0058b6ec  33ff                 xor edi, edi
// 0058b6ee  eb2d                 jmp 0x58b71d
// 0058b6f0  3bfb                 cmp edi, ebx
// 0058b6f2  7602                 jbe 0x58b6f6
// 0058b6f4  ffd5                 call ebp
// 0058b6f6  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 0058b6fa  8b06                 mov eax, dword ptr [esi]
// 0058b6fc  85c9                 test ecx, ecx
// 0058b6fe  7404                 je 0x58b704
// 0058b700  3bc8                 cmp ecx, eax
// 0058b702  7402                 je 0x58b706
// 0058b704  ffd5                 call ebp
// 0058b706  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 0058b70a  2bcf                 sub ecx, edi
// 0058b70c  b8abaaaa2a           mov eax, 0x2aaaaaab
// 0058b711  f7e9                 imul ecx
// 0058b713  c1fa02               sar edx, 2
// 0058b716  8bfa                 mov edi, edx
// 0058b718  c1ef1f               shr edi, 0x1f
// 0058b71b  03fa                 add edi, edx
// 0058b71d  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 0058b721  8b542424             mov edx, dword ptr [esp + 0x24]
// 0058b725  8b442420             mov eax, dword ptr [esp + 0x20]
// 0058b729  51                   push ecx
// 0058b72a  6a01                 push 1
// 0058b72c  52                   push edx
// 0058b72d  50                   push eax
// 0058b72e  8bce                 mov ecx, esi
// 0058b730  e84bfbffff           call 0x58b280
// 0058b735  8b5e0c               mov ebx, dword ptr [esi + 0xc]
// 0058b738  3b5e10               cmp ebx, dword ptr [esi + 0x10]
// 0058b73b  7602                 jbe 0x58b73f
// 0058b73d  ffd5                 call ebp
// 0058b73f  8b36                 mov esi, dword ptr [esi]
// 0058b741  57                   push edi
// 0058b742  8d4c2414             lea ecx, [esp + 0x14]
// 0058b746  89742414             mov dword ptr [esp + 0x14], esi
// 0058b74a  895c2418             mov dword ptr [esp + 0x18], ebx
// 0058b74e  e8cdc62000           call 0x797e20
// 0058b753  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0058b757  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0058b75b  8b542414             mov edx, dword ptr [esp + 0x14]
// 0058b75f  5f                   pop edi
// 0058b760  5e                   pop esi
// 0058b761  5d                   pop ebp
// 0058b762  8908                 mov dword ptr [eax], ecx
// 0058b764  895004               mov dword ptr [eax + 4], edx
// 0058b767  5b                   pop ebx
// 0058b768  83c408               add esp, 8
// 0058b76b  c21000               ret 0x10
// standard library vector<pod24> (function ?insert@?$vector@UE@@V?$allocator@UE@@@std@@@std@@QAE?AV?$_Vector_iterator@UE@@V?$allocator@UE@@@std@@@2@V?$_Vector_const_iterator@UE@@V?$allocator@UE@@@std@@@2@ABUE@@@Z)

// stl: vector<pod24>
struct E { int v[6]; };
#include <vector>
template class std::vector<E>;
