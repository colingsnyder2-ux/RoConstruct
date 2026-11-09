// from server: 100% by auto
// roc 2007-08 004aae90  unit: RBX::Network::Peer  size: 203 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004aae90
//
// 004aae90  83ec08               sub esp, 8
// 004aae93  53                   push ebx
// 004aae94  55                   push ebp
// 004aae95  56                   push esi
// 004aae96  57                   push edi
// 004aae97  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 004aae9b  85ff                 test edi, edi
// 004aae9d  8bf1                 mov esi, ecx
// 004aae9f  8b4604               mov eax, dword ptr [esi + 4]
// 004aaea2  8b28                 mov ebp, dword ptr [eax]
// 004aaea4  7404                 je 0x4aaeaa
// 004aaea6  3bfe                 cmp edi, esi
// 004aaea8  7406                 je 0x4aaeb0
// 004aaeaa  ff15d8e67700         call dword ptr [0x77e6d8]
// 004aaeb0  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 004aaeb4  3bdd                 cmp ebx, ebp
// 004aaeb6  7559                 jne 0x4aaf11
// 004aaeb8  8b442428             mov eax, dword ptr [esp + 0x28]
// 004aaebc  85c0                 test eax, eax
// 004aaebe  8b6e04               mov ebp, dword ptr [esi + 4]
// 004aaec1  7404                 je 0x4aaec7
// 004aaec3  3bc6                 cmp eax, esi
// 004aaec5  7406                 je 0x4aaecd
// 004aaec7  ff15d8e67700         call dword ptr [0x77e6d8]
// 004aaecd  396c242c             cmp dword ptr [esp + 0x2c], ebp
// 004aaed1  753e                 jne 0x4aaf11
// 004aaed3  8b4e04               mov ecx, dword ptr [esi + 4]
// 004aaed6  8b5104               mov edx, dword ptr [ecx + 4]
// 004aaed9  52                   push edx
// 004aaeda  8bce                 mov ecx, esi
// 004aaedc  e8ffe8ffff           call 0x4a97e0
// 004aaee1  8b4604               mov eax, dword ptr [esi + 4]
// 004aaee4  894004               mov dword ptr [eax + 4], eax
// 004aaee7  8b4604               mov eax, dword ptr [esi + 4]
// 004aaeea  c7460800000000       mov dword ptr [esi + 8], 0
// 004aaef1  8900                 mov dword ptr [eax], eax
// 004aaef3  8b4604               mov eax, dword ptr [esi + 4]
// 004aaef6  894008               mov dword ptr [eax + 8], eax
// 004aaef9  8b4604               mov eax, dword ptr [esi + 4]
// 004aaefc  8b08                 mov ecx, dword ptr [eax]
// 004aaefe  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 004aaf02  5f                   pop edi
// 004aaf03  8930                 mov dword ptr [eax], esi
// 004aaf05  5e                   pop esi
// 004aaf06  5d                   pop ebp
// 004aaf07  894804               mov dword ptr [eax + 4], ecx
// 004aaf0a  5b                   pop ebx
// 004aaf0b  83c408               add esp, 8
// 004aaf0e  c21400               ret 0x14
// 004aaf11  85ff                 test edi, edi
// 004aaf13  7406                 je 0x4aaf1b
// 004aaf15  3b7c2428             cmp edi, dword ptr [esp + 0x28]
// 004aaf19  7406                 je 0x4aaf21
// 004aaf1b  ff15d8e67700         call dword ptr [0x77e6d8]
// 004aaf21  3b5c242c             cmp ebx, dword ptr [esp + 0x2c]
// 004aaf25  7421                 je 0x4aaf48
// 004aaf27  8d4c2420             lea ecx, [esp + 0x20]
// 004aaf2b  e880dff8ff           call 0x438eb0
// 004aaf30  53                   push ebx
// 004aaf31  57                   push edi
// 004aaf32  8d542418             lea edx, [esp + 0x18]
// 004aaf36  52                   push edx
// 004aaf37  8bce                 mov ecx, esi
// 004aaf39  e862ebffff           call 0x4a9aa0
// 004aaf3e  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 004aaf42  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 004aaf46  ebc9                 jmp 0x4aaf11
// 004aaf48  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 004aaf4c  8938                 mov dword ptr [eax], edi
// 004aaf4e  5f                   pop edi
// 004aaf4f  5e                   pop esi
// 004aaf50  5d                   pop ebp
// 004aaf51  895804               mov dword ptr [eax + 4], ebx
// 004aaf54  5b                   pop ebx
// 004aaf55  83c408               add esp, 8
// 004aaf58  c21400               ret 0x14
// standard library set<ptr> (function ?erase@?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE?AViterator@12@V312@0@Z)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
