// from server: 100% by auto
// roc 2007-08 005c5420  unit: RBX::Lua::VThreadRef::?$sp_counted_impl_p  size: 143 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 005c5420
//
// 005c5420  51                   push ecx
// 005c5421  53                   push ebx
// 005c5422  55                   push ebp
// 005c5423  8b6c2414             mov ebp, dword ptr [esp + 0x14]
// 005c5427  56                   push esi
// 005c5428  8bf1                 mov esi, ecx
// 005c542a  8b5e04               mov ebx, dword ptr [esi + 4]
// 005c542d  85db                 test ebx, ebx
// 005c542f  57                   push edi
// 005c5430  740c                 je 0x5c543e
// 005c5432  8b4608               mov eax, dword ptr [esi + 8]
// 005c5435  8bc8                 mov ecx, eax
// 005c5437  2bcb                 sub ecx, ebx
// 005c5439  c1f904               sar ecx, 4
// 005c543c  7504                 jne 0x5c5442
// 005c543e  33ff                 xor edi, edi
// 005c5440  eb21                 jmp 0x5c5463
// 005c5442  3bd8                 cmp ebx, eax
// 005c5444  7606                 jbe 0x5c544c
// 005c5446  ff15d8e67700         call dword ptr [0x77e6d8]
// 005c544c  85ed                 test ebp, ebp
// 005c544e  7404                 je 0x5c5454
// 005c5450  3bee                 cmp ebp, esi
// 005c5452  7406                 je 0x5c545a
// 005c5454  ff15d8e67700         call dword ptr [0x77e6d8]
// 005c545a  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 005c545e  2bfb                 sub edi, ebx
// 005c5460  c1ff04               sar edi, 4
// 005c5463  8b542424             mov edx, dword ptr [esp + 0x24]
// 005c5467  8b442420             mov eax, dword ptr [esp + 0x20]
// 005c546b  52                   push edx
// 005c546c  6a01                 push 1
// 005c546e  50                   push eax
// 005c546f  55                   push ebp
// 005c5470  8bce                 mov ecx, esi
// 005c5472  e8a9fcffff           call 0x5c5120
// 005c5477  8b5e04               mov ebx, dword ptr [esi + 4]
// 005c547a  3b5e08               cmp ebx, dword ptr [esi + 8]
// 005c547d  7606                 jbe 0x5c5485
// 005c547f  ff15d8e67700         call dword ptr [0x77e6d8]
// 005c5485  c1e704               shl edi, 4
// 005c5488  03fb                 add edi, ebx
// 005c548a  3b7e08               cmp edi, dword ptr [esi + 8]
// 005c548d  895c2420             mov dword ptr [esp + 0x20], ebx
// 005c5491  7705                 ja 0x5c5498
// 005c5493  3b7e04               cmp edi, dword ptr [esi + 4]
// 005c5496  7306                 jae 0x5c549e
// 005c5498  ff15d8e67700         call dword ptr [0x77e6d8]
// 005c549e  8b442418             mov eax, dword ptr [esp + 0x18]
// 005c54a2  897804               mov dword ptr [eax + 4], edi
// 005c54a5  5f                   pop edi
// 005c54a6  8930                 mov dword ptr [eax], esi
// 005c54a8  5e                   pop esi
// 005c54a9  5d                   pop ebp
// 005c54aa  5b                   pop ebx
// 005c54ab  59                   pop ecx
// 005c54ac  c21000               ret 0x10
// standard library vector<pod16> (function ?insert@?$vector@UE@@V?$allocator@UE@@@std@@@std@@QAE?AV?$_Vector_iterator@UE@@V?$allocator@UE@@@std@@@2@V32@ABUE@@@Z)

// stl: vector<pod16>
struct E { int v[4]; };
#include <vector>
template class std::vector<E>;
