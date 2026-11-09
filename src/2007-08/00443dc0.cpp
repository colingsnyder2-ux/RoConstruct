// from server: 100% by auto
// roc 2007-08 00443dc0  unit: RBX::MergeBinder  size: 143 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00443dc0
//
// 00443dc0  51                   push ecx
// 00443dc1  53                   push ebx
// 00443dc2  55                   push ebp
// 00443dc3  8b6c2414             mov ebp, dword ptr [esp + 0x14]
// 00443dc7  56                   push esi
// 00443dc8  8bf1                 mov esi, ecx
// 00443dca  8b5e04               mov ebx, dword ptr [esi + 4]
// 00443dcd  85db                 test ebx, ebx
// 00443dcf  57                   push edi
// 00443dd0  740c                 je 0x443dde
// 00443dd2  8b4608               mov eax, dword ptr [esi + 8]
// 00443dd5  8bc8                 mov ecx, eax
// 00443dd7  2bcb                 sub ecx, ebx
// 00443dd9  c1f904               sar ecx, 4
// 00443ddc  7504                 jne 0x443de2
// 00443dde  33ff                 xor edi, edi
// 00443de0  eb21                 jmp 0x443e03
// 00443de2  3bd8                 cmp ebx, eax
// 00443de4  7606                 jbe 0x443dec
// 00443de6  ff15d8e67700         call dword ptr [0x77e6d8]
// 00443dec  85ed                 test ebp, ebp
// 00443dee  7404                 je 0x443df4
// 00443df0  3bee                 cmp ebp, esi
// 00443df2  7406                 je 0x443dfa
// 00443df4  ff15d8e67700         call dword ptr [0x77e6d8]
// 00443dfa  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00443dfe  2bfb                 sub edi, ebx
// 00443e00  c1ff04               sar edi, 4
// 00443e03  8b542424             mov edx, dword ptr [esp + 0x24]
// 00443e07  8b442420             mov eax, dword ptr [esp + 0x20]
// 00443e0b  52                   push edx
// 00443e0c  6a01                 push 1
// 00443e0e  50                   push eax
// 00443e0f  55                   push ebp
// 00443e10  8bce                 mov ecx, esi
// 00443e12  e869fbffff           call 0x443980
// 00443e17  8b5e04               mov ebx, dword ptr [esi + 4]
// 00443e1a  3b5e08               cmp ebx, dword ptr [esi + 8]
// 00443e1d  7606                 jbe 0x443e25
// 00443e1f  ff15d8e67700         call dword ptr [0x77e6d8]
// 00443e25  c1e704               shl edi, 4
// 00443e28  03fb                 add edi, ebx
// 00443e2a  3b7e08               cmp edi, dword ptr [esi + 8]
// 00443e2d  895c2420             mov dword ptr [esp + 0x20], ebx
// 00443e31  7705                 ja 0x443e38
// 00443e33  3b7e04               cmp edi, dword ptr [esi + 4]
// 00443e36  7306                 jae 0x443e3e
// 00443e38  ff15d8e67700         call dword ptr [0x77e6d8]
// 00443e3e  8b442418             mov eax, dword ptr [esp + 0x18]
// 00443e42  897804               mov dword ptr [eax + 4], edi
// 00443e45  5f                   pop edi
// 00443e46  8930                 mov dword ptr [eax], esi
// 00443e48  5e                   pop esi
// 00443e49  5d                   pop ebp
// 00443e4a  5b                   pop ebx
// 00443e4b  59                   pop ecx
// 00443e4c  c21000               ret 0x10
// standard library vector<pod16> (function ?insert@?$vector@UE@@V?$allocator@UE@@@std@@@std@@QAE?AV?$_Vector_iterator@UE@@V?$allocator@UE@@@std@@@2@V32@ABUE@@@Z)

// stl: vector<pod16>
struct E { int v[4]; };
#include <vector>
template class std::vector<E>;
