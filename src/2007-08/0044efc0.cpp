// from server: 100% by auto
// roc 2007-08 0044efc0  unit: RBX::CameraTiltUpCommand  size: 203 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0044efc0
//
// 0044efc0  83ec08               sub esp, 8
// 0044efc3  53                   push ebx
// 0044efc4  55                   push ebp
// 0044efc5  56                   push esi
// 0044efc6  57                   push edi
// 0044efc7  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 0044efcb  85ff                 test edi, edi
// 0044efcd  8bf1                 mov esi, ecx
// 0044efcf  8b4604               mov eax, dword ptr [esi + 4]
// 0044efd2  8b28                 mov ebp, dword ptr [eax]
// 0044efd4  7404                 je 0x44efda
// 0044efd6  3bfe                 cmp edi, esi
// 0044efd8  7406                 je 0x44efe0
// 0044efda  ff15d8e67700         call dword ptr [0x77e6d8]
// 0044efe0  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 0044efe4  3bdd                 cmp ebx, ebp
// 0044efe6  7559                 jne 0x44f041
// 0044efe8  8b442428             mov eax, dword ptr [esp + 0x28]
// 0044efec  85c0                 test eax, eax
// 0044efee  8b6e04               mov ebp, dword ptr [esi + 4]
// 0044eff1  7404                 je 0x44eff7
// 0044eff3  3bc6                 cmp eax, esi
// 0044eff5  7406                 je 0x44effd
// 0044eff7  ff15d8e67700         call dword ptr [0x77e6d8]
// 0044effd  396c242c             cmp dword ptr [esp + 0x2c], ebp
// 0044f001  753e                 jne 0x44f041
// 0044f003  8b4e04               mov ecx, dword ptr [esi + 4]
// 0044f006  8b5104               mov edx, dword ptr [ecx + 4]
// 0044f009  52                   push edx
// 0044f00a  8bce                 mov ecx, esi
// 0044f00c  e8df61ffff           call 0x4451f0
// 0044f011  8b4604               mov eax, dword ptr [esi + 4]
// 0044f014  894004               mov dword ptr [eax + 4], eax
// 0044f017  8b4604               mov eax, dword ptr [esi + 4]
// 0044f01a  c7460800000000       mov dword ptr [esi + 8], 0
// 0044f021  8900                 mov dword ptr [eax], eax
// 0044f023  8b4604               mov eax, dword ptr [esi + 4]
// 0044f026  894008               mov dword ptr [eax + 8], eax
// 0044f029  8b4604               mov eax, dword ptr [esi + 4]
// 0044f02c  8b08                 mov ecx, dword ptr [eax]
// 0044f02e  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0044f032  5f                   pop edi
// 0044f033  8930                 mov dword ptr [eax], esi
// 0044f035  5e                   pop esi
// 0044f036  5d                   pop ebp
// 0044f037  894804               mov dword ptr [eax + 4], ecx
// 0044f03a  5b                   pop ebx
// 0044f03b  83c408               add esp, 8
// 0044f03e  c21400               ret 0x14
// 0044f041  85ff                 test edi, edi
// 0044f043  7406                 je 0x44f04b
// 0044f045  3b7c2428             cmp edi, dword ptr [esp + 0x28]
// 0044f049  7406                 je 0x44f051
// 0044f04b  ff15d8e67700         call dword ptr [0x77e6d8]
// 0044f051  3b5c242c             cmp ebx, dword ptr [esp + 0x2c]
// 0044f055  7421                 je 0x44f078
// 0044f057  8d4c2420             lea ecx, [esp + 0x20]
// 0044f05b  e8509efeff           call 0x438eb0
// 0044f060  53                   push ebx
// 0044f061  57                   push edi
// 0044f062  8d542418             lea edx, [esp + 0x18]
// 0044f066  52                   push edx
// 0044f067  8bce                 mov ecx, esi
// 0044f069  e882fcffff           call 0x44ecf0
// 0044f06e  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 0044f072  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 0044f076  ebc9                 jmp 0x44f041
// 0044f078  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0044f07c  8938                 mov dword ptr [eax], edi
// 0044f07e  5f                   pop edi
// 0044f07f  5e                   pop esi
// 0044f080  5d                   pop ebp
// 0044f081  895804               mov dword ptr [eax + 4], ebx
// 0044f084  5b                   pop ebx
// 0044f085  83c408               add esp, 8
// 0044f088  c21400               ret 0x14
// standard library set<ptr> (function ?erase@?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE?AViterator@12@V312@0@Z)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
