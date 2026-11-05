// from server: 100% by auto
// roc 2010-06 004cf330  unit: RBX::Network::Players::Plugin  size: 220 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 004cf330
//
// 004cf330  83ec08               sub esp, 8
// 004cf333  53                   push ebx
// 004cf334  55                   push ebp
// 004cf335  8b2d0ca99e00         mov ebp, dword ptr [0x9ea90c]
// 004cf33b  56                   push esi
// 004cf33c  8bf1                 mov esi, ecx
// 004cf33e  8b4618               mov eax, dword ptr [esi + 0x18]
// 004cf341  8b18                 mov ebx, dword ptr [eax]
// 004cf343  8b06                 mov eax, dword ptr [esi]
// 004cf345  57                   push edi
// 004cf346  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 004cf34a  85ff                 test edi, edi
// 004cf34c  7404                 je 0x4cf352
// 004cf34e  3bf8                 cmp edi, eax
// 004cf350  7406                 je 0x4cf358
// 004cf352  ffd5                 call ebp
// 004cf354  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 004cf358  395c2424             cmp dword ptr [esp + 0x24], ebx
// 004cf35c  7562                 jne 0x4cf3c0
// 004cf35e  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 004cf362  8b5e18               mov ebx, dword ptr [esi + 0x18]
// 004cf365  8b06                 mov eax, dword ptr [esi]
// 004cf367  85c9                 test ecx, ecx
// 004cf369  7404                 je 0x4cf36f
// 004cf36b  3bc8                 cmp ecx, eax
// 004cf36d  7406                 je 0x4cf375
// 004cf36f  ffd5                 call ebp
// 004cf371  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 004cf375  395c242c             cmp dword ptr [esp + 0x2c], ebx
// 004cf379  7545                 jne 0x4cf3c0
// 004cf37b  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 004cf37e  8b5104               mov edx, dword ptr [ecx + 4]
// 004cf381  52                   push edx
// 004cf382  8bce                 mov ecx, esi
// 004cf384  e897e4ffff           call 0x4cd820
// 004cf389  8b4618               mov eax, dword ptr [esi + 0x18]
// 004cf38c  894004               mov dword ptr [eax + 4], eax
// 004cf38f  8b4618               mov eax, dword ptr [esi + 0x18]
// 004cf392  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 004cf399  8900                 mov dword ptr [eax], eax
// 004cf39b  8b4618               mov eax, dword ptr [esi + 0x18]
// 004cf39e  894008               mov dword ptr [eax + 8], eax
// 004cf3a1  8b4618               mov eax, dword ptr [esi + 0x18]
// 004cf3a4  8b16                 mov edx, dword ptr [esi]
// 004cf3a6  8b08                 mov ecx, dword ptr [eax]
// 004cf3a8  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 004cf3ac  5f                   pop edi
// 004cf3ad  5e                   pop esi
// 004cf3ae  5d                   pop ebp
// 004cf3af  894804               mov dword ptr [eax + 4], ecx
// 004cf3b2  8910                 mov dword ptr [eax], edx
// 004cf3b4  5b                   pop ebx
// 004cf3b5  83c408               add esp, 8
// 004cf3b8  c21400               ret 0x14
// 004cf3bb  eb03                 jmp 0x4cf3c0
// 004cf3bd  8d4900               lea ecx, [ecx]
// 004cf3c0  85ff                 test edi, edi
// 004cf3c2  7406                 je 0x4cf3ca
// 004cf3c4  3b7c2428             cmp edi, dword ptr [esp + 0x28]
// 004cf3c8  7406                 je 0x4cf3d0
// 004cf3ca  ffd5                 call ebp
// 004cf3cc  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 004cf3d0  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 004cf3d4  3b5c242c             cmp ebx, dword ptr [esp + 0x2c]
// 004cf3d8  741d                 je 0x4cf3f7
// 004cf3da  8d4c2420             lea ecx, [esp + 0x20]
// 004cf3de  e8cd001900           call 0x65f4b0
// 004cf3e3  53                   push ebx
// 004cf3e4  57                   push edi
// 004cf3e5  8d442418             lea eax, [esp + 0x18]
// 004cf3e9  50                   push eax
// 004cf3ea  8bce                 mov ecx, esi
// 004cf3ec  e84fe1ffff           call 0x4cd540
// 004cf3f1  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 004cf3f5  ebc9                 jmp 0x4cf3c0
// 004cf3f7  8b36                 mov esi, dword ptr [esi]
// 004cf3f9  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 004cf3fd  5f                   pop edi
// 004cf3fe  8930                 mov dword ptr [eax], esi
// 004cf400  5e                   pop esi
// 004cf401  5d                   pop ebp
// 004cf402  895804               mov dword ptr [eax + 4], ebx
// 004cf405  5b                   pop ebx
// 004cf406  83c408               add esp, 8
// 004cf409  c21400               ret 0x14
// standard library set<ptr> (function ?erase@?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE?AViterator@12@Vconst_iterator@12@0@Z)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
