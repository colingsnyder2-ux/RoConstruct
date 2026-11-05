// from server: 100% by auto
// roc 2007-03 0044b050  unit: seg_00440000  size: 172 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0044b050
//
// 0044b050  51                   push ecx
// 0044b051  53                   push ebx
// 0044b052  55                   push ebp
// 0044b053  8b6c2418             mov ebp, dword ptr [esp + 0x18]
// 0044b057  56                   push esi
// 0044b058  8bf1                 mov esi, ecx
// 0044b05a  57                   push edi
// 0044b05b  8b7e04               mov edi, dword ptr [esi + 4]
// 0044b05e  85ff                 test edi, edi
// 0044b060  7419                 je 0x44b07b
// 0044b062  8b5e08               mov ebx, dword ptr [esi + 8]
// 0044b065  8bcb                 mov ecx, ebx
// 0044b067  2bcf                 sub ecx, edi
// 0044b069  b8abaaaa2a           mov eax, 0x2aaaaaab
// 0044b06e  f7e9                 imul ecx
// 0044b070  d1fa                 sar edx, 1
// 0044b072  8bc2                 mov eax, edx
// 0044b074  c1e81f               shr eax, 0x1f
// 0044b077  03c2                 add eax, edx
// 0044b079  7508                 jne 0x44b083
// 0044b07b  8b5c241c             mov ebx, dword ptr [esp + 0x1c]
// 0044b07f  33ff                 xor edi, edi
// 0044b081  eb30                 jmp 0x44b0b3
// 0044b083  3bfb                 cmp edi, ebx
// 0044b085  7606                 jbe 0x44b08d
// 0044b087  ff1544e97700         call dword ptr [0x77e944]
// 0044b08d  8b5c241c             mov ebx, dword ptr [esp + 0x1c]
// 0044b091  85db                 test ebx, ebx
// 0044b093  7404                 je 0x44b099
// 0044b095  3bde                 cmp ebx, esi
// 0044b097  7406                 je 0x44b09f
// 0044b099  ff1544e97700         call dword ptr [0x77e944]
// 0044b09f  8bcd                 mov ecx, ebp
// 0044b0a1  2bcf                 sub ecx, edi
// 0044b0a3  b8abaaaa2a           mov eax, 0x2aaaaaab
// 0044b0a8  f7e9                 imul ecx
// 0044b0aa  d1fa                 sar edx, 1
// 0044b0ac  8bfa                 mov edi, edx
// 0044b0ae  c1ef1f               shr edi, 0x1f
// 0044b0b1  03fa                 add edi, edx
// 0044b0b3  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 0044b0b7  51                   push ecx
// 0044b0b8  6a01                 push 1
// 0044b0ba  55                   push ebp
// 0044b0bb  53                   push ebx
// 0044b0bc  8bce                 mov ecx, esi
// 0044b0be  e89dfcffff           call 0x44ad60
// 0044b0c3  8b5e04               mov ebx, dword ptr [esi + 4]
// 0044b0c6  3b5e08               cmp ebx, dword ptr [esi + 8]
// 0044b0c9  7606                 jbe 0x44b0d1
// 0044b0cb  ff1544e97700         call dword ptr [0x77e944]
// 0044b0d1  8d147f               lea edx, [edi + edi*2]
// 0044b0d4  8d3c93               lea edi, [ebx + edx*4]
// 0044b0d7  3b7e08               cmp edi, dword ptr [esi + 8]
// 0044b0da  895c2420             mov dword ptr [esp + 0x20], ebx
// 0044b0de  7705                 ja 0x44b0e5
// 0044b0e0  3b7e04               cmp edi, dword ptr [esi + 4]
// 0044b0e3  7306                 jae 0x44b0eb
// 0044b0e5  ff1544e97700         call dword ptr [0x77e944]
// 0044b0eb  8b442418             mov eax, dword ptr [esp + 0x18]
// 0044b0ef  897804               mov dword ptr [eax + 4], edi
// 0044b0f2  5f                   pop edi
// 0044b0f3  8930                 mov dword ptr [eax], esi
// 0044b0f5  5e                   pop esi
// 0044b0f6  5d                   pop ebp
// 0044b0f7  5b                   pop ebx
// 0044b0f8  59                   pop ecx
// 0044b0f9  c21000               ret 0x10
// standard library vector<pod12> (function ?insert@?$vector@UE@@V?$allocator@UE@@@std@@@std@@QAE?AV?$_Vector_iterator@UE@@V?$allocator@UE@@@std@@@2@V32@ABUE@@@Z)

// stl: vector<pod12>
struct E { int v[3]; };
#include <vector>
template class std::vector<E>;
