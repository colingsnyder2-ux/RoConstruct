// from server: 100% by auto
// roc 2009-12 005b1c60  unit: RBX::BrickBuilder  size: 206 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 005b1c60
//
// 005b1c60  83ec08               sub esp, 8
// 005b1c63  53                   push ebx
// 005b1c64  55                   push ebp
// 005b1c65  56                   push esi
// 005b1c66  8bf1                 mov esi, ecx
// 005b1c68  8b5e10               mov ebx, dword ptr [esi + 0x10]
// 005b1c6b  57                   push edi
// 005b1c6c  8b7e0c               mov edi, dword ptr [esi + 0xc]
// 005b1c6f  8bcb                 mov ecx, ebx
// 005b1c71  2bcf                 sub ecx, edi
// 005b1c73  b8abaaaa2a           mov eax, 0x2aaaaaab
// 005b1c78  f7e9                 imul ecx
// 005b1c7a  d1fa                 sar edx, 1
// 005b1c7c  8bc2                 mov eax, edx
// 005b1c7e  c1e81f               shr eax, 0x1f
// 005b1c81  03c2                 add eax, edx
// 005b1c83  7504                 jne 0x5b1c89
// 005b1c85  33ff                 xor edi, edi
// 005b1c87  eb34                 jmp 0x5b1cbd
// 005b1c89  3bfb                 cmp edi, ebx
// 005b1c8b  7606                 jbe 0x5b1c93
// 005b1c8d  ff1560b79800         call dword ptr [0x98b760]
// 005b1c93  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 005b1c97  8b06                 mov eax, dword ptr [esi]
// 005b1c99  85c9                 test ecx, ecx
// 005b1c9b  7404                 je 0x5b1ca1
// 005b1c9d  3bc8                 cmp ecx, eax
// 005b1c9f  7406                 je 0x5b1ca7
// 005b1ca1  ff1560b79800         call dword ptr [0x98b760]
// 005b1ca7  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 005b1cab  2bcf                 sub ecx, edi
// 005b1cad  b8abaaaa2a           mov eax, 0x2aaaaaab
// 005b1cb2  f7e9                 imul ecx
// 005b1cb4  d1fa                 sar edx, 1
// 005b1cb6  8bfa                 mov edi, edx
// 005b1cb8  c1ef1f               shr edi, 0x1f
// 005b1cbb  03fa                 add edi, edx
// 005b1cbd  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 005b1cc1  8b542424             mov edx, dword ptr [esp + 0x24]
// 005b1cc5  8b442420             mov eax, dword ptr [esp + 0x20]
// 005b1cc9  51                   push ecx
// 005b1cca  6a01                 push 1
// 005b1ccc  52                   push edx
// 005b1ccd  50                   push eax
// 005b1cce  8bce                 mov ecx, esi
// 005b1cd0  e84bfcffff           call 0x5b1920
// 005b1cd5  8b5e0c               mov ebx, dword ptr [esi + 0xc]
// 005b1cd8  3b5e10               cmp ebx, dword ptr [esi + 0x10]
// 005b1cdb  7606                 jbe 0x5b1ce3
// 005b1cdd  ff1560b79800         call dword ptr [0x98b760]
// 005b1ce3  8b36                 mov esi, dword ptr [esi]
// 005b1ce5  8bee                 mov ebp, esi
// 005b1ce7  895c2414             mov dword ptr [esp + 0x14], ebx
// 005b1ceb  85f6                 test esi, esi
// 005b1ced  751b                 jne 0x5b1d0a
// 005b1cef  ff1560b79800         call dword ptr [0x98b760]
// 005b1cf5  33c0                 xor eax, eax
// 005b1cf7  8d0c7f               lea ecx, [edi + edi*2]
// 005b1cfa  8d3c8b               lea edi, [ebx + ecx*4]
// 005b1cfd  3b7810               cmp edi, dword ptr [eax + 0x10]
// 005b1d00  7713                 ja 0x5b1d15
// 005b1d02  85f6                 test esi, esi
// 005b1d04  7408                 je 0x5b1d0e
// 005b1d06  8b36                 mov esi, dword ptr [esi]
// 005b1d08  eb06                 jmp 0x5b1d10
// 005b1d0a  8b06                 mov eax, dword ptr [esi]
// 005b1d0c  ebe9                 jmp 0x5b1cf7
// 005b1d0e  33f6                 xor esi, esi
// 005b1d10  3b7e0c               cmp edi, dword ptr [esi + 0xc]
// 005b1d13  7306                 jae 0x5b1d1b
// 005b1d15  ff1560b79800         call dword ptr [0x98b760]
// 005b1d1b  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 005b1d1f  897804               mov dword ptr [eax + 4], edi
// 005b1d22  5f                   pop edi
// 005b1d23  5e                   pop esi
// 005b1d24  8928                 mov dword ptr [eax], ebp
// 005b1d26  5d                   pop ebp
// 005b1d27  5b                   pop ebx
// 005b1d28  83c408               add esp, 8
// 005b1d2b  c21000               ret 0x10
// standard library vector<pod12> (function ?insert@?$vector@UE@@V?$allocator@UE@@@std@@@std@@QAE?AV?$_Vector_iterator@UE@@V?$allocator@UE@@@std@@@2@V?$_Vector_const_iterator@UE@@V?$allocator@UE@@@std@@@2@ABUE@@@Z)

// stl: vector<pod12>
struct E { int v[3]; };
#include <vector>
template class std::vector<E>;
