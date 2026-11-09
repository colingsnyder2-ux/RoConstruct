// from server: 100% by auto
// roc 2007-08 00543460  unit: RBX::VDebugSettings::?$FactoryProduct  size: 203 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00543460
//
// 00543460  83ec08               sub esp, 8
// 00543463  53                   push ebx
// 00543464  55                   push ebp
// 00543465  56                   push esi
// 00543466  57                   push edi
// 00543467  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 0054346b  85ff                 test edi, edi
// 0054346d  8bf1                 mov esi, ecx
// 0054346f  8b4604               mov eax, dword ptr [esi + 4]
// 00543472  8b28                 mov ebp, dword ptr [eax]
// 00543474  7404                 je 0x54347a
// 00543476  3bfe                 cmp edi, esi
// 00543478  7406                 je 0x543480
// 0054347a  ff15d8e67700         call dword ptr [0x77e6d8]
// 00543480  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 00543484  3bdd                 cmp ebx, ebp
// 00543486  7559                 jne 0x5434e1
// 00543488  8b442428             mov eax, dword ptr [esp + 0x28]
// 0054348c  85c0                 test eax, eax
// 0054348e  8b6e04               mov ebp, dword ptr [esi + 4]
// 00543491  7404                 je 0x543497
// 00543493  3bc6                 cmp eax, esi
// 00543495  7406                 je 0x54349d
// 00543497  ff15d8e67700         call dword ptr [0x77e6d8]
// 0054349d  396c242c             cmp dword ptr [esp + 0x2c], ebp
// 005434a1  753e                 jne 0x5434e1
// 005434a3  8b4e04               mov ecx, dword ptr [esi + 4]
// 005434a6  8b5104               mov edx, dword ptr [ecx + 4]
// 005434a9  52                   push edx
// 005434aa  8bce                 mov ecx, esi
// 005434ac  e8cf62f2ff           call 0x469780
// 005434b1  8b4604               mov eax, dword ptr [esi + 4]
// 005434b4  894004               mov dword ptr [eax + 4], eax
// 005434b7  8b4604               mov eax, dword ptr [esi + 4]
// 005434ba  c7460800000000       mov dword ptr [esi + 8], 0
// 005434c1  8900                 mov dword ptr [eax], eax
// 005434c3  8b4604               mov eax, dword ptr [esi + 4]
// 005434c6  894008               mov dword ptr [eax + 8], eax
// 005434c9  8b4604               mov eax, dword ptr [esi + 4]
// 005434cc  8b08                 mov ecx, dword ptr [eax]
// 005434ce  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 005434d2  5f                   pop edi
// 005434d3  8930                 mov dword ptr [eax], esi
// 005434d5  5e                   pop esi
// 005434d6  5d                   pop ebp
// 005434d7  894804               mov dword ptr [eax + 4], ecx
// 005434da  5b                   pop ebx
// 005434db  83c408               add esp, 8
// 005434de  c21400               ret 0x14
// 005434e1  85ff                 test edi, edi
// 005434e3  7406                 je 0x5434eb
// 005434e5  3b7c2428             cmp edi, dword ptr [esp + 0x28]
// 005434e9  7406                 je 0x5434f1
// 005434eb  ff15d8e67700         call dword ptr [0x77e6d8]
// 005434f1  3b5c242c             cmp ebx, dword ptr [esp + 0x2c]
// 005434f5  7421                 je 0x543518
// 005434f7  8d4c2420             lea ecx, [esp + 0x20]
// 005434fb  e8206a0900           call 0x5d9f20
// 00543500  53                   push ebx
// 00543501  57                   push edi
// 00543502  8d542418             lea edx, [esp + 0x18]
// 00543506  52                   push edx
// 00543507  8bce                 mov ecx, esi
// 00543509  e882fcffff           call 0x543190
// 0054350e  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 00543512  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00543516  ebc9                 jmp 0x5434e1
// 00543518  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0054351c  8938                 mov dword ptr [eax], edi
// 0054351e  5f                   pop edi
// 0054351f  5e                   pop esi
// 00543520  5d                   pop ebp
// 00543521  895804               mov dword ptr [eax + 4], ebx
// 00543524  5b                   pop ebx
// 00543525  83c408               add esp, 8
// 00543528  c21400               ret 0x14
// standard library set<ptr> (function ?erase@?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE?AViterator@12@V312@0@Z)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
