// from server: 100% by auto
// roc 2008-06 004b8a80  unit: RBX::Network::Server::ClientProxy  size: 220 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004b8a80
//
// 004b8a80  83ec08               sub esp, 8
// 004b8a83  53                   push ebx
// 004b8a84  55                   push ebp
// 004b8a85  8b2d90288000         mov ebp, dword ptr [0x802890]
// 004b8a8b  56                   push esi
// 004b8a8c  8bf1                 mov esi, ecx
// 004b8a8e  8b4618               mov eax, dword ptr [esi + 0x18]
// 004b8a91  8b18                 mov ebx, dword ptr [eax]
// 004b8a93  8b06                 mov eax, dword ptr [esi]
// 004b8a95  57                   push edi
// 004b8a96  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 004b8a9a  85ff                 test edi, edi
// 004b8a9c  7404                 je 0x4b8aa2
// 004b8a9e  3bf8                 cmp edi, eax
// 004b8aa0  7406                 je 0x4b8aa8
// 004b8aa2  ffd5                 call ebp
// 004b8aa4  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 004b8aa8  395c2424             cmp dword ptr [esp + 0x24], ebx
// 004b8aac  7562                 jne 0x4b8b10
// 004b8aae  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 004b8ab2  8b5e18               mov ebx, dword ptr [esi + 0x18]
// 004b8ab5  8b06                 mov eax, dword ptr [esi]
// 004b8ab7  85c9                 test ecx, ecx
// 004b8ab9  7404                 je 0x4b8abf
// 004b8abb  3bc8                 cmp ecx, eax
// 004b8abd  7406                 je 0x4b8ac5
// 004b8abf  ffd5                 call ebp
// 004b8ac1  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 004b8ac5  395c242c             cmp dword ptr [esp + 0x2c], ebx
// 004b8ac9  7545                 jne 0x4b8b10
// 004b8acb  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 004b8ace  8b5104               mov edx, dword ptr [ecx + 4]
// 004b8ad1  52                   push edx
// 004b8ad2  8bce                 mov ecx, esi
// 004b8ad4  e837f3ffff           call 0x4b7e10
// 004b8ad9  8b4618               mov eax, dword ptr [esi + 0x18]
// 004b8adc  894004               mov dword ptr [eax + 4], eax
// 004b8adf  8b4618               mov eax, dword ptr [esi + 0x18]
// 004b8ae2  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 004b8ae9  8900                 mov dword ptr [eax], eax
// 004b8aeb  8b4618               mov eax, dword ptr [esi + 0x18]
// 004b8aee  894008               mov dword ptr [eax + 8], eax
// 004b8af1  8b4618               mov eax, dword ptr [esi + 0x18]
// 004b8af4  8b16                 mov edx, dword ptr [esi]
// 004b8af6  8b08                 mov ecx, dword ptr [eax]
// 004b8af8  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 004b8afc  5f                   pop edi
// 004b8afd  5e                   pop esi
// 004b8afe  5d                   pop ebp
// 004b8aff  894804               mov dword ptr [eax + 4], ecx
// 004b8b02  8910                 mov dword ptr [eax], edx
// 004b8b04  5b                   pop ebx
// 004b8b05  83c408               add esp, 8
// 004b8b08  c21400               ret 0x14
// 004b8b0b  eb03                 jmp 0x4b8b10
// 004b8b0d  8d4900               lea ecx, [ecx]
// 004b8b10  85ff                 test edi, edi
// 004b8b12  7406                 je 0x4b8b1a
// 004b8b14  3b7c2428             cmp edi, dword ptr [esp + 0x28]
// 004b8b18  7406                 je 0x4b8b20
// 004b8b1a  ffd5                 call ebp
// 004b8b1c  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 004b8b20  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 004b8b24  3b5c242c             cmp ebx, dword ptr [esp + 0x2c]
// 004b8b28  741d                 je 0x4b8b47
// 004b8b2a  8d4c2420             lea ecx, [esp + 0x20]
// 004b8b2e  e86d461d00           call 0x68d1a0
// 004b8b33  53                   push ebx
// 004b8b34  57                   push edi
// 004b8b35  8d442418             lea eax, [esp + 0x18]
// 004b8b39  50                   push eax
// 004b8b3a  8bce                 mov ecx, esi
// 004b8b3c  e80f02ffff           call 0x4a8d50
// 004b8b41  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 004b8b45  ebc9                 jmp 0x4b8b10
// 004b8b47  8b36                 mov esi, dword ptr [esi]
// 004b8b49  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 004b8b4d  5f                   pop edi
// 004b8b4e  8930                 mov dword ptr [eax], esi
// 004b8b50  5e                   pop esi
// 004b8b51  5d                   pop ebp
// 004b8b52  895804               mov dword ptr [eax + 4], ebx
// 004b8b55  5b                   pop ebx
// 004b8b56  83c408               add esp, 8
// 004b8b59  c21400               ret 0x14
// standard library set<ptr> (function ?erase@?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE?AViterator@12@Vconst_iterator@12@0@Z)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
