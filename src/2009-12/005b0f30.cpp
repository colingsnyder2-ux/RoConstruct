// from server: 100% by auto
// roc 2009-12 005b0f30  unit: seg_005b0000  size: 206 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 005b0f30
//
// 005b0f30  83ec08               sub esp, 8
// 005b0f33  53                   push ebx
// 005b0f34  55                   push ebp
// 005b0f35  56                   push esi
// 005b0f36  8bf1                 mov esi, ecx
// 005b0f38  8b5e10               mov ebx, dword ptr [esi + 0x10]
// 005b0f3b  57                   push edi
// 005b0f3c  8b7e0c               mov edi, dword ptr [esi + 0xc]
// 005b0f3f  8bcb                 mov ecx, ebx
// 005b0f41  2bcf                 sub ecx, edi
// 005b0f43  b8abaaaa2a           mov eax, 0x2aaaaaab
// 005b0f48  f7e9                 imul ecx
// 005b0f4a  d1fa                 sar edx, 1
// 005b0f4c  8bc2                 mov eax, edx
// 005b0f4e  c1e81f               shr eax, 0x1f
// 005b0f51  03c2                 add eax, edx
// 005b0f53  7504                 jne 0x5b0f59
// 005b0f55  33ff                 xor edi, edi
// 005b0f57  eb34                 jmp 0x5b0f8d
// 005b0f59  3bfb                 cmp edi, ebx
// 005b0f5b  7606                 jbe 0x5b0f63
// 005b0f5d  ff1560b79800         call dword ptr [0x98b760]
// 005b0f63  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 005b0f67  8b06                 mov eax, dword ptr [esi]
// 005b0f69  85c9                 test ecx, ecx
// 005b0f6b  7404                 je 0x5b0f71
// 005b0f6d  3bc8                 cmp ecx, eax
// 005b0f6f  7406                 je 0x5b0f77
// 005b0f71  ff1560b79800         call dword ptr [0x98b760]
// 005b0f77  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 005b0f7b  2bcf                 sub ecx, edi
// 005b0f7d  b8abaaaa2a           mov eax, 0x2aaaaaab
// 005b0f82  f7e9                 imul ecx
// 005b0f84  d1fa                 sar edx, 1
// 005b0f86  8bfa                 mov edi, edx
// 005b0f88  c1ef1f               shr edi, 0x1f
// 005b0f8b  03fa                 add edi, edx
// 005b0f8d  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 005b0f91  8b542424             mov edx, dword ptr [esp + 0x24]
// 005b0f95  8b442420             mov eax, dword ptr [esp + 0x20]
// 005b0f99  51                   push ecx
// 005b0f9a  6a01                 push 1
// 005b0f9c  52                   push edx
// 005b0f9d  50                   push eax
// 005b0f9e  8bce                 mov ecx, esi
// 005b0fa0  e86bfcffff           call 0x5b0c10
// 005b0fa5  8b5e0c               mov ebx, dword ptr [esi + 0xc]
// 005b0fa8  3b5e10               cmp ebx, dword ptr [esi + 0x10]
// 005b0fab  7606                 jbe 0x5b0fb3
// 005b0fad  ff1560b79800         call dword ptr [0x98b760]
// 005b0fb3  8b36                 mov esi, dword ptr [esi]
// 005b0fb5  8bee                 mov ebp, esi
// 005b0fb7  895c2414             mov dword ptr [esp + 0x14], ebx
// 005b0fbb  85f6                 test esi, esi
// 005b0fbd  751b                 jne 0x5b0fda
// 005b0fbf  ff1560b79800         call dword ptr [0x98b760]
// 005b0fc5  33c0                 xor eax, eax
// 005b0fc7  8d0c7f               lea ecx, [edi + edi*2]
// 005b0fca  8d3c8b               lea edi, [ebx + ecx*4]
// 005b0fcd  3b7810               cmp edi, dword ptr [eax + 0x10]
// 005b0fd0  7713                 ja 0x5b0fe5
// 005b0fd2  85f6                 test esi, esi
// 005b0fd4  7408                 je 0x5b0fde
// 005b0fd6  8b36                 mov esi, dword ptr [esi]
// 005b0fd8  eb06                 jmp 0x5b0fe0
// 005b0fda  8b06                 mov eax, dword ptr [esi]
// 005b0fdc  ebe9                 jmp 0x5b0fc7
// 005b0fde  33f6                 xor esi, esi
// 005b0fe0  3b7e0c               cmp edi, dword ptr [esi + 0xc]
// 005b0fe3  7306                 jae 0x5b0feb
// 005b0fe5  ff1560b79800         call dword ptr [0x98b760]
// 005b0feb  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 005b0fef  897804               mov dword ptr [eax + 4], edi
// 005b0ff2  5f                   pop edi
// 005b0ff3  5e                   pop esi
// 005b0ff4  8928                 mov dword ptr [eax], ebp
// 005b0ff6  5d                   pop ebp
// 005b0ff7  5b                   pop ebx
// 005b0ff8  83c408               add esp, 8
// 005b0ffb  c21000               ret 0x10
// standard library vector<pod12> (function ?insert@?$vector@UE@@V?$allocator@UE@@@std@@@std@@QAE?AV?$_Vector_iterator@UE@@V?$allocator@UE@@@std@@@2@V?$_Vector_const_iterator@UE@@V?$allocator@UE@@@std@@@2@ABUE@@@Z)

// stl: vector<pod12>
struct E { int v[3]; };
#include <vector>
template class std::vector<E>;
