// from server: 100% by auto
// roc 2009-12 004a73a0  unit: Ogre::UTVertexPositionNormalStudsTex::?$SpecializedMeshGen  size: 211 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 004a73a0
//
// 004a73a0  83ec08               sub esp, 8
// 004a73a3  53                   push ebx
// 004a73a4  55                   push ebp
// 004a73a5  56                   push esi
// 004a73a6  8bf1                 mov esi, ecx
// 004a73a8  8b5e10               mov ebx, dword ptr [esi + 0x10]
// 004a73ab  57                   push edi
// 004a73ac  8b7e0c               mov edi, dword ptr [esi + 0xc]
// 004a73af  8bcb                 mov ecx, ebx
// 004a73b1  2bcf                 sub ecx, edi
// 004a73b3  b8abaaaa2a           mov eax, 0x2aaaaaab
// 004a73b8  f7e9                 imul ecx
// 004a73ba  c1fa03               sar edx, 3
// 004a73bd  8bc2                 mov eax, edx
// 004a73bf  c1e81f               shr eax, 0x1f
// 004a73c2  03c2                 add eax, edx
// 004a73c4  7504                 jne 0x4a73ca
// 004a73c6  33ff                 xor edi, edi
// 004a73c8  eb35                 jmp 0x4a73ff
// 004a73ca  3bfb                 cmp edi, ebx
// 004a73cc  7606                 jbe 0x4a73d4
// 004a73ce  ff1560b79800         call dword ptr [0x98b760]
// 004a73d4  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 004a73d8  8b06                 mov eax, dword ptr [esi]
// 004a73da  85c9                 test ecx, ecx
// 004a73dc  7404                 je 0x4a73e2
// 004a73de  3bc8                 cmp ecx, eax
// 004a73e0  7406                 je 0x4a73e8
// 004a73e2  ff1560b79800         call dword ptr [0x98b760]
// 004a73e8  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 004a73ec  2bcf                 sub ecx, edi
// 004a73ee  b8abaaaa2a           mov eax, 0x2aaaaaab
// 004a73f3  f7e9                 imul ecx
// 004a73f5  c1fa03               sar edx, 3
// 004a73f8  8bfa                 mov edi, edx
// 004a73fa  c1ef1f               shr edi, 0x1f
// 004a73fd  03fa                 add edi, edx
// 004a73ff  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 004a7403  8b542424             mov edx, dword ptr [esp + 0x24]
// 004a7407  8b442420             mov eax, dword ptr [esp + 0x20]
// 004a740b  51                   push ecx
// 004a740c  6a01                 push 1
// 004a740e  52                   push edx
// 004a740f  50                   push eax
// 004a7410  8bce                 mov ecx, esi
// 004a7412  e8d9cdffff           call 0x4a41f0
// 004a7417  8b5e0c               mov ebx, dword ptr [esi + 0xc]
// 004a741a  3b5e10               cmp ebx, dword ptr [esi + 0x10]
// 004a741d  7606                 jbe 0x4a7425
// 004a741f  ff1560b79800         call dword ptr [0x98b760]
// 004a7425  8b36                 mov esi, dword ptr [esi]
// 004a7427  8bee                 mov ebp, esi
// 004a7429  895c2414             mov dword ptr [esp + 0x14], ebx
// 004a742d  85f6                 test esi, esi
// 004a742f  751e                 jne 0x4a744f
// 004a7431  ff1560b79800         call dword ptr [0x98b760]
// 004a7437  33c0                 xor eax, eax
// 004a7439  8d0c7f               lea ecx, [edi + edi*2]
// 004a743c  c1e104               shl ecx, 4
// 004a743f  8d3c19               lea edi, [ecx + ebx]
// 004a7442  3b7810               cmp edi, dword ptr [eax + 0x10]
// 004a7445  7713                 ja 0x4a745a
// 004a7447  85f6                 test esi, esi
// 004a7449  7408                 je 0x4a7453
// 004a744b  8b36                 mov esi, dword ptr [esi]
// 004a744d  eb06                 jmp 0x4a7455
// 004a744f  8b06                 mov eax, dword ptr [esi]
// 004a7451  ebe6                 jmp 0x4a7439
// 004a7453  33f6                 xor esi, esi
// 004a7455  3b7e0c               cmp edi, dword ptr [esi + 0xc]
// 004a7458  7306                 jae 0x4a7460
// 004a745a  ff1560b79800         call dword ptr [0x98b760]
// 004a7460  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 004a7464  897804               mov dword ptr [eax + 4], edi
// 004a7467  5f                   pop edi
// 004a7468  5e                   pop esi
// 004a7469  8928                 mov dword ptr [eax], ebp
// 004a746b  5d                   pop ebp
// 004a746c  5b                   pop ebx
// 004a746d  83c408               add esp, 8
// 004a7470  c21000               ret 0x10
// standard library vector<pod48> (function ?insert@?$vector@UE@@V?$allocator@UE@@@std@@@std@@QAE?AV?$_Vector_iterator@UE@@V?$allocator@UE@@@std@@@2@V?$_Vector_const_iterator@UE@@V?$allocator@UE@@@std@@@2@ABUE@@@Z)

// stl: vector<pod48>
struct E { int v[12]; };
#include <vector>
template class std::vector<E>;
