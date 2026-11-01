// from server: 100% by auto
// roc 2009-12 007650d0  unit: RBX::VBadgeService::?$BoundYieldFuncDesc  size: 220 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007650d0
//
// 007650d0  83ec08               sub esp, 8
// 007650d3  53                   push ebx
// 007650d4  55                   push ebp
// 007650d5  8b2d60b79800         mov ebp, dword ptr [0x98b760]
// 007650db  56                   push esi
// 007650dc  8bf1                 mov esi, ecx
// 007650de  8b4618               mov eax, dword ptr [esi + 0x18]
// 007650e1  8b18                 mov ebx, dword ptr [eax]
// 007650e3  8b06                 mov eax, dword ptr [esi]
// 007650e5  57                   push edi
// 007650e6  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 007650ea  85ff                 test edi, edi
// 007650ec  7404                 je 0x7650f2
// 007650ee  3bf8                 cmp edi, eax
// 007650f0  7406                 je 0x7650f8
// 007650f2  ffd5                 call ebp
// 007650f4  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 007650f8  395c2424             cmp dword ptr [esp + 0x24], ebx
// 007650fc  7562                 jne 0x765160
// 007650fe  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 00765102  8b5e18               mov ebx, dword ptr [esi + 0x18]
// 00765105  8b06                 mov eax, dword ptr [esi]
// 00765107  85c9                 test ecx, ecx
// 00765109  7404                 je 0x76510f
// 0076510b  3bc8                 cmp ecx, eax
// 0076510d  7406                 je 0x765115
// 0076510f  ffd5                 call ebp
// 00765111  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00765115  395c242c             cmp dword ptr [esp + 0x2c], ebx
// 00765119  7545                 jne 0x765160
// 0076511b  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 0076511e  8b5104               mov edx, dword ptr [ecx + 4]
// 00765121  52                   push edx
// 00765122  8bce                 mov ecx, esi
// 00765124  e857f0ffff           call 0x764180
// 00765129  8b4618               mov eax, dword ptr [esi + 0x18]
// 0076512c  894004               mov dword ptr [eax + 4], eax
// 0076512f  8b4618               mov eax, dword ptr [esi + 0x18]
// 00765132  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 00765139  8900                 mov dword ptr [eax], eax
// 0076513b  8b4618               mov eax, dword ptr [esi + 0x18]
// 0076513e  894008               mov dword ptr [eax + 8], eax
// 00765141  8b4618               mov eax, dword ptr [esi + 0x18]
// 00765144  8b16                 mov edx, dword ptr [esi]
// 00765146  8b08                 mov ecx, dword ptr [eax]
// 00765148  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0076514c  5f                   pop edi
// 0076514d  5e                   pop esi
// 0076514e  5d                   pop ebp
// 0076514f  894804               mov dword ptr [eax + 4], ecx
// 00765152  8910                 mov dword ptr [eax], edx
// 00765154  5b                   pop ebx
// 00765155  83c408               add esp, 8
// 00765158  c21400               ret 0x14
// 0076515b  eb03                 jmp 0x765160
// 0076515d  8d4900               lea ecx, [ecx]
// 00765160  85ff                 test edi, edi
// 00765162  7406                 je 0x76516a
// 00765164  3b7c2428             cmp edi, dword ptr [esp + 0x28]
// 00765168  7406                 je 0x765170
// 0076516a  ffd5                 call ebp
// 0076516c  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00765170  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 00765174  3b5c242c             cmp ebx, dword ptr [esp + 0x2c]
// 00765178  741d                 je 0x765197
// 0076517a  8d4c2420             lea ecx, [esp + 0x20]
// 0076517e  e86de7daff           call 0x5138f0
// 00765183  53                   push ebx
// 00765184  57                   push edi
// 00765185  8d442418             lea eax, [esp + 0x18]
// 00765189  50                   push eax
// 0076518a  8bce                 mov ecx, esi
// 0076518c  e80fedffff           call 0x763ea0
// 00765191  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00765195  ebc9                 jmp 0x765160
// 00765197  8b36                 mov esi, dword ptr [esi]
// 00765199  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0076519d  5f                   pop edi
// 0076519e  8930                 mov dword ptr [eax], esi
// 007651a0  5e                   pop esi
// 007651a1  5d                   pop ebp
// 007651a2  895804               mov dword ptr [eax + 4], ebx
// 007651a5  5b                   pop ebx
// 007651a6  83c408               add esp, 8
// 007651a9  c21400               ret 0x14
// standard library set<ptr> (function ?erase@?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE?AViterator@12@Vconst_iterator@12@0@Z)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
