// from server: 100% by auto
// roc 2008-06 00442270  unit: TextureItem  size: 220 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00442270
//
// 00442270  83ec08               sub esp, 8
// 00442273  53                   push ebx
// 00442274  55                   push ebp
// 00442275  8b2d90288000         mov ebp, dword ptr [0x802890]
// 0044227b  56                   push esi
// 0044227c  8bf1                 mov esi, ecx
// 0044227e  8b4618               mov eax, dword ptr [esi + 0x18]
// 00442281  8b18                 mov ebx, dword ptr [eax]
// 00442283  8b06                 mov eax, dword ptr [esi]
// 00442285  57                   push edi
// 00442286  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 0044228a  85ff                 test edi, edi
// 0044228c  7404                 je 0x442292
// 0044228e  3bf8                 cmp edi, eax
// 00442290  7406                 je 0x442298
// 00442292  ffd5                 call ebp
// 00442294  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00442298  395c2424             cmp dword ptr [esp + 0x24], ebx
// 0044229c  7562                 jne 0x442300
// 0044229e  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 004422a2  8b5e18               mov ebx, dword ptr [esi + 0x18]
// 004422a5  8b06                 mov eax, dword ptr [esi]
// 004422a7  85c9                 test ecx, ecx
// 004422a9  7404                 je 0x4422af
// 004422ab  3bc8                 cmp ecx, eax
// 004422ad  7406                 je 0x4422b5
// 004422af  ffd5                 call ebp
// 004422b1  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 004422b5  395c242c             cmp dword ptr [esp + 0x2c], ebx
// 004422b9  7545                 jne 0x442300
// 004422bb  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 004422be  8b5104               mov edx, dword ptr [ecx + 4]
// 004422c1  52                   push edx
// 004422c2  8bce                 mov ecx, esi
// 004422c4  e837feffff           call 0x442100
// 004422c9  8b4618               mov eax, dword ptr [esi + 0x18]
// 004422cc  894004               mov dword ptr [eax + 4], eax
// 004422cf  8b4618               mov eax, dword ptr [esi + 0x18]
// 004422d2  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 004422d9  8900                 mov dword ptr [eax], eax
// 004422db  8b4618               mov eax, dword ptr [esi + 0x18]
// 004422de  894008               mov dword ptr [eax + 8], eax
// 004422e1  8b4618               mov eax, dword ptr [esi + 0x18]
// 004422e4  8b16                 mov edx, dword ptr [esi]
// 004422e6  8b08                 mov ecx, dword ptr [eax]
// 004422e8  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 004422ec  5f                   pop edi
// 004422ed  5e                   pop esi
// 004422ee  5d                   pop ebp
// 004422ef  894804               mov dword ptr [eax + 4], ecx
// 004422f2  8910                 mov dword ptr [eax], edx
// 004422f4  5b                   pop ebx
// 004422f5  83c408               add esp, 8
// 004422f8  c21400               ret 0x14
// 004422fb  eb03                 jmp 0x442300
// 004422fd  8d4900               lea ecx, [ecx]
// 00442300  85ff                 test edi, edi
// 00442302  7406                 je 0x44230a
// 00442304  3b7c2428             cmp edi, dword ptr [esp + 0x28]
// 00442308  7406                 je 0x442310
// 0044230a  ffd5                 call ebp
// 0044230c  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00442310  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 00442314  3b5c242c             cmp ebx, dword ptr [esp + 0x2c]
// 00442318  741d                 je 0x442337
// 0044231a  8d4c2420             lea ecx, [esp + 0x20]
// 0044231e  e84d64ffff           call 0x438770
// 00442323  53                   push ebx
// 00442324  57                   push edi
// 00442325  8d442418             lea eax, [esp + 0x18]
// 00442329  50                   push eax
// 0044232a  8bce                 mov ecx, esi
// 0044232c  e8aff5ffff           call 0x4418e0
// 00442331  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00442335  ebc9                 jmp 0x442300
// 00442337  8b36                 mov esi, dword ptr [esi]
// 00442339  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0044233d  5f                   pop edi
// 0044233e  8930                 mov dword ptr [eax], esi
// 00442340  5e                   pop esi
// 00442341  5d                   pop ebp
// 00442342  895804               mov dword ptr [eax + 4], ebx
// 00442345  5b                   pop ebx
// 00442346  83c408               add esp, 8
// 00442349  c21400               ret 0x14
// standard library set<ptr> (function ?erase@?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE?AViterator@12@Vconst_iterator@12@0@Z)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
