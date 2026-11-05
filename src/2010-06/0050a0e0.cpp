// from server: 100% by auto
// roc 2010-06 0050a0e0  unit: RBX::Network::ServerReplicator  size: 220 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0050a0e0
//
// 0050a0e0  83ec08               sub esp, 8
// 0050a0e3  53                   push ebx
// 0050a0e4  55                   push ebp
// 0050a0e5  8b2d0ca99e00         mov ebp, dword ptr [0x9ea90c]
// 0050a0eb  56                   push esi
// 0050a0ec  8bf1                 mov esi, ecx
// 0050a0ee  8b4618               mov eax, dword ptr [esi + 0x18]
// 0050a0f1  8b18                 mov ebx, dword ptr [eax]
// 0050a0f3  8b06                 mov eax, dword ptr [esi]
// 0050a0f5  57                   push edi
// 0050a0f6  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 0050a0fa  85ff                 test edi, edi
// 0050a0fc  7404                 je 0x50a102
// 0050a0fe  3bf8                 cmp edi, eax
// 0050a100  7406                 je 0x50a108
// 0050a102  ffd5                 call ebp
// 0050a104  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 0050a108  395c2424             cmp dword ptr [esp + 0x24], ebx
// 0050a10c  7562                 jne 0x50a170
// 0050a10e  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 0050a112  8b5e18               mov ebx, dword ptr [esi + 0x18]
// 0050a115  8b06                 mov eax, dword ptr [esi]
// 0050a117  85c9                 test ecx, ecx
// 0050a119  7404                 je 0x50a11f
// 0050a11b  3bc8                 cmp ecx, eax
// 0050a11d  7406                 je 0x50a125
// 0050a11f  ffd5                 call ebp
// 0050a121  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 0050a125  395c242c             cmp dword ptr [esp + 0x2c], ebx
// 0050a129  7545                 jne 0x50a170
// 0050a12b  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 0050a12e  8b5104               mov edx, dword ptr [ecx + 4]
// 0050a131  52                   push edx
// 0050a132  8bce                 mov ecx, esi
// 0050a134  e867f8ffff           call 0x5099a0
// 0050a139  8b4618               mov eax, dword ptr [esi + 0x18]
// 0050a13c  894004               mov dword ptr [eax + 4], eax
// 0050a13f  8b4618               mov eax, dword ptr [esi + 0x18]
// 0050a142  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 0050a149  8900                 mov dword ptr [eax], eax
// 0050a14b  8b4618               mov eax, dword ptr [esi + 0x18]
// 0050a14e  894008               mov dword ptr [eax + 8], eax
// 0050a151  8b4618               mov eax, dword ptr [esi + 0x18]
// 0050a154  8b16                 mov edx, dword ptr [esi]
// 0050a156  8b08                 mov ecx, dword ptr [eax]
// 0050a158  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0050a15c  5f                   pop edi
// 0050a15d  5e                   pop esi
// 0050a15e  5d                   pop ebp
// 0050a15f  894804               mov dword ptr [eax + 4], ecx
// 0050a162  8910                 mov dword ptr [eax], edx
// 0050a164  5b                   pop ebx
// 0050a165  83c408               add esp, 8
// 0050a168  c21400               ret 0x14
// 0050a16b  eb03                 jmp 0x50a170
// 0050a16d  8d4900               lea ecx, [ecx]
// 0050a170  85ff                 test edi, edi
// 0050a172  7406                 je 0x50a17a
// 0050a174  3b7c2428             cmp edi, dword ptr [esp + 0x28]
// 0050a178  7406                 je 0x50a180
// 0050a17a  ffd5                 call ebp
// 0050a17c  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 0050a180  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 0050a184  3b5c242c             cmp ebx, dword ptr [esp + 0x2c]
// 0050a188  741d                 je 0x50a1a7
// 0050a18a  8d4c2420             lea ecx, [esp + 0x20]
// 0050a18e  e81d542600           call 0x76f5b0
// 0050a193  53                   push ebx
// 0050a194  57                   push edi
// 0050a195  8d442418             lea eax, [esp + 0x18]
// 0050a199  50                   push eax
// 0050a19a  8bce                 mov ecx, esi
// 0050a19c  e8bff9ffff           call 0x509b60
// 0050a1a1  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 0050a1a5  ebc9                 jmp 0x50a170
// 0050a1a7  8b36                 mov esi, dword ptr [esi]
// 0050a1a9  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0050a1ad  5f                   pop edi
// 0050a1ae  8930                 mov dword ptr [eax], esi
// 0050a1b0  5e                   pop esi
// 0050a1b1  5d                   pop ebp
// 0050a1b2  895804               mov dword ptr [eax + 4], ebx
// 0050a1b5  5b                   pop ebx
// 0050a1b6  83c408               add esp, 8
// 0050a1b9  c21400               ret 0x14
// standard library set<ptr> (function ?erase@?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE?AViterator@12@Vconst_iterator@12@0@Z)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
