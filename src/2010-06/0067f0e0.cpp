// from server: 100% by auto
// roc 2010-06 0067f0e0  unit: RBX::VInstance::?$NonFactoryProduct  size: 220 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0067f0e0
//
// 0067f0e0  83ec08               sub esp, 8
// 0067f0e3  53                   push ebx
// 0067f0e4  55                   push ebp
// 0067f0e5  8b2d0ca99e00         mov ebp, dword ptr [0x9ea90c]
// 0067f0eb  56                   push esi
// 0067f0ec  8bf1                 mov esi, ecx
// 0067f0ee  8b4618               mov eax, dword ptr [esi + 0x18]
// 0067f0f1  8b18                 mov ebx, dword ptr [eax]
// 0067f0f3  8b06                 mov eax, dword ptr [esi]
// 0067f0f5  57                   push edi
// 0067f0f6  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 0067f0fa  85ff                 test edi, edi
// 0067f0fc  7404                 je 0x67f102
// 0067f0fe  3bf8                 cmp edi, eax
// 0067f100  7406                 je 0x67f108
// 0067f102  ffd5                 call ebp
// 0067f104  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 0067f108  395c2424             cmp dword ptr [esp + 0x24], ebx
// 0067f10c  7562                 jne 0x67f170
// 0067f10e  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 0067f112  8b5e18               mov ebx, dword ptr [esi + 0x18]
// 0067f115  8b06                 mov eax, dword ptr [esi]
// 0067f117  85c9                 test ecx, ecx
// 0067f119  7404                 je 0x67f11f
// 0067f11b  3bc8                 cmp ecx, eax
// 0067f11d  7406                 je 0x67f125
// 0067f11f  ffd5                 call ebp
// 0067f121  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 0067f125  395c242c             cmp dword ptr [esp + 0x2c], ebx
// 0067f129  7545                 jne 0x67f170
// 0067f12b  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 0067f12e  8b5104               mov edx, dword ptr [ecx + 4]
// 0067f131  52                   push edx
// 0067f132  8bce                 mov ecx, esi
// 0067f134  e817deffff           call 0x67cf50
// 0067f139  8b4618               mov eax, dword ptr [esi + 0x18]
// 0067f13c  894004               mov dword ptr [eax + 4], eax
// 0067f13f  8b4618               mov eax, dword ptr [esi + 0x18]
// 0067f142  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 0067f149  8900                 mov dword ptr [eax], eax
// 0067f14b  8b4618               mov eax, dword ptr [esi + 0x18]
// 0067f14e  894008               mov dword ptr [eax + 8], eax
// 0067f151  8b4618               mov eax, dword ptr [esi + 0x18]
// 0067f154  8b16                 mov edx, dword ptr [esi]
// 0067f156  8b08                 mov ecx, dword ptr [eax]
// 0067f158  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0067f15c  5f                   pop edi
// 0067f15d  5e                   pop esi
// 0067f15e  5d                   pop ebp
// 0067f15f  894804               mov dword ptr [eax + 4], ecx
// 0067f162  8910                 mov dword ptr [eax], edx
// 0067f164  5b                   pop ebx
// 0067f165  83c408               add esp, 8
// 0067f168  c21400               ret 0x14
// 0067f16b  eb03                 jmp 0x67f170
// 0067f16d  8d4900               lea ecx, [ecx]
// 0067f170  85ff                 test edi, edi
// 0067f172  7406                 je 0x67f17a
// 0067f174  3b7c2428             cmp edi, dword ptr [esp + 0x28]
// 0067f178  7406                 je 0x67f180
// 0067f17a  ffd5                 call ebp
// 0067f17c  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 0067f180  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 0067f184  3b5c242c             cmp ebx, dword ptr [esp + 0x2c]
// 0067f188  741d                 je 0x67f1a7
// 0067f18a  8d4c2420             lea ecx, [esp + 0x20]
// 0067f18e  e81d03feff           call 0x65f4b0
// 0067f193  53                   push ebx
// 0067f194  57                   push edi
// 0067f195  8d442418             lea eax, [esp + 0x18]
// 0067f199  50                   push eax
// 0067f19a  8bce                 mov ecx, esi
// 0067f19c  e8afdaffff           call 0x67cc50
// 0067f1a1  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 0067f1a5  ebc9                 jmp 0x67f170
// 0067f1a7  8b36                 mov esi, dword ptr [esi]
// 0067f1a9  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0067f1ad  5f                   pop edi
// 0067f1ae  8930                 mov dword ptr [eax], esi
// 0067f1b0  5e                   pop esi
// 0067f1b1  5d                   pop ebp
// 0067f1b2  895804               mov dword ptr [eax + 4], ebx
// 0067f1b5  5b                   pop ebx
// 0067f1b6  83c408               add esp, 8
// 0067f1b9  c21400               ret 0x14
// standard library set<ptr> (function ?erase@?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE?AViterator@12@Vconst_iterator@12@0@Z)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
