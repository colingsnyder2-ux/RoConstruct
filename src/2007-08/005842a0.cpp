// from server: 100% by auto
// roc 2007-08 005842a0  unit: RBX::VHat::?$FactoryProduct  size: 203 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 005842a0
//
// 005842a0  83ec08               sub esp, 8
// 005842a3  53                   push ebx
// 005842a4  55                   push ebp
// 005842a5  56                   push esi
// 005842a6  57                   push edi
// 005842a7  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 005842ab  85ff                 test edi, edi
// 005842ad  8bf1                 mov esi, ecx
// 005842af  8b4604               mov eax, dword ptr [esi + 4]
// 005842b2  8b28                 mov ebp, dword ptr [eax]
// 005842b4  7404                 je 0x5842ba
// 005842b6  3bfe                 cmp edi, esi
// 005842b8  7406                 je 0x5842c0
// 005842ba  ff15d8e67700         call dword ptr [0x77e6d8]
// 005842c0  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 005842c4  3bdd                 cmp ebx, ebp
// 005842c6  7559                 jne 0x584321
// 005842c8  8b442428             mov eax, dword ptr [esp + 0x28]
// 005842cc  85c0                 test eax, eax
// 005842ce  8b6e04               mov ebp, dword ptr [esi + 4]
// 005842d1  7404                 je 0x5842d7
// 005842d3  3bc6                 cmp eax, esi
// 005842d5  7406                 je 0x5842dd
// 005842d7  ff15d8e67700         call dword ptr [0x77e6d8]
// 005842dd  396c242c             cmp dword ptr [esp + 0x2c], ebp
// 005842e1  753e                 jne 0x584321
// 005842e3  8b4e04               mov ecx, dword ptr [esi + 4]
// 005842e6  8b5104               mov edx, dword ptr [ecx + 4]
// 005842e9  52                   push edx
// 005842ea  8bce                 mov ecx, esi
// 005842ec  e8fff2ffff           call 0x5835f0
// 005842f1  8b4604               mov eax, dword ptr [esi + 4]
// 005842f4  894004               mov dword ptr [eax + 4], eax
// 005842f7  8b4604               mov eax, dword ptr [esi + 4]
// 005842fa  c7460800000000       mov dword ptr [esi + 8], 0
// 00584301  8900                 mov dword ptr [eax], eax
// 00584303  8b4604               mov eax, dword ptr [esi + 4]
// 00584306  894008               mov dword ptr [eax + 8], eax
// 00584309  8b4604               mov eax, dword ptr [esi + 4]
// 0058430c  8b08                 mov ecx, dword ptr [eax]
// 0058430e  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00584312  5f                   pop edi
// 00584313  8930                 mov dword ptr [eax], esi
// 00584315  5e                   pop esi
// 00584316  5d                   pop ebp
// 00584317  894804               mov dword ptr [eax + 4], ecx
// 0058431a  5b                   pop ebx
// 0058431b  83c408               add esp, 8
// 0058431e  c21400               ret 0x14
// 00584321  85ff                 test edi, edi
// 00584323  7406                 je 0x58432b
// 00584325  3b7c2428             cmp edi, dword ptr [esp + 0x28]
// 00584329  7406                 je 0x584331
// 0058432b  ff15d8e67700         call dword ptr [0x77e6d8]
// 00584331  3b5c242c             cmp ebx, dword ptr [esp + 0x2c]
// 00584335  7421                 je 0x584358
// 00584337  8d4c2420             lea ecx, [esp + 0x20]
// 0058433b  e830c5f4ff           call 0x4d0870
// 00584340  53                   push ebx
// 00584341  57                   push edi
// 00584342  8d542418             lea edx, [esp + 0x18]
// 00584346  52                   push edx
// 00584347  8bce                 mov ecx, esi
// 00584349  e8e2f8ffff           call 0x583c30
// 0058434e  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 00584352  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00584356  ebc9                 jmp 0x584321
// 00584358  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0058435c  8938                 mov dword ptr [eax], edi
// 0058435e  5f                   pop edi
// 0058435f  5e                   pop esi
// 00584360  5d                   pop ebp
// 00584361  895804               mov dword ptr [eax + 4], ebx
// 00584364  5b                   pop ebx
// 00584365  83c408               add esp, 8
// 00584368  c21400               ret 0x14
// standard library set<ptr> (function ?erase@?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE?AViterator@12@V312@0@Z)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
