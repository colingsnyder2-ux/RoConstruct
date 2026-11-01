// from server: 100% by auto
// roc 2007-03 005c10f0  unit: seg_005c0000  size: 143 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005c10f0
//
// 005c10f0  51                   push ecx
// 005c10f1  53                   push ebx
// 005c10f2  55                   push ebp
// 005c10f3  8b6c2414             mov ebp, dword ptr [esp + 0x14]
// 005c10f7  56                   push esi
// 005c10f8  8bf1                 mov esi, ecx
// 005c10fa  8b5e04               mov ebx, dword ptr [esi + 4]
// 005c10fd  85db                 test ebx, ebx
// 005c10ff  57                   push edi
// 005c1100  740c                 je 0x5c110e
// 005c1102  8b4608               mov eax, dword ptr [esi + 8]
// 005c1105  8bc8                 mov ecx, eax
// 005c1107  2bcb                 sub ecx, ebx
// 005c1109  c1f904               sar ecx, 4
// 005c110c  7504                 jne 0x5c1112
// 005c110e  33ff                 xor edi, edi
// 005c1110  eb21                 jmp 0x5c1133
// 005c1112  3bd8                 cmp ebx, eax
// 005c1114  7606                 jbe 0x5c111c
// 005c1116  ff1544e97700         call dword ptr [0x77e944]
// 005c111c  85ed                 test ebp, ebp
// 005c111e  7404                 je 0x5c1124
// 005c1120  3bee                 cmp ebp, esi
// 005c1122  7406                 je 0x5c112a
// 005c1124  ff1544e97700         call dword ptr [0x77e944]
// 005c112a  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 005c112e  2bfb                 sub edi, ebx
// 005c1130  c1ff04               sar edi, 4
// 005c1133  8b542424             mov edx, dword ptr [esp + 0x24]
// 005c1137  8b442420             mov eax, dword ptr [esp + 0x20]
// 005c113b  52                   push edx
// 005c113c  6a01                 push 1
// 005c113e  50                   push eax
// 005c113f  55                   push ebp
// 005c1140  8bce                 mov ecx, esi
// 005c1142  e8a9fcffff           call 0x5c0df0
// 005c1147  8b5e04               mov ebx, dword ptr [esi + 4]
// 005c114a  3b5e08               cmp ebx, dword ptr [esi + 8]
// 005c114d  7606                 jbe 0x5c1155
// 005c114f  ff1544e97700         call dword ptr [0x77e944]
// 005c1155  c1e704               shl edi, 4
// 005c1158  03fb                 add edi, ebx
// 005c115a  3b7e08               cmp edi, dword ptr [esi + 8]
// 005c115d  895c2420             mov dword ptr [esp + 0x20], ebx
// 005c1161  7705                 ja 0x5c1168
// 005c1163  3b7e04               cmp edi, dword ptr [esi + 4]
// 005c1166  7306                 jae 0x5c116e
// 005c1168  ff1544e97700         call dword ptr [0x77e944]
// 005c116e  8b442418             mov eax, dword ptr [esp + 0x18]
// 005c1172  897804               mov dword ptr [eax + 4], edi
// 005c1175  5f                   pop edi
// 005c1176  8930                 mov dword ptr [eax], esi
// 005c1178  5e                   pop esi
// 005c1179  5d                   pop ebp
// 005c117a  5b                   pop ebx
// 005c117b  59                   pop ecx
// 005c117c  c21000               ret 0x10
// standard library vector<pod16> (function ?insert@?$vector@UE@@V?$allocator@UE@@@std@@@std@@QAE?AV?$_Vector_iterator@UE@@V?$allocator@UE@@@std@@@2@V32@ABUE@@@Z)

// stl: vector<pod16>
struct E { int v[4]; };
#include <vector>
template class std::vector<E>;
