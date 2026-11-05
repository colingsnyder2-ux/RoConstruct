// from server: 100% by auto
// roc 2007-08 00421d50  unit: CSelectionTreeCtrl  size: 203 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00421d50
//
// 00421d50  83ec08               sub esp, 8
// 00421d53  53                   push ebx
// 00421d54  55                   push ebp
// 00421d55  56                   push esi
// 00421d56  57                   push edi
// 00421d57  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00421d5b  85ff                 test edi, edi
// 00421d5d  8bf1                 mov esi, ecx
// 00421d5f  8b4604               mov eax, dword ptr [esi + 4]
// 00421d62  8b28                 mov ebp, dword ptr [eax]
// 00421d64  7404                 je 0x421d6a
// 00421d66  3bfe                 cmp edi, esi
// 00421d68  7406                 je 0x421d70
// 00421d6a  ff15d8e67700         call dword ptr [0x77e6d8]
// 00421d70  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 00421d74  3bdd                 cmp ebx, ebp
// 00421d76  7559                 jne 0x421dd1
// 00421d78  8b442428             mov eax, dword ptr [esp + 0x28]
// 00421d7c  85c0                 test eax, eax
// 00421d7e  8b6e04               mov ebp, dword ptr [esi + 4]
// 00421d81  7404                 je 0x421d87
// 00421d83  3bc6                 cmp eax, esi
// 00421d85  7406                 je 0x421d8d
// 00421d87  ff15d8e67700         call dword ptr [0x77e6d8]
// 00421d8d  396c242c             cmp dword ptr [esp + 0x2c], ebp
// 00421d91  753e                 jne 0x421dd1
// 00421d93  8b4e04               mov ecx, dword ptr [esi + 4]
// 00421d96  8b5104               mov edx, dword ptr [ecx + 4]
// 00421d99  52                   push edx
// 00421d9a  8bce                 mov ecx, esi
// 00421d9c  e8fff6ffff           call 0x4214a0
// 00421da1  8b4604               mov eax, dword ptr [esi + 4]
// 00421da4  894004               mov dword ptr [eax + 4], eax
// 00421da7  8b4604               mov eax, dword ptr [esi + 4]
// 00421daa  c7460800000000       mov dword ptr [esi + 8], 0
// 00421db1  8900                 mov dword ptr [eax], eax
// 00421db3  8b4604               mov eax, dword ptr [esi + 4]
// 00421db6  894008               mov dword ptr [eax + 8], eax
// 00421db9  8b4604               mov eax, dword ptr [esi + 4]
// 00421dbc  8b08                 mov ecx, dword ptr [eax]
// 00421dbe  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00421dc2  5f                   pop edi
// 00421dc3  8930                 mov dword ptr [eax], esi
// 00421dc5  5e                   pop esi
// 00421dc6  5d                   pop ebp
// 00421dc7  894804               mov dword ptr [eax + 4], ecx
// 00421dca  5b                   pop ebx
// 00421dcb  83c408               add esp, 8
// 00421dce  c21400               ret 0x14
// 00421dd1  85ff                 test edi, edi
// 00421dd3  7406                 je 0x421ddb
// 00421dd5  3b7c2428             cmp edi, dword ptr [esp + 0x28]
// 00421dd9  7406                 je 0x421de1
// 00421ddb  ff15d8e67700         call dword ptr [0x77e6d8]
// 00421de1  3b5c242c             cmp ebx, dword ptr [esp + 0x2c]
// 00421de5  7421                 je 0x421e08
// 00421de7  8d4c2420             lea ecx, [esp + 0x20]
// 00421deb  e8c0700100           call 0x438eb0
// 00421df0  53                   push ebx
// 00421df1  57                   push edi
// 00421df2  8d542418             lea edx, [esp + 0x18]
// 00421df6  52                   push edx
// 00421df7  8bce                 mov ecx, esi
// 00421df9  e802f9ffff           call 0x421700
// 00421dfe  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 00421e02  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00421e06  ebc9                 jmp 0x421dd1
// 00421e08  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00421e0c  8938                 mov dword ptr [eax], edi
// 00421e0e  5f                   pop edi
// 00421e0f  5e                   pop esi
// 00421e10  5d                   pop ebp
// 00421e11  895804               mov dword ptr [eax + 4], ebx
// 00421e14  5b                   pop ebx
// 00421e15  83c408               add esp, 8
// 00421e18  c21400               ret 0x14
// standard library set<ptr> (function ?erase@?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE?AViterator@12@V312@0@Z)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
