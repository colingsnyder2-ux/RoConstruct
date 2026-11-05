// from server: 100% by auto
// roc 2007-08 004cf010  unit: RBX::VSky::?$FactoryProduct::Creator  size: 203 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004cf010
//
// 004cf010  83ec08               sub esp, 8
// 004cf013  53                   push ebx
// 004cf014  55                   push ebp
// 004cf015  56                   push esi
// 004cf016  57                   push edi
// 004cf017  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 004cf01b  85ff                 test edi, edi
// 004cf01d  8bf1                 mov esi, ecx
// 004cf01f  8b4604               mov eax, dword ptr [esi + 4]
// 004cf022  8b28                 mov ebp, dword ptr [eax]
// 004cf024  7404                 je 0x4cf02a
// 004cf026  3bfe                 cmp edi, esi
// 004cf028  7406                 je 0x4cf030
// 004cf02a  ff15d8e67700         call dword ptr [0x77e6d8]
// 004cf030  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 004cf034  3bdd                 cmp ebx, ebp
// 004cf036  7559                 jne 0x4cf091
// 004cf038  8b442428             mov eax, dword ptr [esp + 0x28]
// 004cf03c  85c0                 test eax, eax
// 004cf03e  8b6e04               mov ebp, dword ptr [esi + 4]
// 004cf041  7404                 je 0x4cf047
// 004cf043  3bc6                 cmp eax, esi
// 004cf045  7406                 je 0x4cf04d
// 004cf047  ff15d8e67700         call dword ptr [0x77e6d8]
// 004cf04d  396c242c             cmp dword ptr [esp + 0x2c], ebp
// 004cf051  753e                 jne 0x4cf091
// 004cf053  8b4e04               mov ecx, dword ptr [esi + 4]
// 004cf056  8b5104               mov edx, dword ptr [ecx + 4]
// 004cf059  52                   push edx
// 004cf05a  8bce                 mov ecx, esi
// 004cf05c  e8fff9ffff           call 0x4cea60
// 004cf061  8b4604               mov eax, dword ptr [esi + 4]
// 004cf064  894004               mov dword ptr [eax + 4], eax
// 004cf067  8b4604               mov eax, dword ptr [esi + 4]
// 004cf06a  c7460800000000       mov dword ptr [esi + 8], 0
// 004cf071  8900                 mov dword ptr [eax], eax
// 004cf073  8b4604               mov eax, dword ptr [esi + 4]
// 004cf076  894008               mov dword ptr [eax + 8], eax
// 004cf079  8b4604               mov eax, dword ptr [esi + 4]
// 004cf07c  8b08                 mov ecx, dword ptr [eax]
// 004cf07e  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 004cf082  5f                   pop edi
// 004cf083  8930                 mov dword ptr [eax], esi
// 004cf085  5e                   pop esi
// 004cf086  5d                   pop ebp
// 004cf087  894804               mov dword ptr [eax + 4], ecx
// 004cf08a  5b                   pop ebx
// 004cf08b  83c408               add esp, 8
// 004cf08e  c21400               ret 0x14
// 004cf091  85ff                 test edi, edi
// 004cf093  7406                 je 0x4cf09b
// 004cf095  3b7c2428             cmp edi, dword ptr [esp + 0x28]
// 004cf099  7406                 je 0x4cf0a1
// 004cf09b  ff15d8e67700         call dword ptr [0x77e6d8]
// 004cf0a1  3b5c242c             cmp ebx, dword ptr [esp + 0x2c]
// 004cf0a5  7421                 je 0x4cf0c8
// 004cf0a7  8d4c2420             lea ecx, [esp + 0x20]
// 004cf0ab  e8c0170000           call 0x4d0870
// 004cf0b0  53                   push ebx
// 004cf0b1  57                   push edi
// 004cf0b2  8d542418             lea edx, [esp + 0x18]
// 004cf0b6  52                   push edx
// 004cf0b7  8bce                 mov ecx, esi
// 004cf0b9  e8c2f6ffff           call 0x4ce780
// 004cf0be  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 004cf0c2  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 004cf0c6  ebc9                 jmp 0x4cf091
// 004cf0c8  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 004cf0cc  8938                 mov dword ptr [eax], edi
// 004cf0ce  5f                   pop edi
// 004cf0cf  5e                   pop esi
// 004cf0d0  5d                   pop ebp
// 004cf0d1  895804               mov dword ptr [eax + 4], ebx
// 004cf0d4  5b                   pop ebx
// 004cf0d5  83c408               add esp, 8
// 004cf0d8  c21400               ret 0x14
// standard library set<ptr> (function ?erase@?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE?AViterator@12@V312@0@Z)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
