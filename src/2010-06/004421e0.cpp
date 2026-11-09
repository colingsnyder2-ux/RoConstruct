// from server: 100% by auto
// roc 2010-06 004421e0  unit: HVCXTPPropertyGridItemEnum::?$XItem  size: 220 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 004421e0
//
// 004421e0  83ec08               sub esp, 8
// 004421e3  53                   push ebx
// 004421e4  55                   push ebp
// 004421e5  8b2d0ca99e00         mov ebp, dword ptr [0x9ea90c]
// 004421eb  56                   push esi
// 004421ec  8bf1                 mov esi, ecx
// 004421ee  8b4618               mov eax, dword ptr [esi + 0x18]
// 004421f1  8b18                 mov ebx, dword ptr [eax]
// 004421f3  8b06                 mov eax, dword ptr [esi]
// 004421f5  57                   push edi
// 004421f6  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 004421fa  85ff                 test edi, edi
// 004421fc  7404                 je 0x442202
// 004421fe  3bf8                 cmp edi, eax
// 00442200  7406                 je 0x442208
// 00442202  ffd5                 call ebp
// 00442204  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00442208  395c2424             cmp dword ptr [esp + 0x24], ebx
// 0044220c  7562                 jne 0x442270
// 0044220e  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 00442212  8b5e18               mov ebx, dword ptr [esi + 0x18]
// 00442215  8b06                 mov eax, dword ptr [esi]
// 00442217  85c9                 test ecx, ecx
// 00442219  7404                 je 0x44221f
// 0044221b  3bc8                 cmp ecx, eax
// 0044221d  7406                 je 0x442225
// 0044221f  ffd5                 call ebp
// 00442221  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00442225  395c242c             cmp dword ptr [esp + 0x2c], ebx
// 00442229  7545                 jne 0x442270
// 0044222b  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 0044222e  8b5104               mov edx, dword ptr [ecx + 4]
// 00442231  52                   push edx
// 00442232  8bce                 mov ecx, esi
// 00442234  e837feffff           call 0x442070
// 00442239  8b4618               mov eax, dword ptr [esi + 0x18]
// 0044223c  894004               mov dword ptr [eax + 4], eax
// 0044223f  8b4618               mov eax, dword ptr [esi + 0x18]
// 00442242  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 00442249  8900                 mov dword ptr [eax], eax
// 0044224b  8b4618               mov eax, dword ptr [esi + 0x18]
// 0044224e  894008               mov dword ptr [eax + 8], eax
// 00442251  8b4618               mov eax, dword ptr [esi + 0x18]
// 00442254  8b16                 mov edx, dword ptr [esi]
// 00442256  8b08                 mov ecx, dword ptr [eax]
// 00442258  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0044225c  5f                   pop edi
// 0044225d  5e                   pop esi
// 0044225e  5d                   pop ebp
// 0044225f  894804               mov dword ptr [eax + 4], ecx
// 00442262  8910                 mov dword ptr [eax], edx
// 00442264  5b                   pop ebx
// 00442265  83c408               add esp, 8
// 00442268  c21400               ret 0x14
// 0044226b  eb03                 jmp 0x442270
// 0044226d  8d4900               lea ecx, [ecx]
// 00442270  85ff                 test edi, edi
// 00442272  7406                 je 0x44227a
// 00442274  3b7c2428             cmp edi, dword ptr [esp + 0x28]
// 00442278  7406                 je 0x442280
// 0044227a  ffd5                 call ebp
// 0044227c  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00442280  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 00442284  3b5c242c             cmp ebx, dword ptr [esp + 0x2c]
// 00442288  741d                 je 0x4422a7
// 0044228a  8d4c2420             lea ecx, [esp + 0x20]
// 0044228e  e81dd33200           call 0x76f5b0
// 00442293  53                   push ebx
// 00442294  57                   push edi
// 00442295  8d442418             lea eax, [esp + 0x18]
// 00442299  50                   push eax
// 0044229a  8bce                 mov ecx, esi
// 0044229c  e80ff9ffff           call 0x441bb0
// 004422a1  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 004422a5  ebc9                 jmp 0x442270
// 004422a7  8b36                 mov esi, dword ptr [esi]
// 004422a9  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 004422ad  5f                   pop edi
// 004422ae  8930                 mov dword ptr [eax], esi
// 004422b0  5e                   pop esi
// 004422b1  5d                   pop ebp
// 004422b2  895804               mov dword ptr [eax + 4], ebx
// 004422b5  5b                   pop ebx
// 004422b6  83c408               add esp, 8
// 004422b9  c21400               ret 0x14
// standard library set<ptr> (function ?erase@?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE?AViterator@12@Vconst_iterator@12@0@Z)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
