// from server: 100% by auto
// roc 2010-06 006611d0  unit: G3D::VRay::?$TypedPropertyDescriptor  size: 220 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 006611d0
//
// 006611d0  83ec08               sub esp, 8
// 006611d3  53                   push ebx
// 006611d4  55                   push ebp
// 006611d5  8b2d0ca99e00         mov ebp, dword ptr [0x9ea90c]
// 006611db  56                   push esi
// 006611dc  8bf1                 mov esi, ecx
// 006611de  8b4618               mov eax, dword ptr [esi + 0x18]
// 006611e1  8b18                 mov ebx, dword ptr [eax]
// 006611e3  8b06                 mov eax, dword ptr [esi]
// 006611e5  57                   push edi
// 006611e6  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 006611ea  85ff                 test edi, edi
// 006611ec  7404                 je 0x6611f2
// 006611ee  3bf8                 cmp edi, eax
// 006611f0  7406                 je 0x6611f8
// 006611f2  ffd5                 call ebp
// 006611f4  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 006611f8  395c2424             cmp dword ptr [esp + 0x24], ebx
// 006611fc  7562                 jne 0x661260
// 006611fe  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 00661202  8b5e18               mov ebx, dword ptr [esi + 0x18]
// 00661205  8b06                 mov eax, dword ptr [esi]
// 00661207  85c9                 test ecx, ecx
// 00661209  7404                 je 0x66120f
// 0066120b  3bc8                 cmp ecx, eax
// 0066120d  7406                 je 0x661215
// 0066120f  ffd5                 call ebp
// 00661211  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00661215  395c242c             cmp dword ptr [esp + 0x2c], ebx
// 00661219  7545                 jne 0x661260
// 0066121b  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 0066121e  8b5104               mov edx, dword ptr [ecx + 4]
// 00661221  52                   push edx
// 00661222  8bce                 mov ecx, esi
// 00661224  e8d7f2ffff           call 0x660500
// 00661229  8b4618               mov eax, dword ptr [esi + 0x18]
// 0066122c  894004               mov dword ptr [eax + 4], eax
// 0066122f  8b4618               mov eax, dword ptr [esi + 0x18]
// 00661232  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 00661239  8900                 mov dword ptr [eax], eax
// 0066123b  8b4618               mov eax, dword ptr [esi + 0x18]
// 0066123e  894008               mov dword ptr [eax + 8], eax
// 00661241  8b4618               mov eax, dword ptr [esi + 0x18]
// 00661244  8b16                 mov edx, dword ptr [esi]
// 00661246  8b08                 mov ecx, dword ptr [eax]
// 00661248  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0066124c  5f                   pop edi
// 0066124d  5e                   pop esi
// 0066124e  5d                   pop ebp
// 0066124f  894804               mov dword ptr [eax + 4], ecx
// 00661252  8910                 mov dword ptr [eax], edx
// 00661254  5b                   pop ebx
// 00661255  83c408               add esp, 8
// 00661258  c21400               ret 0x14
// 0066125b  eb03                 jmp 0x661260
// 0066125d  8d4900               lea ecx, [ecx]
// 00661260  85ff                 test edi, edi
// 00661262  7406                 je 0x66126a
// 00661264  3b7c2428             cmp edi, dword ptr [esp + 0x28]
// 00661268  7406                 je 0x661270
// 0066126a  ffd5                 call ebp
// 0066126c  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00661270  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 00661274  3b5c242c             cmp ebx, dword ptr [esp + 0x2c]
// 00661278  741d                 je 0x661297
// 0066127a  8d4c2420             lea ecx, [esp + 0x20]
// 0066127e  e85d670800           call 0x6e79e0
// 00661283  53                   push ebx
// 00661284  57                   push edi
// 00661285  8d442418             lea eax, [esp + 0x18]
// 00661289  50                   push eax
// 0066128a  8bce                 mov ecx, esi
// 0066128c  e87fefffff           call 0x660210
// 00661291  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00661295  ebc9                 jmp 0x661260
// 00661297  8b36                 mov esi, dword ptr [esi]
// 00661299  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0066129d  5f                   pop edi
// 0066129e  8930                 mov dword ptr [eax], esi
// 006612a0  5e                   pop esi
// 006612a1  5d                   pop ebp
// 006612a2  895804               mov dword ptr [eax + 4], ebx
// 006612a5  5b                   pop ebx
// 006612a6  83c408               add esp, 8
// 006612a9  c21400               ret 0x14
// standard library set<ptr> (function ?erase@?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE?AViterator@12@Vconst_iterator@12@0@Z)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
