// from server: 100% by auto
// roc 2009-06 004fc5c0  unit: RBX::Network::ServerReplicator  size: 220 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004fc5c0
//
// 004fc5c0  83ec08               sub esp, 8
// 004fc5c3  53                   push ebx
// 004fc5c4  55                   push ebp
// 004fc5c5  8b2dace98900         mov ebp, dword ptr [0x89e9ac]
// 004fc5cb  56                   push esi
// 004fc5cc  8bf1                 mov esi, ecx
// 004fc5ce  8b4618               mov eax, dword ptr [esi + 0x18]
// 004fc5d1  8b18                 mov ebx, dword ptr [eax]
// 004fc5d3  8b06                 mov eax, dword ptr [esi]
// 004fc5d5  57                   push edi
// 004fc5d6  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 004fc5da  85ff                 test edi, edi
// 004fc5dc  7404                 je 0x4fc5e2
// 004fc5de  3bf8                 cmp edi, eax
// 004fc5e0  7406                 je 0x4fc5e8
// 004fc5e2  ffd5                 call ebp
// 004fc5e4  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 004fc5e8  395c2424             cmp dword ptr [esp + 0x24], ebx
// 004fc5ec  7562                 jne 0x4fc650
// 004fc5ee  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 004fc5f2  8b5e18               mov ebx, dword ptr [esi + 0x18]
// 004fc5f5  8b06                 mov eax, dword ptr [esi]
// 004fc5f7  85c9                 test ecx, ecx
// 004fc5f9  7404                 je 0x4fc5ff
// 004fc5fb  3bc8                 cmp ecx, eax
// 004fc5fd  7406                 je 0x4fc605
// 004fc5ff  ffd5                 call ebp
// 004fc601  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 004fc605  395c242c             cmp dword ptr [esp + 0x2c], ebx
// 004fc609  7545                 jne 0x4fc650
// 004fc60b  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 004fc60e  8b5104               mov edx, dword ptr [ecx + 4]
// 004fc611  52                   push edx
// 004fc612  8bce                 mov ecx, esi
// 004fc614  e8f7faffff           call 0x4fc110
// 004fc619  8b4618               mov eax, dword ptr [esi + 0x18]
// 004fc61c  894004               mov dword ptr [eax + 4], eax
// 004fc61f  8b4618               mov eax, dword ptr [esi + 0x18]
// 004fc622  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 004fc629  8900                 mov dword ptr [eax], eax
// 004fc62b  8b4618               mov eax, dword ptr [esi + 0x18]
// 004fc62e  894008               mov dword ptr [eax + 8], eax
// 004fc631  8b4618               mov eax, dword ptr [esi + 0x18]
// 004fc634  8b16                 mov edx, dword ptr [esi]
// 004fc636  8b08                 mov ecx, dword ptr [eax]
// 004fc638  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 004fc63c  5f                   pop edi
// 004fc63d  5e                   pop esi
// 004fc63e  5d                   pop ebp
// 004fc63f  894804               mov dword ptr [eax + 4], ecx
// 004fc642  8910                 mov dword ptr [eax], edx
// 004fc644  5b                   pop ebx
// 004fc645  83c408               add esp, 8
// 004fc648  c21400               ret 0x14
// 004fc64b  eb03                 jmp 0x4fc650
// 004fc64d  8d4900               lea ecx, [ecx]
// 004fc650  85ff                 test edi, edi
// 004fc652  7406                 je 0x4fc65a
// 004fc654  3b7c2428             cmp edi, dword ptr [esp + 0x28]
// 004fc658  7406                 je 0x4fc660
// 004fc65a  ffd5                 call ebp
// 004fc65c  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 004fc660  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 004fc664  3b5c242c             cmp ebx, dword ptr [esp + 0x2c]
// 004fc668  741d                 je 0x4fc687
// 004fc66a  8d4c2420             lea ecx, [esp + 0x20]
// 004fc66e  e8cdf2ffff           call 0x4fb940
// 004fc673  53                   push ebx
// 004fc674  57                   push edi
// 004fc675  8d442418             lea eax, [esp + 0x18]
// 004fc679  50                   push eax
// 004fc67a  8bce                 mov ecx, esi
// 004fc67c  e8aff7ffff           call 0x4fbe30
// 004fc681  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 004fc685  ebc9                 jmp 0x4fc650
// 004fc687  8b36                 mov esi, dword ptr [esi]
// 004fc689  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 004fc68d  5f                   pop edi
// 004fc68e  8930                 mov dword ptr [eax], esi
// 004fc690  5e                   pop esi
// 004fc691  5d                   pop ebp
// 004fc692  895804               mov dword ptr [eax + 4], ebx
// 004fc695  5b                   pop ebx
// 004fc696  83c408               add esp, 8
// 004fc699  c21400               ret 0x14
// standard library set<ptr> (function ?erase@?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE?AViterator@12@Vconst_iterator@12@0@Z)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
