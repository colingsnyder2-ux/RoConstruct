// from server: 100% by auto
// roc 2008-06 00653170  unit: RBX::ScoreHud  size: 220 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00653170
//
// 00653170  83ec08               sub esp, 8
// 00653173  53                   push ebx
// 00653174  55                   push ebp
// 00653175  8b2d90288000         mov ebp, dword ptr [0x802890]
// 0065317b  56                   push esi
// 0065317c  8bf1                 mov esi, ecx
// 0065317e  8b4618               mov eax, dword ptr [esi + 0x18]
// 00653181  8b18                 mov ebx, dword ptr [eax]
// 00653183  8b06                 mov eax, dword ptr [esi]
// 00653185  57                   push edi
// 00653186  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 0065318a  85ff                 test edi, edi
// 0065318c  7404                 je 0x653192
// 0065318e  3bf8                 cmp edi, eax
// 00653190  7406                 je 0x653198
// 00653192  ffd5                 call ebp
// 00653194  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00653198  395c2424             cmp dword ptr [esp + 0x24], ebx
// 0065319c  7562                 jne 0x653200
// 0065319e  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 006531a2  8b5e18               mov ebx, dword ptr [esi + 0x18]
// 006531a5  8b06                 mov eax, dword ptr [esi]
// 006531a7  85c9                 test ecx, ecx
// 006531a9  7404                 je 0x6531af
// 006531ab  3bc8                 cmp ecx, eax
// 006531ad  7406                 je 0x6531b5
// 006531af  ffd5                 call ebp
// 006531b1  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 006531b5  395c242c             cmp dword ptr [esp + 0x2c], ebx
// 006531b9  7545                 jne 0x653200
// 006531bb  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 006531be  8b5104               mov edx, dword ptr [ecx + 4]
// 006531c1  52                   push edx
// 006531c2  8bce                 mov ecx, esi
// 006531c4  e8e7f1ffff           call 0x6523b0
// 006531c9  8b4618               mov eax, dword ptr [esi + 0x18]
// 006531cc  894004               mov dword ptr [eax + 4], eax
// 006531cf  8b4618               mov eax, dword ptr [esi + 0x18]
// 006531d2  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 006531d9  8900                 mov dword ptr [eax], eax
// 006531db  8b4618               mov eax, dword ptr [esi + 0x18]
// 006531de  894008               mov dword ptr [eax + 8], eax
// 006531e1  8b4618               mov eax, dword ptr [esi + 0x18]
// 006531e4  8b16                 mov edx, dword ptr [esi]
// 006531e6  8b08                 mov ecx, dword ptr [eax]
// 006531e8  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 006531ec  5f                   pop edi
// 006531ed  5e                   pop esi
// 006531ee  5d                   pop ebp
// 006531ef  894804               mov dword ptr [eax + 4], ecx
// 006531f2  8910                 mov dword ptr [eax], edx
// 006531f4  5b                   pop ebx
// 006531f5  83c408               add esp, 8
// 006531f8  c21400               ret 0x14
// 006531fb  eb03                 jmp 0x653200
// 006531fd  8d4900               lea ecx, [ecx]
// 00653200  85ff                 test edi, edi
// 00653202  7406                 je 0x65320a
// 00653204  3b7c2428             cmp edi, dword ptr [esp + 0x28]
// 00653208  7406                 je 0x653210
// 0065320a  ffd5                 call ebp
// 0065320c  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00653210  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 00653214  3b5c242c             cmp ebx, dword ptr [esp + 0x2c]
// 00653218  741d                 je 0x653237
// 0065321a  8d4c2420             lea ecx, [esp + 0x20]
// 0065321e  e84d55deff           call 0x438770
// 00653223  53                   push ebx
// 00653224  57                   push edi
// 00653225  8d442418             lea eax, [esp + 0x18]
// 00653229  50                   push eax
// 0065322a  8bce                 mov ecx, esi
// 0065322c  e81fedffff           call 0x651f50
// 00653231  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00653235  ebc9                 jmp 0x653200
// 00653237  8b36                 mov esi, dword ptr [esi]
// 00653239  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0065323d  5f                   pop edi
// 0065323e  8930                 mov dword ptr [eax], esi
// 00653240  5e                   pop esi
// 00653241  5d                   pop ebp
// 00653242  895804               mov dword ptr [eax + 4], ebx
// 00653245  5b                   pop ebx
// 00653246  83c408               add esp, 8
// 00653249  c21400               ret 0x14
// standard library set<ptr> (function ?erase@?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE?AViterator@12@Vconst_iterator@12@0@Z)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
