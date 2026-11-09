// from server: 100% by auto
// roc 2008-06 004b1160  unit: RBX::Network::Replicator::NewInstanceItem  size: 220 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004b1160
//
// 004b1160  83ec08               sub esp, 8
// 004b1163  53                   push ebx
// 004b1164  55                   push ebp
// 004b1165  8b2d90288000         mov ebp, dword ptr [0x802890]
// 004b116b  56                   push esi
// 004b116c  8bf1                 mov esi, ecx
// 004b116e  8b4618               mov eax, dword ptr [esi + 0x18]
// 004b1171  8b18                 mov ebx, dword ptr [eax]
// 004b1173  8b06                 mov eax, dword ptr [esi]
// 004b1175  57                   push edi
// 004b1176  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 004b117a  85ff                 test edi, edi
// 004b117c  7404                 je 0x4b1182
// 004b117e  3bf8                 cmp edi, eax
// 004b1180  7406                 je 0x4b1188
// 004b1182  ffd5                 call ebp
// 004b1184  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 004b1188  395c2424             cmp dword ptr [esp + 0x24], ebx
// 004b118c  7562                 jne 0x4b11f0
// 004b118e  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 004b1192  8b5e18               mov ebx, dword ptr [esi + 0x18]
// 004b1195  8b06                 mov eax, dword ptr [esi]
// 004b1197  85c9                 test ecx, ecx
// 004b1199  7404                 je 0x4b119f
// 004b119b  3bc8                 cmp ecx, eax
// 004b119d  7406                 je 0x4b11a5
// 004b119f  ffd5                 call ebp
// 004b11a1  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 004b11a5  395c242c             cmp dword ptr [esp + 0x2c], ebx
// 004b11a9  7545                 jne 0x4b11f0
// 004b11ab  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 004b11ae  8b5104               mov edx, dword ptr [ecx + 4]
// 004b11b1  52                   push edx
// 004b11b2  8bce                 mov ecx, esi
// 004b11b4  e8c7fbffff           call 0x4b0d80
// 004b11b9  8b4618               mov eax, dword ptr [esi + 0x18]
// 004b11bc  894004               mov dword ptr [eax + 4], eax
// 004b11bf  8b4618               mov eax, dword ptr [esi + 0x18]
// 004b11c2  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 004b11c9  8900                 mov dword ptr [eax], eax
// 004b11cb  8b4618               mov eax, dword ptr [esi + 0x18]
// 004b11ce  894008               mov dword ptr [eax + 8], eax
// 004b11d1  8b4618               mov eax, dword ptr [esi + 0x18]
// 004b11d4  8b16                 mov edx, dword ptr [esi]
// 004b11d6  8b08                 mov ecx, dword ptr [eax]
// 004b11d8  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 004b11dc  5f                   pop edi
// 004b11dd  5e                   pop esi
// 004b11de  5d                   pop ebp
// 004b11df  894804               mov dword ptr [eax + 4], ecx
// 004b11e2  8910                 mov dword ptr [eax], edx
// 004b11e4  5b                   pop ebx
// 004b11e5  83c408               add esp, 8
// 004b11e8  c21400               ret 0x14
// 004b11eb  eb03                 jmp 0x4b11f0
// 004b11ed  8d4900               lea ecx, [ecx]
// 004b11f0  85ff                 test edi, edi
// 004b11f2  7406                 je 0x4b11fa
// 004b11f4  3b7c2428             cmp edi, dword ptr [esp + 0x28]
// 004b11f8  7406                 je 0x4b1200
// 004b11fa  ffd5                 call ebp
// 004b11fc  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 004b1200  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 004b1204  3b5c242c             cmp ebx, dword ptr [esp + 0x2c]
// 004b1208  741d                 je 0x4b1227
// 004b120a  8d4c2420             lea ecx, [esp + 0x20]
// 004b120e  e83d601000           call 0x5b7250
// 004b1213  53                   push ebx
// 004b1214  57                   push edi
// 004b1215  8d442418             lea eax, [esp + 0x18]
// 004b1219  50                   push eax
// 004b121a  8bce                 mov ecx, esi
// 004b121c  e80fe3ffff           call 0x4af530
// 004b1221  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 004b1225  ebc9                 jmp 0x4b11f0
// 004b1227  8b36                 mov esi, dword ptr [esi]
// 004b1229  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 004b122d  5f                   pop edi
// 004b122e  8930                 mov dword ptr [eax], esi
// 004b1230  5e                   pop esi
// 004b1231  5d                   pop ebp
// 004b1232  895804               mov dword ptr [eax + 4], ebx
// 004b1235  5b                   pop ebx
// 004b1236  83c408               add esp, 8
// 004b1239  c21400               ret 0x14
// standard library set<ptr> (function ?erase@?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE?AViterator@12@Vconst_iterator@12@0@Z)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
