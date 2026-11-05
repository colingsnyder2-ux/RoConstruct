// from server: 100% by auto
// roc 2007-08 0044c780  unit: CRobloxControlColorSelector  size: 172 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0044c780
//
// 0044c780  51                   push ecx
// 0044c781  53                   push ebx
// 0044c782  55                   push ebp
// 0044c783  8b6c2418             mov ebp, dword ptr [esp + 0x18]
// 0044c787  56                   push esi
// 0044c788  8bf1                 mov esi, ecx
// 0044c78a  57                   push edi
// 0044c78b  8b7e04               mov edi, dword ptr [esi + 4]
// 0044c78e  85ff                 test edi, edi
// 0044c790  7419                 je 0x44c7ab
// 0044c792  8b5e08               mov ebx, dword ptr [esi + 8]
// 0044c795  8bcb                 mov ecx, ebx
// 0044c797  2bcf                 sub ecx, edi
// 0044c799  b8abaaaa2a           mov eax, 0x2aaaaaab
// 0044c79e  f7e9                 imul ecx
// 0044c7a0  d1fa                 sar edx, 1
// 0044c7a2  8bc2                 mov eax, edx
// 0044c7a4  c1e81f               shr eax, 0x1f
// 0044c7a7  03c2                 add eax, edx
// 0044c7a9  7508                 jne 0x44c7b3
// 0044c7ab  8b5c241c             mov ebx, dword ptr [esp + 0x1c]
// 0044c7af  33ff                 xor edi, edi
// 0044c7b1  eb30                 jmp 0x44c7e3
// 0044c7b3  3bfb                 cmp edi, ebx
// 0044c7b5  7606                 jbe 0x44c7bd
// 0044c7b7  ff15d8e67700         call dword ptr [0x77e6d8]
// 0044c7bd  8b5c241c             mov ebx, dword ptr [esp + 0x1c]
// 0044c7c1  85db                 test ebx, ebx
// 0044c7c3  7404                 je 0x44c7c9
// 0044c7c5  3bde                 cmp ebx, esi
// 0044c7c7  7406                 je 0x44c7cf
// 0044c7c9  ff15d8e67700         call dword ptr [0x77e6d8]
// 0044c7cf  8bcd                 mov ecx, ebp
// 0044c7d1  2bcf                 sub ecx, edi
// 0044c7d3  b8abaaaa2a           mov eax, 0x2aaaaaab
// 0044c7d8  f7e9                 imul ecx
// 0044c7da  d1fa                 sar edx, 1
// 0044c7dc  8bfa                 mov edi, edx
// 0044c7de  c1ef1f               shr edi, 0x1f
// 0044c7e1  03fa                 add edi, edx
// 0044c7e3  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 0044c7e7  51                   push ecx
// 0044c7e8  6a01                 push 1
// 0044c7ea  55                   push ebp
// 0044c7eb  53                   push ebx
// 0044c7ec  8bce                 mov ecx, esi
// 0044c7ee  e89dfcffff           call 0x44c490
// 0044c7f3  8b5e04               mov ebx, dword ptr [esi + 4]
// 0044c7f6  3b5e08               cmp ebx, dword ptr [esi + 8]
// 0044c7f9  7606                 jbe 0x44c801
// 0044c7fb  ff15d8e67700         call dword ptr [0x77e6d8]
// 0044c801  8d147f               lea edx, [edi + edi*2]
// 0044c804  8d3c93               lea edi, [ebx + edx*4]
// 0044c807  3b7e08               cmp edi, dword ptr [esi + 8]
// 0044c80a  895c2420             mov dword ptr [esp + 0x20], ebx
// 0044c80e  7705                 ja 0x44c815
// 0044c810  3b7e04               cmp edi, dword ptr [esi + 4]
// 0044c813  7306                 jae 0x44c81b
// 0044c815  ff15d8e67700         call dword ptr [0x77e6d8]
// 0044c81b  8b442418             mov eax, dword ptr [esp + 0x18]
// 0044c81f  897804               mov dword ptr [eax + 4], edi
// 0044c822  5f                   pop edi
// 0044c823  8930                 mov dword ptr [eax], esi
// 0044c825  5e                   pop esi
// 0044c826  5d                   pop ebp
// 0044c827  5b                   pop ebx
// 0044c828  59                   pop ecx
// 0044c829  c21000               ret 0x10
// standard library vector<pod12> (function ?insert@?$vector@UE@@V?$allocator@UE@@@std@@@std@@QAE?AV?$_Vector_iterator@UE@@V?$allocator@UE@@@std@@@2@V32@ABUE@@@Z)

// stl: vector<pod12>
struct E { int v[3]; };
#include <vector>
template class std::vector<E>;
