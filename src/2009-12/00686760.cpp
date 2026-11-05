// from server: 100% by auto
// roc 2009-12 00686760  unit: RBX::VChangeHistoryService::?$BoundFuncDesc  size: 220 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00686760
//
// 00686760  83ec08               sub esp, 8
// 00686763  53                   push ebx
// 00686764  55                   push ebp
// 00686765  8b2d60b79800         mov ebp, dword ptr [0x98b760]
// 0068676b  56                   push esi
// 0068676c  8bf1                 mov esi, ecx
// 0068676e  8b4618               mov eax, dword ptr [esi + 0x18]
// 00686771  8b18                 mov ebx, dword ptr [eax]
// 00686773  8b06                 mov eax, dword ptr [esi]
// 00686775  57                   push edi
// 00686776  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 0068677a  85ff                 test edi, edi
// 0068677c  7404                 je 0x686782
// 0068677e  3bf8                 cmp edi, eax
// 00686780  7406                 je 0x686788
// 00686782  ffd5                 call ebp
// 00686784  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00686788  395c2424             cmp dword ptr [esp + 0x24], ebx
// 0068678c  7562                 jne 0x6867f0
// 0068678e  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 00686792  8b5e18               mov ebx, dword ptr [esi + 0x18]
// 00686795  8b06                 mov eax, dword ptr [esi]
// 00686797  85c9                 test ecx, ecx
// 00686799  7404                 je 0x68679f
// 0068679b  3bc8                 cmp ecx, eax
// 0068679d  7406                 je 0x6867a5
// 0068679f  ffd5                 call ebp
// 006867a1  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 006867a5  395c242c             cmp dword ptr [esp + 0x2c], ebx
// 006867a9  7545                 jne 0x6867f0
// 006867ab  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 006867ae  8b5104               mov edx, dword ptr [ecx + 4]
// 006867b1  52                   push edx
// 006867b2  8bce                 mov ecx, esi
// 006867b4  e817eaffff           call 0x6851d0
// 006867b9  8b4618               mov eax, dword ptr [esi + 0x18]
// 006867bc  894004               mov dword ptr [eax + 4], eax
// 006867bf  8b4618               mov eax, dword ptr [esi + 0x18]
// 006867c2  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 006867c9  8900                 mov dword ptr [eax], eax
// 006867cb  8b4618               mov eax, dword ptr [esi + 0x18]
// 006867ce  894008               mov dword ptr [eax + 8], eax
// 006867d1  8b4618               mov eax, dword ptr [esi + 0x18]
// 006867d4  8b16                 mov edx, dword ptr [esi]
// 006867d6  8b08                 mov ecx, dword ptr [eax]
// 006867d8  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 006867dc  5f                   pop edi
// 006867dd  5e                   pop esi
// 006867de  5d                   pop ebp
// 006867df  894804               mov dword ptr [eax + 4], ecx
// 006867e2  8910                 mov dword ptr [eax], edx
// 006867e4  5b                   pop ebx
// 006867e5  83c408               add esp, 8
// 006867e8  c21400               ret 0x14
// 006867eb  eb03                 jmp 0x6867f0
// 006867ed  8d4900               lea ecx, [ecx]
// 006867f0  85ff                 test edi, edi
// 006867f2  7406                 je 0x6867fa
// 006867f4  3b7c2428             cmp edi, dword ptr [esp + 0x28]
// 006867f8  7406                 je 0x686800
// 006867fa  ffd5                 call ebp
// 006867fc  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00686800  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 00686804  3b5c242c             cmp ebx, dword ptr [esp + 0x2c]
// 00686808  741d                 je 0x686827
// 0068680a  8d4c2420             lea ecx, [esp + 0x20]
// 0068680e  e85dfe1300           call 0x7c6670
// 00686813  53                   push ebx
// 00686814  57                   push edi
// 00686815  8d442418             lea eax, [esp + 0x18]
// 00686819  50                   push eax
// 0068681a  8bce                 mov ecx, esi
// 0068681c  e88ff2ffff           call 0x685ab0
// 00686821  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00686825  ebc9                 jmp 0x6867f0
// 00686827  8b36                 mov esi, dword ptr [esi]
// 00686829  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0068682d  5f                   pop edi
// 0068682e  8930                 mov dword ptr [eax], esi
// 00686830  5e                   pop esi
// 00686831  5d                   pop ebp
// 00686832  895804               mov dword ptr [eax + 4], ebx
// 00686835  5b                   pop ebx
// 00686836  83c408               add esp, 8
// 00686839  c21400               ret 0x14
// standard library set<ptr> (function ?erase@?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE?AViterator@12@Vconst_iterator@12@0@Z)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
