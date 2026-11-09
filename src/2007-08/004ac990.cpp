// from server: 100% by auto
// roc 2007-08 004ac990  unit: RBX::Network::Replicator::DeleteInstanceItem  size: 203 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004ac990
//
// 004ac990  83ec08               sub esp, 8
// 004ac993  53                   push ebx
// 004ac994  55                   push ebp
// 004ac995  56                   push esi
// 004ac996  57                   push edi
// 004ac997  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 004ac99b  85ff                 test edi, edi
// 004ac99d  8bf1                 mov esi, ecx
// 004ac99f  8b4604               mov eax, dword ptr [esi + 4]
// 004ac9a2  8b28                 mov ebp, dword ptr [eax]
// 004ac9a4  7404                 je 0x4ac9aa
// 004ac9a6  3bfe                 cmp edi, esi
// 004ac9a8  7406                 je 0x4ac9b0
// 004ac9aa  ff15d8e67700         call dword ptr [0x77e6d8]
// 004ac9b0  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 004ac9b4  3bdd                 cmp ebx, ebp
// 004ac9b6  7559                 jne 0x4aca11
// 004ac9b8  8b442428             mov eax, dword ptr [esp + 0x28]
// 004ac9bc  85c0                 test eax, eax
// 004ac9be  8b6e04               mov ebp, dword ptr [esi + 4]
// 004ac9c1  7404                 je 0x4ac9c7
// 004ac9c3  3bc6                 cmp eax, esi
// 004ac9c5  7406                 je 0x4ac9cd
// 004ac9c7  ff15d8e67700         call dword ptr [0x77e6d8]
// 004ac9cd  396c242c             cmp dword ptr [esp + 0x2c], ebp
// 004ac9d1  753e                 jne 0x4aca11
// 004ac9d3  8b4e04               mov ecx, dword ptr [esi + 4]
// 004ac9d6  8b5104               mov edx, dword ptr [ecx + 4]
// 004ac9d9  52                   push edx
// 004ac9da  8bce                 mov ecx, esi
// 004ac9dc  e87fd5ffff           call 0x4a9f60
// 004ac9e1  8b4604               mov eax, dword ptr [esi + 4]
// 004ac9e4  894004               mov dword ptr [eax + 4], eax
// 004ac9e7  8b4604               mov eax, dword ptr [esi + 4]
// 004ac9ea  c7460800000000       mov dword ptr [esi + 8], 0
// 004ac9f1  8900                 mov dword ptr [eax], eax
// 004ac9f3  8b4604               mov eax, dword ptr [esi + 4]
// 004ac9f6  894008               mov dword ptr [eax + 8], eax
// 004ac9f9  8b4604               mov eax, dword ptr [esi + 4]
// 004ac9fc  8b08                 mov ecx, dword ptr [eax]
// 004ac9fe  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 004aca02  5f                   pop edi
// 004aca03  8930                 mov dword ptr [eax], esi
// 004aca05  5e                   pop esi
// 004aca06  5d                   pop ebp
// 004aca07  894804               mov dword ptr [eax + 4], ecx
// 004aca0a  5b                   pop ebx
// 004aca0b  83c408               add esp, 8
// 004aca0e  c21400               ret 0x14
// 004aca11  85ff                 test edi, edi
// 004aca13  7406                 je 0x4aca1b
// 004aca15  3b7c2428             cmp edi, dword ptr [esp + 0x28]
// 004aca19  7406                 je 0x4aca21
// 004aca1b  ff15d8e67700         call dword ptr [0x77e6d8]
// 004aca21  3b5c242c             cmp ebx, dword ptr [esp + 0x2c]
// 004aca25  7421                 je 0x4aca48
// 004aca27  8d4c2420             lea ecx, [esp + 0x20]
// 004aca2b  e86087ffff           call 0x4a5190
// 004aca30  53                   push ebx
// 004aca31  57                   push edi
// 004aca32  8d542418             lea edx, [esp + 0x18]
// 004aca36  52                   push edx
// 004aca37  8bce                 mov ecx, esi
// 004aca39  e842e0ffff           call 0x4aaa80
// 004aca3e  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 004aca42  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 004aca46  ebc9                 jmp 0x4aca11
// 004aca48  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 004aca4c  8938                 mov dword ptr [eax], edi
// 004aca4e  5f                   pop edi
// 004aca4f  5e                   pop esi
// 004aca50  5d                   pop ebp
// 004aca51  895804               mov dword ptr [eax + 4], ebx
// 004aca54  5b                   pop ebx
// 004aca55  83c408               add esp, 8
// 004aca58  c21400               ret 0x14
// standard library set<ptr> (function ?erase@?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE?AViterator@12@V312@0@Z)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
