// from server: 100% by auto
// roc 2007-08 0044c830  unit: CRobloxControlColorSelector  size: 159 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0044c830
//
// 0044c830  83ec08               sub esp, 8
// 0044c833  56                   push esi
// 0044c834  8bf1                 mov esi, ecx
// 0044c836  57                   push edi
// 0044c837  8b7e04               mov edi, dword ptr [esi + 4]
// 0044c83a  85ff                 test edi, edi
// 0044c83c  7504                 jne 0x44c842
// 0044c83e  33c9                 xor ecx, ecx
// 0044c840  eb15                 jmp 0x44c857
// 0044c842  8b4e08               mov ecx, dword ptr [esi + 8]
// 0044c845  2bcf                 sub ecx, edi
// 0044c847  b8abaaaa2a           mov eax, 0x2aaaaaab
// 0044c84c  f7e9                 imul ecx
// 0044c84e  d1fa                 sar edx, 1
// 0044c850  8bca                 mov ecx, edx
// 0044c852  c1e91f               shr ecx, 0x1f
// 0044c855  03ca                 add ecx, edx
// 0044c857  85ff                 test edi, edi
// 0044c859  744a                 je 0x44c8a5
// 0044c85b  8b560c               mov edx, dword ptr [esi + 0xc]
// 0044c85e  2bd7                 sub edx, edi
// 0044c860  b8abaaaa2a           mov eax, 0x2aaaaaab
// 0044c865  f7ea                 imul edx
// 0044c867  d1fa                 sar edx, 1
// 0044c869  8bc2                 mov eax, edx
// 0044c86b  c1e81f               shr eax, 0x1f
// 0044c86e  03c2                 add eax, edx
// 0044c870  3bc8                 cmp ecx, eax
// 0044c872  7331                 jae 0x44c8a5
// 0044c874  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0044c878  8b542414             mov edx, dword ptr [esp + 0x14]
// 0044c87c  8b7e08               mov edi, dword ptr [esi + 8]
// 0044c87f  c644240800           mov byte ptr [esp + 8], 0
// 0044c884  8b442408             mov eax, dword ptr [esp + 8]
// 0044c888  50                   push eax
// 0044c889  51                   push ecx
// 0044c88a  56                   push esi
// 0044c88b  52                   push edx
// 0044c88c  6a01                 push 1
// 0044c88e  57                   push edi
// 0044c88f  e85cfaffff           call 0x44c2f0
// 0044c894  83c418               add esp, 0x18
// 0044c897  83c70c               add edi, 0xc
// 0044c89a  897e08               mov dword ptr [esi + 8], edi
// 0044c89d  5f                   pop edi
// 0044c89e  5e                   pop esi
// 0044c89f  83c408               add esp, 8
// 0044c8a2  c20400               ret 4
// 0044c8a5  53                   push ebx
// 0044c8a6  8b5e08               mov ebx, dword ptr [esi + 8]
// 0044c8a9  3bfb                 cmp edi, ebx
// 0044c8ab  7606                 jbe 0x44c8b3
// 0044c8ad  ff15d8e67700         call dword ptr [0x77e6d8]
// 0044c8b3  8b442418             mov eax, dword ptr [esp + 0x18]
// 0044c8b7  50                   push eax
// 0044c8b8  53                   push ebx
// 0044c8b9  56                   push esi
// 0044c8ba  8d4c2418             lea ecx, [esp + 0x18]
// 0044c8be  51                   push ecx
// 0044c8bf  8bce                 mov ecx, esi
// 0044c8c1  e8bafeffff           call 0x44c780
// 0044c8c6  5b                   pop ebx
// 0044c8c7  5f                   pop edi
// 0044c8c8  5e                   pop esi
// 0044c8c9  83c408               add esp, 8
// 0044c8cc  c20400               ret 4
// standard library vector<pod12> (function ?push_back@?$vector@UE@@V?$allocator@UE@@@std@@@std@@QAEXABUE@@@Z)

// stl: vector<pod12>
struct E { int v[3]; };
#include <vector>
template class std::vector<E>;
