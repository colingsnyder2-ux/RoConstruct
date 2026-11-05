// from server: 100% by auto
// roc 2009-12 005d21b0  unit: RBX::VRenderSurfaceTypes::?$Table  size: 220 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 005d21b0
//
// 005d21b0  83ec08               sub esp, 8
// 005d21b3  53                   push ebx
// 005d21b4  55                   push ebp
// 005d21b5  8b2d60b79800         mov ebp, dword ptr [0x98b760]
// 005d21bb  56                   push esi
// 005d21bc  8bf1                 mov esi, ecx
// 005d21be  8b4618               mov eax, dword ptr [esi + 0x18]
// 005d21c1  8b18                 mov ebx, dword ptr [eax]
// 005d21c3  8b06                 mov eax, dword ptr [esi]
// 005d21c5  57                   push edi
// 005d21c6  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 005d21ca  85ff                 test edi, edi
// 005d21cc  7404                 je 0x5d21d2
// 005d21ce  3bf8                 cmp edi, eax
// 005d21d0  7406                 je 0x5d21d8
// 005d21d2  ffd5                 call ebp
// 005d21d4  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 005d21d8  395c2424             cmp dword ptr [esp + 0x24], ebx
// 005d21dc  7562                 jne 0x5d2240
// 005d21de  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 005d21e2  8b5e18               mov ebx, dword ptr [esi + 0x18]
// 005d21e5  8b06                 mov eax, dword ptr [esi]
// 005d21e7  85c9                 test ecx, ecx
// 005d21e9  7404                 je 0x5d21ef
// 005d21eb  3bc8                 cmp ecx, eax
// 005d21ed  7406                 je 0x5d21f5
// 005d21ef  ffd5                 call ebp
// 005d21f1  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 005d21f5  395c242c             cmp dword ptr [esp + 0x2c], ebx
// 005d21f9  7545                 jne 0x5d2240
// 005d21fb  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 005d21fe  8b5104               mov edx, dword ptr [ecx + 4]
// 005d2201  52                   push edx
// 005d2202  8bce                 mov ecx, esi
// 005d2204  e827e7ffff           call 0x5d0930
// 005d2209  8b4618               mov eax, dword ptr [esi + 0x18]
// 005d220c  894004               mov dword ptr [eax + 4], eax
// 005d220f  8b4618               mov eax, dword ptr [esi + 0x18]
// 005d2212  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 005d2219  8900                 mov dword ptr [eax], eax
// 005d221b  8b4618               mov eax, dword ptr [esi + 0x18]
// 005d221e  894008               mov dword ptr [eax + 8], eax
// 005d2221  8b4618               mov eax, dword ptr [esi + 0x18]
// 005d2224  8b16                 mov edx, dword ptr [esi]
// 005d2226  8b08                 mov ecx, dword ptr [eax]
// 005d2228  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 005d222c  5f                   pop edi
// 005d222d  5e                   pop esi
// 005d222e  5d                   pop ebp
// 005d222f  894804               mov dword ptr [eax + 4], ecx
// 005d2232  8910                 mov dword ptr [eax], edx
// 005d2234  5b                   pop ebx
// 005d2235  83c408               add esp, 8
// 005d2238  c21400               ret 0x14
// 005d223b  eb03                 jmp 0x5d2240
// 005d223d  8d4900               lea ecx, [ecx]
// 005d2240  85ff                 test edi, edi
// 005d2242  7406                 je 0x5d224a
// 005d2244  3b7c2428             cmp edi, dword ptr [esp + 0x28]
// 005d2248  7406                 je 0x5d2250
// 005d224a  ffd5                 call ebp
// 005d224c  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 005d2250  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 005d2254  3b5c242c             cmp ebx, dword ptr [esp + 0x2c]
// 005d2258  741d                 je 0x5d2277
// 005d225a  8d4c2420             lea ecx, [esp + 0x20]
// 005d225e  e8fdafffff           call 0x5cd260
// 005d2263  53                   push ebx
// 005d2264  57                   push edi
// 005d2265  8d442418             lea eax, [esp + 0x18]
// 005d2269  50                   push eax
// 005d226a  8bce                 mov ecx, esi
// 005d226c  e87fe0ffff           call 0x5d02f0
// 005d2271  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 005d2275  ebc9                 jmp 0x5d2240
// 005d2277  8b36                 mov esi, dword ptr [esi]
// 005d2279  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 005d227d  5f                   pop edi
// 005d227e  8930                 mov dword ptr [eax], esi
// 005d2280  5e                   pop esi
// 005d2281  5d                   pop ebp
// 005d2282  895804               mov dword ptr [eax + 4], ebx
// 005d2285  5b                   pop ebx
// 005d2286  83c408               add esp, 8
// 005d2289  c21400               ret 0x14
// standard library set<ptr> (function ?erase@?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE?AViterator@12@Vconst_iterator@12@0@Z)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
