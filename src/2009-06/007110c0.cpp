// from server: 100% by auto
// roc 2009-06 007110c0  unit: boost::iostreams::zlib_error  size: 220 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007110c0
//
// 007110c0  83ec08               sub esp, 8
// 007110c3  53                   push ebx
// 007110c4  55                   push ebp
// 007110c5  8b2dace98900         mov ebp, dword ptr [0x89e9ac]
// 007110cb  56                   push esi
// 007110cc  8bf1                 mov esi, ecx
// 007110ce  8b4618               mov eax, dword ptr [esi + 0x18]
// 007110d1  8b18                 mov ebx, dword ptr [eax]
// 007110d3  8b06                 mov eax, dword ptr [esi]
// 007110d5  57                   push edi
// 007110d6  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 007110da  85ff                 test edi, edi
// 007110dc  7404                 je 0x7110e2
// 007110de  3bf8                 cmp edi, eax
// 007110e0  7406                 je 0x7110e8
// 007110e2  ffd5                 call ebp
// 007110e4  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 007110e8  395c2424             cmp dword ptr [esp + 0x24], ebx
// 007110ec  7562                 jne 0x711150
// 007110ee  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 007110f2  8b5e18               mov ebx, dword ptr [esi + 0x18]
// 007110f5  8b06                 mov eax, dword ptr [esi]
// 007110f7  85c9                 test ecx, ecx
// 007110f9  7404                 je 0x7110ff
// 007110fb  3bc8                 cmp ecx, eax
// 007110fd  7406                 je 0x711105
// 007110ff  ffd5                 call ebp
// 00711101  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00711105  395c242c             cmp dword ptr [esp + 0x2c], ebx
// 00711109  7545                 jne 0x711150
// 0071110b  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 0071110e  8b5104               mov edx, dword ptr [ecx + 4]
// 00711111  52                   push edx
// 00711112  8bce                 mov ecx, esi
// 00711114  e8a7fcffff           call 0x710dc0
// 00711119  8b4618               mov eax, dword ptr [esi + 0x18]
// 0071111c  894004               mov dword ptr [eax + 4], eax
// 0071111f  8b4618               mov eax, dword ptr [esi + 0x18]
// 00711122  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 00711129  8900                 mov dword ptr [eax], eax
// 0071112b  8b4618               mov eax, dword ptr [esi + 0x18]
// 0071112e  894008               mov dword ptr [eax + 8], eax
// 00711131  8b4618               mov eax, dword ptr [esi + 0x18]
// 00711134  8b16                 mov edx, dword ptr [esi]
// 00711136  8b08                 mov ecx, dword ptr [eax]
// 00711138  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0071113c  5f                   pop edi
// 0071113d  5e                   pop esi
// 0071113e  5d                   pop ebp
// 0071113f  894804               mov dword ptr [eax + 4], ecx
// 00711142  8910                 mov dword ptr [eax], edx
// 00711144  5b                   pop ebx
// 00711145  83c408               add esp, 8
// 00711148  c21400               ret 0x14
// 0071114b  eb03                 jmp 0x711150
// 0071114d  8d4900               lea ecx, [ecx]
// 00711150  85ff                 test edi, edi
// 00711152  7406                 je 0x71115a
// 00711154  3b7c2428             cmp edi, dword ptr [esp + 0x28]
// 00711158  7406                 je 0x711160
// 0071115a  ffd5                 call ebp
// 0071115c  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00711160  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 00711164  3b5c242c             cmp ebx, dword ptr [esp + 0x2c]
// 00711168  741d                 je 0x711187
// 0071116a  8d4c2420             lea ecx, [esp + 0x20]
// 0071116e  e8fd7fedff           call 0x5e9170
// 00711173  53                   push ebx
// 00711174  57                   push edi
// 00711175  8d442418             lea eax, [esp + 0x18]
// 00711179  50                   push eax
// 0071117a  8bce                 mov ecx, esi
// 0071117c  e87ffcffff           call 0x710e00
// 00711181  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00711185  ebc9                 jmp 0x711150
// 00711187  8b36                 mov esi, dword ptr [esi]
// 00711189  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0071118d  5f                   pop edi
// 0071118e  8930                 mov dword ptr [eax], esi
// 00711190  5e                   pop esi
// 00711191  5d                   pop ebp
// 00711192  895804               mov dword ptr [eax + 4], ebx
// 00711195  5b                   pop ebx
// 00711196  83c408               add esp, 8
// 00711199  c21400               ret 0x14
// standard library set<ptr> (function ?erase@?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE?AViterator@12@Vconst_iterator@12@0@Z)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
