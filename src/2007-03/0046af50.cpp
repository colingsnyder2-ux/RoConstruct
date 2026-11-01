// from server: 100% by auto
// roc 2007-03 0046af50  unit: seg_00460000  size: 143 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0046af50
//
// 0046af50  51                   push ecx
// 0046af51  53                   push ebx
// 0046af52  55                   push ebp
// 0046af53  8b6c2414             mov ebp, dword ptr [esp + 0x14]
// 0046af57  56                   push esi
// 0046af58  8bf1                 mov esi, ecx
// 0046af5a  8b5e04               mov ebx, dword ptr [esi + 4]
// 0046af5d  85db                 test ebx, ebx
// 0046af5f  57                   push edi
// 0046af60  740c                 je 0x46af6e
// 0046af62  8b4608               mov eax, dword ptr [esi + 8]
// 0046af65  8bc8                 mov ecx, eax
// 0046af67  2bcb                 sub ecx, ebx
// 0046af69  c1f906               sar ecx, 6
// 0046af6c  7504                 jne 0x46af72
// 0046af6e  33ff                 xor edi, edi
// 0046af70  eb21                 jmp 0x46af93
// 0046af72  3bd8                 cmp ebx, eax
// 0046af74  7606                 jbe 0x46af7c
// 0046af76  ff1544e97700         call dword ptr [0x77e944]
// 0046af7c  85ed                 test ebp, ebp
// 0046af7e  7404                 je 0x46af84
// 0046af80  3bee                 cmp ebp, esi
// 0046af82  7406                 je 0x46af8a
// 0046af84  ff1544e97700         call dword ptr [0x77e944]
// 0046af8a  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 0046af8e  2bfb                 sub edi, ebx
// 0046af90  c1ff06               sar edi, 6
// 0046af93  8b542424             mov edx, dword ptr [esp + 0x24]
// 0046af97  8b442420             mov eax, dword ptr [esp + 0x20]
// 0046af9b  52                   push edx
// 0046af9c  6a01                 push 1
// 0046af9e  50                   push eax
// 0046af9f  55                   push ebp
// 0046afa0  8bce                 mov ecx, esi
// 0046afa2  e889fbffff           call 0x46ab30
// 0046afa7  8b5e04               mov ebx, dword ptr [esi + 4]
// 0046afaa  3b5e08               cmp ebx, dword ptr [esi + 8]
// 0046afad  7606                 jbe 0x46afb5
// 0046afaf  ff1544e97700         call dword ptr [0x77e944]
// 0046afb5  c1e706               shl edi, 6
// 0046afb8  03fb                 add edi, ebx
// 0046afba  3b7e08               cmp edi, dword ptr [esi + 8]
// 0046afbd  895c2420             mov dword ptr [esp + 0x20], ebx
// 0046afc1  7705                 ja 0x46afc8
// 0046afc3  3b7e04               cmp edi, dword ptr [esi + 4]
// 0046afc6  7306                 jae 0x46afce
// 0046afc8  ff1544e97700         call dword ptr [0x77e944]
// 0046afce  8b442418             mov eax, dword ptr [esp + 0x18]
// 0046afd2  897804               mov dword ptr [eax + 4], edi
// 0046afd5  5f                   pop edi
// 0046afd6  8930                 mov dword ptr [eax], esi
// 0046afd8  5e                   pop esi
// 0046afd9  5d                   pop ebp
// 0046afda  5b                   pop ebx
// 0046afdb  59                   pop ecx
// 0046afdc  c21000               ret 0x10
// standard library vector<pod64> (function ?insert@?$vector@UE@@V?$allocator@UE@@@std@@@std@@QAE?AV?$_Vector_iterator@UE@@V?$allocator@UE@@@std@@@2@V32@ABUE@@@Z)

// stl: vector<pod64>
struct E { int v[16]; };
#include <vector>
template class std::vector<E>;
