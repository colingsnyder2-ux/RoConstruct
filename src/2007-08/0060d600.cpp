// from server: 100% by auto
// roc 2007-08 0060d600  unit: RBX::Block  size: 203 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0060d600
//
// 0060d600  83ec08               sub esp, 8
// 0060d603  53                   push ebx
// 0060d604  55                   push ebp
// 0060d605  56                   push esi
// 0060d606  57                   push edi
// 0060d607  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 0060d60b  85ff                 test edi, edi
// 0060d60d  8bf1                 mov esi, ecx
// 0060d60f  8b4604               mov eax, dword ptr [esi + 4]
// 0060d612  8b28                 mov ebp, dword ptr [eax]
// 0060d614  7404                 je 0x60d61a
// 0060d616  3bfe                 cmp edi, esi
// 0060d618  7406                 je 0x60d620
// 0060d61a  ff15d8e67700         call dword ptr [0x77e6d8]
// 0060d620  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 0060d624  3bdd                 cmp ebx, ebp
// 0060d626  7559                 jne 0x60d681
// 0060d628  8b442428             mov eax, dword ptr [esp + 0x28]
// 0060d62c  85c0                 test eax, eax
// 0060d62e  8b6e04               mov ebp, dword ptr [esi + 4]
// 0060d631  7404                 je 0x60d637
// 0060d633  3bc6                 cmp eax, esi
// 0060d635  7406                 je 0x60d63d
// 0060d637  ff15d8e67700         call dword ptr [0x77e6d8]
// 0060d63d  396c242c             cmp dword ptr [esp + 0x2c], ebp
// 0060d641  753e                 jne 0x60d681
// 0060d643  8b4e04               mov ecx, dword ptr [esi + 4]
// 0060d646  8b5104               mov edx, dword ptr [ecx + 4]
// 0060d649  52                   push edx
// 0060d64a  8bce                 mov ecx, esi
// 0060d64c  e83ff9ffff           call 0x60cf90
// 0060d651  8b4604               mov eax, dword ptr [esi + 4]
// 0060d654  894004               mov dword ptr [eax + 4], eax
// 0060d657  8b4604               mov eax, dword ptr [esi + 4]
// 0060d65a  c7460800000000       mov dword ptr [esi + 8], 0
// 0060d661  8900                 mov dword ptr [eax], eax
// 0060d663  8b4604               mov eax, dword ptr [esi + 4]
// 0060d666  894008               mov dword ptr [eax + 8], eax
// 0060d669  8b4604               mov eax, dword ptr [esi + 4]
// 0060d66c  8b08                 mov ecx, dword ptr [eax]
// 0060d66e  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0060d672  5f                   pop edi
// 0060d673  8930                 mov dword ptr [eax], esi
// 0060d675  5e                   pop esi
// 0060d676  5d                   pop ebp
// 0060d677  894804               mov dword ptr [eax + 4], ecx
// 0060d67a  5b                   pop ebx
// 0060d67b  83c408               add esp, 8
// 0060d67e  c21400               ret 0x14
// 0060d681  85ff                 test edi, edi
// 0060d683  7406                 je 0x60d68b
// 0060d685  3b7c2428             cmp edi, dword ptr [esp + 0x28]
// 0060d689  7406                 je 0x60d691
// 0060d68b  ff15d8e67700         call dword ptr [0x77e6d8]
// 0060d691  3b5c242c             cmp ebx, dword ptr [esp + 0x2c]
// 0060d695  7421                 je 0x60d6b8
// 0060d697  8d4c2420             lea ecx, [esp + 0x20]
// 0060d69b  e8e0f6ffff           call 0x60cd80
// 0060d6a0  53                   push ebx
// 0060d6a1  57                   push edi
// 0060d6a2  8d542418             lea edx, [esp + 0x18]
// 0060d6a6  52                   push edx
// 0060d6a7  8bce                 mov ecx, esi
// 0060d6a9  e822fbffff           call 0x60d1d0
// 0060d6ae  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 0060d6b2  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 0060d6b6  ebc9                 jmp 0x60d681
// 0060d6b8  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0060d6bc  8938                 mov dword ptr [eax], edi
// 0060d6be  5f                   pop edi
// 0060d6bf  5e                   pop esi
// 0060d6c0  5d                   pop ebp
// 0060d6c1  895804               mov dword ptr [eax + 4], ebx
// 0060d6c4  5b                   pop ebx
// 0060d6c5  83c408               add esp, 8
// 0060d6c8  c21400               ret 0x14
// standard library set<ptr> (function ?erase@?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE?AViterator@12@V312@0@Z)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
