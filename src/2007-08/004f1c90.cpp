// from server: 100% by auto
// roc 2007-08 004f1c90  unit: RBX::Render::AggregatingSceneManager  size: 203 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004f1c90
//
// 004f1c90  83ec08               sub esp, 8
// 004f1c93  53                   push ebx
// 004f1c94  55                   push ebp
// 004f1c95  56                   push esi
// 004f1c96  57                   push edi
// 004f1c97  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 004f1c9b  85ff                 test edi, edi
// 004f1c9d  8bf1                 mov esi, ecx
// 004f1c9f  8b4604               mov eax, dword ptr [esi + 4]
// 004f1ca2  8b28                 mov ebp, dword ptr [eax]
// 004f1ca4  7404                 je 0x4f1caa
// 004f1ca6  3bfe                 cmp edi, esi
// 004f1ca8  7406                 je 0x4f1cb0
// 004f1caa  ff15d8e67700         call dword ptr [0x77e6d8]
// 004f1cb0  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 004f1cb4  3bdd                 cmp ebx, ebp
// 004f1cb6  7559                 jne 0x4f1d11
// 004f1cb8  8b442428             mov eax, dword ptr [esp + 0x28]
// 004f1cbc  85c0                 test eax, eax
// 004f1cbe  8b6e04               mov ebp, dword ptr [esi + 4]
// 004f1cc1  7404                 je 0x4f1cc7
// 004f1cc3  3bc6                 cmp eax, esi
// 004f1cc5  7406                 je 0x4f1ccd
// 004f1cc7  ff15d8e67700         call dword ptr [0x77e6d8]
// 004f1ccd  396c242c             cmp dword ptr [esp + 0x2c], ebp
// 004f1cd1  753e                 jne 0x4f1d11
// 004f1cd3  8b4e04               mov ecx, dword ptr [esi + 4]
// 004f1cd6  8b5104               mov edx, dword ptr [ecx + 4]
// 004f1cd9  52                   push edx
// 004f1cda  8bce                 mov ecx, esi
// 004f1cdc  e83ff2ffff           call 0x4f0f20
// 004f1ce1  8b4604               mov eax, dword ptr [esi + 4]
// 004f1ce4  894004               mov dword ptr [eax + 4], eax
// 004f1ce7  8b4604               mov eax, dword ptr [esi + 4]
// 004f1cea  c7460800000000       mov dword ptr [esi + 8], 0
// 004f1cf1  8900                 mov dword ptr [eax], eax
// 004f1cf3  8b4604               mov eax, dword ptr [esi + 4]
// 004f1cf6  894008               mov dword ptr [eax + 8], eax
// 004f1cf9  8b4604               mov eax, dword ptr [esi + 4]
// 004f1cfc  8b08                 mov ecx, dword ptr [eax]
// 004f1cfe  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 004f1d02  5f                   pop edi
// 004f1d03  8930                 mov dword ptr [eax], esi
// 004f1d05  5e                   pop esi
// 004f1d06  5d                   pop ebp
// 004f1d07  894804               mov dword ptr [eax + 4], ecx
// 004f1d0a  5b                   pop ebx
// 004f1d0b  83c408               add esp, 8
// 004f1d0e  c21400               ret 0x14
// 004f1d11  85ff                 test edi, edi
// 004f1d13  7406                 je 0x4f1d1b
// 004f1d15  3b7c2428             cmp edi, dword ptr [esp + 0x28]
// 004f1d19  7406                 je 0x4f1d21
// 004f1d1b  ff15d8e67700         call dword ptr [0x77e6d8]
// 004f1d21  3b5c242c             cmp ebx, dword ptr [esp + 0x2c]
// 004f1d25  7421                 je 0x4f1d48
// 004f1d27  8d4c2420             lea ecx, [esp + 0x20]
// 004f1d2b  e850b01100           call 0x60cd80
// 004f1d30  53                   push ebx
// 004f1d31  57                   push edi
// 004f1d32  8d542418             lea edx, [esp + 0x18]
// 004f1d36  52                   push edx
// 004f1d37  8bce                 mov ecx, esi
// 004f1d39  e822efffff           call 0x4f0c60
// 004f1d3e  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 004f1d42  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 004f1d46  ebc9                 jmp 0x4f1d11
// 004f1d48  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 004f1d4c  8938                 mov dword ptr [eax], edi
// 004f1d4e  5f                   pop edi
// 004f1d4f  5e                   pop esi
// 004f1d50  5d                   pop ebp
// 004f1d51  895804               mov dword ptr [eax + 4], ebx
// 004f1d54  5b                   pop ebx
// 004f1d55  83c408               add esp, 8
// 004f1d58  c21400               ret 0x14
// standard library set<ptr> (function ?erase@?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE?AViterator@12@V312@0@Z)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
