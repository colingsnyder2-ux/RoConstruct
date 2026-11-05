// from server: 100% by auto
// roc 2007-08 00441c70  unit: RBX::VSoundId::?$XItem  size: 203 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00441c70
//
// 00441c70  83ec08               sub esp, 8
// 00441c73  53                   push ebx
// 00441c74  55                   push ebp
// 00441c75  56                   push esi
// 00441c76  57                   push edi
// 00441c77  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00441c7b  85ff                 test edi, edi
// 00441c7d  8bf1                 mov esi, ecx
// 00441c7f  8b4604               mov eax, dword ptr [esi + 4]
// 00441c82  8b28                 mov ebp, dword ptr [eax]
// 00441c84  7404                 je 0x441c8a
// 00441c86  3bfe                 cmp edi, esi
// 00441c88  7406                 je 0x441c90
// 00441c8a  ff15d8e67700         call dword ptr [0x77e6d8]
// 00441c90  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 00441c94  3bdd                 cmp ebx, ebp
// 00441c96  7559                 jne 0x441cf1
// 00441c98  8b442428             mov eax, dword ptr [esp + 0x28]
// 00441c9c  85c0                 test eax, eax
// 00441c9e  8b6e04               mov ebp, dword ptr [esi + 4]
// 00441ca1  7404                 je 0x441ca7
// 00441ca3  3bc6                 cmp eax, esi
// 00441ca5  7406                 je 0x441cad
// 00441ca7  ff15d8e67700         call dword ptr [0x77e6d8]
// 00441cad  396c242c             cmp dword ptr [esp + 0x2c], ebp
// 00441cb1  753e                 jne 0x441cf1
// 00441cb3  8b4e04               mov ecx, dword ptr [esi + 4]
// 00441cb6  8b5104               mov edx, dword ptr [ecx + 4]
// 00441cb9  52                   push edx
// 00441cba  8bce                 mov ecx, esi
// 00441cbc  e8bff9ffff           call 0x441680
// 00441cc1  8b4604               mov eax, dword ptr [esi + 4]
// 00441cc4  894004               mov dword ptr [eax + 4], eax
// 00441cc7  8b4604               mov eax, dword ptr [esi + 4]
// 00441cca  c7460800000000       mov dword ptr [esi + 8], 0
// 00441cd1  8900                 mov dword ptr [eax], eax
// 00441cd3  8b4604               mov eax, dword ptr [esi + 4]
// 00441cd6  894008               mov dword ptr [eax + 8], eax
// 00441cd9  8b4604               mov eax, dword ptr [esi + 4]
// 00441cdc  8b08                 mov ecx, dword ptr [eax]
// 00441cde  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00441ce2  5f                   pop edi
// 00441ce3  8930                 mov dword ptr [eax], esi
// 00441ce5  5e                   pop esi
// 00441ce6  5d                   pop ebp
// 00441ce7  894804               mov dword ptr [eax + 4], ecx
// 00441cea  5b                   pop ebx
// 00441ceb  83c408               add esp, 8
// 00441cee  c21400               ret 0x14
// 00441cf1  85ff                 test edi, edi
// 00441cf3  7406                 je 0x441cfb
// 00441cf5  3b7c2428             cmp edi, dword ptr [esp + 0x28]
// 00441cf9  7406                 je 0x441d01
// 00441cfb  ff15d8e67700         call dword ptr [0x77e6d8]
// 00441d01  3b5c242c             cmp ebx, dword ptr [esp + 0x2c]
// 00441d05  7421                 je 0x441d28
// 00441d07  8d4c2420             lea ecx, [esp + 0x20]
// 00441d0b  e860eb0800           call 0x4d0870
// 00441d10  53                   push ebx
// 00441d11  57                   push edi
// 00441d12  8d542418             lea edx, [esp + 0x18]
// 00441d16  52                   push edx
// 00441d17  8bce                 mov ecx, esi
// 00441d19  e8c2efffff           call 0x440ce0
// 00441d1e  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 00441d22  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00441d26  ebc9                 jmp 0x441cf1
// 00441d28  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00441d2c  8938                 mov dword ptr [eax], edi
// 00441d2e  5f                   pop edi
// 00441d2f  5e                   pop esi
// 00441d30  5d                   pop ebp
// 00441d31  895804               mov dword ptr [eax + 4], ebx
// 00441d34  5b                   pop ebx
// 00441d35  83c408               add esp, 8
// 00441d38  c21400               ret 0x14
// standard library set<ptr> (function ?erase@?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE?AViterator@12@V312@0@Z)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
