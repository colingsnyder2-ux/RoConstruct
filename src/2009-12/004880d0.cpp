// from server: 100% by auto
// roc 2009-12 004880d0  unit: Ogre::GfxClustererPart  size: 220 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 004880d0
//
// 004880d0  83ec08               sub esp, 8
// 004880d3  53                   push ebx
// 004880d4  55                   push ebp
// 004880d5  8b2d60b79800         mov ebp, dword ptr [0x98b760]
// 004880db  56                   push esi
// 004880dc  8bf1                 mov esi, ecx
// 004880de  8b4618               mov eax, dword ptr [esi + 0x18]
// 004880e1  8b18                 mov ebx, dword ptr [eax]
// 004880e3  8b06                 mov eax, dword ptr [esi]
// 004880e5  57                   push edi
// 004880e6  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 004880ea  85ff                 test edi, edi
// 004880ec  7404                 je 0x4880f2
// 004880ee  3bf8                 cmp edi, eax
// 004880f0  7406                 je 0x4880f8
// 004880f2  ffd5                 call ebp
// 004880f4  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 004880f8  395c2424             cmp dword ptr [esp + 0x24], ebx
// 004880fc  7562                 jne 0x488160
// 004880fe  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 00488102  8b5e18               mov ebx, dword ptr [esi + 0x18]
// 00488105  8b06                 mov eax, dword ptr [esi]
// 00488107  85c9                 test ecx, ecx
// 00488109  7404                 je 0x48810f
// 0048810b  3bc8                 cmp ecx, eax
// 0048810d  7406                 je 0x488115
// 0048810f  ffd5                 call ebp
// 00488111  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00488115  395c242c             cmp dword ptr [esp + 0x2c], ebx
// 00488119  7545                 jne 0x488160
// 0048811b  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 0048811e  8b5104               mov edx, dword ptr [ecx + 4]
// 00488121  52                   push edx
// 00488122  8bce                 mov ecx, esi
// 00488124  e877ecffff           call 0x486da0
// 00488129  8b4618               mov eax, dword ptr [esi + 0x18]
// 0048812c  894004               mov dword ptr [eax + 4], eax
// 0048812f  8b4618               mov eax, dword ptr [esi + 0x18]
// 00488132  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 00488139  8900                 mov dword ptr [eax], eax
// 0048813b  8b4618               mov eax, dword ptr [esi + 0x18]
// 0048813e  894008               mov dword ptr [eax + 8], eax
// 00488141  8b4618               mov eax, dword ptr [esi + 0x18]
// 00488144  8b16                 mov edx, dword ptr [esi]
// 00488146  8b08                 mov ecx, dword ptr [eax]
// 00488148  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0048814c  5f                   pop edi
// 0048814d  5e                   pop esi
// 0048814e  5d                   pop ebp
// 0048814f  894804               mov dword ptr [eax + 4], ecx
// 00488152  8910                 mov dword ptr [eax], edx
// 00488154  5b                   pop ebx
// 00488155  83c408               add esp, 8
// 00488158  c21400               ret 0x14
// 0048815b  eb03                 jmp 0x488160
// 0048815d  8d4900               lea ecx, [ecx]
// 00488160  85ff                 test edi, edi
// 00488162  7406                 je 0x48816a
// 00488164  3b7c2428             cmp edi, dword ptr [esp + 0x28]
// 00488168  7406                 je 0x488170
// 0048816a  ffd5                 call ebp
// 0048816c  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00488170  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 00488174  3b5c242c             cmp ebx, dword ptr [esp + 0x2c]
// 00488178  741d                 je 0x488197
// 0048817a  8d4c2420             lea ecx, [esp + 0x20]
// 0048817e  e8dd501400           call 0x5cd260
// 00488183  53                   push ebx
// 00488184  57                   push edi
// 00488185  8d442418             lea eax, [esp + 0x18]
// 00488189  50                   push eax
// 0048818a  8bce                 mov ecx, esi
// 0048818c  e82fe9ffff           call 0x486ac0
// 00488191  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00488195  ebc9                 jmp 0x488160
// 00488197  8b36                 mov esi, dword ptr [esi]
// 00488199  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0048819d  5f                   pop edi
// 0048819e  8930                 mov dword ptr [eax], esi
// 004881a0  5e                   pop esi
// 004881a1  5d                   pop ebp
// 004881a2  895804               mov dword ptr [eax + 4], ebx
// 004881a5  5b                   pop ebx
// 004881a6  83c408               add esp, 8
// 004881a9  c21400               ret 0x14
// standard library set<ptr> (function ?erase@?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE?AViterator@12@Vconst_iterator@12@0@Z)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
