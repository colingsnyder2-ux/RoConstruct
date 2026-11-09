// from server: 100% by auto
// roc 2009-06 005dd1e0  unit: RBX::VInstance::?$NonFactoryProduct  size: 220 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 005dd1e0
//
// 005dd1e0  83ec08               sub esp, 8
// 005dd1e3  53                   push ebx
// 005dd1e4  55                   push ebp
// 005dd1e5  8b2dace98900         mov ebp, dword ptr [0x89e9ac]
// 005dd1eb  56                   push esi
// 005dd1ec  8bf1                 mov esi, ecx
// 005dd1ee  8b4618               mov eax, dword ptr [esi + 0x18]
// 005dd1f1  8b18                 mov ebx, dword ptr [eax]
// 005dd1f3  8b06                 mov eax, dword ptr [esi]
// 005dd1f5  57                   push edi
// 005dd1f6  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 005dd1fa  85ff                 test edi, edi
// 005dd1fc  7404                 je 0x5dd202
// 005dd1fe  3bf8                 cmp edi, eax
// 005dd200  7406                 je 0x5dd208
// 005dd202  ffd5                 call ebp
// 005dd204  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 005dd208  395c2424             cmp dword ptr [esp + 0x24], ebx
// 005dd20c  7562                 jne 0x5dd270
// 005dd20e  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 005dd212  8b5e18               mov ebx, dword ptr [esi + 0x18]
// 005dd215  8b06                 mov eax, dword ptr [esi]
// 005dd217  85c9                 test ecx, ecx
// 005dd219  7404                 je 0x5dd21f
// 005dd21b  3bc8                 cmp ecx, eax
// 005dd21d  7406                 je 0x5dd225
// 005dd21f  ffd5                 call ebp
// 005dd221  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 005dd225  395c242c             cmp dword ptr [esp + 0x2c], ebx
// 005dd229  7545                 jne 0x5dd270
// 005dd22b  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 005dd22e  8b5104               mov edx, dword ptr [ecx + 4]
// 005dd231  52                   push edx
// 005dd232  8bce                 mov ecx, esi
// 005dd234  e8a7e7ffff           call 0x5db9e0
// 005dd239  8b4618               mov eax, dword ptr [esi + 0x18]
// 005dd23c  894004               mov dword ptr [eax + 4], eax
// 005dd23f  8b4618               mov eax, dword ptr [esi + 0x18]
// 005dd242  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 005dd249  8900                 mov dword ptr [eax], eax
// 005dd24b  8b4618               mov eax, dword ptr [esi + 0x18]
// 005dd24e  894008               mov dword ptr [eax + 8], eax
// 005dd251  8b4618               mov eax, dword ptr [esi + 0x18]
// 005dd254  8b16                 mov edx, dword ptr [esi]
// 005dd256  8b08                 mov ecx, dword ptr [eax]
// 005dd258  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 005dd25c  5f                   pop edi
// 005dd25d  5e                   pop esi
// 005dd25e  5d                   pop ebp
// 005dd25f  894804               mov dword ptr [eax + 4], ecx
// 005dd262  8910                 mov dword ptr [eax], edx
// 005dd264  5b                   pop ebx
// 005dd265  83c408               add esp, 8
// 005dd268  c21400               ret 0x14
// 005dd26b  eb03                 jmp 0x5dd270
// 005dd26d  8d4900               lea ecx, [ecx]
// 005dd270  85ff                 test edi, edi
// 005dd272  7406                 je 0x5dd27a
// 005dd274  3b7c2428             cmp edi, dword ptr [esp + 0x28]
// 005dd278  7406                 je 0x5dd280
// 005dd27a  ffd5                 call ebp
// 005dd27c  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 005dd280  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 005dd284  3b5c242c             cmp ebx, dword ptr [esp + 0x2c]
// 005dd288  741d                 je 0x5dd2a7
// 005dd28a  8d4c2420             lea ecx, [esp + 0x20]
// 005dd28e  e89dbdffff           call 0x5d9030
// 005dd293  53                   push ebx
// 005dd294  57                   push edi
// 005dd295  8d442418             lea eax, [esp + 0x18]
// 005dd299  50                   push eax
// 005dd29a  8bce                 mov ecx, esi
// 005dd29c  e84fedffff           call 0x5dbff0
// 005dd2a1  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 005dd2a5  ebc9                 jmp 0x5dd270
// 005dd2a7  8b36                 mov esi, dword ptr [esi]
// 005dd2a9  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 005dd2ad  5f                   pop edi
// 005dd2ae  8930                 mov dword ptr [eax], esi
// 005dd2b0  5e                   pop esi
// 005dd2b1  5d                   pop ebp
// 005dd2b2  895804               mov dword ptr [eax + 4], ebx
// 005dd2b5  5b                   pop ebx
// 005dd2b6  83c408               add esp, 8
// 005dd2b9  c21400               ret 0x14
// standard library set<ptr> (function ?erase@?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE?AViterator@12@Vconst_iterator@12@0@Z)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
