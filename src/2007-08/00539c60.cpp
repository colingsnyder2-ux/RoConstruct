// from server: 100% by auto
// roc 2007-08 00539c60  unit: RBX::Reflection::VValue::V?$vector::?$holder  size: 141 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00539c60
//
// 00539c60  51                   push ecx
// 00539c61  53                   push ebx
// 00539c62  55                   push ebp
// 00539c63  8b6c2414             mov ebp, dword ptr [esp + 0x14]
// 00539c67  56                   push esi
// 00539c68  8bf1                 mov esi, ecx
// 00539c6a  57                   push edi
// 00539c6b  8b7e04               mov edi, dword ptr [esi + 4]
// 00539c6e  85ff                 test edi, edi
// 00539c70  740c                 je 0x539c7e
// 00539c72  8b4608               mov eax, dword ptr [esi + 8]
// 00539c75  8bc8                 mov ecx, eax
// 00539c77  2bcf                 sub ecx, edi
// 00539c79  c1f903               sar ecx, 3
// 00539c7c  7504                 jne 0x539c82
// 00539c7e  33db                 xor ebx, ebx
// 00539c80  eb21                 jmp 0x539ca3
// 00539c82  3bf8                 cmp edi, eax
// 00539c84  7606                 jbe 0x539c8c
// 00539c86  ff15d8e67700         call dword ptr [0x77e6d8]
// 00539c8c  85ed                 test ebp, ebp
// 00539c8e  7404                 je 0x539c94
// 00539c90  3bee                 cmp ebp, esi
// 00539c92  7406                 je 0x539c9a
// 00539c94  ff15d8e67700         call dword ptr [0x77e6d8]
// 00539c9a  8b5c2420             mov ebx, dword ptr [esp + 0x20]
// 00539c9e  2bdf                 sub ebx, edi
// 00539ca0  c1fb03               sar ebx, 3
// 00539ca3  8b542424             mov edx, dword ptr [esp + 0x24]
// 00539ca7  8b442420             mov eax, dword ptr [esp + 0x20]
// 00539cab  52                   push edx
// 00539cac  6a01                 push 1
// 00539cae  50                   push eax
// 00539caf  55                   push ebp
// 00539cb0  8bce                 mov ecx, esi
// 00539cb2  e809f9ffff           call 0x5395c0
// 00539cb7  8b7e04               mov edi, dword ptr [esi + 4]
// 00539cba  3b7e08               cmp edi, dword ptr [esi + 8]
// 00539cbd  7606                 jbe 0x539cc5
// 00539cbf  ff15d8e67700         call dword ptr [0x77e6d8]
// 00539cc5  897c2420             mov dword ptr [esp + 0x20], edi
// 00539cc9  8d3cdf               lea edi, [edi + ebx*8]
// 00539ccc  3b7e08               cmp edi, dword ptr [esi + 8]
// 00539ccf  7705                 ja 0x539cd6
// 00539cd1  3b7e04               cmp edi, dword ptr [esi + 4]
// 00539cd4  7306                 jae 0x539cdc
// 00539cd6  ff15d8e67700         call dword ptr [0x77e6d8]
// 00539cdc  8b442418             mov eax, dword ptr [esp + 0x18]
// 00539ce0  897804               mov dword ptr [eax + 4], edi
// 00539ce3  5f                   pop edi
// 00539ce4  8930                 mov dword ptr [eax], esi
// 00539ce6  5e                   pop esi
// 00539ce7  5d                   pop ebp
// 00539ce8  5b                   pop ebx
// 00539ce9  59                   pop ecx
// 00539cea  c21000               ret 0x10
// standard library vector<double> (function ?insert@?$vector@NV?$allocator@N@std@@@std@@QAE?AV?$_Vector_iterator@NV?$allocator@N@std@@@2@V32@ABN@Z)

// stl: vector<double>
typedef double E;
#include <vector>
template class std::vector<E>;
