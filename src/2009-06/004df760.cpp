// from server: 100% by auto
// roc 2009-06 004df760  unit: RBX::Network::IdSerializer  size: 206 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004df760
//
// 004df760  83ec08               sub esp, 8
// 004df763  53                   push ebx
// 004df764  55                   push ebp
// 004df765  56                   push esi
// 004df766  8bf1                 mov esi, ecx
// 004df768  8b5e10               mov ebx, dword ptr [esi + 0x10]
// 004df76b  57                   push edi
// 004df76c  8b7e0c               mov edi, dword ptr [esi + 0xc]
// 004df76f  8bcb                 mov ecx, ebx
// 004df771  2bcf                 sub ecx, edi
// 004df773  b8abaaaa2a           mov eax, 0x2aaaaaab
// 004df778  f7e9                 imul ecx
// 004df77a  d1fa                 sar edx, 1
// 004df77c  8bc2                 mov eax, edx
// 004df77e  c1e81f               shr eax, 0x1f
// 004df781  03c2                 add eax, edx
// 004df783  7504                 jne 0x4df789
// 004df785  33ff                 xor edi, edi
// 004df787  eb34                 jmp 0x4df7bd
// 004df789  3bfb                 cmp edi, ebx
// 004df78b  7606                 jbe 0x4df793
// 004df78d  ff15ace98900         call dword ptr [0x89e9ac]
// 004df793  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 004df797  8b06                 mov eax, dword ptr [esi]
// 004df799  85c9                 test ecx, ecx
// 004df79b  7404                 je 0x4df7a1
// 004df79d  3bc8                 cmp ecx, eax
// 004df79f  7406                 je 0x4df7a7
// 004df7a1  ff15ace98900         call dword ptr [0x89e9ac]
// 004df7a7  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 004df7ab  2bcf                 sub ecx, edi
// 004df7ad  b8abaaaa2a           mov eax, 0x2aaaaaab
// 004df7b2  f7e9                 imul ecx
// 004df7b4  d1fa                 sar edx, 1
// 004df7b6  8bfa                 mov edi, edx
// 004df7b8  c1ef1f               shr edi, 0x1f
// 004df7bb  03fa                 add edi, edx
// 004df7bd  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 004df7c1  8b542424             mov edx, dword ptr [esp + 0x24]
// 004df7c5  8b442420             mov eax, dword ptr [esp + 0x20]
// 004df7c9  51                   push ecx
// 004df7ca  6a01                 push 1
// 004df7cc  52                   push edx
// 004df7cd  50                   push eax
// 004df7ce  8bce                 mov ecx, esi
// 004df7d0  e85bf9ffff           call 0x4df130
// 004df7d5  8b5e0c               mov ebx, dword ptr [esi + 0xc]
// 004df7d8  3b5e10               cmp ebx, dword ptr [esi + 0x10]
// 004df7db  7606                 jbe 0x4df7e3
// 004df7dd  ff15ace98900         call dword ptr [0x89e9ac]
// 004df7e3  8b36                 mov esi, dword ptr [esi]
// 004df7e5  8bee                 mov ebp, esi
// 004df7e7  895c2414             mov dword ptr [esp + 0x14], ebx
// 004df7eb  85f6                 test esi, esi
// 004df7ed  751b                 jne 0x4df80a
// 004df7ef  ff15ace98900         call dword ptr [0x89e9ac]
// 004df7f5  33c0                 xor eax, eax
// 004df7f7  8d0c7f               lea ecx, [edi + edi*2]
// 004df7fa  8d3c8b               lea edi, [ebx + ecx*4]
// 004df7fd  3b7810               cmp edi, dword ptr [eax + 0x10]
// 004df800  7713                 ja 0x4df815
// 004df802  85f6                 test esi, esi
// 004df804  7408                 je 0x4df80e
// 004df806  8b36                 mov esi, dword ptr [esi]
// 004df808  eb06                 jmp 0x4df810
// 004df80a  8b06                 mov eax, dword ptr [esi]
// 004df80c  ebe9                 jmp 0x4df7f7
// 004df80e  33f6                 xor esi, esi
// 004df810  3b7e0c               cmp edi, dword ptr [esi + 0xc]
// 004df813  7306                 jae 0x4df81b
// 004df815  ff15ace98900         call dword ptr [0x89e9ac]
// 004df81b  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 004df81f  897804               mov dword ptr [eax + 4], edi
// 004df822  5f                   pop edi
// 004df823  5e                   pop esi
// 004df824  8928                 mov dword ptr [eax], ebp
// 004df826  5d                   pop ebp
// 004df827  5b                   pop ebx
// 004df828  83c408               add esp, 8
// 004df82b  c21000               ret 0x10
// standard library vector<pod12> (function ?insert@?$vector@UE@@V?$allocator@UE@@@std@@@std@@QAE?AV?$_Vector_iterator@UE@@V?$allocator@UE@@@std@@@2@V?$_Vector_const_iterator@UE@@V?$allocator@UE@@@std@@@2@ABUE@@@Z)

// stl: vector<pod12>
struct E { int v[3]; };
#include <vector>
template class std::vector<E>;
