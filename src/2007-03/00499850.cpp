// from server: 100% by auto
// roc 2007-03 00499850  unit: seg_00490000  size: 172 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00499850
//
// 00499850  51                   push ecx
// 00499851  53                   push ebx
// 00499852  55                   push ebp
// 00499853  8b6c2418             mov ebp, dword ptr [esp + 0x18]
// 00499857  56                   push esi
// 00499858  8bf1                 mov esi, ecx
// 0049985a  57                   push edi
// 0049985b  8b7e04               mov edi, dword ptr [esi + 4]
// 0049985e  85ff                 test edi, edi
// 00499860  7419                 je 0x49987b
// 00499862  8b5e08               mov ebx, dword ptr [esi + 8]
// 00499865  8bcb                 mov ecx, ebx
// 00499867  2bcf                 sub ecx, edi
// 00499869  b8abaaaa2a           mov eax, 0x2aaaaaab
// 0049986e  f7e9                 imul ecx
// 00499870  d1fa                 sar edx, 1
// 00499872  8bc2                 mov eax, edx
// 00499874  c1e81f               shr eax, 0x1f
// 00499877  03c2                 add eax, edx
// 00499879  7508                 jne 0x499883
// 0049987b  8b5c241c             mov ebx, dword ptr [esp + 0x1c]
// 0049987f  33ff                 xor edi, edi
// 00499881  eb30                 jmp 0x4998b3
// 00499883  3bfb                 cmp edi, ebx
// 00499885  7606                 jbe 0x49988d
// 00499887  ff1544e97700         call dword ptr [0x77e944]
// 0049988d  8b5c241c             mov ebx, dword ptr [esp + 0x1c]
// 00499891  85db                 test ebx, ebx
// 00499893  7404                 je 0x499899
// 00499895  3bde                 cmp ebx, esi
// 00499897  7406                 je 0x49989f
// 00499899  ff1544e97700         call dword ptr [0x77e944]
// 0049989f  8bcd                 mov ecx, ebp
// 004998a1  2bcf                 sub ecx, edi
// 004998a3  b8abaaaa2a           mov eax, 0x2aaaaaab
// 004998a8  f7e9                 imul ecx
// 004998aa  d1fa                 sar edx, 1
// 004998ac  8bfa                 mov edi, edx
// 004998ae  c1ef1f               shr edi, 0x1f
// 004998b1  03fa                 add edi, edx
// 004998b3  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 004998b7  51                   push ecx
// 004998b8  6a01                 push 1
// 004998ba  55                   push ebp
// 004998bb  53                   push ebx
// 004998bc  8bce                 mov ecx, esi
// 004998be  e81dfcffff           call 0x4994e0
// 004998c3  8b5e04               mov ebx, dword ptr [esi + 4]
// 004998c6  3b5e08               cmp ebx, dword ptr [esi + 8]
// 004998c9  7606                 jbe 0x4998d1
// 004998cb  ff1544e97700         call dword ptr [0x77e944]
// 004998d1  8d147f               lea edx, [edi + edi*2]
// 004998d4  8d3c93               lea edi, [ebx + edx*4]
// 004998d7  3b7e08               cmp edi, dword ptr [esi + 8]
// 004998da  895c2420             mov dword ptr [esp + 0x20], ebx
// 004998de  7705                 ja 0x4998e5
// 004998e0  3b7e04               cmp edi, dword ptr [esi + 4]
// 004998e3  7306                 jae 0x4998eb
// 004998e5  ff1544e97700         call dword ptr [0x77e944]
// 004998eb  8b442418             mov eax, dword ptr [esp + 0x18]
// 004998ef  897804               mov dword ptr [eax + 4], edi
// 004998f2  5f                   pop edi
// 004998f3  8930                 mov dword ptr [eax], esi
// 004998f5  5e                   pop esi
// 004998f6  5d                   pop ebp
// 004998f7  5b                   pop ebx
// 004998f8  59                   pop ecx
// 004998f9  c21000               ret 0x10
// standard library vector<pod12> (function ?insert@?$vector@UE@@V?$allocator@UE@@@std@@@std@@QAE?AV?$_Vector_iterator@UE@@V?$allocator@UE@@@std@@@2@V32@ABUE@@@Z)

// stl: vector<pod12>
struct E { int v[3]; };
#include <vector>
template class std::vector<E>;
