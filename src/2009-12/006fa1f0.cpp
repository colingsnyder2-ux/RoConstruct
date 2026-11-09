// from server: 100% by auto
// roc 2009-12 006fa1f0  unit: RBX::Network::VPlayer::?$RemoteEventDesc  size: 220 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 006fa1f0
//
// 006fa1f0  83ec08               sub esp, 8
// 006fa1f3  53                   push ebx
// 006fa1f4  55                   push ebp
// 006fa1f5  8b2d60b79800         mov ebp, dword ptr [0x98b760]
// 006fa1fb  56                   push esi
// 006fa1fc  8bf1                 mov esi, ecx
// 006fa1fe  8b4618               mov eax, dword ptr [esi + 0x18]
// 006fa201  8b18                 mov ebx, dword ptr [eax]
// 006fa203  8b06                 mov eax, dword ptr [esi]
// 006fa205  57                   push edi
// 006fa206  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 006fa20a  85ff                 test edi, edi
// 006fa20c  7404                 je 0x6fa212
// 006fa20e  3bf8                 cmp edi, eax
// 006fa210  7406                 je 0x6fa218
// 006fa212  ffd5                 call ebp
// 006fa214  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 006fa218  395c2424             cmp dword ptr [esp + 0x24], ebx
// 006fa21c  7562                 jne 0x6fa280
// 006fa21e  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 006fa222  8b5e18               mov ebx, dword ptr [esi + 0x18]
// 006fa225  8b06                 mov eax, dword ptr [esi]
// 006fa227  85c9                 test ecx, ecx
// 006fa229  7404                 je 0x6fa22f
// 006fa22b  3bc8                 cmp ecx, eax
// 006fa22d  7406                 je 0x6fa235
// 006fa22f  ffd5                 call ebp
// 006fa231  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 006fa235  395c242c             cmp dword ptr [esp + 0x2c], ebx
// 006fa239  7545                 jne 0x6fa280
// 006fa23b  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 006fa23e  8b5104               mov edx, dword ptr [ecx + 4]
// 006fa241  52                   push edx
// 006fa242  8bce                 mov ecx, esi
// 006fa244  e8b7f7ffff           call 0x6f9a00
// 006fa249  8b4618               mov eax, dword ptr [esi + 0x18]
// 006fa24c  894004               mov dword ptr [eax + 4], eax
// 006fa24f  8b4618               mov eax, dword ptr [esi + 0x18]
// 006fa252  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 006fa259  8900                 mov dword ptr [eax], eax
// 006fa25b  8b4618               mov eax, dword ptr [esi + 0x18]
// 006fa25e  894008               mov dword ptr [eax + 8], eax
// 006fa261  8b4618               mov eax, dword ptr [esi + 0x18]
// 006fa264  8b16                 mov edx, dword ptr [esi]
// 006fa266  8b08                 mov ecx, dword ptr [eax]
// 006fa268  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 006fa26c  5f                   pop edi
// 006fa26d  5e                   pop esi
// 006fa26e  5d                   pop ebp
// 006fa26f  894804               mov dword ptr [eax + 4], ecx
// 006fa272  8910                 mov dword ptr [eax], edx
// 006fa274  5b                   pop ebx
// 006fa275  83c408               add esp, 8
// 006fa278  c21400               ret 0x14
// 006fa27b  eb03                 jmp 0x6fa280
// 006fa27d  8d4900               lea ecx, [ecx]
// 006fa280  85ff                 test edi, edi
// 006fa282  7406                 je 0x6fa28a
// 006fa284  3b7c2428             cmp edi, dword ptr [esp + 0x28]
// 006fa288  7406                 je 0x6fa290
// 006fa28a  ffd5                 call ebp
// 006fa28c  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 006fa290  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 006fa294  3b5c242c             cmp ebx, dword ptr [esp + 0x2c]
// 006fa298  741d                 je 0x6fa2b7
// 006fa29a  8d4c2420             lea ecx, [esp + 0x20]
// 006fa29e  e84d96e1ff           call 0x5138f0
// 006fa2a3  53                   push ebx
// 006fa2a4  57                   push edi
// 006fa2a5  8d442418             lea eax, [esp + 0x18]
// 006fa2a9  50                   push eax
// 006fa2aa  8bce                 mov ecx, esi
// 006fa2ac  e86ff4ffff           call 0x6f9720
// 006fa2b1  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 006fa2b5  ebc9                 jmp 0x6fa280
// 006fa2b7  8b36                 mov esi, dword ptr [esi]
// 006fa2b9  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 006fa2bd  5f                   pop edi
// 006fa2be  8930                 mov dword ptr [eax], esi
// 006fa2c0  5e                   pop esi
// 006fa2c1  5d                   pop ebp
// 006fa2c2  895804               mov dword ptr [eax + 4], ebx
// 006fa2c5  5b                   pop ebx
// 006fa2c6  83c408               add esp, 8
// 006fa2c9  c21400               ret 0x14
// standard library set<ptr> (function ?erase@?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE?AViterator@12@Vconst_iterator@12@0@Z)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
