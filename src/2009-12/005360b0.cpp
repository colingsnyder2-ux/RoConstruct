// from server: 100% by auto
// roc 2009-12 005360b0  unit: RBX::Network::IdSerializer  size: 206 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 005360b0
//
// 005360b0  83ec08               sub esp, 8
// 005360b3  53                   push ebx
// 005360b4  55                   push ebp
// 005360b5  56                   push esi
// 005360b6  8bf1                 mov esi, ecx
// 005360b8  8b5e10               mov ebx, dword ptr [esi + 0x10]
// 005360bb  57                   push edi
// 005360bc  8b7e0c               mov edi, dword ptr [esi + 0xc]
// 005360bf  8bcb                 mov ecx, ebx
// 005360c1  2bcf                 sub ecx, edi
// 005360c3  b8abaaaa2a           mov eax, 0x2aaaaaab
// 005360c8  f7e9                 imul ecx
// 005360ca  d1fa                 sar edx, 1
// 005360cc  8bc2                 mov eax, edx
// 005360ce  c1e81f               shr eax, 0x1f
// 005360d1  03c2                 add eax, edx
// 005360d3  7504                 jne 0x5360d9
// 005360d5  33ff                 xor edi, edi
// 005360d7  eb34                 jmp 0x53610d
// 005360d9  3bfb                 cmp edi, ebx
// 005360db  7606                 jbe 0x5360e3
// 005360dd  ff1560b79800         call dword ptr [0x98b760]
// 005360e3  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 005360e7  8b06                 mov eax, dword ptr [esi]
// 005360e9  85c9                 test ecx, ecx
// 005360eb  7404                 je 0x5360f1
// 005360ed  3bc8                 cmp ecx, eax
// 005360ef  7406                 je 0x5360f7
// 005360f1  ff1560b79800         call dword ptr [0x98b760]
// 005360f7  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 005360fb  2bcf                 sub ecx, edi
// 005360fd  b8abaaaa2a           mov eax, 0x2aaaaaab
// 00536102  f7e9                 imul ecx
// 00536104  d1fa                 sar edx, 1
// 00536106  8bfa                 mov edi, edx
// 00536108  c1ef1f               shr edi, 0x1f
// 0053610b  03fa                 add edi, edx
// 0053610d  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 00536111  8b542424             mov edx, dword ptr [esp + 0x24]
// 00536115  8b442420             mov eax, dword ptr [esp + 0x20]
// 00536119  51                   push ecx
// 0053611a  6a01                 push 1
// 0053611c  52                   push edx
// 0053611d  50                   push eax
// 0053611e  8bce                 mov ecx, esi
// 00536120  e85bf8ffff           call 0x535980
// 00536125  8b5e0c               mov ebx, dword ptr [esi + 0xc]
// 00536128  3b5e10               cmp ebx, dword ptr [esi + 0x10]
// 0053612b  7606                 jbe 0x536133
// 0053612d  ff1560b79800         call dword ptr [0x98b760]
// 00536133  8b36                 mov esi, dword ptr [esi]
// 00536135  8bee                 mov ebp, esi
// 00536137  895c2414             mov dword ptr [esp + 0x14], ebx
// 0053613b  85f6                 test esi, esi
// 0053613d  751b                 jne 0x53615a
// 0053613f  ff1560b79800         call dword ptr [0x98b760]
// 00536145  33c0                 xor eax, eax
// 00536147  8d0c7f               lea ecx, [edi + edi*2]
// 0053614a  8d3c8b               lea edi, [ebx + ecx*4]
// 0053614d  3b7810               cmp edi, dword ptr [eax + 0x10]
// 00536150  7713                 ja 0x536165
// 00536152  85f6                 test esi, esi
// 00536154  7408                 je 0x53615e
// 00536156  8b36                 mov esi, dword ptr [esi]
// 00536158  eb06                 jmp 0x536160
// 0053615a  8b06                 mov eax, dword ptr [esi]
// 0053615c  ebe9                 jmp 0x536147
// 0053615e  33f6                 xor esi, esi
// 00536160  3b7e0c               cmp edi, dword ptr [esi + 0xc]
// 00536163  7306                 jae 0x53616b
// 00536165  ff1560b79800         call dword ptr [0x98b760]
// 0053616b  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0053616f  897804               mov dword ptr [eax + 4], edi
// 00536172  5f                   pop edi
// 00536173  5e                   pop esi
// 00536174  8928                 mov dword ptr [eax], ebp
// 00536176  5d                   pop ebp
// 00536177  5b                   pop ebx
// 00536178  83c408               add esp, 8
// 0053617b  c21000               ret 0x10
// standard library vector<pod12> (function ?insert@?$vector@UE@@V?$allocator@UE@@@std@@@std@@QAE?AV?$_Vector_iterator@UE@@V?$allocator@UE@@@std@@@2@V?$_Vector_const_iterator@UE@@V?$allocator@UE@@@std@@@2@ABUE@@@Z)

// stl: vector<pod12>
struct E { int v[3]; };
#include <vector>
template class std::vector<E>;
