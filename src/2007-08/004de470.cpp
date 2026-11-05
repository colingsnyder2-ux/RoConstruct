// from server: 100% by auto
// roc 2007-08 004de470  unit: RBX::Render::Mesh::Level  size: 203 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004de470
//
// 004de470  83ec08               sub esp, 8
// 004de473  53                   push ebx
// 004de474  55                   push ebp
// 004de475  56                   push esi
// 004de476  57                   push edi
// 004de477  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 004de47b  85ff                 test edi, edi
// 004de47d  8bf1                 mov esi, ecx
// 004de47f  8b4604               mov eax, dword ptr [esi + 4]
// 004de482  8b28                 mov ebp, dword ptr [eax]
// 004de484  7404                 je 0x4de48a
// 004de486  3bfe                 cmp edi, esi
// 004de488  7406                 je 0x4de490
// 004de48a  ff15d8e67700         call dword ptr [0x77e6d8]
// 004de490  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 004de494  3bdd                 cmp ebx, ebp
// 004de496  7559                 jne 0x4de4f1
// 004de498  8b442428             mov eax, dword ptr [esp + 0x28]
// 004de49c  85c0                 test eax, eax
// 004de49e  8b6e04               mov ebp, dword ptr [esi + 4]
// 004de4a1  7404                 je 0x4de4a7
// 004de4a3  3bc6                 cmp eax, esi
// 004de4a5  7406                 je 0x4de4ad
// 004de4a7  ff15d8e67700         call dword ptr [0x77e6d8]
// 004de4ad  396c242c             cmp dword ptr [esp + 0x2c], ebp
// 004de4b1  753e                 jne 0x4de4f1
// 004de4b3  8b4e04               mov ecx, dword ptr [esi + 4]
// 004de4b6  8b5104               mov edx, dword ptr [ecx + 4]
// 004de4b9  52                   push edx
// 004de4ba  8bce                 mov ecx, esi
// 004de4bc  e8effbffff           call 0x4de0b0
// 004de4c1  8b4604               mov eax, dword ptr [esi + 4]
// 004de4c4  894004               mov dword ptr [eax + 4], eax
// 004de4c7  8b4604               mov eax, dword ptr [esi + 4]
// 004de4ca  c7460800000000       mov dword ptr [esi + 8], 0
// 004de4d1  8900                 mov dword ptr [eax], eax
// 004de4d3  8b4604               mov eax, dword ptr [esi + 4]
// 004de4d6  894008               mov dword ptr [eax + 8], eax
// 004de4d9  8b4604               mov eax, dword ptr [esi + 4]
// 004de4dc  8b08                 mov ecx, dword ptr [eax]
// 004de4de  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 004de4e2  5f                   pop edi
// 004de4e3  8930                 mov dword ptr [eax], esi
// 004de4e5  5e                   pop esi
// 004de4e6  5d                   pop ebp
// 004de4e7  894804               mov dword ptr [eax + 4], ecx
// 004de4ea  5b                   pop ebx
// 004de4eb  83c408               add esp, 8
// 004de4ee  c21400               ret 0x14
// 004de4f1  85ff                 test edi, edi
// 004de4f3  7406                 je 0x4de4fb
// 004de4f5  3b7c2428             cmp edi, dword ptr [esp + 0x28]
// 004de4f9  7406                 je 0x4de501
// 004de4fb  ff15d8e67700         call dword ptr [0x77e6d8]
// 004de501  3b5c242c             cmp ebx, dword ptr [esp + 0x2c]
// 004de505  7421                 je 0x4de528
// 004de507  8d4c2420             lea ecx, [esp + 0x20]
// 004de50b  e8d0950a00           call 0x587ae0
// 004de510  53                   push ebx
// 004de511  57                   push edi
// 004de512  8d542418             lea edx, [esp + 0x18]
// 004de516  52                   push edx
// 004de517  8bce                 mov ecx, esi
// 004de519  e8f2f0ffff           call 0x4dd610
// 004de51e  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 004de522  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 004de526  ebc9                 jmp 0x4de4f1
// 004de528  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 004de52c  8938                 mov dword ptr [eax], edi
// 004de52e  5f                   pop edi
// 004de52f  5e                   pop esi
// 004de530  5d                   pop ebp
// 004de531  895804               mov dword ptr [eax + 4], ebx
// 004de534  5b                   pop ebx
// 004de535  83c408               add esp, 8
// 004de538  c21400               ret 0x14
// standard library set<ptr> (function ?erase@?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE?AViterator@12@V312@0@Z)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
