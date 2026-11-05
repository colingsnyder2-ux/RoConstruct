// from server: 100% by auto
// roc 2007-08 00584a20  unit: RBX::VHat::?$FactoryProduct  size: 203 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00584a20
//
// 00584a20  83ec08               sub esp, 8
// 00584a23  53                   push ebx
// 00584a24  55                   push ebp
// 00584a25  56                   push esi
// 00584a26  57                   push edi
// 00584a27  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00584a2b  85ff                 test edi, edi
// 00584a2d  8bf1                 mov esi, ecx
// 00584a2f  8b4604               mov eax, dword ptr [esi + 4]
// 00584a32  8b28                 mov ebp, dword ptr [eax]
// 00584a34  7404                 je 0x584a3a
// 00584a36  3bfe                 cmp edi, esi
// 00584a38  7406                 je 0x584a40
// 00584a3a  ff15d8e67700         call dword ptr [0x77e6d8]
// 00584a40  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 00584a44  3bdd                 cmp ebx, ebp
// 00584a46  7559                 jne 0x584aa1
// 00584a48  8b442428             mov eax, dword ptr [esp + 0x28]
// 00584a4c  85c0                 test eax, eax
// 00584a4e  8b6e04               mov ebp, dword ptr [esi + 4]
// 00584a51  7404                 je 0x584a57
// 00584a53  3bc6                 cmp eax, esi
// 00584a55  7406                 je 0x584a5d
// 00584a57  ff15d8e67700         call dword ptr [0x77e6d8]
// 00584a5d  396c242c             cmp dword ptr [esp + 0x2c], ebp
// 00584a61  753e                 jne 0x584aa1
// 00584a63  8b4e04               mov ecx, dword ptr [esi + 4]
// 00584a66  8b5104               mov edx, dword ptr [ecx + 4]
// 00584a69  52                   push edx
// 00584a6a  8bce                 mov ecx, esi
// 00584a6c  e88ffcffff           call 0x584700
// 00584a71  8b4604               mov eax, dword ptr [esi + 4]
// 00584a74  894004               mov dword ptr [eax + 4], eax
// 00584a77  8b4604               mov eax, dword ptr [esi + 4]
// 00584a7a  c7460800000000       mov dword ptr [esi + 8], 0
// 00584a81  8900                 mov dword ptr [eax], eax
// 00584a83  8b4604               mov eax, dword ptr [esi + 4]
// 00584a86  894008               mov dword ptr [eax + 8], eax
// 00584a89  8b4604               mov eax, dword ptr [esi + 4]
// 00584a8c  8b08                 mov ecx, dword ptr [eax]
// 00584a8e  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00584a92  5f                   pop edi
// 00584a93  8930                 mov dword ptr [eax], esi
// 00584a95  5e                   pop esi
// 00584a96  5d                   pop ebp
// 00584a97  894804               mov dword ptr [eax + 4], ecx
// 00584a9a  5b                   pop ebx
// 00584a9b  83c408               add esp, 8
// 00584a9e  c21400               ret 0x14
// 00584aa1  85ff                 test edi, edi
// 00584aa3  7406                 je 0x584aab
// 00584aa5  3b7c2428             cmp edi, dword ptr [esp + 0x28]
// 00584aa9  7406                 je 0x584ab1
// 00584aab  ff15d8e67700         call dword ptr [0x77e6d8]
// 00584ab1  3b5c242c             cmp ebx, dword ptr [esp + 0x2c]
// 00584ab5  7421                 je 0x584ad8
// 00584ab7  8d4c2420             lea ecx, [esp + 0x20]
// 00584abb  e860540500           call 0x5d9f20
// 00584ac0  53                   push ebx
// 00584ac1  57                   push edi
// 00584ac2  8d542418             lea edx, [esp + 0x18]
// 00584ac6  52                   push edx
// 00584ac7  8bce                 mov ecx, esi
// 00584ac9  e862f9ffff           call 0x584430
// 00584ace  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 00584ad2  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00584ad6  ebc9                 jmp 0x584aa1
// 00584ad8  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00584adc  8938                 mov dword ptr [eax], edi
// 00584ade  5f                   pop edi
// 00584adf  5e                   pop esi
// 00584ae0  5d                   pop ebp
// 00584ae1  895804               mov dword ptr [eax + 4], ebx
// 00584ae4  5b                   pop ebx
// 00584ae5  83c408               add esp, 8
// 00584ae8  c21400               ret 0x14
// standard library set<ptr> (function ?erase@?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE?AViterator@12@V312@0@Z)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
