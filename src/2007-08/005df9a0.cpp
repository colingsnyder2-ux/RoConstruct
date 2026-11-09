// from server: 100% by auto
// roc 2007-08 005df9a0  unit: RBX::VMotorFeature::?$FactoryProduct  size: 203 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 005df9a0
//
// 005df9a0  83ec08               sub esp, 8
// 005df9a3  53                   push ebx
// 005df9a4  55                   push ebp
// 005df9a5  56                   push esi
// 005df9a6  57                   push edi
// 005df9a7  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 005df9ab  85ff                 test edi, edi
// 005df9ad  8bf1                 mov esi, ecx
// 005df9af  8b4604               mov eax, dword ptr [esi + 4]
// 005df9b2  8b28                 mov ebp, dword ptr [eax]
// 005df9b4  7404                 je 0x5df9ba
// 005df9b6  3bfe                 cmp edi, esi
// 005df9b8  7406                 je 0x5df9c0
// 005df9ba  ff15d8e67700         call dword ptr [0x77e6d8]
// 005df9c0  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 005df9c4  3bdd                 cmp ebx, ebp
// 005df9c6  7559                 jne 0x5dfa21
// 005df9c8  8b442428             mov eax, dword ptr [esp + 0x28]
// 005df9cc  85c0                 test eax, eax
// 005df9ce  8b6e04               mov ebp, dword ptr [esi + 4]
// 005df9d1  7404                 je 0x5df9d7
// 005df9d3  3bc6                 cmp eax, esi
// 005df9d5  7406                 je 0x5df9dd
// 005df9d7  ff15d8e67700         call dword ptr [0x77e6d8]
// 005df9dd  396c242c             cmp dword ptr [esp + 0x2c], ebp
// 005df9e1  753e                 jne 0x5dfa21
// 005df9e3  8b4e04               mov ecx, dword ptr [esi + 4]
// 005df9e6  8b5104               mov edx, dword ptr [ecx + 4]
// 005df9e9  52                   push edx
// 005df9ea  8bce                 mov ecx, esi
// 005df9ec  e8bff3ffff           call 0x5dedb0
// 005df9f1  8b4604               mov eax, dword ptr [esi + 4]
// 005df9f4  894004               mov dword ptr [eax + 4], eax
// 005df9f7  8b4604               mov eax, dword ptr [esi + 4]
// 005df9fa  c7460800000000       mov dword ptr [esi + 8], 0
// 005dfa01  8900                 mov dword ptr [eax], eax
// 005dfa03  8b4604               mov eax, dword ptr [esi + 4]
// 005dfa06  894008               mov dword ptr [eax + 8], eax
// 005dfa09  8b4604               mov eax, dword ptr [esi + 4]
// 005dfa0c  8b08                 mov ecx, dword ptr [eax]
// 005dfa0e  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 005dfa12  5f                   pop edi
// 005dfa13  8930                 mov dword ptr [eax], esi
// 005dfa15  5e                   pop esi
// 005dfa16  5d                   pop ebp
// 005dfa17  894804               mov dword ptr [eax + 4], ecx
// 005dfa1a  5b                   pop ebx
// 005dfa1b  83c408               add esp, 8
// 005dfa1e  c21400               ret 0x14
// 005dfa21  85ff                 test edi, edi
// 005dfa23  7406                 je 0x5dfa2b
// 005dfa25  3b7c2428             cmp edi, dword ptr [esp + 0x28]
// 005dfa29  7406                 je 0x5dfa31
// 005dfa2b  ff15d8e67700         call dword ptr [0x77e6d8]
// 005dfa31  3b5c242c             cmp ebx, dword ptr [esp + 0x2c]
// 005dfa35  7421                 je 0x5dfa58
// 005dfa37  8d4c2420             lea ecx, [esp + 0x20]
// 005dfa3b  e88082faff           call 0x587cc0
// 005dfa40  53                   push ebx
// 005dfa41  57                   push edi
// 005dfa42  8d542418             lea edx, [esp + 0x18]
// 005dfa46  52                   push edx
// 005dfa47  8bce                 mov ecx, esi
// 005dfa49  e872f8ffff           call 0x5df2c0
// 005dfa4e  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 005dfa52  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 005dfa56  ebc9                 jmp 0x5dfa21
// 005dfa58  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 005dfa5c  8938                 mov dword ptr [eax], edi
// 005dfa5e  5f                   pop edi
// 005dfa5f  5e                   pop esi
// 005dfa60  5d                   pop ebp
// 005dfa61  895804               mov dword ptr [eax + 4], ebx
// 005dfa64  5b                   pop ebx
// 005dfa65  83c408               add esp, 8
// 005dfa68  c21400               ret 0x14
// standard library set<ptr> (function ?erase@?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE?AViterator@12@V312@0@Z)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
