// from server: 100% by auto
// roc 2007-08 004d5ab0  unit: RBX::View::Part  size: 203 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004d5ab0
//
// 004d5ab0  83ec08               sub esp, 8
// 004d5ab3  53                   push ebx
// 004d5ab4  55                   push ebp
// 004d5ab5  56                   push esi
// 004d5ab6  57                   push edi
// 004d5ab7  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 004d5abb  85ff                 test edi, edi
// 004d5abd  8bf1                 mov esi, ecx
// 004d5abf  8b4604               mov eax, dword ptr [esi + 4]
// 004d5ac2  8b28                 mov ebp, dword ptr [eax]
// 004d5ac4  7404                 je 0x4d5aca
// 004d5ac6  3bfe                 cmp edi, esi
// 004d5ac8  7406                 je 0x4d5ad0
// 004d5aca  ff15d8e67700         call dword ptr [0x77e6d8]
// 004d5ad0  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 004d5ad4  3bdd                 cmp ebx, ebp
// 004d5ad6  7559                 jne 0x4d5b31
// 004d5ad8  8b442428             mov eax, dword ptr [esp + 0x28]
// 004d5adc  85c0                 test eax, eax
// 004d5ade  8b6e04               mov ebp, dword ptr [esi + 4]
// 004d5ae1  7404                 je 0x4d5ae7
// 004d5ae3  3bc6                 cmp eax, esi
// 004d5ae5  7406                 je 0x4d5aed
// 004d5ae7  ff15d8e67700         call dword ptr [0x77e6d8]
// 004d5aed  396c242c             cmp dword ptr [esp + 0x2c], ebp
// 004d5af1  753e                 jne 0x4d5b31
// 004d5af3  8b4e04               mov ecx, dword ptr [esi + 4]
// 004d5af6  8b5104               mov edx, dword ptr [ecx + 4]
// 004d5af9  52                   push edx
// 004d5afa  8bce                 mov ecx, esi
// 004d5afc  e85fe0ffff           call 0x4d3b60
// 004d5b01  8b4604               mov eax, dword ptr [esi + 4]
// 004d5b04  894004               mov dword ptr [eax + 4], eax
// 004d5b07  8b4604               mov eax, dword ptr [esi + 4]
// 004d5b0a  c7460800000000       mov dword ptr [esi + 8], 0
// 004d5b11  8900                 mov dword ptr [eax], eax
// 004d5b13  8b4604               mov eax, dword ptr [esi + 4]
// 004d5b16  894008               mov dword ptr [eax + 8], eax
// 004d5b19  8b4604               mov eax, dword ptr [esi + 4]
// 004d5b1c  8b08                 mov ecx, dword ptr [eax]
// 004d5b1e  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 004d5b22  5f                   pop edi
// 004d5b23  8930                 mov dword ptr [eax], esi
// 004d5b25  5e                   pop esi
// 004d5b26  5d                   pop ebp
// 004d5b27  894804               mov dword ptr [eax + 4], ecx
// 004d5b2a  5b                   pop ebx
// 004d5b2b  83c408               add esp, 8
// 004d5b2e  c21400               ret 0x14
// 004d5b31  85ff                 test edi, edi
// 004d5b33  7406                 je 0x4d5b3b
// 004d5b35  3b7c2428             cmp edi, dword ptr [esp + 0x28]
// 004d5b39  7406                 je 0x4d5b41
// 004d5b3b  ff15d8e67700         call dword ptr [0x77e6d8]
// 004d5b41  3b5c242c             cmp ebx, dword ptr [esp + 0x2c]
// 004d5b45  7421                 je 0x4d5b68
// 004d5b47  8d4c2420             lea ecx, [esp + 0x20]
// 004d5b4b  e890adffff           call 0x4d08e0
// 004d5b50  53                   push ebx
// 004d5b51  57                   push edi
// 004d5b52  8d542418             lea edx, [esp + 0x18]
// 004d5b56  52                   push edx
// 004d5b57  8bce                 mov ecx, esi
// 004d5b59  e8d2dcffff           call 0x4d3830
// 004d5b5e  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 004d5b62  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 004d5b66  ebc9                 jmp 0x4d5b31
// 004d5b68  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 004d5b6c  8938                 mov dword ptr [eax], edi
// 004d5b6e  5f                   pop edi
// 004d5b6f  5e                   pop esi
// 004d5b70  5d                   pop ebp
// 004d5b71  895804               mov dword ptr [eax + 4], ebx
// 004d5b74  5b                   pop ebx
// 004d5b75  83c408               add esp, 8
// 004d5b78  c21400               ret 0x14
// standard library set<ptr> (function ?erase@?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE?AViterator@12@V312@0@Z)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
