// from server: 100% by auto
// roc 2009-06 00532c50  unit: RBX::BeveledBlockBuilder  size: 174 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00532c50
//
// 00532c50  83ec08               sub esp, 8
// 00532c53  53                   push ebx
// 00532c54  55                   push ebp
// 00532c55  8b2dace98900         mov ebp, dword ptr [0x89e9ac]
// 00532c5b  56                   push esi
// 00532c5c  8bf1                 mov esi, ecx
// 00532c5e  8b5e10               mov ebx, dword ptr [esi + 0x10]
// 00532c61  57                   push edi
// 00532c62  8b7e0c               mov edi, dword ptr [esi + 0xc]
// 00532c65  8bcb                 mov ecx, ebx
// 00532c67  2bcf                 sub ecx, edi
// 00532c69  b8abaaaa2a           mov eax, 0x2aaaaaab
// 00532c6e  f7e9                 imul ecx
// 00532c70  c1fa02               sar edx, 2
// 00532c73  8bc2                 mov eax, edx
// 00532c75  c1e81f               shr eax, 0x1f
// 00532c78  03c2                 add eax, edx
// 00532c7a  7504                 jne 0x532c80
// 00532c7c  33ff                 xor edi, edi
// 00532c7e  eb2d                 jmp 0x532cad
// 00532c80  3bfb                 cmp edi, ebx
// 00532c82  7602                 jbe 0x532c86
// 00532c84  ffd5                 call ebp
// 00532c86  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 00532c8a  8b06                 mov eax, dword ptr [esi]
// 00532c8c  85c9                 test ecx, ecx
// 00532c8e  7404                 je 0x532c94
// 00532c90  3bc8                 cmp ecx, eax
// 00532c92  7402                 je 0x532c96
// 00532c94  ffd5                 call ebp
// 00532c96  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 00532c9a  2bcf                 sub ecx, edi
// 00532c9c  b8abaaaa2a           mov eax, 0x2aaaaaab
// 00532ca1  f7e9                 imul ecx
// 00532ca3  c1fa02               sar edx, 2
// 00532ca6  8bfa                 mov edi, edx
// 00532ca8  c1ef1f               shr edi, 0x1f
// 00532cab  03fa                 add edi, edx
// 00532cad  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 00532cb1  8b542424             mov edx, dword ptr [esp + 0x24]
// 00532cb5  8b442420             mov eax, dword ptr [esp + 0x20]
// 00532cb9  51                   push ecx
// 00532cba  6a01                 push 1
// 00532cbc  52                   push edx
// 00532cbd  50                   push eax
// 00532cbe  8bce                 mov ecx, esi
// 00532cc0  e88bfbffff           call 0x532850
// 00532cc5  8b5e0c               mov ebx, dword ptr [esi + 0xc]
// 00532cc8  3b5e10               cmp ebx, dword ptr [esi + 0x10]
// 00532ccb  7602                 jbe 0x532ccf
// 00532ccd  ffd5                 call ebp
// 00532ccf  8b36                 mov esi, dword ptr [esi]
// 00532cd1  57                   push edi
// 00532cd2  8d4c2414             lea ecx, [esp + 0x14]
// 00532cd6  89742414             mov dword ptr [esp + 0x14], esi
// 00532cda  895c2418             mov dword ptr [esp + 0x18], ebx
// 00532cde  e8bded1800           call 0x6c1aa0
// 00532ce3  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00532ce7  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00532ceb  8b542414             mov edx, dword ptr [esp + 0x14]
// 00532cef  5f                   pop edi
// 00532cf0  5e                   pop esi
// 00532cf1  5d                   pop ebp
// 00532cf2  8908                 mov dword ptr [eax], ecx
// 00532cf4  895004               mov dword ptr [eax + 4], edx
// 00532cf7  5b                   pop ebx
// 00532cf8  83c408               add esp, 8
// 00532cfb  c21000               ret 0x10
// standard library vector<pod24> (function ?insert@?$vector@UE@@V?$allocator@UE@@@std@@@std@@QAE?AV?$_Vector_iterator@UE@@V?$allocator@UE@@@std@@@2@V?$_Vector_const_iterator@UE@@V?$allocator@UE@@@std@@@2@ABUE@@@Z)

// stl: vector<pod24>
struct E { int v[6]; };
#include <vector>
template class std::vector<E>;
