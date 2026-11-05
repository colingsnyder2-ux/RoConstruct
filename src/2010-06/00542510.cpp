// from server: 100% by auto
// roc 2010-06 00542510  unit: RBX::AggregatingSceneManager  size: 220 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00542510
//
// 00542510  83ec08               sub esp, 8
// 00542513  53                   push ebx
// 00542514  55                   push ebp
// 00542515  8b2d0ca99e00         mov ebp, dword ptr [0x9ea90c]
// 0054251b  56                   push esi
// 0054251c  8bf1                 mov esi, ecx
// 0054251e  8b4618               mov eax, dword ptr [esi + 0x18]
// 00542521  8b18                 mov ebx, dword ptr [eax]
// 00542523  8b06                 mov eax, dword ptr [esi]
// 00542525  57                   push edi
// 00542526  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 0054252a  85ff                 test edi, edi
// 0054252c  7404                 je 0x542532
// 0054252e  3bf8                 cmp edi, eax
// 00542530  7406                 je 0x542538
// 00542532  ffd5                 call ebp
// 00542534  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00542538  395c2424             cmp dword ptr [esp + 0x24], ebx
// 0054253c  7562                 jne 0x5425a0
// 0054253e  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 00542542  8b5e18               mov ebx, dword ptr [esi + 0x18]
// 00542545  8b06                 mov eax, dword ptr [esi]
// 00542547  85c9                 test ecx, ecx
// 00542549  7404                 je 0x54254f
// 0054254b  3bc8                 cmp ecx, eax
// 0054254d  7406                 je 0x542555
// 0054254f  ffd5                 call ebp
// 00542551  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00542555  395c242c             cmp dword ptr [esp + 0x2c], ebx
// 00542559  7545                 jne 0x5425a0
// 0054255b  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 0054255e  8b5104               mov edx, dword ptr [ecx + 4]
// 00542561  52                   push edx
// 00542562  8bce                 mov ecx, esi
// 00542564  e807f1ffff           call 0x541670
// 00542569  8b4618               mov eax, dword ptr [esi + 0x18]
// 0054256c  894004               mov dword ptr [eax + 4], eax
// 0054256f  8b4618               mov eax, dword ptr [esi + 0x18]
// 00542572  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 00542579  8900                 mov dword ptr [eax], eax
// 0054257b  8b4618               mov eax, dword ptr [esi + 0x18]
// 0054257e  894008               mov dword ptr [eax + 8], eax
// 00542581  8b4618               mov eax, dword ptr [esi + 0x18]
// 00542584  8b16                 mov edx, dword ptr [esi]
// 00542586  8b08                 mov ecx, dword ptr [eax]
// 00542588  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0054258c  5f                   pop edi
// 0054258d  5e                   pop esi
// 0054258e  5d                   pop ebp
// 0054258f  894804               mov dword ptr [eax + 4], ecx
// 00542592  8910                 mov dword ptr [eax], edx
// 00542594  5b                   pop ebx
// 00542595  83c408               add esp, 8
// 00542598  c21400               ret 0x14
// 0054259b  eb03                 jmp 0x5425a0
// 0054259d  8d4900               lea ecx, [ecx]
// 005425a0  85ff                 test edi, edi
// 005425a2  7406                 je 0x5425aa
// 005425a4  3b7c2428             cmp edi, dword ptr [esp + 0x28]
// 005425a8  7406                 je 0x5425b0
// 005425aa  ffd5                 call ebp
// 005425ac  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 005425b0  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 005425b4  3b5c242c             cmp ebx, dword ptr [esp + 0x2c]
// 005425b8  741d                 je 0x5425d7
// 005425ba  8d4c2420             lea ecx, [esp + 0x20]
// 005425be  e80dbd0400           call 0x58e2d0
// 005425c3  53                   push ebx
// 005425c4  57                   push edi
// 005425c5  8d442418             lea eax, [esp + 0x18]
// 005425c9  50                   push eax
// 005425ca  8bce                 mov ecx, esi
// 005425cc  e8bfedffff           call 0x541390
// 005425d1  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 005425d5  ebc9                 jmp 0x5425a0
// 005425d7  8b36                 mov esi, dword ptr [esi]
// 005425d9  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 005425dd  5f                   pop edi
// 005425de  8930                 mov dword ptr [eax], esi
// 005425e0  5e                   pop esi
// 005425e1  5d                   pop ebp
// 005425e2  895804               mov dword ptr [eax + 4], ebx
// 005425e5  5b                   pop ebx
// 005425e6  83c408               add esp, 8
// 005425e9  c21400               ret 0x14
// standard library set<ptr> (function ?erase@?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE?AViterator@12@Vconst_iterator@12@0@Z)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
