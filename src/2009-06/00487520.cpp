// from server: 100% by auto
// roc 2009-06 00487520  unit: Ogre::RbxMeshPartAdapter  size: 182 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00487520
//
// 00487520  83ec08               sub esp, 8
// 00487523  53                   push ebx
// 00487524  55                   push ebp
// 00487525  56                   push esi
// 00487526  8bf1                 mov esi, ecx
// 00487528  8b4610               mov eax, dword ptr [esi + 0x10]
// 0048752b  8b5e0c               mov ebx, dword ptr [esi + 0xc]
// 0048752e  8bc8                 mov ecx, eax
// 00487530  2bcb                 sub ecx, ebx
// 00487532  57                   push edi
// 00487533  f7c1f0ffffff         test ecx, 0xfffffff0
// 00487539  7504                 jne 0x48753f
// 0048753b  33ff                 xor edi, edi
// 0048753d  eb27                 jmp 0x487566
// 0048753f  3bd8                 cmp ebx, eax
// 00487541  7606                 jbe 0x487549
// 00487543  ff15ace98900         call dword ptr [0x89e9ac]
// 00487549  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 0048754d  8b06                 mov eax, dword ptr [esi]
// 0048754f  85c9                 test ecx, ecx
// 00487551  7404                 je 0x487557
// 00487553  3bc8                 cmp ecx, eax
// 00487555  7406                 je 0x48755d
// 00487557  ff15ace98900         call dword ptr [0x89e9ac]
// 0048755d  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 00487561  2bfb                 sub edi, ebx
// 00487563  c1ff04               sar edi, 4
// 00487566  8b542428             mov edx, dword ptr [esp + 0x28]
// 0048756a  8b442424             mov eax, dword ptr [esp + 0x24]
// 0048756e  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 00487572  52                   push edx
// 00487573  6a01                 push 1
// 00487575  50                   push eax
// 00487576  51                   push ecx
// 00487577  8bce                 mov ecx, esi
// 00487579  e802f8ffff           call 0x486d80
// 0048757e  8b5e0c               mov ebx, dword ptr [esi + 0xc]
// 00487581  3b5e10               cmp ebx, dword ptr [esi + 0x10]
// 00487584  7606                 jbe 0x48758c
// 00487586  ff15ace98900         call dword ptr [0x89e9ac]
// 0048758c  8b36                 mov esi, dword ptr [esi]
// 0048758e  8bee                 mov ebp, esi
// 00487590  895c2414             mov dword ptr [esp + 0x14], ebx
// 00487594  85f6                 test esi, esi
// 00487596  751a                 jne 0x4875b2
// 00487598  ff15ace98900         call dword ptr [0x89e9ac]
// 0048759e  33c0                 xor eax, eax
// 004875a0  c1e704               shl edi, 4
// 004875a3  03fb                 add edi, ebx
// 004875a5  3b7810               cmp edi, dword ptr [eax + 0x10]
// 004875a8  7713                 ja 0x4875bd
// 004875aa  85f6                 test esi, esi
// 004875ac  7408                 je 0x4875b6
// 004875ae  8b36                 mov esi, dword ptr [esi]
// 004875b0  eb06                 jmp 0x4875b8
// 004875b2  8b06                 mov eax, dword ptr [esi]
// 004875b4  ebea                 jmp 0x4875a0
// 004875b6  33f6                 xor esi, esi
// 004875b8  3b7e0c               cmp edi, dword ptr [esi + 0xc]
// 004875bb  7306                 jae 0x4875c3
// 004875bd  ff15ace98900         call dword ptr [0x89e9ac]
// 004875c3  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 004875c7  897804               mov dword ptr [eax + 4], edi
// 004875ca  5f                   pop edi
// 004875cb  5e                   pop esi
// 004875cc  8928                 mov dword ptr [eax], ebp
// 004875ce  5d                   pop ebp
// 004875cf  5b                   pop ebx
// 004875d0  83c408               add esp, 8
// 004875d3  c21000               ret 0x10
// standard library vector<pod16> (function ?insert@?$vector@UE@@V?$allocator@UE@@@std@@@std@@QAE?AV?$_Vector_iterator@UE@@V?$allocator@UE@@@std@@@2@V?$_Vector_const_iterator@UE@@V?$allocator@UE@@@std@@@2@ABUE@@@Z)

// stl: vector<pod16>
struct E { int v[4]; };
#include <vector>
template class std::vector<E>;
