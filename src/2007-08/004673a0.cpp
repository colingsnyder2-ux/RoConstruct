// from server: 100% by auto
// roc 2007-08 004673a0  unit: VCWorkspace::?$CComObject  size: 203 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004673a0
//
// 004673a0  83ec08               sub esp, 8
// 004673a3  53                   push ebx
// 004673a4  55                   push ebp
// 004673a5  56                   push esi
// 004673a6  57                   push edi
// 004673a7  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 004673ab  85ff                 test edi, edi
// 004673ad  8bf1                 mov esi, ecx
// 004673af  8b4604               mov eax, dword ptr [esi + 4]
// 004673b2  8b28                 mov ebp, dword ptr [eax]
// 004673b4  7404                 je 0x4673ba
// 004673b6  3bfe                 cmp edi, esi
// 004673b8  7406                 je 0x4673c0
// 004673ba  ff15d8e67700         call dword ptr [0x77e6d8]
// 004673c0  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 004673c4  3bdd                 cmp ebx, ebp
// 004673c6  7559                 jne 0x467421
// 004673c8  8b442428             mov eax, dword ptr [esp + 0x28]
// 004673cc  85c0                 test eax, eax
// 004673ce  8b6e04               mov ebp, dword ptr [esi + 4]
// 004673d1  7404                 je 0x4673d7
// 004673d3  3bc6                 cmp eax, esi
// 004673d5  7406                 je 0x4673dd
// 004673d7  ff15d8e67700         call dword ptr [0x77e6d8]
// 004673dd  396c242c             cmp dword ptr [esp + 0x2c], ebp
// 004673e1  753e                 jne 0x467421
// 004673e3  8b4e04               mov ecx, dword ptr [esi + 4]
// 004673e6  8b5104               mov edx, dword ptr [ecx + 4]
// 004673e9  52                   push edx
// 004673ea  8bce                 mov ecx, esi
// 004673ec  e88f230000           call 0x469780
// 004673f1  8b4604               mov eax, dword ptr [esi + 4]
// 004673f4  894004               mov dword ptr [eax + 4], eax
// 004673f7  8b4604               mov eax, dword ptr [esi + 4]
// 004673fa  c7460800000000       mov dword ptr [esi + 8], 0
// 00467401  8900                 mov dword ptr [eax], eax
// 00467403  8b4604               mov eax, dword ptr [esi + 4]
// 00467406  894008               mov dword ptr [eax + 8], eax
// 00467409  8b4604               mov eax, dword ptr [esi + 4]
// 0046740c  8b08                 mov ecx, dword ptr [eax]
// 0046740e  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00467412  5f                   pop edi
// 00467413  8930                 mov dword ptr [eax], esi
// 00467415  5e                   pop esi
// 00467416  5d                   pop ebp
// 00467417  894804               mov dword ptr [eax + 4], ecx
// 0046741a  5b                   pop ebx
// 0046741b  83c408               add esp, 8
// 0046741e  c21400               ret 0x14
// 00467421  85ff                 test edi, edi
// 00467423  7406                 je 0x46742b
// 00467425  3b7c2428             cmp edi, dword ptr [esp + 0x28]
// 00467429  7406                 je 0x467431
// 0046742b  ff15d8e67700         call dword ptr [0x77e6d8]
// 00467431  3b5c242c             cmp ebx, dword ptr [esp + 0x2c]
// 00467435  7421                 je 0x467458
// 00467437  8d4c2420             lea ecx, [esp + 0x20]
// 0046743b  e8e02a1700           call 0x5d9f20
// 00467440  53                   push ebx
// 00467441  57                   push edi
// 00467442  8d542418             lea edx, [esp + 0x18]
// 00467446  52                   push edx
// 00467447  8bce                 mov ecx, esi
// 00467449  e892fcffff           call 0x4670e0
// 0046744e  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 00467452  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00467456  ebc9                 jmp 0x467421
// 00467458  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0046745c  8938                 mov dword ptr [eax], edi
// 0046745e  5f                   pop edi
// 0046745f  5e                   pop esi
// 00467460  5d                   pop ebp
// 00467461  895804               mov dword ptr [eax + 4], ebx
// 00467464  5b                   pop ebx
// 00467465  83c408               add esp, 8
// 00467468  c21400               ret 0x14
// standard library set<ptr> (function ?erase@?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE?AViterator@12@V312@0@Z)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
