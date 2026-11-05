// from server: 100% by auto
// roc 2007-08 0046aeb0  unit: RBX::LDraw2Lua::LDraw2RobloxMapRoot  size: 143 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0046aeb0
//
// 0046aeb0  51                   push ecx
// 0046aeb1  53                   push ebx
// 0046aeb2  55                   push ebp
// 0046aeb3  8b6c2414             mov ebp, dword ptr [esp + 0x14]
// 0046aeb7  56                   push esi
// 0046aeb8  8bf1                 mov esi, ecx
// 0046aeba  8b5e04               mov ebx, dword ptr [esi + 4]
// 0046aebd  85db                 test ebx, ebx
// 0046aebf  57                   push edi
// 0046aec0  740c                 je 0x46aece
// 0046aec2  8b4608               mov eax, dword ptr [esi + 8]
// 0046aec5  8bc8                 mov ecx, eax
// 0046aec7  2bcb                 sub ecx, ebx
// 0046aec9  c1f906               sar ecx, 6
// 0046aecc  7504                 jne 0x46aed2
// 0046aece  33ff                 xor edi, edi
// 0046aed0  eb21                 jmp 0x46aef3
// 0046aed2  3bd8                 cmp ebx, eax
// 0046aed4  7606                 jbe 0x46aedc
// 0046aed6  ff15d8e67700         call dword ptr [0x77e6d8]
// 0046aedc  85ed                 test ebp, ebp
// 0046aede  7404                 je 0x46aee4
// 0046aee0  3bee                 cmp ebp, esi
// 0046aee2  7406                 je 0x46aeea
// 0046aee4  ff15d8e67700         call dword ptr [0x77e6d8]
// 0046aeea  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 0046aeee  2bfb                 sub edi, ebx
// 0046aef0  c1ff06               sar edi, 6
// 0046aef3  8b542424             mov edx, dword ptr [esp + 0x24]
// 0046aef7  8b442420             mov eax, dword ptr [esp + 0x20]
// 0046aefb  52                   push edx
// 0046aefc  6a01                 push 1
// 0046aefe  50                   push eax
// 0046aeff  55                   push ebp
// 0046af00  8bce                 mov ecx, esi
// 0046af02  e889fbffff           call 0x46aa90
// 0046af07  8b5e04               mov ebx, dword ptr [esi + 4]
// 0046af0a  3b5e08               cmp ebx, dword ptr [esi + 8]
// 0046af0d  7606                 jbe 0x46af15
// 0046af0f  ff15d8e67700         call dword ptr [0x77e6d8]
// 0046af15  c1e706               shl edi, 6
// 0046af18  03fb                 add edi, ebx
// 0046af1a  3b7e08               cmp edi, dword ptr [esi + 8]
// 0046af1d  895c2420             mov dword ptr [esp + 0x20], ebx
// 0046af21  7705                 ja 0x46af28
// 0046af23  3b7e04               cmp edi, dword ptr [esi + 4]
// 0046af26  7306                 jae 0x46af2e
// 0046af28  ff15d8e67700         call dword ptr [0x77e6d8]
// 0046af2e  8b442418             mov eax, dword ptr [esp + 0x18]
// 0046af32  897804               mov dword ptr [eax + 4], edi
// 0046af35  5f                   pop edi
// 0046af36  8930                 mov dword ptr [eax], esi
// 0046af38  5e                   pop esi
// 0046af39  5d                   pop ebp
// 0046af3a  5b                   pop ebx
// 0046af3b  59                   pop ecx
// 0046af3c  c21000               ret 0x10
// standard library vector<pod64> (function ?insert@?$vector@UE@@V?$allocator@UE@@@std@@@std@@QAE?AV?$_Vector_iterator@UE@@V?$allocator@UE@@@std@@@2@V32@ABUE@@@Z)

// stl: vector<pod64>
struct E { int v[16]; };
#include <vector>
template class std::vector<E>;
