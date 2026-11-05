// from server: 100% by auto
// roc 2010-06 0076c220  unit: RBX::Network::$$A6AXABVChatMessage::?$signal::slot  size: 220 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0076c220
//
// 0076c220  83ec08               sub esp, 8
// 0076c223  53                   push ebx
// 0076c224  55                   push ebp
// 0076c225  8b2d0ca99e00         mov ebp, dword ptr [0x9ea90c]
// 0076c22b  56                   push esi
// 0076c22c  8bf1                 mov esi, ecx
// 0076c22e  8b4618               mov eax, dword ptr [esi + 0x18]
// 0076c231  8b18                 mov ebx, dword ptr [eax]
// 0076c233  8b06                 mov eax, dword ptr [esi]
// 0076c235  57                   push edi
// 0076c236  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 0076c23a  85ff                 test edi, edi
// 0076c23c  7404                 je 0x76c242
// 0076c23e  3bf8                 cmp edi, eax
// 0076c240  7406                 je 0x76c248
// 0076c242  ffd5                 call ebp
// 0076c244  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 0076c248  395c2424             cmp dword ptr [esp + 0x24], ebx
// 0076c24c  7562                 jne 0x76c2b0
// 0076c24e  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 0076c252  8b5e18               mov ebx, dword ptr [esi + 0x18]
// 0076c255  8b06                 mov eax, dword ptr [esi]
// 0076c257  85c9                 test ecx, ecx
// 0076c259  7404                 je 0x76c25f
// 0076c25b  3bc8                 cmp ecx, eax
// 0076c25d  7406                 je 0x76c265
// 0076c25f  ffd5                 call ebp
// 0076c261  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 0076c265  395c242c             cmp dword ptr [esp + 0x2c], ebx
// 0076c269  7545                 jne 0x76c2b0
// 0076c26b  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 0076c26e  8b5104               mov edx, dword ptr [ecx + 4]
// 0076c271  52                   push edx
// 0076c272  8bce                 mov ecx, esi
// 0076c274  e817f9ffff           call 0x76bb90
// 0076c279  8b4618               mov eax, dword ptr [esi + 0x18]
// 0076c27c  894004               mov dword ptr [eax + 4], eax
// 0076c27f  8b4618               mov eax, dword ptr [esi + 0x18]
// 0076c282  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 0076c289  8900                 mov dword ptr [eax], eax
// 0076c28b  8b4618               mov eax, dword ptr [esi + 0x18]
// 0076c28e  894008               mov dword ptr [eax + 8], eax
// 0076c291  8b4618               mov eax, dword ptr [esi + 0x18]
// 0076c294  8b16                 mov edx, dword ptr [esi]
// 0076c296  8b08                 mov ecx, dword ptr [eax]
// 0076c298  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0076c29c  5f                   pop edi
// 0076c29d  5e                   pop esi
// 0076c29e  5d                   pop ebp
// 0076c29f  894804               mov dword ptr [eax + 4], ecx
// 0076c2a2  8910                 mov dword ptr [eax], edx
// 0076c2a4  5b                   pop ebx
// 0076c2a5  83c408               add esp, 8
// 0076c2a8  c21400               ret 0x14
// 0076c2ab  eb03                 jmp 0x76c2b0
// 0076c2ad  8d4900               lea ecx, [ecx]
// 0076c2b0  85ff                 test edi, edi
// 0076c2b2  7406                 je 0x76c2ba
// 0076c2b4  3b7c2428             cmp edi, dword ptr [esp + 0x28]
// 0076c2b8  7406                 je 0x76c2c0
// 0076c2ba  ffd5                 call ebp
// 0076c2bc  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 0076c2c0  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 0076c2c4  3b5c242c             cmp ebx, dword ptr [esp + 0x2c]
// 0076c2c8  741d                 je 0x76c2e7
// 0076c2ca  8d4c2420             lea ecx, [esp + 0x20]
// 0076c2ce  e80dedffff           call 0x76afe0
// 0076c2d3  53                   push ebx
// 0076c2d4  57                   push edi
// 0076c2d5  8d442418             lea eax, [esp + 0x18]
// 0076c2d9  50                   push eax
// 0076c2da  8bce                 mov ecx, esi
// 0076c2dc  e87ffbffff           call 0x76be60
// 0076c2e1  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 0076c2e5  ebc9                 jmp 0x76c2b0
// 0076c2e7  8b36                 mov esi, dword ptr [esi]
// 0076c2e9  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0076c2ed  5f                   pop edi
// 0076c2ee  8930                 mov dword ptr [eax], esi
// 0076c2f0  5e                   pop esi
// 0076c2f1  5d                   pop ebp
// 0076c2f2  895804               mov dword ptr [eax + 4], ebx
// 0076c2f5  5b                   pop ebx
// 0076c2f6  83c408               add esp, 8
// 0076c2f9  c21400               ret 0x14
// standard library set<ptr> (function ?erase@?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE?AViterator@12@Vconst_iterator@12@0@Z)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
