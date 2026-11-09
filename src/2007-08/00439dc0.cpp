// from server: 100% by auto
// roc 2007-08 00439dc0  unit: RBX::VSoundId::?$XItem  size: 203 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00439dc0
//
// 00439dc0  83ec08               sub esp, 8
// 00439dc3  53                   push ebx
// 00439dc4  55                   push ebp
// 00439dc5  56                   push esi
// 00439dc6  57                   push edi
// 00439dc7  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00439dcb  85ff                 test edi, edi
// 00439dcd  8bf1                 mov esi, ecx
// 00439dcf  8b4604               mov eax, dword ptr [esi + 4]
// 00439dd2  8b28                 mov ebp, dword ptr [eax]
// 00439dd4  7404                 je 0x439dda
// 00439dd6  3bfe                 cmp edi, esi
// 00439dd8  7406                 je 0x439de0
// 00439dda  ff15d8e67700         call dword ptr [0x77e6d8]
// 00439de0  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 00439de4  3bdd                 cmp ebx, ebp
// 00439de6  7559                 jne 0x439e41
// 00439de8  8b442428             mov eax, dword ptr [esp + 0x28]
// 00439dec  85c0                 test eax, eax
// 00439dee  8b6e04               mov ebp, dword ptr [esi + 4]
// 00439df1  7404                 je 0x439df7
// 00439df3  3bc6                 cmp eax, esi
// 00439df5  7406                 je 0x439dfd
// 00439df7  ff15d8e67700         call dword ptr [0x77e6d8]
// 00439dfd  396c242c             cmp dword ptr [esp + 0x2c], ebp
// 00439e01  753e                 jne 0x439e41
// 00439e03  8b4e04               mov ecx, dword ptr [esi + 4]
// 00439e06  8b5104               mov edx, dword ptr [ecx + 4]
// 00439e09  52                   push edx
// 00439e0a  8bce                 mov ecx, esi
// 00439e0c  e8cf941700           call 0x5b32e0
// 00439e11  8b4604               mov eax, dword ptr [esi + 4]
// 00439e14  894004               mov dword ptr [eax + 4], eax
// 00439e17  8b4604               mov eax, dword ptr [esi + 4]
// 00439e1a  c7460800000000       mov dword ptr [esi + 8], 0
// 00439e21  8900                 mov dword ptr [eax], eax
// 00439e23  8b4604               mov eax, dword ptr [esi + 4]
// 00439e26  894008               mov dword ptr [eax + 8], eax
// 00439e29  8b4604               mov eax, dword ptr [esi + 4]
// 00439e2c  8b08                 mov ecx, dword ptr [eax]
// 00439e2e  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00439e32  5f                   pop edi
// 00439e33  8930                 mov dword ptr [eax], esi
// 00439e35  5e                   pop esi
// 00439e36  5d                   pop ebp
// 00439e37  894804               mov dword ptr [eax + 4], ecx
// 00439e3a  5b                   pop ebx
// 00439e3b  83c408               add esp, 8
// 00439e3e  c21400               ret 0x14
// 00439e41  85ff                 test edi, edi
// 00439e43  7406                 je 0x439e4b
// 00439e45  3b7c2428             cmp edi, dword ptr [esp + 0x28]
// 00439e49  7406                 je 0x439e51
// 00439e4b  ff15d8e67700         call dword ptr [0x77e6d8]
// 00439e51  3b5c242c             cmp ebx, dword ptr [esp + 0x2c]
// 00439e55  7421                 je 0x439e78
// 00439e57  8d4c2420             lea ecx, [esp + 0x20]
// 00439e5b  e8e0d31e00           call 0x627240
// 00439e60  53                   push ebx
// 00439e61  57                   push edi
// 00439e62  8d542418             lea edx, [esp + 0x18]
// 00439e66  52                   push edx
// 00439e67  8bce                 mov ecx, esi
// 00439e69  e882fbffff           call 0x4399f0
// 00439e6e  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 00439e72  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00439e76  ebc9                 jmp 0x439e41
// 00439e78  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00439e7c  8938                 mov dword ptr [eax], edi
// 00439e7e  5f                   pop edi
// 00439e7f  5e                   pop esi
// 00439e80  5d                   pop ebp
// 00439e81  895804               mov dword ptr [eax + 4], ebx
// 00439e84  5b                   pop ebx
// 00439e85  83c408               add esp, 8
// 00439e88  c21400               ret 0x14
// standard library set<ptr> (function ?erase@?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE?AViterator@12@V312@0@Z)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
