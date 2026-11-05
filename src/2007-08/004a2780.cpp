// from server: 100% by auto
// roc 2007-08 004a2780  unit: RBX::Network::VServer::?$BoundFuncDesc  size: 172 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004a2780
//
// 004a2780  51                   push ecx
// 004a2781  53                   push ebx
// 004a2782  55                   push ebp
// 004a2783  8b6c2418             mov ebp, dword ptr [esp + 0x18]
// 004a2787  56                   push esi
// 004a2788  8bf1                 mov esi, ecx
// 004a278a  57                   push edi
// 004a278b  8b7e04               mov edi, dword ptr [esi + 4]
// 004a278e  85ff                 test edi, edi
// 004a2790  7419                 je 0x4a27ab
// 004a2792  8b5e08               mov ebx, dword ptr [esi + 8]
// 004a2795  8bcb                 mov ecx, ebx
// 004a2797  2bcf                 sub ecx, edi
// 004a2799  b8abaaaa2a           mov eax, 0x2aaaaaab
// 004a279e  f7e9                 imul ecx
// 004a27a0  d1fa                 sar edx, 1
// 004a27a2  8bc2                 mov eax, edx
// 004a27a4  c1e81f               shr eax, 0x1f
// 004a27a7  03c2                 add eax, edx
// 004a27a9  7508                 jne 0x4a27b3
// 004a27ab  8b5c241c             mov ebx, dword ptr [esp + 0x1c]
// 004a27af  33ff                 xor edi, edi
// 004a27b1  eb30                 jmp 0x4a27e3
// 004a27b3  3bfb                 cmp edi, ebx
// 004a27b5  7606                 jbe 0x4a27bd
// 004a27b7  ff15d8e67700         call dword ptr [0x77e6d8]
// 004a27bd  8b5c241c             mov ebx, dword ptr [esp + 0x1c]
// 004a27c1  85db                 test ebx, ebx
// 004a27c3  7404                 je 0x4a27c9
// 004a27c5  3bde                 cmp ebx, esi
// 004a27c7  7406                 je 0x4a27cf
// 004a27c9  ff15d8e67700         call dword ptr [0x77e6d8]
// 004a27cf  8bcd                 mov ecx, ebp
// 004a27d1  2bcf                 sub ecx, edi
// 004a27d3  b8abaaaa2a           mov eax, 0x2aaaaaab
// 004a27d8  f7e9                 imul ecx
// 004a27da  d1fa                 sar edx, 1
// 004a27dc  8bfa                 mov edi, edx
// 004a27de  c1ef1f               shr edi, 0x1f
// 004a27e1  03fa                 add edi, edx
// 004a27e3  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 004a27e7  51                   push ecx
// 004a27e8  6a01                 push 1
// 004a27ea  55                   push ebp
// 004a27eb  53                   push ebx
// 004a27ec  8bce                 mov ecx, esi
// 004a27ee  e86dfbffff           call 0x4a2360
// 004a27f3  8b5e04               mov ebx, dword ptr [esi + 4]
// 004a27f6  3b5e08               cmp ebx, dword ptr [esi + 8]
// 004a27f9  7606                 jbe 0x4a2801
// 004a27fb  ff15d8e67700         call dword ptr [0x77e6d8]
// 004a2801  8d147f               lea edx, [edi + edi*2]
// 004a2804  8d3c93               lea edi, [ebx + edx*4]
// 004a2807  3b7e08               cmp edi, dword ptr [esi + 8]
// 004a280a  895c2420             mov dword ptr [esp + 0x20], ebx
// 004a280e  7705                 ja 0x4a2815
// 004a2810  3b7e04               cmp edi, dword ptr [esi + 4]
// 004a2813  7306                 jae 0x4a281b
// 004a2815  ff15d8e67700         call dword ptr [0x77e6d8]
// 004a281b  8b442418             mov eax, dword ptr [esp + 0x18]
// 004a281f  897804               mov dword ptr [eax + 4], edi
// 004a2822  5f                   pop edi
// 004a2823  8930                 mov dword ptr [eax], esi
// 004a2825  5e                   pop esi
// 004a2826  5d                   pop ebp
// 004a2827  5b                   pop ebx
// 004a2828  59                   pop ecx
// 004a2829  c21000               ret 0x10
// standard library vector<pod12> (function ?insert@?$vector@UE@@V?$allocator@UE@@@std@@@std@@QAE?AV?$_Vector_iterator@UE@@V?$allocator@UE@@@std@@@2@V32@ABUE@@@Z)

// stl: vector<pod12>
struct E { int v[3]; };
#include <vector>
template class std::vector<E>;
