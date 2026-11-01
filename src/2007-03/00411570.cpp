// from server: 100% by auto
// roc 2007-03 00411570  unit: seg_00410000  size: 174 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00411570
//
// 00411570  51                   push ecx
// 00411571  53                   push ebx
// 00411572  55                   push ebp
// 00411573  8b6c2418             mov ebp, dword ptr [esp + 0x18]
// 00411577  56                   push esi
// 00411578  8bf1                 mov esi, ecx
// 0041157a  57                   push edi
// 0041157b  8b7e04               mov edi, dword ptr [esi + 4]
// 0041157e  85ff                 test edi, edi
// 00411580  741a                 je 0x41159c
// 00411582  8b5e08               mov ebx, dword ptr [esi + 8]
// 00411585  8bcb                 mov ecx, ebx
// 00411587  2bcf                 sub ecx, edi
// 00411589  b8398ee338           mov eax, 0x38e38e39
// 0041158e  f7e9                 imul ecx
// 00411590  c1fa03               sar edx, 3
// 00411593  8bc2                 mov eax, edx
// 00411595  c1e81f               shr eax, 0x1f
// 00411598  03c2                 add eax, edx
// 0041159a  7508                 jne 0x4115a4
// 0041159c  8b5c241c             mov ebx, dword ptr [esp + 0x1c]
// 004115a0  33ff                 xor edi, edi
// 004115a2  eb31                 jmp 0x4115d5
// 004115a4  3bfb                 cmp edi, ebx
// 004115a6  7606                 jbe 0x4115ae
// 004115a8  ff1544e97700         call dword ptr [0x77e944]
// 004115ae  8b5c241c             mov ebx, dword ptr [esp + 0x1c]
// 004115b2  85db                 test ebx, ebx
// 004115b4  7404                 je 0x4115ba
// 004115b6  3bde                 cmp ebx, esi
// 004115b8  7406                 je 0x4115c0
// 004115ba  ff1544e97700         call dword ptr [0x77e944]
// 004115c0  8bcd                 mov ecx, ebp
// 004115c2  2bcf                 sub ecx, edi
// 004115c4  b8398ee338           mov eax, 0x38e38e39
// 004115c9  f7e9                 imul ecx
// 004115cb  c1fa03               sar edx, 3
// 004115ce  8bfa                 mov edi, edx
// 004115d0  c1ef1f               shr edi, 0x1f
// 004115d3  03fa                 add edi, edx
// 004115d5  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 004115d9  51                   push ecx
// 004115da  6a01                 push 1
// 004115dc  55                   push ebp
// 004115dd  53                   push ebx
// 004115de  8bce                 mov ecx, esi
// 004115e0  e87bfcffff           call 0x411260
// 004115e5  8b5e04               mov ebx, dword ptr [esi + 4]
// 004115e8  3b5e08               cmp ebx, dword ptr [esi + 8]
// 004115eb  7606                 jbe 0x4115f3
// 004115ed  ff1544e97700         call dword ptr [0x77e944]
// 004115f3  8d14ff               lea edx, [edi + edi*8]
// 004115f6  8d3c93               lea edi, [ebx + edx*4]
// 004115f9  3b7e08               cmp edi, dword ptr [esi + 8]
// 004115fc  895c2420             mov dword ptr [esp + 0x20], ebx
// 00411600  7705                 ja 0x411607
// 00411602  3b7e04               cmp edi, dword ptr [esi + 4]
// 00411605  7306                 jae 0x41160d
// 00411607  ff1544e97700         call dword ptr [0x77e944]
// 0041160d  8b442418             mov eax, dword ptr [esp + 0x18]
// 00411611  897804               mov dword ptr [eax + 4], edi
// 00411614  5f                   pop edi
// 00411615  8930                 mov dword ptr [eax], esi
// 00411617  5e                   pop esi
// 00411618  5d                   pop ebp
// 00411619  5b                   pop ebx
// 0041161a  59                   pop ecx
// 0041161b  c21000               ret 0x10
// standard library vector<pod36> (function ?insert@?$vector@UE@@V?$allocator@UE@@@std@@@std@@QAE?AV?$_Vector_iterator@UE@@V?$allocator@UE@@@std@@@2@V32@ABUE@@@Z)

// stl: vector<pod36>
struct E { int v[9]; };
#include <vector>
template class std::vector<E>;
