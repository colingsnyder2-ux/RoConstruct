// from server: 100% by auto
// roc 2007-08 005b3a60  unit: RBX::Assembly  size: 203 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 005b3a60
//
// 005b3a60  83ec08               sub esp, 8
// 005b3a63  53                   push ebx
// 005b3a64  55                   push ebp
// 005b3a65  56                   push esi
// 005b3a66  57                   push edi
// 005b3a67  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 005b3a6b  85ff                 test edi, edi
// 005b3a6d  8bf1                 mov esi, ecx
// 005b3a6f  8b4604               mov eax, dword ptr [esi + 4]
// 005b3a72  8b28                 mov ebp, dword ptr [eax]
// 005b3a74  7404                 je 0x5b3a7a
// 005b3a76  3bfe                 cmp edi, esi
// 005b3a78  7406                 je 0x5b3a80
// 005b3a7a  ff15d8e67700         call dword ptr [0x77e6d8]
// 005b3a80  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 005b3a84  3bdd                 cmp ebx, ebp
// 005b3a86  7559                 jne 0x5b3ae1
// 005b3a88  8b442428             mov eax, dword ptr [esp + 0x28]
// 005b3a8c  85c0                 test eax, eax
// 005b3a8e  8b6e04               mov ebp, dword ptr [esi + 4]
// 005b3a91  7404                 je 0x5b3a97
// 005b3a93  3bc6                 cmp eax, esi
// 005b3a95  7406                 je 0x5b3a9d
// 005b3a97  ff15d8e67700         call dword ptr [0x77e6d8]
// 005b3a9d  396c242c             cmp dword ptr [esp + 0x2c], ebp
// 005b3aa1  753e                 jne 0x5b3ae1
// 005b3aa3  8b4e04               mov ecx, dword ptr [esi + 4]
// 005b3aa6  8b5104               mov edx, dword ptr [ecx + 4]
// 005b3aa9  52                   push edx
// 005b3aaa  8bce                 mov ecx, esi
// 005b3aac  e82ff8ffff           call 0x5b32e0
// 005b3ab1  8b4604               mov eax, dword ptr [esi + 4]
// 005b3ab4  894004               mov dword ptr [eax + 4], eax
// 005b3ab7  8b4604               mov eax, dword ptr [esi + 4]
// 005b3aba  c7460800000000       mov dword ptr [esi + 8], 0
// 005b3ac1  8900                 mov dword ptr [eax], eax
// 005b3ac3  8b4604               mov eax, dword ptr [esi + 4]
// 005b3ac6  894008               mov dword ptr [eax + 8], eax
// 005b3ac9  8b4604               mov eax, dword ptr [esi + 4]
// 005b3acc  8b08                 mov ecx, dword ptr [eax]
// 005b3ace  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 005b3ad2  5f                   pop edi
// 005b3ad3  8930                 mov dword ptr [eax], esi
// 005b3ad5  5e                   pop esi
// 005b3ad6  5d                   pop ebp
// 005b3ad7  894804               mov dword ptr [eax + 4], ecx
// 005b3ada  5b                   pop ebx
// 005b3adb  83c408               add esp, 8
// 005b3ade  c21400               ret 0x14
// 005b3ae1  85ff                 test edi, edi
// 005b3ae3  7406                 je 0x5b3aeb
// 005b3ae5  3b7c2428             cmp edi, dword ptr [esp + 0x28]
// 005b3ae9  7406                 je 0x5b3af1
// 005b3aeb  ff15d8e67700         call dword ptr [0x77e6d8]
// 005b3af1  3b5c242c             cmp ebx, dword ptr [esp + 0x2c]
// 005b3af5  7421                 je 0x5b3b18
// 005b3af7  8d4c2420             lea ecx, [esp + 0x20]
// 005b3afb  e840370700           call 0x627240
// 005b3b00  53                   push ebx
// 005b3b01  57                   push edi
// 005b3b02  8d542418             lea edx, [esp + 0x18]
// 005b3b06  52                   push edx
// 005b3b07  8bce                 mov ecx, esi
// 005b3b09  e862f9ffff           call 0x5b3470
// 005b3b0e  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 005b3b12  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 005b3b16  ebc9                 jmp 0x5b3ae1
// 005b3b18  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 005b3b1c  8938                 mov dword ptr [eax], edi
// 005b3b1e  5f                   pop edi
// 005b3b1f  5e                   pop esi
// 005b3b20  5d                   pop ebp
// 005b3b21  895804               mov dword ptr [eax + 4], ebx
// 005b3b24  5b                   pop ebx
// 005b3b25  83c408               add esp, 8
// 005b3b28  c21400               ret 0x14
// standard library set<ptr> (function ?erase@?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE?AViterator@12@V312@0@Z)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
