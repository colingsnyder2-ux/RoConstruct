// from server: 100% by auto
// roc 2009-12 0053f1e0  unit: RBX::Network::Replicator::NewInstanceItem  size: 220 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0053f1e0
//
// 0053f1e0  83ec08               sub esp, 8
// 0053f1e3  53                   push ebx
// 0053f1e4  55                   push ebp
// 0053f1e5  8b2d60b79800         mov ebp, dword ptr [0x98b760]
// 0053f1eb  56                   push esi
// 0053f1ec  8bf1                 mov esi, ecx
// 0053f1ee  8b4618               mov eax, dword ptr [esi + 0x18]
// 0053f1f1  8b18                 mov ebx, dword ptr [eax]
// 0053f1f3  8b06                 mov eax, dword ptr [esi]
// 0053f1f5  57                   push edi
// 0053f1f6  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 0053f1fa  85ff                 test edi, edi
// 0053f1fc  7404                 je 0x53f202
// 0053f1fe  3bf8                 cmp edi, eax
// 0053f200  7406                 je 0x53f208
// 0053f202  ffd5                 call ebp
// 0053f204  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 0053f208  395c2424             cmp dword ptr [esp + 0x24], ebx
// 0053f20c  7562                 jne 0x53f270
// 0053f20e  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 0053f212  8b5e18               mov ebx, dword ptr [esi + 0x18]
// 0053f215  8b06                 mov eax, dword ptr [esi]
// 0053f217  85c9                 test ecx, ecx
// 0053f219  7404                 je 0x53f21f
// 0053f21b  3bc8                 cmp ecx, eax
// 0053f21d  7406                 je 0x53f225
// 0053f21f  ffd5                 call ebp
// 0053f221  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 0053f225  395c242c             cmp dword ptr [esp + 0x2c], ebx
// 0053f229  7545                 jne 0x53f270
// 0053f22b  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 0053f22e  8b5104               mov edx, dword ptr [ecx + 4]
// 0053f231  52                   push edx
// 0053f232  8bce                 mov ecx, esi
// 0053f234  e857ecffff           call 0x53de90
// 0053f239  8b4618               mov eax, dword ptr [esi + 0x18]
// 0053f23c  894004               mov dword ptr [eax + 4], eax
// 0053f23f  8b4618               mov eax, dword ptr [esi + 0x18]
// 0053f242  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 0053f249  8900                 mov dword ptr [eax], eax
// 0053f24b  8b4618               mov eax, dword ptr [esi + 0x18]
// 0053f24e  894008               mov dword ptr [eax + 8], eax
// 0053f251  8b4618               mov eax, dword ptr [esi + 0x18]
// 0053f254  8b16                 mov edx, dword ptr [esi]
// 0053f256  8b08                 mov ecx, dword ptr [eax]
// 0053f258  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0053f25c  5f                   pop edi
// 0053f25d  5e                   pop esi
// 0053f25e  5d                   pop ebp
// 0053f25f  894804               mov dword ptr [eax + 4], ecx
// 0053f262  8910                 mov dword ptr [eax], edx
// 0053f264  5b                   pop ebx
// 0053f265  83c408               add esp, 8
// 0053f268  c21400               ret 0x14
// 0053f26b  eb03                 jmp 0x53f270
// 0053f26d  8d4900               lea ecx, [ecx]
// 0053f270  85ff                 test edi, edi
// 0053f272  7406                 je 0x53f27a
// 0053f274  3b7c2428             cmp edi, dword ptr [esp + 0x28]
// 0053f278  7406                 je 0x53f280
// 0053f27a  ffd5                 call ebp
// 0053f27c  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 0053f280  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 0053f284  3b5c242c             cmp ebx, dword ptr [esp + 0x2c]
// 0053f288  741d                 je 0x53f2a7
// 0053f28a  8d4c2420             lea ecx, [esp + 0x20]
// 0053f28e  e80d481700           call 0x6b3aa0
// 0053f293  53                   push ebx
// 0053f294  57                   push edi
// 0053f295  8d442418             lea eax, [esp + 0x18]
// 0053f299  50                   push eax
// 0053f29a  8bce                 mov ecx, esi
// 0053f29c  e8afe7ffff           call 0x53da50
// 0053f2a1  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 0053f2a5  ebc9                 jmp 0x53f270
// 0053f2a7  8b36                 mov esi, dword ptr [esi]
// 0053f2a9  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0053f2ad  5f                   pop edi
// 0053f2ae  8930                 mov dword ptr [eax], esi
// 0053f2b0  5e                   pop esi
// 0053f2b1  5d                   pop ebp
// 0053f2b2  895804               mov dword ptr [eax + 4], ebx
// 0053f2b5  5b                   pop ebx
// 0053f2b6  83c408               add esp, 8
// 0053f2b9  c21400               ret 0x14
// standard library set<ptr> (function ?erase@?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE?AViterator@12@Vconst_iterator@12@0@Z)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
