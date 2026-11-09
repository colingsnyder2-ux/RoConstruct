// from server: 100% by auto
// roc 2010-06 008e58b0  unit: Ogre::RbxEntity  size: 206 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008e58b0
//
// 008e58b0  83ec08               sub esp, 8
// 008e58b3  53                   push ebx
// 008e58b4  55                   push ebp
// 008e58b5  56                   push esi
// 008e58b6  8bf1                 mov esi, ecx
// 008e58b8  8b5e10               mov ebx, dword ptr [esi + 0x10]
// 008e58bb  57                   push edi
// 008e58bc  8b7e0c               mov edi, dword ptr [esi + 0xc]
// 008e58bf  8bcb                 mov ecx, ebx
// 008e58c1  2bcf                 sub ecx, edi
// 008e58c3  b8abaaaa2a           mov eax, 0x2aaaaaab
// 008e58c8  f7e9                 imul ecx
// 008e58ca  d1fa                 sar edx, 1
// 008e58cc  8bc2                 mov eax, edx
// 008e58ce  c1e81f               shr eax, 0x1f
// 008e58d1  03c2                 add eax, edx
// 008e58d3  7504                 jne 0x8e58d9
// 008e58d5  33ff                 xor edi, edi
// 008e58d7  eb34                 jmp 0x8e590d
// 008e58d9  3bfb                 cmp edi, ebx
// 008e58db  7606                 jbe 0x8e58e3
// 008e58dd  ff150ca99e00         call dword ptr [0x9ea90c]
// 008e58e3  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 008e58e7  8b06                 mov eax, dword ptr [esi]
// 008e58e9  85c9                 test ecx, ecx
// 008e58eb  7404                 je 0x8e58f1
// 008e58ed  3bc8                 cmp ecx, eax
// 008e58ef  7406                 je 0x8e58f7
// 008e58f1  ff150ca99e00         call dword ptr [0x9ea90c]
// 008e58f7  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 008e58fb  2bcf                 sub ecx, edi
// 008e58fd  b8abaaaa2a           mov eax, 0x2aaaaaab
// 008e5902  f7e9                 imul ecx
// 008e5904  d1fa                 sar edx, 1
// 008e5906  8bfa                 mov edi, edx
// 008e5908  c1ef1f               shr edi, 0x1f
// 008e590b  03fa                 add edi, edx
// 008e590d  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 008e5911  8b542424             mov edx, dword ptr [esp + 0x24]
// 008e5915  8b442420             mov eax, dword ptr [esp + 0x20]
// 008e5919  51                   push ecx
// 008e591a  6a01                 push 1
// 008e591c  52                   push edx
// 008e591d  50                   push eax
// 008e591e  8bce                 mov ecx, esi
// 008e5920  e8bbb1ffff           call 0x8e0ae0
// 008e5925  8b5e0c               mov ebx, dword ptr [esi + 0xc]
// 008e5928  3b5e10               cmp ebx, dword ptr [esi + 0x10]
// 008e592b  7606                 jbe 0x8e5933
// 008e592d  ff150ca99e00         call dword ptr [0x9ea90c]
// 008e5933  8b36                 mov esi, dword ptr [esi]
// 008e5935  8bee                 mov ebp, esi
// 008e5937  895c2414             mov dword ptr [esp + 0x14], ebx
// 008e593b  85f6                 test esi, esi
// 008e593d  751b                 jne 0x8e595a
// 008e593f  ff150ca99e00         call dword ptr [0x9ea90c]
// 008e5945  33c0                 xor eax, eax
// 008e5947  8d0c7f               lea ecx, [edi + edi*2]
// 008e594a  8d3c8b               lea edi, [ebx + ecx*4]
// 008e594d  3b7810               cmp edi, dword ptr [eax + 0x10]
// 008e5950  7713                 ja 0x8e5965
// 008e5952  85f6                 test esi, esi
// 008e5954  7408                 je 0x8e595e
// 008e5956  8b36                 mov esi, dword ptr [esi]
// 008e5958  eb06                 jmp 0x8e5960
// 008e595a  8b06                 mov eax, dword ptr [esi]
// 008e595c  ebe9                 jmp 0x8e5947
// 008e595e  33f6                 xor esi, esi
// 008e5960  3b7e0c               cmp edi, dword ptr [esi + 0xc]
// 008e5963  7306                 jae 0x8e596b
// 008e5965  ff150ca99e00         call dword ptr [0x9ea90c]
// 008e596b  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 008e596f  897804               mov dword ptr [eax + 4], edi
// 008e5972  5f                   pop edi
// 008e5973  5e                   pop esi
// 008e5974  8928                 mov dword ptr [eax], ebp
// 008e5976  5d                   pop ebp
// 008e5977  5b                   pop ebx
// 008e5978  83c408               add esp, 8
// 008e597b  c21000               ret 0x10
// standard library vector<pod12> (function ?insert@?$vector@UE@@V?$allocator@UE@@@std@@@std@@QAE?AV?$_Vector_iterator@UE@@V?$allocator@UE@@@std@@@2@V?$_Vector_const_iterator@UE@@V?$allocator@UE@@@std@@@2@ABUE@@@Z)

// stl: vector<pod12>
struct E { int v[3]; };
#include <vector>
template class std::vector<E>;
