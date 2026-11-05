// from server: 100% by auto
// roc 2007-08 004893c0  unit: RBX::Network::VPlayer::?$FactoryProduct  size: 203 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004893c0
//
// 004893c0  83ec08               sub esp, 8
// 004893c3  53                   push ebx
// 004893c4  55                   push ebp
// 004893c5  56                   push esi
// 004893c6  57                   push edi
// 004893c7  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 004893cb  85ff                 test edi, edi
// 004893cd  8bf1                 mov esi, ecx
// 004893cf  8b4604               mov eax, dword ptr [esi + 4]
// 004893d2  8b28                 mov ebp, dword ptr [eax]
// 004893d4  7404                 je 0x4893da
// 004893d6  3bfe                 cmp edi, esi
// 004893d8  7406                 je 0x4893e0
// 004893da  ff15d8e67700         call dword ptr [0x77e6d8]
// 004893e0  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 004893e4  3bdd                 cmp ebx, ebp
// 004893e6  7559                 jne 0x489441
// 004893e8  8b442428             mov eax, dword ptr [esp + 0x28]
// 004893ec  85c0                 test eax, eax
// 004893ee  8b6e04               mov ebp, dword ptr [esi + 4]
// 004893f1  7404                 je 0x4893f7
// 004893f3  3bc6                 cmp eax, esi
// 004893f5  7406                 je 0x4893fd
// 004893f7  ff15d8e67700         call dword ptr [0x77e6d8]
// 004893fd  396c242c             cmp dword ptr [esp + 0x2c], ebp
// 00489401  753e                 jne 0x489441
// 00489403  8b4e04               mov ecx, dword ptr [esi + 4]
// 00489406  8b5104               mov edx, dword ptr [ecx + 4]
// 00489409  52                   push edx
// 0048940a  8bce                 mov ecx, esi
// 0048940c  e86fe8ffff           call 0x487c80
// 00489411  8b4604               mov eax, dword ptr [esi + 4]
// 00489414  894004               mov dword ptr [eax + 4], eax
// 00489417  8b4604               mov eax, dword ptr [esi + 4]
// 0048941a  c7460800000000       mov dword ptr [esi + 8], 0
// 00489421  8900                 mov dword ptr [eax], eax
// 00489423  8b4604               mov eax, dword ptr [esi + 4]
// 00489426  894008               mov dword ptr [eax + 8], eax
// 00489429  8b4604               mov eax, dword ptr [esi + 4]
// 0048942c  8b08                 mov ecx, dword ptr [eax]
// 0048942e  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00489432  5f                   pop edi
// 00489433  8930                 mov dword ptr [eax], esi
// 00489435  5e                   pop esi
// 00489436  5d                   pop ebp
// 00489437  894804               mov dword ptr [eax + 4], ecx
// 0048943a  5b                   pop ebx
// 0048943b  83c408               add esp, 8
// 0048943e  c21400               ret 0x14
// 00489441  85ff                 test edi, edi
// 00489443  7406                 je 0x48944b
// 00489445  3b7c2428             cmp edi, dword ptr [esp + 0x28]
// 00489449  7406                 je 0x489451
// 0048944b  ff15d8e67700         call dword ptr [0x77e6d8]
// 00489451  3b5c242c             cmp ebx, dword ptr [esp + 0x2c]
// 00489455  7421                 je 0x489478
// 00489457  8d4c2420             lea ecx, [esp + 0x20]
// 0048945b  e8a0d6ffff           call 0x486b00
// 00489460  53                   push ebx
// 00489461  57                   push edi
// 00489462  8d542418             lea edx, [esp + 0x18]
// 00489466  52                   push edx
// 00489467  8bce                 mov ecx, esi
// 00489469  e842f5ffff           call 0x4889b0
// 0048946e  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 00489472  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00489476  ebc9                 jmp 0x489441
// 00489478  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0048947c  8938                 mov dword ptr [eax], edi
// 0048947e  5f                   pop edi
// 0048947f  5e                   pop esi
// 00489480  5d                   pop ebp
// 00489481  895804               mov dword ptr [eax + 4], ebx
// 00489484  5b                   pop ebx
// 00489485  83c408               add esp, 8
// 00489488  c21400               ret 0x14
// standard library set<ptr> (function ?erase@?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE?AViterator@12@V312@0@Z)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
