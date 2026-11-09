// from server: 100% by auto
// roc 2007-08 004ad480  unit: RBX::Network::Replicator::DeleteInstanceItem  size: 203 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004ad480
//
// 004ad480  83ec08               sub esp, 8
// 004ad483  53                   push ebx
// 004ad484  55                   push ebp
// 004ad485  56                   push esi
// 004ad486  57                   push edi
// 004ad487  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 004ad48b  85ff                 test edi, edi
// 004ad48d  8bf1                 mov esi, ecx
// 004ad48f  8b4604               mov eax, dword ptr [esi + 4]
// 004ad492  8b28                 mov ebp, dword ptr [eax]
// 004ad494  7404                 je 0x4ad49a
// 004ad496  3bfe                 cmp edi, esi
// 004ad498  7406                 je 0x4ad4a0
// 004ad49a  ff15d8e67700         call dword ptr [0x77e6d8]
// 004ad4a0  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 004ad4a4  3bdd                 cmp ebx, ebp
// 004ad4a6  7559                 jne 0x4ad501
// 004ad4a8  8b442428             mov eax, dword ptr [esp + 0x28]
// 004ad4ac  85c0                 test eax, eax
// 004ad4ae  8b6e04               mov ebp, dword ptr [esi + 4]
// 004ad4b1  7404                 je 0x4ad4b7
// 004ad4b3  3bc6                 cmp eax, esi
// 004ad4b5  7406                 je 0x4ad4bd
// 004ad4b7  ff15d8e67700         call dword ptr [0x77e6d8]
// 004ad4bd  396c242c             cmp dword ptr [esp + 0x2c], ebp
// 004ad4c1  753e                 jne 0x4ad501
// 004ad4c3  8b4e04               mov ecx, dword ptr [esi + 4]
// 004ad4c6  8b5104               mov edx, dword ptr [ecx + 4]
// 004ad4c9  52                   push edx
// 004ad4ca  8bce                 mov ecx, esi
// 004ad4cc  e8ffe3ffff           call 0x4ab8d0
// 004ad4d1  8b4604               mov eax, dword ptr [esi + 4]
// 004ad4d4  894004               mov dword ptr [eax + 4], eax
// 004ad4d7  8b4604               mov eax, dword ptr [esi + 4]
// 004ad4da  c7460800000000       mov dword ptr [esi + 8], 0
// 004ad4e1  8900                 mov dword ptr [eax], eax
// 004ad4e3  8b4604               mov eax, dword ptr [esi + 4]
// 004ad4e6  894008               mov dword ptr [eax + 8], eax
// 004ad4e9  8b4604               mov eax, dword ptr [esi + 4]
// 004ad4ec  8b08                 mov ecx, dword ptr [eax]
// 004ad4ee  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 004ad4f2  5f                   pop edi
// 004ad4f3  8930                 mov dword ptr [eax], esi
// 004ad4f5  5e                   pop esi
// 004ad4f6  5d                   pop ebp
// 004ad4f7  894804               mov dword ptr [eax + 4], ecx
// 004ad4fa  5b                   pop ebx
// 004ad4fb  83c408               add esp, 8
// 004ad4fe  c21400               ret 0x14
// 004ad501  85ff                 test edi, edi
// 004ad503  7406                 je 0x4ad50b
// 004ad505  3b7c2428             cmp edi, dword ptr [esp + 0x28]
// 004ad509  7406                 je 0x4ad511
// 004ad50b  ff15d8e67700         call dword ptr [0x77e6d8]
// 004ad511  3b5c242c             cmp ebx, dword ptr [esp + 0x2c]
// 004ad515  7421                 je 0x4ad538
// 004ad517  8d4c2420             lea ecx, [esp + 0x20]
// 004ad51b  e8a0a70d00           call 0x587cc0
// 004ad520  53                   push ebx
// 004ad521  57                   push edi
// 004ad522  8d542418             lea edx, [esp + 0x18]
// 004ad526  52                   push edx
// 004ad527  8bce                 mov ecx, esi
// 004ad529  e8c2e0ffff           call 0x4ab5f0
// 004ad52e  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 004ad532  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 004ad536  ebc9                 jmp 0x4ad501
// 004ad538  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 004ad53c  8938                 mov dword ptr [eax], edi
// 004ad53e  5f                   pop edi
// 004ad53f  5e                   pop esi
// 004ad540  5d                   pop ebp
// 004ad541  895804               mov dword ptr [eax + 4], ebx
// 004ad544  5b                   pop ebx
// 004ad545  83c408               add esp, 8
// 004ad548  c21400               ret 0x14
// standard library set<ptr> (function ?erase@?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE?AViterator@12@V312@0@Z)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
