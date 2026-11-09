// from server: 100% by auto
// roc 2009-06 0083a8e0  unit: Ogre::RbxEntity  size: 206 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0083a8e0
//
// 0083a8e0  83ec08               sub esp, 8
// 0083a8e3  53                   push ebx
// 0083a8e4  55                   push ebp
// 0083a8e5  56                   push esi
// 0083a8e6  8bf1                 mov esi, ecx
// 0083a8e8  8b5e10               mov ebx, dword ptr [esi + 0x10]
// 0083a8eb  57                   push edi
// 0083a8ec  8b7e0c               mov edi, dword ptr [esi + 0xc]
// 0083a8ef  8bcb                 mov ecx, ebx
// 0083a8f1  2bcf                 sub ecx, edi
// 0083a8f3  b8abaaaa2a           mov eax, 0x2aaaaaab
// 0083a8f8  f7e9                 imul ecx
// 0083a8fa  d1fa                 sar edx, 1
// 0083a8fc  8bc2                 mov eax, edx
// 0083a8fe  c1e81f               shr eax, 0x1f
// 0083a901  03c2                 add eax, edx
// 0083a903  7504                 jne 0x83a909
// 0083a905  33ff                 xor edi, edi
// 0083a907  eb34                 jmp 0x83a93d
// 0083a909  3bfb                 cmp edi, ebx
// 0083a90b  7606                 jbe 0x83a913
// 0083a90d  ff15ace98900         call dword ptr [0x89e9ac]
// 0083a913  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 0083a917  8b06                 mov eax, dword ptr [esi]
// 0083a919  85c9                 test ecx, ecx
// 0083a91b  7404                 je 0x83a921
// 0083a91d  3bc8                 cmp ecx, eax
// 0083a91f  7406                 je 0x83a927
// 0083a921  ff15ace98900         call dword ptr [0x89e9ac]
// 0083a927  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 0083a92b  2bcf                 sub ecx, edi
// 0083a92d  b8abaaaa2a           mov eax, 0x2aaaaaab
// 0083a932  f7e9                 imul ecx
// 0083a934  d1fa                 sar edx, 1
// 0083a936  8bfa                 mov edi, edx
// 0083a938  c1ef1f               shr edi, 0x1f
// 0083a93b  03fa                 add edi, edx
// 0083a93d  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 0083a941  8b542424             mov edx, dword ptr [esp + 0x24]
// 0083a945  8b442420             mov eax, dword ptr [esp + 0x20]
// 0083a949  51                   push ecx
// 0083a94a  6a01                 push 1
// 0083a94c  52                   push edx
// 0083a94d  50                   push eax
// 0083a94e  8bce                 mov ecx, esi
// 0083a950  e88b10c4ff           call 0x47b9e0
// 0083a955  8b5e0c               mov ebx, dword ptr [esi + 0xc]
// 0083a958  3b5e10               cmp ebx, dword ptr [esi + 0x10]
// 0083a95b  7606                 jbe 0x83a963
// 0083a95d  ff15ace98900         call dword ptr [0x89e9ac]
// 0083a963  8b36                 mov esi, dword ptr [esi]
// 0083a965  8bee                 mov ebp, esi
// 0083a967  895c2414             mov dword ptr [esp + 0x14], ebx
// 0083a96b  85f6                 test esi, esi
// 0083a96d  751b                 jne 0x83a98a
// 0083a96f  ff15ace98900         call dword ptr [0x89e9ac]
// 0083a975  33c0                 xor eax, eax
// 0083a977  8d0c7f               lea ecx, [edi + edi*2]
// 0083a97a  8d3c8b               lea edi, [ebx + ecx*4]
// 0083a97d  3b7810               cmp edi, dword ptr [eax + 0x10]
// 0083a980  7713                 ja 0x83a995
// 0083a982  85f6                 test esi, esi
// 0083a984  7408                 je 0x83a98e
// 0083a986  8b36                 mov esi, dword ptr [esi]
// 0083a988  eb06                 jmp 0x83a990
// 0083a98a  8b06                 mov eax, dword ptr [esi]
// 0083a98c  ebe9                 jmp 0x83a977
// 0083a98e  33f6                 xor esi, esi
// 0083a990  3b7e0c               cmp edi, dword ptr [esi + 0xc]
// 0083a993  7306                 jae 0x83a99b
// 0083a995  ff15ace98900         call dword ptr [0x89e9ac]
// 0083a99b  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0083a99f  897804               mov dword ptr [eax + 4], edi
// 0083a9a2  5f                   pop edi
// 0083a9a3  5e                   pop esi
// 0083a9a4  8928                 mov dword ptr [eax], ebp
// 0083a9a6  5d                   pop ebp
// 0083a9a7  5b                   pop ebx
// 0083a9a8  83c408               add esp, 8
// 0083a9ab  c21000               ret 0x10
// standard library vector<pod12> (function ?insert@?$vector@UE@@V?$allocator@UE@@@std@@@std@@QAE?AV?$_Vector_iterator@UE@@V?$allocator@UE@@@std@@@2@V?$_Vector_const_iterator@UE@@V?$allocator@UE@@@std@@@2@ABUE@@@Z)

// stl: vector<pod12>
struct E { int v[3]; };
#include <vector>
template class std::vector<E>;
