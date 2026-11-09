// from server: 100% by auto
// roc 2009-06 005de780  unit: RBX::VInstance::?$NonFactoryProduct  size: 182 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 005de780
//
// 005de780  83ec08               sub esp, 8
// 005de783  53                   push ebx
// 005de784  55                   push ebp
// 005de785  56                   push esi
// 005de786  8bf1                 mov esi, ecx
// 005de788  8b4610               mov eax, dword ptr [esi + 0x10]
// 005de78b  8b5e0c               mov ebx, dword ptr [esi + 0xc]
// 005de78e  8bc8                 mov ecx, eax
// 005de790  2bcb                 sub ecx, ebx
// 005de792  57                   push edi
// 005de793  f7c1e0ffffff         test ecx, 0xffffffe0
// 005de799  7504                 jne 0x5de79f
// 005de79b  33ff                 xor edi, edi
// 005de79d  eb27                 jmp 0x5de7c6
// 005de79f  3bd8                 cmp ebx, eax
// 005de7a1  7606                 jbe 0x5de7a9
// 005de7a3  ff15ace98900         call dword ptr [0x89e9ac]
// 005de7a9  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 005de7ad  8b06                 mov eax, dword ptr [esi]
// 005de7af  85c9                 test ecx, ecx
// 005de7b1  7404                 je 0x5de7b7
// 005de7b3  3bc8                 cmp ecx, eax
// 005de7b5  7406                 je 0x5de7bd
// 005de7b7  ff15ace98900         call dword ptr [0x89e9ac]
// 005de7bd  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 005de7c1  2bfb                 sub edi, ebx
// 005de7c3  c1ff05               sar edi, 5
// 005de7c6  8b542428             mov edx, dword ptr [esp + 0x28]
// 005de7ca  8b442424             mov eax, dword ptr [esp + 0x24]
// 005de7ce  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 005de7d2  52                   push edx
// 005de7d3  6a01                 push 1
// 005de7d5  50                   push eax
// 005de7d6  51                   push ecx
// 005de7d7  8bce                 mov ecx, esi
// 005de7d9  e882f8ffff           call 0x5de060
// 005de7de  8b5e0c               mov ebx, dword ptr [esi + 0xc]
// 005de7e1  3b5e10               cmp ebx, dword ptr [esi + 0x10]
// 005de7e4  7606                 jbe 0x5de7ec
// 005de7e6  ff15ace98900         call dword ptr [0x89e9ac]
// 005de7ec  8b36                 mov esi, dword ptr [esi]
// 005de7ee  8bee                 mov ebp, esi
// 005de7f0  895c2414             mov dword ptr [esp + 0x14], ebx
// 005de7f4  85f6                 test esi, esi
// 005de7f6  751a                 jne 0x5de812
// 005de7f8  ff15ace98900         call dword ptr [0x89e9ac]
// 005de7fe  33c0                 xor eax, eax
// 005de800  c1e705               shl edi, 5
// 005de803  03fb                 add edi, ebx
// 005de805  3b7810               cmp edi, dword ptr [eax + 0x10]
// 005de808  7713                 ja 0x5de81d
// 005de80a  85f6                 test esi, esi
// 005de80c  7408                 je 0x5de816
// 005de80e  8b36                 mov esi, dword ptr [esi]
// 005de810  eb06                 jmp 0x5de818
// 005de812  8b06                 mov eax, dword ptr [esi]
// 005de814  ebea                 jmp 0x5de800
// 005de816  33f6                 xor esi, esi
// 005de818  3b7e0c               cmp edi, dword ptr [esi + 0xc]
// 005de81b  7306                 jae 0x5de823
// 005de81d  ff15ace98900         call dword ptr [0x89e9ac]
// 005de823  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 005de827  897804               mov dword ptr [eax + 4], edi
// 005de82a  5f                   pop edi
// 005de82b  5e                   pop esi
// 005de82c  8928                 mov dword ptr [eax], ebp
// 005de82e  5d                   pop ebp
// 005de82f  5b                   pop ebx
// 005de830  83c408               add esp, 8
// 005de833  c21000               ret 0x10
// standard library vector<pod32> (function ?insert@?$vector@UE@@V?$allocator@UE@@@std@@@std@@QAE?AV?$_Vector_iterator@UE@@V?$allocator@UE@@@std@@@2@V?$_Vector_const_iterator@UE@@V?$allocator@UE@@@std@@@2@ABUE@@@Z)

// stl: vector<pod32>
struct E { int v[8]; };
#include <vector>
template class std::vector<E>;
