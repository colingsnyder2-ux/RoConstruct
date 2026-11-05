// from server: 100% by auto
// roc 2009-12 00521620  unit: RBX::Network::Players::Plugin  size: 220 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00521620
//
// 00521620  83ec08               sub esp, 8
// 00521623  53                   push ebx
// 00521624  55                   push ebp
// 00521625  8b2d60b79800         mov ebp, dword ptr [0x98b760]
// 0052162b  56                   push esi
// 0052162c  8bf1                 mov esi, ecx
// 0052162e  8b4618               mov eax, dword ptr [esi + 0x18]
// 00521631  8b18                 mov ebx, dword ptr [eax]
// 00521633  8b06                 mov eax, dword ptr [esi]
// 00521635  57                   push edi
// 00521636  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 0052163a  85ff                 test edi, edi
// 0052163c  7404                 je 0x521642
// 0052163e  3bf8                 cmp edi, eax
// 00521640  7406                 je 0x521648
// 00521642  ffd5                 call ebp
// 00521644  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00521648  395c2424             cmp dword ptr [esp + 0x24], ebx
// 0052164c  7562                 jne 0x5216b0
// 0052164e  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 00521652  8b5e18               mov ebx, dword ptr [esi + 0x18]
// 00521655  8b06                 mov eax, dword ptr [esi]
// 00521657  85c9                 test ecx, ecx
// 00521659  7404                 je 0x52165f
// 0052165b  3bc8                 cmp ecx, eax
// 0052165d  7406                 je 0x521665
// 0052165f  ffd5                 call ebp
// 00521661  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00521665  395c242c             cmp dword ptr [esp + 0x2c], ebx
// 00521669  7545                 jne 0x5216b0
// 0052166b  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 0052166e  8b5104               mov edx, dword ptr [ecx + 4]
// 00521671  52                   push edx
// 00521672  8bce                 mov ecx, esi
// 00521674  e877e2ffff           call 0x51f8f0
// 00521679  8b4618               mov eax, dword ptr [esi + 0x18]
// 0052167c  894004               mov dword ptr [eax + 4], eax
// 0052167f  8b4618               mov eax, dword ptr [esi + 0x18]
// 00521682  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 00521689  8900                 mov dword ptr [eax], eax
// 0052168b  8b4618               mov eax, dword ptr [esi + 0x18]
// 0052168e  894008               mov dword ptr [eax + 8], eax
// 00521691  8b4618               mov eax, dword ptr [esi + 0x18]
// 00521694  8b16                 mov edx, dword ptr [esi]
// 00521696  8b08                 mov ecx, dword ptr [eax]
// 00521698  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0052169c  5f                   pop edi
// 0052169d  5e                   pop esi
// 0052169e  5d                   pop ebp
// 0052169f  894804               mov dword ptr [eax + 4], ecx
// 005216a2  8910                 mov dword ptr [eax], edx
// 005216a4  5b                   pop ebx
// 005216a5  83c408               add esp, 8
// 005216a8  c21400               ret 0x14
// 005216ab  eb03                 jmp 0x5216b0
// 005216ad  8d4900               lea ecx, [ecx]
// 005216b0  85ff                 test edi, edi
// 005216b2  7406                 je 0x5216ba
// 005216b4  3b7c2428             cmp edi, dword ptr [esp + 0x28]
// 005216b8  7406                 je 0x5216c0
// 005216ba  ffd5                 call ebp
// 005216bc  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 005216c0  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 005216c4  3b5c242c             cmp ebx, dword ptr [esp + 0x2c]
// 005216c8  741d                 je 0x5216e7
// 005216ca  8d4c2420             lea ecx, [esp + 0x20]
// 005216ce  e81d22ffff           call 0x5138f0
// 005216d3  53                   push ebx
// 005216d4  57                   push edi
// 005216d5  8d442418             lea eax, [esp + 0x18]
// 005216d9  50                   push eax
// 005216da  8bce                 mov ecx, esi
// 005216dc  e82fdfffff           call 0x51f610
// 005216e1  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 005216e5  ebc9                 jmp 0x5216b0
// 005216e7  8b36                 mov esi, dword ptr [esi]
// 005216e9  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 005216ed  5f                   pop edi
// 005216ee  8930                 mov dword ptr [eax], esi
// 005216f0  5e                   pop esi
// 005216f1  5d                   pop ebp
// 005216f2  895804               mov dword ptr [eax + 4], ebx
// 005216f5  5b                   pop ebx
// 005216f6  83c408               add esp, 8
// 005216f9  c21400               ret 0x14
// standard library set<ptr> (function ?erase@?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE?AViterator@12@Vconst_iterator@12@0@Z)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
