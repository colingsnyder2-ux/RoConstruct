// from server: 100% by auto
// roc 2007-08 005478c0  unit: RBX::MD5HasherImpl  size: 203 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 005478c0
//
// 005478c0  83ec08               sub esp, 8
// 005478c3  53                   push ebx
// 005478c4  55                   push ebp
// 005478c5  56                   push esi
// 005478c6  57                   push edi
// 005478c7  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 005478cb  85ff                 test edi, edi
// 005478cd  8bf1                 mov esi, ecx
// 005478cf  8b4604               mov eax, dword ptr [esi + 4]
// 005478d2  8b28                 mov ebp, dword ptr [eax]
// 005478d4  7404                 je 0x5478da
// 005478d6  3bfe                 cmp edi, esi
// 005478d8  7406                 je 0x5478e0
// 005478da  ff15d8e67700         call dword ptr [0x77e6d8]
// 005478e0  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 005478e4  3bdd                 cmp ebx, ebp
// 005478e6  7559                 jne 0x547941
// 005478e8  8b442428             mov eax, dword ptr [esp + 0x28]
// 005478ec  85c0                 test eax, eax
// 005478ee  8b6e04               mov ebp, dword ptr [esi + 4]
// 005478f1  7404                 je 0x5478f7
// 005478f3  3bc6                 cmp eax, esi
// 005478f5  7406                 je 0x5478fd
// 005478f7  ff15d8e67700         call dword ptr [0x77e6d8]
// 005478fd  396c242c             cmp dword ptr [esp + 0x2c], ebp
// 00547901  753e                 jne 0x547941
// 00547903  8b4e04               mov ecx, dword ptr [esi + 4]
// 00547906  8b5104               mov edx, dword ptr [ecx + 4]
// 00547909  52                   push edx
// 0054790a  8bce                 mov ecx, esi
// 0054790c  e86ff8ffff           call 0x547180
// 00547911  8b4604               mov eax, dword ptr [esi + 4]
// 00547914  894004               mov dword ptr [eax + 4], eax
// 00547917  8b4604               mov eax, dword ptr [esi + 4]
// 0054791a  c7460800000000       mov dword ptr [esi + 8], 0
// 00547921  8900                 mov dword ptr [eax], eax
// 00547923  8b4604               mov eax, dword ptr [esi + 4]
// 00547926  894008               mov dword ptr [eax + 8], eax
// 00547929  8b4604               mov eax, dword ptr [esi + 4]
// 0054792c  8b08                 mov ecx, dword ptr [eax]
// 0054792e  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00547932  5f                   pop edi
// 00547933  8930                 mov dword ptr [eax], esi
// 00547935  5e                   pop esi
// 00547936  5d                   pop ebp
// 00547937  894804               mov dword ptr [eax + 4], ecx
// 0054793a  5b                   pop ebx
// 0054793b  83c408               add esp, 8
// 0054793e  c21400               ret 0x14
// 00547941  85ff                 test edi, edi
// 00547943  7406                 je 0x54794b
// 00547945  3b7c2428             cmp edi, dword ptr [esp + 0x28]
// 00547949  7406                 je 0x547951
// 0054794b  ff15d8e67700         call dword ptr [0x77e6d8]
// 00547951  3b5c242c             cmp ebx, dword ptr [esp + 0x2c]
// 00547955  7421                 je 0x547978
// 00547957  8d4c2420             lea ecx, [esp + 0x20]
// 0054795b  e8d0daffff           call 0x545430
// 00547960  53                   push ebx
// 00547961  57                   push edi
// 00547962  8d542418             lea edx, [esp + 0x18]
// 00547966  52                   push edx
// 00547967  8bce                 mov ecx, esi
// 00547969  e8d2f3ffff           call 0x546d40
// 0054796e  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 00547972  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00547976  ebc9                 jmp 0x547941
// 00547978  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0054797c  8938                 mov dword ptr [eax], edi
// 0054797e  5f                   pop edi
// 0054797f  5e                   pop esi
// 00547980  5d                   pop ebp
// 00547981  895804               mov dword ptr [eax + 4], ebx
// 00547984  5b                   pop ebx
// 00547985  83c408               add esp, 8
// 00547988  c21400               ret 0x14
// standard library set<ptr> (function ?erase@?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE?AViterator@12@V312@0@Z)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
