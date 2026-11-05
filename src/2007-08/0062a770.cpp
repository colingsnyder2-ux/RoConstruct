// from server: 100% by auto
// roc 2007-08 0062a770  unit: RBX::AssemblyStage  size: 203 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0062a770
//
// 0062a770  83ec08               sub esp, 8
// 0062a773  53                   push ebx
// 0062a774  55                   push ebp
// 0062a775  56                   push esi
// 0062a776  57                   push edi
// 0062a777  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 0062a77b  85ff                 test edi, edi
// 0062a77d  8bf1                 mov esi, ecx
// 0062a77f  8b4604               mov eax, dword ptr [esi + 4]
// 0062a782  8b28                 mov ebp, dword ptr [eax]
// 0062a784  7404                 je 0x62a78a
// 0062a786  3bfe                 cmp edi, esi
// 0062a788  7406                 je 0x62a790
// 0062a78a  ff15d8e67700         call dword ptr [0x77e6d8]
// 0062a790  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 0062a794  3bdd                 cmp ebx, ebp
// 0062a796  7559                 jne 0x62a7f1
// 0062a798  8b442428             mov eax, dword ptr [esp + 0x28]
// 0062a79c  85c0                 test eax, eax
// 0062a79e  8b6e04               mov ebp, dword ptr [esi + 4]
// 0062a7a1  7404                 je 0x62a7a7
// 0062a7a3  3bc6                 cmp eax, esi
// 0062a7a5  7406                 je 0x62a7ad
// 0062a7a7  ff15d8e67700         call dword ptr [0x77e6d8]
// 0062a7ad  396c242c             cmp dword ptr [esp + 0x2c], ebp
// 0062a7b1  753e                 jne 0x62a7f1
// 0062a7b3  8b4e04               mov ecx, dword ptr [esi + 4]
// 0062a7b6  8b5104               mov edx, dword ptr [ecx + 4]
// 0062a7b9  52                   push edx
// 0062a7ba  8bce                 mov ecx, esi
// 0062a7bc  e8affeffff           call 0x62a670
// 0062a7c1  8b4604               mov eax, dword ptr [esi + 4]
// 0062a7c4  894004               mov dword ptr [eax + 4], eax
// 0062a7c7  8b4604               mov eax, dword ptr [esi + 4]
// 0062a7ca  c7460800000000       mov dword ptr [esi + 8], 0
// 0062a7d1  8900                 mov dword ptr [eax], eax
// 0062a7d3  8b4604               mov eax, dword ptr [esi + 4]
// 0062a7d6  894008               mov dword ptr [eax + 8], eax
// 0062a7d9  8b4604               mov eax, dword ptr [esi + 4]
// 0062a7dc  8b08                 mov ecx, dword ptr [eax]
// 0062a7de  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0062a7e2  5f                   pop edi
// 0062a7e3  8930                 mov dword ptr [eax], esi
// 0062a7e5  5e                   pop esi
// 0062a7e6  5d                   pop ebp
// 0062a7e7  894804               mov dword ptr [eax + 4], ecx
// 0062a7ea  5b                   pop ebx
// 0062a7eb  83c408               add esp, 8
// 0062a7ee  c21400               ret 0x14
// 0062a7f1  85ff                 test edi, edi
// 0062a7f3  7406                 je 0x62a7fb
// 0062a7f5  3b7c2428             cmp edi, dword ptr [esp + 0x28]
// 0062a7f9  7406                 je 0x62a801
// 0062a7fb  ff15d8e67700         call dword ptr [0x77e6d8]
// 0062a801  3b5c242c             cmp ebx, dword ptr [esp + 0x2c]
// 0062a805  7421                 je 0x62a828
// 0062a807  8d4c2420             lea ecx, [esp + 0x20]
// 0062a80b  e8d060eaff           call 0x4d08e0
// 0062a810  53                   push ebx
// 0062a811  57                   push edi
// 0062a812  8d542418             lea edx, [esp + 0x18]
// 0062a816  52                   push edx
// 0062a817  8bce                 mov ecx, esi
// 0062a819  e882fbffff           call 0x62a3a0
// 0062a81e  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 0062a822  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 0062a826  ebc9                 jmp 0x62a7f1
// 0062a828  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0062a82c  8938                 mov dword ptr [eax], edi
// 0062a82e  5f                   pop edi
// 0062a82f  5e                   pop esi
// 0062a830  5d                   pop ebp
// 0062a831  895804               mov dword ptr [eax + 4], ebx
// 0062a834  5b                   pop ebx
// 0062a835  83c408               add esp, 8
// 0062a838  c21400               ret 0x14
// standard library set<ptr> (function ?erase@?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE?AViterator@12@V312@0@Z)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
