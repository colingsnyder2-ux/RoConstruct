// from server: 100% by auto
// roc 2007-08 00620a10  unit: RBX::ScoreHud  size: 203 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00620a10
//
// 00620a10  83ec08               sub esp, 8
// 00620a13  53                   push ebx
// 00620a14  55                   push ebp
// 00620a15  56                   push esi
// 00620a16  57                   push edi
// 00620a17  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00620a1b  85ff                 test edi, edi
// 00620a1d  8bf1                 mov esi, ecx
// 00620a1f  8b4604               mov eax, dword ptr [esi + 4]
// 00620a22  8b28                 mov ebp, dword ptr [eax]
// 00620a24  7404                 je 0x620a2a
// 00620a26  3bfe                 cmp edi, esi
// 00620a28  7406                 je 0x620a30
// 00620a2a  ff15d8e67700         call dword ptr [0x77e6d8]
// 00620a30  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 00620a34  3bdd                 cmp ebx, ebp
// 00620a36  7559                 jne 0x620a91
// 00620a38  8b442428             mov eax, dword ptr [esp + 0x28]
// 00620a3c  85c0                 test eax, eax
// 00620a3e  8b6e04               mov ebp, dword ptr [esi + 4]
// 00620a41  7404                 je 0x620a47
// 00620a43  3bc6                 cmp eax, esi
// 00620a45  7406                 je 0x620a4d
// 00620a47  ff15d8e67700         call dword ptr [0x77e6d8]
// 00620a4d  396c242c             cmp dword ptr [esp + 0x2c], ebp
// 00620a51  753e                 jne 0x620a91
// 00620a53  8b4e04               mov ecx, dword ptr [esi + 4]
// 00620a56  8b5104               mov edx, dword ptr [ecx + 4]
// 00620a59  52                   push edx
// 00620a5a  8bce                 mov ecx, esi
// 00620a5c  e80ff7ffff           call 0x620170
// 00620a61  8b4604               mov eax, dword ptr [esi + 4]
// 00620a64  894004               mov dword ptr [eax + 4], eax
// 00620a67  8b4604               mov eax, dword ptr [esi + 4]
// 00620a6a  c7460800000000       mov dword ptr [esi + 8], 0
// 00620a71  8900                 mov dword ptr [eax], eax
// 00620a73  8b4604               mov eax, dword ptr [esi + 4]
// 00620a76  894008               mov dword ptr [eax + 8], eax
// 00620a79  8b4604               mov eax, dword ptr [esi + 4]
// 00620a7c  8b08                 mov ecx, dword ptr [eax]
// 00620a7e  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00620a82  5f                   pop edi
// 00620a83  8930                 mov dword ptr [eax], esi
// 00620a85  5e                   pop esi
// 00620a86  5d                   pop ebp
// 00620a87  894804               mov dword ptr [eax + 4], ecx
// 00620a8a  5b                   pop ebx
// 00620a8b  83c408               add esp, 8
// 00620a8e  c21400               ret 0x14
// 00620a91  85ff                 test edi, edi
// 00620a93  7406                 je 0x620a9b
// 00620a95  3b7c2428             cmp edi, dword ptr [esp + 0x28]
// 00620a99  7406                 je 0x620aa1
// 00620a9b  ff15d8e67700         call dword ptr [0x77e6d8]
// 00620aa1  3b5c242c             cmp ebx, dword ptr [esp + 0x2c]
// 00620aa5  7421                 je 0x620ac8
// 00620aa7  8d4c2420             lea ecx, [esp + 0x20]
// 00620aab  e83070f6ff           call 0x587ae0
// 00620ab0  53                   push ebx
// 00620ab1  57                   push edi
// 00620ab2  8d542418             lea edx, [esp + 0x18]
// 00620ab6  52                   push edx
// 00620ab7  8bce                 mov ecx, esi
// 00620ab9  e8f2f0ffff           call 0x61fbb0
// 00620abe  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 00620ac2  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00620ac6  ebc9                 jmp 0x620a91
// 00620ac8  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00620acc  8938                 mov dword ptr [eax], edi
// 00620ace  5f                   pop edi
// 00620acf  5e                   pop esi
// 00620ad0  5d                   pop ebp
// 00620ad1  895804               mov dword ptr [eax + 4], ebx
// 00620ad4  5b                   pop ebx
// 00620ad5  83c408               add esp, 8
// 00620ad8  c21400               ret 0x14
// standard library set<ptr> (function ?erase@?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE?AViterator@12@V312@0@Z)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
