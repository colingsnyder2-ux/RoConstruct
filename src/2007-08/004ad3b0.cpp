// from server: 100% by auto
// roc 2007-08 004ad3b0  unit: RBX::Network::Replicator::DeleteInstanceItem  size: 203 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004ad3b0
//
// 004ad3b0  83ec08               sub esp, 8
// 004ad3b3  53                   push ebx
// 004ad3b4  55                   push ebp
// 004ad3b5  56                   push esi
// 004ad3b6  57                   push edi
// 004ad3b7  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 004ad3bb  85ff                 test edi, edi
// 004ad3bd  8bf1                 mov esi, ecx
// 004ad3bf  8b4604               mov eax, dword ptr [esi + 4]
// 004ad3c2  8b28                 mov ebp, dword ptr [eax]
// 004ad3c4  7404                 je 0x4ad3ca
// 004ad3c6  3bfe                 cmp edi, esi
// 004ad3c8  7406                 je 0x4ad3d0
// 004ad3ca  ff15d8e67700         call dword ptr [0x77e6d8]
// 004ad3d0  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 004ad3d4  3bdd                 cmp ebx, ebp
// 004ad3d6  7559                 jne 0x4ad431
// 004ad3d8  8b442428             mov eax, dword ptr [esp + 0x28]
// 004ad3dc  85c0                 test eax, eax
// 004ad3de  8b6e04               mov ebp, dword ptr [esi + 4]
// 004ad3e1  7404                 je 0x4ad3e7
// 004ad3e3  3bc6                 cmp eax, esi
// 004ad3e5  7406                 je 0x4ad3ed
// 004ad3e7  ff15d8e67700         call dword ptr [0x77e6d8]
// 004ad3ed  396c242c             cmp dword ptr [esp + 0x2c], ebp
// 004ad3f1  753e                 jne 0x4ad431
// 004ad3f3  8b4e04               mov ecx, dword ptr [esi + 4]
// 004ad3f6  8b5104               mov edx, dword ptr [ecx + 4]
// 004ad3f9  52                   push edx
// 004ad3fa  8bce                 mov ecx, esi
// 004ad3fc  e8ff720d00           call 0x584700
// 004ad401  8b4604               mov eax, dword ptr [esi + 4]
// 004ad404  894004               mov dword ptr [eax + 4], eax
// 004ad407  8b4604               mov eax, dword ptr [esi + 4]
// 004ad40a  c7460800000000       mov dword ptr [esi + 8], 0
// 004ad411  8900                 mov dword ptr [eax], eax
// 004ad413  8b4604               mov eax, dword ptr [esi + 4]
// 004ad416  894008               mov dword ptr [eax + 8], eax
// 004ad419  8b4604               mov eax, dword ptr [esi + 4]
// 004ad41c  8b08                 mov ecx, dword ptr [eax]
// 004ad41e  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 004ad422  5f                   pop edi
// 004ad423  8930                 mov dword ptr [eax], esi
// 004ad425  5e                   pop esi
// 004ad426  5d                   pop ebp
// 004ad427  894804               mov dword ptr [eax + 4], ecx
// 004ad42a  5b                   pop ebx
// 004ad42b  83c408               add esp, 8
// 004ad42e  c21400               ret 0x14
// 004ad431  85ff                 test edi, edi
// 004ad433  7406                 je 0x4ad43b
// 004ad435  3b7c2428             cmp edi, dword ptr [esp + 0x28]
// 004ad439  7406                 je 0x4ad441
// 004ad43b  ff15d8e67700         call dword ptr [0x77e6d8]
// 004ad441  3b5c242c             cmp ebx, dword ptr [esp + 0x2c]
// 004ad445  7421                 je 0x4ad468
// 004ad447  8d4c2420             lea ecx, [esp + 0x20]
// 004ad44b  e8d0ca1200           call 0x5d9f20
// 004ad450  53                   push ebx
// 004ad451  57                   push edi
// 004ad452  8d542418             lea edx, [esp + 0x18]
// 004ad456  52                   push edx
// 004ad457  8bce                 mov ecx, esi
// 004ad459  e8d2deffff           call 0x4ab330
// 004ad45e  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 004ad462  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 004ad466  ebc9                 jmp 0x4ad431
// 004ad468  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 004ad46c  8938                 mov dword ptr [eax], edi
// 004ad46e  5f                   pop edi
// 004ad46f  5e                   pop esi
// 004ad470  5d                   pop ebp
// 004ad471  895804               mov dword ptr [eax + 4], ebx
// 004ad474  5b                   pop ebx
// 004ad475  83c408               add esp, 8
// 004ad478  c21400               ret 0x14
// standard library set<ptr> (function ?erase@?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE?AViterator@12@V312@0@Z)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
