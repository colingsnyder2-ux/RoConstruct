// from server: 100% by auto
// roc 2008-06 00560960  unit: RBX::VContentProvider::?$DescribedNonCreatable  size: 220 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00560960
//
// 00560960  83ec08               sub esp, 8
// 00560963  53                   push ebx
// 00560964  55                   push ebp
// 00560965  8b2d90288000         mov ebp, dword ptr [0x802890]
// 0056096b  56                   push esi
// 0056096c  8bf1                 mov esi, ecx
// 0056096e  8b4618               mov eax, dword ptr [esi + 0x18]
// 00560971  8b18                 mov ebx, dword ptr [eax]
// 00560973  8b06                 mov eax, dword ptr [esi]
// 00560975  57                   push edi
// 00560976  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 0056097a  85ff                 test edi, edi
// 0056097c  7404                 je 0x560982
// 0056097e  3bf8                 cmp edi, eax
// 00560980  7406                 je 0x560988
// 00560982  ffd5                 call ebp
// 00560984  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00560988  395c2424             cmp dword ptr [esp + 0x24], ebx
// 0056098c  7562                 jne 0x5609f0
// 0056098e  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 00560992  8b5e18               mov ebx, dword ptr [esi + 0x18]
// 00560995  8b06                 mov eax, dword ptr [esi]
// 00560997  85c9                 test ecx, ecx
// 00560999  7404                 je 0x56099f
// 0056099b  3bc8                 cmp ecx, eax
// 0056099d  7406                 je 0x5609a5
// 0056099f  ffd5                 call ebp
// 005609a1  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 005609a5  395c242c             cmp dword ptr [esp + 0x2c], ebx
// 005609a9  7545                 jne 0x5609f0
// 005609ab  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 005609ae  8b5104               mov edx, dword ptr [ecx + 4]
// 005609b1  52                   push edx
// 005609b2  8bce                 mov ecx, esi
// 005609b4  e807e9ffff           call 0x55f2c0
// 005609b9  8b4618               mov eax, dword ptr [esi + 0x18]
// 005609bc  894004               mov dword ptr [eax + 4], eax
// 005609bf  8b4618               mov eax, dword ptr [esi + 0x18]
// 005609c2  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 005609c9  8900                 mov dword ptr [eax], eax
// 005609cb  8b4618               mov eax, dword ptr [esi + 0x18]
// 005609ce  894008               mov dword ptr [eax + 8], eax
// 005609d1  8b4618               mov eax, dword ptr [esi + 0x18]
// 005609d4  8b16                 mov edx, dword ptr [esi]
// 005609d6  8b08                 mov ecx, dword ptr [eax]
// 005609d8  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 005609dc  5f                   pop edi
// 005609dd  5e                   pop esi
// 005609de  5d                   pop ebp
// 005609df  894804               mov dword ptr [eax + 4], ecx
// 005609e2  8910                 mov dword ptr [eax], edx
// 005609e4  5b                   pop ebx
// 005609e5  83c408               add esp, 8
// 005609e8  c21400               ret 0x14
// 005609eb  eb03                 jmp 0x5609f0
// 005609ed  8d4900               lea ecx, [ecx]
// 005609f0  85ff                 test edi, edi
// 005609f2  7406                 je 0x5609fa
// 005609f4  3b7c2428             cmp edi, dword ptr [esp + 0x28]
// 005609f8  7406                 je 0x560a00
// 005609fa  ffd5                 call ebp
// 005609fc  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00560a00  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 00560a04  3b5c242c             cmp ebx, dword ptr [esp + 0x2c]
// 00560a08  741d                 je 0x560a27
// 00560a0a  8d4c2420             lea ecx, [esp + 0x20]
// 00560a0e  e80dc0ffff           call 0x55ca20
// 00560a13  53                   push ebx
// 00560a14  57                   push edi
// 00560a15  8d442418             lea eax, [esp + 0x18]
// 00560a19  50                   push eax
// 00560a1a  8bce                 mov ecx, esi
// 00560a1c  e89fe5ffff           call 0x55efc0
// 00560a21  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00560a25  ebc9                 jmp 0x5609f0
// 00560a27  8b36                 mov esi, dword ptr [esi]
// 00560a29  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00560a2d  5f                   pop edi
// 00560a2e  8930                 mov dword ptr [eax], esi
// 00560a30  5e                   pop esi
// 00560a31  5d                   pop ebp
// 00560a32  895804               mov dword ptr [eax + 4], ebx
// 00560a35  5b                   pop ebx
// 00560a36  83c408               add esp, 8
// 00560a39  c21400               ret 0x14
// standard library set<ptr> (function ?erase@?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE?AViterator@12@Vconst_iterator@12@0@Z)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
