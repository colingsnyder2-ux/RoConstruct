// from server: 100% by auto
// roc 2007-08 004ce6b0  unit: G3D::VVector3::?$Table  size: 203 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004ce6b0
//
// 004ce6b0  83ec08               sub esp, 8
// 004ce6b3  53                   push ebx
// 004ce6b4  55                   push ebp
// 004ce6b5  56                   push esi
// 004ce6b6  57                   push edi
// 004ce6b7  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 004ce6bb  85ff                 test edi, edi
// 004ce6bd  8bf1                 mov esi, ecx
// 004ce6bf  8b4604               mov eax, dword ptr [esi + 4]
// 004ce6c2  8b28                 mov ebp, dword ptr [eax]
// 004ce6c4  7404                 je 0x4ce6ca
// 004ce6c6  3bfe                 cmp edi, esi
// 004ce6c8  7406                 je 0x4ce6d0
// 004ce6ca  ff15d8e67700         call dword ptr [0x77e6d8]
// 004ce6d0  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 004ce6d4  3bdd                 cmp ebx, ebp
// 004ce6d6  7559                 jne 0x4ce731
// 004ce6d8  8b442428             mov eax, dword ptr [esp + 0x28]
// 004ce6dc  85c0                 test eax, eax
// 004ce6de  8b6e04               mov ebp, dword ptr [esi + 4]
// 004ce6e1  7404                 je 0x4ce6e7
// 004ce6e3  3bc6                 cmp eax, esi
// 004ce6e5  7406                 je 0x4ce6ed
// 004ce6e7  ff15d8e67700         call dword ptr [0x77e6d8]
// 004ce6ed  396c242c             cmp dword ptr [esp + 0x2c], ebp
// 004ce6f1  753e                 jne 0x4ce731
// 004ce6f3  8b4e04               mov ecx, dword ptr [esi + 4]
// 004ce6f6  8b5104               mov edx, dword ptr [ecx + 4]
// 004ce6f9  52                   push edx
// 004ce6fa  8bce                 mov ecx, esi
// 004ce6fc  e80ffeffff           call 0x4ce510
// 004ce701  8b4604               mov eax, dword ptr [esi + 4]
// 004ce704  894004               mov dword ptr [eax + 4], eax
// 004ce707  8b4604               mov eax, dword ptr [esi + 4]
// 004ce70a  c7460800000000       mov dword ptr [esi + 8], 0
// 004ce711  8900                 mov dword ptr [eax], eax
// 004ce713  8b4604               mov eax, dword ptr [esi + 4]
// 004ce716  894008               mov dword ptr [eax + 8], eax
// 004ce719  8b4604               mov eax, dword ptr [esi + 4]
// 004ce71c  8b08                 mov ecx, dword ptr [eax]
// 004ce71e  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 004ce722  5f                   pop edi
// 004ce723  8930                 mov dword ptr [eax], esi
// 004ce725  5e                   pop esi
// 004ce726  5d                   pop ebp
// 004ce727  894804               mov dword ptr [eax + 4], ecx
// 004ce72a  5b                   pop ebx
// 004ce72b  83c408               add esp, 8
// 004ce72e  c21400               ret 0x14
// 004ce731  85ff                 test edi, edi
// 004ce733  7406                 je 0x4ce73b
// 004ce735  3b7c2428             cmp edi, dword ptr [esp + 0x28]
// 004ce739  7406                 je 0x4ce741
// 004ce73b  ff15d8e67700         call dword ptr [0x77e6d8]
// 004ce741  3b5c242c             cmp ebx, dword ptr [esp + 0x2c]
// 004ce745  7421                 je 0x4ce768
// 004ce747  8d4c2420             lea ecx, [esp + 0x20]
// 004ce74b  e820210000           call 0x4d0870
// 004ce750  53                   push ebx
// 004ce751  57                   push edi
// 004ce752  8d542418             lea edx, [esp + 0x18]
// 004ce756  52                   push edx
// 004ce757  8bce                 mov ecx, esi
// 004ce759  e852f9ffff           call 0x4ce0b0
// 004ce75e  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 004ce762  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 004ce766  ebc9                 jmp 0x4ce731
// 004ce768  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 004ce76c  8938                 mov dword ptr [eax], edi
// 004ce76e  5f                   pop edi
// 004ce76f  5e                   pop esi
// 004ce770  5d                   pop ebp
// 004ce771  895804               mov dword ptr [eax + 4], ebx
// 004ce774  5b                   pop ebx
// 004ce775  83c408               add esp, 8
// 004ce778  c21400               ret 0x14
// standard library set<ptr> (function ?erase@?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE?AViterator@12@V312@0@Z)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
