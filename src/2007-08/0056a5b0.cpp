// from server: 100% by auto
// roc 2007-08 0056a5b0  unit: RBX::ModelInstance  size: 203 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0056a5b0
//
// 0056a5b0  83ec08               sub esp, 8
// 0056a5b3  53                   push ebx
// 0056a5b4  55                   push ebp
// 0056a5b5  56                   push esi
// 0056a5b6  57                   push edi
// 0056a5b7  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 0056a5bb  85ff                 test edi, edi
// 0056a5bd  8bf1                 mov esi, ecx
// 0056a5bf  8b4604               mov eax, dword ptr [esi + 4]
// 0056a5c2  8b28                 mov ebp, dword ptr [eax]
// 0056a5c4  7404                 je 0x56a5ca
// 0056a5c6  3bfe                 cmp edi, esi
// 0056a5c8  7406                 je 0x56a5d0
// 0056a5ca  ff15d8e67700         call dword ptr [0x77e6d8]
// 0056a5d0  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 0056a5d4  3bdd                 cmp ebx, ebp
// 0056a5d6  7559                 jne 0x56a631
// 0056a5d8  8b442428             mov eax, dword ptr [esp + 0x28]
// 0056a5dc  85c0                 test eax, eax
// 0056a5de  8b6e04               mov ebp, dword ptr [esi + 4]
// 0056a5e1  7404                 je 0x56a5e7
// 0056a5e3  3bc6                 cmp eax, esi
// 0056a5e5  7406                 je 0x56a5ed
// 0056a5e7  ff15d8e67700         call dword ptr [0x77e6d8]
// 0056a5ed  396c242c             cmp dword ptr [esp + 0x2c], ebp
// 0056a5f1  753e                 jne 0x56a631
// 0056a5f3  8b4e04               mov ecx, dword ptr [esi + 4]
// 0056a5f6  8b5104               mov edx, dword ptr [ecx + 4]
// 0056a5f9  52                   push edx
// 0056a5fa  8bce                 mov ecx, esi
// 0056a5fc  e8cf12f4ff           call 0x4ab8d0
// 0056a601  8b4604               mov eax, dword ptr [esi + 4]
// 0056a604  894004               mov dword ptr [eax + 4], eax
// 0056a607  8b4604               mov eax, dword ptr [esi + 4]
// 0056a60a  c7460800000000       mov dword ptr [esi + 8], 0
// 0056a611  8900                 mov dword ptr [eax], eax
// 0056a613  8b4604               mov eax, dword ptr [esi + 4]
// 0056a616  894008               mov dword ptr [eax + 8], eax
// 0056a619  8b4604               mov eax, dword ptr [esi + 4]
// 0056a61c  8b08                 mov ecx, dword ptr [eax]
// 0056a61e  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0056a622  5f                   pop edi
// 0056a623  8930                 mov dword ptr [eax], esi
// 0056a625  5e                   pop esi
// 0056a626  5d                   pop ebp
// 0056a627  894804               mov dword ptr [eax + 4], ecx
// 0056a62a  5b                   pop ebx
// 0056a62b  83c408               add esp, 8
// 0056a62e  c21400               ret 0x14
// 0056a631  85ff                 test edi, edi
// 0056a633  7406                 je 0x56a63b
// 0056a635  3b7c2428             cmp edi, dword ptr [esp + 0x28]
// 0056a639  7406                 je 0x56a641
// 0056a63b  ff15d8e67700         call dword ptr [0x77e6d8]
// 0056a641  3b5c242c             cmp ebx, dword ptr [esp + 0x2c]
// 0056a645  7421                 je 0x56a668
// 0056a647  8d4c2420             lea ecx, [esp + 0x20]
// 0056a64b  e870d60100           call 0x587cc0
// 0056a650  53                   push ebx
// 0056a651  57                   push edi
// 0056a652  8d542418             lea edx, [esp + 0x18]
// 0056a656  52                   push edx
// 0056a657  8bce                 mov ecx, esi
// 0056a659  e8d2f8ffff           call 0x569f30
// 0056a65e  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 0056a662  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 0056a666  ebc9                 jmp 0x56a631
// 0056a668  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0056a66c  8938                 mov dword ptr [eax], edi
// 0056a66e  5f                   pop edi
// 0056a66f  5e                   pop esi
// 0056a670  5d                   pop ebp
// 0056a671  895804               mov dword ptr [eax + 4], ebx
// 0056a674  5b                   pop ebx
// 0056a675  83c408               add esp, 8
// 0056a678  c21400               ret 0x14
// standard library set<ptr> (function ?erase@?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE?AViterator@12@V312@0@Z)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
