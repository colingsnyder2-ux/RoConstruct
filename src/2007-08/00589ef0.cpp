// from server: 100% by auto
// roc 2007-08 00589ef0  unit: VStockSound::?$FactoryProduct  size: 203 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00589ef0
//
// 00589ef0  83ec08               sub esp, 8
// 00589ef3  53                   push ebx
// 00589ef4  55                   push ebp
// 00589ef5  56                   push esi
// 00589ef6  57                   push edi
// 00589ef7  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00589efb  85ff                 test edi, edi
// 00589efd  8bf1                 mov esi, ecx
// 00589eff  8b4604               mov eax, dword ptr [esi + 4]
// 00589f02  8b28                 mov ebp, dword ptr [eax]
// 00589f04  7404                 je 0x589f0a
// 00589f06  3bfe                 cmp edi, esi
// 00589f08  7406                 je 0x589f10
// 00589f0a  ff15d8e67700         call dword ptr [0x77e6d8]
// 00589f10  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 00589f14  3bdd                 cmp ebx, ebp
// 00589f16  7559                 jne 0x589f71
// 00589f18  8b442428             mov eax, dword ptr [esp + 0x28]
// 00589f1c  85c0                 test eax, eax
// 00589f1e  8b6e04               mov ebp, dword ptr [esi + 4]
// 00589f21  7404                 je 0x589f27
// 00589f23  3bc6                 cmp eax, esi
// 00589f25  7406                 je 0x589f2d
// 00589f27  ff15d8e67700         call dword ptr [0x77e6d8]
// 00589f2d  396c242c             cmp dword ptr [esp + 0x2c], ebp
// 00589f31  753e                 jne 0x589f71
// 00589f33  8b4e04               mov ecx, dword ptr [esi + 4]
// 00589f36  8b5104               mov edx, dword ptr [ecx + 4]
// 00589f39  52                   push edx
// 00589f3a  8bce                 mov ecx, esi
// 00589f3c  e89ff4ffff           call 0x5893e0
// 00589f41  8b4604               mov eax, dword ptr [esi + 4]
// 00589f44  894004               mov dword ptr [eax + 4], eax
// 00589f47  8b4604               mov eax, dword ptr [esi + 4]
// 00589f4a  c7460800000000       mov dword ptr [esi + 8], 0
// 00589f51  8900                 mov dword ptr [eax], eax
// 00589f53  8b4604               mov eax, dword ptr [esi + 4]
// 00589f56  894008               mov dword ptr [eax + 8], eax
// 00589f59  8b4604               mov eax, dword ptr [esi + 4]
// 00589f5c  8b08                 mov ecx, dword ptr [eax]
// 00589f5e  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00589f62  5f                   pop edi
// 00589f63  8930                 mov dword ptr [eax], esi
// 00589f65  5e                   pop esi
// 00589f66  5d                   pop ebp
// 00589f67  894804               mov dword ptr [eax + 4], ecx
// 00589f6a  5b                   pop ebx
// 00589f6b  83c408               add esp, 8
// 00589f6e  c21400               ret 0x14
// 00589f71  85ff                 test edi, edi
// 00589f73  7406                 je 0x589f7b
// 00589f75  3b7c2428             cmp edi, dword ptr [esp + 0x28]
// 00589f79  7406                 je 0x589f81
// 00589f7b  ff15d8e67700         call dword ptr [0x77e6d8]
// 00589f81  3b5c242c             cmp ebx, dword ptr [esp + 0x2c]
// 00589f85  7421                 je 0x589fa8
// 00589f87  8d4c2420             lea ecx, [esp + 0x20]
// 00589f8b  e850dbffff           call 0x587ae0
// 00589f90  53                   push ebx
// 00589f91  57                   push edi
// 00589f92  8d542418             lea edx, [esp + 0x18]
// 00589f96  52                   push edx
// 00589f97  8bce                 mov ecx, esi
// 00589f99  e822f6ffff           call 0x5895c0
// 00589f9e  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 00589fa2  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00589fa6  ebc9                 jmp 0x589f71
// 00589fa8  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00589fac  8938                 mov dword ptr [eax], edi
// 00589fae  5f                   pop edi
// 00589faf  5e                   pop esi
// 00589fb0  5d                   pop ebp
// 00589fb1  895804               mov dword ptr [eax + 4], ebx
// 00589fb4  5b                   pop ebx
// 00589fb5  83c408               add esp, 8
// 00589fb8  c21400               ret 0x14
// standard library set<ptr> (function ?erase@?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE?AViterator@12@V312@0@Z)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
