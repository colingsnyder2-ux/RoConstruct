// from server: 100% by auto
// roc 2007-08 005db490  unit: RBX::VVelocityMotor::?$FactoryProduct  size: 141 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 005db490
//
// 005db490  51                   push ecx
// 005db491  53                   push ebx
// 005db492  55                   push ebp
// 005db493  8b6c2414             mov ebp, dword ptr [esp + 0x14]
// 005db497  56                   push esi
// 005db498  8bf1                 mov esi, ecx
// 005db49a  57                   push edi
// 005db49b  8b7e04               mov edi, dword ptr [esi + 4]
// 005db49e  85ff                 test edi, edi
// 005db4a0  740c                 je 0x5db4ae
// 005db4a2  8b4608               mov eax, dword ptr [esi + 8]
// 005db4a5  8bc8                 mov ecx, eax
// 005db4a7  2bcf                 sub ecx, edi
// 005db4a9  c1f902               sar ecx, 2
// 005db4ac  7504                 jne 0x5db4b2
// 005db4ae  33db                 xor ebx, ebx
// 005db4b0  eb21                 jmp 0x5db4d3
// 005db4b2  3bf8                 cmp edi, eax
// 005db4b4  7606                 jbe 0x5db4bc
// 005db4b6  ff15d8e67700         call dword ptr [0x77e6d8]
// 005db4bc  85ed                 test ebp, ebp
// 005db4be  7404                 je 0x5db4c4
// 005db4c0  3bee                 cmp ebp, esi
// 005db4c2  7406                 je 0x5db4ca
// 005db4c4  ff15d8e67700         call dword ptr [0x77e6d8]
// 005db4ca  8b5c2420             mov ebx, dword ptr [esp + 0x20]
// 005db4ce  2bdf                 sub ebx, edi
// 005db4d0  c1fb02               sar ebx, 2
// 005db4d3  8b542424             mov edx, dword ptr [esp + 0x24]
// 005db4d7  8b442420             mov eax, dword ptr [esp + 0x20]
// 005db4db  52                   push edx
// 005db4dc  6a01                 push 1
// 005db4de  50                   push eax
// 005db4df  55                   push ebp
// 005db4e0  8bce                 mov ecx, esi
// 005db4e2  e859fdffff           call 0x5db240
// 005db4e7  8b7e04               mov edi, dword ptr [esi + 4]
// 005db4ea  3b7e08               cmp edi, dword ptr [esi + 8]
// 005db4ed  7606                 jbe 0x5db4f5
// 005db4ef  ff15d8e67700         call dword ptr [0x77e6d8]
// 005db4f5  897c2420             mov dword ptr [esp + 0x20], edi
// 005db4f9  8d3c9f               lea edi, [edi + ebx*4]
// 005db4fc  3b7e08               cmp edi, dword ptr [esi + 8]
// 005db4ff  7705                 ja 0x5db506
// 005db501  3b7e04               cmp edi, dword ptr [esi + 4]
// 005db504  7306                 jae 0x5db50c
// 005db506  ff15d8e67700         call dword ptr [0x77e6d8]
// 005db50c  8b442418             mov eax, dword ptr [esp + 0x18]
// 005db510  897804               mov dword ptr [eax + 4], edi
// 005db513  5f                   pop edi
// 005db514  8930                 mov dword ptr [eax], esi
// 005db516  5e                   pop esi
// 005db517  5d                   pop ebp
// 005db518  5b                   pop ebx
// 005db519  59                   pop ecx
// 005db51a  c21000               ret 0x10
// standard library vector<ptr> (function ?insert@?$vector@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAE?AV?$_Vector_iterator@PAUT@@V?$allocator@PAUT@@@std@@@2@V32@ABQAUT@@@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
