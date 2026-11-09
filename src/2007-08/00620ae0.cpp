// from server: 100% by auto
// roc 2007-08 00620ae0  unit: RBX::ScoreHud  size: 203 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00620ae0
//
// 00620ae0  83ec08               sub esp, 8
// 00620ae3  53                   push ebx
// 00620ae4  55                   push ebp
// 00620ae5  56                   push esi
// 00620ae6  57                   push edi
// 00620ae7  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00620aeb  85ff                 test edi, edi
// 00620aed  8bf1                 mov esi, ecx
// 00620aef  8b4604               mov eax, dword ptr [esi + 4]
// 00620af2  8b28                 mov ebp, dword ptr [eax]
// 00620af4  7404                 je 0x620afa
// 00620af6  3bfe                 cmp edi, esi
// 00620af8  7406                 je 0x620b00
// 00620afa  ff15d8e67700         call dword ptr [0x77e6d8]
// 00620b00  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 00620b04  3bdd                 cmp ebx, ebp
// 00620b06  7559                 jne 0x620b61
// 00620b08  8b442428             mov eax, dword ptr [esp + 0x28]
// 00620b0c  85c0                 test eax, eax
// 00620b0e  8b6e04               mov ebp, dword ptr [esi + 4]
// 00620b11  7404                 je 0x620b17
// 00620b13  3bc6                 cmp eax, esi
// 00620b15  7406                 je 0x620b1d
// 00620b17  ff15d8e67700         call dword ptr [0x77e6d8]
// 00620b1d  396c242c             cmp dword ptr [esp + 0x2c], ebp
// 00620b21  753e                 jne 0x620b61
// 00620b23  8b4e04               mov ecx, dword ptr [esi + 4]
// 00620b26  8b5104               mov edx, dword ptr [ecx + 4]
// 00620b29  52                   push edx
// 00620b2a  8bce                 mov ecx, esi
// 00620b2c  e87ff6ffff           call 0x6201b0
// 00620b31  8b4604               mov eax, dword ptr [esi + 4]
// 00620b34  894004               mov dword ptr [eax + 4], eax
// 00620b37  8b4604               mov eax, dword ptr [esi + 4]
// 00620b3a  c7460800000000       mov dword ptr [esi + 8], 0
// 00620b41  8900                 mov dword ptr [eax], eax
// 00620b43  8b4604               mov eax, dword ptr [esi + 4]
// 00620b46  894008               mov dword ptr [eax + 8], eax
// 00620b49  8b4604               mov eax, dword ptr [esi + 4]
// 00620b4c  8b08                 mov ecx, dword ptr [eax]
// 00620b4e  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00620b52  5f                   pop edi
// 00620b53  8930                 mov dword ptr [eax], esi
// 00620b55  5e                   pop esi
// 00620b56  5d                   pop ebp
// 00620b57  894804               mov dword ptr [eax + 4], ecx
// 00620b5a  5b                   pop ebx
// 00620b5b  83c408               add esp, 8
// 00620b5e  c21400               ret 0x14
// 00620b61  85ff                 test edi, edi
// 00620b63  7406                 je 0x620b6b
// 00620b65  3b7c2428             cmp edi, dword ptr [esp + 0x28]
// 00620b69  7406                 je 0x620b71
// 00620b6b  ff15d8e67700         call dword ptr [0x77e6d8]
// 00620b71  3b5c242c             cmp ebx, dword ptr [esp + 0x2c]
// 00620b75  7421                 je 0x620b98
// 00620b77  8d4c2420             lea ecx, [esp + 0x20]
// 00620b7b  e800c2feff           call 0x60cd80
// 00620b80  53                   push ebx
// 00620b81  57                   push edi
// 00620b82  8d542418             lea edx, [esp + 0x18]
// 00620b86  52                   push edx
// 00620b87  8bce                 mov ecx, esi
// 00620b89  e8f2f2ffff           call 0x61fe80
// 00620b8e  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 00620b92  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00620b96  ebc9                 jmp 0x620b61
// 00620b98  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00620b9c  8938                 mov dword ptr [eax], edi
// 00620b9e  5f                   pop edi
// 00620b9f  5e                   pop esi
// 00620ba0  5d                   pop ebp
// 00620ba1  895804               mov dword ptr [eax + 4], ebx
// 00620ba4  5b                   pop ebx
// 00620ba5  83c408               add esp, 8
// 00620ba8  c21400               ret 0x14
// standard library set<ptr> (function ?erase@?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE?AViterator@12@V312@0@Z)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
