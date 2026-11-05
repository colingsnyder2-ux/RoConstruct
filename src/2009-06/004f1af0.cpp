// from server: 100% by auto
// roc 2009-06 004f1af0  unit: RBX::Network::VReplicator::?$EventDesc  size: 220 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004f1af0
//
// 004f1af0  83ec08               sub esp, 8
// 004f1af3  53                   push ebx
// 004f1af4  55                   push ebp
// 004f1af5  8b2dace98900         mov ebp, dword ptr [0x89e9ac]
// 004f1afb  56                   push esi
// 004f1afc  8bf1                 mov esi, ecx
// 004f1afe  8b4618               mov eax, dword ptr [esi + 0x18]
// 004f1b01  8b18                 mov ebx, dword ptr [eax]
// 004f1b03  8b06                 mov eax, dword ptr [esi]
// 004f1b05  57                   push edi
// 004f1b06  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 004f1b0a  85ff                 test edi, edi
// 004f1b0c  7404                 je 0x4f1b12
// 004f1b0e  3bf8                 cmp edi, eax
// 004f1b10  7406                 je 0x4f1b18
// 004f1b12  ffd5                 call ebp
// 004f1b14  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 004f1b18  395c2424             cmp dword ptr [esp + 0x24], ebx
// 004f1b1c  7562                 jne 0x4f1b80
// 004f1b1e  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 004f1b22  8b5e18               mov ebx, dword ptr [esi + 0x18]
// 004f1b25  8b06                 mov eax, dword ptr [esi]
// 004f1b27  85c9                 test ecx, ecx
// 004f1b29  7404                 je 0x4f1b2f
// 004f1b2b  3bc8                 cmp ecx, eax
// 004f1b2d  7406                 je 0x4f1b35
// 004f1b2f  ffd5                 call ebp
// 004f1b31  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 004f1b35  395c242c             cmp dword ptr [esp + 0x2c], ebx
// 004f1b39  7545                 jne 0x4f1b80
// 004f1b3b  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 004f1b3e  8b5104               mov edx, dword ptr [ecx + 4]
// 004f1b41  52                   push edx
// 004f1b42  8bce                 mov ecx, esi
// 004f1b44  e8b7deffff           call 0x4efa00
// 004f1b49  8b4618               mov eax, dword ptr [esi + 0x18]
// 004f1b4c  894004               mov dword ptr [eax + 4], eax
// 004f1b4f  8b4618               mov eax, dword ptr [esi + 0x18]
// 004f1b52  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 004f1b59  8900                 mov dword ptr [eax], eax
// 004f1b5b  8b4618               mov eax, dword ptr [esi + 0x18]
// 004f1b5e  894008               mov dword ptr [eax + 8], eax
// 004f1b61  8b4618               mov eax, dword ptr [esi + 0x18]
// 004f1b64  8b16                 mov edx, dword ptr [esi]
// 004f1b66  8b08                 mov ecx, dword ptr [eax]
// 004f1b68  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 004f1b6c  5f                   pop edi
// 004f1b6d  5e                   pop esi
// 004f1b6e  5d                   pop ebp
// 004f1b6f  894804               mov dword ptr [eax + 4], ecx
// 004f1b72  8910                 mov dword ptr [eax], edx
// 004f1b74  5b                   pop ebx
// 004f1b75  83c408               add esp, 8
// 004f1b78  c21400               ret 0x14
// 004f1b7b  eb03                 jmp 0x4f1b80
// 004f1b7d  8d4900               lea ecx, [ecx]
// 004f1b80  85ff                 test edi, edi
// 004f1b82  7406                 je 0x4f1b8a
// 004f1b84  3b7c2428             cmp edi, dword ptr [esp + 0x28]
// 004f1b88  7406                 je 0x4f1b90
// 004f1b8a  ffd5                 call ebp
// 004f1b8c  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 004f1b90  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 004f1b94  3b5c242c             cmp ebx, dword ptr [esp + 0x2c]
// 004f1b98  741d                 je 0x4f1bb7
// 004f1b9a  8d4c2420             lea ecx, [esp + 0x20]
// 004f1b9e  e86dce1400           call 0x63ea10
// 004f1ba3  53                   push ebx
// 004f1ba4  57                   push edi
// 004f1ba5  8d442418             lea eax, [esp + 0x18]
// 004f1ba9  50                   push eax
// 004f1baa  8bce                 mov ecx, esi
// 004f1bac  e82fe2feff           call 0x4dfde0
// 004f1bb1  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 004f1bb5  ebc9                 jmp 0x4f1b80
// 004f1bb7  8b36                 mov esi, dword ptr [esi]
// 004f1bb9  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 004f1bbd  5f                   pop edi
// 004f1bbe  8930                 mov dword ptr [eax], esi
// 004f1bc0  5e                   pop esi
// 004f1bc1  5d                   pop ebp
// 004f1bc2  895804               mov dword ptr [eax + 4], ebx
// 004f1bc5  5b                   pop ebx
// 004f1bc6  83c408               add esp, 8
// 004f1bc9  c21400               ret 0x14
// standard library set<ptr> (function ?erase@?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE?AViterator@12@Vconst_iterator@12@0@Z)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
