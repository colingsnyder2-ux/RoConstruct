// from server: 100% by auto
// roc 2009-12 006ae210  unit: RBX::Accoutrement  size: 220 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 006ae210
//
// 006ae210  83ec08               sub esp, 8
// 006ae213  53                   push ebx
// 006ae214  55                   push ebp
// 006ae215  8b2d60b79800         mov ebp, dword ptr [0x98b760]
// 006ae21b  56                   push esi
// 006ae21c  8bf1                 mov esi, ecx
// 006ae21e  8b4618               mov eax, dword ptr [esi + 0x18]
// 006ae221  8b18                 mov ebx, dword ptr [eax]
// 006ae223  8b06                 mov eax, dword ptr [esi]
// 006ae225  57                   push edi
// 006ae226  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 006ae22a  85ff                 test edi, edi
// 006ae22c  7404                 je 0x6ae232
// 006ae22e  3bf8                 cmp edi, eax
// 006ae230  7406                 je 0x6ae238
// 006ae232  ffd5                 call ebp
// 006ae234  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 006ae238  395c2424             cmp dword ptr [esp + 0x24], ebx
// 006ae23c  7562                 jne 0x6ae2a0
// 006ae23e  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 006ae242  8b5e18               mov ebx, dword ptr [esi + 0x18]
// 006ae245  8b06                 mov eax, dword ptr [esi]
// 006ae247  85c9                 test ecx, ecx
// 006ae249  7404                 je 0x6ae24f
// 006ae24b  3bc8                 cmp ecx, eax
// 006ae24d  7406                 je 0x6ae255
// 006ae24f  ffd5                 call ebp
// 006ae251  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 006ae255  395c242c             cmp dword ptr [esp + 0x2c], ebx
// 006ae259  7545                 jne 0x6ae2a0
// 006ae25b  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 006ae25e  8b5104               mov edx, dword ptr [ecx + 4]
// 006ae261  52                   push edx
// 006ae262  8bce                 mov ecx, esi
// 006ae264  e897f7ffff           call 0x6ada00
// 006ae269  8b4618               mov eax, dword ptr [esi + 0x18]
// 006ae26c  894004               mov dword ptr [eax + 4], eax
// 006ae26f  8b4618               mov eax, dword ptr [esi + 0x18]
// 006ae272  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 006ae279  8900                 mov dword ptr [eax], eax
// 006ae27b  8b4618               mov eax, dword ptr [esi + 0x18]
// 006ae27e  894008               mov dword ptr [eax + 8], eax
// 006ae281  8b4618               mov eax, dword ptr [esi + 0x18]
// 006ae284  8b16                 mov edx, dword ptr [esi]
// 006ae286  8b08                 mov ecx, dword ptr [eax]
// 006ae288  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 006ae28c  5f                   pop edi
// 006ae28d  5e                   pop esi
// 006ae28e  5d                   pop ebp
// 006ae28f  894804               mov dword ptr [eax + 4], ecx
// 006ae292  8910                 mov dword ptr [eax], edx
// 006ae294  5b                   pop ebx
// 006ae295  83c408               add esp, 8
// 006ae298  c21400               ret 0x14
// 006ae29b  eb03                 jmp 0x6ae2a0
// 006ae29d  8d4900               lea ecx, [ecx]
// 006ae2a0  85ff                 test edi, edi
// 006ae2a2  7406                 je 0x6ae2aa
// 006ae2a4  3b7c2428             cmp edi, dword ptr [esp + 0x28]
// 006ae2a8  7406                 je 0x6ae2b0
// 006ae2aa  ffd5                 call ebp
// 006ae2ac  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 006ae2b0  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 006ae2b4  3b5c242c             cmp ebx, dword ptr [esp + 0x2c]
// 006ae2b8  741d                 je 0x6ae2d7
// 006ae2ba  8d4c2420             lea ecx, [esp + 0x20]
// 006ae2be  e84dc6dcff           call 0x47a910
// 006ae2c3  53                   push ebx
// 006ae2c4  57                   push edi
// 006ae2c5  8d442418             lea eax, [esp + 0x18]
// 006ae2c9  50                   push eax
// 006ae2ca  8bce                 mov ecx, esi
// 006ae2cc  e84ff4ffff           call 0x6ad720
// 006ae2d1  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 006ae2d5  ebc9                 jmp 0x6ae2a0
// 006ae2d7  8b36                 mov esi, dword ptr [esi]
// 006ae2d9  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 006ae2dd  5f                   pop edi
// 006ae2de  8930                 mov dword ptr [eax], esi
// 006ae2e0  5e                   pop esi
// 006ae2e1  5d                   pop ebp
// 006ae2e2  895804               mov dword ptr [eax + 4], ebx
// 006ae2e5  5b                   pop ebx
// 006ae2e6  83c408               add esp, 8
// 006ae2e9  c21400               ret 0x14
// standard library set<ptr> (function ?erase@?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE?AViterator@12@Vconst_iterator@12@0@Z)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
