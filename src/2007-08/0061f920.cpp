// from server: 100% by auto
// roc 2007-08 0061f920  unit: RBX::ScoreHud  size: 203 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0061f920
//
// 0061f920  83ec08               sub esp, 8
// 0061f923  53                   push ebx
// 0061f924  55                   push ebp
// 0061f925  56                   push esi
// 0061f926  57                   push edi
// 0061f927  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 0061f92b  85ff                 test edi, edi
// 0061f92d  8bf1                 mov esi, ecx
// 0061f92f  8b4604               mov eax, dword ptr [esi + 4]
// 0061f932  8b28                 mov ebp, dword ptr [eax]
// 0061f934  7404                 je 0x61f93a
// 0061f936  3bfe                 cmp edi, esi
// 0061f938  7406                 je 0x61f940
// 0061f93a  ff15d8e67700         call dword ptr [0x77e6d8]
// 0061f940  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 0061f944  3bdd                 cmp ebx, ebp
// 0061f946  7559                 jne 0x61f9a1
// 0061f948  8b442428             mov eax, dword ptr [esp + 0x28]
// 0061f94c  85c0                 test eax, eax
// 0061f94e  8b6e04               mov ebp, dword ptr [esi + 4]
// 0061f951  7404                 je 0x61f957
// 0061f953  3bc6                 cmp eax, esi
// 0061f955  7406                 je 0x61f95d
// 0061f957  ff15d8e67700         call dword ptr [0x77e6d8]
// 0061f95d  396c242c             cmp dword ptr [esp + 0x2c], ebp
// 0061f961  753e                 jne 0x61f9a1
// 0061f963  8b4e04               mov ecx, dword ptr [esi + 4]
// 0061f966  8b5104               mov edx, dword ptr [ecx + 4]
// 0061f969  52                   push edx
// 0061f96a  8bce                 mov ecx, esi
// 0061f96c  e87ff3ffff           call 0x61ecf0
// 0061f971  8b4604               mov eax, dword ptr [esi + 4]
// 0061f974  894004               mov dword ptr [eax + 4], eax
// 0061f977  8b4604               mov eax, dword ptr [esi + 4]
// 0061f97a  c7460800000000       mov dword ptr [esi + 8], 0
// 0061f981  8900                 mov dword ptr [eax], eax
// 0061f983  8b4604               mov eax, dword ptr [esi + 4]
// 0061f986  894008               mov dword ptr [eax + 8], eax
// 0061f989  8b4604               mov eax, dword ptr [esi + 4]
// 0061f98c  8b08                 mov ecx, dword ptr [eax]
// 0061f98e  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0061f992  5f                   pop edi
// 0061f993  8930                 mov dword ptr [eax], esi
// 0061f995  5e                   pop esi
// 0061f996  5d                   pop ebp
// 0061f997  894804               mov dword ptr [eax + 4], ecx
// 0061f99a  5b                   pop ebx
// 0061f99b  83c408               add esp, 8
// 0061f99e  c21400               ret 0x14
// 0061f9a1  85ff                 test edi, edi
// 0061f9a3  7406                 je 0x61f9ab
// 0061f9a5  3b7c2428             cmp edi, dword ptr [esp + 0x28]
// 0061f9a9  7406                 je 0x61f9b1
// 0061f9ab  ff15d8e67700         call dword ptr [0x77e6d8]
// 0061f9b1  3b5c242c             cmp ebx, dword ptr [esp + 0x2c]
// 0061f9b5  7421                 je 0x61f9d8
// 0061f9b7  8d4c2420             lea ecx, [esp + 0x20]
// 0061f9bb  e8b00eebff           call 0x4d0870
// 0061f9c0  53                   push ebx
// 0061f9c1  57                   push edi
// 0061f9c2  8d542418             lea edx, [esp + 0x18]
// 0061f9c6  52                   push edx
// 0061f9c7  8bce                 mov ecx, esi
// 0061f9c9  e8e2eeffff           call 0x61e8b0
// 0061f9ce  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 0061f9d2  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 0061f9d6  ebc9                 jmp 0x61f9a1
// 0061f9d8  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0061f9dc  8938                 mov dword ptr [eax], edi
// 0061f9de  5f                   pop edi
// 0061f9df  5e                   pop esi
// 0061f9e0  5d                   pop ebp
// 0061f9e1  895804               mov dword ptr [eax + 4], ebx
// 0061f9e4  5b                   pop ebx
// 0061f9e5  83c408               add esp, 8
// 0061f9e8  c21400               ret 0x14
// standard library set<ptr> (function ?erase@?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE?AViterator@12@V312@0@Z)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
